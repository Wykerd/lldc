/**
 * Copyright 2021 Daniel Wykerd
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef LLDC_PARSE_H
#define LLDC_PARSE_H

#include <cwire/common.h>
#include <lldc/common.h>
#include <yyjson.h>

typedef int (*lldc_parser_func)(void *obj, yyjson_val *json);

typedef struct lldc_parser_def_s {
    const char *key;
    lldc_parser_func parser;
} lldc_parser_def_t;

#define LLDC_PARSER_LOAD(length)               \
    if (!parsers.len)                       \
    {                                       \
        for (size_t i = 0; i < length; i++)    \
            lldc_hashmap_set(&parsers, parser_def[i].key, parser_def[i].parser);    \
    }

typedef struct lldc_parser_malloc_ledger_s {
    void **pointers;
    size_t len;
    size_t size;
} lldc_parser_malloc_ledger_t;

#define LLDC_PARSER_BASE                \
    cwr_malloc_ctx_t *_mctx;            \
    lldc_parser_malloc_ledger_t *_mlog;
    

typedef struct lldc_parser_obj_s {
    LLDC_PARSER_BASE
} lldc_parser_obj_t;

void *lldc_parser_strdup (lldc_parser_obj_t *parser, const char *str);
void *lldc_parser_malloc (lldc_parser_obj_t *parser, size_t size);
void lldc_parser_free (lldc_parser_obj_t *parser);

/* Primatives Arrays */
typedef struct lldc_parser_string_arr_s {
    LLDC_PARSER_BASE
    const char **items;
    size_t len;
} lldc_parser_string_arr_t;

typedef struct lldc_parser_int_arr_s {
    LLDC_PARSER_BASE
    int *items;
    size_t len;
} lldc_parser_int_arr_t;

typedef lldc_parser_int_arr_t lldc_parser_boolean_arr_t;

typedef struct lldc_parser_uint_arr_s {
    LLDC_PARSER_BASE
    uint64_t *items;
    size_t len;
} lldc_parser_uint_arr_t;

typedef struct lldc_parser_double_arr_s {
    LLDC_PARSER_BASE
    double *items;
    size_t len;
} lldc_parser_double_arr_t;

typedef lldc_parser_double_arr_t lldc_parser_timestamp_arr_t;

typedef struct lldc_parser_snowflake_arr_s {
    LLDC_PARSER_BASE
    snowflake_t *items;
    size_t len;
} lldc_parser_snowflake_arr_t;

int lldc_parser_int_arr_parse (lldc_parser_int_arr_t *arr, yyjson_val *json);
int lldc_parser_uint_arr_parse (lldc_parser_uint_arr_t *arr, yyjson_val *json);
int lldc_parser_string_arr_parse (lldc_parser_string_arr_t *arr, yyjson_val *json);
int lldc_parser_toint_arr_parse(lldc_parser_uint_arr_t *arr, yyjson_val *json);
int lldc_parser_double_arr_parse(lldc_parser_double_arr_t *arr, yyjson_val *json);
int lldc_parser_timestamp_arr_parse(lldc_parser_timestamp_arr_t *arr, yyjson_val *json);

#define lldc_parser_boolean_arr_parse(arr, json) lldc_parser_int_arr_parse((lldc_parser_int_arr_t *)arr, json)
#define lldc_parser_snowflake_arr_parse(arr, json) lldc_parser_toint_arr_parse((lldc_parser_uint_arr_t *)arr, json)

#endif
