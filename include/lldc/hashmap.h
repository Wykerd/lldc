#ifndef LLDC_HASHMAP_H
#define LLDC_HASHMAP_H

#include <cwire/common.h>

/* Must be a power of two */
#define LLDC_HASHMAP_DEFAULT_SIZE   4 // 2**7
/* Double table size and rehash when load factor greater than equal to this value */
#define LLDC_MAXIMUM_LOAD_FACTOR    0.7

typedef int (*lldc_hashmap_cmp)(const void *, const void *);
typedef uint64_t (*lldc_hashmap_hash)(const void *);
typedef void *(*lldc_hashmap_key_dup)(cwr_malloc_ctx_t *m_ctx, const void *);
typedef void (*lldc_hashmap_key_free)(cwr_malloc_ctx_t *m_ctx, void *);
typedef int (*lldc_hashmap_iterator)(const void *key, const void *value);

typedef struct lldc_hashmap_entry_s {
    uint64_t hash;
    void *key;
    void *value;
} lldc_hashmap_entry_t;

typedef struct lldc_hashmap_s {
    lldc_hashmap_entry_t *table;
    size_t len;
    size_t size;
    cwr_malloc_ctx_t *m_ctx;
    lldc_hashmap_cmp compare;
    lldc_hashmap_hash hash;
    lldc_hashmap_key_dup dup_key;
    lldc_hashmap_key_free free_key;
} lldc_hashmap_t;

double lldc_hashmap_load_factor (lldc_hashmap_t *map);
uint64_t lldc_hashmap_hash_str (const void *str);
void *lldc_hashmap_dup_str (cwr_malloc_ctx_t *m_ctx, const void *str);
void lldc_hashmap_free_str (cwr_malloc_ctx_t *m_ctx, void *str);
int lldc_hashmap_init_str (lldc_hashmap_t *map, cwr_malloc_ctx_t *m_ctx);
int lldc_hashmap_init (lldc_hashmap_t *map, cwr_malloc_ctx_t *m_ctx, lldc_hashmap_hash hash_func, lldc_hashmap_cmp cmp_func, lldc_hashmap_key_dup dup_key, lldc_hashmap_key_free free_key);
int lldc_hashmap_set (lldc_hashmap_t *map, const void *key, void *value);
int lldc_hashmap_replace (lldc_hashmap_t *map, const void *key, void *value);
void *lldc_hashmap_delete (lldc_hashmap_t *map, const void *key);
void *lldc_hashmap_get (lldc_hashmap_t *map, const void *key);
void lldc_hashmap_iterate (lldc_hashmap_t *map, lldc_hashmap_iterator iterator);
void lldc_hashmap_free (lldc_hashmap_t *map);

#endif
