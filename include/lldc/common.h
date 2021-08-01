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

/* Library information */
#define LLDC_VERSION                0x00000100
#define LLDC_VERSION_STR            "0.1.0"
#define LLDC_VERSION_LONG           "lldc " LLDC_VERSION_STR
#define LLDC_GIT_REPO               "https://github.com/Wykerd/lldc.git"

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

#endif
