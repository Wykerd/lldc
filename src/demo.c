#include <lldc/hashmap.h>

int main(int argc, char const *argv[])
{
    cwr_malloc_ctx_t m_ctx;
    lldc_hashmap_t map;

    cwr_malloc_ctx_new(&m_ctx);
    lldc_hashmap_init_str(&map, &m_ctx);

    char hello[] = "This is a test";
    char world[] = "And it works";
    char wide[] = "Wooh!!!";
    char event[] = "good";

    lldc_hashmap_set(&map, "hello", hello);
    lldc_hashmap_set(&map, "wide", wide);
    lldc_hashmap_set(&map, "world", world);
    lldc_hashmap_set(&map, "event", event);

    puts(lldc_hashmap_delete(&map, "wide"));
    puts(lldc_hashmap_get(&map, "hello"));
    puts(lldc_hashmap_get(&map, "world"));
    puts(lldc_hashmap_delete(&map, "event"));
    if (!lldc_hashmap_get(&map, "event"))
        puts("events not found");

    printf("len %zu\n", map.len);

    lldc_hashmap_free(&map);
    cwr_malloc_ctx_dump_leaks(&m_ctx);

    return 0;
}
