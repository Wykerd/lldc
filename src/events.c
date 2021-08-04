#include <lldc/events.h>

int lldc_event_ready (lldc_gateway_client_t *client, yyjson_val *data)
{
    client->status.resuming = 0;
    client->status.connected = 1;

    

    printf(">> Shard %d of %d connected, session_id=\n", 
        client->identify.shard[0] + 1, 
        client->identify.shard[1] ? client->identify.shard[1] : 1);
}
