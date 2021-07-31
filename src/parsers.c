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
#include <lldc/parsers.h>
#include <lldc/hashmap.h>
/**
 * message Parser
 * Human readable error message
 * type: object.string
 */
static
int lldc__discord_error_message_parse (lldc_discord_error_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->message = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * errors Parser
 * JSON object
 * See the Developer page for info: https://discord.com/developers/docs/reference#error-messages
 * type: object.rawobj
 */
static
int lldc__discord_error_errors_parse (lldc_discord_error_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_obj(json))
        return -1;

    obj->errors = json;

    return 0;
}
/**
 * code Parser
 * Error code
 * type: object.int
 */
static
int lldc__discord_error_code_parse (lldc_discord_error_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->code = yyjson_get_int(json);

    return 0;
}
int lldc_discord_error_parse (cwr_malloc_ctx_t *_mctx, lldc_discord_error_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_parser_def_t parser_def[3] = {
        { "code", (int (*)(void *, yyjson_val *))lldc__discord_error_code_parse },
        { "errors", (int (*)(void *, yyjson_val *))lldc__discord_error_errors_parse },
        { "message", (int (*)(void *, yyjson_val *))lldc__discord_error_message_parse }
    };

    static lldc_hashmap_entry_t parser_table[8] = { 0 };
    static lldc_hashmap_t parsers = {  
        .size = 8,
        .len = 0,
        .table = parser_table,
        .hash = lldc_hashmap_hash_str,
        .compare = (int (*)(const void *, const void *))strcmp,
        .dup_key = lldc_hashmap_dup_echo,
        .free_key = lldc_hashmap_free_noop
    };
    LLDC_PARSER_LOAD(3)

    if (!yyjson_is_obj(json))
        return -1;

    lldc_parser_malloc_ledger_t *ledger = obj->_mlog;
    
    memset(obj, 0, sizeof(lldc_discord_error_t));

    obj->_mctx = _mctx;
    if (!has_existing_ledger)
        obj->_mlog = &obj->__mlog;
    else
        obj->_mlog = ledger;

    yyjson_val *key, *val;
    yyjson_obj_iter iter;
    yyjson_obj_iter_init(json, &iter);
    while ((key = yyjson_obj_iter_next(&iter))) {
        val = yyjson_obj_iter_get_val(key);
        lldc_parser_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}