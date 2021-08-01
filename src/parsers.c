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