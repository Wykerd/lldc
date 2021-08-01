/**
 * Copyright 2021 Daniel Wykerd
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#include <lldc/hashmap.h>
#include <lldc/spooky.h>
#include <string.h>

#include <cwire/no_malloc.h>

double lldc_hashmap_load_factor (lldc_hashmap_t *map) 
{
    return (map->len * 1.0) / (map->size * 1.0);
};

uint64_t lldc_hashmap_hash_str (const void *str)
{
    const char*ss = str;
    return spooky_hash64(str, strlen(str), 0);
}

void *lldc_hashmap_dup_str (cwr_malloc_ctx_t *m_ctx, const void *str)
{
    size_t len = strlen(str);
    char *n_str = cwr_malloc(m_ctx, len + 1);
    if (!n_str)
        return NULL;
    memcpy(n_str, str, len);
    n_str[len] = '\0';
    return n_str;
}

void *lldc_hashmap_dup_echo (cwr_malloc_ctx_t *m_ctx, const void *str)
{
    return (void *)str;
}

void lldc_hashmap_free_noop (cwr_malloc_ctx_t *m_ctx, void *str)
{
    /* noop */
}

void lldc_hashmap_free_str (cwr_malloc_ctx_t *m_ctx, void *str)
{
    cwr_free(m_ctx, str);
}

int lldc_hashmap_init_str (lldc_hashmap_t *map, cwr_malloc_ctx_t *m_ctx)
{
    return lldc_hashmap_init(map, m_ctx, lldc_hashmap_hash_str, (int (*)(const void *, const void *))strcmp, lldc_hashmap_dup_str, lldc_hashmap_free_str);
}

int lldc_hashmap_init (lldc_hashmap_t *map, cwr_malloc_ctx_t *m_ctx, lldc_hashmap_hash hash_func, lldc_hashmap_cmp cmp_func, lldc_hashmap_key_dup dup_key, lldc_hashmap_key_free free_key)
{
    memset(map, 0, sizeof(lldc_hashmap_t));
    map->m_ctx = m_ctx;
    map->hash = hash_func;
    map->compare = cmp_func;
    map->dup_key = dup_key;
    map->free_key = free_key;
    map->size = LLDC_HASHMAP_DEFAULT_SIZE;
    map->table = cwr_mallocz(map->m_ctx, sizeof(lldc_hashmap_entry_t) * LLDC_HASHMAP_DEFAULT_SIZE);
    if (!map->table)
        return ENOMEM;
    return 0;
}

/**
 * @param entry Set ot the memory location of the entry or the next open location for insertion
 * @returns The index of the entry or the next open location for insertion 
 */
static inline
size_t lldc__hashmap_find (lldc_hashmap_t *map, uint64_t hash, const void *key, lldc_hashmap_entry_t **entry)
{
    size_t idx = hash & (map->size - 1);

    while (map->table[idx].key)
    {
        if (!map->compare(key, map->table[idx].key))
            break;
        idx = (idx + 1) & (map->size - 1);
    }

    *entry = &map->table[idx];
    return idx;
}

static inline
int lldc__hashmap_grow (lldc_hashmap_t *map)
{
    lldc_hashmap_entry_t *old_table = map->table;
    size_t old_size = map->size;

    lldc_hashmap_entry_t *new_table = cwr_mallocz(map->m_ctx, sizeof(lldc_hashmap_entry_t) * (map->size * 2));
    if (!new_table)
        return ENOMEM;
    
    map->table = new_table;
    map->size *= 2;

    for (size_t i = 0; i < old_size; i++)
        if (old_table[i].key)
        {
            lldc_hashmap_entry_t *entry;
            size_t idx = lldc__hashmap_find(map, old_table[i].hash, old_table[i].key, &entry);

            entry->key = old_table[i].key;
            entry->value = old_table[i].value;
        };

    cwr_free(map->m_ctx, old_table);

    return 0;
}

int lldc_hashmap_set (lldc_hashmap_t *map, const void *key, void *value)
{
    int r = 0;
    lldc_hashmap_entry_t *entry;
    uint64_t hash = map->hash(key);
    size_t idx = lldc__hashmap_find(map, hash, key, &entry);

    if (entry->key)
        return EEXIST;

    entry->key = map->dup_key(map->m_ctx, key);
    if (!entry->key)
        return ENOMEM;

    entry->value = value;
    entry->hash = hash;

    map->len++;

    if (lldc_hashmap_load_factor(map) >= LLDC_MAXIMUM_LOAD_FACTOR)
        return lldc__hashmap_grow(map);
        
    return 0;
}


int lldc_hashmap_replace (lldc_hashmap_t *map, const void *key, void *value)
{
    int r = 0;
    lldc_hashmap_entry_t *entry;
    uint64_t hash = map->hash(key);
    size_t idx = lldc__hashmap_find(map, hash, key, &entry);

    if (!entry->key)
    {
        entry->key = map->dup_key(map->m_ctx, key);
        if (!entry->key)
            return ENOMEM;
        
        map->len++;
    }

    entry->value = value;
    entry->hash = hash;

    if (lldc_hashmap_load_factor(map) >= LLDC_MAXIMUM_LOAD_FACTOR)
        return lldc__hashmap_grow(map);
        
    return 0;
}

void *lldc_hashmap_delete (lldc_hashmap_t *map, const void *key)
{
    lldc_hashmap_entry_t *entry;
    uint64_t hash = map->hash(key);
    size_t idx = lldc__hashmap_find(map, hash, key, &entry);

    if (!entry->key)
        return NULL;
    
    void *value = entry->value;

    map->free_key(map->m_ctx, entry->key);

    map->len--;

    size_t search_idx = (idx + 1) & (map->size - 1);

    for (size_t i = 0; i < map->size; i++)
    {
        if (!map->table[search_idx].key) /* Empty cell */
            break;

        /* If the new one has a lower or equal index */
        if ((map->table[search_idx].hash & (map->size - 1)) <= idx)
        {
            *entry = map->table[search_idx]; /* Replace the old entry with the new one */
            entry = &map->table[search_idx]; /* Set the entry to the new one */
            idx = map->table[search_idx].hash & (map->size - 1); /* Now find breaks in the chain for new one */
        }

        search_idx = (search_idx + 1) & (map->size - 1);
    }

    memset(entry, 0, sizeof(lldc_hashmap_entry_t));

    return value;
}

void *lldc_hashmap_get (lldc_hashmap_t *map, const void *key)
{
    lldc_hashmap_entry_t *entry;
    uint64_t hash = map->hash(key);
    size_t idx = lldc__hashmap_find(map, hash, key, &entry);

    if (entry->key)
        return entry->value;

    return NULL;
}

void lldc_hashmap_iterate (lldc_hashmap_t *map, lldc_hashmap_iterator iterator)
{
    for (size_t i = 0; i < map->size; i++)
        if (map->table[i].key)
            iterator(map->table[i].key, map->table[i].value);
}

void lldc_hashmap_free (lldc_hashmap_t *map)
{
    for (size_t i = 0; i < map->size; i++)
        if (map->table[i].key)
            map->free_key(map->m_ctx, map->table[i].key);

    cwr_free(map->m_ctx, map->table);

    map->size = 0;
    map->len = 0;
}
