/**
 * Copyright 2021 Daniel Wykerd
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef LLDC_STRUCTURE_H
#define LLDC_STRUCTURE_H

#include <cwire/common.h>
#include <lldc/common.h>
#include <yyjson.h>

typedef int (*lldc_struct_func)(void *obj, yyjson_val *json);

typedef struct lldc_struct_def_s {
    const char *key;
    lldc_struct_func parser;
} lldc_struct_def_t;

#define LLDC_PARSER_LOAD(length)               \
    if (!parsers.len)                       \
    {                                       \
        for (size_t i = 0; i < length; i++)    \
            lldc_hashmap_set(&parsers, parser_def[i].key, parser_def[i].parser);    \
    }

typedef struct lldc_struct_malloc_ledger_s {
    void **pointers;
    size_t len;
    size_t size;
} lldc_struct_malloc_ledger_t;

#define LLDC_STRUCT_BASE                \
    cwr_malloc_ctx_t *_mctx;            \
    lldc_struct_malloc_ledger_t *_mlog;
    

typedef struct lldc_struct_obj_s {
    LLDC_STRUCT_BASE
} lldc_struct_obj_t;

typedef struct lldc_struct_obj_root_s {
    LLDC_STRUCT_BASE
    lldc_struct_malloc_ledger_t __mlog;
} lldc_struct_obj_root_t;

void *lldc_struct_strdup (lldc_struct_obj_t *parser, const char *str);
void *lldc_struct_malloc (lldc_struct_obj_t *parser, size_t size);
void lldc_struct_free (lldc_struct_obj_t *parser);
/**
 * Initialize a structure for use without parsing from json
 */
void lldc_struct_init (cwr_malloc_ctx_t *_mctx, lldc_struct_obj_root_t *parser);

/* Primatives Arrays */
typedef struct lldc_struct_string_arr_s {
    LLDC_STRUCT_BASE
    const char **items;
    size_t len;
} lldc_struct_string_arr_t;

typedef struct lldc_struct_int_arr_s {
    LLDC_STRUCT_BASE
    int *items;
    size_t len;
} lldc_struct_int_arr_t;

typedef lldc_struct_int_arr_t lldc_struct_boolean_arr_t;

typedef struct lldc_struct_uint_arr_s {
    LLDC_STRUCT_BASE
    uint64_t *items;
    size_t len;
} lldc_struct_uint_arr_t;

typedef struct lldc_struct_double_arr_s {
    LLDC_STRUCT_BASE
    double *items;
    size_t len;
} lldc_struct_double_arr_t;

typedef lldc_struct_double_arr_t lldc_struct_timestamp_arr_t;

typedef struct lldc_struct_snowflake_arr_s {
    LLDC_STRUCT_BASE
    snowflake_t *items;
    size_t len;
} lldc_struct_snowflake_arr_t;

int lldc_struct_int_arr_parse (lldc_struct_int_arr_t *arr, yyjson_val *json);
int lldc_struct_uint_arr_parse (lldc_struct_uint_arr_t *arr, yyjson_val *json);
int lldc_struct_string_arr_parse (lldc_struct_string_arr_t *arr, yyjson_val *json);
int lldc_struct_toint_arr_parse(lldc_struct_uint_arr_t *arr, yyjson_val *json);
int lldc_struct_double_arr_parse(lldc_struct_double_arr_t *arr, yyjson_val *json);
int lldc_struct_timestamp_arr_parse(lldc_struct_timestamp_arr_t *arr, yyjson_val *json);

#define lldc_struct_boolean_arr_parse(arr, json) lldc_struct_int_arr_parse((lldc_struct_int_arr_t *)arr, json)
#define lldc_struct_snowflake_arr_parse(arr, json) lldc_struct_toint_arr_parse((lldc_struct_uint_arr_t *)arr, json)

#endif
