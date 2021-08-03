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

#define LLDC_CLIENT_STATUS_INVISIBLE    "invisible"
#define LLDC_CLIENT_STATUS_OFFLINE      "offline"

typedef enum lldc_gateway_intent {
    LLDC_INTENT_GUILDS = (1 << 0),
    LLDC_INTENT_GUILD_MEMBERS = (1 << 1),
    LLDC_INTENT_GUILD_BANS = (1 << 2),
    LLDC_INTENT_GUILD_EMOJIS_AND_STICKERS = (1 << 3),
    LLDC_INTENT_GUILD_INTEGRATIONS = (1 << 4),
    LLDC_INTENT_GUILD_WEBHOOKS = (1 << 5),
    LLDC_INTENT_GUILD_INVITES = (1 << 6),
    LLDC_INTENT_GUILD_VOICE_STATES = (1 << 7),
    LLDC_INTENT_GUILD_PRESENCES = (1 << 8),
    LLDC_INTENT_GUILD_MESSAGES = (1 << 9),
    LLDC_INTENT_GUILD_MESSAGE_REACTIONS = (1 << 10),
    LLDC_INTENT_GUILD_MESSAGE_TYPING = (1 << 11),
    LLDC_INTENT_DIRECT_MESSAGES = (1 << 12),
    LLDC_INTENT_DIRECT_MESSAGE_REACTIONS = (1 << 13),
    LLDC_INTENT_DIRECT_MESSAGE_TYPING = (1 << 14)
} lldc_gateway_intent_t;

typedef struct lldc_gateway_update_presence_s {
    /* unix time (in milliseconds) of when the client went idle, or null if the client is not idle */
    int since;
    /* the user's activities */
    lldc_activity_bot_arr_t activities;
    /* the user's new status */
    const char *status;
    /* whether or not the client is afk */
    int afk;
} lldc_gateway_update_presence_t;

typedef struct lldc_gateway_identify_defaults_s {
    const char *token;
    /* client properties */
    struct {
        const char *os;
        const char *lib_name;
    } properties;
    /* the Gateway Intents you wish to receive */
    lldc_gateway_intent_t intents;
    /**
     * value between 50 and 250, total number of members where the gateway will stop 
     * sending offline members in the guild member list 
     */
    uint8_t large_threshold;
} lldc_gateway_identify_defaults_t;

typedef struct lldc_gateway_identify_s {
    const char *token;
    /* client properties */
    struct {
        const char *os;
        const char *lib_name;
    } properties;
    /* the Gateway Intents you wish to receive */
    lldc_gateway_intent_t intents;
    /**
     * value between 50 and 250, total number of members where the gateway will stop 
     * sending offline members in the guild member list 
     */
    uint8_t large_threshold;
    /* used for Guild Sharding */
    int shard[2];
    /* presence structure for initial presence information */
    lldc_gateway_update_presence_t presence; 
} lldc_gateway_identify_t;

void *lldc_activity_bot_stringify (lldc_activity_bot_t *activity, cwr_buf_t *buf);
void *lldc_update_presence_stringify (lldc_gateway_update_presence_t *presence, cwr_buf_t *buf);
void *lldc_gateway_identify_stringify (lldc_gateway_identify_t *identify, cwr_buf_t *buf);

/**
 * Gateway shard 
 */
typedef struct lldc_gateway_client_s {
    /* Identify object */
    lldc_gateway_identify_t identify;

    /* Memory Context */
    cwr_malloc_ctx_t *m_ctx;
    yyjson_alc *json_alc;

    /* Client event loop */
    uv_loop_t *loop;
    uv_timer_t heartbeat_timer;
    int heartbeat_interval;
    /**
     * If a client does not receive a heartbeat ack between its attempts at sending heartbeats, 
     * this may be due to a failed or "zombied" connection. 
     * The client should then immediately terminate the connection with a non-1000 close code, 
     * reconnect, and attempt to Resume.
     */
    int want_ack;
    
    int last_s;

    /* Bot is heartbeating to gateway */
    int is_ready;
    /* Bot is connected */
    int is_connected; 

    /* Incomplete frame buffer */
    cwr_buf_t frame_buffer;
    /* General Purpose Buffer */
    cwr_buf_t gp_buf;
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
