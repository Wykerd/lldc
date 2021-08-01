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
#ifndef LLDC_PARSERS_H
#define LLDC_PARSERS_H
#include <lldc/parse.h>
#include <yyjson.h>
typedef enum lldc_user_flag {
    /* None */
    LLDC_USER_FLAG_NONE = (0),
    /* Discord Employee */
    LLDC_USER_FLAG_DISCORD_EMPLOYEE = (1 << 0),
    /* Partnered Server Owner */
    LLDC_USER_FLAG_PARTNERED_SERVER_OWNER = (1 << 1),
    /* HypeSquad Events */
    LLDC_USER_FLAG_HYPE_SQUAD_EVENTS = (1 << 2),
    /* Bug Hunter Level 1 */
    LLDC_USER_FLAG_BUG_HUNTER_LEVEL_1 = (1 << 3),
    /* House Bravery */
    LLDC_USER_FLAG_HOUSE_BRAVERY = (1 << 6),
    /* House Brilliance */
    LLDC_USER_FLAG_HOUSE_BRILLIANCE = (1 << 7),
    /* House Balance */
    LLDC_USER_FLAG_HOUSE_BALANCE = (1 << 8),
    /* Early Supporter */
    LLDC_USER_FLAG_EARLY_SUPPORTER = (1 << 9),
    /* Team User */
    LLDC_USER_FLAG_TEAM_USER = (1 << 10),
    /* Bug Hunter Level 2 */
    LLDC_USER_FLAG_BUG_HUNTER_LEVEL_2 = (1 << 14),
    /* Verified Bot */
    LLDC_USER_FLAG_VERIFIED_BOT = (1 << 16),
    /* Early Verified Bot Developer */
    LLDC_USER_FLAG_EARLY_VERIFIED_BOT_DEVELOPER = (1 << 17),
    /* Discord Certified Moderator */
    LLDC_USER_FLAG_DISCORD_CERTIFIED_MODERATOR = (1 << 18)
} lldc_user_flag_t;
typedef enum lldc_user_premium {
    /* None */
    LLDC_PREMIUM_NONE = (0),
    /* Nitro Classic */
    LLDC_PREMIUM_NITRO_CLASSIC = (1),
    /* Nitro */
    LLDC_PREMIUM_NITRO = (2)
} lldc_user_premium_t;
typedef enum lldc_webhook_type {
    /* Incoming Webhooks can post messages to channels with a generated token */
    LLDC_WEBHOOK_INCOMING = (1),
    /* Channel Follower Webhooks are internal webhooks used with Channel Following to post new messages into channels */
    LLDC_WEBHOOK_CHANNEL_FOLLOWER = (2),
    /* Application webhooks are webhooks used with Interactions */
    LLDC_WEBHOOK_APPLICATION = (3)
} lldc_webhook_type_t;
typedef enum lldc_auditlog_event {
    /* GUILD_UPDATE */
    LLDC_AE_GUILD_UPDATE = (1),
    /* CHANNEL_CREATE */
    LLDC_AE_CHANNEL_CREATE = (10),
    /* CHANNEL_UPDATE */
    LLDC_AE_CHANNEL_UPDATE = (11),
    /* CHANNEL_DELETE */
    LLDC_AE_CHANNEL_DELETE = (12),
    /* CHANNEL_OVERWRITE_CREATE */
    LLDC_AE_CHANNEL_OVERWRITE_CREATE = (13),
    /* CHANNEL_OVERWRITE_UPDATE */
    LLDC_AE_CHANNEL_OVERWRITE_UPDATE = (14),
    /* CHANNEL_OVERWRITE_DELETE */
    LLDC_AE_CHANNEL_OVERWRITE_DELETE = (15),
    /* MEMBER_KICK */
    LLDC_AE_MEMBER_KICK = (20),
    /* MEMBER_PRUNE */
    LLDC_AE_MEMBER_PRUNE = (21),
    /* MEMBER_BAN_ADD */
    LLDC_AE_MEMBER_BAN_ADD = (22),
    /* MEMBER_BAN_REMOVE */
    LLDC_AE_MEMBER_BAN_REMOVE = (23),
    /* MEMBER_UPDATE */
    LLDC_AE_MEMBER_UPDATE = (24),
    /* MEMBER_ROLE_UPDATE */
    LLDC_AE_MEMBER_ROLE_UPDATE = (25),
    /* MEMBER_MOVE */
    LLDC_AE_MEMBER_MOVE = (26),
    /* MEMBER_DISCONNECT */
    LLDC_AE_MEMBER_DISCONNECT = (27),
    /* BOT_ADD */
    LLDC_AE_BOT_ADD = (28),
    /* ROLE_CREATE */
    LLDC_AE_ROLE_CREATE = (30),
    /* ROLE_UPDATE */
    LLDC_AE_ROLE_UPDATE = (31),
    /* ROLE_DELETE */
    LLDC_AE_ROLE_DELETE = (32),
    /* INVITE_CREATE */
    LLDC_AE_INVITE_CREATE = (40),
    /* INVITE_UPDATE */
    LLDC_AE_INVITE_UPDATE = (41),
    /* INVITE_DELETE */
    LLDC_AE_INVITE_DELETE = (42),
    /* WEBHOOK_CREATE */
    LLDC_AE_WEBHOOK_CREATE = (50),
    /* WEBHOOK_UPDATE */
    LLDC_AE_WEBHOOK_UPDATE = (51),
    /* WEBHOOK_DELETE */
    LLDC_AE_WEBHOOK_DELETE = (52),
    /* EMOJI_CREATE */
    LLDC_AE_EMOJI_CREATE = (60),
    /* EMOJI_UPDATE */
    LLDC_AE_EMOJI_UPDATE = (61),
    /* EMOJI_DELETE */
    LLDC_AE_EMOJI_DELETE = (62),
    /* MESSAGE_DELETE */
    LLDC_AE_MESSAGE_DELETE = (72),
    /* MESSAGE_BULK_DELETE */
    LLDC_AE_MESSAGE_BULK_DELETE = (73),
    /* MESSAGE_PIN */
    LLDC_AE_MESSAGE_PIN = (74),
    /* MESSAGE_UNPIN */
    LLDC_AE_MESSAGE_UNPIN = (75),
    /* INTEGRATION_CREATE */
    LLDC_AE_INTEGRATION_CREATE = (80),
    /* INTEGRATION_UPDATE */
    LLDC_AE_INTEGRATION_UPDATE = (81),
    /* INTEGRATION_DELETE */
    LLDC_AE_INTEGRATION_DELETE = (82),
    /* STAGE_INSTANCE_CREATE */
    LLDC_AE_STAGE_INSTANCE_CREATE = (83),
    /* STAGE_INSTANCE_UPDATE */
    LLDC_AE_STAGE_INSTANCE_UPDATE = (84),
    /* STAGE_INSTANCE_DELETE */
    LLDC_AE_STAGE_INSTANCE_DELETE = (85),
    /* STICKER_CREATE */
    LLDC_AE_STICKER_CREATE = (90),
    /* STICKER_UPDATE */
    LLDC_AE_STICKER_UPDATE = (91),
    /* STICKER_DELETE */
    LLDC_AE_STICKER_DELETE = (92)
} lldc_auditlog_event_t;
typedef enum lldc_channel_overwrite_type {
    /* role */
    LLDC_CH_OVERWRITE_ROLE = (0),
    /* member */
    LLDC_CH_OVERWRITE_MEMBER = (1)
} lldc_channel_overwrite_type_t;
/* Allows creation of instant invites */
#define LLDC_PERMISSION_CREATE_INSTANT_INVITE (1 << 0)
/* Allows kicking members */
#define LLDC_PERMISSION_KICK_MEMBERS (1 << 1)
/* Allows banning members */
#define LLDC_PERMISSION_BAN_MEMBERS (1 << 2)
/* Allows all permissions and bypasses channel permission overwrites */
#define LLDC_PERMISSION_ADMINISTRATOR (1 << 3)
/* Allows management and editing of channels */
#define LLDC_PERMISSION_MANAGE_CHANNELS (1 << 4)
/* Allows management and editing of the guild */
#define LLDC_PERMISSION_MANAGE_GUILD (1 << 5)
/* Allows for the addition of reactions to messages */
#define LLDC_PERMISSION_ADD_REACTIONS (1 << 6)
/* Allows for viewing of audit logs */
#define LLDC_PERMISSION_VIEW_AUDIT_LOG (1 << 7)
/* Allows for using priority speaker in a voice channel */
#define LLDC_PERMISSION_PRIORITY_SPEAKER (1 << 8)
/* Allows the user to go live */
#define LLDC_PERMISSION_STREAM (1 << 9)
/* Allows guild members to view a channel, which includes reading messages in text channels */
#define LLDC_PERMISSION_VIEW_CHANNEL (1 << 10)
/* Allows for sending messages in a channel */
#define LLDC_PERMISSION_SEND_MESSAGES (1 << 11)
/* Allows for sending of /tts messages */
#define LLDC_PERMISSION_SEND_TTS_MESSAGES (1 << 12)
/* Allows for deletion of other users messages */
#define LLDC_PERMISSION_MANAGE_MESSAGES (1 << 13)
/* Links sent by users with this permission will be auto-embedded */
#define LLDC_PERMISSION_EMBED_LINKS (1 << 14)
/* Allows for uploading images and files */
#define LLDC_PERMISSION_ATTACH_FILES (1 << 15)
/* Allows for reading of message history */
#define LLDC_PERMISSION_READ_MESSAGE_HISTORY (1 << 16)
/* Allows for using the @everyone tag to notify all users in a channel, and the @here tag to notify all online users in a channel */
#define LLDC_PERMISSION_MENTION_EVERYONE (1 << 17)
/* Allows the usage of custom emojis from other servers */
#define LLDC_PERMISSION_USE_EXTERNAL_EMOJIS (1 << 18)
/* Allows for viewing guild insights */
#define LLDC_PERMISSION_VIEW_GUILD_INSIGHTS (1 << 19)
/* Allows for joining of a voice channel */
#define LLDC_PERMISSION_CONNECT (1 << 20)
/* Allows for speaking in a voice channel */
#define LLDC_PERMISSION_SPEAK (1 << 21)
/* Allows for muting members in a voice channel */
#define LLDC_PERMISSION_MUTE_MEMBERS (1 << 22)
/* Allows for deafening of members in a voice channel */
#define LLDC_PERMISSION_DEAFEN_MEMBERS (1 << 23)
/* Allows for moving of members between voice channels */
#define LLDC_PERMISSION_MOVE_MEMBERS (1 << 24)
/* Allows for using voice-activity-detection in a voice channel */
#define LLDC_PERMISSION_USE_VAD (1 << 25)
/* Allows for modification of own nickname */
#define LLDC_PERMISSION_CHANGE_NICKNAME (1 << 26)
/* Allows for modification of other users nicknames */
#define LLDC_PERMISSION_MANAGE_NICKNAMES (1 << 27)
/* Allows management and editing of roles */
#define LLDC_PERMISSION_MANAGE_ROLES (1 << 28)
/* Allows management and editing of webhooks */
#define LLDC_PERMISSION_MANAGE_WEBHOOKS (1 << 29)
/* Allows management and editing of emojis and stickers */
#define LLDC_PERMISSION_MANAGE_EMOJIS_AND_STICKERS (1 << 30)
/* Allows members to use slash commands in text channels */
#define LLDC_PERMISSION_USE_SLASH_COMMANDS (1 << 31)
/* Allows for requesting to speak in stage channels. (This permission is under active development and may be changed or removed.) */
#define LLDC_PERMISSION_REQUEST_TO_SPEAK (1 << 32)
/* Allows for deleting and archiving threads, and viewing all private threads */
#define LLDC_PERMISSION_MANAGE_THREADS (1 << 34)
/* Allows for creating and participating in threads */
#define LLDC_PERMISSION_USE_PUBLIC_THREADS (1 << 35)
/* Allows for creating and participating in private threads */
#define LLDC_PERMISSION_USE_PRIVATE_THREADS (1 << 36)
/* Allows the usage of custom stickers from other servers */
#define LLDC_PERMISSION_USE_EXTERNAL_STICKERS (1 << 37)
typedef enum lldc_channel_type {
    /* a text channel within a server */
    LLDC_CH_TYPE_GUILD_TEXT = (0),
    /* a direct message between users */
    LLDC_CH_TYPE_DM = (1),
    /* a voice channel within a server */
    LLDC_CH_TYPE_GUILD_VOICE = (2),
    /* a direct message between multiple users */
    LLDC_CH_TYPE_GROUP_DM = (3),
    /* an organizational category that contains up to 50 channels */
    LLDC_CH_TYPE_GUILD_CATEGORY = (4),
    /* a channel that users can follow and crosspost into their own server */
    LLDC_CH_TYPE_GUILD_NEWS = (5),
    /* a channel in which game developers can sell their game on Discord */
    LLDC_CH_TYPE_GUILD_STORE = (6),
    /* a temporary sub-channel within a GUILD_NEWS channel */
    LLDC_CH_TYPE_GUILD_NEWS_THREAD = (10),
    /* a temporary sub-channel within a GUILD_TEXT channel */
    LLDC_CH_TYPE_GUILD_PUBLIC_THREAD = (11),
    /* a temporary sub-channel within a GUILD_TEXT channel that is only viewable by those invited and those with the MANAGE_THREADS permission */
    LLDC_CH_TYPE_GUILD_PRIVATE_THREAD = (12),
    /* a voice channel for hosting events with an audience */
    LLDC_CH_TYPE_GUILD_STAGE_VOICE = (13)
} lldc_channel_type_t;
typedef enum lldc_channel_video_quality_mode {
    /* Discord chooses the quality for optimal performance */
    LLDC_QUALITY_AUTO = (1),
    /* 720p */
    LLDC_QUALITY_FULL = (2)
} lldc_channel_video_quality_mode_t;
/* Error Messages */
typedef struct lldc_discord_error_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_parser_malloc_ledger_t __mlog;
    /** 
     * Error code 
     */
    int code;
    /** 
     * JSON object
     * See the Developer page for info: https://discord.com/developers/docs/reference#error-messages 
     */
    yyjson_val *errors;
    /** 
     * Human readable error message 
     */
    const char *message;
} lldc_discord_error_t;
/* User Structure */
typedef struct lldc_user_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_parser_malloc_ledger_t __mlog;
    /** 
     * the user's id 
     */
    snowflake_t id;
    /** 
     * the user's username, not unique across the platform 
     */
    const char *username;
    /** 
     * the user's 4-digit discord-tag 
     */
    const char *discriminator;
    /** 
     * OPTIONAL: the user's avatar hash 
     */
    const char *avatar;
    /** 
     * whether the user belongs to an OAuth2 application 
     */
    int bot;
    /** 
     * whether the user is an Official Discord System user (part of the urgent message system) 
     */
    int system;
    /** 
     * whether the user has two factor enabled on their account 
     */
    int mfa_enabled;
    /** 
     * the user's chosen language option 
     */
    const char *locale;
    /** 
     * the flags on a user's account 
     */
    lldc_user_flag_t flags;
    /** 
     * the type of Nitro subscription on a user's account 
     */
    lldc_user_premium_t premium_type;
    /** 
     * the public flags on a user's account 
     */
    lldc_user_premium_t public_flags;
} lldc_user_t;
/* User Array */
typedef struct lldc_user_arr_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_user_t *items;
    size_t len;
    lldc_parser_malloc_ledger_t __mlog;
} lldc_user_arr_t;
/* OPTIONAL: the partial guild of the channel that this webhook is following (returned for Channel Follower Webhooks) */
typedef struct lldc_webhook_source_guild_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    /** 
     * guild id 
     */
    snowflake_t id;
    /** 
     * guild name (2-100 characters, excluding trailing and leading whitespace) 
     */
    const char *name;
    /** 
     * OPTIONAL: icon hash 
     */
    const char *icon;
} lldc_webhook_source_guild_t;
/* OPTIONAL: the partial channel that this webhook is following (returned for Channel Follower Webhooks) */
typedef struct lldc_webhook_source_channel_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    /** 
     * the id of this channel 
     */
    snowflake_t id;
    /** 
     * the name of the channel (1-100 characters) 
     */
    const char *name;
} lldc_webhook_source_channel_t;
/* Used to represent a webhook */
typedef struct lldc_webhook_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_parser_malloc_ledger_t __mlog;
    /** 
     * the id of the webhook 
     */
    snowflake_t id;
    /** 
     * the type of the webhook 
     */
    lldc_webhook_type_t type;
    /** 
     * OPTIONAL: the guild id this webhook is for, if any 
     */
    snowflake_t guild_id;
    /** 
     * OPTIONAL: the channel id this webhook is for, if any 
     */
    snowflake_t channel_id;
    /** 
     * OPTIONAL: the user this webhook was created by (not returned when getting a webhook with its token) 
     */
    lldc_user_t user;
    /** 
     * OPTIONAL: the default name of the webhook 
     */
    const char *name;
    /** 
     * OPTIONAL: the default user avatar hash of the webhook 
     */
    const char *avatar;
    /** 
     * OPTIONAL: the secure token of the webhook (returned for Incoming Webhooks) 
     */
    const char *token;
    /** 
     * OPTIONAL: the bot/OAuth2 application that created this webhook 
     */
    snowflake_t application_id;
    /** 
     * OPTIONAL: the partial guild of the channel that this webhook is following (returned for Channel Follower Webhooks) 
     */
    lldc_webhook_source_guild_t source_guild;
    /** 
     * OPTIONAL: the partial channel that this webhook is following (returned for Channel Follower Webhooks) 
     */
    lldc_webhook_source_channel_t source_channel;
    /** 
     * OPTIONAL: the url used for executing the webhook (returned by the webhooks OAuth2 flow) 
     */
    const char *url;
} lldc_webhook_t;
/* Webhook Array */
typedef struct lldc_webhook_arr_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_webhook_t *items;
    size_t len;
    lldc_parser_malloc_ledger_t __mlog;
} lldc_webhook_arr_t;
/* Integration Account Structure */
typedef struct lldc_interaction_account_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_parser_malloc_ledger_t __mlog;
    /** 
     * id of the account 
     */
    const char *id;
    /** 
     * name of the account 
     */
    const char *name;
} lldc_interaction_account_t;
/* audit log changes */
typedef struct lldc_audit_log_changes_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_parser_malloc_ledger_t __mlog;
    /** 
     * OPTIONAL: new value of the key 
     */
    yyjson_val *new_value;
    /** 
     * OPTIONAL: old value of the key 
     */
    yyjson_val *old_value;
    /** 
     * name of audit log change key 
     */
    const char *key;
} lldc_audit_log_changes_t;
/* Optional Audit Entry Info */
typedef struct lldc_audit_log_options_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_parser_malloc_ledger_t __mlog;
    /** 
     * number of days after which inactive members were kicked 
     */
    const char *delete_member_days;
    /** 
     * number of members removed by the prune 
     */
    const char *members_removed;
    /** 
     * channel in which the entities were targeted 
     */
    snowflake_t channel_id;
    /** 
     * id of the message that was targeted 
     */
    snowflake_t message_id;
    /** 
     * number of entities that were targeted 
     */
    const char *count;
    /** 
     * id of the overwritten entity 
     */
    snowflake_t id;
    /** 
     * type of overwritten entity - "0" for "role" or "1" for "member" 
     */
    const char *type;
    /** 
     * name of the role if type is "0" (not present if type is "1") 
     */
    const char *role_name;
} lldc_audit_log_options_t;
/* OPTIONAL: changes made to the target_id */
typedef struct lldc_audit_log_entry_changes_arr_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_audit_log_changes_t *items;
    size_t len;
} lldc_audit_log_entry_changes_arr_t;
/* audit log entry */
typedef struct lldc_audit_log_entry_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_parser_malloc_ledger_t __mlog;
    /** 
     * OPTIONAL: id of the affected entity (webhook, user, role, etc.) 
     */
    snowflake_t target_id;
    /** 
     * OPTIONAL: changes made to the target_id 
     */
    lldc_audit_log_entry_changes_arr_t changes;
    /** 
     * OPTIONAL: the user who made the changes 
     */
    snowflake_t user_id;
    /** 
     * id of the entry 
     */
    snowflake_t id;
    /** 
     * type of action that occured 
     */
    lldc_auditlog_event_t action_type;
    /** 
     * OPTIONAL: additional info for certain action types 
     */
    lldc_audit_log_options_t options;
    /** 
     * OPTIONAL: the reason for the change (0-512 characters) 
     */
    const char *reason;
} lldc_audit_log_entry_t;
/* partial integration objects */
typedef struct lldc_audit_log_integrations_item_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    /** 
     * integration id 
     */
    snowflake_t id;
    /** 
     * integration name 
     */
    const char *name;
    /** 
     * integration type (twitch, youtube, or discord) 
     */
    const char *type;
    /** 
     * integration account information 
     */
    lldc_interaction_account_t account;
} lldc_audit_log_integrations_item_t;
/* list of partial integration objects */
typedef struct lldc_audit_log_integrations_arr_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_audit_log_integrations_item_t *items;
    size_t len;
} lldc_audit_log_integrations_arr_t;
/* list of audit log entries */
typedef struct lldc_audit_log_audit_log_entries_arr_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_audit_log_entry_t *items;
    size_t len;
} lldc_audit_log_audit_log_entries_arr_t;
/* Audit Logs */
typedef struct lldc_audit_log_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_parser_malloc_ledger_t __mlog;
    /** 
     * list of webhooks found in the audit log 
     */
    lldc_webhook_arr_t webhooks;
    /** 
     * list of users found in the audit log 
     */
    lldc_user_arr_t users;
    /** 
     * list of partial integration objects 
     */
    lldc_audit_log_integrations_arr_t integrations;
    /** 
     * list of audit log entries 
     */
    lldc_audit_log_audit_log_entries_arr_t audit_log_entries;
} lldc_audit_log_t;
/* Represents a guild or DM channel within Discord */
typedef struct lldc_channel_overwrite_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_parser_malloc_ledger_t __mlog;
    /** 
     * role or user id 
     */
    snowflake_t id;
    /** 
     * either 0 (role) or 1 (member) 
     */
    lldc_channel_overwrite_type_t type;
    /** 
     * permission bit set 
     */
    uint64_t allow;
    /** 
     * permission bit set 
     */
    uint64_t deny;
} lldc_channel_overwrite_t;
/* Channel Overwrite Array */
typedef struct lldc_channel_overwrite_arr_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_channel_overwrite_t *items;
    size_t len;
    lldc_parser_malloc_ledger_t __mlog;
} lldc_channel_overwrite_arr_t;
/* The thread metadata object contains a number of thread-specific channel fields that are not needed by other channel types. */
typedef struct lldc_thread_metadata_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_parser_malloc_ledger_t __mlog;
    /** 
     * whether the thread is archived 
     */
    int archived;
    /** 
     * duration in minutes to automatically archive the thread after recent activity, can be set to: 60, 1440, 4320, 10080 
     */
    int auto_archive_duration;
    /** 
     * timestamp when the thread's archive status was last changed, used for calculating recent activity 
     */
    double archive_timestamp;
    /** 
     * OPTIONAL: whether the thread is locked; when a thread is locked, only users with MANAGE_THREADS can unarchive it 
     */
    int locked;
} lldc_thread_metadata_t;
/* A thread member is used to indicate whether a user has joined a thread or not. */
typedef struct lldc_thread_member_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_parser_malloc_ledger_t __mlog;
    /** 
     * OPTIONAL: the id of the thread 
     */
    snowflake_t id;
    /** 
     * OPTIONAL: the id of the user 
     */
    snowflake_t user_id;
    /** 
     * the time the current user last joined the thread 
     */
    double join_timestamp;
    /** 
     * any user-thread settings, currently only used for notifications 
     */
    int flags;
} lldc_thread_member_t;
/* Represents a guild or DM channel within Discord */
typedef struct lldc_channel_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_parser_malloc_ledger_t __mlog;
    /** 
     * the id of this channel 
     */
    snowflake_t id;
    /** 
     * the type of channel 
     */
    lldc_channel_type_t type;
    /** 
     * OPTIONAL: the id of the guild (may be missing for some channel objects received over gateway guild dispatches) 
     */
    snowflake_t guild_id;
    /** 
     * OPTIONAL: sorting position of the channel 
     */
    int position;
    /** 
     * OPTIONAL: explicit permission overwrites for members and roles 
     */
    lldc_channel_overwrite_arr_t permission_overwrites;
    /** 
     * OPTIONAL: the name of the channel (1-100 characters) 
     */
    const char *name;
    /** 
     * OPTIONAL: the channel topic (0-1024 characters) 
     */
    const char *topic;
    /** 
     * OPTIONAL: whether the channel is nsfw 
     */
    int nsfw;
    /** 
     * OPTIONAL: the id of the last message sent in this channel (may not point to an existing or valid message) 
     */
    snowflake_t last_message_id;
    /** 
     * OPTIONAL: the bitrate (in bits) of the voice channel 
     */
    int bitrate;
    /** 
     * OPTIONAL: the user limit of the voice channel 
     */
    int user_limit;
    /** 
     * OPTIONAL: amount of seconds a user has to wait before sending another message (0-21600); bots, as well as users with the permission manage_messages or manage_channel, are unaffected 
     */
    int rate_limit_per_user;
    /** 
     * OPTIONAL: the recipients of the DM 
     */
    lldc_user_arr_t recipients;
    /** 
     * OPTIONAL: icon hash 
     */
    const char *icon;
    /** 
     * OPTIONAL: id of the creator of the group DM or thread 
     */
    snowflake_t owner_id;
    /** 
     * OPTIONAL: application id of the group DM creator if it is bot-created 
     */
    snowflake_t application_id;
    /** 
     * OPTIONAL: for guild channels: id of the parent category for a channel (each parent category can contain up to 50 channels), for threads: id of the text channel this thread was created 
     */
    snowflake_t parent_id;
    /** 
     * OPTIONAL: when the last pinned message was pinned. This may be null in events such as GUILD_CREATE when a message is not pinned. 
     */
    double last_pin_timestamp;
    /** 
     * OPTIONAL: voice region id for the voice channel, automatic when set to null 
     */
    const char *rtc_region;
    /** 
     * OPTIONAL: the camera video quality mode of the voice channel, 1 when not present 
     */
    lldc_channel_video_quality_mode_t video_quality_mode;
    /** 
     * OPTIONAL: an approximate count of messages in a thread, stops counting at 50 
     */
    int message_count;
    /** 
     * OPTIONAL: an approximate count of users in a thread, stops counting at 50 
     */
    int member_count;
    /** 
     * OPTIONAL: thread-specific fields not needed by other channels 
     */
    lldc_thread_metadata_t thread_metadata;
    /** 
     * OPTIONAL: thread member object for the current user, if they have joined the thread, only included on certain API endpoints 
     */
    lldc_thread_member_t member;
    /** 
     * OPTIONAL: default duration for newly created threads, in minutes, to automatically archive the thread after recent activity, can be set to: 60, 1440, 4320, 10080 
     */
    int default_auto_archive_duration;
    /** 
     * OPTIONAL: computed permissions for the invoking user in the channel, including overwrites, only included when part of the resolved data received on a slash command interaction 
     */
    uint64_t permissions;
} lldc_channel_t;
/**
* Discord Error Parser
* Error Messages
*/
int lldc_discord_error_parse (cwr_malloc_ctx_t *_mctx, lldc_discord_error_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* User Parser
* User Structure
*/
int lldc_user_parse (cwr_malloc_ctx_t *_mctx, lldc_user_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* User Parser
* User Array
*/
int lldc_user_arr_parse (cwr_malloc_ctx_t *_mctx, lldc_user_arr_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Webhook Parser
* Used to represent a webhook
*/
int lldc_webhook_parse (cwr_malloc_ctx_t *_mctx, lldc_webhook_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Webhook Parser
* Webhook Array
*/
int lldc_webhook_arr_parse (cwr_malloc_ctx_t *_mctx, lldc_webhook_arr_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Interaction Account Parser
* Integration Account Structure
*/
int lldc_interaction_account_parse (cwr_malloc_ctx_t *_mctx, lldc_interaction_account_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Audit Log Changes Parser
* audit log changes
*/
int lldc_audit_log_changes_parse (cwr_malloc_ctx_t *_mctx, lldc_audit_log_changes_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Audit Log Options Parser
* Optional Audit Entry Info
*/
int lldc_audit_log_options_parse (cwr_malloc_ctx_t *_mctx, lldc_audit_log_options_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Audit Log Entry Parser
* audit log entry
*/
int lldc_audit_log_entry_parse (cwr_malloc_ctx_t *_mctx, lldc_audit_log_entry_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Audit Log Parser
* Audit Logs
*/
int lldc_audit_log_parse (cwr_malloc_ctx_t *_mctx, lldc_audit_log_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Channel Overwrite Parser
* Represents a guild or DM channel within Discord
*/
int lldc_channel_overwrite_parse (cwr_malloc_ctx_t *_mctx, lldc_channel_overwrite_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Channel Overwrite Parser
* Channel Overwrite Array
*/
int lldc_channel_overwrite_arr_parse (cwr_malloc_ctx_t *_mctx, lldc_channel_overwrite_arr_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Thread Metadata Parser
* The thread metadata object contains a number of thread-specific channel fields that are not needed by other channel types.
*/
int lldc_thread_metadata_parse (cwr_malloc_ctx_t *_mctx, lldc_thread_metadata_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Thread Member Parser
* A thread member is used to indicate whether a user has joined a thread or not.
*/
int lldc_thread_member_parse (cwr_malloc_ctx_t *_mctx, lldc_thread_member_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Channel Parser
* Represents a guild or DM channel within Discord
*/
int lldc_channel_parse (cwr_malloc_ctx_t *_mctx, lldc_channel_t *obj, yyjson_val *json, int has_existing_ledger);
#endif