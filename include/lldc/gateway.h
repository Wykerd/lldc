/**
 * Copyright 2021 Daniel Wykerd
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef LLDC_GATEWAY_H
#define LLDC_GATEWAY_H

#include <lldc/common.h>
#include <lldc/parsers.h>
#include <cwire/socket.h>
#include <cwire/tls.h>
#include <cwire/ws.h>
#include <uv.h>
#include <yyjson.h>
#ifdef LLDC_GW_COMPRESS
#include <zlib.h>
#endif

/**
 * Gateway shard 
 */
typedef struct lldc_gateway_client_s {
    /* Memory Context */
    cwr_malloc_ctx_t *m_ctx;
    yyjson_alc *json_alc;

    /* Client event loop */
    uv_loop_t *loop;
    uv_timer_t heartbeat_timer;

    /* Bot is connected to gateway */
    int is_ready;

    /* Incomplete frame buffer */
    cwr_buf_t frame_buffer;

#ifdef LLDC_GW_COMPRESS
    /* Buffer to store decompressed message */
    cwr_buf_t decomp_buffer;
    /* zlib-stream decompression context */
	z_stream d_stream;
#endif

    /* Network Stack */
    cwr_sock_t tcp;
    cwr_tls_t  tls;
    cwr_ws_t   ws;
} lldc_gateway_client_t;

/**
 * It is recommended to set the tls.sec_ctx first from an existing context
 */
int lldc_gateway_client_init (cwr_malloc_ctx_t *m_ctx, uv_loop_t *loop, lldc_gateway_client_t *client);
int lldc_gateway_client_connect (lldc_gateway_client_t *client);

#endif
