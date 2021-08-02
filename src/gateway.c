#include <lldc/gateway.h>
#include <string.h>

static void lldc__gw_stream_err (cwr_linkable_t *stream)
{
    lldc_gateway_client_t *client = stream->data;
    // TODO: error
}
static void lldc__gw_ws_fail (cwr_ws_t *ws)
{
    lldc_gateway_client_t *client = ws->data;
    // TODO: we've failed
}
static void lldc__gw_ws_close (cwr_ws_t *ws)
{
    lldc_gateway_client_t *client = ws->data;
    // TODO: close reason
    cwr_sock_shutdown(&client->tcp);
    cwr_tls_shutdown(&client->tls);
}
static void lldc__gw_tls_close (cwr_tls_t *tls)
{
    lldc_gateway_client_t *client = tls->data;
    // TODO: close reason
    cwr_sock_shutdown(&client->tcp);
}
static void lldc__gw_tcp_close (cwr_sock_t *tcp)
{
    lldc_gateway_client_t *client = tcp->data;
    // TODO: we're closed everything we can reconnect now
}

static void lldc__gw_close_recv (cwr_ws_t *ws, uint16_t status, const char *reason, size_t reason_len)
{
    lldc_gateway_client_t *client = ws->data;
    // server has sent a close frame

}

static void lldc__gw_tcp_connect (cwr_sock_t *tcp)
{
    lldc_gateway_client_t *client = tcp->data;

    /* Complete the connection */
    cwr_tls_connect(&client->tls);
    cwr_ws_connect(&client->ws, LLDC_GW_WS_URI, sizeof(LLDC_GW_WS_URI) - 1);

    cwr_sock_read_start(tcp); /* Start receiving data */
}

static void lldc__gw_msg_chunk (cwr_ws_t *ws, const char *data, size_t len)
{
    lldc_gateway_client_t *client = ws->data;

    if (cwr_buf_push_back(&client->frame_buffer, data, len) == NULL)
        return; // TODO: OOM
}

static void lldc__gw_msg_recv (cwr_ws_t *ws)
{
    lldc_gateway_client_t *client = ws->data;
    cwr_buf_t *msg = &client->frame_buffer;
    /* Full message received */
#ifdef LLDC_GW_COMPRESS
    if (msg->base[msg->len - 4] == 0x00 && msg->base[msg->len - 3] == 0x00 && 
        msg->base[msg->len - 2] == 0xFF && msg->base[msg->len - 1] == 0xFF)
        return;

    client->d_stream.next_in = (Bytef *)client->frame_buffer.base;
    client->d_stream.avail_in = client->frame_buffer.len;
    do {
        client->d_stream.next_out = (Bytef *)client->decomp_buffer.base + client->decomp_buffer.len;
        client->d_stream.avail_out = client->decomp_buffer.size - client->decomp_buffer.len;
        int r = inflate(&client->d_stream, Z_NO_FLUSH);
        int read = (client->decomp_buffer.size - client->decomp_buffer.len) - client->d_stream.avail_out;
        if (r != Z_OK)
        {
            // TODO: abnormal close
            cwr_ws_close(ws, 1003); /* close with unexceptable data status */
        }
        if (client->d_stream.avail_out == 0)
        {
            if (cwr_buf_resize(&client->decomp_buffer, client->decomp_buffer.size + LLDC_FRAME_BUF_SIZE) == NULL)
                return; // TODO: OOM
        }
        client->decomp_buffer.len += read;
    } while (client->d_stream.avail_out == 0);
    msg = &client->decomp_buffer;
#endif

    fwrite(msg->base, 1, msg->len, stdout);
    fputc('\n', stdout);

    lldc_gateway_payload_t payload;

    yyjson_read_err err;

    yyjson_doc *doc = yyjson_read_opts(msg->base, msg->len, 0, client->json_alc, &err);

    yyjson_val *root = yyjson_doc_get_root(doc);


    lldc_gateway_payload_parse(client->m_ctx, &payload, root, 0);

    if (doc == NULL)
    {
        if (err.code == YYJSON_READ_ERROR_MEMORY_ALLOCATION) // TODO: oom
        {
            
        }
        // else just ignore the error
        goto end;
    }

    cwr_malloc_ctx_dump_leaks(client->m_ctx);
    switch (payload.op)
    {
    case /* constant-expression */:
        /* code */
        break;
    
    default:
        break;
    }

    lldc_struct_free(&payload);
    yyjson_doc_free(doc);
end:
#ifdef LLDC_GW_COMPRESS
    client->decomp_buffer.len = 0;
#endif
    client->frame_buffer.len = 0;
}

