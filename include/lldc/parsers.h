/**
* Copyright 2021 Daniel Wykerd
*
* Use of this source code is governed by an MIT-style
* license that can be found in the LICENSE file or at
* https://opensource.org/licenses/MIT.
*/

/**
 * This source has been automatically generated.
 * Do not edit it directly!
 * 
 * See scripts/gen_parser.js and the schemas in schemas/
 * for the sources used to generate this file
 */
#ifndef LLDC_PARSERS_H
#define LLDC_PARSERS_H
#include <lldc/parse.h>
#include <yyjson.h>
/* Error Messages */
typedef struct lldc_discord_error_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_parser_malloc_ledger_t __mlog;
    /** 
     * Error code 
     */
    int code;
    /** 
     * JSON object
     * See the Developer page for info: https://discord.com/developers/docs/reference#error-messages 
     */
    yyjson_val *errors;
    /** 
     * Human readable error message 
     */
    const char *message;
} lldc_discord_error_t;
/**
* Discord Error Parser
* Error Messages
*/
int lldc_discord_error_parse (cwr_malloc_ctx_t *_mctx, lldc_discord_error_t *obj, yyjson_val *json, int has_existing_ledger);
#endif