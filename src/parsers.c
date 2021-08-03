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
 * custom Parser
 * whether this is a custom voice region (used for events/etc)
 * type: object.bool
 */
static
int lldc__voice_region_custom_parse (lldc_voice_region_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_bool(json))
        return -1;

    obj->custom = yyjson_get_bool(json);

    return 0;
}
/**
 * deprecated Parser
 * whether this is a deprecated voice region (avoid switching to these)
 * type: object.bool
 */
static
int lldc__voice_region_deprecated_parse (lldc_voice_region_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_bool(json))
        return -1;

    obj->deprecated = yyjson_get_bool(json);

    return 0;
}
/**
 * optimal Parser
 * true for a single server that is closest to the current user's client
 * type: object.bool
 */
static
int lldc__voice_region_optimal_parse (lldc_voice_region_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_bool(json))
        return -1;

    obj->optimal = yyjson_get_bool(json);

    return 0;
}
/**
 * vip Parser
 * true if this is a vip-only server
 * type: object.bool
 */
static
int lldc__voice_region_vip_parse (lldc_voice_region_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_bool(json))
        return -1;

    obj->vip = yyjson_get_bool(json);

    return 0;
}
/**
 * name Parser
 * name of the region
 * type: object.string
 */
static
int lldc__voice_region_name_parse (lldc_voice_region_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->name = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * id Parser
 * unique ID for the region
 * type: object.string
 */
static
int lldc__voice_region_id_parse (lldc_voice_region_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->id = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * visibility Parser
 * visibility of this connection
 * type: object.int
 */
static
int lldc__connection_visibility_parse (lldc_connection_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->visibility = yyjson_get_int(json);

    return 0;
}
/**
 * show_activity Parser
 * whether activities related to this connection will be shown in presence updates
 * type: object.bool
 */
static
int lldc__connection_show_activity_parse (lldc_connection_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_bool(json))
        return -1;

    obj->show_activity = yyjson_get_bool(json);

    return 0;
}
/**
 * friend_sync Parser
 * whether friend sync is enabled for this connection
 * type: object.bool
 */
static
int lldc__connection_friend_sync_parse (lldc_connection_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_bool(json))
        return -1;

    obj->friend_sync = yyjson_get_bool(json);

    return 0;
}
/**
 * verified Parser
 * whether the connection is verified
 * type: object.bool
 */
static
int lldc__connection_verified_parse (lldc_connection_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_bool(json))
        return -1;

    obj->verified = yyjson_get_bool(json);

    return 0;
}
/**
 * revoked Parser
 * OPTIONAL: whether the connection is revoked
 * type: object.bool
 */
static
int lldc__connection_revoked_parse (lldc_connection_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_bool(json))
        return -1;

    obj->revoked = yyjson_get_bool(json);

    return 0;
}
/**
 * type Parser
 * the service of the connection (twitch, youtube)
 * type: object.string
 */
