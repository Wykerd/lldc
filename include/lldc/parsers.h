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
/* Component Structure */
typedef struct lldc_component_s lldc_component_t;
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
typedef enum lldc_application_member_state {
    /* INVITED */
    LLDC_APP_MS_INVITED = (1),
    /* ACCEPTED */
    LLDC_APP_MS_ACCEPTED = (2)
} lldc_application_member_state_t;
typedef enum lldc_application_flags {
    /* GATEWAY_PRESENCE */
    LLDC_APP_FLAG_GATEWAY_PRESENCE = (1 << 12),
    /* GATEWAY_PRESENCE_LIMITED */
    LLDC_APP_FLAG_GATEWAY_PRESENCE_LIMITED = (1 << 13),
    /* GATEWAY_GUILD_MEMBERS */
    LLDC_APP_FLAG_GATEWAY_GUILD_MEMBERS = (1 << 14),
    /* GATEWAY_GUILD_MEMBERS_LIMITED */
    LLDC_APP_FLAG_GATEWAY_GUILD_MEMBERS_LIMITED = (1 << 15),
    /* VERIFICATION_PENDING_GUILD_LIMIT */
    LLDC_APP_FLAG_VERIFICATION_PENDING_GUILD_LIMIT = (1 << 16),
    /* EMBEDDED */
    LLDC_APP_FLAG_EMBEDDED = (1 << 17)
} lldc_application_flags_t;
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
typedef enum lldc_component_type {
    /* A container for other components */
    LLDC_COMPONENT_ACTION_ROW = (1),
    /* A button object */
    LLDC_COMPONENT_BUTTON = (2),
    /* A select menu for picking from choices */
    LLDC_COMPONENT_SELECT_MENU = (3)
} lldc_component_type_t;
typedef enum lldc_component_style {
    /* blurple */
    LLDC_COMPONENT_STYLE_PRIMARY = (1),
    /* grey */
    LLDC_COMPONENT_STYLE_SECONDARY = (2),
    /* green */
    LLDC_COMPONENT_STYLE_SUCCESS = (3),
    /* red */
    LLDC_COMPONENT_STYLE_DANGER = (4),
    /* grey, navigates to a URL */
    LLDC_COMPONENT_STYLE_LINK = (5)
} lldc_component_style_t;
typedef enum lldc_sticker_type {
    /* an official sticker in a pack, part of Nitro or in a removed purchasable pack */
    LLDC_STICKER_TYPE_STANDARD = (1),
    /* a sticker uploaded to a Boosted guild for the guild's members */
    LLDC_STICKER_TYPE_GUILD = (2)
} lldc_sticker_type_t;
typedef enum lldc_sticker_format {
    /* PNG */
    LLDC_STICKER_FORMAT_PNG = (1),
    /* APNG */
    LLDC_STICKER_FORMAT_APNG = (2),
    /* LOTTIE */
    LLDC_STICKER_FORMAT_LOTTIE = (3)
} lldc_sticker_format_t;
typedef enum lldc_message_activity_type {
    /* JOIN */
    LLDC_MSG_ACTIVITY_JOIN = (1),
    /* SPECTATE */
    LLDC_MSG_ACTIVITY_SPECTATE = (2),
    /* LISTEN */
    LLDC_MSG_ACTIVITY_LISTEN = (3),
    /* JOIN_REQUEST */
    LLDC_MSG_ACTIVITY_JOIN_REQUEST = (5)
} lldc_message_activity_type_t;
typedef enum lldc_message_type {
    /* DEFAULT */
    LLDC_MSG_DEFAULT = (0),
    /* RECIPIENT_ADD */
    LLDC_MSG_RECIPIENT_ADD = (1),
    /* RECIPIENT_REMOVE */
    LLDC_MSG_RECIPIENT_REMOVE = (2),
    /* CALL */
    LLDC_MSG_CALL = (3),
    /* CHANNEL_NAME_CHANGE */
    LLDC_MSG_CHANNEL_NAME_CHANGE = (4),
    /* CHANNEL_ICON_CHANGE */
    LLDC_MSG_CHANNEL_ICON_CHANGE = (5),
    /* CHANNEL_PINNED_MESSAGE */
    LLDC_MSG_CHANNEL_PINNED_MESSAGE = (6),
    /* GUILD_MEMBER_JOIN */
    LLDC_MSG_GUILD_MEMBER_JOIN = (7),
    /* USER_PREMIUM_GUILD_SUBSCRIPTION */
    LLDC_MSG_USER_PREMIUM_GUILD_SUBSCRIPTION = (8),
    /* USER_PREMIUM_GUILD_SUBSCRIPTION_TIER_1 */
    LLDC_MSG_USER_PREMIUM_GUILD_SUBSCRIPTION_TIER_1 = (9),
    /* USER_PREMIUM_GUILD_SUBSCRIPTION_TIER_2 */
    LLDC_MSG_USER_PREMIUM_GUILD_SUBSCRIPTION_TIER_2 = (10),
    /* USER_PREMIUM_GUILD_SUBSCRIPTION_TIER_3 */
    LLDC_MSG_USER_PREMIUM_GUILD_SUBSCRIPTION_TIER_3 = (11),
    /* CHANNEL_FOLLOW_ADD */
    LLDC_MSG_CHANNEL_FOLLOW_ADD = (12),
    /* GUILD_DISCOVERY_DISQUALIFIED */
    LLDC_MSG_GUILD_DISCOVERY_DISQUALIFIED = (14),
    /* GUILD_DISCOVERY_REQUALIFIED */
    LLDC_MSG_GUILD_DISCOVERY_REQUALIFIED = (15),
    /* GUILD_DISCOVERY_GRACE_PERIOD_INITIAL_WARNING */
    LLDC_MSG_GUILD_DISCOVERY_GRACE_PERIOD_INITIAL_WARNING = (16),
    /* GUILD_DISCOVERY_GRACE_PERIOD_FINAL_WARNING */
    LLDC_MSG_GUILD_DISCOVERY_GRACE_PERIOD_FINAL_WARNING = (17),
    /* THREAD_CREATED */
    LLDC_MSG_THREAD_CREATED = (18),
    /* REPLY */
    LLDC_MSG_REPLY = (19),
    /* APPLICATION_COMMAND */
    LLDC_MSG_APPLICATION_COMMAND = (20),
    /* THREAD_STARTER_MESSAGE */
    LLDC_MSG_THREAD_STARTER_MESSAGE = (21),
    /* GUILD_INVITE_REMINDER */
    LLDC_MSG_GUILD_INVITE_REMINDER = (22)
} lldc_message_type_t;
typedef enum lldc_message_flags {
    /* this message has been published to subscribed channels (via Channel Following) */
    LLDC_MSG_FLAG_CROSSPOSTED = (1 << 0),
    /* this message originated from a message in another channel (via Channel Following) */
    LLDC_MSG_FLAG_IS_CROSSPOST = (1 << 1),
    /* do not include any embeds when serializing this message */
    LLDC_MSG_FLAG_SUPPRESS_EMBEDS = (1 << 2),
    /* the source message for this crosspost has been deleted (via Channel Following) */
    LLDC_MSG_FLAG_SOURCE_MESSAGE_DELETED = (1 << 3),
    /* this message came from the urgent message system */
    LLDC_MSG_FLAG_URGENT = (1 << 4),
    /* this message has an associated thread, with the same id as the message */
    LLDC_MSG_FLAG_HAS_THREAD = (1 << 5),
    /* this message is only visible to the user who invoked the Interaction */
    LLDC_MSG_FLAG_EPHEMERAL = (1 << 6),
    /* this message is an Interaction Response and the bot is "thinking" */
    LLDC_MSG_FLAG_LOADING = (1 << 7)
} lldc_message_flags_t;
/* Controls role mentions */
#define LLDC_ALLOWED_MENTION_ROLE_MENTIONS "roles"
/* Controls user mentions */
#define LLDC_ALLOWED_MENTION_USER_MENTIONS "users"
/* Controls @everyone and @here mentions */
#define LLDC_ALLOWED_MENTION_EVERYONE_MENTIONS "everyone"
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
typedef enum lldc_activity_type {
    /* Game */
    LLDC_ACTIVITY_GAME = (0),
    /* Streaming */
    LLDC_ACTIVITY_STREAMING = (1),
    /* Listening */
    LLDC_ACTIVITY_LISTENING = (2),
    /* Watching */
    LLDC_ACTIVITY_WATCHING = (3),
    /* Custom */
    LLDC_ACTIVITY_CUSTOM = (4),
    /* Competing */
    LLDC_ACTIVITY_COMPETING = (5)
} lldc_activity_type_t;
typedef enum lldc_activity_flags {
    /* INSTANCE */
    LLDC_ACTIVITY_FLAGS_INSTANCE = (1 << 0),
    /* JOIN */
    LLDC_ACTIVITY_FLAGS_JOIN = (1 << 1),
    /* SPECTATE */
    LLDC_ACTIVITY_FLAGS_SPECTATE = (1 << 2),
    /* JOIN_REQUEST */
    LLDC_ACTIVITY_FLAGS_JOIN_REQUEST = (1 << 3),
    /* SYNC */
    LLDC_ACTIVITY_FLAGS_SYNC = (1 << 4),
    /* PLAY */
    LLDC_ACTIVITY_FLAGS_PLAY = (1 << 5)
} lldc_activity_flags_t;
/* ONLINE */
#define LLDC_CLIENT_STATUS_ONLINE "online"
/* IDLE */
#define LLDC_CLIENT_STATUS_IDLE "idle"
/* DND */
#define LLDC_CLIENT_STATUS_DND "dnd"
typedef enum lldc_stage_instance_privacy_level {
    /* The Stage instance is visible publicly, such as on Stage discovery. */
    LLDC_STAGE_INSTANCE_PRIVACY_PUBLIC = (1),
    /* The Stage instance is visible to only guild members. */
    LLDC_STAGE_INSTANCE_PRIVACY_GUILD_ONLY = (2)
} lldc_stage_instance_privacy_level_t;
/* guild has access to set an animated guild icon */
#define LLDC_GUILD_FEATURE_ANIMATED_ICON "ANIMATED_ICON"
/* guild has access to set a guild banner image */
#define LLDC_GUILD_FEATURE_BANNER "BANNER"
/* guild has access to use commerce features (i.e. create store channels) */
#define LLDC_GUILD_FEATURE_COMMERCE "COMMERCE"
/* guild can enable welcome screen, Membership Screening, stage channels and discovery, and receives community updates */
#define LLDC_GUILD_FEATURE_COMMUNITY "COMMUNITY"
/* guild is able to be discovered in the directory */
#define LLDC_GUILD_FEATURE_DISCOVERABLE "DISCOVERABLE"
/* guild is able to be featured in the directory */
#define LLDC_GUILD_FEATURE_FEATURABLE "FEATURABLE"
/* guild has access to set an invite splash background */
#define LLDC_GUILD_FEATURE_INVITE_SPLASH "INVITE_SPLASH"
/* guild has enabled Membership Screening */
#define LLDC_GUILD_FEATURE_MEMBER_VERIFICATION_GATE_ENABLED "MEMBER_VERIFICATION_GATE_ENABLED"
/* guild has access to create news channels */
#define LLDC_GUILD_FEATURE_NEWS "NEWS"
/* guild is partnered */
#define LLDC_GUILD_FEATURE_PARTNERED "PARTNERED"
/* guild can be previewed before joining via Membership Screening or the directory */
#define LLDC_GUILD_FEATURE_PREVIEW_ENABLED "PREVIEW_ENABLED"
/* guild has access to set a vanity URL */
#define LLDC_GUILD_FEATURE_VANITY_URL "VANITY_URL"
/* guild is verified */
#define LLDC_GUILD_FEATURE_VERIFIED "VERIFIED"
/* guild has access to set 384kbps bitrate in voice (previously VIP voice servers) */
#define LLDC_GUILD_FEATURE_VIP_REGIONS "VIP_REGIONS"
/* guild has enabled the welcome screen */
#define LLDC_GUILD_FEATURE_WELCOME_SCREEN_ENABLED "WELCOME_SCREEN_ENABLED"
/* guild has enabled ticketed events */
#define LLDC_GUILD_FEATURE_TICKETED_EVENTS_ENABLED "TICKETED_EVENTS_ENABLED"
/* guild has enabled monetization */
#define LLDC_GUILD_FEATURE_MONETIZATION_ENABLED "MONETIZATION_ENABLED"
/* guild has increased custom sticker slots */
#define LLDC_GUILD_FEATURE_MORE_STICKERS "MORE_STICKERS"
/* guild has access to the three day archive time for threads */
#define LLDC_GUILD_FEATURE_THREE_DAY_THREAD_ARCHIVE "THREE_DAY_THREAD_ARCHIVE"
/* guild has access to the seven day archive time for threads */
#define LLDC_GUILD_FEATURE_SEVEN_DAY_THREAD_ARCHIVE "SEVEN_DAY_THREAD_ARCHIVE"
/* guild has access to create private threads */
#define LLDC_GUILD_FEATURE_PRIVATE_THREADS "PRIVATE_THREADS"
typedef enum lldc_integration_expire_behavior {
    /* Remove role */
    LLDC_INTEGRATION_EXPIRE_REMOVE_ROLE = (0),
    /* Kick */
    LLDC_INTEGRATION_EXPIRE_KICK = (1)
} lldc_integration_expire_behavior_t;
typedef enum lldc_guild_verification_level {
    /* unrestricted */
    LLDC_VERIFICATION_LEVEL_NONE = (0),
    /* must have verified email on account */
    LLDC_VERIFICATION_LEVEL_LOW = (1),
    /* must be registered on Discord for longer than 5 minutes */
    LLDC_VERIFICATION_LEVEL_MEDIUM = (2),
    /* must be a member of the server for longer than 10 minutes */
    LLDC_VERIFICATION_LEVEL_HIGH = (3),
    /* must have a verified phone number */
    LLDC_VERIFICATION_LEVEL_VERY_HIGH = (4)
} lldc_guild_verification_level_t;
typedef enum lldc_guild_message_notifications_level {
    /* members will receive notifications for all messages by default */
    LLDC_MSG_NOTIFICATION_ALL_MESSAGES = (0),
    /* members will receive notifications only for messages that @mention them by default */
    LLDC_MSG_NOTIFICATION_ONLY_MENTIONS = (1)
} lldc_guild_message_notifications_level_t;
typedef enum lldc_guild_explicit_content_filter_level {
    /* media content will not be scanned */
    LLDC_EXPLICIT_FILTER_DISABLED = (0),
    /* media content sent by members without roles will be scanned */
    LLDC_EXPLICIT_FILTER_MEMBERS_WITHOUT_ROLES = (1),
    /* media content sent by all members will be scanned */
    LLDC_EXPLICIT_FILTER_ALL_MEMBERS = (2)
} lldc_guild_explicit_content_filter_level_t;
typedef enum lldc_guild_mfa_level {
    /* guild has no MFA/2FA requirement for moderation actions */
    LLDC_MFA_NONE = (0),
    /* guild has a 2FA requirement for moderation actions */
    LLDC_MFA_ELEVATED = (1)
} lldc_guild_mfa_level_t;
typedef enum lldc_guild_system_channel_flags {
    /* Suppress member join notifications */
    LLDC_GUILD_SYSTEM_SUPPRESS_JOIN_NOTIFICATIONS = (1 << 0),
    /* Suppress server boost notifications */
    LLDC_GUILD_SYSTEM_SUPPRESS_PREMIUM_SUBSCRIPTIONS = (1 << 1),
    /* Suppress server setup tips */
    LLDC_GUILD_SYSTEM_SUPPRESS_GUILD_REMINDER_NOTIFICATIONS = (1 << 2)
} lldc_guild_system_channel_flags_t;
typedef enum lldc_guild_premium_tier {
    /* guild has not unlocked any Server Boost perks */
    LLDC_GUILD_PREMIUM_NONE = (0),
    /* guild has unlocked Server Boost level 1 perks */
    LLDC_GUILD_PREMIUM_TIER_1 = (1),
    /* guild has unlocked Server Boost level 2 perks */
    LLDC_GUILD_PREMIUM_TIER_2 = (2),
    /* guild has unlocked Server Boost level 3 perks */
    LLDC_GUILD_PREMIUM_TIER_3 = (3)
} lldc_guild_premium_tier_t;
typedef enum lldc_guild_nsfw_level {
    /* DEFAULT */
    LLDC_GUILD_NSFW_DEFAULT = (0),
    /* EXPLICIT */
    LLDC_GUILD_NSFW_EXPLICIT = (1),
    /* SAFE */
    LLDC_GUILD_NSFW_SAFE = (2),
    /* AGE_RESTRICTED */
    LLDC_GUILD_NSFW_AGE_RESTRICTED = (3)
} lldc_guild_nsfw_level_t;
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
/* Team Member Object */
typedef struct lldc_team_member_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_parser_malloc_ledger_t __mlog;
    /** 
     * the user's membership state on the team 
     */
    lldc_application_member_state_t membership_state;
    /** 
     * the id of the parent team of which they are a member 
     */
    snowflake_t team_id;
    /** 
     * the avatar, discriminator, id, and username of the user 
     */
    lldc_user_t user;
} lldc_team_member_t;
/* Team Member Array */
typedef struct lldc_team_member_arr_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_team_member_t *items;
    size_t len;
    lldc_parser_malloc_ledger_t __mlog;
} lldc_team_member_arr_t;
/* Team Object */
typedef struct lldc_team_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_parser_malloc_ledger_t __mlog;
    /** 
     * OPTIONAL: a hash of the image of the team's icon 
     */
    const char *icon;
    /** 
     * the unique id of the team 
     */
    snowflake_t id;
    /** 
     * the members of the team 
     */
    lldc_team_member_arr_t members;
    /** 
     * the name of the team 
     */
    const char *name;
    /** 
     * the user id of the current team owner 
     */
    snowflake_t owner_user_id;
} lldc_team_t;
/* Application Structure */
typedef struct lldc_application_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_parser_malloc_ledger_t __mlog;
    /** 
     * the id of the app 
     */
    snowflake_t id;
    /** 
     * the name of the app 
     */
    const char *name;
    /** 
     * OPTIONAL: the icon hash of the app 
     */
    const char *icon;
    /** 
     * the description of the app 
     */
    const char *description;
    /** 
     * OPTIONAL: an array of rpc origin urls, if rpc is enabled 
     */
    lldc_parser_string_arr_t rpc_origins;
    /** 
     * when false only app owner can join the app's bot to guilds 
     */
    int bot_public;
    /** 
     * when true the app's bot will only join upon completion of the full oauth2 code grant flow 
     */
    int bot_require_code_grant;
    /** 
     * OPTIONAL: the url of the app's terms of service 
     */
    const char *terms_of_service_url;
    /** 
     * OPTIONAL: the url of the app's privacy policy 
     */
    const char *privacy_policy_url;
    /** 
     * OPTIONAL: partial user object containing info on the owner of the application 
     */
    lldc_user_t owner;
    /** 
     * if this application is a game sold on Discord, this field will be the summary field for the store page of its primary sku 
     */
    const char *summary;
    /** 
     * the hex encoded key for verification in interactions and the GameSDK's GetTicket 
     */
    const char *verify_key;
    /** 
     * OPTIONAL: if the application belongs to a team, this will be a list of the members of that team 
     */
    lldc_team_t team;
    /** 
     * OPTIONAL: if this application is a game sold on Discord, this field will be the guild to which it has been linked 
     */
    snowflake_t guild_id;
    /** 
     * OPTIONAL: if this application is a game sold on Discord, this field will be the id of the "Game SKU" that is created, if exists 
     */
    snowflake_t primary_sku_id;
    /** 
     * OPTIONAL: if this application is a game sold on Discord, this field will be the URL slug that links to the store page 
     */
    const char *slug;
    /** 
     * OPTIONAL: the application's default rich presence invite cover image hash 
     */
    const char *cover_image;
    /** 
     * OPTIONAL: the application's public flags 
     */
    lldc_application_flags_t flags;
} lldc_application_t;
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
/* Guild Member */
typedef struct lldc_guild_member_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_parser_malloc_ledger_t __mlog;
    /** 
     * OPTIONAL: the user this guild member represents 
     */
    lldc_user_t user;
    /** 
     * OPTIONAL: this users guild nickname 
     */
    const char *nick;
    /** 
     * array of role object ids 
     */
    lldc_parser_snowflake_arr_t roles;
    /** 
     * when the user joined the guild 
     */
    double joined_at;
    /** 
     * OPTIONAL: when the user started boosting the guild 
     */
    double premium_since;
    /** 
     * whether the user is deafened in voice channels 
     */
    int deaf;
    /** 
     * whether the user is muted in voice channels 
     */
    int mute;
    /** 
     * OPTIONAL: whether the user has not yet passed the guild's Membership Screening requirements 
     */
    int pending;
    /** 
     * OPTIONAL: total permissions of the member in the channel, including overwrites, returned when in the interaction object 
     */
    uint64_t permissions;
} lldc_guild_member_t;
/* Guild Member Array */
typedef struct lldc_guild_member_arr_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_guild_member_t *items;
    size_t len;
    lldc_parser_malloc_ledger_t __mlog;
} lldc_guild_member_arr_t;
/* Partial Guild Member (excluding user) */
typedef struct lldc_partial_guild_member_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_parser_malloc_ledger_t __mlog;
    /** 
     * OPTIONAL: this users guild nickname 
     */
    const char *nick;
    /** 
     * array of role object ids 
     */
    lldc_parser_snowflake_arr_t roles;
    /** 
     * when the user joined the guild 
     */
    double joined_at;
    /** 
     * OPTIONAL: when the user started boosting the guild 
     */
    double premium_since;
    /** 
     * whether the user is deafened in voice channels 
     */
    int deaf;
    /** 
     * whether the user is muted in voice channels 
     */
    int mute;
    /** 
     * OPTIONAL: whether the user has not yet passed the guild's Membership Screening requirements 
     */
    int pending;
    /** 
     * OPTIONAL: total permissions of the member in the channel, including overwrites, returned when in the interaction object 
     */
    uint64_t permissions;
} lldc_partial_guild_member_t;
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
/* Role Tags Structure */
typedef struct lldc_role_tags_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_parser_malloc_ledger_t __mlog;
    /** 
     * OPTIONAL: the id of the bot this role belongs to 
     */
    snowflake_t bot_id;
    /** 
     * OPTIONAL: the id of the integration this role belongs to 
     */
    snowflake_t integration_id;
} lldc_role_tags_t;
/* Roles represent a set of permissions attached to a group of users. Roles have unique names, colors, and can be "pinned" to the side bar, causing their members to be listed separately. Roles are unique per guild, and can have separate permission profiles for the global context (guild) and channel context. The @everyone role has the same ID as the guild it belongs to. */
typedef struct lldc_role_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_parser_malloc_ledger_t __mlog;
    /** 
     * role id 
     */
    snowflake_t id;
    /** 
     * role name 
     */
    const char *name;
    /** 
     * integer representation of hexadecimal color code 
     */
    int color;
    /** 
     * if this role is pinned in the user listing 
     */
    int hoist;
    /** 
     * position of this role 
     */
    int position;
    /** 
     * permission bit set 
     */
    uint64_t permissions;
    /** 
     * whether this role is managed by an integration 
     */
    int managed;
    /** 
     * whether this role is mentionable 
     */
    int mentionable;
    /** 
     * OPTIONAL: the tags this role has 
     */
    lldc_role_tags_t tags;
} lldc_role_t;
/* Role Array */
typedef struct lldc_role_arr_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_role_t *items;
    size_t len;
    lldc_parser_malloc_ledger_t __mlog;
} lldc_role_arr_t;
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
/* Attachment Structure */
typedef struct lldc_attachment_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_parser_malloc_ledger_t __mlog;
    /** 
     * attachment id 
     */
    snowflake_t id;
    /** 
     * name of file attached 
     */
    const char *filename;
    /** 
     * OPTIONAL: the attachment's media type 
     */
    const char *content_type;
    /** 
     * size of file in bytes 
     */
    int size;
    /** 
     * source url of file 
     */
    const char *url;
    /** 
     * a proxied url of file 
     */
    const char *proxy_url;
    /** 
     * OPTIONAL: height of file (if image) 
     */
    int height;
    /** 
     * OPTIONAL: width of file (if image) 
     */
    int width;
} lldc_attachment_t;
/* Attachment Array */
typedef struct lldc_attachment_arr_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_attachment_t *items;
    size_t len;
    lldc_parser_malloc_ledger_t __mlog;
} lldc_attachment_arr_t;
/* Channel Mention Structure */
typedef struct lldc_channel_mention_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_parser_malloc_ledger_t __mlog;
    /** 
     * id of the channel 
     */
    snowflake_t id;
    /** 
     * id of the guild containing the channel 
     */
    snowflake_t guild_id;
    /** 
     * the type of channel 
     */
    int type;
    /** 
     * the name of the channel 
     */
    const char *name;
} lldc_channel_mention_t;
/* Channel Mention Array */
typedef struct lldc_channel_mention_arr_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_channel_mention_t *items;
    size_t len;
    lldc_parser_malloc_ledger_t __mlog;
} lldc_channel_mention_arr_t;
/* Embed Author Structure */
typedef struct lldc_embed_author_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_parser_malloc_ledger_t __mlog;
    /** 
     * OPTIONAL: name of author 
     */
    const char *name;
    /** 
     * OPTIONAL: url of author 
     */
    const char *url;
    /** 
     * OPTIONAL: url of author icon (only supports http(s) and attachments) 
     */
    const char *icon_url;
    /** 
     * OPTIONAL: a proxied url of author icon 
     */
    const char *proxy_icon_url;
} lldc_embed_author_t;
/* Embed Footer Structure */
typedef struct lldc_embed_footer_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_parser_malloc_ledger_t __mlog;
    /** 
     * footer text 
     */
    const char *text;
    /** 
     * OPTIONAL: url of footer icon (only supports http(s) and attachments) 
     */
    const char *icon_url;
    /** 
     * OPTIONAL: a proxied url of footer icon 
     */
    const char *proxy_icon_url;
} lldc_embed_footer_t;
/* Embed Image Structure */
typedef struct lldc_embed_image_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_parser_malloc_ledger_t __mlog;
    /** 
     * OPTIONAL: source url of image (only supports http(s) and attachments) 
     */
    const char *url;
    /** 
     * OPTIONAL: a proxied url of the image 
     */
    const char *proxy_url;
    /** 
     * OPTIONAL: height of image 
     */
    int height;
    /** 
     * OPTIONAL: width of image 
     */
    int width;
} lldc_embed_image_t;
/* Embed Provider Structure */
typedef struct lldc_embed_provider_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_parser_malloc_ledger_t __mlog;
    /** 
     * OPTIONAL: name of provider 
     */
    const char *name;
    /** 
     * OPTIONAL: url of provider 
     */
    const char *url;
} lldc_embed_provider_t;
/* Embed Thumbnail Structure */
typedef struct lldc_embed_thumbnail_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_parser_malloc_ledger_t __mlog;
    /** 
     * OPTIONAL: source url of thumbnail (only supports http(s) and attachments) 
     */
    const char *url;
    /** 
     * OPTIONAL: a proxied url of the thumbnail 
     */
    const char *proxy_url;
    /** 
     * OPTIONAL: height of thumbnail 
     */
    int height;
    /** 
     * OPTIONAL: width of thumbnail 
     */
    int width;
} lldc_embed_thumbnail_t;
/* Embed Video Structure */
typedef struct lldc_embed_video_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_parser_malloc_ledger_t __mlog;
    /** 
     * OPTIONAL: source url of video 
     */
    const char *url;
    /** 
     * OPTIONAL: a proxied url of the video 
     */
    const char *proxy_url;
    /** 
     * OPTIONAL: height of video 
     */
    int height;
    /** 
     * OPTIONAL: width of video 
     */
    int width;
} lldc_embed_video_t;
/* Embed Field Structure */
typedef struct lldc_embed_field_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_parser_malloc_ledger_t __mlog;
    /** 
     * name of the field 
     */
    const char *name;
    /** 
     * value of the field 
     */
    const char *value;
    /** 
     * OPTIONAL: whether or not this field should display inline 
     */
    int is_inline;
} lldc_embed_field_t;
/* Embed Field Array */
typedef struct lldc_embed_field_arr_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_embed_field_t *items;
    size_t len;
    lldc_parser_malloc_ledger_t __mlog;
} lldc_embed_field_arr_t;
/* Embed Structure */
typedef struct lldc_embed_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_parser_malloc_ledger_t __mlog;
    /** 
     * OPTIONAL: title of embed 
     */
    const char *title;
    /** 
     * OPTIONAL: type of embed (always "rich" for webhook embeds) 
     */
    const char *type;
    /** 
     * OPTIONAL: description of embed 
     */
    const char *description;
    /** 
     * OPTIONAL: url of embed 
     */
    const char *url;
    /** 
     * OPTIONAL: timestamp of embed content 
     */
    double timestamp;
    /** 
     * OPTIONAL: color code of the embed 
     */
    int color;
    /** 
     * OPTIONAL: footer information 
     */
    lldc_embed_footer_t footer;
    /** 
     * OPTIONAL: image information 
     */
    lldc_embed_image_t image;
    /** 
     * OPTIONAL: thumbnail information 
     */
    lldc_embed_thumbnail_t thumbnail;
    /** 
     * OPTIONAL: video information 
     */
    lldc_embed_video_t video;
    /** 
     * OPTIONAL: provider information 
     */
    lldc_embed_provider_t provider;
    /** 
     * OPTIONAL: author information 
     */
    lldc_embed_author_t author;
    /** 
     * OPTIONAL: fields information 
     */
    lldc_embed_field_arr_t fields;
} lldc_embed_t;
/* Embed Array */
typedef struct lldc_embed_arr_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_embed_t *items;
    size_t len;
    lldc_parser_malloc_ledger_t __mlog;
} lldc_embed_arr_t;
/* Emoji Structure */
typedef struct lldc_emoji_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_parser_malloc_ledger_t __mlog;
    /** 
     * OPTIONAL: emoji id 
     */
    snowflake_t id;
    /** 
     * OPTIONAL: emoji name 
     */
    const char *name;
    /** 
     * OPTIONAL: roles allowed to use this emoji 
     */
    lldc_parser_snowflake_arr_t roles;
    /** 
     * OPTIONAL: user that created this emoji 
     */
    lldc_user_t user;
    /** 
     * OPTIONAL: whether this emoji must be wrapped in colons 
     */
    int require_colons;
    /** 
     * OPTIONAL: whether this emoji is managed 
     */
    int managed;
    /** 
     * OPTIONAL: whether this emoji is animated 
     */
    int animated;
    /** 
     * OPTIONAL: whether this emoji can be used, may be false due to loss of Server Boosts 
     */
    int available;
} lldc_emoji_t;
/* Emoji Array */
typedef struct lldc_emoji_arr_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_emoji_t *items;
    size_t len;
    lldc_parser_malloc_ledger_t __mlog;
} lldc_emoji_arr_t;
/* Reaction Structure */
typedef struct lldc_reaction_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_parser_malloc_ledger_t __mlog;
    /** 
     * times this emoji has been used to react 
     */
    int count;
    /** 
     * whether the current user reacted using this emoji 
     */
    int me;
    /** 
     * emoji information 
     */
    lldc_emoji_t emoji;
} lldc_reaction_t;
/* Reaction Array */
typedef struct lldc_reaction_arr_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_reaction_t *items;
    size_t len;
    lldc_parser_malloc_ledger_t __mlog;
} lldc_reaction_arr_t;
/* Select Option Structure */
typedef struct lldc_select_option_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_parser_malloc_ledger_t __mlog;
    /** 
     * the user-facing name of the option, max 25 characters 
     */
    const char *label;
    /** 
     * the dev-define value of the option, max 100 characters 
     */
    const char *value;
    /** 
     * OPTIONAL: an additional description of the option, max 50 characters 
     */
    const char *description;
    /** 
     * OPTIONAL: id, name, and animated 
     */
    lldc_emoji_t emoji;
    /** 
     * OPTIONAL: will render this option as selected by default 
     */
    int is_default;
} lldc_select_option_t;
/* Select Option Array */
typedef struct lldc_select_option_arr_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_select_option_t *items;
    size_t len;
    lldc_parser_malloc_ledger_t __mlog;
} lldc_select_option_arr_t;
/* Component Array */
typedef struct lldc_component_arr_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_component_t *items;
    size_t len;
    lldc_parser_malloc_ledger_t __mlog;
} lldc_component_arr_t;
/* Component Structure */
struct lldc_component_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_parser_malloc_ledger_t __mlog;
    /** 
     * component type 
     */
    lldc_component_type_t type;
    /** 
     * OPTIONAL: a developer-defined identifier for the component, max 100 characters 
     */
    const char *custom_id;
    /** 
     * OPTIONAL: whether the component is disabled, default false 
     */
    int disabled;
    /** 
     * OPTIONAL: one of button styles 
     */
    lldc_component_style_t style;
    /** 
     * OPTIONAL: text that appears on the button, max 80 characters 
     */
    const char *label;
    /** 
     * OPTIONAL: name, id, and animated 
     */
    lldc_emoji_t emoji;
    /** 
     * OPTIONAL: a url for link-style buttons 
     */
    const char *url;
    /** 
     * the choices in the select, max 25 
     */
    lldc_select_option_arr_t options;
    /** 
     * OPTIONAL: custom placeholder text if nothing is selected, max 100 characters 
     */
    const char *placeholder;
    /** 
     * OPTIONAL: the minimum number of items that must be chosen; default 1, min 0, max 25 
     */
    int min_values;
    /** 
     * OPTIONAL: the maximum number of items that can be chosen; default 1, max 25 
     */
    int max_values;
    /** 
     * OPTIONAL: a list of child components 
     */
    lldc_component_arr_t components;
};
/* Represents a sticker that can be sent in messages. */
typedef struct lldc_sticker_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_parser_malloc_ledger_t __mlog;
    /** 
     * id of the sticker 
     */
    snowflake_t id;
    /** 
     * OPTIONAL: for standard stickers, id of the pack the sticker is from 
     */
    snowflake_t pack_id;
    /** 
     * name of the sticker 
     */
    const char *name;
    /** 
     * OPTIONAL: description of the sticker 
     */
    const char *description;
    /** 
     * for guild stickers, the Discord name of a unicode emoji representing the sticker's expression. for standard stickers, a comma-separated list of related expressions. 
     */
    const char *tags;
    /** 
     * type of sticker 
     */
    lldc_sticker_type_t type;
    /** 
     * type of sticker format 
     */
    lldc_sticker_format_t format_type;
    /** 
     * OPTIONAL: whether this guild sticker can be used, may be false due to loss of Server Boosts 
     */
    int available;
    /** 
     * OPTIONAL: id of the guild that owns this sticker 
     */
    snowflake_t guild_id;
    /** 
     * OPTIONAL: the user that uploaded the guild sticker 
     */
    lldc_user_t user;
    /** 
     * OPTIONAL: the standard sticker's sort order within its pack 
     */
    int sort_value;
} lldc_sticker_t;
/* Sticker Array */
typedef struct lldc_sticker_arr_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_sticker_t *items;
    size_t len;
    lldc_parser_malloc_ledger_t __mlog;
} lldc_sticker_arr_t;
/* The smallest amount of data required to render a sticker. A partial sticker object. */
typedef struct lldc_sticker_item_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_parser_malloc_ledger_t __mlog;
    /** 
     * id of the sticker 
     */
    snowflake_t id;
    /** 
     * name of the sticker 
     */
    const char *name;
    /** 
     * type of sticker format 
     */
    lldc_sticker_format_t format_type;
} lldc_sticker_item_t;
/* Sticker Item Array */
typedef struct lldc_sticker_item_arr_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_sticker_item_t *items;
    size_t len;
    lldc_parser_malloc_ledger_t __mlog;
} lldc_sticker_item_arr_t;
/* Message Activity Structure */
typedef struct lldc_message_activity_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_parser_malloc_ledger_t __mlog;
    /** 
     * type of message activity 
     */
    lldc_message_activity_type_t type;
    /** 
     * OPTIONAL: party_id from a Rich Presence event 
     */
    const char *party_id;
} lldc_message_activity_t;
/* Message Reference Structure */
typedef struct lldc_message_reference_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_parser_malloc_ledger_t __mlog;
    /** 
     * OPTIONAL: id of the originating message 
     */
    snowflake_t message_id;
    /** 
     * OPTIONAL: id of the originating message's channel 
     */
    snowflake_t channel_id;
    /** 
     * OPTIONAL: id of the originating message's guild 
     */
    snowflake_t guild_id;
    /** 
     * OPTIONAL: when sending, whether to error if the referenced message doesn't exist instead of sending as a normal (non-reply) message, default true 
     */
    int fail_if_not_exists;
} lldc_message_reference_t;
/* Message Interaction Structure */
typedef struct lldc_message_interaction_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_parser_malloc_ledger_t __mlog;
    /** 
     * id of the interaction 
     */
    snowflake_t id;
    /** 
     * the type of interaction 
     */
    int type;
    /** 
     * the name of the application command 
     */
    const char *name;
    /** 
     * the user who invoked the interaction 
     */
    lldc_user_t user;
} lldc_message_interaction_t;
/* Represents a message sent in a channel within Discord. */
typedef struct lldc_message_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_parser_malloc_ledger_t __mlog;
    /** 
     * id of the message 
     */
    snowflake_t id;
    /** 
     * id of the channel the message was sent in 
     */
    snowflake_t channel_id;
    /** 
     * OPTIONAL: id of the guild the message was sent in 
     */
    snowflake_t guild_id;
    /** 
     * the author of this message (not guaranteed to be a valid user, see below) 
     */
    lldc_user_t author;
    /** 
     * OPTIONAL: member properties for this message's author 
     */
    lldc_partial_guild_member_t member;
    /** 
     * contents of the message 
     */
    const char *content;
    /** 
     * when this message was sent 
     */
    double timestamp;
    /** 
     * OPTIONAL: when this message was edited (or null if never) 
     */
    double edited_timestamp;
    /** 
     * whether this was a TTS message 
     */
    int tts;
    /** 
     * whether this message mentions everyone 
     */
    int mention_everyone;
    /** 
     * users specifically mentioned in the message 
     */
    lldc_user_arr_t mentions;
    /** 
     * roles specifically mentioned in this message 
     */
    lldc_parser_snowflake_arr_t mention_roles;
    /** 
     * OPTIONAL: channels specifically mentioned in this message 
     */
    lldc_channel_mention_t mention_channels;
    /** 
     * any attached files 
     */
    lldc_attachment_arr_t attachments;
    /** 
     * any embedded content 
     */
    lldc_embed_arr_t embeds;
    /** 
     * OPTIONAL: reactions to the message 
     */
    lldc_reaction_t reactions;
    /** 
     * whether this message is pinned 
     */
    int pinned;
    /** 
     * OPTIONAL: if the message is generated by a webhook, this is the webhook's id 
     */
    snowflake_t webhook_id;
    /** 
     * type of message 
     */
    lldc_message_type_t type;
    /** 
     * OPTIONAL: sent with Rich Presence-related chat embeds 
     */
    lldc_message_activity_t activity;
    /** 
     * OPTIONAL: sent with Rich Presence-related chat embeds 
     */
    lldc_application_t application;
    /** 
     * OPTIONAL: if the message is a response to an Interaction, this is the id of the interaction's application 
     */
    snowflake_t application_id;
    /** 
     * OPTIONAL: data showing the source of a crosspost, channel follow add, pin, or reply message 
     */
    lldc_message_reference_t message_reference;
    /** 
     * OPTIONAL: message flags combined as a bitfield 
     */
    lldc_message_flags_t flags;
    /** 
     * OPTIONAL: sent if the message is a response to an Interaction 
     */
    lldc_message_interaction_t interaction;
    /** 
     * OPTIONAL: the thread that was started from this message, includes thread member object. You should parse this yourself if you want it. 
     */
    yyjson_val *thread;
    /** 
     * OPTIONAL: sent if the message contains components like buttons, action rows, or other interactive components 
     */
    lldc_component_arr_t components;
    /** 
     * OPTIONAL: sent if the message contains stickers 
     */
    lldc_sticker_item_arr_t sticker_items;
} lldc_message_t;
/* The allowed mention field allows for more granular control over mentions without various hacks to the message content. This will always validate against message content to avoid phantom pings (e.g. to ping everyone, you must still have @everyone in the message content), and check against user/bot permissions. */
typedef struct lldc_allowed_mentions_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_parser_malloc_ledger_t __mlog;
    /** 
     * An array of allowed mention types to parse from the content. 
     */
    lldc_parser_string_arr_t parse;
    /** 
     * Array of role_ids to mention (Max size of 100) 
     */
    lldc_parser_snowflake_arr_t roles;
    /** 
     * Array of user_ids to mention (Max size of 100) 
     */
    lldc_parser_snowflake_arr_t users;
    /** 
     * For replies, whether to mention the author of the message being replied to (default false) 
     */
    int replied_user;
} lldc_allowed_mentions_t;
/* Followed Channel Structure */
typedef struct lldc_followed_channel_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_parser_malloc_ledger_t __mlog;
    /** 
     * source channel id 
     */
    snowflake_t channel_id;
    /** 
     * created target webhook id 
     */
    snowflake_t webhook_id;
} lldc_followed_channel_t;
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
/* Channel Array */
typedef struct lldc_channel_arr_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_channel_t *items;
    size_t len;
    lldc_parser_malloc_ledger_t __mlog;
} lldc_channel_arr_t;
/* Used to represent a user's voice connection status. */
typedef struct lldc_voice_state_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_parser_malloc_ledger_t __mlog;
    /** 
     * OPTIONAL: the guild id this voice state is for 
     */
    snowflake_t guild_id;
    /** 
     * OPTIONAL: the channel id this user is connected to 
     */
    snowflake_t channel_id;
    /** 
     * the user id this voice state is for 
     */
    snowflake_t user_id;
    /** 
     * OPTIONAL: the guild member this voice state is for 
     */
    lldc_guild_member_t member;
    /** 
     * the session id for this voice state 
     */
    const char *session_id;
    /** 
     * whether this user is deafened by the server 
     */
    int deaf;
    /** 
     * whether this user is muted by the server 
     */
    int mute;
    /** 
     * whether this user is locally deafened 
     */
    int self_deaf;
    /** 
     * whether this user is locally muted 
     */
    int self_mute;
    /** 
     * OPTIONAL: whether this user is streaming using "Go Live" 
     */
    int self_stream;
    /** 
     * whether this user's camera is enabled 
     */
    int self_video;
    /** 
     * whether this user is muted by the current user 
     */
    int suppress;
    /** 
     * OPTIONAL: the time at which the user requested to speak 
     */
    double request_to_speak_timestamp;
} lldc_voice_state_t;
/* Voice State Array */
typedef struct lldc_voice_state_arr_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_voice_state_t *items;
    size_t len;
    lldc_parser_malloc_ledger_t __mlog;
} lldc_voice_state_arr_t;
/* Start and End timestamps */
typedef struct lldc_activity_timestamps_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_parser_malloc_ledger_t __mlog;
    /** 
     * OPTIONAL: unix time (in milliseconds) of when the activity started 
     */
    int start;
    /** 
     * OPTIONAL: unix time (in milliseconds) of when the activity ends 
     */
    int end;
} lldc_activity_timestamps_t;
/* Activity Party Structure */
typedef struct lldc_activity_party_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_parser_malloc_ledger_t __mlog;
    /** 
     * OPTIONAL: the id of the party 
     */
    const char *id;
    /** 
     * OPTIONAL: used to show the party's current and maximum size 
     */
    lldc_parser_int_arr_t size;
} lldc_activity_party_t;
/* Activity Assets Structure */
typedef struct lldc_activity_assets_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_parser_malloc_ledger_t __mlog;
    /** 
     * OPTIONAL: the id for a large asset of the activity, usually a snowflake 
     */
    const char *large_image;
    /** 
     * OPTIONAL: text displayed when hovering over the large image of the activity 
     */
    const char *large_text;
    /** 
     * OPTIONAL: the id for a small asset of the activity, usually a snowflake 
     */
    const char *small_image;
    /** 
     * OPTIONAL: text displayed when hovering over the small image of the activity 
     */
    const char *small_text;
} lldc_activity_assets_t;
/* Activity Secrets Structure */
typedef struct lldc_activity_secrets_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_parser_malloc_ledger_t __mlog;
    /** 
     * OPTIONAL: the secret for joining a party 
     */
    const char *join;
    /** 
     * OPTIONAL: the secret for spectating a game 
     */
    const char *spectate;
    /** 
     * OPTIONAL: the secret for a specific instanced match 
     */
    const char *match;
} lldc_activity_secrets_t;
/* When received over the gateway, the buttons field is an array of strings, which are the button labels. Bots cannot access a user's activity button URLs. When sending, the buttons field must be an array of the below object: */
typedef struct lldc_activity_buttons_item_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    /** 
     * the text shown on the button (1-32 characters) 
     */
    const char *label;
    /** 
     * the url opened when clicking the button (1-512 characters) 
     */
    const char *url;
} lldc_activity_buttons_item_t;
/* OPTIONAL: the custom buttons shown in the Rich Presence (max 2) */
typedef struct lldc_activity_buttons_arr_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_activity_buttons_item_t *items;
    size_t len;
} lldc_activity_buttons_arr_t;
/* Presence Activity */
typedef struct lldc_activity_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_parser_malloc_ledger_t __mlog;
    /** 
     * the activity's name 
     */
    const char *name;
    /** 
     * activity type 
     */
    lldc_activity_type_t type;
    /** 
     * OPTIONAL: stream url, is validated when type is 1 
     */
    const char *url;
    /** 
     * unix timestamp (in milliseconds) of when the activity was added to the user's session 
     */
    int created_at;
    /** 
     * OPTIONAL: unix timestamps for start and/or end of the game 
     */
    lldc_activity_timestamps_t timestamps;
    /** 
     * OPTIONAL: application id for the game 
     */
    snowflake_t application_id;
    /** 
     * OPTIONAL: what the player is currently doing 
     */
    const char *details;
    /** 
     * OPTIONAL: the user's current party status 
     */
    const char *state;
    /** 
     * OPTIONAL: the emoji used for a custom status 
     */
    lldc_emoji_t emoji;
    /** 
     * OPTIONAL: information for the current party of the player 
     */
    lldc_activity_party_t party;
    /** 
     * OPTIONAL: images for the presence and their hover texts 
     */
    lldc_activity_assets_t assets;
    /** 
     * OPTIONAL: secrets for Rich Presence joining and spectating 
     */
    lldc_activity_secrets_t secrets;
    /** 
     * OPTIONAL: whether or not the activity is an instanced game session 
     */
    int instance;
    /** 
     * OPTIONAL: activity flags ORd together, describes what the payload includes 
     */
    lldc_activity_flags_t flags;
    /** 
     * OPTIONAL: the custom buttons shown in the Rich Presence (max 2) 
     */
    lldc_activity_buttons_arr_t buttons;
} lldc_activity_t;
/* Presence Activity for Bot */
typedef struct lldc_activity_bot_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_parser_malloc_ledger_t __mlog;
    /** 
     * the activity's name 
     */
    const char *name;
    /** 
     * activity type 
     */
    lldc_activity_type_t type;
    /** 
     * OPTIONAL: stream url, is validated when type is 1 
     */
    const char *url;
} lldc_activity_bot_t;
/* Activity Array */
typedef struct lldc_activity_arr_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_activity_t *items;
    size_t len;
    lldc_parser_malloc_ledger_t __mlog;
} lldc_activity_arr_t;
/* Active sessions are indicated with an "online", "idle", or "dnd" string per platform. If a user is offline or invisible, the corresponding field is not present. */
typedef struct lldc_client_status_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_parser_malloc_ledger_t __mlog;
    /** 
     * OPTIONAL: the user's status set for an active desktop (Windows, Linux, Mac) application session 
     */
    const char *desktop;
    /** 
     * OPTIONAL: the user's status set for an active mobile (iOS, Android) application session 
     */
    const char *mobile;
    /** 
     * OPTIONAL: the user's status set for an active web (browser, bot account) application session 
     */
    const char *web;
} lldc_client_status_t;
/* A user's presence is their current state on a guild. This event is sent when a user's presence or info, such as name or avatar, is updated. */
typedef struct lldc_presence_update_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_parser_malloc_ledger_t __mlog;
    /** 
     * the user presence is being updated for 
     */
    lldc_user_t user;
    /** 
     * id of the guild 
     */
    snowflake_t guild_id;
    /** 
     * either "idle", "dnd", "online", or "offline" 
     */
    const char *status;
    /** 
     * user's current activities 
     */
    lldc_activity_arr_t activities;
    /** 
     * user's platform-dependent status 
     */
    lldc_client_status_t client_status;
} lldc_presence_update_t;
/* Presence Update Array */
typedef struct lldc_presence_update_arr_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_presence_update_t *items;
    size_t len;
    lldc_parser_malloc_ledger_t __mlog;
} lldc_presence_update_arr_t;
/* Stage Instance Structure */
typedef struct lldc_stage_instance_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_parser_malloc_ledger_t __mlog;
    /** 
     * The id of this Stage instance 
     */
    snowflake_t id;
    /** 
     * The guild id of the associated Stage channel 
     */
    snowflake_t guild_id;
    /** 
     * The id of the associated Stage channel 
     */
    snowflake_t channel_id;
    /** 
     * The topic of the Stage instance (1-120 characters) 
     */
    const char *topic;
    /** 
     * The privacy level of the Stage instance 
     */
    lldc_stage_instance_privacy_level_t privacy_level;
    /** 
     * Whether or not Stage discovery is disabled 
     */
    int discoverable_disabled;
} lldc_stage_instance_t;
/* Stage Instance Array */
typedef struct lldc_stage_instance_arr_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_stage_instance_t *items;
    size_t len;
    lldc_parser_malloc_ledger_t __mlog;
} lldc_stage_instance_arr_t;
/* Welcome Screen Channel Structure */
typedef struct lldc_welcome_screen_channel_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_parser_malloc_ledger_t __mlog;
    /** 
     * the channel's id 
     */
    snowflake_t channel_id;
    /** 
     * the description shown for the channel 
     */
    const char *description;
    /** 
     * OPTIONAL: the emoji id, if the emoji is custom 
     */
    snowflake_t emoji_id;
    /** 
     * OPTIONAL: the emoji name if custom, the unicode character if standard, or null if no emoji is set 
     */
    const char *emoji_name;
} lldc_welcome_screen_channel_t;
/* Welcome Screen Channel Array */
typedef struct lldc_welcome_screen_channel_arr_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_welcome_screen_channel_t *items;
    size_t len;
    lldc_parser_malloc_ledger_t __mlog;
} lldc_welcome_screen_channel_arr_t;
/* Welcome Screen Structure */
typedef struct lldc_welcome_screen_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_parser_malloc_ledger_t __mlog;
    /** 
     * OPTIONAL: the server description shown in the welcome screen 
     */
    const char *description;
    /** 
     * the channels shown in the welcome screen, up to 5 
     */
    lldc_welcome_screen_channel_arr_t welcome_channels;
} lldc_welcome_screen_t;
/* Guild Widget Structure - it's called guilds 'cause of conflict */
typedef struct lldc_guilds_widget_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_parser_malloc_ledger_t __mlog;
    /** 
     * whether the widget is enabled 
     */
    int enabled;
    /** 
     * OPTIONAL: the widget channel id 
     */
    snowflake_t channel_id;
} lldc_guilds_widget_t;
/* Guild Preview Structure */
typedef struct lldc_guild_preview_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_parser_malloc_ledger_t __mlog;
    /** 
     * guild id 
     */
    snowflake_t id;
    /** 
     * guild name (2-100 characters) 
     */
    const char *name;
    /** 
     * OPTIONAL: icon hash 
     */
    const char *icon;
    /** 
     * OPTIONAL: splash hash 
     */
    const char *splash;
    /** 
     * OPTIONAL: discovery splash hash 
     */
    const char *discovery_splash;
    /** 
     * custom guild emojis 
     */
    lldc_emoji_arr_t emojis;
    /** 
     * enabled guild features 
     */
    lldc_parser_string_arr_t features;
    /** 
     * approximate number of members in this guild 
     */
    int approximate_member_count;
    /** 
     * approximate number of online members in this guild 
     */
    int approximate_presence_count;
    /** 
     * OPTIONAL: the description for the guild, if the guild is discoverable 
     */
    const char *description;
} lldc_guild_preview_t;
/* Integration Account Structure */
typedef struct lldc_integration_account_s {
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
} lldc_integration_account_t;
/* Integration Application Structure */
typedef struct lldc_integration_application_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_parser_malloc_ledger_t __mlog;
    /** 
     * the id of the app 
     */
    snowflake_t id;
    /** 
     * the name of the app 
     */
    const char *name;
    /** 
     * OPTIONAL: the icon hash of the app 
     */
    const char *icon;
    /** 
     * the description of the app 
     */
    const char *description;
    /** 
     * the summary of the app 
     */
    const char *summary;
    /** 
     * OPTIONAL: the bot associated with this application 
     */
    lldc_user_t bot;
} lldc_integration_application_t;
/* Integration Structure */
typedef struct lldc_integration_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_parser_malloc_ledger_t __mlog;
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
     * is this integration enabled 
     */
    int enabled;
    /** 
     * OPTIONAL: is this integration syncing 
     */
    int syncing;
    /** 
     * OPTIONAL: id that this integration uses for "subscribers" 
     */
    snowflake_t role_id;
    /** 
     * OPTIONAL: whether emoticons should be synced for this integration (twitch only currently) 
     */
    int enable_emoticons;
    /** 
     * OPTIONAL: the behavior of expiring subscribers 
     */
    lldc_integration_expire_behavior_t expire_behavior;
    /** 
     * OPTIONAL: the grace period (in days) before expiring subscribers 
     */
    int expire_grace_period;
    /** 
     * OPTIONAL: user for this integration 
     */
    lldc_user_t user;
    /** 
     * integration account information 
     */
    lldc_integration_account_t account;
    /** 
     * OPTIONAL: when this integration was last synced 
     */
    double synced_at;
    /** 
     * OPTIONAL: how many subscribers this integration has 
     */
    int subscriber_count;
    /** 
     * OPTIONAL: has this integration been revoked 
     */
    int revoked;
    /** 
     * OPTIONAL: The bot/OAuth2 application for discord integrations 
     */
    lldc_integration_application_t application;
} lldc_integration_t;
/* Integration Array */
typedef struct lldc_integration_arr_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_integration_t *items;
    size_t len;
    lldc_parser_malloc_ledger_t __mlog;
} lldc_integration_arr_t;
/* Ban Structure */
typedef struct lldc_ban_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_parser_malloc_ledger_t __mlog;
    /** 
     * OPTIONAL: the reason for the ban 
     */
    const char *reason;
    /** 
     * the banned user 
     */
    lldc_user_t user;
} lldc_ban_t;
/* Ban Array */
typedef struct lldc_ban_arr_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_ban_t *items;
    size_t len;
    lldc_parser_malloc_ledger_t __mlog;
} lldc_ban_arr_t;
/* Guilds in Discord represent an isolated collection of users and channels, and are often referred to as "servers" in the UI. */
typedef struct lldc_guild_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_parser_malloc_ledger_t __mlog;
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
    /** 
     * OPTIONAL: icon hash, returned when in the template object 
     */
    const char *icon_hash;
    /** 
     * OPTIONAL: splash hash 
     */
    const char *splash;
    /** 
     * OPTIONAL: discovery splash hash; only present for guilds with the "DISCOVERABLE" feature 
     */
    const char *discovery_splash;
    /** 
     * OPTIONAL: true if the user is the owner of the guild 
     */
    int owner;
    /** 
     * id of owner 
     */
    snowflake_t owner_id;
    /** 
     * OPTIONAL: total permissions for the user in the guild (excludes overwrites) 
     */
    uint64_t permissions;
    /** 
     * OPTIONAL: voice region id for the guild (deprecated) 
     */
    const char *region;
    /** 
     * OPTIONAL: id of afk channel 
     */
    snowflake_t afk_channel_id;
    /** 
     * afk timeout in seconds 
     */
    int afk_timeout;
    /** 
     * OPTIONAL: true if the server widget is enabled 
     */
    int widget_enabled;
    /** 
     * OPTIONAL: the channel id that the widget will generate an invite to, or null if set to no invite 
     */
    snowflake_t widget_channel_id;
    /** 
     * verification level required for the guild 
     */
    lldc_guild_verification_level_t verification_level;
    /** 
     * default message notifications level 
     */
    lldc_guild_message_notifications_level_t default_message_notifications;
    /** 
     * explicit content filter level 
     */
    lldc_guild_explicit_content_filter_level_t explicit_content_filter;
    /** 
     * roles in the guild 
     */
    lldc_role_t roles;
    /** 
     * custom guild emojis 
     */
    lldc_emoji_t emojis;
    /** 
     * enabled guild features 
     */
    lldc_parser_string_arr_t features;
    /** 
     * required MFA level for the guild 
     */
    lldc_guild_mfa_level_t mfa_level;
    /** 
     * OPTIONAL: application id of the guild creator if it is bot-created 
     */
    snowflake_t application_id;
    /** 
     * OPTIONAL: the id of the channel where guild notices such as welcome messages and boost events are posted 
     */
    snowflake_t system_channel_id;
    /** 
     * system channel flags 
     */
    lldc_guild_system_channel_flags_t system_channel_flags;
    /** 
     * OPTIONAL: the id of the channel where Community guilds can display rules and/or guidelines 
     */
    snowflake_t rules_channel_id;
    /** 
     * OPTIONAL: when this guild was joined at 
     */
    double joined_at;
    /** 
     * OPTIONAL: true if this is considered a large guild 
     */
    int large;
    /** 
     * OPTIONAL: true if this guild is unavailable due to an outage 
     */
    int unavailable;
    /** 
     * OPTIONAL: total number of members in this guild 
     */
    int member_count;
    /** 
     * OPTIONAL: states of members currently in voice channels; lacks the guild_id key 
     */
    lldc_voice_state_arr_t voice_states;
    /** 
     * OPTIONAL: users in the guild 
     */
    lldc_guild_member_arr_t members;
    /** 
     * OPTIONAL: channels in the guild 
     */
    lldc_channel_arr_t channels;
    /** 
     * OPTIONAL: all active threads in the guild that current user has permission to view 
     */
    lldc_channel_arr_t threads;
    /** 
     * OPTIONAL: presences of the members in the guild, will only include non-offline members if the size is greater than large threshold 
     */
    lldc_presence_update_arr_t presences;
    /** 
     * OPTIONAL: the maximum number of presences for the guild (null is always returned, apart from the largest of guilds) 
     */
    int max_presences;
    /** 
     * OPTIONAL: the maximum number of members for the guild 
     */
    int max_members;
    /** 
     * OPTIONAL: the vanity url code for the guild 
     */
    const char *vanity_url_code;
    /** 
     * OPTIONAL: the description of a Community guild 
     */
    const char *description;
    /** 
     * OPTIONAL: banner hash 
     */
    const char *banner;
    /** 
     * premium tier (Server Boost level) 
     */
    lldc_guild_premium_tier_t premium_tier;
    /** 
     * OPTIONAL: the number of boosts this guild currently has 
     */
    int premium_subscription_count;
    /** 
     * the preferred locale of a Community guild; used in server discovery and notices from Discord; defaults to "en-US" 
     */
    const char *preferred_locale;
    /** 
     * OPTIONAL: the id of the channel where admins and moderators of Community guilds receive notices from Discord 
     */
    snowflake_t public_updates_channel_id;
    /** 
     * OPTIONAL: the maximum amount of users in a video channel 
     */
    int max_video_channel_users;
    /** 
     * OPTIONAL: approximate number of members in this guild, returned from the GET /guilds/<id> endpoint when with_counts is true 
     */
    int approximate_member_count;
    /** 
     * OPTIONAL: approximate number of non-offline members in this guild, returned from the GET /guilds/<id> endpoint when with_counts is true 
     */
    int approximate_presence_count;
    /** 
     * OPTIONAL: the welcome screen of a Community guild, shown to new members, returned in an Invite's guild object 
     */
    lldc_welcome_screen_t welcome_screen;
    /** 
     * guild NSFW level 
     */
    lldc_guild_nsfw_level_t nsfw_level;
    /** 
     * OPTIONAL: Stage instances in the guild 
     */
    lldc_stage_instance_arr_t stage_instances;
    /** 
     * OPTIONAL: custom guild stickers 
     */
    lldc_sticker_arr_t stickers;
} lldc_guild_t;
/* Guild Array */
typedef struct lldc_guild_arr_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_guild_t *items;
    size_t len;
    lldc_parser_malloc_ledger_t __mlog;
} lldc_guild_arr_t;
/* Represents a code that when used, creates a guild based on a snapshot of an existing guild. */
typedef struct lldc_guild_template_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_parser_malloc_ledger_t __mlog;
    /** 
     * the template code (unique ID) 
     */
    const char *code;
    /** 
     * template name 
     */
    const char *name;
    /** 
     * OPTIONAL: the description for the template 
     */
    const char *description;
    /** 
     * number of times this template has been used 
     */
    int usage_count;
    /** 
     * the ID of the user who created the template 
     */
    snowflake_t creator_id;
    /** 
     * the user who created the template 
     */
    lldc_user_t creator;
    /** 
     * when this template was created 
     */
    double created_at;
    /** 
     * when this template was last synced to the source guild 
     */
    double updated_at;
    /** 
     * the ID of the guild this template is based on 
     */
    snowflake_t source_guild_id;
    /** 
     * OPTIONAL: whether the template has unsynced changes 
     */
    int is_dirty;
} lldc_guild_template_t;
/* Guild Template Array */
typedef struct lldc_guild_template_arr_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    lldc_guild_template_t *items;
    size_t len;
    lldc_parser_malloc_ledger_t __mlog;
} lldc_guild_template_arr_t;
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
* Team Member Parser
* Team Member Object
*/
int lldc_team_member_parse (cwr_malloc_ctx_t *_mctx, lldc_team_member_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Team Member Parser
* Team Member Array
*/
int lldc_team_member_arr_parse (cwr_malloc_ctx_t *_mctx, lldc_team_member_arr_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Team Parser
* Team Object
*/
int lldc_team_parse (cwr_malloc_ctx_t *_mctx, lldc_team_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Application Parser
* Application Structure
*/
int lldc_application_parse (cwr_malloc_ctx_t *_mctx, lldc_application_t *obj, yyjson_val *json, int has_existing_ledger);
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
* Guild Member Parser
* Guild Member
*/
int lldc_guild_member_parse (cwr_malloc_ctx_t *_mctx, lldc_guild_member_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Guild Member Parser
* Guild Member Array
*/
int lldc_guild_member_arr_parse (cwr_malloc_ctx_t *_mctx, lldc_guild_member_arr_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Partial Guild Member Parser
* Partial Guild Member (excluding user)
*/
int lldc_partial_guild_member_parse (cwr_malloc_ctx_t *_mctx, lldc_partial_guild_member_t *obj, yyjson_val *json, int has_existing_ledger);
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
* Role Tags Parser
* Role Tags Structure
*/
int lldc_role_tags_parse (cwr_malloc_ctx_t *_mctx, lldc_role_tags_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Role Parser
* Roles represent a set of permissions attached to a group of users. Roles have unique names, colors, and can be "pinned" to the side bar, causing their members to be listed separately. Roles are unique per guild, and can have separate permission profiles for the global context (guild) and channel context. The @everyone role has the same ID as the guild it belongs to.
*/
int lldc_role_parse (cwr_malloc_ctx_t *_mctx, lldc_role_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Role Parser
* Role Array
*/
int lldc_role_arr_parse (cwr_malloc_ctx_t *_mctx, lldc_role_arr_t *obj, yyjson_val *json, int has_existing_ledger);
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
* Attachment Parser
* Attachment Structure
*/
int lldc_attachment_parse (cwr_malloc_ctx_t *_mctx, lldc_attachment_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Attachment Parser
* Attachment Array
*/
int lldc_attachment_arr_parse (cwr_malloc_ctx_t *_mctx, lldc_attachment_arr_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Channel Mention Parser
* Channel Mention Structure
*/
int lldc_channel_mention_parse (cwr_malloc_ctx_t *_mctx, lldc_channel_mention_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Channel Mention Parser
* Channel Mention Array
*/
int lldc_channel_mention_arr_parse (cwr_malloc_ctx_t *_mctx, lldc_channel_mention_arr_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Embed Author Parser
* Embed Author Structure
*/
int lldc_embed_author_parse (cwr_malloc_ctx_t *_mctx, lldc_embed_author_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Embed Footer Parser
* Embed Footer Structure
*/
int lldc_embed_footer_parse (cwr_malloc_ctx_t *_mctx, lldc_embed_footer_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Embed Image Parser
* Embed Image Structure
*/
int lldc_embed_image_parse (cwr_malloc_ctx_t *_mctx, lldc_embed_image_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Embed Provider Parser
* Embed Provider Structure
*/
int lldc_embed_provider_parse (cwr_malloc_ctx_t *_mctx, lldc_embed_provider_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Embed Thumbnail Parser
* Embed Thumbnail Structure
*/
int lldc_embed_thumbnail_parse (cwr_malloc_ctx_t *_mctx, lldc_embed_thumbnail_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Embed Video Parser
* Embed Video Structure
*/
int lldc_embed_video_parse (cwr_malloc_ctx_t *_mctx, lldc_embed_video_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Embed Field Parser
* Embed Field Structure
*/
int lldc_embed_field_parse (cwr_malloc_ctx_t *_mctx, lldc_embed_field_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Embed Field Parser
* Embed Field Array
*/
int lldc_embed_field_arr_parse (cwr_malloc_ctx_t *_mctx, lldc_embed_field_arr_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Embed Parser
* Embed Structure
*/
int lldc_embed_parse (cwr_malloc_ctx_t *_mctx, lldc_embed_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Embed Parser
* Embed Array
*/
int lldc_embed_arr_parse (cwr_malloc_ctx_t *_mctx, lldc_embed_arr_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Emoji Parser
* Emoji Structure
*/
int lldc_emoji_parse (cwr_malloc_ctx_t *_mctx, lldc_emoji_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Emoji Parser
* Emoji Array
*/
int lldc_emoji_arr_parse (cwr_malloc_ctx_t *_mctx, lldc_emoji_arr_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Reaction Parser
* Reaction Structure
*/
int lldc_reaction_parse (cwr_malloc_ctx_t *_mctx, lldc_reaction_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Reaction Parser
* Reaction Array
*/
int lldc_reaction_arr_parse (cwr_malloc_ctx_t *_mctx, lldc_reaction_arr_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Select Option Parser
* Select Option Structure
*/
int lldc_select_option_parse (cwr_malloc_ctx_t *_mctx, lldc_select_option_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Select Option Parser
* Select Option Array
*/
int lldc_select_option_arr_parse (cwr_malloc_ctx_t *_mctx, lldc_select_option_arr_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Component Parser
* Component Array
*/
int lldc_component_arr_parse (cwr_malloc_ctx_t *_mctx, lldc_component_arr_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Component Parser
* Component Structure
*/
int lldc_component_parse (cwr_malloc_ctx_t *_mctx, lldc_component_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Sticker Parser
* Represents a sticker that can be sent in messages.
*/
int lldc_sticker_parse (cwr_malloc_ctx_t *_mctx, lldc_sticker_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Sticker Parser
* Sticker Array
*/
int lldc_sticker_arr_parse (cwr_malloc_ctx_t *_mctx, lldc_sticker_arr_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Sticker Item Parser
* The smallest amount of data required to render a sticker. A partial sticker object.
*/
int lldc_sticker_item_parse (cwr_malloc_ctx_t *_mctx, lldc_sticker_item_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Sticker Item Parser
* Sticker Item Array
*/
int lldc_sticker_item_arr_parse (cwr_malloc_ctx_t *_mctx, lldc_sticker_item_arr_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Message Activity Parser
* Message Activity Structure
*/
int lldc_message_activity_parse (cwr_malloc_ctx_t *_mctx, lldc_message_activity_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Message Reference Parser
* Message Reference Structure
*/
int lldc_message_reference_parse (cwr_malloc_ctx_t *_mctx, lldc_message_reference_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Message Interaction Parser
* Message Interaction Structure
*/
int lldc_message_interaction_parse (cwr_malloc_ctx_t *_mctx, lldc_message_interaction_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Message Parser
* Represents a message sent in a channel within Discord.
*/
int lldc_message_parse (cwr_malloc_ctx_t *_mctx, lldc_message_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Followed Channel Parser
* Followed Channel Structure
*/
int lldc_followed_channel_parse (cwr_malloc_ctx_t *_mctx, lldc_followed_channel_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Channel Parser
* Represents a guild or DM channel within Discord
*/
int lldc_channel_parse (cwr_malloc_ctx_t *_mctx, lldc_channel_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Channel Parser
* Channel Array
*/
int lldc_channel_arr_parse (cwr_malloc_ctx_t *_mctx, lldc_channel_arr_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Voice State Parser
* Used to represent a user's voice connection status.
*/
int lldc_voice_state_parse (cwr_malloc_ctx_t *_mctx, lldc_voice_state_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Voice State Parser
* Voice State Array
*/
int lldc_voice_state_arr_parse (cwr_malloc_ctx_t *_mctx, lldc_voice_state_arr_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Activity Timestamps Parser
* Start and End timestamps
*/
int lldc_activity_timestamps_parse (cwr_malloc_ctx_t *_mctx, lldc_activity_timestamps_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Activity Party Parser
* Activity Party Structure
*/
int lldc_activity_party_parse (cwr_malloc_ctx_t *_mctx, lldc_activity_party_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Activity Assets Parser
* Activity Assets Structure
*/
int lldc_activity_assets_parse (cwr_malloc_ctx_t *_mctx, lldc_activity_assets_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Activity Secrets Parser
* Activity Secrets Structure
*/
int lldc_activity_secrets_parse (cwr_malloc_ctx_t *_mctx, lldc_activity_secrets_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Activity Parser
* Presence Activity
*/
int lldc_activity_parse (cwr_malloc_ctx_t *_mctx, lldc_activity_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Activity Parser
* Activity Array
*/
int lldc_activity_arr_parse (cwr_malloc_ctx_t *_mctx, lldc_activity_arr_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Client Status Parser
* Active sessions are indicated with an "online", "idle", or "dnd" string per platform. If a user is offline or invisible, the corresponding field is not present.
*/
int lldc_client_status_parse (cwr_malloc_ctx_t *_mctx, lldc_client_status_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Presence Update Parser
* A user's presence is their current state on a guild. This event is sent when a user's presence or info, such as name or avatar, is updated.
*/
int lldc_presence_update_parse (cwr_malloc_ctx_t *_mctx, lldc_presence_update_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Presence Update Parser
* Presence Update Array
*/
int lldc_presence_update_arr_parse (cwr_malloc_ctx_t *_mctx, lldc_presence_update_arr_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Stage Instance Parser
* Stage Instance Structure
*/
int lldc_stage_instance_parse (cwr_malloc_ctx_t *_mctx, lldc_stage_instance_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Stage Instance Parser
* Stage Instance Array
*/
int lldc_stage_instance_arr_parse (cwr_malloc_ctx_t *_mctx, lldc_stage_instance_arr_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Welcome Screen Channel Parser
* Welcome Screen Channel Structure
*/
int lldc_welcome_screen_channel_parse (cwr_malloc_ctx_t *_mctx, lldc_welcome_screen_channel_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Welcome Screen Channel Parser
* Welcome Screen Channel Array
*/
int lldc_welcome_screen_channel_arr_parse (cwr_malloc_ctx_t *_mctx, lldc_welcome_screen_channel_arr_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Welcome Screen Parser
* Welcome Screen Structure
*/
int lldc_welcome_screen_parse (cwr_malloc_ctx_t *_mctx, lldc_welcome_screen_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Guilds Widget Parser
* Guild Widget Structure - it's called guilds 'cause of conflict
*/
int lldc_guilds_widget_parse (cwr_malloc_ctx_t *_mctx, lldc_guilds_widget_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Guild Preview Parser
* Guild Preview Structure
*/
int lldc_guild_preview_parse (cwr_malloc_ctx_t *_mctx, lldc_guild_preview_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Integration Account Parser
* Integration Account Structure
*/
int lldc_integration_account_parse (cwr_malloc_ctx_t *_mctx, lldc_integration_account_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Integration Application Parser
* Integration Application Structure
*/
int lldc_integration_application_parse (cwr_malloc_ctx_t *_mctx, lldc_integration_application_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Integration Parser
* Integration Structure
*/
int lldc_integration_parse (cwr_malloc_ctx_t *_mctx, lldc_integration_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Integration Parser
* Integration Array
*/
int lldc_integration_arr_parse (cwr_malloc_ctx_t *_mctx, lldc_integration_arr_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Ban Parser
* Ban Structure
*/
int lldc_ban_parse (cwr_malloc_ctx_t *_mctx, lldc_ban_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Ban Parser
* Ban Array
*/
int lldc_ban_arr_parse (cwr_malloc_ctx_t *_mctx, lldc_ban_arr_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Guild Parser
* Guilds in Discord represent an isolated collection of users and channels, and are often referred to as "servers" in the UI.
*/
int lldc_guild_parse (cwr_malloc_ctx_t *_mctx, lldc_guild_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Guild Parser
* Guild Array
*/
int lldc_guild_arr_parse (cwr_malloc_ctx_t *_mctx, lldc_guild_arr_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Guild Template Parser
* Represents a code that when used, creates a guild based on a snapshot of an existing guild.
*/
int lldc_guild_template_parse (cwr_malloc_ctx_t *_mctx, lldc_guild_template_t *obj, yyjson_val *json, int has_existing_ledger);
/**
* Guild Template Parser
* Guild Template Array
*/
int lldc_guild_template_arr_parse (cwr_malloc_ctx_t *_mctx, lldc_guild_template_arr_t *obj, yyjson_val *json, int has_existing_ledger);
#endif