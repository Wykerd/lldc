#include <lldc/parsers.h>
#include <lldc/gateway.h>

int main(int argc, char const *argv[])
{
    cwr_malloc_ctx_t m_ctx;
    cwr_malloc_ctx_new(&m_ctx); 

    const yyjson_alc json_alc = {
        .free = m_ctx.mf.cwr_free,
        .malloc = m_ctx.mf.cwr_malloc,
        .realloc = m_ctx.mf.cwr_realloc,
        .ctx = &m_ctx.ms
    };

    lldc_gateway_client_t gw;

    lldc_gateway_client_init(&m_ctx, uv_default_loop(), &gw);

    gw.identify.token = "tok";
    gw.identify.intents = LLDC_INTENT_GUILDS | LLDC_INTENT_GUILD_MESSAGES;
    gw.identify.properties.os = "linux";
    gw.identify.properties.lib_name = "lldc";

    lldc_activity_bot_t activities[] = {
        {
            .name = "LLDC DEV",
            .type = LLDC_ACTIVITY_WATCHING,
            .url = NULL
        }
    };

    gw.identify.presence.activities.items = activities;
    gw.identify.presence.activities.len = 1;
    gw.identify.presence.status = LLDC_CLIENT_STATUS_ONLINE;
/*
    cwr_buf_t buf;
    cwr_buf_malloc(&buf, &m_ctx, 10);
    lldc_gateway_identify_stringify(&gw.identify, &buf);
    fwrite(buf.base, buf.len, 1, stdout);*/

    lldc_gateway_client_connect(&gw);
    gw.json_alc = &json_alc;

    uv_run(uv_default_loop(), UV_RUN_DEFAULT);
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
