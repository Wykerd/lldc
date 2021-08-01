/**
* Copyright 2021 Daniel Wykerd
*
* Use of this source code is governed by an MIT-style
* license that can be found in the LICENSE file or at
* https://opensource.org/licenses/MIT.
*/

/**
 * This source has been automatically generated.
 * Do not edit it directly!
 * 
 * See scripts/gen_parser.js and the schemas in schemas/
 * for the sources used to generate this file
 */
#include <lldc/parsers.h>
#include <lldc/hashmap.h>
#include <stdlib.h>
/**
 * permissions Parser
 * OPTIONAL: computed permissions for the invoking user in the channel, including overwrites, only included when part of the resolved data received on a slash command interaction
 * type: object.touint
 */
static
int lldc__channel_permissions_parse (lldc_channel_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->permissions = (uint64_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * default_auto_archive_duration Parser
 * OPTIONAL: default duration for newly created threads, in minutes, to automatically archive the thread after recent activity, can be set to: 60, 1440, 4320, 10080
 * type: object.int
 */
static
int lldc__channel_default_auto_archive_duration_parse (lldc_channel_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->default_auto_archive_duration = yyjson_get_int(json);

    return 0;
}
/**
 * member_count Parser
 * OPTIONAL: an approximate count of users in a thread, stops counting at 50
 * type: object.int
 */
static
int lldc__channel_member_count_parse (lldc_channel_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->member_count = yyjson_get_int(json);

    return 0;
}
/**
 * message_count Parser
 * OPTIONAL: an approximate count of messages in a thread, stops counting at 50
 * type: object.int
 */
static
int lldc__channel_message_count_parse (lldc_channel_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->message_count = yyjson_get_int(json);

    return 0;
}
/**
 * video_quality_mode Parser
 * OPTIONAL: the camera video quality mode of the voice channel, 1 when not present
 * type: object.int
 */
static
int lldc__channel_video_quality_mode_parse (lldc_channel_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->video_quality_mode = yyjson_get_int(json);

    return 0;
}
/**
 * rtc_region Parser
 * OPTIONAL: voice region id for the voice channel, automatic when set to null
 * type: object.string
 */
static
int lldc__channel_rtc_region_parse (lldc_channel_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->rtc_region = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * last_pin_timestamp Parser
 * OPTIONAL: when the last pinned message was pinned. This may be null in events such as GUILD_CREATE when a message is not pinned.
 * type: object.timestamp
 */
static
int lldc__channel_last_pin_timestamp_parse (lldc_channel_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
    {
        obj->last_pin_timestamp = NAN;
        return -1;
    }

    obj->last_pin_timestamp = lldc_date_parse(yyjson_get_str(json));

    return 0;
}
/**
 * parent_id Parser
 * OPTIONAL: for guild channels: id of the parent category for a channel (each parent category can contain up to 50 channels), for threads: id of the text channel this thread was created
 * type: object.snowflake
 */
static
int lldc__channel_parent_id_parse (lldc_channel_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->parent_id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * application_id Parser
 * OPTIONAL: application id of the group DM creator if it is bot-created
 * type: object.snowflake
 */
static
int lldc__channel_application_id_parse (lldc_channel_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->application_id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * owner_id Parser
 * OPTIONAL: id of the creator of the group DM or thread
 * type: object.snowflake
 */
static
int lldc__channel_owner_id_parse (lldc_channel_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->owner_id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * icon Parser
 * OPTIONAL: icon hash
 * type: object.string
 */
static
int lldc__channel_icon_parse (lldc_channel_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->icon = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * rate_limit_per_user Parser
 * OPTIONAL: amount of seconds a user has to wait before sending another message (0-21600); bots, as well as users with the permission manage_messages or manage_channel, are unaffected
 * type: object.int
 */
static
int lldc__channel_rate_limit_per_user_parse (lldc_channel_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->rate_limit_per_user = yyjson_get_int(json);

    return 0;
}
/**
 * user_limit Parser
 * OPTIONAL: the user limit of the voice channel
 * type: object.int
 */
static
int lldc__channel_user_limit_parse (lldc_channel_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->user_limit = yyjson_get_int(json);

    return 0;
}
/**
 * bitrate Parser
 * OPTIONAL: the bitrate (in bits) of the voice channel
 * type: object.int
 */
static
int lldc__channel_bitrate_parse (lldc_channel_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->bitrate = yyjson_get_int(json);

    return 0;
}
/**
 * last_message_id Parser
 * OPTIONAL: the id of the last message sent in this channel (may not point to an existing or valid message)
 * type: object.snowflake
 */
static
int lldc__channel_last_message_id_parse (lldc_channel_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->last_message_id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * nsfw Parser
 * OPTIONAL: whether the channel is nsfw
 * type: object.bool
 */
static
int lldc__channel_nsfw_parse (lldc_channel_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_bool(json))
        return -1;

    obj->nsfw = yyjson_get_bool(json);

    return 0;
}
/**
 * topic Parser
 * OPTIONAL: the channel topic (0-1024 characters)
 * type: object.string
 */
static
int lldc__channel_topic_parse (lldc_channel_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->topic = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * name Parser
 * OPTIONAL: the name of the channel (1-100 characters)
 * type: object.string
 */
static
int lldc__channel_name_parse (lldc_channel_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->name = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * position Parser
 * OPTIONAL: sorting position of the channel
 * type: object.int
 */
static
int lldc__channel_position_parse (lldc_channel_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->position = yyjson_get_int(json);

    return 0;
}
/**
 * guild_id Parser
 * OPTIONAL: the id of the guild (may be missing for some channel objects received over gateway guild dispatches)
 * type: object.snowflake
 */
static
int lldc__channel_guild_id_parse (lldc_channel_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->guild_id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * type Parser
 * the type of channel
 * type: object.int
 */
static
int lldc__channel_type_parse (lldc_channel_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->type = yyjson_get_int(json);

    return 0;
}
/**
 * id Parser
 * the id of this channel
 * type: object.snowflake
 */
static
int lldc__channel_id_parse (lldc_channel_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * thread Parser
 * OPTIONAL: the thread that was started from this message, includes thread member object. You should parse this yourself if you want it.
 * type: object.rawobj
 */
static
int lldc__message_thread_parse (lldc_message_t *obj, yyjson_val *json) 
{
    obj->thread = json;

    return 0;
}
/**
 * flags Parser
 * OPTIONAL: message flags combined as a bitfield
 * type: object.int
 */
static
int lldc__message_flags_parse (lldc_message_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->flags = yyjson_get_int(json);

    return 0;
}
/**
 * application_id Parser
 * OPTIONAL: if the message is a response to an Interaction, this is the id of the interaction's application
 * type: object.snowflake
 */
static
int lldc__message_application_id_parse (lldc_message_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->application_id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * application Parser
 * OPTIONAL: sent with Rich Presence-related chat embeds
 * type: object.rawobj
 */
static
int lldc__message_application_parse (lldc_message_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_obj(json))
        return -1;

    obj->application = json;

    return 0;
}
/**
 * activity Parser
 * OPTIONAL: sent with Rich Presence-related chat embeds
 * type: object.rawobj
 */
static
int lldc__message_activity_parse (lldc_message_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_obj(json))
        return -1;

    obj->activity = json;

    return 0;
}
/**
 * type Parser
 * type of message
 * type: object.int
 */
static
int lldc__message_type_parse (lldc_message_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->type = yyjson_get_int(json);

    return 0;
}
/**
 * webhook_id Parser
 * OPTIONAL: if the message is generated by a webhook, this is the webhook's id
 * type: object.snowflake
 */
static
int lldc__message_webhook_id_parse (lldc_message_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->webhook_id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * pinned Parser
 * whether this message is pinned
 * type: object.bool
 */
static
int lldc__message_pinned_parse (lldc_message_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_bool(json))
        return -1;

    obj->pinned = yyjson_get_bool(json);

    return 0;
}
/**
 * mention_everyone Parser
 * whether this message mentions everyone
 * type: object.bool
 */
static
int lldc__message_mention_everyone_parse (lldc_message_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_bool(json))
        return -1;

    obj->mention_everyone = yyjson_get_bool(json);

    return 0;
}
/**
 * tts Parser
 * whether this was a TTS message
 * type: object.bool
 */
static
int lldc__message_tts_parse (lldc_message_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_bool(json))
        return -1;

    obj->tts = yyjson_get_bool(json);

    return 0;
}
/**
 * edited_timestamp Parser
 * OPTIONAL: when this message was edited (or null if never)
 * type: object.timestamp
 */
static
int lldc__message_edited_timestamp_parse (lldc_message_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
    {
        obj->edited_timestamp = NAN;
        return -1;
    }

    obj->edited_timestamp = lldc_date_parse(yyjson_get_str(json));

    return 0;
}
/**
 * timestamp Parser
 * when this message was sent
 * type: object.timestamp
 */
static
int lldc__message_timestamp_parse (lldc_message_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
    {
        obj->timestamp = NAN;
        return -1;
    }

    obj->timestamp = lldc_date_parse(yyjson_get_str(json));

    return 0;
}
/**
 * content Parser
 * contents of the message
 * type: object.string
 */
static
int lldc__message_content_parse (lldc_message_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->content = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * guild_id Parser
 * OPTIONAL: id of the guild the message was sent in
 * type: object.snowflake
 */
static
int lldc__message_guild_id_parse (lldc_message_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->guild_id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * channel_id Parser
 * id of the channel the message was sent in
 * type: object.snowflake
 */
static
int lldc__message_channel_id_parse (lldc_message_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->channel_id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * id Parser
 * id of the message
 * type: object.snowflake
 */
static
int lldc__message_id_parse (lldc_message_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * name Parser
 * the name of the application command
 * type: object.string
 */
static
int lldc__message_interaction_name_parse (lldc_message_interaction_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->name = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * type Parser
 * the type of interaction
 * type: object.int
 */
static
int lldc__message_interaction_type_parse (lldc_message_interaction_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->type = yyjson_get_int(json);

    return 0;
}
/**
 * id Parser
 * id of the interaction
 * type: object.snowflake
 */
static
int lldc__message_interaction_id_parse (lldc_message_interaction_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * fail_if_not_exists Parser
 * OPTIONAL: when sending, whether to error if the referenced message doesn't exist instead of sending as a normal (non-reply) message, default true
 * type: object.bool
 */
static
int lldc__message_reference_fail_if_not_exists_parse (lldc_message_reference_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_bool(json))
        return -1;

    obj->fail_if_not_exists = yyjson_get_bool(json);

    return 0;
}
/**
 * guild_id Parser
 * OPTIONAL: id of the originating message's guild
 * type: object.snowflake
 */
static
int lldc__message_reference_guild_id_parse (lldc_message_reference_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->guild_id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * channel_id Parser
 * OPTIONAL: id of the originating message's channel
 * type: object.snowflake
 */
static
int lldc__message_reference_channel_id_parse (lldc_message_reference_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->channel_id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * message_id Parser
 * OPTIONAL: id of the originating message
 * type: object.snowflake
 */
static
int lldc__message_reference_message_id_parse (lldc_message_reference_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->message_id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * party_id Parser
 * OPTIONAL: party_id from a Rich Presence event
 * type: object.string
 */
static
int lldc__message_activity_party_id_parse (lldc_message_activity_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->party_id = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * type Parser
 * type of message activity
 * type: object.int
 */
static
int lldc__message_activity_type_parse (lldc_message_activity_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->type = yyjson_get_int(json);

    return 0;
}
/**
 * format_type Parser
 * type of sticker format
 * type: object.int
 */
static
int lldc__sticker_item_format_type_parse (lldc_sticker_item_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->format_type = yyjson_get_int(json);

    return 0;
}
/**
 * name Parser
 * name of the sticker
 * type: object.string
 */
static
int lldc__sticker_item_name_parse (lldc_sticker_item_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->name = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * id Parser
 * id of the sticker
 * type: object.snowflake
 */
static
int lldc__sticker_item_id_parse (lldc_sticker_item_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * max_values Parser
 * OPTIONAL: the maximum number of items that can be chosen; default 1, max 25
 * type: object.int
 */
static
int lldc__component_max_values_parse (lldc_component_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->max_values = yyjson_get_int(json);

    return 0;
}
/**
 * min_values Parser
 * OPTIONAL: the minimum number of items that must be chosen; default 1, min 0, max 25
 * type: object.int
 */
static
int lldc__component_min_values_parse (lldc_component_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->min_values = yyjson_get_int(json);

    return 0;
}
/**
 * placeholder Parser
 * OPTIONAL: custom placeholder text if nothing is selected, max 100 characters
 * type: object.string
 */
static
int lldc__component_placeholder_parse (lldc_component_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->placeholder = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * url Parser
 * OPTIONAL: a url for link-style buttons
 * type: object.string
 */
static
int lldc__component_url_parse (lldc_component_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->url = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * label Parser
 * OPTIONAL: text that appears on the button, max 80 characters
 * type: object.string
 */
static
int lldc__component_label_parse (lldc_component_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->label = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * style Parser
 * OPTIONAL: one of button styles
 * type: object.int
 */
static
int lldc__component_style_parse (lldc_component_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->style = yyjson_get_int(json);

    return 0;
}
/**
 * disabled Parser
 * OPTIONAL: whether the component is disabled, default false
 * type: object.bool
 */
static
int lldc__component_disabled_parse (lldc_component_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_bool(json))
        return -1;

    obj->disabled = yyjson_get_bool(json);

    return 0;
}
/**
 * custom_id Parser
 * OPTIONAL: a developer-defined identifier for the component, max 100 characters
 * type: object.string
 */
static
int lldc__component_custom_id_parse (lldc_component_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->custom_id = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * type Parser
 * component type
 * type: object.int
 */
static
int lldc__component_type_parse (lldc_component_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->type = yyjson_get_int(json);

    return 0;
}
/**
 * default Parser
 * OPTIONAL: will render this option as selected by default
 * type: object.bool
 */
static
int lldc__select_option_is_default_parse (lldc_select_option_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_bool(json))
        return -1;

    obj->is_default = yyjson_get_bool(json);

    return 0;
}
/**
 * description Parser
 * OPTIONAL: an additional description of the option, max 50 characters
 * type: object.string
 */
static
int lldc__select_option_description_parse (lldc_select_option_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->description = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * value Parser
 * the dev-define value of the option, max 100 characters
 * type: object.string
 */
static
int lldc__select_option_value_parse (lldc_select_option_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->value = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * label Parser
 * the user-facing name of the option, max 25 characters
 * type: object.string
 */
static
int lldc__select_option_label_parse (lldc_select_option_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->label = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * name Parser
 * name of the account
 * type: object.string
 */
static
int lldc__interaction_account_name_parse (lldc_interaction_account_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->name = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * id Parser
 * id of the account
 * type: object.string
 */
static
int lldc__interaction_account_id_parse (lldc_interaction_account_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->id = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * me Parser
 * whether the current user reacted using this emoji
 * type: object.bool
 */
static
int lldc__reaction_me_parse (lldc_reaction_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_bool(json))
        return -1;

    obj->me = yyjson_get_bool(json);

    return 0;
}
/**
 * count Parser
 * times this emoji has been used to react
 * type: object.int
 */
static
int lldc__reaction_count_parse (lldc_reaction_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->count = yyjson_get_int(json);

    return 0;
}
/**
 * available Parser
 * OPTIONAL: whether this emoji can be used, may be false due to loss of Server Boosts
 * type: object.bool
 */
static
int lldc__emoji_available_parse (lldc_emoji_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_bool(json))
        return -1;

    obj->available = yyjson_get_bool(json);

    return 0;
}
/**
 * animated Parser
 * OPTIONAL: whether this emoji is animated
 * type: object.bool
 */
static
int lldc__emoji_animated_parse (lldc_emoji_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_bool(json))
        return -1;

    obj->animated = yyjson_get_bool(json);

    return 0;
}
/**
 * managed Parser
 * OPTIONAL: whether this emoji is managed
 * type: object.bool
 */
static
int lldc__emoji_managed_parse (lldc_emoji_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_bool(json))
        return -1;

    obj->managed = yyjson_get_bool(json);

    return 0;
}
/**
 * require_colons Parser
 * OPTIONAL: whether this emoji must be wrapped in colons
 * type: object.bool
 */
static
int lldc__emoji_require_colons_parse (lldc_emoji_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_bool(json))
        return -1;

    obj->require_colons = yyjson_get_bool(json);

    return 0;
}
/**
 * name Parser
 * OPTIONAL: emoji name
 * type: object.string
 */
static
int lldc__emoji_name_parse (lldc_emoji_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->name = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * id Parser
 * OPTIONAL: emoji id
 * type: object.snowflake
 */
static
int lldc__emoji_id_parse (lldc_emoji_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * color Parser
 * OPTIONAL: color code of the embed
 * type: object.int
 */
static
int lldc__embed_color_parse (lldc_embed_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->color = yyjson_get_int(json);

    return 0;
}
/**
 * timestamp Parser
 * OPTIONAL: timestamp of embed content
 * type: object.timestamp
 */
static
int lldc__embed_timestamp_parse (lldc_embed_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
    {
        obj->timestamp = NAN;
        return -1;
    }

    obj->timestamp = lldc_date_parse(yyjson_get_str(json));

    return 0;
}
/**
 * url Parser
 * OPTIONAL: url of embed
 * type: object.string
 */
static
int lldc__embed_url_parse (lldc_embed_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->url = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * description Parser
 * OPTIONAL: description of embed
 * type: object.string
 */
static
int lldc__embed_description_parse (lldc_embed_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->description = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * type Parser
 * OPTIONAL: type of embed (always "rich" for webhook embeds)
 * type: object.string
 */
static
int lldc__embed_type_parse (lldc_embed_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->type = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * title Parser
 * OPTIONAL: title of embed
 * type: object.string
 */
static
int lldc__embed_title_parse (lldc_embed_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->title = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * inline Parser
 * OPTIONAL: whether or not this field should display inline
 * type: object.bool
 */
static
int lldc__embed_field_is_inline_parse (lldc_embed_field_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_bool(json))
        return -1;

    obj->is_inline = yyjson_get_bool(json);

    return 0;
}
/**
 * value Parser
 * value of the field
 * type: object.string
 */
static
int lldc__embed_field_value_parse (lldc_embed_field_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->value = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * name Parser
 * name of the field
 * type: object.string
 */
static
int lldc__embed_field_name_parse (lldc_embed_field_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->name = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * width Parser
 * OPTIONAL: width of video
 * type: object.int
 */
static
int lldc__embed_video_width_parse (lldc_embed_video_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->width = yyjson_get_int(json);

    return 0;
}
/**
 * height Parser
 * OPTIONAL: height of video
 * type: object.int
 */
static
int lldc__embed_video_height_parse (lldc_embed_video_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->height = yyjson_get_int(json);

    return 0;
}
/**
 * proxy_url Parser
 * OPTIONAL: a proxied url of the video
 * type: object.string
 */
static
int lldc__embed_video_proxy_url_parse (lldc_embed_video_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->proxy_url = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * url Parser
 * OPTIONAL: source url of video
 * type: object.string
 */
static
int lldc__embed_video_url_parse (lldc_embed_video_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->url = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * width Parser
 * OPTIONAL: width of thumbnail
 * type: object.int
 */
static
int lldc__embed_thumbnail_width_parse (lldc_embed_thumbnail_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->width = yyjson_get_int(json);

    return 0;
}
/**
 * height Parser
 * OPTIONAL: height of thumbnail
 * type: object.int
 */
static
int lldc__embed_thumbnail_height_parse (lldc_embed_thumbnail_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->height = yyjson_get_int(json);

    return 0;
}
/**
 * proxy_url Parser
 * OPTIONAL: a proxied url of the thumbnail
 * type: object.string
 */
static
int lldc__embed_thumbnail_proxy_url_parse (lldc_embed_thumbnail_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->proxy_url = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * url Parser
 * OPTIONAL: source url of thumbnail (only supports http(s) and attachments)
 * type: object.string
 */
static
int lldc__embed_thumbnail_url_parse (lldc_embed_thumbnail_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->url = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * url Parser
 * OPTIONAL: url of provider
 * type: object.string
 */
static
int lldc__embed_provider_url_parse (lldc_embed_provider_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->url = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * name Parser
 * OPTIONAL: name of provider
 * type: object.string
 */
static
int lldc__embed_provider_name_parse (lldc_embed_provider_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->name = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * width Parser
 * OPTIONAL: width of image
 * type: object.int
 */
static
int lldc__embed_image_width_parse (lldc_embed_image_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->width = yyjson_get_int(json);

    return 0;
}
/**
 * height Parser
 * OPTIONAL: height of image
 * type: object.int
 */
static
int lldc__embed_image_height_parse (lldc_embed_image_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->height = yyjson_get_int(json);

    return 0;
}
/**
 * proxy_url Parser
 * OPTIONAL: a proxied url of the image
 * type: object.string
 */
static
int lldc__embed_image_proxy_url_parse (lldc_embed_image_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->proxy_url = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * url Parser
 * OPTIONAL: source url of image (only supports http(s) and attachments)
 * type: object.string
 */
static
int lldc__embed_image_url_parse (lldc_embed_image_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->url = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * proxy_icon_url Parser
 * OPTIONAL: a proxied url of footer icon
 * type: object.string
 */
static
int lldc__embed_footer_proxy_icon_url_parse (lldc_embed_footer_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->proxy_icon_url = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * icon_url Parser
 * OPTIONAL: url of footer icon (only supports http(s) and attachments)
 * type: object.string
 */
static
int lldc__embed_footer_icon_url_parse (lldc_embed_footer_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->icon_url = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * text Parser
 * footer text
 * type: object.string
 */
static
int lldc__embed_footer_text_parse (lldc_embed_footer_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->text = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * proxy_icon_url Parser
 * OPTIONAL: a proxied url of author icon
 * type: object.string
 */
static
int lldc__embed_author_proxy_icon_url_parse (lldc_embed_author_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->proxy_icon_url = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * icon_url Parser
 * OPTIONAL: url of author icon (only supports http(s) and attachments)
 * type: object.string
 */
static
int lldc__embed_author_icon_url_parse (lldc_embed_author_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->icon_url = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * url Parser
 * OPTIONAL: url of author
 * type: object.string
 */
static
int lldc__embed_author_url_parse (lldc_embed_author_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->url = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * name Parser
 * OPTIONAL: name of author
 * type: object.string
 */
static
int lldc__embed_author_name_parse (lldc_embed_author_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->name = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * name Parser
 * the name of the channel
 * type: object.string
 */
static
int lldc__channel_mention_name_parse (lldc_channel_mention_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->name = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * type Parser
 * the type of channel
 * type: object.int
 */
static
int lldc__channel_mention_type_parse (lldc_channel_mention_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->type = yyjson_get_int(json);

    return 0;
}
/**
 * guild_id Parser
 * id of the guild containing the channel
 * type: object.snowflake
 */
static
int lldc__channel_mention_guild_id_parse (lldc_channel_mention_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->guild_id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * id Parser
 * id of the channel
 * type: object.snowflake
 */
static
int lldc__channel_mention_id_parse (lldc_channel_mention_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * width Parser
 * OPTIONAL: width of file (if image)
 * type: object.int
 */
static
int lldc__attachment_width_parse (lldc_attachment_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->width = yyjson_get_int(json);

    return 0;
}
/**
 * height Parser
 * OPTIONAL: height of file (if image)
 * type: object.int
 */
static
int lldc__attachment_height_parse (lldc_attachment_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->height = yyjson_get_int(json);

    return 0;
}
/**
 * proxy_url Parser
 * a proxied url of file
 * type: object.string
 */
static
int lldc__attachment_proxy_url_parse (lldc_attachment_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->proxy_url = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * url Parser
 * source url of file
 * type: object.string
 */
static
int lldc__attachment_url_parse (lldc_attachment_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->url = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * size Parser
 * size of file in bytes
 * type: object.int
 */
static
int lldc__attachment_size_parse (lldc_attachment_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->size = yyjson_get_int(json);

    return 0;
}
/**
 * content_type Parser
 * OPTIONAL: the attachment's media type
 * type: object.string
 */
static
int lldc__attachment_content_type_parse (lldc_attachment_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->content_type = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * filename Parser
 * name of file attached
 * type: object.string
 */
static
int lldc__attachment_filename_parse (lldc_attachment_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->filename = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * id Parser
 * attachment id
 * type: object.snowflake
 */
static
int lldc__attachment_id_parse (lldc_attachment_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * flags Parser
 * any user-thread settings, currently only used for notifications
 * type: object.int
 */
static
int lldc__thread_member_flags_parse (lldc_thread_member_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->flags = yyjson_get_int(json);

    return 0;
}
/**
 * join_timestamp Parser
 * the time the current user last joined the thread
 * type: object.timestamp
 */
static
int lldc__thread_member_join_timestamp_parse (lldc_thread_member_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
    {
        obj->join_timestamp = NAN;
        return -1;
    }

    obj->join_timestamp = lldc_date_parse(yyjson_get_str(json));

    return 0;
}
/**
 * user_id Parser
 * OPTIONAL: the id of the user
 * type: object.snowflake
 */
static
int lldc__thread_member_user_id_parse (lldc_thread_member_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->user_id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * id Parser
 * OPTIONAL: the id of the thread
 * type: object.snowflake
 */
static
int lldc__thread_member_id_parse (lldc_thread_member_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * locked Parser
 * OPTIONAL: whether the thread is locked; when a thread is locked, only users with MANAGE_THREADS can unarchive it
 * type: object.bool
 */
static
int lldc__thread_metadata_locked_parse (lldc_thread_metadata_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_bool(json))
        return -1;

    obj->locked = yyjson_get_bool(json);

    return 0;
}
/**
 * archive_timestamp Parser
 * timestamp when the thread's archive status was last changed, used for calculating recent activity
 * type: object.timestamp
 */
static
int lldc__thread_metadata_archive_timestamp_parse (lldc_thread_metadata_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
    {
        obj->archive_timestamp = NAN;
        return -1;
    }

    obj->archive_timestamp = lldc_date_parse(yyjson_get_str(json));

    return 0;
}
/**
 * auto_archive_duration Parser
 * duration in minutes to automatically archive the thread after recent activity, can be set to: 60, 1440, 4320, 10080
 * type: object.int
 */
static
int lldc__thread_metadata_auto_archive_duration_parse (lldc_thread_metadata_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->auto_archive_duration = yyjson_get_int(json);

    return 0;
}
/**
 * archived Parser
 * whether the thread is archived
 * type: object.bool
 */
static
int lldc__thread_metadata_archived_parse (lldc_thread_metadata_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_bool(json))
        return -1;

    obj->archived = yyjson_get_bool(json);

    return 0;
}
/**
 * deny Parser
 * permission bit set
 * type: object.touint
 */
static
int lldc__channel_overwrite_deny_parse (lldc_channel_overwrite_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->deny = (uint64_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * allow Parser
 * permission bit set
 * type: object.touint
 */
static
int lldc__channel_overwrite_allow_parse (lldc_channel_overwrite_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->allow = (uint64_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * type Parser
 * either 0 (role) or 1 (member)
 * type: object.int
 */
static
int lldc__channel_overwrite_type_parse (lldc_channel_overwrite_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->type = yyjson_get_int(json);

    return 0;
}
/**
 * id Parser
 * role or user id
 * type: object.snowflake
 */
static
int lldc__channel_overwrite_id_parse (lldc_channel_overwrite_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * permissions Parser
 * OPTIONAL: total permissions of the member in the channel, including overwrites, returned when in the interaction object
 * type: object.string
 */
static
int lldc__partial_guild_member_permissions_parse (lldc_partial_guild_member_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->permissions = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * pending Parser
 * OPTIONAL: whether the user has not yet passed the guild's Membership Screening requirements
 * type: object.bool
 */
static
int lldc__partial_guild_member_pending_parse (lldc_partial_guild_member_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_bool(json))
        return -1;

    obj->pending = yyjson_get_bool(json);

    return 0;
}
/**
 * mute Parser
 * whether the user is muted in voice channels
 * type: object.bool
 */
static
int lldc__partial_guild_member_mute_parse (lldc_partial_guild_member_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_bool(json))
        return -1;

    obj->mute = yyjson_get_bool(json);

    return 0;
}
/**
 * deaf Parser
 * whether the user is deafened in voice channels
 * type: object.bool
 */
static
int lldc__partial_guild_member_deaf_parse (lldc_partial_guild_member_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_bool(json))
        return -1;

    obj->deaf = yyjson_get_bool(json);

    return 0;
}
/**
 * premium_since Parser
 * OPTIONAL: when the user started boosting the guild
 * type: object.timestamp
 */
static
int lldc__partial_guild_member_premium_since_parse (lldc_partial_guild_member_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
    {
        obj->premium_since = NAN;
        return -1;
    }

    obj->premium_since = lldc_date_parse(yyjson_get_str(json));

    return 0;
}
/**
 * joined_at Parser
 * when the user joined the guild
 * type: object.timestamp
 */
static
int lldc__partial_guild_member_joined_at_parse (lldc_partial_guild_member_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
    {
        obj->joined_at = NAN;
        return -1;
    }

    obj->joined_at = lldc_date_parse(yyjson_get_str(json));

    return 0;
}
/**
 * nick Parser
 * OPTIONAL: this users guild nickname
 * type: object.string
 */
static
int lldc__partial_guild_member_nick_parse (lldc_partial_guild_member_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->nick = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * permissions Parser
 * OPTIONAL: total permissions of the member in the channel, including overwrites, returned when in the interaction object
 * type: object.string
 */
static
int lldc__guild_member_permissions_parse (lldc_guild_member_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->permissions = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * pending Parser
 * OPTIONAL: whether the user has not yet passed the guild's Membership Screening requirements
 * type: object.bool
 */
static
int lldc__guild_member_pending_parse (lldc_guild_member_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_bool(json))
        return -1;

    obj->pending = yyjson_get_bool(json);

    return 0;
}
/**
 * mute Parser
 * whether the user is muted in voice channels
 * type: object.bool
 */
static
int lldc__guild_member_mute_parse (lldc_guild_member_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_bool(json))
        return -1;

    obj->mute = yyjson_get_bool(json);

    return 0;
}
/**
 * deaf Parser
 * whether the user is deafened in voice channels
 * type: object.bool
 */
static
int lldc__guild_member_deaf_parse (lldc_guild_member_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_bool(json))
        return -1;

    obj->deaf = yyjson_get_bool(json);

    return 0;
}
/**
 * premium_since Parser
 * OPTIONAL: when the user started boosting the guild
 * type: object.timestamp
 */
static
int lldc__guild_member_premium_since_parse (lldc_guild_member_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
    {
        obj->premium_since = NAN;
        return -1;
    }

    obj->premium_since = lldc_date_parse(yyjson_get_str(json));

    return 0;
}
/**
 * joined_at Parser
 * when the user joined the guild
 * type: object.timestamp
 */
static
int lldc__guild_member_joined_at_parse (lldc_guild_member_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
    {
        obj->joined_at = NAN;
        return -1;
    }

    obj->joined_at = lldc_date_parse(yyjson_get_str(json));

    return 0;
}
/**
 * nick Parser
 * OPTIONAL: this users guild nickname
 * type: object.string
 */
static
int lldc__guild_member_nick_parse (lldc_guild_member_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->nick = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * type Parser
 * integration type (twitch, youtube, or discord)
 * type: object.string
 */
static
int lldc__audit_log_integrations_item_type_parse (lldc_audit_log_integrations_item_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->type = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * name Parser
 * integration name
 * type: object.string
 */
static
int lldc__audit_log_integrations_item_name_parse (lldc_audit_log_integrations_item_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->name = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * id Parser
 * integration id
 * type: object.snowflake
 */
static
int lldc__audit_log_integrations_item_id_parse (lldc_audit_log_integrations_item_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * reason Parser
 * OPTIONAL: the reason for the change (0-512 characters)
 * type: object.string
 */
static
int lldc__audit_log_entry_reason_parse (lldc_audit_log_entry_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->reason = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * action_type Parser
 * type of action that occured
 * type: object.int
 */
static
int lldc__audit_log_entry_action_type_parse (lldc_audit_log_entry_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->action_type = yyjson_get_int(json);

    return 0;
}
/**
 * id Parser
 * id of the entry
 * type: object.snowflake
 */
static
int lldc__audit_log_entry_id_parse (lldc_audit_log_entry_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * user_id Parser
 * OPTIONAL: the user who made the changes
 * type: object.snowflake
 */
static
int lldc__audit_log_entry_user_id_parse (lldc_audit_log_entry_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->user_id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * target_id Parser
 * OPTIONAL: id of the affected entity (webhook, user, role, etc.)
 * type: object.snowflake
 */
static
int lldc__audit_log_entry_target_id_parse (lldc_audit_log_entry_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->target_id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * role_name Parser
 * name of the role if type is "0" (not present if type is "1")
 * type: object.string
 */
static
int lldc__audit_log_options_role_name_parse (lldc_audit_log_options_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->role_name = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * type Parser
 * type of overwritten entity - "0" for "role" or "1" for "member"
 * type: object.string
 */
static
int lldc__audit_log_options_type_parse (lldc_audit_log_options_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->type = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * id Parser
 * id of the overwritten entity
 * type: object.snowflake
 */
static
int lldc__audit_log_options_id_parse (lldc_audit_log_options_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * count Parser
 * number of entities that were targeted
 * type: object.string
 */
static
int lldc__audit_log_options_count_parse (lldc_audit_log_options_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->count = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * message_id Parser
 * id of the message that was targeted
 * type: object.snowflake
 */
static
int lldc__audit_log_options_message_id_parse (lldc_audit_log_options_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->message_id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * channel_id Parser
 * channel in which the entities were targeted
 * type: object.snowflake
 */
static
int lldc__audit_log_options_channel_id_parse (lldc_audit_log_options_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->channel_id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * members_removed Parser
 * number of members removed by the prune
 * type: object.string
 */
static
int lldc__audit_log_options_members_removed_parse (lldc_audit_log_options_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->members_removed = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * delete_member_days Parser
 * number of days after which inactive members were kicked
 * type: object.string
 */
static
int lldc__audit_log_options_delete_member_days_parse (lldc_audit_log_options_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->delete_member_days = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * key Parser
 * name of audit log change key
 * type: object.string
 */
static
int lldc__audit_log_changes_key_parse (lldc_audit_log_changes_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->key = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * old_value Parser
 * OPTIONAL: old value of the key
 * type: object.rawobj
 */
static
int lldc__audit_log_changes_old_value_parse (lldc_audit_log_changes_t *obj, yyjson_val *json) 
{
    obj->old_value = json;

    return 0;
}
/**
 * new_value Parser
 * OPTIONAL: new value of the key
 * type: object.rawobj
 */
static
int lldc__audit_log_changes_new_value_parse (lldc_audit_log_changes_t *obj, yyjson_val *json) 
{
    obj->new_value = json;

    return 0;
}
/**
 * url Parser
 * OPTIONAL: the url used for executing the webhook (returned by the webhooks OAuth2 flow)
 * type: object.string
 */
static
int lldc__webhook_url_parse (lldc_webhook_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->url = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * name Parser
 * the name of the channel (1-100 characters)
 * type: object.string
 */
static
int lldc__webhook_source_channel_name_parse (lldc_webhook_source_channel_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->name = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * id Parser
 * the id of this channel
 * type: object.snowflake
 */
static
int lldc__webhook_source_channel_id_parse (lldc_webhook_source_channel_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * icon Parser
 * OPTIONAL: icon hash
 * type: object.string
 */
static
int lldc__webhook_source_guild_icon_parse (lldc_webhook_source_guild_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->icon = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * name Parser
 * guild name (2-100 characters, excluding trailing and leading whitespace)
 * type: object.string
 */
static
int lldc__webhook_source_guild_name_parse (lldc_webhook_source_guild_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->name = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * id Parser
 * guild id
 * type: object.snowflake
 */
static
int lldc__webhook_source_guild_id_parse (lldc_webhook_source_guild_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * application_id Parser
 * OPTIONAL: the bot/OAuth2 application that created this webhook
 * type: object.snowflake
 */
static
int lldc__webhook_application_id_parse (lldc_webhook_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->application_id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * token Parser
 * OPTIONAL: the secure token of the webhook (returned for Incoming Webhooks)
 * type: object.string
 */
static
int lldc__webhook_token_parse (lldc_webhook_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->token = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * avatar Parser
 * OPTIONAL: the default user avatar hash of the webhook
 * type: object.string
 */
static
int lldc__webhook_avatar_parse (lldc_webhook_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->avatar = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * name Parser
 * OPTIONAL: the default name of the webhook
 * type: object.string
 */
static
int lldc__webhook_name_parse (lldc_webhook_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->name = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * channel_id Parser
 * OPTIONAL: the channel id this webhook is for, if any
 * type: object.snowflake
 */
static
int lldc__webhook_channel_id_parse (lldc_webhook_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->channel_id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * guild_id Parser
 * OPTIONAL: the guild id this webhook is for, if any
 * type: object.snowflake
 */
static
int lldc__webhook_guild_id_parse (lldc_webhook_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->guild_id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * type Parser
 * the type of the webhook
 * type: object.int
 */
static
int lldc__webhook_type_parse (lldc_webhook_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->type = yyjson_get_int(json);

    return 0;
}
/**
 * id Parser
 * the id of the webhook
 * type: object.snowflake
 */
static
int lldc__webhook_id_parse (lldc_webhook_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * flags Parser
 * OPTIONAL: the application's public flags
 * type: object.int
 */
static
int lldc__application_flags_parse (lldc_application_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->flags = yyjson_get_int(json);

    return 0;
}
/**
 * cover_image Parser
 * OPTIONAL: the application's default rich presence invite cover image hash
 * type: object.string
 */
static
int lldc__application_cover_image_parse (lldc_application_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->cover_image = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * slug Parser
 * OPTIONAL: if this application is a game sold on Discord, this field will be the URL slug that links to the store page
 * type: object.string
 */
static
int lldc__application_slug_parse (lldc_application_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->slug = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * primary_sku_id Parser
 * OPTIONAL: if this application is a game sold on Discord, this field will be the id of the "Game SKU" that is created, if exists
 * type: object.snowflake
 */
static
int lldc__application_primary_sku_id_parse (lldc_application_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->primary_sku_id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * guild_id Parser
 * OPTIONAL: if this application is a game sold on Discord, this field will be the guild to which it has been linked
 * type: object.snowflake
 */
static
int lldc__application_guild_id_parse (lldc_application_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->guild_id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * verify_key Parser
 * the hex encoded key for verification in interactions and the GameSDK's GetTicket
 * type: object.string
 */
static
int lldc__application_verify_key_parse (lldc_application_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->verify_key = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * summary Parser
 * if this application is a game sold on Discord, this field will be the summary field for the store page of its primary sku
 * type: object.string
 */
static
int lldc__application_summary_parse (lldc_application_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->summary = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * privacy_policy_url Parser
 * OPTIONAL: the url of the app's privacy policy
 * type: object.string
 */
static
int lldc__application_privacy_policy_url_parse (lldc_application_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->privacy_policy_url = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * terms_of_service_url Parser
 * OPTIONAL: the url of the app's terms of service
 * type: object.string
 */
static
int lldc__application_terms_of_service_url_parse (lldc_application_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->terms_of_service_url = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * bot_require_code_grant Parser
 * when true the app's bot will only join upon completion of the full oauth2 code grant flow
 * type: object.bool
 */
static
int lldc__application_bot_require_code_grant_parse (lldc_application_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_bool(json))
        return -1;

    obj->bot_require_code_grant = yyjson_get_bool(json);

    return 0;
}
/**
 * bot_public Parser
 * when false only app owner can join the app's bot to guilds
 * type: object.bool
 */
static
int lldc__application_bot_public_parse (lldc_application_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_bool(json))
        return -1;

    obj->bot_public = yyjson_get_bool(json);

    return 0;
}
/**
 * description Parser
 * the description of the app
 * type: object.string
 */
static
int lldc__application_description_parse (lldc_application_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->description = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * icon Parser
 * OPTIONAL: the icon hash of the app
 * type: object.string
 */
static
int lldc__application_icon_parse (lldc_application_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->icon = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * name Parser
 * the name of the app
 * type: object.string
 */
static
int lldc__application_name_parse (lldc_application_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->name = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * id Parser
 * the id of the app
 * type: object.snowflake
 */
static
int lldc__application_id_parse (lldc_application_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * owner_user_id Parser
 * the user id of the current team owner
 * type: object.snowflake
 */
static
int lldc__team_owner_user_id_parse (lldc_team_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->owner_user_id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * name Parser
 * the name of the team
 * type: object.string
 */
static
int lldc__team_name_parse (lldc_team_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->name = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * id Parser
 * the unique id of the team
 * type: object.snowflake
 */
static
int lldc__team_id_parse (lldc_team_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * icon Parser
 * OPTIONAL: a hash of the image of the team's icon
 * type: object.string
 */
static
int lldc__team_icon_parse (lldc_team_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->icon = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * team_id Parser
 * the id of the parent team of which they are a member
 * type: object.snowflake
 */
static
int lldc__team_member_team_id_parse (lldc_team_member_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->team_id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * membership_state Parser
 * the user's membership state on the team
 * type: object.int
 */
static
int lldc__team_member_membership_state_parse (lldc_team_member_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->membership_state = yyjson_get_int(json);

    return 0;
}
/**
 * public_flags Parser
 * the public flags on a user's account
 * type: object.int
 */
static
int lldc__user_public_flags_parse (lldc_user_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->public_flags = yyjson_get_int(json);

    return 0;
}
/**
 * premium_type Parser
 * the type of Nitro subscription on a user's account
 * type: object.int
 */
static
int lldc__user_premium_type_parse (lldc_user_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->premium_type = yyjson_get_int(json);

    return 0;
}
/**
 * flags Parser
 * the flags on a user's account
 * type: object.int
 */
static
int lldc__user_flags_parse (lldc_user_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->flags = yyjson_get_int(json);

    return 0;
}
/**
 * locale Parser
 * the user's chosen language option
 * type: object.string
 */
static
int lldc__user_locale_parse (lldc_user_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->locale = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * mfa_enabled Parser
 * whether the user has two factor enabled on their account
 * type: object.bool
 */
static
int lldc__user_mfa_enabled_parse (lldc_user_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_bool(json))
        return -1;

    obj->mfa_enabled = yyjson_get_bool(json);

    return 0;
}
/**
 * system Parser
 * whether the user is an Official Discord System user (part of the urgent message system)
 * type: object.bool
 */
static
int lldc__user_system_parse (lldc_user_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_bool(json))
        return -1;

    obj->system = yyjson_get_bool(json);

    return 0;
}
/**
 * bot Parser
 * whether the user belongs to an OAuth2 application
 * type: object.bool
 */
static
int lldc__user_bot_parse (lldc_user_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_bool(json))
        return -1;

    obj->bot = yyjson_get_bool(json);

    return 0;
}
/**
 * avatar Parser
 * OPTIONAL: the user's avatar hash
 * type: object.string
 */
static
int lldc__user_avatar_parse (lldc_user_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->avatar = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * discriminator Parser
 * the user's 4-digit discord-tag
 * type: object.string
 */
static
int lldc__user_discriminator_parse (lldc_user_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->discriminator = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * username Parser
 * the user's username, not unique across the platform
 * type: object.string
 */
static
int lldc__user_username_parse (lldc_user_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->username = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * id Parser
 * the user's id
 * type: object.snowflake
 */
static
int lldc__user_id_parse (lldc_user_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * message Parser
 * Human readable error message
 * type: object.string
 */
static
int lldc__discord_error_message_parse (lldc_discord_error_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->message = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * errors Parser
 * JSON object
 * See the Developer page for info: https://discord.com/developers/docs/reference#error-messages
 * type: object.rawobj
 */
static
int lldc__discord_error_errors_parse (lldc_discord_error_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_obj(json))
        return -1;

    obj->errors = json;

    return 0;
}
/**
 * code Parser
 * Error code
 * type: object.int
 */
static
int lldc__discord_error_code_parse (lldc_discord_error_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->code = yyjson_get_int(json);

    return 0;
}
int lldc_discord_error_parse (cwr_malloc_ctx_t *_mctx, lldc_discord_error_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_parser_def_t parser_def[3] = {
        { "code", (int (*)(void *, yyjson_val *))lldc__discord_error_code_parse },
        { "errors", (int (*)(void *, yyjson_val *))lldc__discord_error_errors_parse },
        { "message", (int (*)(void *, yyjson_val *))lldc__discord_error_message_parse }
    };

    static lldc_hashmap_entry_t parser_table[8] = { 0 };
    static lldc_hashmap_t parsers = {  
        .size = 8,
        .len = 0,
        .table = parser_table,
        .hash = lldc_hashmap_hash_str,
        .compare = (int (*)(const void *, const void *))strcmp,
        .dup_key = lldc_hashmap_dup_echo,
        .free_key = lldc_hashmap_free_noop
    };
    LLDC_PARSER_LOAD(3)

    if (!yyjson_is_obj(json))
        return -1;

    lldc_parser_malloc_ledger_t *ledger = obj->_mlog;
    
    memset(obj, 0, sizeof(lldc_discord_error_t));

    obj->_mctx = _mctx;
    if (!has_existing_ledger)
        obj->_mlog = &obj->__mlog;
    else
        obj->_mlog = ledger;

    yyjson_val *key, *val;
    yyjson_obj_iter iter;
    yyjson_obj_iter_init(json, &iter);
    while ((key = yyjson_obj_iter_next(&iter))) {
        val = yyjson_obj_iter_get_val(key);
        lldc_parser_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
int lldc_user_parse (cwr_malloc_ctx_t *_mctx, lldc_user_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_parser_def_t parser_def[11] = {
        { "id", (int (*)(void *, yyjson_val *))lldc__user_id_parse },
        { "username", (int (*)(void *, yyjson_val *))lldc__user_username_parse },
        { "discriminator", (int (*)(void *, yyjson_val *))lldc__user_discriminator_parse },
        { "avatar", (int (*)(void *, yyjson_val *))lldc__user_avatar_parse },
        { "bot", (int (*)(void *, yyjson_val *))lldc__user_bot_parse },
        { "system", (int (*)(void *, yyjson_val *))lldc__user_system_parse },
        { "mfa_enabled", (int (*)(void *, yyjson_val *))lldc__user_mfa_enabled_parse },
        { "locale", (int (*)(void *, yyjson_val *))lldc__user_locale_parse },
        { "flags", (int (*)(void *, yyjson_val *))lldc__user_flags_parse },
        { "premium_type", (int (*)(void *, yyjson_val *))lldc__user_premium_type_parse },
        { "public_flags", (int (*)(void *, yyjson_val *))lldc__user_public_flags_parse }
    };

    static lldc_hashmap_entry_t parser_table[16] = { 0 };
    static lldc_hashmap_t parsers = {  
        .size = 16,
        .len = 0,
        .table = parser_table,
        .hash = lldc_hashmap_hash_str,
        .compare = (int (*)(const void *, const void *))strcmp,
        .dup_key = lldc_hashmap_dup_echo,
        .free_key = lldc_hashmap_free_noop
    };
    LLDC_PARSER_LOAD(11)

    if (!yyjson_is_obj(json))
        return -1;

    lldc_parser_malloc_ledger_t *ledger = obj->_mlog;
    
    memset(obj, 0, sizeof(lldc_user_t));

    obj->_mctx = _mctx;
    if (!has_existing_ledger)
        obj->_mlog = &obj->__mlog;
    else
        obj->_mlog = ledger;

    yyjson_val *key, *val;
    yyjson_obj_iter iter;
    yyjson_obj_iter_init(json, &iter);
    while ((key = yyjson_obj_iter_next(&iter))) {
        val = yyjson_obj_iter_get_val(key);
        lldc_parser_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
/**
* User Parser
* User Objects
* type: object.object
*/
static
int lldc__user_item_parse (lldc_user_t *_obj, yyjson_val *json)
{
    return lldc_user_parse(_obj->_mctx, _obj, json, 1);
}
int lldc_user_arr_parse (cwr_malloc_ctx_t *_mctx, lldc_user_arr_t *obj, yyjson_val *json, int has_existing_ledger)
{

    if (!yyjson_is_arr(json))
        return -1;

    size_t arr_size = yyjson_arr_size(json);
    if (!arr_size)
    {
        obj->items = NULL;
        obj->len = 0;
        return 0;
    }

    obj->_mctx = _mctx;
    if (!has_existing_ledger)
        obj->_mlog = &obj->__mlog;

    obj->items = lldc_parser_malloc((lldc_parser_obj_t *)obj, sizeof(*obj->items) * arr_size);
    if (obj->items == NULL)
    {
        obj->len = 0;
        return -1;
    }
    obj->len = arr_size;

    size_t idx, max;
    yyjson_val *val;
    yyjson_arr_foreach(json, idx, max, val) {
        obj->items[idx]._mctx = obj->_mctx;
        obj->items[idx]._mlog = obj->_mlog;
        lldc__user_item_parse(&obj->items[idx], val);
    }

    return 0;
}
/**
* user Parser
* the avatar, discriminator, id, and username of the user
* type: object.object
*/
static
int lldc__team_member_user_parse (lldc_team_member_t *_obj, yyjson_val *json)
{
    _obj->user._mlog = _obj->_mlog;
    return lldc_user_parse(_obj->_mctx, &_obj->user, json, 1);
}
int lldc_team_member_parse (cwr_malloc_ctx_t *_mctx, lldc_team_member_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_parser_def_t parser_def[3] = {
        { "membership_state", (int (*)(void *, yyjson_val *))lldc__team_member_membership_state_parse },
        { "team_id", (int (*)(void *, yyjson_val *))lldc__team_member_team_id_parse },
        { "user", (int (*)(void *, yyjson_val *))lldc__team_member_user_parse }
    };

    static lldc_hashmap_entry_t parser_table[8] = { 0 };
    static lldc_hashmap_t parsers = {  
        .size = 8,
        .len = 0,
        .table = parser_table,
        .hash = lldc_hashmap_hash_str,
        .compare = (int (*)(const void *, const void *))strcmp,
        .dup_key = lldc_hashmap_dup_echo,
        .free_key = lldc_hashmap_free_noop
    };
    LLDC_PARSER_LOAD(3)

    if (!yyjson_is_obj(json))
        return -1;

    lldc_parser_malloc_ledger_t *ledger = obj->_mlog;
    
    memset(obj, 0, sizeof(lldc_team_member_t));

    obj->_mctx = _mctx;
    if (!has_existing_ledger)
        obj->_mlog = &obj->__mlog;
    else
        obj->_mlog = ledger;

    yyjson_val *key, *val;
    yyjson_obj_iter iter;
    yyjson_obj_iter_init(json, &iter);
    while ((key = yyjson_obj_iter_next(&iter))) {
        val = yyjson_obj_iter_get_val(key);
        lldc_parser_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
/**
* Team Member Parser
* Team Member Objects
* type: object.object
*/
static
int lldc__team_member_item_parse (lldc_team_member_t *_obj, yyjson_val *json)
{
    return lldc_team_member_parse(_obj->_mctx, _obj, json, 1);
}
int lldc_team_member_arr_parse (cwr_malloc_ctx_t *_mctx, lldc_team_member_arr_t *obj, yyjson_val *json, int has_existing_ledger)
{

    if (!yyjson_is_arr(json))
        return -1;

    size_t arr_size = yyjson_arr_size(json);
    if (!arr_size)
    {
        obj->items = NULL;
        obj->len = 0;
        return 0;
    }

    obj->_mctx = _mctx;
    if (!has_existing_ledger)
        obj->_mlog = &obj->__mlog;

    obj->items = lldc_parser_malloc((lldc_parser_obj_t *)obj, sizeof(*obj->items) * arr_size);
    if (obj->items == NULL)
    {
        obj->len = 0;
        return -1;
    }
    obj->len = arr_size;

    size_t idx, max;
    yyjson_val *val;
    yyjson_arr_foreach(json, idx, max, val) {
        obj->items[idx]._mctx = obj->_mctx;
        obj->items[idx]._mlog = obj->_mlog;
        lldc__team_member_item_parse(&obj->items[idx], val);
    }

    return 0;
}
/**
* members Parser
* the members of the team
* type: object.object
*/
static
int lldc__team_members_parse (lldc_team_t *_obj, yyjson_val *json)
{
    _obj->members._mlog = _obj->_mlog;
    return lldc_team_member_arr_parse(_obj->_mctx, &_obj->members, json, 1);
}
int lldc_team_parse (cwr_malloc_ctx_t *_mctx, lldc_team_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_parser_def_t parser_def[5] = {
        { "icon", (int (*)(void *, yyjson_val *))lldc__team_icon_parse },
        { "id", (int (*)(void *, yyjson_val *))lldc__team_id_parse },
        { "members", (int (*)(void *, yyjson_val *))lldc__team_members_parse },
        { "name", (int (*)(void *, yyjson_val *))lldc__team_name_parse },
        { "owner_user_id", (int (*)(void *, yyjson_val *))lldc__team_owner_user_id_parse }
    };

    static lldc_hashmap_entry_t parser_table[8] = { 0 };
    static lldc_hashmap_t parsers = {  
        .size = 8,
        .len = 0,
        .table = parser_table,
        .hash = lldc_hashmap_hash_str,
        .compare = (int (*)(const void *, const void *))strcmp,
        .dup_key = lldc_hashmap_dup_echo,
        .free_key = lldc_hashmap_free_noop
    };
    LLDC_PARSER_LOAD(5)

    if (!yyjson_is_obj(json))
        return -1;

    lldc_parser_malloc_ledger_t *ledger = obj->_mlog;
    
    memset(obj, 0, sizeof(lldc_team_t));

    obj->_mctx = _mctx;
    if (!has_existing_ledger)
        obj->_mlog = &obj->__mlog;
    else
        obj->_mlog = ledger;

    yyjson_val *key, *val;
    yyjson_obj_iter iter;
    yyjson_obj_iter_init(json, &iter);
    while ((key = yyjson_obj_iter_next(&iter))) {
        val = yyjson_obj_iter_get_val(key);
        lldc_parser_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
/**
* rpc_origins Parser
* OPTIONAL: an array of rpc origin urls, if rpc is enabled
* type: object.array[string]
*/
static
int lldc__application_rpc_origins_parse (lldc_application_t *_obj, yyjson_val *json)
{
    lldc_parser_string_arr_t *obj = &_obj->rpc_origins;

    obj->_mctx = _obj->_mctx;
    obj->_mlog = _obj->_mlog;
    return lldc_parser_string_arr_parse(obj, json);
}
/**
* owner Parser
* OPTIONAL: partial user object containing info on the owner of the application
* type: object.object
*/
static
int lldc__application_owner_parse (lldc_application_t *_obj, yyjson_val *json)
{
    _obj->owner._mlog = _obj->_mlog;
    return lldc_user_parse(_obj->_mctx, &_obj->owner, json, 1);
}
/**
* team Parser
* OPTIONAL: if the application belongs to a team, this will be a list of the members of that team
* type: object.object
*/
static
int lldc__application_team_parse (lldc_application_t *_obj, yyjson_val *json)
{
    _obj->team._mlog = _obj->_mlog;
    return lldc_team_parse(_obj->_mctx, &_obj->team, json, 1);
}
int lldc_application_parse (cwr_malloc_ctx_t *_mctx, lldc_application_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_parser_def_t parser_def[18] = {
        { "id", (int (*)(void *, yyjson_val *))lldc__application_id_parse },
        { "name", (int (*)(void *, yyjson_val *))lldc__application_name_parse },
        { "icon", (int (*)(void *, yyjson_val *))lldc__application_icon_parse },
        { "description", (int (*)(void *, yyjson_val *))lldc__application_description_parse },
        { "rpc_origins", (int (*)(void *, yyjson_val *))lldc__application_rpc_origins_parse },
        { "bot_public", (int (*)(void *, yyjson_val *))lldc__application_bot_public_parse },
        { "bot_require_code_grant", (int (*)(void *, yyjson_val *))lldc__application_bot_require_code_grant_parse },
        { "terms_of_service_url", (int (*)(void *, yyjson_val *))lldc__application_terms_of_service_url_parse },
        { "privacy_policy_url", (int (*)(void *, yyjson_val *))lldc__application_privacy_policy_url_parse },
        { "owner", (int (*)(void *, yyjson_val *))lldc__application_owner_parse },
        { "summary", (int (*)(void *, yyjson_val *))lldc__application_summary_parse },
        { "verify_key", (int (*)(void *, yyjson_val *))lldc__application_verify_key_parse },
        { "team", (int (*)(void *, yyjson_val *))lldc__application_team_parse },
        { "guild_id", (int (*)(void *, yyjson_val *))lldc__application_guild_id_parse },
        { "primary_sku_id", (int (*)(void *, yyjson_val *))lldc__application_primary_sku_id_parse },
        { "slug", (int (*)(void *, yyjson_val *))lldc__application_slug_parse },
        { "cover_image", (int (*)(void *, yyjson_val *))lldc__application_cover_image_parse },
        { "flags", (int (*)(void *, yyjson_val *))lldc__application_flags_parse }
    };

    static lldc_hashmap_entry_t parser_table[32] = { 0 };
    static lldc_hashmap_t parsers = {  
        .size = 32,
        .len = 0,
        .table = parser_table,
        .hash = lldc_hashmap_hash_str,
        .compare = (int (*)(const void *, const void *))strcmp,
        .dup_key = lldc_hashmap_dup_echo,
        .free_key = lldc_hashmap_free_noop
    };
    LLDC_PARSER_LOAD(18)

    if (!yyjson_is_obj(json))
        return -1;

    lldc_parser_malloc_ledger_t *ledger = obj->_mlog;
    
    memset(obj, 0, sizeof(lldc_application_t));

    obj->_mctx = _mctx;
    if (!has_existing_ledger)
        obj->_mlog = &obj->__mlog;
    else
        obj->_mlog = ledger;

    yyjson_val *key, *val;
    yyjson_obj_iter iter;
    yyjson_obj_iter_init(json, &iter);
    while ((key = yyjson_obj_iter_next(&iter))) {
        val = yyjson_obj_iter_get_val(key);
        lldc_parser_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
/**
* user Parser
* OPTIONAL: the user this webhook was created by (not returned when getting a webhook with its token)
* type: object.object
*/
static
int lldc__webhook_user_parse (lldc_webhook_t *_obj, yyjson_val *json)
{
    _obj->user._mlog = _obj->_mlog;
    return lldc_user_parse(_obj->_mctx, &_obj->user, json, 1);
}
/**
* source_guild Parser
* OPTIONAL: the partial guild of the channel that this webhook is following (returned for Channel Follower Webhooks)
* type: object.object
*/
static
int lldc__webhook_source_guild_parse (lldc_webhook_t *_obj, yyjson_val *json)
{
    lldc_webhook_source_guild_t *obj = &_obj->source_guild;

    static lldc_parser_def_t parser_def[3] = {
        { "id", (int (*)(void *, yyjson_val *))lldc__webhook_source_guild_id_parse },
        { "name", (int (*)(void *, yyjson_val *))lldc__webhook_source_guild_name_parse },
        { "icon", (int (*)(void *, yyjson_val *))lldc__webhook_source_guild_icon_parse }
    };

    static lldc_hashmap_entry_t parser_table[8] = { 0 };
    static lldc_hashmap_t parsers = {  
        .size = 8,
        .len = 0,
        .table = parser_table,
        .hash = lldc_hashmap_hash_str,
        .compare = (int (*)(const void *, const void *))strcmp,
        .dup_key = lldc_hashmap_dup_echo,
        .free_key = lldc_hashmap_free_noop
    };
    LLDC_PARSER_LOAD(3)

    if (!yyjson_is_obj(json))
        return -1;

    lldc_parser_malloc_ledger_t *ledger = obj->_mlog;
    
    memset(obj, 0, sizeof(lldc_webhook_source_guild_t));

    obj->_mctx = _obj->_mctx;
    obj->_mlog = _obj->_mlog;

    yyjson_val *key, *val;
    yyjson_obj_iter iter;
    yyjson_obj_iter_init(json, &iter);
    while ((key = yyjson_obj_iter_next(&iter))) {
        val = yyjson_obj_iter_get_val(key);
        lldc_parser_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
/**
* source_channel Parser
* OPTIONAL: the partial channel that this webhook is following (returned for Channel Follower Webhooks)
* type: object.object
*/
static
int lldc__webhook_source_channel_parse (lldc_webhook_t *_obj, yyjson_val *json)
{
    lldc_webhook_source_channel_t *obj = &_obj->source_channel;

    static lldc_parser_def_t parser_def[2] = {
        { "id", (int (*)(void *, yyjson_val *))lldc__webhook_source_channel_id_parse },
        { "name", (int (*)(void *, yyjson_val *))lldc__webhook_source_channel_name_parse }
    };

    static lldc_hashmap_entry_t parser_table[4] = { 0 };
    static lldc_hashmap_t parsers = {  
        .size = 4,
        .len = 0,
        .table = parser_table,
        .hash = lldc_hashmap_hash_str,
        .compare = (int (*)(const void *, const void *))strcmp,
        .dup_key = lldc_hashmap_dup_echo,
        .free_key = lldc_hashmap_free_noop
    };
    LLDC_PARSER_LOAD(2)

    if (!yyjson_is_obj(json))
        return -1;

    lldc_parser_malloc_ledger_t *ledger = obj->_mlog;
    
    memset(obj, 0, sizeof(lldc_webhook_source_channel_t));

    obj->_mctx = _obj->_mctx;
    obj->_mlog = _obj->_mlog;

    yyjson_val *key, *val;
    yyjson_obj_iter iter;
    yyjson_obj_iter_init(json, &iter);
    while ((key = yyjson_obj_iter_next(&iter))) {
        val = yyjson_obj_iter_get_val(key);
        lldc_parser_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
int lldc_webhook_parse (cwr_malloc_ctx_t *_mctx, lldc_webhook_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_parser_def_t parser_def[12] = {
        { "id", (int (*)(void *, yyjson_val *))lldc__webhook_id_parse },
        { "type", (int (*)(void *, yyjson_val *))lldc__webhook_type_parse },
        { "guild_id", (int (*)(void *, yyjson_val *))lldc__webhook_guild_id_parse },
        { "channel_id", (int (*)(void *, yyjson_val *))lldc__webhook_channel_id_parse },
        { "user", (int (*)(void *, yyjson_val *))lldc__webhook_user_parse },
        { "name", (int (*)(void *, yyjson_val *))lldc__webhook_name_parse },
        { "avatar", (int (*)(void *, yyjson_val *))lldc__webhook_avatar_parse },
        { "token", (int (*)(void *, yyjson_val *))lldc__webhook_token_parse },
        { "application_id", (int (*)(void *, yyjson_val *))lldc__webhook_application_id_parse },
        { "source_guild", (int (*)(void *, yyjson_val *))lldc__webhook_source_guild_parse },
        { "source_channel", (int (*)(void *, yyjson_val *))lldc__webhook_source_channel_parse },
        { "url", (int (*)(void *, yyjson_val *))lldc__webhook_url_parse }
    };

    static lldc_hashmap_entry_t parser_table[32] = { 0 };
    static lldc_hashmap_t parsers = {  
        .size = 32,
        .len = 0,
        .table = parser_table,
        .hash = lldc_hashmap_hash_str,
        .compare = (int (*)(const void *, const void *))strcmp,
        .dup_key = lldc_hashmap_dup_echo,
        .free_key = lldc_hashmap_free_noop
    };
    LLDC_PARSER_LOAD(12)

    if (!yyjson_is_obj(json))
        return -1;

    lldc_parser_malloc_ledger_t *ledger = obj->_mlog;
    
    memset(obj, 0, sizeof(lldc_webhook_t));

    obj->_mctx = _mctx;
    if (!has_existing_ledger)
        obj->_mlog = &obj->__mlog;
    else
        obj->_mlog = ledger;

    yyjson_val *key, *val;
    yyjson_obj_iter iter;
    yyjson_obj_iter_init(json, &iter);
    while ((key = yyjson_obj_iter_next(&iter))) {
        val = yyjson_obj_iter_get_val(key);
        lldc_parser_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
/**
* Webhook Parser
* Webhook Objects
* type: object.object
*/
static
int lldc__webhook_item_parse (lldc_webhook_t *_obj, yyjson_val *json)
{
    return lldc_webhook_parse(_obj->_mctx, _obj, json, 1);
}
int lldc_webhook_arr_parse (cwr_malloc_ctx_t *_mctx, lldc_webhook_arr_t *obj, yyjson_val *json, int has_existing_ledger)
{

    if (!yyjson_is_arr(json))
        return -1;

    size_t arr_size = yyjson_arr_size(json);
    if (!arr_size)
    {
        obj->items = NULL;
        obj->len = 0;
        return 0;
    }

    obj->_mctx = _mctx;
    if (!has_existing_ledger)
        obj->_mlog = &obj->__mlog;

    obj->items = lldc_parser_malloc((lldc_parser_obj_t *)obj, sizeof(*obj->items) * arr_size);
    if (obj->items == NULL)
    {
        obj->len = 0;
        return -1;
    }
    obj->len = arr_size;

    size_t idx, max;
    yyjson_val *val;
    yyjson_arr_foreach(json, idx, max, val) {
        obj->items[idx]._mctx = obj->_mctx;
        obj->items[idx]._mlog = obj->_mlog;
        lldc__webhook_item_parse(&obj->items[idx], val);
    }

    return 0;
}
int lldc_audit_log_changes_parse (cwr_malloc_ctx_t *_mctx, lldc_audit_log_changes_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_parser_def_t parser_def[3] = {
        { "new_value", (int (*)(void *, yyjson_val *))lldc__audit_log_changes_new_value_parse },
        { "old_value", (int (*)(void *, yyjson_val *))lldc__audit_log_changes_old_value_parse },
        { "key", (int (*)(void *, yyjson_val *))lldc__audit_log_changes_key_parse }
    };

    static lldc_hashmap_entry_t parser_table[8] = { 0 };
    static lldc_hashmap_t parsers = {  
        .size = 8,
        .len = 0,
        .table = parser_table,
        .hash = lldc_hashmap_hash_str,
        .compare = (int (*)(const void *, const void *))strcmp,
        .dup_key = lldc_hashmap_dup_echo,
        .free_key = lldc_hashmap_free_noop
    };
    LLDC_PARSER_LOAD(3)

    if (!yyjson_is_obj(json))
        return -1;

    lldc_parser_malloc_ledger_t *ledger = obj->_mlog;
    
    memset(obj, 0, sizeof(lldc_audit_log_changes_t));

    obj->_mctx = _mctx;
    if (!has_existing_ledger)
        obj->_mlog = &obj->__mlog;
    else
        obj->_mlog = ledger;

    yyjson_val *key, *val;
    yyjson_obj_iter iter;
    yyjson_obj_iter_init(json, &iter);
    while ((key = yyjson_obj_iter_next(&iter))) {
        val = yyjson_obj_iter_get_val(key);
        lldc_parser_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
int lldc_audit_log_options_parse (cwr_malloc_ctx_t *_mctx, lldc_audit_log_options_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_parser_def_t parser_def[8] = {
        { "delete_member_days", (int (*)(void *, yyjson_val *))lldc__audit_log_options_delete_member_days_parse },
        { "members_removed", (int (*)(void *, yyjson_val *))lldc__audit_log_options_members_removed_parse },
        { "channel_id", (int (*)(void *, yyjson_val *))lldc__audit_log_options_channel_id_parse },
        { "message_id", (int (*)(void *, yyjson_val *))lldc__audit_log_options_message_id_parse },
        { "count", (int (*)(void *, yyjson_val *))lldc__audit_log_options_count_parse },
        { "id", (int (*)(void *, yyjson_val *))lldc__audit_log_options_id_parse },
        { "type", (int (*)(void *, yyjson_val *))lldc__audit_log_options_type_parse },
        { "role_name", (int (*)(void *, yyjson_val *))lldc__audit_log_options_role_name_parse }
    };

    static lldc_hashmap_entry_t parser_table[16] = { 0 };
    static lldc_hashmap_t parsers = {  
        .size = 16,
        .len = 0,
        .table = parser_table,
        .hash = lldc_hashmap_hash_str,
        .compare = (int (*)(const void *, const void *))strcmp,
        .dup_key = lldc_hashmap_dup_echo,
        .free_key = lldc_hashmap_free_noop
    };
    LLDC_PARSER_LOAD(8)

    if (!yyjson_is_obj(json))
        return -1;

    lldc_parser_malloc_ledger_t *ledger = obj->_mlog;
    
    memset(obj, 0, sizeof(lldc_audit_log_options_t));

    obj->_mctx = _mctx;
    if (!has_existing_ledger)
        obj->_mlog = &obj->__mlog;
    else
        obj->_mlog = ledger;

    yyjson_val *key, *val;
    yyjson_obj_iter iter;
    yyjson_obj_iter_init(json, &iter);
    while ((key = yyjson_obj_iter_next(&iter))) {
        val = yyjson_obj_iter_get_val(key);
        lldc_parser_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
/**
* changes Parser
* array of audit log change objects
* type: object.object
*/
static
int lldc__audit_log_entry_changes_item_parse (lldc_audit_log_changes_t *_obj, yyjson_val *json)
{
    return lldc_audit_log_changes_parse(_obj->_mctx, _obj, json, 1);
}
/**
* changes Parser
* OPTIONAL: changes made to the target_id
* type: object.array[object]
*/
static
int lldc__audit_log_entry_changes_parse (lldc_audit_log_entry_t *_obj, yyjson_val *json)
{
    lldc_audit_log_entry_changes_arr_t *obj = &_obj->changes;

    if (!yyjson_is_arr(json))
        return -1;

    size_t arr_size = yyjson_arr_size(json);
    if (!arr_size)
    {
        obj->items = NULL;
        obj->len = 0;
        return 0;
    }

    obj->_mctx = _obj->_mctx;
    obj->_mlog = _obj->_mlog;

    obj->items = lldc_parser_malloc((lldc_parser_obj_t *)obj, sizeof(*obj->items) * arr_size);
    if (obj->items == NULL)
    {
        obj->len = 0;
        return -1;
    }
    obj->len = arr_size;

    size_t idx, max;
    yyjson_val *val;
    yyjson_arr_foreach(json, idx, max, val) {
        obj->items[idx]._mctx = obj->_mctx;
        obj->items[idx]._mlog = obj->_mlog;
        lldc__audit_log_entry_changes_item_parse(&obj->items[idx], val);
    }

    return 0;
}
/**
* options Parser
* OPTIONAL: additional info for certain action types
* type: object.object
*/
static
int lldc__audit_log_entry_options_parse (lldc_audit_log_entry_t *_obj, yyjson_val *json)
{
    _obj->options._mlog = _obj->_mlog;
    return lldc_audit_log_options_parse(_obj->_mctx, &_obj->options, json, 1);
}
int lldc_audit_log_entry_parse (cwr_malloc_ctx_t *_mctx, lldc_audit_log_entry_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_parser_def_t parser_def[7] = {
        { "target_id", (int (*)(void *, yyjson_val *))lldc__audit_log_entry_target_id_parse },
        { "changes", (int (*)(void *, yyjson_val *))lldc__audit_log_entry_changes_parse },
        { "user_id", (int (*)(void *, yyjson_val *))lldc__audit_log_entry_user_id_parse },
        { "id", (int (*)(void *, yyjson_val *))lldc__audit_log_entry_id_parse },
        { "action_type", (int (*)(void *, yyjson_val *))lldc__audit_log_entry_action_type_parse },
        { "options", (int (*)(void *, yyjson_val *))lldc__audit_log_entry_options_parse },
        { "reason", (int (*)(void *, yyjson_val *))lldc__audit_log_entry_reason_parse }
    };

    static lldc_hashmap_entry_t parser_table[16] = { 0 };
    static lldc_hashmap_t parsers = {  
        .size = 16,
        .len = 0,
        .table = parser_table,
        .hash = lldc_hashmap_hash_str,
        .compare = (int (*)(const void *, const void *))strcmp,
        .dup_key = lldc_hashmap_dup_echo,
        .free_key = lldc_hashmap_free_noop
    };
    LLDC_PARSER_LOAD(7)

    if (!yyjson_is_obj(json))
        return -1;

    lldc_parser_malloc_ledger_t *ledger = obj->_mlog;
    
    memset(obj, 0, sizeof(lldc_audit_log_entry_t));

    obj->_mctx = _mctx;
    if (!has_existing_ledger)
        obj->_mlog = &obj->__mlog;
    else
        obj->_mlog = ledger;

    yyjson_val *key, *val;
    yyjson_obj_iter iter;
    yyjson_obj_iter_init(json, &iter);
    while ((key = yyjson_obj_iter_next(&iter))) {
        val = yyjson_obj_iter_get_val(key);
        lldc_parser_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
/**
* webhooks Parser
* list of webhooks found in the audit log
* type: object.object
*/
static
int lldc__audit_log_webhooks_parse (lldc_audit_log_t *_obj, yyjson_val *json)
{
    _obj->webhooks._mlog = _obj->_mlog;
    return lldc_webhook_arr_parse(_obj->_mctx, &_obj->webhooks, json, 1);
}
/**
* users Parser
* list of users found in the audit log
* type: object.object
*/
static
int lldc__audit_log_users_parse (lldc_audit_log_t *_obj, yyjson_val *json)
{
    _obj->users._mlog = _obj->_mlog;
    return lldc_user_arr_parse(_obj->_mctx, &_obj->users, json, 1);
}
/**
* account Parser
* integration account information
* type: object.object
*/
static
int lldc__audit_log_integrations_item_account_parse (lldc_audit_log_integrations_item_t *_obj, yyjson_val *json)
{
    _obj->account._mlog = _obj->_mlog;
    return lldc_interaction_account_parse(_obj->_mctx, &_obj->account, json, 1);
}
/**
* integrations Parser
* partial integration objects
* type: array.object
*/
static
int lldc__audit_log_integrations_item_parse (lldc_audit_log_integrations_item_t *obj, yyjson_val *json)
{

    static lldc_parser_def_t parser_def[4] = {
        { "id", (int (*)(void *, yyjson_val *))lldc__audit_log_integrations_item_id_parse },
        { "name", (int (*)(void *, yyjson_val *))lldc__audit_log_integrations_item_name_parse },
        { "type", (int (*)(void *, yyjson_val *))lldc__audit_log_integrations_item_type_parse },
        { "account", (int (*)(void *, yyjson_val *))lldc__audit_log_integrations_item_account_parse }
    };

    static lldc_hashmap_entry_t parser_table[8] = { 0 };
    static lldc_hashmap_t parsers = {  
        .size = 8,
        .len = 0,
        .table = parser_table,
        .hash = lldc_hashmap_hash_str,
        .compare = (int (*)(const void *, const void *))strcmp,
        .dup_key = lldc_hashmap_dup_echo,
        .free_key = lldc_hashmap_free_noop
    };
    LLDC_PARSER_LOAD(4)

    if (!yyjson_is_obj(json))
        return -1;

    lldc_parser_malloc_ledger_t *ledger = obj->_mlog;
    cwr_malloc_ctx_t *mctx = obj->_mctx;
    memset(obj, 0, sizeof(lldc_audit_log_integrations_item_t));

    obj->_mlog = ledger;
    obj->_mctx = mctx;
    yyjson_val *key, *val;
    yyjson_obj_iter iter;
    yyjson_obj_iter_init(json, &iter);
    while ((key = yyjson_obj_iter_next(&iter))) {
        val = yyjson_obj_iter_get_val(key);
        lldc_parser_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
/**
* integrations Parser
* list of partial integration objects
* type: object.array[object]
*/
static
int lldc__audit_log_integrations_parse (lldc_audit_log_t *_obj, yyjson_val *json)
{
    lldc_audit_log_integrations_arr_t *obj = &_obj->integrations;

    if (!yyjson_is_arr(json))
        return -1;

    size_t arr_size = yyjson_arr_size(json);
    if (!arr_size)
    {
        obj->items = NULL;
        obj->len = 0;
        return 0;
    }

    obj->_mctx = _obj->_mctx;
    obj->_mlog = _obj->_mlog;

    obj->items = lldc_parser_malloc((lldc_parser_obj_t *)obj, sizeof(*obj->items) * arr_size);
    if (obj->items == NULL)
    {
        obj->len = 0;
        return -1;
    }
    obj->len = arr_size;

    size_t idx, max;
    yyjson_val *val;
    yyjson_arr_foreach(json, idx, max, val) {
        obj->items[idx]._mctx = obj->_mctx;
        obj->items[idx]._mlog = obj->_mlog;
        lldc__audit_log_integrations_item_parse(&obj->items[idx], val);
    }

    return 0;
}
/**
* audit_log_entries Parser
* array of audit log entry objects
* type: object.object
*/
static
int lldc__audit_log_audit_log_entries_item_parse (lldc_audit_log_entry_t *_obj, yyjson_val *json)
{
    return lldc_audit_log_entry_parse(_obj->_mctx, _obj, json, 1);
}
/**
* audit_log_entries Parser
* list of audit log entries
* type: object.array[object]
*/
static
int lldc__audit_log_audit_log_entries_parse (lldc_audit_log_t *_obj, yyjson_val *json)
{
    lldc_audit_log_audit_log_entries_arr_t *obj = &_obj->audit_log_entries;

    if (!yyjson_is_arr(json))
        return -1;

    size_t arr_size = yyjson_arr_size(json);
    if (!arr_size)
    {
        obj->items = NULL;
        obj->len = 0;
        return 0;
    }

    obj->_mctx = _obj->_mctx;
    obj->_mlog = _obj->_mlog;

    obj->items = lldc_parser_malloc((lldc_parser_obj_t *)obj, sizeof(*obj->items) * arr_size);
    if (obj->items == NULL)
    {
        obj->len = 0;
        return -1;
    }
    obj->len = arr_size;

    size_t idx, max;
    yyjson_val *val;
    yyjson_arr_foreach(json, idx, max, val) {
        obj->items[idx]._mctx = obj->_mctx;
        obj->items[idx]._mlog = obj->_mlog;
        lldc__audit_log_audit_log_entries_item_parse(&obj->items[idx], val);
    }

    return 0;
}
int lldc_audit_log_parse (cwr_malloc_ctx_t *_mctx, lldc_audit_log_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_parser_def_t parser_def[4] = {
        { "webhooks", (int (*)(void *, yyjson_val *))lldc__audit_log_webhooks_parse },
        { "users", (int (*)(void *, yyjson_val *))lldc__audit_log_users_parse },
        { "integrations", (int (*)(void *, yyjson_val *))lldc__audit_log_integrations_parse },
        { "audit_log_entries", (int (*)(void *, yyjson_val *))lldc__audit_log_audit_log_entries_parse }
    };

    static lldc_hashmap_entry_t parser_table[8] = { 0 };
    static lldc_hashmap_t parsers = {  
        .size = 8,
        .len = 0,
        .table = parser_table,
        .hash = lldc_hashmap_hash_str,
        .compare = (int (*)(const void *, const void *))strcmp,
        .dup_key = lldc_hashmap_dup_echo,
        .free_key = lldc_hashmap_free_noop
    };
    LLDC_PARSER_LOAD(4)

    if (!yyjson_is_obj(json))
        return -1;

    lldc_parser_malloc_ledger_t *ledger = obj->_mlog;
    
    memset(obj, 0, sizeof(lldc_audit_log_t));

    obj->_mctx = _mctx;
    if (!has_existing_ledger)
        obj->_mlog = &obj->__mlog;
    else
        obj->_mlog = ledger;

    yyjson_val *key, *val;
    yyjson_obj_iter iter;
    yyjson_obj_iter_init(json, &iter);
    while ((key = yyjson_obj_iter_next(&iter))) {
        val = yyjson_obj_iter_get_val(key);
        lldc_parser_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
/**
* user Parser
* OPTIONAL: the user this guild member represents
* type: object.object
*/
static
int lldc__guild_member_user_parse (lldc_guild_member_t *_obj, yyjson_val *json)
{
    _obj->user._mlog = _obj->_mlog;
    return lldc_user_parse(_obj->_mctx, &_obj->user, json, 1);
}
/**
* roles Parser
* array of role object ids
* type: object.array[snowflake]
*/
static
int lldc__guild_member_roles_parse (lldc_guild_member_t *_obj, yyjson_val *json)
{
    lldc_parser_snowflake_arr_t *obj = &_obj->roles;

    obj->_mctx = _obj->_mctx;
    obj->_mlog = _obj->_mlog;
    return lldc_parser_snowflake_arr_parse(obj, json);
}
int lldc_guild_member_parse (cwr_malloc_ctx_t *_mctx, lldc_guild_member_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_parser_def_t parser_def[9] = {
        { "user", (int (*)(void *, yyjson_val *))lldc__guild_member_user_parse },
        { "nick", (int (*)(void *, yyjson_val *))lldc__guild_member_nick_parse },
        { "roles", (int (*)(void *, yyjson_val *))lldc__guild_member_roles_parse },
        { "joined_at", (int (*)(void *, yyjson_val *))lldc__guild_member_joined_at_parse },
        { "premium_since", (int (*)(void *, yyjson_val *))lldc__guild_member_premium_since_parse },
        { "deaf", (int (*)(void *, yyjson_val *))lldc__guild_member_deaf_parse },
        { "mute", (int (*)(void *, yyjson_val *))lldc__guild_member_mute_parse },
        { "pending", (int (*)(void *, yyjson_val *))lldc__guild_member_pending_parse },
        { "permissions", (int (*)(void *, yyjson_val *))lldc__guild_member_permissions_parse }
    };

    static lldc_hashmap_entry_t parser_table[16] = { 0 };
    static lldc_hashmap_t parsers = {  
        .size = 16,
        .len = 0,
        .table = parser_table,
        .hash = lldc_hashmap_hash_str,
        .compare = (int (*)(const void *, const void *))strcmp,
        .dup_key = lldc_hashmap_dup_echo,
        .free_key = lldc_hashmap_free_noop
    };
    LLDC_PARSER_LOAD(9)

    if (!yyjson_is_obj(json))
        return -1;

    lldc_parser_malloc_ledger_t *ledger = obj->_mlog;
    
    memset(obj, 0, sizeof(lldc_guild_member_t));

    obj->_mctx = _mctx;
    if (!has_existing_ledger)
        obj->_mlog = &obj->__mlog;
    else
        obj->_mlog = ledger;

    yyjson_val *key, *val;
    yyjson_obj_iter iter;
    yyjson_obj_iter_init(json, &iter);
    while ((key = yyjson_obj_iter_next(&iter))) {
        val = yyjson_obj_iter_get_val(key);
        lldc_parser_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
/**
* roles Parser
* array of role object ids
* type: object.array[snowflake]
*/
static
int lldc__partial_guild_member_roles_parse (lldc_partial_guild_member_t *_obj, yyjson_val *json)
{
    lldc_parser_snowflake_arr_t *obj = &_obj->roles;

    obj->_mctx = _obj->_mctx;
    obj->_mlog = _obj->_mlog;
    return lldc_parser_snowflake_arr_parse(obj, json);
}
int lldc_partial_guild_member_parse (cwr_malloc_ctx_t *_mctx, lldc_partial_guild_member_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_parser_def_t parser_def[8] = {
        { "nick", (int (*)(void *, yyjson_val *))lldc__partial_guild_member_nick_parse },
        { "roles", (int (*)(void *, yyjson_val *))lldc__partial_guild_member_roles_parse },
        { "joined_at", (int (*)(void *, yyjson_val *))lldc__partial_guild_member_joined_at_parse },
        { "premium_since", (int (*)(void *, yyjson_val *))lldc__partial_guild_member_premium_since_parse },
        { "deaf", (int (*)(void *, yyjson_val *))lldc__partial_guild_member_deaf_parse },
        { "mute", (int (*)(void *, yyjson_val *))lldc__partial_guild_member_mute_parse },
        { "pending", (int (*)(void *, yyjson_val *))lldc__partial_guild_member_pending_parse },
        { "permissions", (int (*)(void *, yyjson_val *))lldc__partial_guild_member_permissions_parse }
    };

    static lldc_hashmap_entry_t parser_table[16] = { 0 };
    static lldc_hashmap_t parsers = {  
        .size = 16,
        .len = 0,
        .table = parser_table,
        .hash = lldc_hashmap_hash_str,
        .compare = (int (*)(const void *, const void *))strcmp,
        .dup_key = lldc_hashmap_dup_echo,
        .free_key = lldc_hashmap_free_noop
    };
    LLDC_PARSER_LOAD(8)

    if (!yyjson_is_obj(json))
        return -1;

    lldc_parser_malloc_ledger_t *ledger = obj->_mlog;
    
    memset(obj, 0, sizeof(lldc_partial_guild_member_t));

    obj->_mctx = _mctx;
    if (!has_existing_ledger)
        obj->_mlog = &obj->__mlog;
    else
        obj->_mlog = ledger;

    yyjson_val *key, *val;
    yyjson_obj_iter iter;
    yyjson_obj_iter_init(json, &iter);
    while ((key = yyjson_obj_iter_next(&iter))) {
        val = yyjson_obj_iter_get_val(key);
        lldc_parser_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
int lldc_channel_overwrite_parse (cwr_malloc_ctx_t *_mctx, lldc_channel_overwrite_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_parser_def_t parser_def[4] = {
        { "id", (int (*)(void *, yyjson_val *))lldc__channel_overwrite_id_parse },
        { "type", (int (*)(void *, yyjson_val *))lldc__channel_overwrite_type_parse },
        { "allow", (int (*)(void *, yyjson_val *))lldc__channel_overwrite_allow_parse },
        { "deny", (int (*)(void *, yyjson_val *))lldc__channel_overwrite_deny_parse }
    };

    static lldc_hashmap_entry_t parser_table[8] = { 0 };
    static lldc_hashmap_t parsers = {  
        .size = 8,
        .len = 0,
        .table = parser_table,
        .hash = lldc_hashmap_hash_str,
        .compare = (int (*)(const void *, const void *))strcmp,
        .dup_key = lldc_hashmap_dup_echo,
        .free_key = lldc_hashmap_free_noop
    };
    LLDC_PARSER_LOAD(4)

    if (!yyjson_is_obj(json))
        return -1;

    lldc_parser_malloc_ledger_t *ledger = obj->_mlog;
    
    memset(obj, 0, sizeof(lldc_channel_overwrite_t));

    obj->_mctx = _mctx;
    if (!has_existing_ledger)
        obj->_mlog = &obj->__mlog;
    else
        obj->_mlog = ledger;

    yyjson_val *key, *val;
    yyjson_obj_iter iter;
    yyjson_obj_iter_init(json, &iter);
    while ((key = yyjson_obj_iter_next(&iter))) {
        val = yyjson_obj_iter_get_val(key);
        lldc_parser_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
/**
* Channel Overwrite Parser
* Channel Overwrite Objects
* type: object.object
*/
static
int lldc__channel_overwrite_item_parse (lldc_channel_overwrite_t *_obj, yyjson_val *json)
{
    return lldc_channel_overwrite_parse(_obj->_mctx, _obj, json, 1);
}
int lldc_channel_overwrite_arr_parse (cwr_malloc_ctx_t *_mctx, lldc_channel_overwrite_arr_t *obj, yyjson_val *json, int has_existing_ledger)
{

    if (!yyjson_is_arr(json))
        return -1;

    size_t arr_size = yyjson_arr_size(json);
    if (!arr_size)
    {
        obj->items = NULL;
        obj->len = 0;
        return 0;
    }

    obj->_mctx = _mctx;
    if (!has_existing_ledger)
        obj->_mlog = &obj->__mlog;

    obj->items = lldc_parser_malloc((lldc_parser_obj_t *)obj, sizeof(*obj->items) * arr_size);
    if (obj->items == NULL)
    {
        obj->len = 0;
        return -1;
    }
    obj->len = arr_size;

    size_t idx, max;
    yyjson_val *val;
    yyjson_arr_foreach(json, idx, max, val) {
        obj->items[idx]._mctx = obj->_mctx;
        obj->items[idx]._mlog = obj->_mlog;
        lldc__channel_overwrite_item_parse(&obj->items[idx], val);
    }

    return 0;
}
int lldc_thread_metadata_parse (cwr_malloc_ctx_t *_mctx, lldc_thread_metadata_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_parser_def_t parser_def[4] = {
        { "archived", (int (*)(void *, yyjson_val *))lldc__thread_metadata_archived_parse },
        { "auto_archive_duration", (int (*)(void *, yyjson_val *))lldc__thread_metadata_auto_archive_duration_parse },
        { "archive_timestamp", (int (*)(void *, yyjson_val *))lldc__thread_metadata_archive_timestamp_parse },
        { "locked", (int (*)(void *, yyjson_val *))lldc__thread_metadata_locked_parse }
    };

    static lldc_hashmap_entry_t parser_table[8] = { 0 };
    static lldc_hashmap_t parsers = {  
        .size = 8,
        .len = 0,
        .table = parser_table,
        .hash = lldc_hashmap_hash_str,
        .compare = (int (*)(const void *, const void *))strcmp,
        .dup_key = lldc_hashmap_dup_echo,
        .free_key = lldc_hashmap_free_noop
    };
    LLDC_PARSER_LOAD(4)

    if (!yyjson_is_obj(json))
        return -1;

    lldc_parser_malloc_ledger_t *ledger = obj->_mlog;
    
    memset(obj, 0, sizeof(lldc_thread_metadata_t));

    obj->_mctx = _mctx;
    if (!has_existing_ledger)
        obj->_mlog = &obj->__mlog;
    else
        obj->_mlog = ledger;

    yyjson_val *key, *val;
    yyjson_obj_iter iter;
    yyjson_obj_iter_init(json, &iter);
    while ((key = yyjson_obj_iter_next(&iter))) {
        val = yyjson_obj_iter_get_val(key);
        lldc_parser_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
int lldc_thread_member_parse (cwr_malloc_ctx_t *_mctx, lldc_thread_member_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_parser_def_t parser_def[4] = {
        { "id", (int (*)(void *, yyjson_val *))lldc__thread_member_id_parse },
        { "user_id", (int (*)(void *, yyjson_val *))lldc__thread_member_user_id_parse },
        { "join_timestamp", (int (*)(void *, yyjson_val *))lldc__thread_member_join_timestamp_parse },
        { "flags", (int (*)(void *, yyjson_val *))lldc__thread_member_flags_parse }
    };

    static lldc_hashmap_entry_t parser_table[8] = { 0 };
    static lldc_hashmap_t parsers = {  
        .size = 8,
        .len = 0,
        .table = parser_table,
        .hash = lldc_hashmap_hash_str,
        .compare = (int (*)(const void *, const void *))strcmp,
        .dup_key = lldc_hashmap_dup_echo,
        .free_key = lldc_hashmap_free_noop
    };
    LLDC_PARSER_LOAD(4)

    if (!yyjson_is_obj(json))
        return -1;

    lldc_parser_malloc_ledger_t *ledger = obj->_mlog;
    
    memset(obj, 0, sizeof(lldc_thread_member_t));

    obj->_mctx = _mctx;
    if (!has_existing_ledger)
        obj->_mlog = &obj->__mlog;
    else
        obj->_mlog = ledger;

    yyjson_val *key, *val;
    yyjson_obj_iter iter;
    yyjson_obj_iter_init(json, &iter);
    while ((key = yyjson_obj_iter_next(&iter))) {
        val = yyjson_obj_iter_get_val(key);
        lldc_parser_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
int lldc_attachment_parse (cwr_malloc_ctx_t *_mctx, lldc_attachment_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_parser_def_t parser_def[8] = {
        { "id", (int (*)(void *, yyjson_val *))lldc__attachment_id_parse },
        { "filename", (int (*)(void *, yyjson_val *))lldc__attachment_filename_parse },
        { "content_type", (int (*)(void *, yyjson_val *))lldc__attachment_content_type_parse },
        { "size", (int (*)(void *, yyjson_val *))lldc__attachment_size_parse },
        { "url", (int (*)(void *, yyjson_val *))lldc__attachment_url_parse },
        { "proxy_url", (int (*)(void *, yyjson_val *))lldc__attachment_proxy_url_parse },
        { "height", (int (*)(void *, yyjson_val *))lldc__attachment_height_parse },
        { "width", (int (*)(void *, yyjson_val *))lldc__attachment_width_parse }
    };

    static lldc_hashmap_entry_t parser_table[16] = { 0 };
    static lldc_hashmap_t parsers = {  
        .size = 16,
        .len = 0,
        .table = parser_table,
        .hash = lldc_hashmap_hash_str,
        .compare = (int (*)(const void *, const void *))strcmp,
        .dup_key = lldc_hashmap_dup_echo,
        .free_key = lldc_hashmap_free_noop
    };
    LLDC_PARSER_LOAD(8)

    if (!yyjson_is_obj(json))
        return -1;

    lldc_parser_malloc_ledger_t *ledger = obj->_mlog;
    
    memset(obj, 0, sizeof(lldc_attachment_t));

    obj->_mctx = _mctx;
    if (!has_existing_ledger)
        obj->_mlog = &obj->__mlog;
    else
        obj->_mlog = ledger;

    yyjson_val *key, *val;
    yyjson_obj_iter iter;
    yyjson_obj_iter_init(json, &iter);
    while ((key = yyjson_obj_iter_next(&iter))) {
        val = yyjson_obj_iter_get_val(key);
        lldc_parser_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
/**
* Attachment Parser
* Attachment Objects
* type: object.object
*/
static
int lldc__attachment_item_parse (lldc_attachment_t *_obj, yyjson_val *json)
{
    return lldc_attachment_parse(_obj->_mctx, _obj, json, 1);
}
int lldc_attachment_arr_parse (cwr_malloc_ctx_t *_mctx, lldc_attachment_arr_t *obj, yyjson_val *json, int has_existing_ledger)
{

    if (!yyjson_is_arr(json))
        return -1;

    size_t arr_size = yyjson_arr_size(json);
    if (!arr_size)
    {
        obj->items = NULL;
        obj->len = 0;
        return 0;
    }

    obj->_mctx = _mctx;
    if (!has_existing_ledger)
        obj->_mlog = &obj->__mlog;

    obj->items = lldc_parser_malloc((lldc_parser_obj_t *)obj, sizeof(*obj->items) * arr_size);
    if (obj->items == NULL)
    {
        obj->len = 0;
        return -1;
    }
    obj->len = arr_size;

    size_t idx, max;
    yyjson_val *val;
    yyjson_arr_foreach(json, idx, max, val) {
        obj->items[idx]._mctx = obj->_mctx;
        obj->items[idx]._mlog = obj->_mlog;
        lldc__attachment_item_parse(&obj->items[idx], val);
    }

    return 0;
}
int lldc_channel_mention_parse (cwr_malloc_ctx_t *_mctx, lldc_channel_mention_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_parser_def_t parser_def[4] = {
        { "id", (int (*)(void *, yyjson_val *))lldc__channel_mention_id_parse },
        { "guild_id", (int (*)(void *, yyjson_val *))lldc__channel_mention_guild_id_parse },
        { "type", (int (*)(void *, yyjson_val *))lldc__channel_mention_type_parse },
        { "name", (int (*)(void *, yyjson_val *))lldc__channel_mention_name_parse }
    };

    static lldc_hashmap_entry_t parser_table[8] = { 0 };
    static lldc_hashmap_t parsers = {  
        .size = 8,
        .len = 0,
        .table = parser_table,
        .hash = lldc_hashmap_hash_str,
        .compare = (int (*)(const void *, const void *))strcmp,
        .dup_key = lldc_hashmap_dup_echo,
        .free_key = lldc_hashmap_free_noop
    };
    LLDC_PARSER_LOAD(4)

    if (!yyjson_is_obj(json))
        return -1;

    lldc_parser_malloc_ledger_t *ledger = obj->_mlog;
    
    memset(obj, 0, sizeof(lldc_channel_mention_t));

    obj->_mctx = _mctx;
    if (!has_existing_ledger)
        obj->_mlog = &obj->__mlog;
    else
        obj->_mlog = ledger;

    yyjson_val *key, *val;
    yyjson_obj_iter iter;
    yyjson_obj_iter_init(json, &iter);
    while ((key = yyjson_obj_iter_next(&iter))) {
        val = yyjson_obj_iter_get_val(key);
        lldc_parser_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
/**
* Channel Mention Parser
* Channel Mention Objects
* type: object.object
*/
static
int lldc__channel_mention_item_parse (lldc_channel_mention_t *_obj, yyjson_val *json)
{
    return lldc_channel_mention_parse(_obj->_mctx, _obj, json, 1);
}
int lldc_channel_mention_arr_parse (cwr_malloc_ctx_t *_mctx, lldc_channel_mention_arr_t *obj, yyjson_val *json, int has_existing_ledger)
{

    if (!yyjson_is_arr(json))
        return -1;

    size_t arr_size = yyjson_arr_size(json);
    if (!arr_size)
    {
        obj->items = NULL;
        obj->len = 0;
        return 0;
    }

    obj->_mctx = _mctx;
    if (!has_existing_ledger)
        obj->_mlog = &obj->__mlog;

    obj->items = lldc_parser_malloc((lldc_parser_obj_t *)obj, sizeof(*obj->items) * arr_size);
    if (obj->items == NULL)
    {
        obj->len = 0;
        return -1;
    }
    obj->len = arr_size;

    size_t idx, max;
    yyjson_val *val;
    yyjson_arr_foreach(json, idx, max, val) {
        obj->items[idx]._mctx = obj->_mctx;
        obj->items[idx]._mlog = obj->_mlog;
        lldc__channel_mention_item_parse(&obj->items[idx], val);
    }

    return 0;
}
int lldc_embed_author_parse (cwr_malloc_ctx_t *_mctx, lldc_embed_author_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_parser_def_t parser_def[4] = {
        { "name", (int (*)(void *, yyjson_val *))lldc__embed_author_name_parse },
        { "url", (int (*)(void *, yyjson_val *))lldc__embed_author_url_parse },
        { "icon_url", (int (*)(void *, yyjson_val *))lldc__embed_author_icon_url_parse },
        { "proxy_icon_url", (int (*)(void *, yyjson_val *))lldc__embed_author_proxy_icon_url_parse }
    };

    static lldc_hashmap_entry_t parser_table[8] = { 0 };
    static lldc_hashmap_t parsers = {  
        .size = 8,
        .len = 0,
        .table = parser_table,
        .hash = lldc_hashmap_hash_str,
        .compare = (int (*)(const void *, const void *))strcmp,
        .dup_key = lldc_hashmap_dup_echo,
        .free_key = lldc_hashmap_free_noop
    };
    LLDC_PARSER_LOAD(4)

    if (!yyjson_is_obj(json))
        return -1;

    lldc_parser_malloc_ledger_t *ledger = obj->_mlog;
    
    memset(obj, 0, sizeof(lldc_embed_author_t));

    obj->_mctx = _mctx;
    if (!has_existing_ledger)
        obj->_mlog = &obj->__mlog;
    else
        obj->_mlog = ledger;

    yyjson_val *key, *val;
    yyjson_obj_iter iter;
    yyjson_obj_iter_init(json, &iter);
    while ((key = yyjson_obj_iter_next(&iter))) {
        val = yyjson_obj_iter_get_val(key);
        lldc_parser_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
int lldc_embed_footer_parse (cwr_malloc_ctx_t *_mctx, lldc_embed_footer_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_parser_def_t parser_def[3] = {
        { "text", (int (*)(void *, yyjson_val *))lldc__embed_footer_text_parse },
        { "icon_url", (int (*)(void *, yyjson_val *))lldc__embed_footer_icon_url_parse },
        { "proxy_icon_url", (int (*)(void *, yyjson_val *))lldc__embed_footer_proxy_icon_url_parse }
    };

    static lldc_hashmap_entry_t parser_table[8] = { 0 };
    static lldc_hashmap_t parsers = {  
        .size = 8,
        .len = 0,
        .table = parser_table,
        .hash = lldc_hashmap_hash_str,
        .compare = (int (*)(const void *, const void *))strcmp,
        .dup_key = lldc_hashmap_dup_echo,
        .free_key = lldc_hashmap_free_noop
    };
    LLDC_PARSER_LOAD(3)

    if (!yyjson_is_obj(json))
        return -1;

    lldc_parser_malloc_ledger_t *ledger = obj->_mlog;
    
    memset(obj, 0, sizeof(lldc_embed_footer_t));

    obj->_mctx = _mctx;
    if (!has_existing_ledger)
        obj->_mlog = &obj->__mlog;
    else
        obj->_mlog = ledger;

    yyjson_val *key, *val;
    yyjson_obj_iter iter;
    yyjson_obj_iter_init(json, &iter);
    while ((key = yyjson_obj_iter_next(&iter))) {
        val = yyjson_obj_iter_get_val(key);
        lldc_parser_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
int lldc_embed_image_parse (cwr_malloc_ctx_t *_mctx, lldc_embed_image_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_parser_def_t parser_def[4] = {
        { "url", (int (*)(void *, yyjson_val *))lldc__embed_image_url_parse },
        { "proxy_url", (int (*)(void *, yyjson_val *))lldc__embed_image_proxy_url_parse },
        { "height", (int (*)(void *, yyjson_val *))lldc__embed_image_height_parse },
        { "width", (int (*)(void *, yyjson_val *))lldc__embed_image_width_parse }
    };

    static lldc_hashmap_entry_t parser_table[8] = { 0 };
    static lldc_hashmap_t parsers = {  
        .size = 8,
        .len = 0,
        .table = parser_table,
        .hash = lldc_hashmap_hash_str,
        .compare = (int (*)(const void *, const void *))strcmp,
        .dup_key = lldc_hashmap_dup_echo,
        .free_key = lldc_hashmap_free_noop
    };
    LLDC_PARSER_LOAD(4)

    if (!yyjson_is_obj(json))
        return -1;

    lldc_parser_malloc_ledger_t *ledger = obj->_mlog;
    
    memset(obj, 0, sizeof(lldc_embed_image_t));

    obj->_mctx = _mctx;
    if (!has_existing_ledger)
        obj->_mlog = &obj->__mlog;
    else
        obj->_mlog = ledger;

    yyjson_val *key, *val;
    yyjson_obj_iter iter;
    yyjson_obj_iter_init(json, &iter);
    while ((key = yyjson_obj_iter_next(&iter))) {
        val = yyjson_obj_iter_get_val(key);
        lldc_parser_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
int lldc_embed_provider_parse (cwr_malloc_ctx_t *_mctx, lldc_embed_provider_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_parser_def_t parser_def[2] = {
        { "name", (int (*)(void *, yyjson_val *))lldc__embed_provider_name_parse },
        { "url", (int (*)(void *, yyjson_val *))lldc__embed_provider_url_parse }
    };

    static lldc_hashmap_entry_t parser_table[4] = { 0 };
    static lldc_hashmap_t parsers = {  
        .size = 4,
        .len = 0,
        .table = parser_table,
        .hash = lldc_hashmap_hash_str,
        .compare = (int (*)(const void *, const void *))strcmp,
        .dup_key = lldc_hashmap_dup_echo,
        .free_key = lldc_hashmap_free_noop
    };
    LLDC_PARSER_LOAD(2)

    if (!yyjson_is_obj(json))
        return -1;

    lldc_parser_malloc_ledger_t *ledger = obj->_mlog;
    
    memset(obj, 0, sizeof(lldc_embed_provider_t));

    obj->_mctx = _mctx;
    if (!has_existing_ledger)
        obj->_mlog = &obj->__mlog;
    else
        obj->_mlog = ledger;

    yyjson_val *key, *val;
    yyjson_obj_iter iter;
    yyjson_obj_iter_init(json, &iter);
    while ((key = yyjson_obj_iter_next(&iter))) {
        val = yyjson_obj_iter_get_val(key);
        lldc_parser_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
int lldc_embed_thumbnail_parse (cwr_malloc_ctx_t *_mctx, lldc_embed_thumbnail_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_parser_def_t parser_def[4] = {
        { "url", (int (*)(void *, yyjson_val *))lldc__embed_thumbnail_url_parse },
        { "proxy_url", (int (*)(void *, yyjson_val *))lldc__embed_thumbnail_proxy_url_parse },
        { "height", (int (*)(void *, yyjson_val *))lldc__embed_thumbnail_height_parse },
        { "width", (int (*)(void *, yyjson_val *))lldc__embed_thumbnail_width_parse }
    };

    static lldc_hashmap_entry_t parser_table[8] = { 0 };
    static lldc_hashmap_t parsers = {  
        .size = 8,
        .len = 0,
        .table = parser_table,
        .hash = lldc_hashmap_hash_str,
        .compare = (int (*)(const void *, const void *))strcmp,
        .dup_key = lldc_hashmap_dup_echo,
        .free_key = lldc_hashmap_free_noop
    };
    LLDC_PARSER_LOAD(4)

    if (!yyjson_is_obj(json))
        return -1;

    lldc_parser_malloc_ledger_t *ledger = obj->_mlog;
    
    memset(obj, 0, sizeof(lldc_embed_thumbnail_t));

    obj->_mctx = _mctx;
    if (!has_existing_ledger)
        obj->_mlog = &obj->__mlog;
    else
        obj->_mlog = ledger;

    yyjson_val *key, *val;
    yyjson_obj_iter iter;
    yyjson_obj_iter_init(json, &iter);
    while ((key = yyjson_obj_iter_next(&iter))) {
        val = yyjson_obj_iter_get_val(key);
        lldc_parser_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
int lldc_embed_video_parse (cwr_malloc_ctx_t *_mctx, lldc_embed_video_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_parser_def_t parser_def[4] = {
        { "url", (int (*)(void *, yyjson_val *))lldc__embed_video_url_parse },
        { "proxy_url", (int (*)(void *, yyjson_val *))lldc__embed_video_proxy_url_parse },
        { "height", (int (*)(void *, yyjson_val *))lldc__embed_video_height_parse },
        { "width", (int (*)(void *, yyjson_val *))lldc__embed_video_width_parse }
    };

    static lldc_hashmap_entry_t parser_table[8] = { 0 };
    static lldc_hashmap_t parsers = {  
        .size = 8,
        .len = 0,
        .table = parser_table,
        .hash = lldc_hashmap_hash_str,
        .compare = (int (*)(const void *, const void *))strcmp,
        .dup_key = lldc_hashmap_dup_echo,
        .free_key = lldc_hashmap_free_noop
    };
    LLDC_PARSER_LOAD(4)

    if (!yyjson_is_obj(json))
        return -1;

    lldc_parser_malloc_ledger_t *ledger = obj->_mlog;
    
    memset(obj, 0, sizeof(lldc_embed_video_t));

    obj->_mctx = _mctx;
    if (!has_existing_ledger)
        obj->_mlog = &obj->__mlog;
    else
        obj->_mlog = ledger;

    yyjson_val *key, *val;
    yyjson_obj_iter iter;
    yyjson_obj_iter_init(json, &iter);
    while ((key = yyjson_obj_iter_next(&iter))) {
        val = yyjson_obj_iter_get_val(key);
        lldc_parser_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
int lldc_embed_field_parse (cwr_malloc_ctx_t *_mctx, lldc_embed_field_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_parser_def_t parser_def[3] = {
        { "name", (int (*)(void *, yyjson_val *))lldc__embed_field_name_parse },
        { "value", (int (*)(void *, yyjson_val *))lldc__embed_field_value_parse },
        { "inline", (int (*)(void *, yyjson_val *))lldc__embed_field_is_inline_parse }
    };

    static lldc_hashmap_entry_t parser_table[8] = { 0 };
    static lldc_hashmap_t parsers = {  
        .size = 8,
        .len = 0,
        .table = parser_table,
        .hash = lldc_hashmap_hash_str,
        .compare = (int (*)(const void *, const void *))strcmp,
        .dup_key = lldc_hashmap_dup_echo,
        .free_key = lldc_hashmap_free_noop
    };
    LLDC_PARSER_LOAD(3)

    if (!yyjson_is_obj(json))
        return -1;

    lldc_parser_malloc_ledger_t *ledger = obj->_mlog;
    
    memset(obj, 0, sizeof(lldc_embed_field_t));

    obj->_mctx = _mctx;
    if (!has_existing_ledger)
        obj->_mlog = &obj->__mlog;
    else
        obj->_mlog = ledger;

    yyjson_val *key, *val;
    yyjson_obj_iter iter;
    yyjson_obj_iter_init(json, &iter);
    while ((key = yyjson_obj_iter_next(&iter))) {
        val = yyjson_obj_iter_get_val(key);
        lldc_parser_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
/**
* Embed Field Parser
* Embed Field Objects
* type: object.object
*/
static
int lldc__embed_field_item_parse (lldc_embed_field_t *_obj, yyjson_val *json)
{
    return lldc_embed_field_parse(_obj->_mctx, _obj, json, 1);
}
int lldc_embed_field_arr_parse (cwr_malloc_ctx_t *_mctx, lldc_embed_field_arr_t *obj, yyjson_val *json, int has_existing_ledger)
{

    if (!yyjson_is_arr(json))
        return -1;

    size_t arr_size = yyjson_arr_size(json);
    if (!arr_size)
    {
        obj->items = NULL;
        obj->len = 0;
        return 0;
    }

    obj->_mctx = _mctx;
    if (!has_existing_ledger)
        obj->_mlog = &obj->__mlog;

    obj->items = lldc_parser_malloc((lldc_parser_obj_t *)obj, sizeof(*obj->items) * arr_size);
    if (obj->items == NULL)
    {
        obj->len = 0;
        return -1;
    }
    obj->len = arr_size;

    size_t idx, max;
    yyjson_val *val;
    yyjson_arr_foreach(json, idx, max, val) {
        obj->items[idx]._mctx = obj->_mctx;
        obj->items[idx]._mlog = obj->_mlog;
        lldc__embed_field_item_parse(&obj->items[idx], val);
    }

    return 0;
}
/**
* footer Parser
* OPTIONAL: footer information
* type: object.object
*/
static
int lldc__embed_footer_parse (lldc_embed_t *_obj, yyjson_val *json)
{
    _obj->footer._mlog = _obj->_mlog;
    return lldc_embed_footer_parse(_obj->_mctx, &_obj->footer, json, 1);
}
/**
* image Parser
* OPTIONAL: image information
* type: object.object
*/
static
int lldc__embed_image_parse (lldc_embed_t *_obj, yyjson_val *json)
{
    _obj->image._mlog = _obj->_mlog;
    return lldc_embed_image_parse(_obj->_mctx, &_obj->image, json, 1);
}
/**
* thumbnail Parser
* OPTIONAL: thumbnail information
* type: object.object
*/
static
int lldc__embed_thumbnail_parse (lldc_embed_t *_obj, yyjson_val *json)
{
    _obj->thumbnail._mlog = _obj->_mlog;
    return lldc_embed_thumbnail_parse(_obj->_mctx, &_obj->thumbnail, json, 1);
}
/**
* video Parser
* OPTIONAL: video information
* type: object.object
*/
static
int lldc__embed_video_parse (lldc_embed_t *_obj, yyjson_val *json)
{
    _obj->video._mlog = _obj->_mlog;
    return lldc_embed_video_parse(_obj->_mctx, &_obj->video, json, 1);
}
/**
* provider Parser
* OPTIONAL: provider information
* type: object.object
*/
static
int lldc__embed_provider_parse (lldc_embed_t *_obj, yyjson_val *json)
{
    _obj->provider._mlog = _obj->_mlog;
    return lldc_embed_provider_parse(_obj->_mctx, &_obj->provider, json, 1);
}
/**
* author Parser
* OPTIONAL: author information
* type: object.object
*/
static
int lldc__embed_author_parse (lldc_embed_t *_obj, yyjson_val *json)
{
    _obj->author._mlog = _obj->_mlog;
    return lldc_embed_author_parse(_obj->_mctx, &_obj->author, json, 1);
}
/**
* fields Parser
* OPTIONAL: fields information
* type: object.object
*/
static
int lldc__embed_fields_parse (lldc_embed_t *_obj, yyjson_val *json)
{
    _obj->fields._mlog = _obj->_mlog;
    return lldc_embed_field_arr_parse(_obj->_mctx, &_obj->fields, json, 1);
}
int lldc_embed_parse (cwr_malloc_ctx_t *_mctx, lldc_embed_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_parser_def_t parser_def[13] = {
        { "title", (int (*)(void *, yyjson_val *))lldc__embed_title_parse },
        { "type", (int (*)(void *, yyjson_val *))lldc__embed_type_parse },
        { "description", (int (*)(void *, yyjson_val *))lldc__embed_description_parse },
        { "url", (int (*)(void *, yyjson_val *))lldc__embed_url_parse },
        { "timestamp", (int (*)(void *, yyjson_val *))lldc__embed_timestamp_parse },
        { "color", (int (*)(void *, yyjson_val *))lldc__embed_color_parse },
        { "footer", (int (*)(void *, yyjson_val *))lldc__embed_footer_parse },
        { "image", (int (*)(void *, yyjson_val *))lldc__embed_image_parse },
        { "thumbnail", (int (*)(void *, yyjson_val *))lldc__embed_thumbnail_parse },
        { "video", (int (*)(void *, yyjson_val *))lldc__embed_video_parse },
        { "provider", (int (*)(void *, yyjson_val *))lldc__embed_provider_parse },
        { "author", (int (*)(void *, yyjson_val *))lldc__embed_author_parse },
        { "fields", (int (*)(void *, yyjson_val *))lldc__embed_fields_parse }
    };

    static lldc_hashmap_entry_t parser_table[32] = { 0 };
    static lldc_hashmap_t parsers = {  
        .size = 32,
        .len = 0,
        .table = parser_table,
        .hash = lldc_hashmap_hash_str,
        .compare = (int (*)(const void *, const void *))strcmp,
        .dup_key = lldc_hashmap_dup_echo,
        .free_key = lldc_hashmap_free_noop
    };
    LLDC_PARSER_LOAD(13)

    if (!yyjson_is_obj(json))
        return -1;

    lldc_parser_malloc_ledger_t *ledger = obj->_mlog;
    
    memset(obj, 0, sizeof(lldc_embed_t));

    obj->_mctx = _mctx;
    if (!has_existing_ledger)
        obj->_mlog = &obj->__mlog;
    else
        obj->_mlog = ledger;

    yyjson_val *key, *val;
    yyjson_obj_iter iter;
    yyjson_obj_iter_init(json, &iter);
    while ((key = yyjson_obj_iter_next(&iter))) {
        val = yyjson_obj_iter_get_val(key);
        lldc_parser_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
/**
* Embed Parser
* Embed Objects
* type: object.object
*/
static
int lldc__embed_item_parse (lldc_embed_t *_obj, yyjson_val *json)
{
    return lldc_embed_parse(_obj->_mctx, _obj, json, 1);
}
int lldc_embed_arr_parse (cwr_malloc_ctx_t *_mctx, lldc_embed_arr_t *obj, yyjson_val *json, int has_existing_ledger)
{

    if (!yyjson_is_arr(json))
        return -1;

    size_t arr_size = yyjson_arr_size(json);
    if (!arr_size)
    {
        obj->items = NULL;
        obj->len = 0;
        return 0;
    }

    obj->_mctx = _mctx;
    if (!has_existing_ledger)
        obj->_mlog = &obj->__mlog;

    obj->items = lldc_parser_malloc((lldc_parser_obj_t *)obj, sizeof(*obj->items) * arr_size);
    if (obj->items == NULL)
    {
        obj->len = 0;
        return -1;
    }
    obj->len = arr_size;

    size_t idx, max;
    yyjson_val *val;
    yyjson_arr_foreach(json, idx, max, val) {
        obj->items[idx]._mctx = obj->_mctx;
        obj->items[idx]._mlog = obj->_mlog;
        lldc__embed_item_parse(&obj->items[idx], val);
    }

    return 0;
}
/**
* roles Parser
* OPTIONAL: roles allowed to use this emoji
* type: object.array[snowflake]
*/
static
int lldc__emoji_roles_parse (lldc_emoji_t *_obj, yyjson_val *json)
{
    lldc_parser_snowflake_arr_t *obj = &_obj->roles;

    obj->_mctx = _obj->_mctx;
    obj->_mlog = _obj->_mlog;
    return lldc_parser_snowflake_arr_parse(obj, json);
}
/**
* user Parser
* OPTIONAL: user that created this emoji
* type: object.object
*/
static
int lldc__emoji_user_parse (lldc_emoji_t *_obj, yyjson_val *json)
{
    _obj->user._mlog = _obj->_mlog;
    return lldc_user_parse(_obj->_mctx, &_obj->user, json, 1);
}
int lldc_emoji_parse (cwr_malloc_ctx_t *_mctx, lldc_emoji_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_parser_def_t parser_def[8] = {
        { "id", (int (*)(void *, yyjson_val *))lldc__emoji_id_parse },
        { "name", (int (*)(void *, yyjson_val *))lldc__emoji_name_parse },
        { "roles", (int (*)(void *, yyjson_val *))lldc__emoji_roles_parse },
        { "user", (int (*)(void *, yyjson_val *))lldc__emoji_user_parse },
        { "require_colons", (int (*)(void *, yyjson_val *))lldc__emoji_require_colons_parse },
        { "managed", (int (*)(void *, yyjson_val *))lldc__emoji_managed_parse },
        { "animated", (int (*)(void *, yyjson_val *))lldc__emoji_animated_parse },
        { "available", (int (*)(void *, yyjson_val *))lldc__emoji_available_parse }
    };

    static lldc_hashmap_entry_t parser_table[16] = { 0 };
    static lldc_hashmap_t parsers = {  
        .size = 16,
        .len = 0,
        .table = parser_table,
        .hash = lldc_hashmap_hash_str,
        .compare = (int (*)(const void *, const void *))strcmp,
        .dup_key = lldc_hashmap_dup_echo,
        .free_key = lldc_hashmap_free_noop
    };
    LLDC_PARSER_LOAD(8)

    if (!yyjson_is_obj(json))
        return -1;

    lldc_parser_malloc_ledger_t *ledger = obj->_mlog;
    
    memset(obj, 0, sizeof(lldc_emoji_t));

    obj->_mctx = _mctx;
    if (!has_existing_ledger)
        obj->_mlog = &obj->__mlog;
    else
        obj->_mlog = ledger;

    yyjson_val *key, *val;
    yyjson_obj_iter iter;
    yyjson_obj_iter_init(json, &iter);
    while ((key = yyjson_obj_iter_next(&iter))) {
        val = yyjson_obj_iter_get_val(key);
        lldc_parser_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
/**
* Emoji Parser
* Emoji Objects
* type: object.object
*/
static
int lldc__emoji_item_parse (lldc_emoji_t *_obj, yyjson_val *json)
{
    return lldc_emoji_parse(_obj->_mctx, _obj, json, 1);
}
int lldc_emoji_arr_parse (cwr_malloc_ctx_t *_mctx, lldc_emoji_arr_t *obj, yyjson_val *json, int has_existing_ledger)
{

    if (!yyjson_is_arr(json))
        return -1;

    size_t arr_size = yyjson_arr_size(json);
    if (!arr_size)
    {
        obj->items = NULL;
        obj->len = 0;
        return 0;
    }

    obj->_mctx = _mctx;
    if (!has_existing_ledger)
        obj->_mlog = &obj->__mlog;

    obj->items = lldc_parser_malloc((lldc_parser_obj_t *)obj, sizeof(*obj->items) * arr_size);
    if (obj->items == NULL)
    {
        obj->len = 0;
        return -1;
    }
    obj->len = arr_size;

    size_t idx, max;
    yyjson_val *val;
    yyjson_arr_foreach(json, idx, max, val) {
        obj->items[idx]._mctx = obj->_mctx;
        obj->items[idx]._mlog = obj->_mlog;
        lldc__emoji_item_parse(&obj->items[idx], val);
    }

    return 0;
}
/**
* emoji Parser
* emoji information
* type: object.object
*/
static
int lldc__reaction_emoji_parse (lldc_reaction_t *_obj, yyjson_val *json)
{
    _obj->emoji._mlog = _obj->_mlog;
    return lldc_emoji_parse(_obj->_mctx, &_obj->emoji, json, 1);
}
int lldc_reaction_parse (cwr_malloc_ctx_t *_mctx, lldc_reaction_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_parser_def_t parser_def[3] = {
        { "count", (int (*)(void *, yyjson_val *))lldc__reaction_count_parse },
        { "me", (int (*)(void *, yyjson_val *))lldc__reaction_me_parse },
        { "emoji", (int (*)(void *, yyjson_val *))lldc__reaction_emoji_parse }
    };

    static lldc_hashmap_entry_t parser_table[8] = { 0 };
    static lldc_hashmap_t parsers = {  
        .size = 8,
        .len = 0,
        .table = parser_table,
        .hash = lldc_hashmap_hash_str,
        .compare = (int (*)(const void *, const void *))strcmp,
        .dup_key = lldc_hashmap_dup_echo,
        .free_key = lldc_hashmap_free_noop
    };
    LLDC_PARSER_LOAD(3)

    if (!yyjson_is_obj(json))
        return -1;

    lldc_parser_malloc_ledger_t *ledger = obj->_mlog;
    
    memset(obj, 0, sizeof(lldc_reaction_t));

    obj->_mctx = _mctx;
    if (!has_existing_ledger)
        obj->_mlog = &obj->__mlog;
    else
        obj->_mlog = ledger;

    yyjson_val *key, *val;
    yyjson_obj_iter iter;
    yyjson_obj_iter_init(json, &iter);
    while ((key = yyjson_obj_iter_next(&iter))) {
        val = yyjson_obj_iter_get_val(key);
        lldc_parser_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
/**
* Reaction Parser
* Reaction Objects
* type: object.object
*/
static
int lldc__reaction_item_parse (lldc_reaction_t *_obj, yyjson_val *json)
{
    return lldc_reaction_parse(_obj->_mctx, _obj, json, 1);
}
int lldc_reaction_arr_parse (cwr_malloc_ctx_t *_mctx, lldc_reaction_arr_t *obj, yyjson_val *json, int has_existing_ledger)
{

    if (!yyjson_is_arr(json))
        return -1;

    size_t arr_size = yyjson_arr_size(json);
    if (!arr_size)
    {
        obj->items = NULL;
        obj->len = 0;
        return 0;
    }

    obj->_mctx = _mctx;
    if (!has_existing_ledger)
        obj->_mlog = &obj->__mlog;

    obj->items = lldc_parser_malloc((lldc_parser_obj_t *)obj, sizeof(*obj->items) * arr_size);
    if (obj->items == NULL)
    {
        obj->len = 0;
        return -1;
    }
    obj->len = arr_size;

    size_t idx, max;
    yyjson_val *val;
    yyjson_arr_foreach(json, idx, max, val) {
        obj->items[idx]._mctx = obj->_mctx;
        obj->items[idx]._mlog = obj->_mlog;
        lldc__reaction_item_parse(&obj->items[idx], val);
    }

    return 0;
}
int lldc_interaction_account_parse (cwr_malloc_ctx_t *_mctx, lldc_interaction_account_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_parser_def_t parser_def[2] = {
        { "id", (int (*)(void *, yyjson_val *))lldc__interaction_account_id_parse },
        { "name", (int (*)(void *, yyjson_val *))lldc__interaction_account_name_parse }
    };

    static lldc_hashmap_entry_t parser_table[4] = { 0 };
    static lldc_hashmap_t parsers = {  
        .size = 4,
        .len = 0,
        .table = parser_table,
        .hash = lldc_hashmap_hash_str,
        .compare = (int (*)(const void *, const void *))strcmp,
        .dup_key = lldc_hashmap_dup_echo,
        .free_key = lldc_hashmap_free_noop
    };
    LLDC_PARSER_LOAD(2)

    if (!yyjson_is_obj(json))
        return -1;

    lldc_parser_malloc_ledger_t *ledger = obj->_mlog;
    
    memset(obj, 0, sizeof(lldc_interaction_account_t));

    obj->_mctx = _mctx;
    if (!has_existing_ledger)
        obj->_mlog = &obj->__mlog;
    else
        obj->_mlog = ledger;

    yyjson_val *key, *val;
    yyjson_obj_iter iter;
    yyjson_obj_iter_init(json, &iter);
    while ((key = yyjson_obj_iter_next(&iter))) {
        val = yyjson_obj_iter_get_val(key);
        lldc_parser_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
/**
* emoji Parser
* OPTIONAL: id, name, and animated
* type: object.object
*/
static
int lldc__select_option_emoji_parse (lldc_select_option_t *_obj, yyjson_val *json)
{
    _obj->emoji._mlog = _obj->_mlog;
    return lldc_emoji_parse(_obj->_mctx, &_obj->emoji, json, 1);
}
int lldc_select_option_parse (cwr_malloc_ctx_t *_mctx, lldc_select_option_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_parser_def_t parser_def[5] = {
        { "label", (int (*)(void *, yyjson_val *))lldc__select_option_label_parse },
        { "value", (int (*)(void *, yyjson_val *))lldc__select_option_value_parse },
        { "description", (int (*)(void *, yyjson_val *))lldc__select_option_description_parse },
        { "emoji", (int (*)(void *, yyjson_val *))lldc__select_option_emoji_parse },
        { "default", (int (*)(void *, yyjson_val *))lldc__select_option_is_default_parse }
    };

    static lldc_hashmap_entry_t parser_table[8] = { 0 };
    static lldc_hashmap_t parsers = {  
        .size = 8,
        .len = 0,
        .table = parser_table,
        .hash = lldc_hashmap_hash_str,
        .compare = (int (*)(const void *, const void *))strcmp,
        .dup_key = lldc_hashmap_dup_echo,
        .free_key = lldc_hashmap_free_noop
    };
    LLDC_PARSER_LOAD(5)

    if (!yyjson_is_obj(json))
        return -1;

    lldc_parser_malloc_ledger_t *ledger = obj->_mlog;
    
    memset(obj, 0, sizeof(lldc_select_option_t));

    obj->_mctx = _mctx;
    if (!has_existing_ledger)
        obj->_mlog = &obj->__mlog;
    else
        obj->_mlog = ledger;

    yyjson_val *key, *val;
    yyjson_obj_iter iter;
    yyjson_obj_iter_init(json, &iter);
    while ((key = yyjson_obj_iter_next(&iter))) {
        val = yyjson_obj_iter_get_val(key);
        lldc_parser_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
/**
* Select Option Parser
* Select Option Objects
* type: object.object
*/
static
int lldc__select_option_item_parse (lldc_select_option_t *_obj, yyjson_val *json)
{
    return lldc_select_option_parse(_obj->_mctx, _obj, json, 1);
}
int lldc_select_option_arr_parse (cwr_malloc_ctx_t *_mctx, lldc_select_option_arr_t *obj, yyjson_val *json, int has_existing_ledger)
{

    if (!yyjson_is_arr(json))
        return -1;

    size_t arr_size = yyjson_arr_size(json);
    if (!arr_size)
    {
        obj->items = NULL;
        obj->len = 0;
        return 0;
    }

    obj->_mctx = _mctx;
    if (!has_existing_ledger)
        obj->_mlog = &obj->__mlog;

    obj->items = lldc_parser_malloc((lldc_parser_obj_t *)obj, sizeof(*obj->items) * arr_size);
    if (obj->items == NULL)
    {
        obj->len = 0;
        return -1;
    }
    obj->len = arr_size;

    size_t idx, max;
    yyjson_val *val;
    yyjson_arr_foreach(json, idx, max, val) {
        obj->items[idx]._mctx = obj->_mctx;
        obj->items[idx]._mlog = obj->_mlog;
        lldc__select_option_item_parse(&obj->items[idx], val);
    }

    return 0;
}
/**
* Component Parser
* Component Objects
* type: object.object
*/
static
int lldc__component_item_parse (lldc_component_t *_obj, yyjson_val *json)
{
    return lldc_component_parse(_obj->_mctx, _obj, json, 1);
}
int lldc_component_arr_parse (cwr_malloc_ctx_t *_mctx, lldc_component_arr_t *obj, yyjson_val *json, int has_existing_ledger)
{

    if (!yyjson_is_arr(json))
        return -1;

    size_t arr_size = yyjson_arr_size(json);
    if (!arr_size)
    {
        obj->items = NULL;
        obj->len = 0;
        return 0;
    }

    obj->_mctx = _mctx;
    if (!has_existing_ledger)
        obj->_mlog = &obj->__mlog;

    obj->items = lldc_parser_malloc((lldc_parser_obj_t *)obj, sizeof(*obj->items) * arr_size);
    if (obj->items == NULL)
    {
        obj->len = 0;
        return -1;
    }
    obj->len = arr_size;

    size_t idx, max;
    yyjson_val *val;
    yyjson_arr_foreach(json, idx, max, val) {
        obj->items[idx]._mctx = obj->_mctx;
        obj->items[idx]._mlog = obj->_mlog;
        lldc__component_item_parse(&obj->items[idx], val);
    }

    return 0;
}
/**
* emoji Parser
* OPTIONAL: name, id, and animated
* type: object.object
*/
static
int lldc__component_emoji_parse (lldc_component_t *_obj, yyjson_val *json)
{
    _obj->emoji._mlog = _obj->_mlog;
    return lldc_emoji_parse(_obj->_mctx, &_obj->emoji, json, 1);
}
/**
* options Parser
* the choices in the select, max 25
* type: object.object
*/
static
int lldc__component_options_parse (lldc_component_t *_obj, yyjson_val *json)
{
    _obj->options._mlog = _obj->_mlog;
    return lldc_select_option_arr_parse(_obj->_mctx, &_obj->options, json, 1);
}
/**
* components Parser
* OPTIONAL: a list of child components
* type: object.object
*/
static
int lldc__component_components_parse (lldc_component_t *_obj, yyjson_val *json)
{
    _obj->components._mlog = _obj->_mlog;
    return lldc_component_arr_parse(_obj->_mctx, &_obj->components, json, 1);
}
int lldc_component_parse (cwr_malloc_ctx_t *_mctx, lldc_component_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_parser_def_t parser_def[12] = {
        { "type", (int (*)(void *, yyjson_val *))lldc__component_type_parse },
        { "custom_id", (int (*)(void *, yyjson_val *))lldc__component_custom_id_parse },
        { "disabled", (int (*)(void *, yyjson_val *))lldc__component_disabled_parse },
        { "style", (int (*)(void *, yyjson_val *))lldc__component_style_parse },
        { "label", (int (*)(void *, yyjson_val *))lldc__component_label_parse },
        { "emoji", (int (*)(void *, yyjson_val *))lldc__component_emoji_parse },
        { "url", (int (*)(void *, yyjson_val *))lldc__component_url_parse },
        { "options", (int (*)(void *, yyjson_val *))lldc__component_options_parse },
        { "placeholder", (int (*)(void *, yyjson_val *))lldc__component_placeholder_parse },
        { "min_values", (int (*)(void *, yyjson_val *))lldc__component_min_values_parse },
        { "max_values", (int (*)(void *, yyjson_val *))lldc__component_max_values_parse },
        { "components", (int (*)(void *, yyjson_val *))lldc__component_components_parse }
    };

    static lldc_hashmap_entry_t parser_table[32] = { 0 };
    static lldc_hashmap_t parsers = {  
        .size = 32,
        .len = 0,
        .table = parser_table,
        .hash = lldc_hashmap_hash_str,
        .compare = (int (*)(const void *, const void *))strcmp,
        .dup_key = lldc_hashmap_dup_echo,
        .free_key = lldc_hashmap_free_noop
    };
    LLDC_PARSER_LOAD(12)

    if (!yyjson_is_obj(json))
        return -1;

    lldc_parser_malloc_ledger_t *ledger = obj->_mlog;
    
    memset(obj, 0, sizeof(lldc_component_t));

    obj->_mctx = _mctx;
    if (!has_existing_ledger)
        obj->_mlog = &obj->__mlog;
    else
        obj->_mlog = ledger;

    yyjson_val *key, *val;
    yyjson_obj_iter iter;
    yyjson_obj_iter_init(json, &iter);
    while ((key = yyjson_obj_iter_next(&iter))) {
        val = yyjson_obj_iter_get_val(key);
        lldc_parser_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
int lldc_sticker_item_parse (cwr_malloc_ctx_t *_mctx, lldc_sticker_item_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_parser_def_t parser_def[3] = {
        { "id", (int (*)(void *, yyjson_val *))lldc__sticker_item_id_parse },
        { "name", (int (*)(void *, yyjson_val *))lldc__sticker_item_name_parse },
        { "format_type", (int (*)(void *, yyjson_val *))lldc__sticker_item_format_type_parse }
    };

    static lldc_hashmap_entry_t parser_table[8] = { 0 };
    static lldc_hashmap_t parsers = {  
        .size = 8,
        .len = 0,
        .table = parser_table,
        .hash = lldc_hashmap_hash_str,
        .compare = (int (*)(const void *, const void *))strcmp,
        .dup_key = lldc_hashmap_dup_echo,
        .free_key = lldc_hashmap_free_noop
    };
    LLDC_PARSER_LOAD(3)

    if (!yyjson_is_obj(json))
        return -1;

    lldc_parser_malloc_ledger_t *ledger = obj->_mlog;
    
    memset(obj, 0, sizeof(lldc_sticker_item_t));

    obj->_mctx = _mctx;
    if (!has_existing_ledger)
        obj->_mlog = &obj->__mlog;
    else
        obj->_mlog = ledger;

    yyjson_val *key, *val;
    yyjson_obj_iter iter;
    yyjson_obj_iter_init(json, &iter);
    while ((key = yyjson_obj_iter_next(&iter))) {
        val = yyjson_obj_iter_get_val(key);
        lldc_parser_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
/**
* Sticker Item Parser
* Sticker Item Objects
* type: object.object
*/
static
int lldc__sticker_item_item_parse (lldc_sticker_item_t *_obj, yyjson_val *json)
{
    return lldc_sticker_item_parse(_obj->_mctx, _obj, json, 1);
}
int lldc_sticker_item_arr_parse (cwr_malloc_ctx_t *_mctx, lldc_sticker_item_arr_t *obj, yyjson_val *json, int has_existing_ledger)
{

    if (!yyjson_is_arr(json))
        return -1;

    size_t arr_size = yyjson_arr_size(json);
    if (!arr_size)
    {
        obj->items = NULL;
        obj->len = 0;
        return 0;
    }

    obj->_mctx = _mctx;
    if (!has_existing_ledger)
        obj->_mlog = &obj->__mlog;

    obj->items = lldc_parser_malloc((lldc_parser_obj_t *)obj, sizeof(*obj->items) * arr_size);
    if (obj->items == NULL)
    {
        obj->len = 0;
        return -1;
    }
    obj->len = arr_size;

    size_t idx, max;
    yyjson_val *val;
    yyjson_arr_foreach(json, idx, max, val) {
        obj->items[idx]._mctx = obj->_mctx;
        obj->items[idx]._mlog = obj->_mlog;
        lldc__sticker_item_item_parse(&obj->items[idx], val);
    }

    return 0;
}
int lldc_message_activity_parse (cwr_malloc_ctx_t *_mctx, lldc_message_activity_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_parser_def_t parser_def[2] = {
        { "type", (int (*)(void *, yyjson_val *))lldc__message_activity_type_parse },
        { "party_id", (int (*)(void *, yyjson_val *))lldc__message_activity_party_id_parse }
    };

    static lldc_hashmap_entry_t parser_table[4] = { 0 };
    static lldc_hashmap_t parsers = {  
        .size = 4,
        .len = 0,
        .table = parser_table,
        .hash = lldc_hashmap_hash_str,
        .compare = (int (*)(const void *, const void *))strcmp,
        .dup_key = lldc_hashmap_dup_echo,
        .free_key = lldc_hashmap_free_noop
    };
    LLDC_PARSER_LOAD(2)

    if (!yyjson_is_obj(json))
        return -1;

    lldc_parser_malloc_ledger_t *ledger = obj->_mlog;
    
    memset(obj, 0, sizeof(lldc_message_activity_t));

    obj->_mctx = _mctx;
    if (!has_existing_ledger)
        obj->_mlog = &obj->__mlog;
    else
        obj->_mlog = ledger;

    yyjson_val *key, *val;
    yyjson_obj_iter iter;
    yyjson_obj_iter_init(json, &iter);
    while ((key = yyjson_obj_iter_next(&iter))) {
        val = yyjson_obj_iter_get_val(key);
        lldc_parser_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
int lldc_message_reference_parse (cwr_malloc_ctx_t *_mctx, lldc_message_reference_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_parser_def_t parser_def[4] = {
        { "message_id", (int (*)(void *, yyjson_val *))lldc__message_reference_message_id_parse },
        { "channel_id", (int (*)(void *, yyjson_val *))lldc__message_reference_channel_id_parse },
        { "guild_id", (int (*)(void *, yyjson_val *))lldc__message_reference_guild_id_parse },
        { "fail_if_not_exists", (int (*)(void *, yyjson_val *))lldc__message_reference_fail_if_not_exists_parse }
    };

    static lldc_hashmap_entry_t parser_table[8] = { 0 };
    static lldc_hashmap_t parsers = {  
        .size = 8,
        .len = 0,
        .table = parser_table,
        .hash = lldc_hashmap_hash_str,
        .compare = (int (*)(const void *, const void *))strcmp,
        .dup_key = lldc_hashmap_dup_echo,
        .free_key = lldc_hashmap_free_noop
    };
    LLDC_PARSER_LOAD(4)

    if (!yyjson_is_obj(json))
        return -1;

    lldc_parser_malloc_ledger_t *ledger = obj->_mlog;
    
    memset(obj, 0, sizeof(lldc_message_reference_t));

    obj->_mctx = _mctx;
    if (!has_existing_ledger)
        obj->_mlog = &obj->__mlog;
    else
        obj->_mlog = ledger;

    yyjson_val *key, *val;
    yyjson_obj_iter iter;
    yyjson_obj_iter_init(json, &iter);
    while ((key = yyjson_obj_iter_next(&iter))) {
        val = yyjson_obj_iter_get_val(key);
        lldc_parser_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
/**
* user Parser
* the user who invoked the interaction
* type: object.object
*/
static
int lldc__message_interaction_user_parse (lldc_message_interaction_t *_obj, yyjson_val *json)
{
    _obj->user._mlog = _obj->_mlog;
    return lldc_user_parse(_obj->_mctx, &_obj->user, json, 1);
}
int lldc_message_interaction_parse (cwr_malloc_ctx_t *_mctx, lldc_message_interaction_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_parser_def_t parser_def[4] = {
        { "id", (int (*)(void *, yyjson_val *))lldc__message_interaction_id_parse },
        { "type", (int (*)(void *, yyjson_val *))lldc__message_interaction_type_parse },
        { "name", (int (*)(void *, yyjson_val *))lldc__message_interaction_name_parse },
        { "user", (int (*)(void *, yyjson_val *))lldc__message_interaction_user_parse }
    };

    static lldc_hashmap_entry_t parser_table[8] = { 0 };
    static lldc_hashmap_t parsers = {  
        .size = 8,
        .len = 0,
        .table = parser_table,
        .hash = lldc_hashmap_hash_str,
        .compare = (int (*)(const void *, const void *))strcmp,
        .dup_key = lldc_hashmap_dup_echo,
        .free_key = lldc_hashmap_free_noop
    };
    LLDC_PARSER_LOAD(4)

    if (!yyjson_is_obj(json))
        return -1;

    lldc_parser_malloc_ledger_t *ledger = obj->_mlog;
    
    memset(obj, 0, sizeof(lldc_message_interaction_t));

    obj->_mctx = _mctx;
    if (!has_existing_ledger)
        obj->_mlog = &obj->__mlog;
    else
        obj->_mlog = ledger;

    yyjson_val *key, *val;
    yyjson_obj_iter iter;
    yyjson_obj_iter_init(json, &iter);
    while ((key = yyjson_obj_iter_next(&iter))) {
        val = yyjson_obj_iter_get_val(key);
        lldc_parser_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
/**
* author Parser
* the author of this message (not guaranteed to be a valid user, see below)
* type: object.object
*/
static
int lldc__message_author_parse (lldc_message_t *_obj, yyjson_val *json)
{
    _obj->author._mlog = _obj->_mlog;
    return lldc_user_parse(_obj->_mctx, &_obj->author, json, 1);
}
/**
* member Parser
* OPTIONAL: member properties for this message's author
* type: object.object
*/
static
int lldc__message_member_parse (lldc_message_t *_obj, yyjson_val *json)
{
    _obj->member._mlog = _obj->_mlog;
    return lldc_partial_guild_member_parse(_obj->_mctx, &_obj->member, json, 1);
}
/**
* mentions Parser
* users specifically mentioned in the message
* type: object.object
*/
static
int lldc__message_mentions_parse (lldc_message_t *_obj, yyjson_val *json)
{
    _obj->mentions._mlog = _obj->_mlog;
    return lldc_user_arr_parse(_obj->_mctx, &_obj->mentions, json, 1);
}
/**
* mention_roles Parser
* roles specifically mentioned in this message
* type: object.array[snowflake]
*/
static
int lldc__message_mention_roles_parse (lldc_message_t *_obj, yyjson_val *json)
{
    lldc_parser_snowflake_arr_t *obj = &_obj->mention_roles;

    obj->_mctx = _obj->_mctx;
    obj->_mlog = _obj->_mlog;
    return lldc_parser_snowflake_arr_parse(obj, json);
}
/**
* mention_channels Parser
* OPTIONAL: channels specifically mentioned in this message
* type: object.object
*/
static
int lldc__message_mention_channels_parse (lldc_message_t *_obj, yyjson_val *json)
{
    _obj->mention_channels._mlog = _obj->_mlog;
    return lldc_channel_mention_parse(_obj->_mctx, &_obj->mention_channels, json, 1);
}
/**
* attachments Parser
* any attached files
* type: object.object
*/
static
int lldc__message_attachments_parse (lldc_message_t *_obj, yyjson_val *json)
{
    _obj->attachments._mlog = _obj->_mlog;
    return lldc_attachment_arr_parse(_obj->_mctx, &_obj->attachments, json, 1);
}
/**
* embeds Parser
* any embedded content
* type: object.object
*/
static
int lldc__message_embeds_parse (lldc_message_t *_obj, yyjson_val *json)
{
    _obj->embeds._mlog = _obj->_mlog;
    return lldc_embed_arr_parse(_obj->_mctx, &_obj->embeds, json, 1);
}
/**
* reactions Parser
* OPTIONAL: reactions to the message
* type: object.object
*/
static
int lldc__message_reactions_parse (lldc_message_t *_obj, yyjson_val *json)
{
    _obj->reactions._mlog = _obj->_mlog;
    return lldc_reaction_parse(_obj->_mctx, &_obj->reactions, json, 1);
}
/**
* message_reference Parser
* OPTIONAL: data showing the source of a crosspost, channel follow add, pin, or reply message
* type: object.object
*/
static
int lldc__message_message_reference_parse (lldc_message_t *_obj, yyjson_val *json)
{
    _obj->message_reference._mlog = _obj->_mlog;
    return lldc_message_reference_parse(_obj->_mctx, &_obj->message_reference, json, 1);
}
/**
* interaction Parser
* OPTIONAL: sent if the message is a response to an Interaction
* type: object.object
*/
static
int lldc__message_interaction_parse (lldc_message_t *_obj, yyjson_val *json)
{
    _obj->interaction._mlog = _obj->_mlog;
    return lldc_message_interaction_parse(_obj->_mctx, &_obj->interaction, json, 1);
}
/**
* components Parser
* OPTIONAL: sent if the message contains components like buttons, action rows, or other interactive components
* type: object.object
*/
static
int lldc__message_components_parse (lldc_message_t *_obj, yyjson_val *json)
{
    _obj->components._mlog = _obj->_mlog;
    return lldc_component_arr_parse(_obj->_mctx, &_obj->components, json, 1);
}
/**
* sticker_items Parser
* OPTIONAL: sent if the message contains stickers
* type: object.object
*/
static
int lldc__message_sticker_items_parse (lldc_message_t *_obj, yyjson_val *json)
{
    _obj->sticker_items._mlog = _obj->_mlog;
    return lldc_sticker_item_arr_parse(_obj->_mctx, &_obj->sticker_items, json, 1);
}
int lldc_message_parse (cwr_malloc_ctx_t *_mctx, lldc_message_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_parser_def_t parser_def[28] = {
        { "id", (int (*)(void *, yyjson_val *))lldc__message_id_parse },
        { "channel_id", (int (*)(void *, yyjson_val *))lldc__message_channel_id_parse },
        { "guild_id", (int (*)(void *, yyjson_val *))lldc__message_guild_id_parse },
        { "author", (int (*)(void *, yyjson_val *))lldc__message_author_parse },
        { "member", (int (*)(void *, yyjson_val *))lldc__message_member_parse },
        { "content", (int (*)(void *, yyjson_val *))lldc__message_content_parse },
        { "timestamp", (int (*)(void *, yyjson_val *))lldc__message_timestamp_parse },
        { "edited_timestamp", (int (*)(void *, yyjson_val *))lldc__message_edited_timestamp_parse },
        { "tts", (int (*)(void *, yyjson_val *))lldc__message_tts_parse },
        { "mention_everyone", (int (*)(void *, yyjson_val *))lldc__message_mention_everyone_parse },
        { "mentions", (int (*)(void *, yyjson_val *))lldc__message_mentions_parse },
        { "mention_roles", (int (*)(void *, yyjson_val *))lldc__message_mention_roles_parse },
        { "mention_channels", (int (*)(void *, yyjson_val *))lldc__message_mention_channels_parse },
        { "attachments", (int (*)(void *, yyjson_val *))lldc__message_attachments_parse },
        { "embeds", (int (*)(void *, yyjson_val *))lldc__message_embeds_parse },
        { "reactions", (int (*)(void *, yyjson_val *))lldc__message_reactions_parse },
        { "pinned", (int (*)(void *, yyjson_val *))lldc__message_pinned_parse },
        { "webhook_id", (int (*)(void *, yyjson_val *))lldc__message_webhook_id_parse },
        { "type", (int (*)(void *, yyjson_val *))lldc__message_type_parse },
        { "activity", (int (*)(void *, yyjson_val *))lldc__message_activity_parse },
        { "application", (int (*)(void *, yyjson_val *))lldc__message_application_parse },
        { "application_id", (int (*)(void *, yyjson_val *))lldc__message_application_id_parse },
        { "message_reference", (int (*)(void *, yyjson_val *))lldc__message_message_reference_parse },
        { "flags", (int (*)(void *, yyjson_val *))lldc__message_flags_parse },
        { "interaction", (int (*)(void *, yyjson_val *))lldc__message_interaction_parse },
        { "thread", (int (*)(void *, yyjson_val *))lldc__message_thread_parse },
        { "components", (int (*)(void *, yyjson_val *))lldc__message_components_parse },
        { "sticker_items", (int (*)(void *, yyjson_val *))lldc__message_sticker_items_parse }
    };

    static lldc_hashmap_entry_t parser_table[64] = { 0 };
    static lldc_hashmap_t parsers = {  
        .size = 64,
        .len = 0,
        .table = parser_table,
        .hash = lldc_hashmap_hash_str,
        .compare = (int (*)(const void *, const void *))strcmp,
        .dup_key = lldc_hashmap_dup_echo,
        .free_key = lldc_hashmap_free_noop
    };
    LLDC_PARSER_LOAD(28)

    if (!yyjson_is_obj(json))
        return -1;

    lldc_parser_malloc_ledger_t *ledger = obj->_mlog;
    
    memset(obj, 0, sizeof(lldc_message_t));

    obj->_mctx = _mctx;
    if (!has_existing_ledger)
        obj->_mlog = &obj->__mlog;
    else
        obj->_mlog = ledger;

    yyjson_val *key, *val;
    yyjson_obj_iter iter;
    yyjson_obj_iter_init(json, &iter);
    while ((key = yyjson_obj_iter_next(&iter))) {
        val = yyjson_obj_iter_get_val(key);
        lldc_parser_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
/**
* permission_overwrites Parser
* OPTIONAL: explicit permission overwrites for members and roles
* type: object.object
*/
static
int lldc__channel_permission_overwrites_parse (lldc_channel_t *_obj, yyjson_val *json)
{
    _obj->permission_overwrites._mlog = _obj->_mlog;
    return lldc_channel_overwrite_arr_parse(_obj->_mctx, &_obj->permission_overwrites, json, 1);
}
/**
* recipients Parser
* OPTIONAL: the recipients of the DM
* type: object.object
*/
static
int lldc__channel_recipients_parse (lldc_channel_t *_obj, yyjson_val *json)
{
    _obj->recipients._mlog = _obj->_mlog;
    return lldc_user_arr_parse(_obj->_mctx, &_obj->recipients, json, 1);
}
/**
* thread_metadata Parser
* OPTIONAL: thread-specific fields not needed by other channels
* type: object.object
*/
static
int lldc__channel_thread_metadata_parse (lldc_channel_t *_obj, yyjson_val *json)
{
    _obj->thread_metadata._mlog = _obj->_mlog;
    return lldc_thread_metadata_parse(_obj->_mctx, &_obj->thread_metadata, json, 1);
}
/**
* member Parser
* OPTIONAL: thread member object for the current user, if they have joined the thread, only included on certain API endpoints
* type: object.object
*/
static
int lldc__channel_member_parse (lldc_channel_t *_obj, yyjson_val *json)
{
    _obj->member._mlog = _obj->_mlog;
    return lldc_thread_member_parse(_obj->_mctx, &_obj->member, json, 1);
}
int lldc_channel_parse (cwr_malloc_ctx_t *_mctx, lldc_channel_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_parser_def_t parser_def[26] = {
        { "id", (int (*)(void *, yyjson_val *))lldc__channel_id_parse },
        { "type", (int (*)(void *, yyjson_val *))lldc__channel_type_parse },
        { "guild_id", (int (*)(void *, yyjson_val *))lldc__channel_guild_id_parse },
        { "position", (int (*)(void *, yyjson_val *))lldc__channel_position_parse },
        { "permission_overwrites", (int (*)(void *, yyjson_val *))lldc__channel_permission_overwrites_parse },
        { "name", (int (*)(void *, yyjson_val *))lldc__channel_name_parse },
        { "topic", (int (*)(void *, yyjson_val *))lldc__channel_topic_parse },
        { "nsfw", (int (*)(void *, yyjson_val *))lldc__channel_nsfw_parse },
        { "last_message_id", (int (*)(void *, yyjson_val *))lldc__channel_last_message_id_parse },
        { "bitrate", (int (*)(void *, yyjson_val *))lldc__channel_bitrate_parse },
        { "user_limit", (int (*)(void *, yyjson_val *))lldc__channel_user_limit_parse },
        { "rate_limit_per_user", (int (*)(void *, yyjson_val *))lldc__channel_rate_limit_per_user_parse },
        { "recipients", (int (*)(void *, yyjson_val *))lldc__channel_recipients_parse },
        { "icon", (int (*)(void *, yyjson_val *))lldc__channel_icon_parse },
        { "owner_id", (int (*)(void *, yyjson_val *))lldc__channel_owner_id_parse },
        { "application_id", (int (*)(void *, yyjson_val *))lldc__channel_application_id_parse },
        { "parent_id", (int (*)(void *, yyjson_val *))lldc__channel_parent_id_parse },
        { "last_pin_timestamp", (int (*)(void *, yyjson_val *))lldc__channel_last_pin_timestamp_parse },
        { "rtc_region", (int (*)(void *, yyjson_val *))lldc__channel_rtc_region_parse },
        { "video_quality_mode", (int (*)(void *, yyjson_val *))lldc__channel_video_quality_mode_parse },
        { "message_count", (int (*)(void *, yyjson_val *))lldc__channel_message_count_parse },
        { "member_count", (int (*)(void *, yyjson_val *))lldc__channel_member_count_parse },
        { "thread_metadata", (int (*)(void *, yyjson_val *))lldc__channel_thread_metadata_parse },
        { "member", (int (*)(void *, yyjson_val *))lldc__channel_member_parse },
        { "default_auto_archive_duration", (int (*)(void *, yyjson_val *))lldc__channel_default_auto_archive_duration_parse },
        { "permissions", (int (*)(void *, yyjson_val *))lldc__channel_permissions_parse }
    };

    static lldc_hashmap_entry_t parser_table[64] = { 0 };
    static lldc_hashmap_t parsers = {  
        .size = 64,
        .len = 0,
        .table = parser_table,
        .hash = lldc_hashmap_hash_str,
        .compare = (int (*)(const void *, const void *))strcmp,
        .dup_key = lldc_hashmap_dup_echo,
        .free_key = lldc_hashmap_free_noop
    };
    LLDC_PARSER_LOAD(26)

    if (!yyjson_is_obj(json))
        return -1;

    lldc_parser_malloc_ledger_t *ledger = obj->_mlog;
    
    memset(obj, 0, sizeof(lldc_channel_t));

    obj->_mctx = _mctx;
    if (!has_existing_ledger)
        obj->_mlog = &obj->__mlog;
    else
        obj->_mlog = ledger;

    yyjson_val *key, *val;
    yyjson_obj_iter iter;
    yyjson_obj_iter_init(json, &iter);
    while ((key = yyjson_obj_iter_next(&iter))) {
        val = yyjson_obj_iter_get_val(key);
        lldc_parser_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}