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

/* Base array type */
typedef struct lldc_struct_opaque_arr_s {
    LLDC_STRUCT_BASE
    void *items;
    size_t len;
} lldc_struct_opaque_arr_t;

typedef struct lldc_struct_opaque_root_arr_s {
    LLDC_STRUCT_BASE
    void *items;
    size_t len;
    lldc_struct_malloc_ledger_t __mlog;
} lldc_struct_opaque_root_arr_t;

/**
 * Allocate and copy a string as a member of a structure
 */
void *lldc_struct_strdup (lldc_struct_obj_t *st, const char *str);
/**
 * Allocate memory owned by the structure 
 */
void *lldc_struct_malloc (lldc_struct_obj_t *st, size_t size);
/**
 * Reallocate memory already owned by the structure 
 */
void *lldc_struct_realloc (lldc_struct_obj_t *st, void *ptr, size_t size);
/**
 * Free a structure and all of its members
 */
void lldc_struct_free (lldc_struct_obj_t *st);
/**
 * Initialize a structure for use without parsing from json
 */
void lldc_struct_init (cwr_malloc_ctx_t *_mctx, lldc_struct_obj_root_t *st);
/**
 * Set the value of a string member
 * 
 * @param ptr pointer to the member to set
 * @param val the value to copy (strdup)
 * @return NULL if fail else pointer to the newly set value
 */
const char *lldc_struct_set_str (lldc_struct_obj_t *st, const char **ptr, const char *val);
/**
 * Set the value of a string member
 * 
 * @param ptr pointer to the member to set
 * @param val the value to copy (strdup)
 * @param len length of the string
 * @return NULL if fail else pointer to the newly set value
 */
const char *lldc_struct_set_strn (lldc_struct_obj_t *st, const char **ptr, const char *val, size_t len);
/**
 * Initialize array not previously initialized by a parser
 * 
 * @param st parent structure (this structure owns all the pointers allocated by the array)
 * @param arr the array
 */
void lldc_struct_init_arr (lldc_struct_obj_t *st, lldc_struct_opaque_arr_t *arr);
/**
 * Initialize root array not previously initialized by a parser
 * 
 * @param arr the array
 */
void lldc_struct_init_root_arr (cwr_malloc_ctx_t *_mctx, lldc_struct_opaque_root_arr_t *arr);
/**
 * Allocate several new elements in an array
 * 
 * @param arr the array structure to use
 * @param elem_size size of the array element
 * @param count amount of elements to allocate
 * @return Pointer to the new element
 */
void *lldc_struct_add_elem_arr (lldc_struct_opaque_arr_t *arr, size_t elem_size, size_t count);


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

/// Used internally
int lldc_struct_int_arr_parse (lldc_struct_int_arr_t *arr, yyjson_val *json);
/// Used internally
int lldc_struct_uint_arr_parse (lldc_struct_uint_arr_t *arr, yyjson_val *json);
/// Used internally
int lldc_struct_string_arr_parse (lldc_struct_string_arr_t *arr, yyjson_val *json);
/// Used internally
int lldc_struct_toint_arr_parse(lldc_struct_uint_arr_t *arr, yyjson_val *json);
/// Used internally
int lldc_struct_double_arr_parse(lldc_struct_double_arr_t *arr, yyjson_val *json);
/// Used internally
int lldc_struct_timestamp_arr_parse(lldc_struct_timestamp_arr_t *arr, yyjson_val *json);

/// Used internally
#define lldc_struct_boolean_arr_parse(arr, json) lldc_struct_int_arr_parse((lldc_struct_int_arr_t *)arr, json)
/// Used internally
#define lldc_struct_snowflake_arr_parse(arr, json) lldc_struct_toint_arr_parse((lldc_struct_uint_arr_t *)arr, json)

#endif
