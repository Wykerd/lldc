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

#endif
