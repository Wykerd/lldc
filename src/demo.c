#include <lldc/parsers.h>

int main(int argc, char const *argv[])
{
    yyjson_doc *doc = yyjson_read("{\"id\":\"784340056030576660\",\"last_message_id\":\"871070902048149504\",\"last_pin_timestamp\":\"2021-05-17T12:15:43+00:00\",\"type\":0,\"name\":\"💬general-chat\",\"position\":11,\"parent_id\":\"739120567751409685\",\"topic\":null,\"guild_id\":\"715899956581630062\",\"permission_overwrites\":[{\"id\":\"715899956581630062\",\"type\":0,\"allow\":\"65536\",\"deny\":\"50176\"},{\"id\":\"716369069258833922\",\"type\":0,\"allow\":\"379968\",\"deny\":\"0\"},{\"id\":\"727199682840887396\",\"type\":0,\"allow\":\"388160\",\"deny\":\"135168\"},{\"id\":\"729056238968504391\",\"type\":0,\"allow\":\"66560\",\"deny\":\"192512\"},{\"id\":\"729354798637514803\",\"type\":0,\"allow\":\"66560\",\"deny\":\"2361408\"},{\"id\":\"731155521897496596\",\"type\":0,\"allow\":\"0\",\"deny\":\"49152\"},{\"id\":\"731440222205902908\",\"type\":0,\"allow\":\"392256\",\"deny\":\"805437457\"},{\"id\":\"737972678681690132\",\"type\":0,\"allow\":\"388160\",\"deny\":\"135168\"},{\"id\":\"752556415469748308\",\"type\":0,\"allow\":\"0\",\"deny\":\"1024\"},{\"id\":\"810599326400512010\",\"type\":0,\"allow\":\"114688\",\"deny\":\"393280\"},{\"id\":\"854106723601874984\",\"type\":0,\"allow\":\"379968\",\"deny\":\"2952933393\"}],\"nsfw\":false,\"rate_limit_per_user\":0}", 1061, 0);

    cwr_malloc_ctx_t m_ctx;
    cwr_malloc_ctx_new(&m_ctx); 

    lldc_channel_t err;

    lldc_channel_parse(&m_ctx, &err, yyjson_doc_get_root(doc), 0);

    lldc_parser_free(&err);

    cwr_malloc_ctx_dump_leaks(&m_ctx);

    yyjson_doc_free(doc);

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
