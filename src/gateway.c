#include <lldc/gateway.h>
#include <lldc/events.h>
#include <string.h>

static const char *gateway_close_codes[] = {
    "Unknown error",
    "Unknown opcode",
    "Decode error",
    "Not authenticated",
    "Authentication failed",
    "Already authenticated",
    "Undocumented error?", /* 4006 missing */
    "Invalid seq",
    "Rate limited",
    "Session timed out",
    "Invalid shard",
    "Sharding required",
    "Invalid API version",
    "Invalid intent(s)",
    "Disallow intent(s)"
};

static inline
void lldc__gw_stop_timers (lldc_gateway_client_t *client) 
{
    if (client->status.ready)
        uv_timer_stop(&client->heartbeat_timer);
    if (client->status.reidentifying)
        uv_timer_stop(&client->identify_timeout);
}

static inline
void lldc__gw_close (lldc_gateway_client_t *client, uint16_t status)
{
    lldc__gw_stop_timers(client);
    if (!cwr_ws_close(&client->ws, status))
    {
        // fallback to closing the tls connection
        if (!cwr_tls_shutdown(&client->tls))
        {
            // fallback to closing the tcp connection
            if (!cwr_sock_shutdown(&client->tcp))
            {
                // TODO: we're fucked
            }
        }
    }
}

static inline
void lldc__gw_reconnect (lldc_gateway_client_t *client) 
{
    /**
     * This is a generic status code that can be returned when 
     * there is no other more suitable status code 
     */
    lldc__gw_close(client, 1008); 
    memset(&client->status, 0, sizeof(client->status));
    client->status.resuming = 1;
}

static void lldc__gw_stream_err (cwr_linkable_t *stream)
{
    lldc_gateway_client_t *client = stream->data;
    // TODO: error
    lldc__gw_stop_timers(client);
}
static void lldc__gw_ws_fail (cwr_ws_t *ws)
{
    lldc_gateway_client_t *client = ws->data;
    // TODO: we've failed
    lldc__gw_stop_timers(client);
}
static void lldc__gw_ws_close (cwr_ws_t *ws)
{
    lldc_gateway_client_t *client = ws->data;
    // TODO: close reason
    lldc__gw_stop_timers(client);
    cwr_sock_shutdown(&client->tcp);
    cwr_tls_shutdown(&client->tls);
}
static void lldc__gw_tls_close (cwr_tls_t *tls)
{
    lldc_gateway_client_t *client = tls->data;
    // TODO: close reason
    lldc__gw_stop_timers(client);
    cwr_sock_shutdown(&client->tcp);
}
static void lldc__gw_tcp_close (cwr_sock_t *tcp)
{
    lldc_gateway_client_t *client = tcp->data;
    // TODO: we're closed everything we can reconnect now
    lldc__gw_stop_timers(client);
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
    // TODO: check returns
    cwr_tls_connect_with_sni(&client->tls, LLDC_GW_HOST);
    cwr_ws_connect(&client->ws, LLDC_GW_WS_URI, sizeof(LLDC_GW_WS_URI) - 1);

    cwr_sock_read_start(tcp); /* Start receiving data */
}

static void lldc__gw_msg_chunk (cwr_ws_t *ws, const char *data, size_t len)
{
    lldc_gateway_client_t *client = ws->data;

    if (cwr_buf_push_back(&client->frame_buffer, data, len) == NULL)
        return; // TODO: OOM
}

static 
void lldc__gw_heartbeat (uv_timer_t* handle)
{
    puts("<< Heartbeat");
    lldc_gateway_client_t *client = handle->data;

    if (client->status.want_ack)
    {
        lldc__gw_reconnect(client);
        return;
    }

    client->gp_buf.len = 0;

    int r = 0;

    if (!client->last_s)
        r = cwr_ws_send(&client->ws, "{\"op\":1,\"d\":null}", 17, CWR_WS_OP_TEXT);
    else
    {
        if (cwr_buf_printf(&client->gp_buf, "{\"op\":1,\"d\":%d}", client->last_s) == NULL)
            return; // TODO: fatal oom

        r = cwr_ws_send(&client->ws, client->gp_buf.base, client->gp_buf.len, CWR_WS_OP_TEXT);
    }

    if (r)
        return; // TODO: fatal

    client->status.want_ack = 0;
}

static inline
int lldc__gw_payload_header (cwr_buf_t *buf, lldc_gateway_opcode_t opcode)
{
    return !cwr_buf_printf(buf, "{\"op\":%d,\"d\":", opcode);
}

