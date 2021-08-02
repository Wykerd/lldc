/**
 * Copyright 2021 Daniel Wykerd
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#include <lldc/structure.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define LLDC_PARSER_LEDGER_DEF_SIZE 8

void *lldc_struct_malloc (lldc_struct_obj_t *parser, size_t size)
{
    if (parser->_mlog->pointers == NULL)
    {
        parser->_mlog->pointers = cwr_malloc(parser->_mctx, sizeof(void *) * LLDC_PARSER_LEDGER_DEF_SIZE);
        if (!parser->_mlog->pointers)
            return NULL;
        parser->_mlog->len = 0;
        parser->_mlog->size = LLDC_PARSER_LEDGER_DEF_SIZE;
    };

    if (parser->_mlog->size < parser->_mlog->len + 1)
    {
        void *ptrs = cwr_realloc(parser->_mctx, parser->_mlog->pointers, sizeof(void *) * parser->_mlog->size * 2);
        if (!ptrs)
            return NULL;
        parser->_mlog->pointers = ptrs;
        parser->_mlog->size *= 2;
    }

    void *ptr = cwr_malloc(parser->_mctx, size);
    if (!ptr)
        return NULL;
    
    parser->_mlog->pointers[parser->_mlog->len++] = ptr;

    return ptr;
}

void *lldc_struct_realloc (lldc_struct_obj_t *st, void *ptr, size_t size)
{
    assert(ptr != NULL && "Pointer must not be null");
    return cwr_realloc(st->_mctx, ptr, size);
}

void *lldc_struct_strdup (lldc_struct_obj_t *parser, const char *str)
{
    size_t len = strlen(str);
    char *n_str = lldc_struct_malloc(parser, len + 1);
    if (!n_str)
        return NULL;
    memcpy(n_str, str, len);
    n_str[len] = '\0';
    return n_str;
}

void lldc_struct_init (cwr_malloc_ctx_t *_mctx, lldc_struct_obj_root_t *parser)
{
    parser->_mctx = _mctx;
    parser->_mlog = &parser->__mlog;
}

void lldc_struct_free (lldc_struct_obj_t *parser)
{
    for (size_t i = 0; i < parser->_mlog->len; i++)
        cwr_free(parser->_mctx, parser->_mlog->pointers[i]);

    cwr_free(parser->_mctx, parser->_mlog->pointers);

    parser->_mlog->pointers = NULL;
    parser->_mlog->len = 0;
    parser->_mlog->size = 0;
}

const char *lldc_struct_set_strn (lldc_struct_obj_t *st, const char **ptr, const char *val, size_t len)
{
    if (*ptr == NULL)
    {
        *ptr = lldc_struct_malloc(st, len);
        if (*ptr == NULL)
            return NULL;
        memcpy(*ptr, val, len);
        return *ptr;
    }

    char *str = lldc_struct_realloc(st, *ptr, len);
    if (*str = NULL)
        return NULL;
    
    *ptr = str;
    memcpy(*ptr, val, len);

    return *ptr;
}

const char *lldc_struct_set_str (lldc_struct_obj_t *st, const char **ptr, const char *val)
{
    if (*ptr == NULL)
    {
        *ptr = lldc_struct_strdup(st, val);
        return *ptr;
    }

    return lldc_struct_set_strn(st, ptr, val, strlen(val) + 1);
}

void lldc_struct_init_arr (lldc_struct_obj_t *st, lldc_struct_opaque_arr_t *arr)
{
    arr->_mctx = st->_mctx;
    arr->_mlog = st->_mlog;
}

void lldc_struct_init_root_arr (cwr_malloc_ctx_t *_mctx, lldc_struct_opaque_root_arr_t *parser)
{
    parser->_mctx = _mctx;
    parser->_mlog = &parser->__mlog;
}

void *lldc_struct_add_elem_arr (lldc_struct_opaque_arr_t *arr, size_t elem_size, size_t count)
{
    if (arr->items == NULL)
    {
        arr->items = lldc_struct_malloc((lldc_struct_obj_t *)arr, elem_size * count);
        memset(arr->items, 0, elem_size * count);
        arr->len = count;
        return arr->items;
    }

    char *n_arr = lldc_struct_realloc((lldc_struct_obj_t *)arr, arr->items, (arr->len + count) * elem_size);
    if (*n_arr = NULL)
        return NULL;

    arr->items = n_arr;
    memset(arr->items + arr->len, 0, (arr->len + count) * elem_size);
    arr->len += count;

    return arr->items + arr->len - count;
}

int lldc_struct_int_arr_parse (lldc_struct_int_arr_t *arr, yyjson_val *json)
{
    if (!yyjson_is_arr(json))
        return -1;

    size_t arr_size = yyjson_arr_size(json);
    if (!arr_size)
    {
        arr->items = NULL;
        arr->len = 0;
        return 0;
    }

    arr->items = lldc_struct_malloc((lldc_struct_obj_t *)arr, sizeof(*arr->items) * arr_size);
    if (arr->items == NULL)
    {
        arr->len = 0;
        return -1;
    }
    arr->len = arr_size;

    size_t idx, max;
    yyjson_val *val;
    yyjson_arr_foreach(json, idx, max, val) {
        if (yyjson_is_int(val))
            arr->items[idx] = yyjson_get_int(val);
    }

    return 0;
}

int lldc_struct_uint_arr_parse (lldc_struct_uint_arr_t *arr, yyjson_val *json)
{
    if (!yyjson_is_arr(json))
        return -1;

    size_t arr_size = yyjson_arr_size(json);
    if (!arr_size)
    {
        arr->items = NULL;
        arr->len = 0;
        return 0;
    }

    arr->items = lldc_struct_malloc((lldc_struct_obj_t *)arr, sizeof(*arr->items) * arr_size);
    if (arr->items == NULL)
    {
        arr->len = 0;
        return -1;
    }
    arr->len = arr_size;

    size_t idx, max;
    yyjson_val *val;
    yyjson_arr_foreach(json, idx, max, val) {
        if (yyjson_is_uint(val))
            arr->items[idx] = yyjson_get_uint(val);
    }

    return 0;
}

int lldc_struct_string_arr_parse (lldc_struct_string_arr_t *arr, yyjson_val *json)
{
    if (!yyjson_is_arr(json))
        return -1;

    size_t arr_size = yyjson_arr_size(json);
    if (!arr_size)
    {
        arr->items = NULL;
        arr->len = 0;
        return 0;
    }

    arr->items = lldc_struct_malloc((lldc_struct_obj_t *)arr, sizeof(*arr->items) * arr_size);
    if (arr->items == NULL)
    {
        arr->len = 0;
        return -1;
    }
    arr->len = arr_size;

    size_t idx, max;
    yyjson_val *val;
    yyjson_arr_foreach(json, idx, max, val) {
        if (yyjson_is_str(val))
            arr->items[idx] = lldc_struct_strdup((lldc_struct_obj_t *)arr, yyjson_get_str(val));
    }

    return 0;
}

int lldc_struct_toint_arr_parse(lldc_struct_uint_arr_t *arr, yyjson_val *json)
{
    if (!yyjson_is_arr(json))
        return -1;

    size_t arr_size = yyjson_arr_size(json);
    if (!arr_size)
    {
        arr->items = NULL;
        arr->len = 0;
        return 0;
    }

    arr->items = lldc_struct_malloc((lldc_struct_obj_t *)arr, sizeof(*arr->items) * arr_size);
    if (arr->items == NULL)
    {
        arr->len = 0;
        return -1;
    }
    arr->len = arr_size;

    size_t idx, max;
    yyjson_val *val;
    yyjson_arr_foreach(json, idx, max, val) {
        if (yyjson_is_str(val))
            arr->items[idx] = (uint64_t)atoll(yyjson_get_str(val));
    }

    return 0;
}

int lldc_struct_double_arr_parse(lldc_struct_double_arr_t *arr, yyjson_val *json)
{
    if (!yyjson_is_arr(json))
        return -1;

    size_t arr_size = yyjson_arr_size(json);
    if (!arr_size)
    {
        arr->items = NULL;
        arr->len = 0;
        return 0;
    }

    arr->items = lldc_struct_malloc((lldc_struct_obj_t *)arr, sizeof(*arr->items) * arr_size);
    if (arr->items == NULL)
    {
        arr->len = 0;
        return -1;
    }
    arr->len = arr_size;

    size_t idx, max;
    yyjson_val *val;
    yyjson_arr_foreach(json, idx, max, val) {
        if (yyjson_is_real(val))
            arr->items[idx] = yyjson_get_real(val);
    }

    return 0;
}

int lldc_struct_timestamp_arr_parse(lldc_struct_timestamp_arr_t *arr, yyjson_val *json)
{
    if (!yyjson_is_arr(json))
        return -1;

    size_t arr_size = yyjson_arr_size(json);
    if (!arr_size)
    {
        arr->items = NULL;
        arr->len = 0;
        return 0;
    }

    arr->items = lldc_struct_malloc((lldc_struct_obj_t *)arr, sizeof(*arr->items) * arr_size);
    if (arr->items == NULL)
    {
        arr->len = 0;
        return -1;
    }
    arr->len = arr_size;

    size_t idx, max;
    yyjson_val *val;
    yyjson_arr_foreach(json, idx, max, val) {
        if (yyjson_is_str(val))
            arr->items[idx] = lldc_date_parse(yyjson_get_str(val));
    }

    return 0;
}
