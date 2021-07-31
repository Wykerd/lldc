#include <lldc/parsers.h>

int main(int argc, char const *argv[])
{
    yyjson_doc *doc = yyjson_read("{\"code\":50035,\"errors\":{\"access_token\":{\"_errors\":[{\"code\":\"BASE_TYPE_REQUIRED\",\"message\":\"This field is required\"}]}},\"message\":\"Invalid Form Body\"}", 149, 0);

    cwr_malloc_ctx_t m_ctx;
    cwr_malloc_ctx_new(&m_ctx); 

    lldc_discord_error_t err;

    lldc_discord_error_parse(&m_ctx, &err, yyjson_doc_get_root(doc), 0);

    lldc_parser_free(&err);

    cwr_malloc_ctx_dump_leaks(&m_ctx);

    return 0;
}


/*
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
    puts(lldc_hashmap_get(&map, "hello"));
    puts(lldc_hashmap_get(&map, "world"));

    printf("len %zu\n", map.len);

    lldc_hashmap_free(&map);
    cwr_malloc_ctx_dump_leaks(&m_ctx);

    return 0;
}*/
