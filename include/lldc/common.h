/**
 * Copyright 2021 Daniel Wykerd
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef LLDC_COMMON_H
#define LLDC_COMMON_H

#include <cwire/common.h>
#include <stddef.h>
#include <inttypes.h>
#include <math.h>

/* Library information */
#define LLDC_VERSION                0x00000100
#define LLDC_VERSION_STR            "0.1.0"
#define LLDC_VERSION_LONG           "lldc " LLDC_VERSION_STR
#define LLDC_GIT_REPO               "https://github.com/Wykerd/lldc.git"

#define LLDC_GW_COMPRESS 1

/* Gateway defines */
#define LLDC_GW_VERSION             9
#define LLDC_GW_VERSION_STR         "9"
#ifdef LLDC_GW_COMPRESS
#define LLDC_GW_WS_QUERY            "?v=" LLDC_GW_VERSION_STR "&encoding=json&compress=zlib-stream"
#else
#define LLDC_GW_WS_QUERY            "?v=" LLDC_GW_VERSION_STR "&encoding=json"
#endif
#define LLDC_GW_WS_URI              "wss://gateway.discord.gg/" LLDC_GW_WS_QUERY
#define LLDC_GW_HOST                "gateway.discord.gg"
#define LLDC_FRAME_BUF_SIZE         4096
#define LLDC_DECOMP_BUF_SIZE        LLDC_FRAME_BUF_SIZE

/* API Defines */
#define LLDC_DEFAULT_PORT           "443"
#define LLDC_API_HOST               "discord.com"
#define LLDC_API_PORT               LLDC_DEFAULT_PORT
#define LLDC_API_VERSION            9
#define LLDC_API_VERSION_STR        "9"
#define LLDC_API_BASE_PATH          "/api/v" LLDC_API_VERSION_STR
#define LLDC_CDN_HOST               "cdn.discordapp.com"
#define LLDC_CDN_PORT               LLDC_DEFAULT_PORT
#define LLDC_USER_AGENT             "DiscordBot (" LLDC_GIT_REPO ", " LLDC_VERSION_STR ")"

/* Mime types */
#define LLDC_MIME_PNG               "image/png"
#define LLDC_MIME_JPEG              "image/jpeg"
#define LLDC_MIME_GIF               "image/gif"
#define LLDC_MIME_WEBP              "image/webp"

/* Message Formatting */
#define LLDC_FORMAT_USER            "<@%s>"
#define LLDC_FORMAT_USER_NICK       "<@!%s>"
#define LLDC_FORMAT_CHANNEL         "<#%s>"
#define LLDC_FORMAT_ROLE            "<#&%s>"
/* NAME, ID */
#define LLDC_FORMAT_CUSTOM_EMOJI    "<:%s:%s>"
/* NAME, ID */
#define LLDC_FORMAT_CUSTOM_AEMOJI   "<a:%s:%s>"
/* Unix timestamp (seconds) */
#define LLDC_FORMAT_TIMESTAMP       "<t:%llu>"
/** 
 * Unix timestamp (seconds)
 * Format:
 * t	16:20	                        Short Time
 * T	16:20:30	                    Long Time
 * d	20/04/2021	                    Short Date
 * D	20 April 2021	                Long Date
 * f 	20 April 2021 16:20	            Short Date/Time
 * F	Tuesday, 20 April 2021 16:20	Long Date/Time
 * R	2 months ago	                Relative Time
 */
#define LLDC_FORMAT_TIMESTAMP_F      "<t:%llu:%c>"

typedef uint64_t snowflake_t;

/**
 * decode a percent-encoded C string with optional path normalization
 *
 * The buffer pointed to by @dst must be at least strlen(@src) bytes.
 * Decoding stops at the first character from @src that decodes to null.
 *
 * @param dst       destination buffer
 * @param src       source buffer
 * @return          number of valid characters in @dst
 * @author          Johan Lindh <johan@linkdata.se>
 * @legalese        BSD licensed (http://opensource.org/licenses/BSD-2-Clause)
 */
size_t lldc_urldecode(char* dst, const char* src);

/**
 * url encode a C string
 * 
 * Source: http://www.geekhideout.com/urlcode.shtml
 * License: Public Domain
 * Make sure output buffer is `strlen(str) * 3 + 1` in size 
 * @param dst       destination buffer
 * @param src       source buffer
 */
size_t lldc_urlencode(char* dst, const char *str);

/**
 * Escape string for use in json
 */
void *lldc_buf_write_json_str (cwr_buf_t *buf, const char *s);

/**
 * ISO Date parser
 * @param s     ISO date
 * @return      number of milliseconds since the Unix Epoch
 */
double lldc_date_parse (const char *s);

/**
 * Get current time
 * @return      number of milliseconds since the Unix Epoch
 */
double lldc_date_now ();

#endif