static inline
int lldc__gw_payload_footer (cwr_buf_t *buf)
{
    return !cwr_buf_push_back(buf, "}", 1);
}

static
void lldc__gw_identify (lldc_gateway_client_t *client) 
{
    if (client->identify_remaining != NULL && !*client->identify_remaining)
        return; // TODO: We're rate limited! DO NOT CONTINUE!

    client->gp_buf.len = 0;
    if (lldc__gw_payload_header(&client->gp_buf, LLDC_GW_OP_IDENTIFY) ||
        !lldc_gateway_identify_stringify(&client->identify, &client->gp_buf) ||
        lldc__gw_payload_footer(&client->gp_buf))
        return; // TODO: fatal

    if (cwr_ws_send(&client->ws, client->gp_buf.base, client->gp_buf.len, CWR_WS_OP_TEXT) != CWR_E_WS_OK)
        return; // TODO: fatal
}

static 
void lldc__gw_reidentify (uv_timer_t* handle)
{
    lldc_gateway_client_t *client = handle->data;

    client->status.reidentifying = 0;
    lldc__gw_identify(client);
}

static
void lldc__gw_resume (lldc_gateway_client_t *client) 
{

}

#include <lldc/hashmap.h>

static
void lldc__gw_dispatch_event (lldc_gateway_client_t *client, lldc_gateway_payload_t *payload)
{
    static lldc_struct_def_t parser_def[1] = {
        { "READY", (int (*)(void *, yyjson_val *))lldc_event_ready },
    };

    static lldc_hashmap_entry_t parser_table[2] = { 0 };
    static lldc_hashmap_t parsers = {  
        .size = 2,
        .len = 0,
        .table = parser_table,
        .hash = lldc_hashmap_hash_str,
        .compare = (int (*)(const void *, const void *))strcmp,
        .dup_key = lldc_hashmap_dup_echo,
        .free_key = lldc_hashmap_free_noop
    };
    LLDC_PARSER_LOAD(1)

    if (!payload->t)
        return; // TODO: handle this??

    lldc_struct_func parser = lldc_hashmap_get(&parsers, payload->t);
    if (parser)
        parser(client, payload->d);
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
            // TODO: 
            lldc__gw_close(client, 1003); /* close with unexceptable data status */
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

    lldc_gateway_payload_t payload;

    yyjson_read_err err;
    yyjson_doc *doc = yyjson_read_opts(msg->base, msg->len, 0, client->json_alc, &err);
    if (doc == NULL)
    {
        if (err.code == YYJSON_READ_ERROR_MEMORY_ALLOCATION) // TODO: oom
        {

        }
        // TODO: error
        lldc__gw_close(client, 1003); /* close with unexceptable data status */
        goto end;
    }
    yyjson_val *root = yyjson_doc_get_root(doc);

    lldc_gateway_payload_parse(client->m_ctx, &payload, root, 0);

    if (payload.s)
        client->last_s = payload.s;

    switch (payload.op)
    {
    case LLDC_GW_OP_DISPATCH:
        {
            /* An event was dispatched. */
            lldc__gw_dispatch_event(client, &payload);
        }
        break;

    case LLDC_GW_OP_HEARTBEAT:
        {
            client->status.want_ack = 0;
            lldc__gw_heartbeat(&client->heartbeat_timer);   
        }
        break;

    case LLDC_GW_OP_RECONNECT:
        {
            /* You should attempt to reconnect and resume immediately. */
            lldc__gw_reconnect(client);
        }
        break;

    case LLDC_GW_OP_INVALID_SESSION:
        {
            /* Session is invalidated */
            /* If we tried resuming, this means wait 5 seconds and identify */
            if (client->status.resuming)
            {
                client->status.resuming = 0;
                client->status.reidentifying = 1;
                uv_timer_start(&client->identify_timeout, lldc__gw_reidentify, 5000, 0);
            }
            /* If we receive this randomly, we should reconnect ? */
            if (client->status.connected)
            {
                lldc__gw_reconnect(client);
                break;
            }
            /* If we tried to identify, this is fatal */
            if (client->status.ready)
            {
                // TODO: fatal
            }
        }
        break;

    case LLDC_GW_OP_HELLO:
        if (!client->status.ready)
        {
            /* Since this has one field we don't need a fancy parser */
            yyjson_val *hb = yyjson_obj_get(payload.d, "heartbeat_interval");

            if (!hb || !yyjson_is_int(hb))
                return; // TODO: this is critical

            client->heartbeat_interval = yyjson_get_int(hb);

            /* Start the beating */
            int r = uv_timer_start(&client->heartbeat_timer, lldc__gw_heartbeat, 0, client->heartbeat_interval);
            if (r)
                return; // TODO: this is critical

            /* We can now identify */
            if (client->status.resuming)
                lldc__gw_resume(client);
            else
                lldc__gw_identify(client);

            client->status.ready = 1;
        }
        break;

    case LLDC_GW_OP_HEARTBEAT_ACK:
        client->status.want_ack = 0;
        break;
    
    default:
        break;
    }

    lldc_struct_free((lldc_struct_obj_t *)&payload);
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

    uv_timer_init(loop, &client->heartbeat_timer);
    client->heartbeat_timer.data = client;
    uv_timer_init(loop, &client->identify_timeout);
    client->identify_timeout.data = client;

    if (cwr_buf_malloc(&client->frame_buffer, m_ctx, LLDC_FRAME_BUF_SIZE) == NULL)
        return 1;

    if (cwr_buf_malloc(&client->gp_buf, m_ctx, LLDC_FRAME_BUF_SIZE) == NULL)
        goto fail1;

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
        cwr_buf_free(&client->gp_buf);
fail1:
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

void *lldc_activity_bot_stringify (lldc_activity_bot_t *activity, cwr_buf_t *buf)
{
    if (unlikely(!cwr_buf_printf(buf, "{\"type\":%d,\"name\":", activity->type)))
        return NULL;
    if (activity->name)
    {
        if (unlikely(!cwr_buf_push_back(buf, "\"", 1) ||
            !lldc_buf_write_json_str(buf, activity->name) ||
            !cwr_buf_push_back(buf, "\"", 1)))
            return NULL;
        
    }
    else if (unlikely(!cwr_buf_push_back(buf, "null", 4)))
        return NULL;
    if (activity->url)
        if (!cwr_buf_push_back(buf, ",\"url\":\"", 8) ||
            !lldc_buf_write_json_str(buf, activity->name) ||
            !cwr_buf_push_back(buf, "\"", 1))
            return NULL;

    if (unlikely(!cwr_buf_push_back(buf, "}", 1)))
        return NULL;

    return buf->base;
}

void *lldc_update_presence_stringify (lldc_gateway_update_presence_t *presence, cwr_buf_t *buf)
{
    if (unlikely(!cwr_buf_printf(buf, "{\"afk\":%s,\"activities\":[", presence->afk ? "true" : "false")))
        return NULL;
    for (size_t i = 0; i < presence->activities.len; i++)
    {
        if (i && !cwr_buf_push_back(buf, ",", 1))
            return NULL;
        if (unlikely(!lldc_activity_bot_stringify(&presence->activities.items[i], buf)))
            return NULL;
    }
    if (unlikely(!cwr_buf_push_back(buf, "]", 1)))
        return NULL;

    if (presence->since)
        if (!cwr_buf_printf(buf, ",\"since\":%d", presence->since))
            return NULL;

    if (presence->status)
        if (!cwr_buf_printf(buf, ",\"status\":\"%s\"", presence->status))
            return NULL;

    if (!cwr_buf_push_back(buf, "}", 1))
        return NULL;

    return buf->base;
}

void *lldc_gateway_identify_stringify (lldc_gateway_identify_t *identify, cwr_buf_t *buf)
{
    int p = 
        !cwr_buf_push_back(buf, "{\"token\":\"", 10) ||
        !lldc_buf_write_json_str(buf, identify->token) ||
        !cwr_buf_push_back(buf, "\",\"properties\":{\"$os\":\"", 23) ||
        !lldc_buf_write_json_str(buf, identify->properties.os) ||
        !cwr_buf_push_back(buf, "\",\"$browser\":\"", 14) ||
        !lldc_buf_write_json_str(buf, identify->properties.lib_name) ||
        !cwr_buf_push_back(buf, "\",\"$device\":\"", 13) ||
        !lldc_buf_write_json_str(buf, identify->properties.lib_name) ||
        !cwr_buf_printf(buf, 
            "\"},\"intents\":%d,\"compress\":false,\"large_threshold\":%d,\"shard\":[%d,%d],\"presence\":", 
            identify->intents, 
            identify->large_threshold < 50 ? 50 : identify->large_threshold,
            identify->shard[0], identify->shard[1] ? identify->shard[1] : 1) ||
        !lldc_update_presence_stringify(&identify->presence, buf) ||
        !cwr_buf_push_back(buf, "}", 1);

    if (unlikely(p))
        return NULL;

    return buf->base;
}