static
int lldc__connection_type_parse (lldc_connection_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->type = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * name Parser
 * the username of the connection account
 * type: object.string
 */
static
int lldc__connection_name_parse (lldc_connection_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->name = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * id Parser
 * id of the connection account
 * type: object.string
 */
static
int lldc__connection_id_parse (lldc_connection_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->id = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * expires_at Parser
 * OPTIONAL: the expiration date of this invite, returned from the GET /invites/<code> endpoint when with_expiration is true
 * type: object.timestamp
 */
static
int lldc__invite_expires_at_parse (lldc_invite_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
    {
        obj->expires_at = NAN;
        return -1;
    }

    obj->expires_at = lldc_date_parse(yyjson_get_str(json));

    return 0;
}
/**
 * approximate_member_count Parser
 * OPTIONAL: approximate count of total members, returned from the GET /invites/<code> endpoint when with_counts is true
 * type: object.int
 */
static
int lldc__invite_approximate_member_count_parse (lldc_invite_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->approximate_member_count = yyjson_get_int(json);

    return 0;
}
/**
 * approximate_presence_count Parser
 * OPTIONAL: approximate count of online members, returned from the GET /invites/<code> endpoint when with_counts is true
 * type: object.int
 */
static
int lldc__invite_approximate_presence_count_parse (lldc_invite_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->approximate_presence_count = yyjson_get_int(json);

    return 0;
}
/**
 * target_type Parser
 * OPTIONAL: the type of target for this voice channel invite
 * type: object.int
 */
static
int lldc__invite_target_type_parse (lldc_invite_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->target_type = yyjson_get_int(json);

    return 0;
}
/**
 * code Parser
 * the invite code (unique ID)
 * type: object.string
 */
static
int lldc__invite_code_parse (lldc_invite_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->code = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * created_at Parser
 * when this invite was created
 * type: object.timestamp
 */
static
int lldc__invite_metadata_created_at_parse (lldc_invite_metadata_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
    {
        obj->created_at = NAN;
        return -1;
    }

    obj->created_at = lldc_date_parse(yyjson_get_str(json));

    return 0;
}
/**
 * temporary Parser
 * whether this invite only grants temporary membership
 * type: object.bool
 */
static
int lldc__invite_metadata_temporary_parse (lldc_invite_metadata_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_bool(json))
        return -1;

    obj->temporary = yyjson_get_bool(json);

    return 0;
}
/**
 * max_age Parser
 * duration (in seconds) after which the invite expires
 * type: object.int
 */
static
int lldc__invite_metadata_max_age_parse (lldc_invite_metadata_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->max_age = yyjson_get_int(json);

    return 0;
}
/**
 * max_uses Parser
 * max number of times this invite can be used
 * type: object.int
 */
static
int lldc__invite_metadata_max_uses_parse (lldc_invite_metadata_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->max_uses = yyjson_get_int(json);

    return 0;
}
/**
 * uses Parser
 * number of times this invite has been used
 * type: object.int
 */
static
int lldc__invite_metadata_uses_parse (lldc_invite_metadata_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->uses = yyjson_get_int(json);

    return 0;
}
/**
 * topic Parser
 * the topic of the Stage instance (1-120 characters)
 * type: object.string
 */
static
int lldc__invite_stage_instance_topic_parse (lldc_invite_stage_instance_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->topic = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * speaker_count Parser
 * the number of users speaking in the Stage
 * type: object.int
 */
static
int lldc__invite_stage_instance_speaker_count_parse (lldc_invite_stage_instance_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->speaker_count = yyjson_get_int(json);

    return 0;
}
/**
 * participant_count Parser
 * the number of users in the Stage
 * type: object.int
 */
static
int lldc__invite_stage_instance_participant_count_parse (lldc_invite_stage_instance_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->participant_count = yyjson_get_int(json);

    return 0;
}
/**
 * is_dirty Parser
 * OPTIONAL: whether the template has unsynced changes
 * type: object.bool
 */
static
int lldc__guild_template_is_dirty_parse (lldc_guild_template_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_bool(json))
        return -1;

    obj->is_dirty = yyjson_get_bool(json);

    return 0;
}
/**
 * source_guild_id Parser
 * the ID of the guild this template is based on
 * type: object.snowflake
 */
static
int lldc__guild_template_source_guild_id_parse (lldc_guild_template_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->source_guild_id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * updated_at Parser
 * when this template was last synced to the source guild
 * type: object.timestamp
 */
static
int lldc__guild_template_updated_at_parse (lldc_guild_template_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
    {
        obj->updated_at = NAN;
        return -1;
    }

    obj->updated_at = lldc_date_parse(yyjson_get_str(json));

    return 0;
}
/**
 * created_at Parser
 * when this template was created
 * type: object.timestamp
 */
static
int lldc__guild_template_created_at_parse (lldc_guild_template_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
    {
        obj->created_at = NAN;
        return -1;
    }

    obj->created_at = lldc_date_parse(yyjson_get_str(json));

    return 0;
}
/**
 * creator_id Parser
 * the ID of the user who created the template
 * type: object.snowflake
 */
static
int lldc__guild_template_creator_id_parse (lldc_guild_template_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->creator_id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * usage_count Parser
 * number of times this template has been used
 * type: object.int
 */
static
int lldc__guild_template_usage_count_parse (lldc_guild_template_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->usage_count = yyjson_get_int(json);

    return 0;
}
/**
 * description Parser
 * OPTIONAL: the description for the template
 * type: object.string
 */
static
int lldc__guild_template_description_parse (lldc_guild_template_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->description = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * name Parser
 * template name
 * type: object.string
 */
static
int lldc__guild_template_name_parse (lldc_guild_template_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->name = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * code Parser
 * the template code (unique ID)
 * type: object.string
 */
static
int lldc__guild_template_code_parse (lldc_guild_template_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->code = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * nsfw_level Parser
 * guild NSFW level
 * type: object.int
 */
static
int lldc__guild_nsfw_level_parse (lldc_guild_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->nsfw_level = yyjson_get_int(json);

    return 0;
}
/**
 * approximate_presence_count Parser
 * OPTIONAL: approximate number of non-offline members in this guild, returned from the GET /guilds/<id> endpoint when with_counts is true
 * type: object.int
 */
static
int lldc__guild_approximate_presence_count_parse (lldc_guild_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->approximate_presence_count = yyjson_get_int(json);

    return 0;
}
/**
 * approximate_member_count Parser
 * OPTIONAL: approximate number of members in this guild, returned from the GET /guilds/<id> endpoint when with_counts is true
 * type: object.int
 */
static
int lldc__guild_approximate_member_count_parse (lldc_guild_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->approximate_member_count = yyjson_get_int(json);

    return 0;
}
/**
 * max_video_channel_users Parser
 * OPTIONAL: the maximum amount of users in a video channel
 * type: object.int
 */
static
int lldc__guild_max_video_channel_users_parse (lldc_guild_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->max_video_channel_users = yyjson_get_int(json);

    return 0;
}
/**
 * public_updates_channel_id Parser
 * OPTIONAL: the id of the channel where admins and moderators of Community guilds receive notices from Discord
 * type: object.snowflake
 */
static
int lldc__guild_public_updates_channel_id_parse (lldc_guild_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->public_updates_channel_id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * preferred_locale Parser
 * the preferred locale of a Community guild; used in server discovery and notices from Discord; defaults to "en-US"
 * type: object.string
 */
static
int lldc__guild_preferred_locale_parse (lldc_guild_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->preferred_locale = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * premium_subscription_count Parser
 * OPTIONAL: the number of boosts this guild currently has
 * type: object.int
 */
static
int lldc__guild_premium_subscription_count_parse (lldc_guild_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->premium_subscription_count = yyjson_get_int(json);

    return 0;
}
/**
 * premium_tier Parser
 * premium tier (Server Boost level)
 * type: object.int
 */
static
int lldc__guild_premium_tier_parse (lldc_guild_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->premium_tier = yyjson_get_int(json);

    return 0;
}
/**
 * banner Parser
 * OPTIONAL: banner hash
 * type: object.string
 */
static
int lldc__guild_banner_parse (lldc_guild_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->banner = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * description Parser
 * OPTIONAL: the description of a Community guild
 * type: object.string
 */
static
int lldc__guild_description_parse (lldc_guild_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->description = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * vanity_url_code Parser
 * OPTIONAL: the vanity url code for the guild
 * type: object.string
 */
static
int lldc__guild_vanity_url_code_parse (lldc_guild_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->vanity_url_code = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * max_members Parser
 * OPTIONAL: the maximum number of members for the guild
 * type: object.int
 */
static
int lldc__guild_max_members_parse (lldc_guild_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->max_members = yyjson_get_int(json);

    return 0;
}
/**
 * max_presences Parser
 * OPTIONAL: the maximum number of presences for the guild (null is always returned, apart from the largest of guilds)
 * type: object.int
 */
static
int lldc__guild_max_presences_parse (lldc_guild_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->max_presences = yyjson_get_int(json);

    return 0;
}
/**
 * member_count Parser
 * OPTIONAL: total number of members in this guild
 * type: object.int
 */
static
int lldc__guild_member_count_parse (lldc_guild_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->member_count = yyjson_get_int(json);

    return 0;
}
/**
 * unavailable Parser
 * OPTIONAL: true if this guild is unavailable due to an outage
 * type: object.bool
 */
static
int lldc__guild_unavailable_parse (lldc_guild_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_bool(json))
        return -1;

    obj->unavailable = yyjson_get_bool(json);

    return 0;
}
/**
 * large Parser
 * OPTIONAL: true if this is considered a large guild
 * type: object.bool
 */
static
int lldc__guild_large_parse (lldc_guild_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_bool(json))
        return -1;

    obj->large = yyjson_get_bool(json);

    return 0;
}
/**
 * joined_at Parser
 * OPTIONAL: when this guild was joined at
 * type: object.timestamp
 */
static
int lldc__guild_joined_at_parse (lldc_guild_t *obj, yyjson_val *json) 
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
 * rules_channel_id Parser
 * OPTIONAL: the id of the channel where Community guilds can display rules and/or guidelines
 * type: object.snowflake
 */
static
int lldc__guild_rules_channel_id_parse (lldc_guild_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->rules_channel_id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * system_channel_flags Parser
 * system channel flags
 * type: object.int
 */
static
int lldc__guild_system_channel_flags_parse (lldc_guild_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->system_channel_flags = yyjson_get_int(json);

    return 0;
}
/**
 * system_channel_id Parser
 * OPTIONAL: the id of the channel where guild notices such as welcome messages and boost events are posted
 * type: object.snowflake
 */
static
int lldc__guild_system_channel_id_parse (lldc_guild_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->system_channel_id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * application_id Parser
 * OPTIONAL: application id of the guild creator if it is bot-created
 * type: object.snowflake
 */
static
int lldc__guild_application_id_parse (lldc_guild_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->application_id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * mfa_level Parser
 * required MFA level for the guild
 * type: object.int
 */
static
int lldc__guild_mfa_level_parse (lldc_guild_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->mfa_level = yyjson_get_int(json);

    return 0;
}
/**
 * explicit_content_filter Parser
 * explicit content filter level
 * type: object.int
 */
static
int lldc__guild_explicit_content_filter_parse (lldc_guild_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->explicit_content_filter = yyjson_get_int(json);

    return 0;
}
/**
 * default_message_notifications Parser
 * default message notifications level
 * type: object.int
 */
static
int lldc__guild_default_message_notifications_parse (lldc_guild_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->default_message_notifications = yyjson_get_int(json);

    return 0;
}
/**
 * verification_level Parser
 * verification level required for the guild
 * type: object.int
 */
static
int lldc__guild_verification_level_parse (lldc_guild_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->verification_level = yyjson_get_int(json);

    return 0;
}
/**
 * widget_channel_id Parser
 * OPTIONAL: the channel id that the widget will generate an invite to, or null if set to no invite
 * type: object.snowflake
 */
static
int lldc__guild_widget_channel_id_parse (lldc_guild_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->widget_channel_id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * widget_enabled Parser
 * OPTIONAL: true if the server widget is enabled
 * type: object.bool
 */
static
int lldc__guild_widget_enabled_parse (lldc_guild_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_bool(json))
        return -1;

    obj->widget_enabled = yyjson_get_bool(json);

    return 0;
}
/**
 * afk_timeout Parser
 * afk timeout in seconds
 * type: object.int
 */
static
int lldc__guild_afk_timeout_parse (lldc_guild_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->afk_timeout = yyjson_get_int(json);

    return 0;
}
/**
 * afk_channel_id Parser
 * OPTIONAL: id of afk channel
 * type: object.snowflake
 */
static
int lldc__guild_afk_channel_id_parse (lldc_guild_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->afk_channel_id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * region Parser
 * OPTIONAL: voice region id for the guild (deprecated)
 * type: object.string
 */
static
int lldc__guild_region_parse (lldc_guild_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->region = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * permissions Parser
 * OPTIONAL: total permissions for the user in the guild (excludes overwrites)
 * type: object.touint
 */
static
int lldc__guild_permissions_parse (lldc_guild_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->permissions = (uint64_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * owner_id Parser
 * id of owner
 * type: object.snowflake
 */
static
int lldc__guild_owner_id_parse (lldc_guild_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->owner_id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * owner Parser
 * OPTIONAL: true if the user is the owner of the guild
 * type: object.bool
 */
static
int lldc__guild_owner_parse (lldc_guild_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_bool(json))
        return -1;

    obj->owner = yyjson_get_bool(json);

    return 0;
}
/**
 * discovery_splash Parser
 * OPTIONAL: discovery splash hash; only present for guilds with the "DISCOVERABLE" feature
 * type: object.string
 */
static
int lldc__guild_discovery_splash_parse (lldc_guild_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->discovery_splash = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * splash Parser
 * OPTIONAL: splash hash
 * type: object.string
 */
static
int lldc__guild_splash_parse (lldc_guild_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->splash = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * icon_hash Parser
 * OPTIONAL: icon hash, returned when in the template object
 * type: object.string
 */
static
int lldc__guild_icon_hash_parse (lldc_guild_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->icon_hash = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * icon Parser
 * OPTIONAL: icon hash
 * type: object.string
 */
static
int lldc__guild_icon_parse (lldc_guild_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->icon = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * name Parser
 * guild name (2-100 characters, excluding trailing and leading whitespace)
 * type: object.string
 */
static
int lldc__guild_name_parse (lldc_guild_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->name = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * id Parser
 * guild id
 * type: object.snowflake
 */
static
int lldc__guild_id_parse (lldc_guild_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * reason Parser
 * OPTIONAL: the reason for the ban
 * type: object.string
 */
static
int lldc__ban_reason_parse (lldc_ban_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->reason = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * enabled Parser
 * is this integration enabled
 * type: object.bool
 */
static
int lldc__partial_integration_enabled_parse (lldc_partial_integration_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_bool(json))
        return -1;

    obj->enabled = yyjson_get_bool(json);

    return 0;
}
/**
 * type Parser
 * integration type (twitch, youtube, or discord)
 * type: object.string
 */
static
int lldc__partial_integration_type_parse (lldc_partial_integration_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->type = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * name Parser
 * integration name
 * type: object.string
 */
static
int lldc__partial_integration_name_parse (lldc_partial_integration_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->name = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * id Parser
 * integration id
 * type: object.snowflake
 */
static
int lldc__partial_integration_id_parse (lldc_partial_integration_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * revoked Parser
 * OPTIONAL: has this integration been revoked
 * type: object.bool
 */
static
int lldc__integration_revoked_parse (lldc_integration_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_bool(json))
        return -1;

    obj->revoked = yyjson_get_bool(json);

    return 0;
}
/**
 * subscriber_count Parser
 * OPTIONAL: how many subscribers this integration has
 * type: object.int
 */
static
int lldc__integration_subscriber_count_parse (lldc_integration_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->subscriber_count = yyjson_get_int(json);

    return 0;
}
/**
 * synced_at Parser
 * OPTIONAL: when this integration was last synced
 * type: object.timestamp
 */
static
int lldc__integration_synced_at_parse (lldc_integration_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
    {
        obj->synced_at = NAN;
        return -1;
    }

    obj->synced_at = lldc_date_parse(yyjson_get_str(json));

    return 0;
}
/**
 * expire_grace_period Parser
 * OPTIONAL: the grace period (in days) before expiring subscribers
 * type: object.int
 */
static
int lldc__integration_expire_grace_period_parse (lldc_integration_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->expire_grace_period = yyjson_get_int(json);

    return 0;
}
/**
 * expire_behavior Parser
 * OPTIONAL: the behavior of expiring subscribers
 * type: object.int
 */
static
int lldc__integration_expire_behavior_parse (lldc_integration_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->expire_behavior = yyjson_get_int(json);

    return 0;
}
/**
 * enable_emoticons Parser
 * OPTIONAL: whether emoticons should be synced for this integration (twitch only currently)
 * type: object.bool
 */
static
int lldc__integration_enable_emoticons_parse (lldc_integration_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_bool(json))
        return -1;

    obj->enable_emoticons = yyjson_get_bool(json);

    return 0;
}
/**
 * role_id Parser
 * OPTIONAL: id that this integration uses for "subscribers"
 * type: object.snowflake
 */
static
int lldc__integration_role_id_parse (lldc_integration_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->role_id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * syncing Parser
 * OPTIONAL: is this integration syncing
 * type: object.bool
 */
static
int lldc__integration_syncing_parse (lldc_integration_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_bool(json))
        return -1;

    obj->syncing = yyjson_get_bool(json);

    return 0;
}
/**
 * enabled Parser
 * is this integration enabled
 * type: object.bool
 */
static
int lldc__integration_enabled_parse (lldc_integration_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_bool(json))
        return -1;

    obj->enabled = yyjson_get_bool(json);

    return 0;
}
/**
 * type Parser
 * integration type (twitch, youtube, or discord)
 * type: object.string
 */
static
int lldc__integration_type_parse (lldc_integration_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->type = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * name Parser
 * integration name
 * type: object.string
 */
static
int lldc__integration_name_parse (lldc_integration_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->name = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * id Parser
 * integration id
 * type: object.snowflake
 */
static
int lldc__integration_id_parse (lldc_integration_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * summary Parser
 * the summary of the app
 * type: object.string
 */
static
int lldc__integration_application_summary_parse (lldc_integration_application_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->summary = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * description Parser
 * the description of the app
 * type: object.string
 */
static
int lldc__integration_application_description_parse (lldc_integration_application_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->description = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * icon Parser
 * OPTIONAL: the icon hash of the app
 * type: object.string
 */
static
int lldc__integration_application_icon_parse (lldc_integration_application_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->icon = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * name Parser
 * the name of the app
 * type: object.string
 */
static
int lldc__integration_application_name_parse (lldc_integration_application_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->name = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * id Parser
 * the id of the app
 * type: object.snowflake
 */
static
int lldc__integration_application_id_parse (lldc_integration_application_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * name Parser
 * name of the account
 * type: object.string
 */
static
int lldc__integration_account_name_parse (lldc_integration_account_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->name = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * id Parser
 * id of the account
 * type: object.string
 */
static
int lldc__integration_account_id_parse (lldc_integration_account_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->id = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * description Parser
 * OPTIONAL: the description for the guild, if the guild is discoverable
 * type: object.string
 */
static
int lldc__guild_preview_description_parse (lldc_guild_preview_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->description = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * approximate_presence_count Parser
 * approximate number of online members in this guild
 * type: object.int
 */
static
int lldc__guild_preview_approximate_presence_count_parse (lldc_guild_preview_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->approximate_presence_count = yyjson_get_int(json);

    return 0;
}
/**
 * approximate_member_count Parser
 * approximate number of members in this guild
 * type: object.int
 */
static
int lldc__guild_preview_approximate_member_count_parse (lldc_guild_preview_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->approximate_member_count = yyjson_get_int(json);

    return 0;
}
/**
 * discovery_splash Parser
 * OPTIONAL: discovery splash hash
 * type: object.string
 */
static
int lldc__guild_preview_discovery_splash_parse (lldc_guild_preview_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->discovery_splash = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * splash Parser
 * OPTIONAL: splash hash
 * type: object.string
 */
static
int lldc__guild_preview_splash_parse (lldc_guild_preview_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->splash = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * icon Parser
 * OPTIONAL: icon hash
 * type: object.string
 */
static
int lldc__guild_preview_icon_parse (lldc_guild_preview_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->icon = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * name Parser
 * guild name (2-100 characters)
 * type: object.string
 */
static
int lldc__guild_preview_name_parse (lldc_guild_preview_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->name = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * id Parser
 * guild id
 * type: object.snowflake
 */
static
int lldc__guild_preview_id_parse (lldc_guild_preview_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * channel_id Parser
 * OPTIONAL: the widget channel id
 * type: object.snowflake
 */
static
int lldc__guilds_widget_channel_id_parse (lldc_guilds_widget_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->channel_id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * enabled Parser
 * whether the widget is enabled
 * type: object.bool
 */
static
int lldc__guilds_widget_enabled_parse (lldc_guilds_widget_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_bool(json))
        return -1;

    obj->enabled = yyjson_get_bool(json);

    return 0;
}
/**
 * description Parser
 * OPTIONAL: the server description shown in the welcome screen
 * type: object.string
 */
static
int lldc__welcome_screen_description_parse (lldc_welcome_screen_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->description = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * emoji_name Parser
 * OPTIONAL: the emoji name if custom, the unicode character if standard, or null if no emoji is set
 * type: object.string
 */
static
int lldc__welcome_screen_channel_emoji_name_parse (lldc_welcome_screen_channel_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->emoji_name = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * emoji_id Parser
 * OPTIONAL: the emoji id, if the emoji is custom
 * type: object.snowflake
 */
static
int lldc__welcome_screen_channel_emoji_id_parse (lldc_welcome_screen_channel_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->emoji_id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * description Parser
 * the description shown for the channel
 * type: object.string
 */
static
int lldc__welcome_screen_channel_description_parse (lldc_welcome_screen_channel_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->description = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * channel_id Parser
 * the channel's id
 * type: object.snowflake
 */
static
int lldc__welcome_screen_channel_channel_id_parse (lldc_welcome_screen_channel_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->channel_id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * discoverable_disabled Parser
 * Whether or not Stage discovery is disabled
 * type: object.bool
 */
static
int lldc__stage_instance_discoverable_disabled_parse (lldc_stage_instance_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_bool(json))
        return -1;

    obj->discoverable_disabled = yyjson_get_bool(json);

    return 0;
}
/**
 * privacy_level Parser
 * The privacy level of the Stage instance
 * type: object.int
 */
static
int lldc__stage_instance_privacy_level_parse (lldc_stage_instance_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->privacy_level = yyjson_get_int(json);

    return 0;
}
/**
 * topic Parser
 * The topic of the Stage instance (1-120 characters)
 * type: object.string
 */
static
int lldc__stage_instance_topic_parse (lldc_stage_instance_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->topic = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * channel_id Parser
 * The id of the associated Stage channel
 * type: object.snowflake
 */
static
int lldc__stage_instance_channel_id_parse (lldc_stage_instance_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->channel_id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * guild_id Parser
 * The guild id of the associated Stage channel
 * type: object.snowflake
 */
static
int lldc__stage_instance_guild_id_parse (lldc_stage_instance_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->guild_id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * id Parser
 * The id of this Stage instance
 * type: object.snowflake
 */
static
int lldc__stage_instance_id_parse (lldc_stage_instance_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * t Parser
 * OPTIONAL: the event name for this payload
 * type: object.string
 */
static
int lldc__gateway_payload_t_parse (lldc_gateway_payload_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->t = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * s Parser
 * OPTIONAL: sequence number, used for resuming sessions and heartbeats
 * type: object.int
 */
static
int lldc__gateway_payload_s_parse (lldc_gateway_payload_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->s = yyjson_get_int(json);

    return 0;
}
/**
 * d Parser
 * OPTIONAL: event data
 * type: object.rawobj
 */
static
int lldc__gateway_payload_d_parse (lldc_gateway_payload_t *obj, yyjson_val *json) 
{
    obj->d = json;

    return 0;
}
/**
 * op Parser
 * opcode for the payload
 * type: object.int
 */
static
int lldc__gateway_payload_op_parse (lldc_gateway_payload_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->op = yyjson_get_int(json);

    return 0;
}
/**
 * status Parser
 * either "idle", "dnd", "online", or "offline"
 * type: object.string
 */
static
int lldc__presence_update_status_parse (lldc_presence_update_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->status = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * guild_id Parser
 * id of the guild
 * type: object.snowflake
 */
static
int lldc__presence_update_guild_id_parse (lldc_presence_update_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->guild_id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * web Parser
 * OPTIONAL: the user's status set for an active web (browser, bot account) application session
 * type: object.string
 */
static
int lldc__client_status_web_parse (lldc_client_status_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->web = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * mobile Parser
 * OPTIONAL: the user's status set for an active mobile (iOS, Android) application session
 * type: object.string
 */
static
int lldc__client_status_mobile_parse (lldc_client_status_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->mobile = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * desktop Parser
 * OPTIONAL: the user's status set for an active desktop (Windows, Linux, Mac) application session
 * type: object.string
 */
static
int lldc__client_status_desktop_parse (lldc_client_status_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->desktop = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * url Parser
 * OPTIONAL: stream url, is validated when type is 1
 * type: object.string
 */
static
int lldc__activity_bot_url_parse (lldc_activity_bot_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->url = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * type Parser
 * activity type
 * type: object.int
 */
static
int lldc__activity_bot_type_parse (lldc_activity_bot_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->type = yyjson_get_int(json);

    return 0;
}
/**
 * name Parser
 * the activity's name
 * type: object.string
 */
static
int lldc__activity_bot_name_parse (lldc_activity_bot_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->name = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * url Parser
 * the url opened when clicking the button (1-512 characters)
 * type: object.string
 */
static
int lldc__activity_buttons_item_url_parse (lldc_activity_buttons_item_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->url = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * label Parser
 * the text shown on the button (1-32 characters)
 * type: object.string
 */
static
int lldc__activity_buttons_item_label_parse (lldc_activity_buttons_item_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->label = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * flags Parser
 * OPTIONAL: activity flags ORd together, describes what the payload includes
 * type: object.int
 */
static
int lldc__activity_flags_parse (lldc_activity_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->flags = yyjson_get_int(json);

    return 0;
}
/**
 * instance Parser
 * OPTIONAL: whether or not the activity is an instanced game session
 * type: object.bool
 */
static
int lldc__activity_instance_parse (lldc_activity_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_bool(json))
        return -1;

    obj->instance = yyjson_get_bool(json);

    return 0;
}
/**
 * state Parser
 * OPTIONAL: the user's current party status
 * type: object.string
 */
static
int lldc__activity_state_parse (lldc_activity_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->state = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * details Parser
 * OPTIONAL: what the player is currently doing
 * type: object.string
 */
static
int lldc__activity_details_parse (lldc_activity_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->details = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * application_id Parser
 * OPTIONAL: application id for the game
 * type: object.snowflake
 */
static
int lldc__activity_application_id_parse (lldc_activity_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->application_id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * created_at Parser
 * unix timestamp (in milliseconds) of when the activity was added to the user's session
 * type: object.uint
 */
static
int lldc__activity_created_at_parse (lldc_activity_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_uint(json))
        return -1;

    obj->created_at = yyjson_get_uint(json);

    return 0;
}
/**
 * url Parser
 * OPTIONAL: stream url, is validated when type is 1
 * type: object.string
 */
static
int lldc__activity_url_parse (lldc_activity_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->url = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * type Parser
 * activity type
 * type: object.int
 */
static
int lldc__activity_type_parse (lldc_activity_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->type = yyjson_get_int(json);

    return 0;
}
/**
 * name Parser
 * the activity's name
 * type: object.string
 */
static
int lldc__activity_name_parse (lldc_activity_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->name = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * match Parser
 * OPTIONAL: the secret for a specific instanced match
 * type: object.string
 */
static
int lldc__activity_secrets_match_parse (lldc_activity_secrets_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->match = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * spectate Parser
 * OPTIONAL: the secret for spectating a game
 * type: object.string
 */
static
int lldc__activity_secrets_spectate_parse (lldc_activity_secrets_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->spectate = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * join Parser
 * OPTIONAL: the secret for joining a party
 * type: object.string
 */
static
int lldc__activity_secrets_join_parse (lldc_activity_secrets_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->join = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * small_text Parser
 * OPTIONAL: text displayed when hovering over the small image of the activity
 * type: object.string
 */
static
int lldc__activity_assets_small_text_parse (lldc_activity_assets_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->small_text = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * small_image Parser
 * OPTIONAL: the id for a small asset of the activity, usually a snowflake
 * type: object.string
 */
static
int lldc__activity_assets_small_image_parse (lldc_activity_assets_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->small_image = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * large_text Parser
 * OPTIONAL: text displayed when hovering over the large image of the activity
 * type: object.string
 */
static
int lldc__activity_assets_large_text_parse (lldc_activity_assets_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->large_text = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * large_image Parser
 * OPTIONAL: the id for a large asset of the activity, usually a snowflake
 * type: object.string
 */
static
int lldc__activity_assets_large_image_parse (lldc_activity_assets_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->large_image = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * id Parser
 * OPTIONAL: the id of the party
 * type: object.string
 */
static
int lldc__activity_party_id_parse (lldc_activity_party_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->id = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * end Parser
 * OPTIONAL: unix time (in milliseconds) of when the activity ends
 * type: object.uint
 */
static
int lldc__activity_timestamps_end_parse (lldc_activity_timestamps_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_uint(json))
        return -1;

    obj->end = yyjson_get_uint(json);

    return 0;
}
/**
 * start Parser
 * OPTIONAL: unix time (in milliseconds) of when the activity started
 * type: object.uint
 */
static
int lldc__activity_timestamps_start_parse (lldc_activity_timestamps_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_uint(json))
        return -1;

    obj->start = yyjson_get_uint(json);

    return 0;
}
/**
 * request_to_speak_timestamp Parser
 * OPTIONAL: the time at which the user requested to speak
 * type: object.timestamp
 */
static
int lldc__voice_state_request_to_speak_timestamp_parse (lldc_voice_state_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
    {
        obj->request_to_speak_timestamp = NAN;
        return -1;
    }

    obj->request_to_speak_timestamp = lldc_date_parse(yyjson_get_str(json));

    return 0;
}
/**
 * suppress Parser
 * whether this user is muted by the current user
 * type: object.bool
 */
static
int lldc__voice_state_suppress_parse (lldc_voice_state_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_bool(json))
        return -1;

    obj->suppress = yyjson_get_bool(json);

    return 0;
}
/**
 * self_video Parser
 * whether this user's camera is enabled
 * type: object.bool
 */
static
int lldc__voice_state_self_video_parse (lldc_voice_state_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_bool(json))
        return -1;

    obj->self_video = yyjson_get_bool(json);

    return 0;
}
/**
 * self_stream Parser
 * OPTIONAL: whether this user is streaming using "Go Live"
 * type: object.bool
 */
static
int lldc__voice_state_self_stream_parse (lldc_voice_state_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_bool(json))
        return -1;

    obj->self_stream = yyjson_get_bool(json);

    return 0;
}
/**
 * self_mute Parser
 * whether this user is locally muted
 * type: object.bool
 */
static
int lldc__voice_state_self_mute_parse (lldc_voice_state_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_bool(json))
        return -1;

    obj->self_mute = yyjson_get_bool(json);

    return 0;
}
/**
 * self_deaf Parser
 * whether this user is locally deafened
 * type: object.bool
 */
static
int lldc__voice_state_self_deaf_parse (lldc_voice_state_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_bool(json))
        return -1;

    obj->self_deaf = yyjson_get_bool(json);

    return 0;
}
/**
 * mute Parser
 * whether this user is muted by the server
 * type: object.bool
 */
static
int lldc__voice_state_mute_parse (lldc_voice_state_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_bool(json))
        return -1;

    obj->mute = yyjson_get_bool(json);

    return 0;
}
/**
 * deaf Parser
 * whether this user is deafened by the server
 * type: object.bool
 */
static
int lldc__voice_state_deaf_parse (lldc_voice_state_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_bool(json))
        return -1;

    obj->deaf = yyjson_get_bool(json);

    return 0;
}
/**
 * session_id Parser
 * the session id for this voice state
 * type: object.string
 */
static
int lldc__voice_state_session_id_parse (lldc_voice_state_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->session_id = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * user_id Parser
 * the user id this voice state is for
 * type: object.snowflake
 */
static
int lldc__voice_state_user_id_parse (lldc_voice_state_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->user_id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * channel_id Parser
 * OPTIONAL: the channel id this user is connected to
 * type: object.snowflake
 */
static
int lldc__voice_state_channel_id_parse (lldc_voice_state_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->channel_id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * guild_id Parser
 * OPTIONAL: the guild id this voice state is for
 * type: object.snowflake
 */
static
int lldc__voice_state_guild_id_parse (lldc_voice_state_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->guild_id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
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

    obj->rtc_region = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

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

    obj->icon = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

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

    obj->topic = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

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

    obj->name = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

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
 * webhook_id Parser
 * created target webhook id
 * type: object.snowflake
 */
static
int lldc__followed_channel_webhook_id_parse (lldc_followed_channel_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->webhook_id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * channel_id Parser
 * source channel id
 * type: object.snowflake
 */
static
int lldc__followed_channel_channel_id_parse (lldc_followed_channel_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->channel_id = (snowflake_t)atoll(yyjson_get_str(json));

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

    obj->content = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

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

    obj->name = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

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

    obj->party_id = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

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
 * banner_asset_id Parser
 * id of the sticker pack's banner image
 * type: object.snowflake
 */
static
int lldc__sticker_packs_banner_asset_id_parse (lldc_sticker_packs_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->banner_asset_id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * description Parser
 * description of the sticker pack
 * type: object.string
 */
static
int lldc__sticker_packs_description_parse (lldc_sticker_packs_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->description = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * cover_sticker_id Parser
 * OPTIONAL: id of a sticker in the pack which is shown as the pack's icon
 * type: object.snowflake
 */
static
int lldc__sticker_packs_cover_sticker_id_parse (lldc_sticker_packs_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->cover_sticker_id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * sku_id Parser
 * id of the pack's SKU
 * type: object.snowflake
 */
static
int lldc__sticker_packs_sku_id_parse (lldc_sticker_packs_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->sku_id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * name Parser
 * name of the sticker pack
 * type: object.string
 */
static
int lldc__sticker_packs_name_parse (lldc_sticker_packs_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->name = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * id Parser
 * id of the sticker pack
 * type: object.snowflake
 */
static
int lldc__sticker_packs_id_parse (lldc_sticker_packs_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->id = (snowflake_t)atoll(yyjson_get_str(json));

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

    obj->name = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

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
 * sort_value Parser
 * OPTIONAL: the standard sticker's sort order within its pack
 * type: object.int
 */
static
int lldc__sticker_sort_value_parse (lldc_sticker_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->sort_value = yyjson_get_int(json);

    return 0;
}
/**
 * guild_id Parser
 * OPTIONAL: id of the guild that owns this sticker
 * type: object.snowflake
 */
static
int lldc__sticker_guild_id_parse (lldc_sticker_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->guild_id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * available Parser
 * OPTIONAL: whether this guild sticker can be used, may be false due to loss of Server Boosts
 * type: object.bool
 */
static
int lldc__sticker_available_parse (lldc_sticker_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_bool(json))
        return -1;

    obj->available = yyjson_get_bool(json);

    return 0;
}
/**
 * format_type Parser
 * type of sticker format
 * type: object.int
 */
static
int lldc__sticker_format_type_parse (lldc_sticker_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->format_type = yyjson_get_int(json);

    return 0;
}
/**
 * type Parser
 * type of sticker
 * type: object.int
 */
static
int lldc__sticker_type_parse (lldc_sticker_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->type = yyjson_get_int(json);

    return 0;
}
/**
 * tags Parser
 * for guild stickers, the Discord name of a unicode emoji representing the sticker's expression. for standard stickers, a comma-separated list of related expressions.
 * type: object.string
 */
static
int lldc__sticker_tags_parse (lldc_sticker_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->tags = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * description Parser
 * OPTIONAL: description of the sticker
 * type: object.string
 */
static
int lldc__sticker_description_parse (lldc_sticker_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->description = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * name Parser
 * name of the sticker
 * type: object.string
 */
static
int lldc__sticker_name_parse (lldc_sticker_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->name = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * pack_id Parser
 * OPTIONAL: for standard stickers, id of the pack the sticker is from
 * type: object.snowflake
 */
static
int lldc__sticker_pack_id_parse (lldc_sticker_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->pack_id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * id Parser
 * id of the sticker
 * type: object.snowflake
 */
static
int lldc__sticker_id_parse (lldc_sticker_t *obj, yyjson_val *json) 
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

    obj->placeholder = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

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

    obj->url = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

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

    obj->label = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

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

    obj->custom_id = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

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

    obj->description = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

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

    obj->value = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

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

    obj->label = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

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

    obj->name = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

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

    obj->url = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

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

    obj->description = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

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

    obj->type = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

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

    obj->title = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

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

    obj->value = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

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

    obj->name = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

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

    obj->proxy_url = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

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

    obj->url = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

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

    obj->proxy_url = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

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

    obj->url = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

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

    obj->url = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

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

    obj->name = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

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

    obj->proxy_url = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

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

    obj->url = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

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

    obj->proxy_icon_url = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

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

    obj->icon_url = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

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

    obj->text = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

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

    obj->proxy_icon_url = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

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

    obj->icon_url = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

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

    obj->url = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

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

    obj->name = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

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

    obj->name = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

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

    obj->proxy_url = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

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

    obj->url = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

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

    obj->content_type = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

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

    obj->filename = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

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
 * mentionable Parser
 * whether this role is mentionable
 * type: object.bool
 */
static
int lldc__role_mentionable_parse (lldc_role_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_bool(json))
        return -1;

    obj->mentionable = yyjson_get_bool(json);

    return 0;
}
/**
 * managed Parser
 * whether this role is managed by an integration
 * type: object.bool
 */
static
int lldc__role_managed_parse (lldc_role_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_bool(json))
        return -1;

    obj->managed = yyjson_get_bool(json);

    return 0;
}
/**
 * permissions Parser
 * permission bit set
 * type: object.touint
 */
static
int lldc__role_permissions_parse (lldc_role_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->permissions = (uint64_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * position Parser
 * position of this role
 * type: object.int
 */
static
int lldc__role_position_parse (lldc_role_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->position = yyjson_get_int(json);

    return 0;
}
/**
 * hoist Parser
 * if this role is pinned in the user listing
 * type: object.bool
 */
static
int lldc__role_hoist_parse (lldc_role_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_bool(json))
        return -1;

    obj->hoist = yyjson_get_bool(json);

    return 0;
}
/**
 * color Parser
 * integer representation of hexadecimal color code
 * type: object.int
 */
static
int lldc__role_color_parse (lldc_role_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->color = yyjson_get_int(json);

    return 0;
}
/**
 * name Parser
 * role name
 * type: object.string
 */
static
int lldc__role_name_parse (lldc_role_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->name = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * id Parser
 * role id
 * type: object.snowflake
 */
static
int lldc__role_id_parse (lldc_role_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * integration_id Parser
 * OPTIONAL: the id of the integration this role belongs to
 * type: object.snowflake
 */
static
int lldc__role_tags_integration_id_parse (lldc_role_tags_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->integration_id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * bot_id Parser
 * OPTIONAL: the id of the bot this role belongs to
 * type: object.snowflake
 */
static
int lldc__role_tags_bot_id_parse (lldc_role_tags_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->bot_id = (snowflake_t)atoll(yyjson_get_str(json));

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
 * type: object.touint
 */
static
int lldc__partial_guild_member_permissions_parse (lldc_partial_guild_member_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->permissions = (uint64_t)atoll(yyjson_get_str(json));

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

    obj->nick = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * permissions Parser
 * OPTIONAL: total permissions of the member in the channel, including overwrites, returned when in the interaction object
 * type: object.touint
 */
static
int lldc__guild_member_permissions_parse (lldc_guild_member_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->permissions = (uint64_t)atoll(yyjson_get_str(json));

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

    obj->nick = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

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

    obj->type = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

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

    obj->name = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

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

    obj->reason = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

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

    obj->role_name = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

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

    obj->type = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

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

    obj->count = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

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

    obj->members_removed = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

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

    obj->delete_member_days = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

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

    obj->key = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

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

    obj->name = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

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

    obj->id = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

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

    obj->url = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

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

    obj->token = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

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

    obj->avatar = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

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

    obj->name = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

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
 * banner Parser
 * OPTIONAL: banner hash
 * type: object.string
 */
static
int lldc__partial_guild_banner_parse (lldc_partial_guild_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->banner = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * description Parser
 * OPTIONAL: the description of a Community guild
 * type: object.string
 */
static
int lldc__partial_guild_description_parse (lldc_partial_guild_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->description = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * vanity_url_code Parser
 * OPTIONAL: the vanity url code for the guild
 * type: object.string
 */
static
int lldc__partial_guild_vanity_url_code_parse (lldc_partial_guild_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->vanity_url_code = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * verification_level Parser
 * verification level required for the guild
 * type: object.int
 */
static
int lldc__partial_guild_verification_level_parse (lldc_partial_guild_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_int(json))
        return -1;

    obj->verification_level = yyjson_get_int(json);

    return 0;
}
/**
 * discovery_splash Parser
 * OPTIONAL: discovery splash hash; only present for guilds with the "DISCOVERABLE" feature
 * type: object.string
 */
static
int lldc__partial_guild_discovery_splash_parse (lldc_partial_guild_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->discovery_splash = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * splash Parser
 * OPTIONAL: splash hash
 * type: object.string
 */
static
int lldc__partial_guild_splash_parse (lldc_partial_guild_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->splash = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * icon Parser
 * OPTIONAL: icon hash
 * type: object.string
 */
static
int lldc__partial_guild_icon_parse (lldc_partial_guild_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->icon = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * name Parser
 * guild name (2-100 characters, excluding trailing and leading whitespace)
 * type: object.string
 */
static
int lldc__partial_guild_name_parse (lldc_partial_guild_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->name = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * id Parser
 * guild id
 * type: object.snowflake
 */
static
int lldc__partial_guild_id_parse (lldc_partial_guild_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * parent_id Parser
 * OPTIONAL: for guild channels: id of the parent category for a channel (each parent category can contain up to 50 channels), for threads: id of the text channel this thread was created
 * type: object.snowflake
 */
static
int lldc__partial_channel_parent_id_parse (lldc_partial_channel_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->parent_id = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}
/**
 * name Parser
 * OPTIONAL: the name of the channel (1-100 characters)
 * type: object.string
 */
static
int lldc__partial_channel_name_parse (lldc_partial_channel_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->name = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

    return 0;
}
/**
 * type Parser
 * the type of channel
 * type: object.int
 */
static
int lldc__partial_channel_type_parse (lldc_partial_channel_t *obj, yyjson_val *json) 
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
int lldc__partial_channel_id_parse (lldc_partial_channel_t *obj, yyjson_val *json) 
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

    obj->cover_image = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

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

    obj->slug = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

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

    obj->verify_key = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

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

    obj->summary = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

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

    obj->privacy_policy_url = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

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

    obj->terms_of_service_url = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

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

    obj->description = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

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

    obj->icon = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

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

    obj->name = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

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

    obj->name = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

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

    obj->icon = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

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

    obj->locale = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

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

    obj->avatar = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

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

    obj->discriminator = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

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

    obj->username = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

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

    obj->message = lldc_struct_strdup((lldc_struct_obj_t *)obj, yyjson_get_str(json));

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

    static lldc_struct_def_t parser_def[3] = {
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

    lldc_struct_malloc_ledger_t *ledger = obj->_mlog;
    
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
        lldc_struct_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
int lldc_user_parse (cwr_malloc_ctx_t *_mctx, lldc_user_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_struct_def_t parser_def[11] = {
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

    lldc_struct_malloc_ledger_t *ledger = obj->_mlog;
    
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
        lldc_struct_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
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

    obj->items = lldc_struct_malloc((lldc_struct_obj_t *)obj, sizeof(*obj->items) * arr_size);
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

    static lldc_struct_def_t parser_def[3] = {
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

    lldc_struct_malloc_ledger_t *ledger = obj->_mlog;
    
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
        lldc_struct_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
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

    obj->items = lldc_struct_malloc((lldc_struct_obj_t *)obj, sizeof(*obj->items) * arr_size);
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

    static lldc_struct_def_t parser_def[5] = {
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

    lldc_struct_malloc_ledger_t *ledger = obj->_mlog;
    
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
        lldc_struct_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
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
    lldc_struct_string_arr_t *obj = &_obj->rpc_origins;

    obj->_mctx = _obj->_mctx;
    obj->_mlog = _obj->_mlog;
    return lldc_struct_string_arr_parse(obj, json);
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

    static lldc_struct_def_t parser_def[18] = {
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

    lldc_struct_malloc_ledger_t *ledger = obj->_mlog;
    
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
        lldc_struct_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
int lldc_partial_channel_parse (cwr_malloc_ctx_t *_mctx, lldc_partial_channel_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_struct_def_t parser_def[4] = {
        { "id", (int (*)(void *, yyjson_val *))lldc__partial_channel_id_parse },
        { "type", (int (*)(void *, yyjson_val *))lldc__partial_channel_type_parse },
        { "name", (int (*)(void *, yyjson_val *))lldc__partial_channel_name_parse },
        { "parent_id", (int (*)(void *, yyjson_val *))lldc__partial_channel_parent_id_parse }
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

    lldc_struct_malloc_ledger_t *ledger = obj->_mlog;
    
    memset(obj, 0, sizeof(lldc_partial_channel_t));

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
        lldc_struct_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
/**
* Partial Channel Parser
* Partial Channel Objects
* type: object.object
*/
static
int lldc__partial_channel_item_parse (lldc_partial_channel_t *_obj, yyjson_val *json)
{
    return lldc_partial_channel_parse(_obj->_mctx, _obj, json, 1);
}
int lldc_partial_channel_arr_parse (cwr_malloc_ctx_t *_mctx, lldc_partial_channel_arr_t *obj, yyjson_val *json, int has_existing_ledger)
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

    obj->items = lldc_struct_malloc((lldc_struct_obj_t *)obj, sizeof(*obj->items) * arr_size);
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
        lldc__partial_channel_item_parse(&obj->items[idx], val);
    }

    return 0;
}
/**
* features Parser
* enabled guild features
* type: object.array[string]
*/
static
int lldc__partial_guild_features_parse (lldc_partial_guild_t *_obj, yyjson_val *json)
{
    lldc_struct_string_arr_t *obj = &_obj->features;

    obj->_mctx = _obj->_mctx;
    obj->_mlog = _obj->_mlog;
    return lldc_struct_string_arr_parse(obj, json);
}
int lldc_partial_guild_parse (cwr_malloc_ctx_t *_mctx, lldc_partial_guild_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_struct_def_t parser_def[10] = {
        { "id", (int (*)(void *, yyjson_val *))lldc__partial_guild_id_parse },
        { "name", (int (*)(void *, yyjson_val *))lldc__partial_guild_name_parse },
        { "icon", (int (*)(void *, yyjson_val *))lldc__partial_guild_icon_parse },
        { "splash", (int (*)(void *, yyjson_val *))lldc__partial_guild_splash_parse },
        { "discovery_splash", (int (*)(void *, yyjson_val *))lldc__partial_guild_discovery_splash_parse },
        { "verification_level", (int (*)(void *, yyjson_val *))lldc__partial_guild_verification_level_parse },
        { "features", (int (*)(void *, yyjson_val *))lldc__partial_guild_features_parse },
        { "vanity_url_code", (int (*)(void *, yyjson_val *))lldc__partial_guild_vanity_url_code_parse },
        { "description", (int (*)(void *, yyjson_val *))lldc__partial_guild_description_parse },
        { "banner", (int (*)(void *, yyjson_val *))lldc__partial_guild_banner_parse }
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
    LLDC_PARSER_LOAD(10)

    if (!yyjson_is_obj(json))
        return -1;

    lldc_struct_malloc_ledger_t *ledger = obj->_mlog;
    
    memset(obj, 0, sizeof(lldc_partial_guild_t));

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
        lldc_struct_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
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
* OPTIONAL: the guild of the channel that this webhook is following (returned for Channel Follower Webhooks)
* type: object.object
*/
static
int lldc__webhook_source_guild_parse (lldc_webhook_t *_obj, yyjson_val *json)
{
    _obj->source_guild._mlog = _obj->_mlog;
    return lldc_partial_guild_parse(_obj->_mctx, &_obj->source_guild, json, 1);
}
/**
* source_channel Parser
* OPTIONAL: the channel that this webhook is following (returned for Channel Follower Webhooks)
* type: object.object
*/
static
int lldc__webhook_source_channel_parse (lldc_webhook_t *_obj, yyjson_val *json)
{
    _obj->source_channel._mlog = _obj->_mlog;
    return lldc_partial_channel_parse(_obj->_mctx, &_obj->source_channel, json, 1);
}
int lldc_webhook_parse (cwr_malloc_ctx_t *_mctx, lldc_webhook_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_struct_def_t parser_def[12] = {
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

    lldc_struct_malloc_ledger_t *ledger = obj->_mlog;
    
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
        lldc_struct_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
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

    obj->items = lldc_struct_malloc((lldc_struct_obj_t *)obj, sizeof(*obj->items) * arr_size);
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

    static lldc_struct_def_t parser_def[2] = {
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

    lldc_struct_malloc_ledger_t *ledger = obj->_mlog;
    
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
        lldc_struct_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
int lldc_audit_log_changes_parse (cwr_malloc_ctx_t *_mctx, lldc_audit_log_changes_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_struct_def_t parser_def[3] = {
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

    lldc_struct_malloc_ledger_t *ledger = obj->_mlog;
    
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
        lldc_struct_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
int lldc_audit_log_options_parse (cwr_malloc_ctx_t *_mctx, lldc_audit_log_options_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_struct_def_t parser_def[8] = {
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

    lldc_struct_malloc_ledger_t *ledger = obj->_mlog;
    
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
        lldc_struct_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
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

    obj->items = lldc_struct_malloc((lldc_struct_obj_t *)obj, sizeof(*obj->items) * arr_size);
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

    static lldc_struct_def_t parser_def[7] = {
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

    lldc_struct_malloc_ledger_t *ledger = obj->_mlog;
    
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
        lldc_struct_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
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

    static lldc_struct_def_t parser_def[4] = {
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

    lldc_struct_malloc_ledger_t *ledger = obj->_mlog;
    cwr_malloc_ctx_t *mctx = obj->_mctx;
    memset(obj, 0, sizeof(lldc_audit_log_integrations_item_t));

    obj->_mlog = ledger;
    obj->_mctx = mctx;
    yyjson_val *key, *val;
    yyjson_obj_iter iter;
    yyjson_obj_iter_init(json, &iter);
    while ((key = yyjson_obj_iter_next(&iter))) {
        val = yyjson_obj_iter_get_val(key);
        lldc_struct_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
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

    obj->items = lldc_struct_malloc((lldc_struct_obj_t *)obj, sizeof(*obj->items) * arr_size);
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

    obj->items = lldc_struct_malloc((lldc_struct_obj_t *)obj, sizeof(*obj->items) * arr_size);
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

    static lldc_struct_def_t parser_def[4] = {
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

    lldc_struct_malloc_ledger_t *ledger = obj->_mlog;
    
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
        lldc_struct_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
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
    lldc_struct_snowflake_arr_t *obj = &_obj->roles;

    obj->_mctx = _obj->_mctx;
    obj->_mlog = _obj->_mlog;
    return lldc_struct_snowflake_arr_parse(obj, json);
}
int lldc_guild_member_parse (cwr_malloc_ctx_t *_mctx, lldc_guild_member_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_struct_def_t parser_def[9] = {
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

    lldc_struct_malloc_ledger_t *ledger = obj->_mlog;
    
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
        lldc_struct_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
/**
* Guild Member Parser
* Guild Member Objects
* type: object.object
*/
static
int lldc__guild_member_item_parse (lldc_guild_member_t *_obj, yyjson_val *json)
{
    return lldc_guild_member_parse(_obj->_mctx, _obj, json, 1);
}
int lldc_guild_member_arr_parse (cwr_malloc_ctx_t *_mctx, lldc_guild_member_arr_t *obj, yyjson_val *json, int has_existing_ledger)
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

    obj->items = lldc_struct_malloc((lldc_struct_obj_t *)obj, sizeof(*obj->items) * arr_size);
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
        lldc__guild_member_item_parse(&obj->items[idx], val);
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
    lldc_struct_snowflake_arr_t *obj = &_obj->roles;

    obj->_mctx = _obj->_mctx;
    obj->_mlog = _obj->_mlog;
    return lldc_struct_snowflake_arr_parse(obj, json);
}
int lldc_partial_guild_member_parse (cwr_malloc_ctx_t *_mctx, lldc_partial_guild_member_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_struct_def_t parser_def[8] = {
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

    lldc_struct_malloc_ledger_t *ledger = obj->_mlog;
    
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
        lldc_struct_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
/**
* Partial Guild Member Parser
* Partial Guild Member Objects
* type: object.object
*/
static
int lldc__partial_guild_member_item_parse (lldc_partial_guild_member_t *_obj, yyjson_val *json)
{
    return lldc_partial_guild_member_parse(_obj->_mctx, _obj, json, 1);
}
int lldc_partial_guild_member_arr_parse (cwr_malloc_ctx_t *_mctx, lldc_partial_guild_member_arr_t *obj, yyjson_val *json, int has_existing_ledger)
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

    obj->items = lldc_struct_malloc((lldc_struct_obj_t *)obj, sizeof(*obj->items) * arr_size);
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
        lldc__partial_guild_member_item_parse(&obj->items[idx], val);
    }

    return 0;
}
int lldc_channel_overwrite_parse (cwr_malloc_ctx_t *_mctx, lldc_channel_overwrite_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_struct_def_t parser_def[4] = {
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

    lldc_struct_malloc_ledger_t *ledger = obj->_mlog;
    
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
        lldc_struct_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
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

    obj->items = lldc_struct_malloc((lldc_struct_obj_t *)obj, sizeof(*obj->items) * arr_size);
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
int lldc_role_tags_parse (cwr_malloc_ctx_t *_mctx, lldc_role_tags_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_struct_def_t parser_def[2] = {
        { "bot_id", (int (*)(void *, yyjson_val *))lldc__role_tags_bot_id_parse },
        { "integration_id", (int (*)(void *, yyjson_val *))lldc__role_tags_integration_id_parse }
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

    lldc_struct_malloc_ledger_t *ledger = obj->_mlog;
    
    memset(obj, 0, sizeof(lldc_role_tags_t));

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
        lldc_struct_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
/**
* tags Parser
* OPTIONAL: the tags this role has
* type: object.object
*/
static
int lldc__role_tags_parse (lldc_role_t *_obj, yyjson_val *json)
{
    _obj->tags._mlog = _obj->_mlog;
    return lldc_role_tags_parse(_obj->_mctx, &_obj->tags, json, 1);
}
int lldc_role_parse (cwr_malloc_ctx_t *_mctx, lldc_role_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_struct_def_t parser_def[9] = {
        { "id", (int (*)(void *, yyjson_val *))lldc__role_id_parse },
        { "name", (int (*)(void *, yyjson_val *))lldc__role_name_parse },
        { "color", (int (*)(void *, yyjson_val *))lldc__role_color_parse },
        { "hoist", (int (*)(void *, yyjson_val *))lldc__role_hoist_parse },
        { "position", (int (*)(void *, yyjson_val *))lldc__role_position_parse },
        { "permissions", (int (*)(void *, yyjson_val *))lldc__role_permissions_parse },
        { "managed", (int (*)(void *, yyjson_val *))lldc__role_managed_parse },
        { "mentionable", (int (*)(void *, yyjson_val *))lldc__role_mentionable_parse },
        { "tags", (int (*)(void *, yyjson_val *))lldc__role_tags_parse }
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

    lldc_struct_malloc_ledger_t *ledger = obj->_mlog;
    
    memset(obj, 0, sizeof(lldc_role_t));

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
        lldc_struct_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
/**
* Role Parser
* Role Objects
* type: object.object
*/
static
int lldc__role_item_parse (lldc_role_t *_obj, yyjson_val *json)
{
    return lldc_role_parse(_obj->_mctx, _obj, json, 1);
}
int lldc_role_arr_parse (cwr_malloc_ctx_t *_mctx, lldc_role_arr_t *obj, yyjson_val *json, int has_existing_ledger)
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

    obj->items = lldc_struct_malloc((lldc_struct_obj_t *)obj, sizeof(*obj->items) * arr_size);
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
        lldc__role_item_parse(&obj->items[idx], val);
    }

    return 0;
}
int lldc_thread_metadata_parse (cwr_malloc_ctx_t *_mctx, lldc_thread_metadata_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_struct_def_t parser_def[4] = {
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

    lldc_struct_malloc_ledger_t *ledger = obj->_mlog;
    
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
        lldc_struct_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
int lldc_thread_member_parse (cwr_malloc_ctx_t *_mctx, lldc_thread_member_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_struct_def_t parser_def[4] = {
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

    lldc_struct_malloc_ledger_t *ledger = obj->_mlog;
    
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
        lldc_struct_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
int lldc_attachment_parse (cwr_malloc_ctx_t *_mctx, lldc_attachment_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_struct_def_t parser_def[8] = {
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

    lldc_struct_malloc_ledger_t *ledger = obj->_mlog;
    
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
        lldc_struct_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
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

    obj->items = lldc_struct_malloc((lldc_struct_obj_t *)obj, sizeof(*obj->items) * arr_size);
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

    static lldc_struct_def_t parser_def[4] = {
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

    lldc_struct_malloc_ledger_t *ledger = obj->_mlog;
    
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
        lldc_struct_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
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

    obj->items = lldc_struct_malloc((lldc_struct_obj_t *)obj, sizeof(*obj->items) * arr_size);
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

    static lldc_struct_def_t parser_def[4] = {
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

    lldc_struct_malloc_ledger_t *ledger = obj->_mlog;
    
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
        lldc_struct_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
int lldc_embed_footer_parse (cwr_malloc_ctx_t *_mctx, lldc_embed_footer_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_struct_def_t parser_def[3] = {
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

    lldc_struct_malloc_ledger_t *ledger = obj->_mlog;
    
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
        lldc_struct_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
int lldc_embed_image_parse (cwr_malloc_ctx_t *_mctx, lldc_embed_image_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_struct_def_t parser_def[4] = {
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

    lldc_struct_malloc_ledger_t *ledger = obj->_mlog;
    
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
        lldc_struct_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
int lldc_embed_provider_parse (cwr_malloc_ctx_t *_mctx, lldc_embed_provider_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_struct_def_t parser_def[2] = {
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

    lldc_struct_malloc_ledger_t *ledger = obj->_mlog;
    
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
        lldc_struct_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
int lldc_embed_thumbnail_parse (cwr_malloc_ctx_t *_mctx, lldc_embed_thumbnail_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_struct_def_t parser_def[4] = {
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

    lldc_struct_malloc_ledger_t *ledger = obj->_mlog;
    
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
        lldc_struct_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
int lldc_embed_video_parse (cwr_malloc_ctx_t *_mctx, lldc_embed_video_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_struct_def_t parser_def[4] = {
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

    lldc_struct_malloc_ledger_t *ledger = obj->_mlog;
    
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
        lldc_struct_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
int lldc_embed_field_parse (cwr_malloc_ctx_t *_mctx, lldc_embed_field_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_struct_def_t parser_def[3] = {
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

    lldc_struct_malloc_ledger_t *ledger = obj->_mlog;
    
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
        lldc_struct_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
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

    obj->items = lldc_struct_malloc((lldc_struct_obj_t *)obj, sizeof(*obj->items) * arr_size);
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

    static lldc_struct_def_t parser_def[13] = {
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

    lldc_struct_malloc_ledger_t *ledger = obj->_mlog;
    
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
        lldc_struct_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
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

    obj->items = lldc_struct_malloc((lldc_struct_obj_t *)obj, sizeof(*obj->items) * arr_size);
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
    lldc_struct_snowflake_arr_t *obj = &_obj->roles;

    obj->_mctx = _obj->_mctx;
    obj->_mlog = _obj->_mlog;
    return lldc_struct_snowflake_arr_parse(obj, json);
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

    static lldc_struct_def_t parser_def[8] = {
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

    lldc_struct_malloc_ledger_t *ledger = obj->_mlog;
    
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
        lldc_struct_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
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

    obj->items = lldc_struct_malloc((lldc_struct_obj_t *)obj, sizeof(*obj->items) * arr_size);
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

    static lldc_struct_def_t parser_def[3] = {
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

    lldc_struct_malloc_ledger_t *ledger = obj->_mlog;
    
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
        lldc_struct_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
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

    obj->items = lldc_struct_malloc((lldc_struct_obj_t *)obj, sizeof(*obj->items) * arr_size);
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

    static lldc_struct_def_t parser_def[5] = {
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

    lldc_struct_malloc_ledger_t *ledger = obj->_mlog;
    
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
        lldc_struct_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
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

    obj->items = lldc_struct_malloc((lldc_struct_obj_t *)obj, sizeof(*obj->items) * arr_size);
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

    obj->items = lldc_struct_malloc((lldc_struct_obj_t *)obj, sizeof(*obj->items) * arr_size);
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

    static lldc_struct_def_t parser_def[12] = {
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

    lldc_struct_malloc_ledger_t *ledger = obj->_mlog;
    
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
        lldc_struct_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
/**
* user Parser
* OPTIONAL: the user that uploaded the guild sticker
* type: object.object
*/
static
int lldc__sticker_user_parse (lldc_sticker_t *_obj, yyjson_val *json)
{
    _obj->user._mlog = _obj->_mlog;
    return lldc_user_parse(_obj->_mctx, &_obj->user, json, 1);
}
int lldc_sticker_parse (cwr_malloc_ctx_t *_mctx, lldc_sticker_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_struct_def_t parser_def[11] = {
        { "id", (int (*)(void *, yyjson_val *))lldc__sticker_id_parse },
        { "pack_id", (int (*)(void *, yyjson_val *))lldc__sticker_pack_id_parse },
        { "name", (int (*)(void *, yyjson_val *))lldc__sticker_name_parse },
        { "description", (int (*)(void *, yyjson_val *))lldc__sticker_description_parse },
        { "tags", (int (*)(void *, yyjson_val *))lldc__sticker_tags_parse },
        { "type", (int (*)(void *, yyjson_val *))lldc__sticker_type_parse },
        { "format_type", (int (*)(void *, yyjson_val *))lldc__sticker_format_type_parse },
        { "available", (int (*)(void *, yyjson_val *))lldc__sticker_available_parse },
        { "guild_id", (int (*)(void *, yyjson_val *))lldc__sticker_guild_id_parse },
        { "user", (int (*)(void *, yyjson_val *))lldc__sticker_user_parse },
        { "sort_value", (int (*)(void *, yyjson_val *))lldc__sticker_sort_value_parse }
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

    lldc_struct_malloc_ledger_t *ledger = obj->_mlog;
    
    memset(obj, 0, sizeof(lldc_sticker_t));

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
        lldc_struct_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
/**
* Sticker Parser
* Sticker Objects
* type: object.object
*/
static
int lldc__sticker_item_parse (lldc_sticker_t *_obj, yyjson_val *json)
{
    return lldc_sticker_parse(_obj->_mctx, _obj, json, 1);
}
int lldc_sticker_arr_parse (cwr_malloc_ctx_t *_mctx, lldc_sticker_arr_t *obj, yyjson_val *json, int has_existing_ledger)
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

    obj->items = lldc_struct_malloc((lldc_struct_obj_t *)obj, sizeof(*obj->items) * arr_size);
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
        lldc__sticker_item_parse(&obj->items[idx], val);
    }

    return 0;
}
int lldc_sticker_item_parse (cwr_malloc_ctx_t *_mctx, lldc_sticker_item_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_struct_def_t parser_def[3] = {
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

    lldc_struct_malloc_ledger_t *ledger = obj->_mlog;
    
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
        lldc_struct_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
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

    obj->items = lldc_struct_malloc((lldc_struct_obj_t *)obj, sizeof(*obj->items) * arr_size);
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
/**
* stickers Parser
* the stickers in the pack
* type: object.object
*/
static
int lldc__sticker_packs_stickers_parse (lldc_sticker_packs_t *_obj, yyjson_val *json)
{
    _obj->stickers._mlog = _obj->_mlog;
    return lldc_sticker_arr_parse(_obj->_mctx, &_obj->stickers, json, 1);
}
int lldc_sticker_packs_parse (cwr_malloc_ctx_t *_mctx, lldc_sticker_packs_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_struct_def_t parser_def[7] = {
        { "id", (int (*)(void *, yyjson_val *))lldc__sticker_packs_id_parse },
        { "stickers", (int (*)(void *, yyjson_val *))lldc__sticker_packs_stickers_parse },
        { "name", (int (*)(void *, yyjson_val *))lldc__sticker_packs_name_parse },
        { "sku_id", (int (*)(void *, yyjson_val *))lldc__sticker_packs_sku_id_parse },
        { "cover_sticker_id", (int (*)(void *, yyjson_val *))lldc__sticker_packs_cover_sticker_id_parse },
        { "description", (int (*)(void *, yyjson_val *))lldc__sticker_packs_description_parse },
        { "banner_asset_id", (int (*)(void *, yyjson_val *))lldc__sticker_packs_banner_asset_id_parse }
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

    lldc_struct_malloc_ledger_t *ledger = obj->_mlog;
    
    memset(obj, 0, sizeof(lldc_sticker_packs_t));

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
        lldc_struct_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
int lldc_message_activity_parse (cwr_malloc_ctx_t *_mctx, lldc_message_activity_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_struct_def_t parser_def[2] = {
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

    lldc_struct_malloc_ledger_t *ledger = obj->_mlog;
    
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
        lldc_struct_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
int lldc_message_reference_parse (cwr_malloc_ctx_t *_mctx, lldc_message_reference_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_struct_def_t parser_def[4] = {
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

    lldc_struct_malloc_ledger_t *ledger = obj->_mlog;
    
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
        lldc_struct_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
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

    static lldc_struct_def_t parser_def[4] = {
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

    lldc_struct_malloc_ledger_t *ledger = obj->_mlog;
    
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
        lldc_struct_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
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
    lldc_struct_snowflake_arr_t *obj = &_obj->mention_roles;

    obj->_mctx = _obj->_mctx;
    obj->_mlog = _obj->_mlog;
    return lldc_struct_snowflake_arr_parse(obj, json);
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
* activity Parser
* OPTIONAL: sent with Rich Presence-related chat embeds
* type: object.object
*/
static
int lldc__message_activity_parse (lldc_message_t *_obj, yyjson_val *json)
{
    _obj->activity._mlog = _obj->_mlog;
    return lldc_message_activity_parse(_obj->_mctx, &_obj->activity, json, 1);
}
/**
* application Parser
* OPTIONAL: sent with Rich Presence-related chat embeds
* type: object.object
*/
static
int lldc__message_application_parse (lldc_message_t *_obj, yyjson_val *json)
{
    _obj->application._mlog = _obj->_mlog;
    return lldc_application_parse(_obj->_mctx, &_obj->application, json, 1);
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

    static lldc_struct_def_t parser_def[28] = {
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

    lldc_struct_malloc_ledger_t *ledger = obj->_mlog;
    
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
        lldc_struct_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
int lldc_followed_channel_parse (cwr_malloc_ctx_t *_mctx, lldc_followed_channel_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_struct_def_t parser_def[2] = {
        { "channel_id", (int (*)(void *, yyjson_val *))lldc__followed_channel_channel_id_parse },
        { "webhook_id", (int (*)(void *, yyjson_val *))lldc__followed_channel_webhook_id_parse }
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

    lldc_struct_malloc_ledger_t *ledger = obj->_mlog;
    
    memset(obj, 0, sizeof(lldc_followed_channel_t));

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
        lldc_struct_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
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

    static lldc_struct_def_t parser_def[26] = {
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

    lldc_struct_malloc_ledger_t *ledger = obj->_mlog;
    
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
        lldc_struct_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
/**
* Channel Parser
* Channel Objects
* type: object.object
*/
static
int lldc__channel_item_parse (lldc_channel_t *_obj, yyjson_val *json)
{
    return lldc_channel_parse(_obj->_mctx, _obj, json, 1);
}
int lldc_channel_arr_parse (cwr_malloc_ctx_t *_mctx, lldc_channel_arr_t *obj, yyjson_val *json, int has_existing_ledger)
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

    obj->items = lldc_struct_malloc((lldc_struct_obj_t *)obj, sizeof(*obj->items) * arr_size);
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
        lldc__channel_item_parse(&obj->items[idx], val);
    }

    return 0;
}
/**
* member Parser
* OPTIONAL: the guild member this voice state is for
* type: object.object
*/
static
int lldc__voice_state_member_parse (lldc_voice_state_t *_obj, yyjson_val *json)
{
    _obj->member._mlog = _obj->_mlog;
    return lldc_guild_member_parse(_obj->_mctx, &_obj->member, json, 1);
}
int lldc_voice_state_parse (cwr_malloc_ctx_t *_mctx, lldc_voice_state_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_struct_def_t parser_def[13] = {
        { "guild_id", (int (*)(void *, yyjson_val *))lldc__voice_state_guild_id_parse },
        { "channel_id", (int (*)(void *, yyjson_val *))lldc__voice_state_channel_id_parse },
        { "user_id", (int (*)(void *, yyjson_val *))lldc__voice_state_user_id_parse },
        { "member", (int (*)(void *, yyjson_val *))lldc__voice_state_member_parse },
        { "session_id", (int (*)(void *, yyjson_val *))lldc__voice_state_session_id_parse },
        { "deaf", (int (*)(void *, yyjson_val *))lldc__voice_state_deaf_parse },
        { "mute", (int (*)(void *, yyjson_val *))lldc__voice_state_mute_parse },
        { "self_deaf", (int (*)(void *, yyjson_val *))lldc__voice_state_self_deaf_parse },
        { "self_mute", (int (*)(void *, yyjson_val *))lldc__voice_state_self_mute_parse },
        { "self_stream", (int (*)(void *, yyjson_val *))lldc__voice_state_self_stream_parse },
        { "self_video", (int (*)(void *, yyjson_val *))lldc__voice_state_self_video_parse },
        { "suppress", (int (*)(void *, yyjson_val *))lldc__voice_state_suppress_parse },
        { "request_to_speak_timestamp", (int (*)(void *, yyjson_val *))lldc__voice_state_request_to_speak_timestamp_parse }
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

    lldc_struct_malloc_ledger_t *ledger = obj->_mlog;
    
    memset(obj, 0, sizeof(lldc_voice_state_t));

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
        lldc_struct_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
/**
* Voice State Parser
* Voice State Objects
* type: object.object
*/
static
int lldc__voice_state_item_parse (lldc_voice_state_t *_obj, yyjson_val *json)
{
    return lldc_voice_state_parse(_obj->_mctx, _obj, json, 1);
}
int lldc_voice_state_arr_parse (cwr_malloc_ctx_t *_mctx, lldc_voice_state_arr_t *obj, yyjson_val *json, int has_existing_ledger)
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

    obj->items = lldc_struct_malloc((lldc_struct_obj_t *)obj, sizeof(*obj->items) * arr_size);
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
        lldc__voice_state_item_parse(&obj->items[idx], val);
    }

    return 0;
}
int lldc_activity_timestamps_parse (cwr_malloc_ctx_t *_mctx, lldc_activity_timestamps_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_struct_def_t parser_def[2] = {
        { "start", (int (*)(void *, yyjson_val *))lldc__activity_timestamps_start_parse },
        { "end", (int (*)(void *, yyjson_val *))lldc__activity_timestamps_end_parse }
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

    lldc_struct_malloc_ledger_t *ledger = obj->_mlog;
    
    memset(obj, 0, sizeof(lldc_activity_timestamps_t));

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
        lldc_struct_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
/**
* size Parser
* OPTIONAL: used to show the party's current and maximum size
* type: object.array[int]
*/
static
int lldc__activity_party_size_parse (lldc_activity_party_t *_obj, yyjson_val *json)
{
    lldc_struct_int_arr_t *obj = &_obj->size;

    obj->_mctx = _obj->_mctx;
    obj->_mlog = _obj->_mlog;
    return lldc_struct_int_arr_parse(obj, json);
}
int lldc_activity_party_parse (cwr_malloc_ctx_t *_mctx, lldc_activity_party_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_struct_def_t parser_def[2] = {
        { "id", (int (*)(void *, yyjson_val *))lldc__activity_party_id_parse },
        { "size", (int (*)(void *, yyjson_val *))lldc__activity_party_size_parse }
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

    lldc_struct_malloc_ledger_t *ledger = obj->_mlog;
    
    memset(obj, 0, sizeof(lldc_activity_party_t));

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
        lldc_struct_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
int lldc_activity_assets_parse (cwr_malloc_ctx_t *_mctx, lldc_activity_assets_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_struct_def_t parser_def[4] = {
        { "large_image", (int (*)(void *, yyjson_val *))lldc__activity_assets_large_image_parse },
        { "large_text", (int (*)(void *, yyjson_val *))lldc__activity_assets_large_text_parse },
        { "small_image", (int (*)(void *, yyjson_val *))lldc__activity_assets_small_image_parse },
        { "small_text", (int (*)(void *, yyjson_val *))lldc__activity_assets_small_text_parse }
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

    lldc_struct_malloc_ledger_t *ledger = obj->_mlog;
    
    memset(obj, 0, sizeof(lldc_activity_assets_t));

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
        lldc_struct_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
int lldc_activity_secrets_parse (cwr_malloc_ctx_t *_mctx, lldc_activity_secrets_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_struct_def_t parser_def[3] = {
        { "join", (int (*)(void *, yyjson_val *))lldc__activity_secrets_join_parse },
        { "spectate", (int (*)(void *, yyjson_val *))lldc__activity_secrets_spectate_parse },
        { "match", (int (*)(void *, yyjson_val *))lldc__activity_secrets_match_parse }
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

    lldc_struct_malloc_ledger_t *ledger = obj->_mlog;
    
    memset(obj, 0, sizeof(lldc_activity_secrets_t));

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
        lldc_struct_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
/**
* timestamps Parser
* OPTIONAL: unix timestamps for start and/or end of the game
* type: object.object
*/
static
int lldc__activity_timestamps_parse (lldc_activity_t *_obj, yyjson_val *json)
{
    _obj->timestamps._mlog = _obj->_mlog;
    return lldc_activity_timestamps_parse(_obj->_mctx, &_obj->timestamps, json, 1);
}
/**
* emoji Parser
* OPTIONAL: the emoji used for a custom status
* type: object.object
*/
static
int lldc__activity_emoji_parse (lldc_activity_t *_obj, yyjson_val *json)
{
    _obj->emoji._mlog = _obj->_mlog;
    return lldc_emoji_parse(_obj->_mctx, &_obj->emoji, json, 1);
}
/**
* party Parser
* OPTIONAL: information for the current party of the player
* type: object.object
*/
static
int lldc__activity_party_parse (lldc_activity_t *_obj, yyjson_val *json)
{
    _obj->party._mlog = _obj->_mlog;
    return lldc_activity_party_parse(_obj->_mctx, &_obj->party, json, 1);
}
/**
* assets Parser
* OPTIONAL: images for the presence and their hover texts
* type: object.object
*/
static
int lldc__activity_assets_parse (lldc_activity_t *_obj, yyjson_val *json)
{
    _obj->assets._mlog = _obj->_mlog;
    return lldc_activity_assets_parse(_obj->_mctx, &_obj->assets, json, 1);
}
/**
* secrets Parser
* OPTIONAL: secrets for Rich Presence joining and spectating
* type: object.object
*/
static
int lldc__activity_secrets_parse (lldc_activity_t *_obj, yyjson_val *json)
{
    _obj->secrets._mlog = _obj->_mlog;
    return lldc_activity_secrets_parse(_obj->_mctx, &_obj->secrets, json, 1);
}
/**
* buttons Parser
* When received over the gateway, the buttons field is an array of strings, which are the button labels. Bots cannot access a user's activity button URLs. When sending, the buttons field must be an array of the below object:
* type: array.object
*/
static
int lldc__activity_buttons_item_parse (lldc_activity_buttons_item_t *obj, yyjson_val *json)
{

    static lldc_struct_def_t parser_def[2] = {
        { "label", (int (*)(void *, yyjson_val *))lldc__activity_buttons_item_label_parse },
        { "url", (int (*)(void *, yyjson_val *))lldc__activity_buttons_item_url_parse }
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

    lldc_struct_malloc_ledger_t *ledger = obj->_mlog;
    cwr_malloc_ctx_t *mctx = obj->_mctx;
    memset(obj, 0, sizeof(lldc_activity_buttons_item_t));

    obj->_mlog = ledger;
    obj->_mctx = mctx;
    yyjson_val *key, *val;
    yyjson_obj_iter iter;
    yyjson_obj_iter_init(json, &iter);
    while ((key = yyjson_obj_iter_next(&iter))) {
        val = yyjson_obj_iter_get_val(key);
        lldc_struct_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
/**
* buttons Parser
* OPTIONAL: the custom buttons shown in the Rich Presence (max 2)
* type: object.array[object]
*/
static
int lldc__activity_buttons_parse (lldc_activity_t *_obj, yyjson_val *json)
{
    lldc_activity_buttons_arr_t *obj = &_obj->buttons;

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

    obj->items = lldc_struct_malloc((lldc_struct_obj_t *)obj, sizeof(*obj->items) * arr_size);
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
        lldc__activity_buttons_item_parse(&obj->items[idx], val);
    }

    return 0;
}
int lldc_activity_parse (cwr_malloc_ctx_t *_mctx, lldc_activity_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_struct_def_t parser_def[15] = {
        { "name", (int (*)(void *, yyjson_val *))lldc__activity_name_parse },
        { "type", (int (*)(void *, yyjson_val *))lldc__activity_type_parse },
        { "url", (int (*)(void *, yyjson_val *))lldc__activity_url_parse },
        { "created_at", (int (*)(void *, yyjson_val *))lldc__activity_created_at_parse },
        { "timestamps", (int (*)(void *, yyjson_val *))lldc__activity_timestamps_parse },
        { "application_id", (int (*)(void *, yyjson_val *))lldc__activity_application_id_parse },
        { "details", (int (*)(void *, yyjson_val *))lldc__activity_details_parse },
        { "state", (int (*)(void *, yyjson_val *))lldc__activity_state_parse },
        { "emoji", (int (*)(void *, yyjson_val *))lldc__activity_emoji_parse },
        { "party", (int (*)(void *, yyjson_val *))lldc__activity_party_parse },
        { "assets", (int (*)(void *, yyjson_val *))lldc__activity_assets_parse },
        { "secrets", (int (*)(void *, yyjson_val *))lldc__activity_secrets_parse },
        { "instance", (int (*)(void *, yyjson_val *))lldc__activity_instance_parse },
        { "flags", (int (*)(void *, yyjson_val *))lldc__activity_flags_parse },
        { "buttons", (int (*)(void *, yyjson_val *))lldc__activity_buttons_parse }
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
    LLDC_PARSER_LOAD(15)

    if (!yyjson_is_obj(json))
        return -1;

    lldc_struct_malloc_ledger_t *ledger = obj->_mlog;
    
    memset(obj, 0, sizeof(lldc_activity_t));

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
        lldc_struct_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
int lldc_activity_bot_parse (cwr_malloc_ctx_t *_mctx, lldc_activity_bot_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_struct_def_t parser_def[3] = {
        { "name", (int (*)(void *, yyjson_val *))lldc__activity_bot_name_parse },
        { "type", (int (*)(void *, yyjson_val *))lldc__activity_bot_type_parse },
        { "url", (int (*)(void *, yyjson_val *))lldc__activity_bot_url_parse }
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

    lldc_struct_malloc_ledger_t *ledger = obj->_mlog;
    
    memset(obj, 0, sizeof(lldc_activity_bot_t));

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
        lldc_struct_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
/**
* Activity Parser
* Activity Objects
* type: object.object
*/
static
int lldc__activity_item_parse (lldc_activity_t *_obj, yyjson_val *json)
{
    return lldc_activity_parse(_obj->_mctx, _obj, json, 1);
}
int lldc_activity_arr_parse (cwr_malloc_ctx_t *_mctx, lldc_activity_arr_t *obj, yyjson_val *json, int has_existing_ledger)
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

    obj->items = lldc_struct_malloc((lldc_struct_obj_t *)obj, sizeof(*obj->items) * arr_size);
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
        lldc__activity_item_parse(&obj->items[idx], val);
    }

    return 0;
}
/**
* Activity Bot Parser
* Activity Bot Objects
* type: object.object
*/
static
int lldc__activity_bot_item_parse (lldc_activity_bot_t *_obj, yyjson_val *json)
{
    return lldc_activity_bot_parse(_obj->_mctx, _obj, json, 1);
}
int lldc_activity_bot_arr_parse (cwr_malloc_ctx_t *_mctx, lldc_activity_bot_arr_t *obj, yyjson_val *json, int has_existing_ledger)
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

    obj->items = lldc_struct_malloc((lldc_struct_obj_t *)obj, sizeof(*obj->items) * arr_size);
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
        lldc__activity_bot_item_parse(&obj->items[idx], val);
    }

    return 0;
}
int lldc_client_status_parse (cwr_malloc_ctx_t *_mctx, lldc_client_status_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_struct_def_t parser_def[3] = {
        { "desktop", (int (*)(void *, yyjson_val *))lldc__client_status_desktop_parse },
        { "mobile", (int (*)(void *, yyjson_val *))lldc__client_status_mobile_parse },
        { "web", (int (*)(void *, yyjson_val *))lldc__client_status_web_parse }
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

    lldc_struct_malloc_ledger_t *ledger = obj->_mlog;
    
    memset(obj, 0, sizeof(lldc_client_status_t));

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
        lldc_struct_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
/**
* user Parser
* the user presence is being updated for
* type: object.object
*/
static
int lldc__presence_update_user_parse (lldc_presence_update_t *_obj, yyjson_val *json)
{
    _obj->user._mlog = _obj->_mlog;
    return lldc_user_parse(_obj->_mctx, &_obj->user, json, 1);
}
/**
* activities Parser
* user's current activities
* type: object.object
*/
static
int lldc__presence_update_activities_parse (lldc_presence_update_t *_obj, yyjson_val *json)
{
    _obj->activities._mlog = _obj->_mlog;
    return lldc_activity_arr_parse(_obj->_mctx, &_obj->activities, json, 1);
}
/**
* client_status Parser
* user's platform-dependent status
* type: object.object
*/
static
int lldc__presence_update_client_status_parse (lldc_presence_update_t *_obj, yyjson_val *json)
{
    _obj->client_status._mlog = _obj->_mlog;
    return lldc_client_status_parse(_obj->_mctx, &_obj->client_status, json, 1);
}
int lldc_presence_update_parse (cwr_malloc_ctx_t *_mctx, lldc_presence_update_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_struct_def_t parser_def[5] = {
        { "user", (int (*)(void *, yyjson_val *))lldc__presence_update_user_parse },
        { "guild_id", (int (*)(void *, yyjson_val *))lldc__presence_update_guild_id_parse },
        { "status", (int (*)(void *, yyjson_val *))lldc__presence_update_status_parse },
        { "activities", (int (*)(void *, yyjson_val *))lldc__presence_update_activities_parse },
        { "client_status", (int (*)(void *, yyjson_val *))lldc__presence_update_client_status_parse }
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

    lldc_struct_malloc_ledger_t *ledger = obj->_mlog;
    
    memset(obj, 0, sizeof(lldc_presence_update_t));

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
        lldc_struct_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
/**
* Presence Update Parser
* Presence Update Objects
* type: object.object
*/
static
int lldc__presence_update_item_parse (lldc_presence_update_t *_obj, yyjson_val *json)
{
    return lldc_presence_update_parse(_obj->_mctx, _obj, json, 1);
}
int lldc_presence_update_arr_parse (cwr_malloc_ctx_t *_mctx, lldc_presence_update_arr_t *obj, yyjson_val *json, int has_existing_ledger)
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

    obj->items = lldc_struct_malloc((lldc_struct_obj_t *)obj, sizeof(*obj->items) * arr_size);
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
        lldc__presence_update_item_parse(&obj->items[idx], val);
    }

    return 0;
}
int lldc_gateway_payload_parse (cwr_malloc_ctx_t *_mctx, lldc_gateway_payload_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_struct_def_t parser_def[4] = {
        { "op", (int (*)(void *, yyjson_val *))lldc__gateway_payload_op_parse },
        { "d", (int (*)(void *, yyjson_val *))lldc__gateway_payload_d_parse },
        { "s", (int (*)(void *, yyjson_val *))lldc__gateway_payload_s_parse },
        { "t", (int (*)(void *, yyjson_val *))lldc__gateway_payload_t_parse }
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

    lldc_struct_malloc_ledger_t *ledger = obj->_mlog;
    
    memset(obj, 0, sizeof(lldc_gateway_payload_t));

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
        lldc_struct_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
int lldc_stage_instance_parse (cwr_malloc_ctx_t *_mctx, lldc_stage_instance_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_struct_def_t parser_def[6] = {
        { "id", (int (*)(void *, yyjson_val *))lldc__stage_instance_id_parse },
        { "guild_id", (int (*)(void *, yyjson_val *))lldc__stage_instance_guild_id_parse },
        { "channel_id", (int (*)(void *, yyjson_val *))lldc__stage_instance_channel_id_parse },
        { "topic", (int (*)(void *, yyjson_val *))lldc__stage_instance_topic_parse },
        { "privacy_level", (int (*)(void *, yyjson_val *))lldc__stage_instance_privacy_level_parse },
        { "discoverable_disabled", (int (*)(void *, yyjson_val *))lldc__stage_instance_discoverable_disabled_parse }
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
    LLDC_PARSER_LOAD(6)

    if (!yyjson_is_obj(json))
        return -1;

    lldc_struct_malloc_ledger_t *ledger = obj->_mlog;
    
    memset(obj, 0, sizeof(lldc_stage_instance_t));

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
        lldc_struct_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
/**
* Stage Instance Parser
* Stage Instance Objects
* type: object.object
*/
static
int lldc__stage_instance_item_parse (lldc_stage_instance_t *_obj, yyjson_val *json)
{
    return lldc_stage_instance_parse(_obj->_mctx, _obj, json, 1);
}
int lldc_stage_instance_arr_parse (cwr_malloc_ctx_t *_mctx, lldc_stage_instance_arr_t *obj, yyjson_val *json, int has_existing_ledger)
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

    obj->items = lldc_struct_malloc((lldc_struct_obj_t *)obj, sizeof(*obj->items) * arr_size);
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
        lldc__stage_instance_item_parse(&obj->items[idx], val);
    }

    return 0;
}
int lldc_welcome_screen_channel_parse (cwr_malloc_ctx_t *_mctx, lldc_welcome_screen_channel_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_struct_def_t parser_def[4] = {
        { "channel_id", (int (*)(void *, yyjson_val *))lldc__welcome_screen_channel_channel_id_parse },
        { "description", (int (*)(void *, yyjson_val *))lldc__welcome_screen_channel_description_parse },
        { "emoji_id", (int (*)(void *, yyjson_val *))lldc__welcome_screen_channel_emoji_id_parse },
        { "emoji_name", (int (*)(void *, yyjson_val *))lldc__welcome_screen_channel_emoji_name_parse }
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

    lldc_struct_malloc_ledger_t *ledger = obj->_mlog;
    
    memset(obj, 0, sizeof(lldc_welcome_screen_channel_t));

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
        lldc_struct_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
/**
* Welcome Screen Channel Parser
* Welcome Screen Channel Objects
* type: object.object
*/
static
int lldc__welcome_screen_channel_item_parse (lldc_welcome_screen_channel_t *_obj, yyjson_val *json)
{
    return lldc_welcome_screen_channel_parse(_obj->_mctx, _obj, json, 1);
}
int lldc_welcome_screen_channel_arr_parse (cwr_malloc_ctx_t *_mctx, lldc_welcome_screen_channel_arr_t *obj, yyjson_val *json, int has_existing_ledger)
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

    obj->items = lldc_struct_malloc((lldc_struct_obj_t *)obj, sizeof(*obj->items) * arr_size);
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
        lldc__welcome_screen_channel_item_parse(&obj->items[idx], val);
    }

    return 0;
}
/**
* welcome_channels Parser
* the channels shown in the welcome screen, up to 5
* type: object.object
*/
static
int lldc__welcome_screen_welcome_channels_parse (lldc_welcome_screen_t *_obj, yyjson_val *json)
{
    _obj->welcome_channels._mlog = _obj->_mlog;
    return lldc_welcome_screen_channel_arr_parse(_obj->_mctx, &_obj->welcome_channels, json, 1);
}
int lldc_welcome_screen_parse (cwr_malloc_ctx_t *_mctx, lldc_welcome_screen_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_struct_def_t parser_def[2] = {
        { "description", (int (*)(void *, yyjson_val *))lldc__welcome_screen_description_parse },
        { "welcome_channels", (int (*)(void *, yyjson_val *))lldc__welcome_screen_welcome_channels_parse }
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

    lldc_struct_malloc_ledger_t *ledger = obj->_mlog;
    
    memset(obj, 0, sizeof(lldc_welcome_screen_t));

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
        lldc_struct_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
int lldc_guilds_widget_parse (cwr_malloc_ctx_t *_mctx, lldc_guilds_widget_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_struct_def_t parser_def[2] = {
        { "enabled", (int (*)(void *, yyjson_val *))lldc__guilds_widget_enabled_parse },
        { "channel_id", (int (*)(void *, yyjson_val *))lldc__guilds_widget_channel_id_parse }
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

    lldc_struct_malloc_ledger_t *ledger = obj->_mlog;
    
    memset(obj, 0, sizeof(lldc_guilds_widget_t));

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
        lldc_struct_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
/**
* emojis Parser
* custom guild emojis
* type: object.object
*/
static
int lldc__guild_preview_emojis_parse (lldc_guild_preview_t *_obj, yyjson_val *json)
{
    _obj->emojis._mlog = _obj->_mlog;
    return lldc_emoji_arr_parse(_obj->_mctx, &_obj->emojis, json, 1);
}
/**
* features Parser
* enabled guild features
* type: object.array[string]
*/
static
int lldc__guild_preview_features_parse (lldc_guild_preview_t *_obj, yyjson_val *json)
{
    lldc_struct_string_arr_t *obj = &_obj->features;

    obj->_mctx = _obj->_mctx;
    obj->_mlog = _obj->_mlog;
    return lldc_struct_string_arr_parse(obj, json);
}
int lldc_guild_preview_parse (cwr_malloc_ctx_t *_mctx, lldc_guild_preview_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_struct_def_t parser_def[10] = {
        { "id", (int (*)(void *, yyjson_val *))lldc__guild_preview_id_parse },
        { "name", (int (*)(void *, yyjson_val *))lldc__guild_preview_name_parse },
        { "icon", (int (*)(void *, yyjson_val *))lldc__guild_preview_icon_parse },
        { "splash", (int (*)(void *, yyjson_val *))lldc__guild_preview_splash_parse },
        { "discovery_splash", (int (*)(void *, yyjson_val *))lldc__guild_preview_discovery_splash_parse },
        { "emojis", (int (*)(void *, yyjson_val *))lldc__guild_preview_emojis_parse },
        { "features", (int (*)(void *, yyjson_val *))lldc__guild_preview_features_parse },
        { "approximate_member_count", (int (*)(void *, yyjson_val *))lldc__guild_preview_approximate_member_count_parse },
        { "approximate_presence_count", (int (*)(void *, yyjson_val *))lldc__guild_preview_approximate_presence_count_parse },
        { "description", (int (*)(void *, yyjson_val *))lldc__guild_preview_description_parse }
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
    LLDC_PARSER_LOAD(10)

    if (!yyjson_is_obj(json))
        return -1;

    lldc_struct_malloc_ledger_t *ledger = obj->_mlog;
    
    memset(obj, 0, sizeof(lldc_guild_preview_t));

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
        lldc_struct_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
int lldc_integration_account_parse (cwr_malloc_ctx_t *_mctx, lldc_integration_account_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_struct_def_t parser_def[2] = {
        { "id", (int (*)(void *, yyjson_val *))lldc__integration_account_id_parse },
        { "name", (int (*)(void *, yyjson_val *))lldc__integration_account_name_parse }
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

    lldc_struct_malloc_ledger_t *ledger = obj->_mlog;
    
    memset(obj, 0, sizeof(lldc_integration_account_t));

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
        lldc_struct_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
/**
* bot Parser
* OPTIONAL: the bot associated with this application
* type: object.object
*/
static
int lldc__integration_application_bot_parse (lldc_integration_application_t *_obj, yyjson_val *json)
{
    _obj->bot._mlog = _obj->_mlog;
    return lldc_user_parse(_obj->_mctx, &_obj->bot, json, 1);
}
int lldc_integration_application_parse (cwr_malloc_ctx_t *_mctx, lldc_integration_application_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_struct_def_t parser_def[6] = {
        { "id", (int (*)(void *, yyjson_val *))lldc__integration_application_id_parse },
        { "name", (int (*)(void *, yyjson_val *))lldc__integration_application_name_parse },
        { "icon", (int (*)(void *, yyjson_val *))lldc__integration_application_icon_parse },
        { "description", (int (*)(void *, yyjson_val *))lldc__integration_application_description_parse },
        { "summary", (int (*)(void *, yyjson_val *))lldc__integration_application_summary_parse },
        { "bot", (int (*)(void *, yyjson_val *))lldc__integration_application_bot_parse }
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
    LLDC_PARSER_LOAD(6)

    if (!yyjson_is_obj(json))
        return -1;

    lldc_struct_malloc_ledger_t *ledger = obj->_mlog;
    
    memset(obj, 0, sizeof(lldc_integration_application_t));

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
        lldc_struct_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
/**
* user Parser
* OPTIONAL: user for this integration
* type: object.object
*/
static
int lldc__integration_user_parse (lldc_integration_t *_obj, yyjson_val *json)
{
    _obj->user._mlog = _obj->_mlog;
    return lldc_user_parse(_obj->_mctx, &_obj->user, json, 1);
}
/**
* account Parser
* integration account information
* type: object.object
*/
static
int lldc__integration_account_parse (lldc_integration_t *_obj, yyjson_val *json)
{
    _obj->account._mlog = _obj->_mlog;
    return lldc_integration_account_parse(_obj->_mctx, &_obj->account, json, 1);
}
/**
* application Parser
* OPTIONAL: The bot/OAuth2 application for discord integrations
* type: object.object
*/
static
int lldc__integration_application_parse (lldc_integration_t *_obj, yyjson_val *json)
{
    _obj->application._mlog = _obj->_mlog;
    return lldc_integration_application_parse(_obj->_mctx, &_obj->application, json, 1);
}
int lldc_integration_parse (cwr_malloc_ctx_t *_mctx, lldc_integration_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_struct_def_t parser_def[15] = {
        { "id", (int (*)(void *, yyjson_val *))lldc__integration_id_parse },
        { "name", (int (*)(void *, yyjson_val *))lldc__integration_name_parse },
        { "type", (int (*)(void *, yyjson_val *))lldc__integration_type_parse },
        { "enabled", (int (*)(void *, yyjson_val *))lldc__integration_enabled_parse },
        { "syncing", (int (*)(void *, yyjson_val *))lldc__integration_syncing_parse },
        { "role_id", (int (*)(void *, yyjson_val *))lldc__integration_role_id_parse },
        { "enable_emoticons", (int (*)(void *, yyjson_val *))lldc__integration_enable_emoticons_parse },
        { "expire_behavior", (int (*)(void *, yyjson_val *))lldc__integration_expire_behavior_parse },
        { "expire_grace_period", (int (*)(void *, yyjson_val *))lldc__integration_expire_grace_period_parse },
        { "user", (int (*)(void *, yyjson_val *))lldc__integration_user_parse },
        { "account", (int (*)(void *, yyjson_val *))lldc__integration_account_parse },
        { "synced_at", (int (*)(void *, yyjson_val *))lldc__integration_synced_at_parse },
        { "subscriber_count", (int (*)(void *, yyjson_val *))lldc__integration_subscriber_count_parse },
        { "revoked", (int (*)(void *, yyjson_val *))lldc__integration_revoked_parse },
        { "application", (int (*)(void *, yyjson_val *))lldc__integration_application_parse }
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
    LLDC_PARSER_LOAD(15)

    if (!yyjson_is_obj(json))
        return -1;

    lldc_struct_malloc_ledger_t *ledger = obj->_mlog;
    
    memset(obj, 0, sizeof(lldc_integration_t));

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
        lldc_struct_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
/**
* Integration Parser
* Integration Objects
* type: object.object
*/
static
int lldc__integration_item_parse (lldc_integration_t *_obj, yyjson_val *json)
{
    return lldc_integration_parse(_obj->_mctx, _obj, json, 1);
}
int lldc_integration_arr_parse (cwr_malloc_ctx_t *_mctx, lldc_integration_arr_t *obj, yyjson_val *json, int has_existing_ledger)
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

    obj->items = lldc_struct_malloc((lldc_struct_obj_t *)obj, sizeof(*obj->items) * arr_size);
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
        lldc__integration_item_parse(&obj->items[idx], val);
    }

    return 0;
}
/**
* account Parser
* integration account information
* type: object.object
*/
static
int lldc__partial_integration_account_parse (lldc_partial_integration_t *_obj, yyjson_val *json)
{
    _obj->account._mlog = _obj->_mlog;
    return lldc_integration_account_parse(_obj->_mctx, &_obj->account, json, 1);
}
int lldc_partial_integration_parse (cwr_malloc_ctx_t *_mctx, lldc_partial_integration_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_struct_def_t parser_def[5] = {
        { "id", (int (*)(void *, yyjson_val *))lldc__partial_integration_id_parse },
        { "name", (int (*)(void *, yyjson_val *))lldc__partial_integration_name_parse },
        { "type", (int (*)(void *, yyjson_val *))lldc__partial_integration_type_parse },
        { "enabled", (int (*)(void *, yyjson_val *))lldc__partial_integration_enabled_parse },
        { "account", (int (*)(void *, yyjson_val *))lldc__partial_integration_account_parse }
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

    lldc_struct_malloc_ledger_t *ledger = obj->_mlog;
    
    memset(obj, 0, sizeof(lldc_partial_integration_t));

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
        lldc_struct_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
/**
* Partial Integration Parser
* Partial Integration Objects
* type: object.object
*/
static
int lldc__partial_integration_item_parse (lldc_partial_integration_t *_obj, yyjson_val *json)
{
    return lldc_partial_integration_parse(_obj->_mctx, _obj, json, 1);
}
int lldc_partial_integration_arr_parse (cwr_malloc_ctx_t *_mctx, lldc_partial_integration_arr_t *obj, yyjson_val *json, int has_existing_ledger)
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

    obj->items = lldc_struct_malloc((lldc_struct_obj_t *)obj, sizeof(*obj->items) * arr_size);
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
        lldc__partial_integration_item_parse(&obj->items[idx], val);
    }

    return 0;
}
/**
* user Parser
* the banned user
* type: object.object
*/
static
int lldc__ban_user_parse (lldc_ban_t *_obj, yyjson_val *json)
{
    _obj->user._mlog = _obj->_mlog;
    return lldc_user_parse(_obj->_mctx, &_obj->user, json, 1);
}
int lldc_ban_parse (cwr_malloc_ctx_t *_mctx, lldc_ban_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_struct_def_t parser_def[2] = {
        { "reason", (int (*)(void *, yyjson_val *))lldc__ban_reason_parse },
        { "user", (int (*)(void *, yyjson_val *))lldc__ban_user_parse }
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

    lldc_struct_malloc_ledger_t *ledger = obj->_mlog;
    
    memset(obj, 0, sizeof(lldc_ban_t));

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
        lldc_struct_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
/**
* Ban Parser
* Ban Objects
* type: object.object
*/
static
int lldc__ban_item_parse (lldc_ban_t *_obj, yyjson_val *json)
{
    return lldc_ban_parse(_obj->_mctx, _obj, json, 1);
}
int lldc_ban_arr_parse (cwr_malloc_ctx_t *_mctx, lldc_ban_arr_t *obj, yyjson_val *json, int has_existing_ledger)
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

    obj->items = lldc_struct_malloc((lldc_struct_obj_t *)obj, sizeof(*obj->items) * arr_size);
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
        lldc__ban_item_parse(&obj->items[idx], val);
    }

    return 0;
}
/**
* roles Parser
* roles in the guild
* type: object.object
*/
static
int lldc__guild_roles_parse (lldc_guild_t *_obj, yyjson_val *json)
{
    _obj->roles._mlog = _obj->_mlog;
    return lldc_role_parse(_obj->_mctx, &_obj->roles, json, 1);
}
/**
* emojis Parser
* custom guild emojis
* type: object.object
*/
static
int lldc__guild_emojis_parse (lldc_guild_t *_obj, yyjson_val *json)
{
    _obj->emojis._mlog = _obj->_mlog;
    return lldc_emoji_parse(_obj->_mctx, &_obj->emojis, json, 1);
}
/**
* features Parser
* enabled guild features
* type: object.array[string]
*/
static
int lldc__guild_features_parse (lldc_guild_t *_obj, yyjson_val *json)
{
    lldc_struct_string_arr_t *obj = &_obj->features;

    obj->_mctx = _obj->_mctx;
    obj->_mlog = _obj->_mlog;
    return lldc_struct_string_arr_parse(obj, json);
}
/**
* voice_states Parser
* OPTIONAL: states of members currently in voice channels; lacks the guild_id key
* type: object.object
*/
static
int lldc__guild_voice_states_parse (lldc_guild_t *_obj, yyjson_val *json)
{
    _obj->voice_states._mlog = _obj->_mlog;
    return lldc_voice_state_arr_parse(_obj->_mctx, &_obj->voice_states, json, 1);
}
/**
* members Parser
* OPTIONAL: users in the guild
* type: object.object
*/
static
int lldc__guild_members_parse (lldc_guild_t *_obj, yyjson_val *json)
{
    _obj->members._mlog = _obj->_mlog;
    return lldc_guild_member_arr_parse(_obj->_mctx, &_obj->members, json, 1);
}
/**
* channels Parser
* OPTIONAL: channels in the guild
* type: object.object
*/
static
int lldc__guild_channels_parse (lldc_guild_t *_obj, yyjson_val *json)
{
    _obj->channels._mlog = _obj->_mlog;
    return lldc_channel_arr_parse(_obj->_mctx, &_obj->channels, json, 1);
}
/**
* threads Parser
* OPTIONAL: all active threads in the guild that current user has permission to view
* type: object.object
*/
static
int lldc__guild_threads_parse (lldc_guild_t *_obj, yyjson_val *json)
{
    _obj->threads._mlog = _obj->_mlog;
    return lldc_channel_arr_parse(_obj->_mctx, &_obj->threads, json, 1);
}
/**
* presences Parser
* OPTIONAL: presences of the members in the guild, will only include non-offline members if the size is greater than large threshold
* type: object.object
*/
static
int lldc__guild_presences_parse (lldc_guild_t *_obj, yyjson_val *json)
{
    _obj->presences._mlog = _obj->_mlog;
    return lldc_presence_update_arr_parse(_obj->_mctx, &_obj->presences, json, 1);
}
/**
* welcome_screen Parser
* OPTIONAL: the welcome screen of a Community guild, shown to new members, returned in an Invite's guild object
* type: object.object
*/
static
int lldc__guild_welcome_screen_parse (lldc_guild_t *_obj, yyjson_val *json)
{
    _obj->welcome_screen._mlog = _obj->_mlog;
    return lldc_welcome_screen_parse(_obj->_mctx, &_obj->welcome_screen, json, 1);
}
/**
* stage_instances Parser
* OPTIONAL: Stage instances in the guild
* type: object.object
*/
static
int lldc__guild_stage_instances_parse (lldc_guild_t *_obj, yyjson_val *json)
{
    _obj->stage_instances._mlog = _obj->_mlog;
    return lldc_stage_instance_arr_parse(_obj->_mctx, &_obj->stage_instances, json, 1);
}
/**
* stickers Parser
* OPTIONAL: custom guild stickers
* type: object.object
*/
static
int lldc__guild_stickers_parse (lldc_guild_t *_obj, yyjson_val *json)
{
    _obj->stickers._mlog = _obj->_mlog;
    return lldc_sticker_arr_parse(_obj->_mctx, &_obj->stickers, json, 1);
}
int lldc_guild_parse (cwr_malloc_ctx_t *_mctx, lldc_guild_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_struct_def_t parser_def[50] = {
        { "id", (int (*)(void *, yyjson_val *))lldc__guild_id_parse },
        { "name", (int (*)(void *, yyjson_val *))lldc__guild_name_parse },
        { "icon", (int (*)(void *, yyjson_val *))lldc__guild_icon_parse },
        { "icon_hash", (int (*)(void *, yyjson_val *))lldc__guild_icon_hash_parse },
        { "splash", (int (*)(void *, yyjson_val *))lldc__guild_splash_parse },
        { "discovery_splash", (int (*)(void *, yyjson_val *))lldc__guild_discovery_splash_parse },
        { "owner", (int (*)(void *, yyjson_val *))lldc__guild_owner_parse },
        { "owner_id", (int (*)(void *, yyjson_val *))lldc__guild_owner_id_parse },
        { "permissions", (int (*)(void *, yyjson_val *))lldc__guild_permissions_parse },
        { "region", (int (*)(void *, yyjson_val *))lldc__guild_region_parse },
        { "afk_channel_id", (int (*)(void *, yyjson_val *))lldc__guild_afk_channel_id_parse },
        { "afk_timeout", (int (*)(void *, yyjson_val *))lldc__guild_afk_timeout_parse },
        { "widget_enabled", (int (*)(void *, yyjson_val *))lldc__guild_widget_enabled_parse },
        { "widget_channel_id", (int (*)(void *, yyjson_val *))lldc__guild_widget_channel_id_parse },
        { "verification_level", (int (*)(void *, yyjson_val *))lldc__guild_verification_level_parse },
        { "default_message_notifications", (int (*)(void *, yyjson_val *))lldc__guild_default_message_notifications_parse },
        { "explicit_content_filter", (int (*)(void *, yyjson_val *))lldc__guild_explicit_content_filter_parse },
        { "roles", (int (*)(void *, yyjson_val *))lldc__guild_roles_parse },
        { "emojis", (int (*)(void *, yyjson_val *))lldc__guild_emojis_parse },
        { "features", (int (*)(void *, yyjson_val *))lldc__guild_features_parse },
        { "mfa_level", (int (*)(void *, yyjson_val *))lldc__guild_mfa_level_parse },
        { "application_id", (int (*)(void *, yyjson_val *))lldc__guild_application_id_parse },
        { "system_channel_id", (int (*)(void *, yyjson_val *))lldc__guild_system_channel_id_parse },
        { "system_channel_flags", (int (*)(void *, yyjson_val *))lldc__guild_system_channel_flags_parse },
        { "rules_channel_id", (int (*)(void *, yyjson_val *))lldc__guild_rules_channel_id_parse },
        { "joined_at", (int (*)(void *, yyjson_val *))lldc__guild_joined_at_parse },
        { "large", (int (*)(void *, yyjson_val *))lldc__guild_large_parse },
        { "unavailable", (int (*)(void *, yyjson_val *))lldc__guild_unavailable_parse },
        { "member_count", (int (*)(void *, yyjson_val *))lldc__guild_member_count_parse },
        { "voice_states", (int (*)(void *, yyjson_val *))lldc__guild_voice_states_parse },
        { "members", (int (*)(void *, yyjson_val *))lldc__guild_members_parse },
        { "channels", (int (*)(void *, yyjson_val *))lldc__guild_channels_parse },
        { "threads", (int (*)(void *, yyjson_val *))lldc__guild_threads_parse },
        { "presences", (int (*)(void *, yyjson_val *))lldc__guild_presences_parse },
        { "max_presences", (int (*)(void *, yyjson_val *))lldc__guild_max_presences_parse },
        { "max_members", (int (*)(void *, yyjson_val *))lldc__guild_max_members_parse },
        { "vanity_url_code", (int (*)(void *, yyjson_val *))lldc__guild_vanity_url_code_parse },
        { "description", (int (*)(void *, yyjson_val *))lldc__guild_description_parse },
        { "banner", (int (*)(void *, yyjson_val *))lldc__guild_banner_parse },
        { "premium_tier", (int (*)(void *, yyjson_val *))lldc__guild_premium_tier_parse },
        { "premium_subscription_count", (int (*)(void *, yyjson_val *))lldc__guild_premium_subscription_count_parse },
        { "preferred_locale", (int (*)(void *, yyjson_val *))lldc__guild_preferred_locale_parse },
        { "public_updates_channel_id", (int (*)(void *, yyjson_val *))lldc__guild_public_updates_channel_id_parse },
        { "max_video_channel_users", (int (*)(void *, yyjson_val *))lldc__guild_max_video_channel_users_parse },
        { "approximate_member_count", (int (*)(void *, yyjson_val *))lldc__guild_approximate_member_count_parse },
        { "approximate_presence_count", (int (*)(void *, yyjson_val *))lldc__guild_approximate_presence_count_parse },
        { "welcome_screen", (int (*)(void *, yyjson_val *))lldc__guild_welcome_screen_parse },
        { "nsfw_level", (int (*)(void *, yyjson_val *))lldc__guild_nsfw_level_parse },
        { "stage_instances", (int (*)(void *, yyjson_val *))lldc__guild_stage_instances_parse },
        { "stickers", (int (*)(void *, yyjson_val *))lldc__guild_stickers_parse }
    };

    static lldc_hashmap_entry_t parser_table[128] = { 0 };
    static lldc_hashmap_t parsers = {  
        .size = 128,
        .len = 0,
        .table = parser_table,
        .hash = lldc_hashmap_hash_str,
        .compare = (int (*)(const void *, const void *))strcmp,
        .dup_key = lldc_hashmap_dup_echo,
        .free_key = lldc_hashmap_free_noop
    };
    LLDC_PARSER_LOAD(50)

    if (!yyjson_is_obj(json))
        return -1;

    lldc_struct_malloc_ledger_t *ledger = obj->_mlog;
    
    memset(obj, 0, sizeof(lldc_guild_t));

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
        lldc_struct_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
/**
* Guild Parser
* Guild Objects
* type: object.object
*/
static
int lldc__guild_item_parse (lldc_guild_t *_obj, yyjson_val *json)
{
    return lldc_guild_parse(_obj->_mctx, _obj, json, 1);
}
int lldc_guild_arr_parse (cwr_malloc_ctx_t *_mctx, lldc_guild_arr_t *obj, yyjson_val *json, int has_existing_ledger)
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

    obj->items = lldc_struct_malloc((lldc_struct_obj_t *)obj, sizeof(*obj->items) * arr_size);
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
        lldc__guild_item_parse(&obj->items[idx], val);
    }

    return 0;
}
/**
* creator Parser
* the user who created the template
* type: object.object
*/
static
int lldc__guild_template_creator_parse (lldc_guild_template_t *_obj, yyjson_val *json)
{
    _obj->creator._mlog = _obj->_mlog;
    return lldc_user_parse(_obj->_mctx, &_obj->creator, json, 1);
}
int lldc_guild_template_parse (cwr_malloc_ctx_t *_mctx, lldc_guild_template_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_struct_def_t parser_def[10] = {
        { "code", (int (*)(void *, yyjson_val *))lldc__guild_template_code_parse },
        { "name", (int (*)(void *, yyjson_val *))lldc__guild_template_name_parse },
        { "description", (int (*)(void *, yyjson_val *))lldc__guild_template_description_parse },
        { "usage_count", (int (*)(void *, yyjson_val *))lldc__guild_template_usage_count_parse },
        { "creator_id", (int (*)(void *, yyjson_val *))lldc__guild_template_creator_id_parse },
        { "creator", (int (*)(void *, yyjson_val *))lldc__guild_template_creator_parse },
        { "created_at", (int (*)(void *, yyjson_val *))lldc__guild_template_created_at_parse },
        { "updated_at", (int (*)(void *, yyjson_val *))lldc__guild_template_updated_at_parse },
        { "source_guild_id", (int (*)(void *, yyjson_val *))lldc__guild_template_source_guild_id_parse },
        { "is_dirty", (int (*)(void *, yyjson_val *))lldc__guild_template_is_dirty_parse }
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
    LLDC_PARSER_LOAD(10)

    if (!yyjson_is_obj(json))
        return -1;

    lldc_struct_malloc_ledger_t *ledger = obj->_mlog;
    
    memset(obj, 0, sizeof(lldc_guild_template_t));

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
        lldc_struct_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
/**
* Guild Template Parser
* Guild Template Objects
* type: object.object
*/
static
int lldc__guild_template_item_parse (lldc_guild_template_t *_obj, yyjson_val *json)
{
    return lldc_guild_template_parse(_obj->_mctx, _obj, json, 1);
}
int lldc_guild_template_arr_parse (cwr_malloc_ctx_t *_mctx, lldc_guild_template_arr_t *obj, yyjson_val *json, int has_existing_ledger)
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

    obj->items = lldc_struct_malloc((lldc_struct_obj_t *)obj, sizeof(*obj->items) * arr_size);
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
        lldc__guild_template_item_parse(&obj->items[idx], val);
    }

    return 0;
}
/**
* members Parser
* the members speaking in the Stage
* type: object.object
*/
static
int lldc__invite_stage_instance_members_parse (lldc_invite_stage_instance_t *_obj, yyjson_val *json)
{
    _obj->members._mlog = _obj->_mlog;
    return lldc_partial_guild_member_arr_parse(_obj->_mctx, &_obj->members, json, 1);
}
int lldc_invite_stage_instance_parse (cwr_malloc_ctx_t *_mctx, lldc_invite_stage_instance_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_struct_def_t parser_def[4] = {
        { "members", (int (*)(void *, yyjson_val *))lldc__invite_stage_instance_members_parse },
        { "participant_count", (int (*)(void *, yyjson_val *))lldc__invite_stage_instance_participant_count_parse },
        { "speaker_count", (int (*)(void *, yyjson_val *))lldc__invite_stage_instance_speaker_count_parse },
        { "topic", (int (*)(void *, yyjson_val *))lldc__invite_stage_instance_topic_parse }
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

    lldc_struct_malloc_ledger_t *ledger = obj->_mlog;
    
    memset(obj, 0, sizeof(lldc_invite_stage_instance_t));

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
        lldc_struct_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
int lldc_invite_metadata_parse (cwr_malloc_ctx_t *_mctx, lldc_invite_metadata_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_struct_def_t parser_def[5] = {
        { "uses", (int (*)(void *, yyjson_val *))lldc__invite_metadata_uses_parse },
        { "max_uses", (int (*)(void *, yyjson_val *))lldc__invite_metadata_max_uses_parse },
        { "max_age", (int (*)(void *, yyjson_val *))lldc__invite_metadata_max_age_parse },
        { "temporary", (int (*)(void *, yyjson_val *))lldc__invite_metadata_temporary_parse },
        { "created_at", (int (*)(void *, yyjson_val *))lldc__invite_metadata_created_at_parse }
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

    lldc_struct_malloc_ledger_t *ledger = obj->_mlog;
    
    memset(obj, 0, sizeof(lldc_invite_metadata_t));

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
        lldc_struct_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
/**
* guild Parser
* OPTIONAL: the guild this invite is for
* type: object.object
*/
static
int lldc__invite_guild_parse (lldc_invite_t *_obj, yyjson_val *json)
{
    _obj->guild._mlog = _obj->_mlog;
    return lldc_partial_guild_parse(_obj->_mctx, &_obj->guild, json, 1);
}
/**
* channel Parser
* the channel this invite is for
* type: object.object
*/
static
int lldc__invite_channel_parse (lldc_invite_t *_obj, yyjson_val *json)
{
    _obj->channel._mlog = _obj->_mlog;
    return lldc_partial_channel_parse(_obj->_mctx, &_obj->channel, json, 1);
}
/**
* inviter Parser
* OPTIONAL: the user who created the invite
* type: object.object
*/
static
int lldc__invite_inviter_parse (lldc_invite_t *_obj, yyjson_val *json)
{
    _obj->inviter._mlog = _obj->_mlog;
    return lldc_user_parse(_obj->_mctx, &_obj->inviter, json, 1);
}
/**
* target_user Parser
* OPTIONAL: the user whose stream to display for this voice channel stream invite
* type: object.object
*/
static
int lldc__invite_target_user_parse (lldc_invite_t *_obj, yyjson_val *json)
{
    _obj->target_user._mlog = _obj->_mlog;
    return lldc_user_parse(_obj->_mctx, &_obj->target_user, json, 1);
}
/**
* target_application Parser
* OPTIONAL: the embedded application to open for this voice channel embedded application invite
* type: object.object
*/
static
int lldc__invite_target_application_parse (lldc_invite_t *_obj, yyjson_val *json)
{
    _obj->target_application._mlog = _obj->_mlog;
    return lldc_application_parse(_obj->_mctx, &_obj->target_application, json, 1);
}
/**
* stage_instance Parser
* OPTIONAL: stage instance data if there is a public Stage instance in the Stage channel this invite is for
* type: object.object
*/
static
int lldc__invite_stage_instance_parse (lldc_invite_t *_obj, yyjson_val *json)
{
    _obj->stage_instance._mlog = _obj->_mlog;
    return lldc_invite_stage_instance_parse(_obj->_mctx, &_obj->stage_instance, json, 1);
}
int lldc_invite_parse (cwr_malloc_ctx_t *_mctx, lldc_invite_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_struct_def_t parser_def[11] = {
        { "code", (int (*)(void *, yyjson_val *))lldc__invite_code_parse },
        { "guild", (int (*)(void *, yyjson_val *))lldc__invite_guild_parse },
        { "channel", (int (*)(void *, yyjson_val *))lldc__invite_channel_parse },
        { "inviter", (int (*)(void *, yyjson_val *))lldc__invite_inviter_parse },
        { "target_type", (int (*)(void *, yyjson_val *))lldc__invite_target_type_parse },
        { "target_user", (int (*)(void *, yyjson_val *))lldc__invite_target_user_parse },
        { "target_application", (int (*)(void *, yyjson_val *))lldc__invite_target_application_parse },
        { "approximate_presence_count", (int (*)(void *, yyjson_val *))lldc__invite_approximate_presence_count_parse },
        { "approximate_member_count", (int (*)(void *, yyjson_val *))lldc__invite_approximate_member_count_parse },
        { "expires_at", (int (*)(void *, yyjson_val *))lldc__invite_expires_at_parse },
        { "stage_instance", (int (*)(void *, yyjson_val *))lldc__invite_stage_instance_parse }
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

    lldc_struct_malloc_ledger_t *ledger = obj->_mlog;
    
    memset(obj, 0, sizeof(lldc_invite_t));

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
        lldc_struct_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
/**
* integrations Parser
* OPTIONAL: an array of partial server integrations
* type: object.object
*/
static
int lldc__connection_integrations_parse (lldc_connection_t *_obj, yyjson_val *json)
{
    _obj->integrations._mlog = _obj->_mlog;
    return lldc_partial_integration_arr_parse(_obj->_mctx, &_obj->integrations, json, 1);
}
int lldc_connection_parse (cwr_malloc_ctx_t *_mctx, lldc_connection_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_struct_def_t parser_def[9] = {
        { "id", (int (*)(void *, yyjson_val *))lldc__connection_id_parse },
        { "name", (int (*)(void *, yyjson_val *))lldc__connection_name_parse },
        { "type", (int (*)(void *, yyjson_val *))lldc__connection_type_parse },
        { "revoked", (int (*)(void *, yyjson_val *))lldc__connection_revoked_parse },
        { "integrations", (int (*)(void *, yyjson_val *))lldc__connection_integrations_parse },
        { "verified", (int (*)(void *, yyjson_val *))lldc__connection_verified_parse },
        { "friend_sync", (int (*)(void *, yyjson_val *))lldc__connection_friend_sync_parse },
        { "show_activity", (int (*)(void *, yyjson_val *))lldc__connection_show_activity_parse },
        { "visibility", (int (*)(void *, yyjson_val *))lldc__connection_visibility_parse }
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

    lldc_struct_malloc_ledger_t *ledger = obj->_mlog;
    
    memset(obj, 0, sizeof(lldc_connection_t));

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
        lldc_struct_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
int lldc_voice_region_parse (cwr_malloc_ctx_t *_mctx, lldc_voice_region_t *obj, yyjson_val *json, int has_existing_ledger)
{

    static lldc_struct_def_t parser_def[6] = {
        { "id", (int (*)(void *, yyjson_val *))lldc__voice_region_id_parse },
        { "name", (int (*)(void *, yyjson_val *))lldc__voice_region_name_parse },
        { "vip", (int (*)(void *, yyjson_val *))lldc__voice_region_vip_parse },
        { "optimal", (int (*)(void *, yyjson_val *))lldc__voice_region_optimal_parse },
        { "deprecated", (int (*)(void *, yyjson_val *))lldc__voice_region_deprecated_parse },
        { "custom", (int (*)(void *, yyjson_val *))lldc__voice_region_custom_parse }
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
    LLDC_PARSER_LOAD(6)

    if (!yyjson_is_obj(json))
        return -1;

    lldc_struct_malloc_ledger_t *ledger = obj->_mlog;
    
    memset(obj, 0, sizeof(lldc_voice_region_t));

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
        lldc_struct_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;
}
/**
* Voice Region Parser
* Voice Region Objects
* type: object.object
*/
static
int lldc__voice_region_item_parse (lldc_voice_region_t *_obj, yyjson_val *json)
{
    return lldc_voice_region_parse(_obj->_mctx, _obj, json, 1);
}
int lldc_voice_region_arr_parse (cwr_malloc_ctx_t *_mctx, lldc_voice_region_arr_t *obj, yyjson_val *json, int has_existing_ledger)
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

    obj->items = lldc_struct_malloc((lldc_struct_obj_t *)obj, sizeof(*obj->items) * arr_size);
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
        lldc__voice_region_item_parse(&obj->items[idx], val);
    }

    return 0;
}