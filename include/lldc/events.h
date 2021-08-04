/**
 * Copyright 2021 Daniel Wykerd
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef LLDC_EVENTS_H
#define LLDC_EVENTS_H

#include <lldc/gateway.h>

int lldc_event_ready (lldc_gateway_client_t *client, yyjson_val *data);

#endif