int lldc_gateway_client_init (cwr_malloc_ctx_t *m_ctx, uv_loop_t *loop, lldc_gateway_client_t *client)
{
    memset(client, 0, sizeof(*client));

    ssize_t r;

    client->m_ctx = m_ctx;
    client->loop = loop;

    if (cwr_buf_malloc(&client->frame_buffer, m_ctx, LLDC_FRAME_BUF_SIZE) == NULL)
        return 1;

    r = cwr_sock_init(m_ctx, loop, &client->tcp);

    if (r)
        return r;


    if (client->tls.sec_ctx.ssl_ctx)
        r = cwr_tls_init_ex(m_ctx, (cwr_linkable_t *)&client->tcp, &client->tls, &client->tls.sec_ctx);
    else
        r = cwr_tls_init(m_ctx, (cwr_linkable_t *)&client->tcp, &client->tls);

    if (r)
    {
tls_fail:
        if (client->tls.sec_ctx.ssl_ctx)
            cwr_sec_ctx_free(&client->tls.sec_ctx);
        return r;
    }
    
    r = cwr_ws_init(m_ctx, (cwr_linkable_t *)&client->tls, &client->ws);

    if (r)
    {
wss_fail:
        cwr_ws_free(&client->ws);
        goto tls_fail;
    }

    client->tcp.data = client;
    client->tls.data = client;
    client->ws.data = client;

    client->tcp.on_connect = lldc__gw_tcp_connect;

    /* Underlying connection close handlers */
    client->tcp.on_close = lldc__gw_tcp_close;
    client->tls.on_close = lldc__gw_tls_close;
    client->ws.on_close = lldc__gw_ws_close;
    client->ws.on_fail = lldc__gw_ws_fail; /* Fail is only called BEFORE we're good to go */

    /* Generic fatal error handler */
    client->tcp.io.on_error = (cwr_sock_link_cb)lldc__gw_stream_err;
    client->tls.io.on_error = (cwr_tls_link_cb)lldc__gw_stream_err;
    client->ws.io.on_error = (cwr_ws_link_cb)lldc__gw_stream_err;

    /* Clean close handlers */
    client->ws.on_receive_close = lldc__gw_close_recv;
    client->ws.on_message = lldc__gw_msg_chunk;
    client->ws.on_message_complete = lldc__gw_msg_recv;

#ifdef LLDC_GW_COMPRESS
    client->d_stream.zalloc = Z_NULL;
    client->d_stream.zfree = Z_NULL;
    client->d_stream.opaque = Z_NULL;
    if (inflateInit(&client->d_stream) != Z_OK) 
        goto fail;
    if (cwr_buf_malloc(&client->decomp_buffer, m_ctx, LLDC_DECOMP_BUF_SIZE) == NULL)
    {
fail:
        r = 1;
        cwr_buf_free(&client->frame_buffer);
        goto wss_fail;
    }
#endif
    return 0;
}

int lldc_gateway_client_connect (lldc_gateway_client_t *client)
{
    // TODO: error
    cwr_sock_connect_host(&client->tcp, LLDC_GW_HOST, LLDC_DEFAULT_PORT);
    return 0;
}

