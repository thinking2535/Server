DROP PROCEDURE IF EXISTS [dbo].[sys_sp_UnBlockFriend]
GO
DROP PROCEDURE IF EXISTS [dbo].[sys_sp_Punish]
GO
DROP PROCEDURE IF EXISTS [dbo].[sys_sp_Login]
GO
DROP PROCEDURE IF EXISTS [dbo].[sys_sp_DenyFriend]
GO
DROP PROCEDURE IF EXISTS [dbo].[sys_sp_Create]
GO
DROP PROCEDURE IF EXISTS [dbo].[sys_sp_Clear]
GO
DROP PROCEDURE IF EXISTS [dbo].[sys_sp_Check]
GO
DROP PROCEDURE IF EXISTS [dbo].[sys_sp_ChangeState]
GO
DROP PROCEDURE IF EXISTS [dbo].[sys_sp_ChangeNick]
GO
DROP PROCEDURE IF EXISTS [dbo].[sys_sp_BlockFriend]
GO
DROP PROCEDURE IF EXISTS [dbo].[sys_sp_AllowFriend]
GO
DROP PROCEDURE IF EXISTS [dbo].[sys_sp_AddFriendRequest]
GO
DROP PROCEDURE IF EXISTS [dbo].[sys_sp_AddFriendFail]
GO
DROP PROCEDURE IF EXISTS [dbo].[sys_sp_AddFriendEnd]
GO
DROP PROCEDURE IF EXISTS [dbo].[sys_sp_AddFriendBegin]
GO
DROP PROCEDURE IF EXISTS [dbo].[spUpdateMatchBlockEndTime]
GO
DROP PROCEDURE IF EXISTS [dbo].[spUpdateInvalidDisconnectInfo]
GO
DROP PROCEDURE IF EXISTS [dbo].[spUnsetChar]
GO
DROP PROCEDURE IF EXISTS [dbo].[spTutorialReward]
GO
DROP PROCEDURE IF EXISTS [dbo].[spSetUserExp]
GO
DROP PROCEDURE IF EXISTS [dbo].[spSetResources]
GO
DROP PROCEDURE IF EXISTS [dbo].[spSetPoint]
GO
DROP PROCEDURE IF EXISTS [dbo].[spSetChar]
GO
DROP PROCEDURE IF EXISTS [dbo].[spSelectChar]
GO
DROP PROCEDURE IF EXISTS [dbo].[spRankReward]
GO
DROP PROCEDURE IF EXISTS [dbo].[spRankingReward]
GO
DROP PROCEDURE IF EXISTS [dbo].[spQuestSet]
GO
DROP PROCEDURE IF EXISTS [dbo].[spQuestReward]
GO
DROP PROCEDURE IF EXISTS [dbo].[spQuestNew]
GO
DROP PROCEDURE IF EXISTS [dbo].[spQuestDone]
GO
DROP PROCEDURE IF EXISTS [dbo].[spQuestDel]
GO
DROP PROCEDURE IF EXISTS [dbo].[spQuestDailyCompleteReward]
GO
DROP PROCEDURE IF EXISTS [dbo].[spLogin]
GO
DROP PROCEDURE IF EXISTS [dbo].[spJoin]
GO
DROP PROCEDURE IF EXISTS [dbo].[spFlyAwayBattleStart]
GO
DROP PROCEDURE IF EXISTS [dbo].[spFlyAwayBattleEnd]
GO
DROP PROCEDURE IF EXISTS [dbo].[spCouponUse]
GO
DROP PROCEDURE IF EXISTS [dbo].[spClear]
GO
DROP PROCEDURE IF EXISTS [dbo].[spCheckID]
GO
DROP PROCEDURE IF EXISTS [dbo].[spChangeNickEndFail]
GO
DROP PROCEDURE IF EXISTS [dbo].[spChangeNickEnd]
GO
DROP PROCEDURE IF EXISTS [dbo].[spChangeNickBegin]
GO
DROP PROCEDURE IF EXISTS [dbo].[spBuyChar]
GO
DROP PROCEDURE IF EXISTS [dbo].[spBuy]
GO
DROP PROCEDURE IF EXISTS [dbo].[spBattleEnd]
GO
DROP PROCEDURE IF EXISTS [dbo].[spArrowDodgeBattleStart]
GO
DROP PROCEDURE IF EXISTS [dbo].[spArrowDodgeBattleEnd]
GO
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[tUser]') AND type in (N'U'))
ALTER TABLE [dbo].[tUser] DROP CONSTRAINT IF EXISTS [DF_tUser_InvalidDisconnectCount]
GO
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[tUser]') AND type in (N'U'))
ALTER TABLE [dbo].[tUser] DROP CONSTRAINT IF EXISTS [DF_tUser_InvalidDisconnectMatchBlockEndTime]
GO
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[tUser]') AND type in (N'U'))
ALTER TABLE [dbo].[tUser] DROP CONSTRAINT IF EXISTS [DF_tUser_InvalidDisconnectEndTime]
GO
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[tUser]') AND type in (N'U'))
ALTER TABLE [dbo].[tUser] DROP CONSTRAINT IF EXISTS [DF_tUser_ChangingNick]
GO
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[tUser]') AND type in (N'U'))
ALTER TABLE [dbo].[tUser] DROP CONSTRAINT IF EXISTS [DF_tUser_RankingRewardCounter]
GO
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[tUser]') AND type in (N'U'))
ALTER TABLE [dbo].[tUser] DROP CONSTRAINT IF EXISTS [DF_tUser_TutorialReward_1]
GO
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[tUser]') AND type in (N'U'))
ALTER TABLE [dbo].[tUser] DROP CONSTRAINT IF EXISTS [DF_tUser_QuestDailyCompleteCount]
GO
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[tUser]') AND type in (N'U'))
ALTER TABLE [dbo].[tUser] DROP CONSTRAINT IF EXISTS [DF_tUser_BlowBalloonTotal]
GO
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[tUser]') AND type in (N'U'))
ALTER TABLE [dbo].[tUser] DROP CONSTRAINT IF EXISTS [DF_tUser_ChainKillTotal]
GO
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[tUser]') AND type in (N'U'))
ALTER TABLE [dbo].[tUser] DROP CONSTRAINT IF EXISTS [DF_tUser_KillTotal]
GO
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[tUser]') AND type in (N'U'))
ALTER TABLE [dbo].[tUser] DROP CONSTRAINT IF EXISTS [DF_tUser_IslandComboBest]
GO
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[tUser]') AND type in (N'U'))
ALTER TABLE [dbo].[tUser] DROP CONSTRAINT IF EXISTS [DF_tUser_IslandPointBest]
GO
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[tUser]') AND type in (N'U'))
ALTER TABLE [dbo].[tUser] DROP CONSTRAINT IF EXISTS [DF_tUser_BattlePointBest1]
GO
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[tUser]') AND type in (N'U'))
ALTER TABLE [dbo].[tUser] DROP CONSTRAINT IF EXISTS [DF_tUser_BestBattlePoint]
GO
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[tUser]') AND type in (N'U'))
ALTER TABLE [dbo].[tUser] DROP CONSTRAINT IF EXISTS [DF_tUser_LoseCountSolo1]
GO
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[tUser]') AND type in (N'U'))
ALTER TABLE [dbo].[tUser] DROP CONSTRAINT IF EXISTS [DF_tUser_WinCountSolo1]
GO
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[tUser]') AND type in (N'U'))
ALTER TABLE [dbo].[tUser] DROP CONSTRAINT IF EXISTS [DF_tUser_LoseCount]
GO
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[tUser]') AND type in (N'U'))
ALTER TABLE [dbo].[tUser] DROP CONSTRAINT IF EXISTS [DF_tUser_WinCount]
GO
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[tUser]') AND type in (N'U'))
ALTER TABLE [dbo].[tUser] DROP CONSTRAINT IF EXISTS [DF_tUser_LastGotRewardRankIndex]
GO
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[tUser]') AND type in (N'U'))
ALTER TABLE [dbo].[tUser] DROP CONSTRAINT IF EXISTS [DF_tUser_PointBest]
GO
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[tUser]') AND type in (N'U'))
ALTER TABLE [dbo].[tUser] DROP CONSTRAINT IF EXISTS [DF_tUser_Point]
GO
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[tUser]') AND type in (N'U'))
ALTER TABLE [dbo].[tUser] DROP CONSTRAINT IF EXISTS [DF_tUser_eloPoint]
GO
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[tUser]') AND type in (N'U'))
ALTER TABLE [dbo].[tUser] DROP CONSTRAINT IF EXISTS [DF_tUser_CanPushAtNight]
GO
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[tUser]') AND type in (N'U'))
ALTER TABLE [dbo].[tUser] DROP CONSTRAINT IF EXISTS [DF_tUser_Exp]
GO
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[tQuest]') AND type in (N'U'))
ALTER TABLE [dbo].[tQuest] DROP CONSTRAINT IF EXISTS [DF_tQuest_CoolEndTime]
GO
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[tQuest]') AND type in (N'U'))
ALTER TABLE [dbo].[tQuest] DROP CONSTRAINT IF EXISTS [DF_tQuest_Count]
GO
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[tChar]') AND type in (N'U'))
ALTER TABLE [dbo].[tChar] DROP CONSTRAINT IF EXISTS [DF_tChar_BalloonCode_1]
GO
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[tChar]') AND type in (N'U'))
ALTER TABLE [dbo].[tChar] DROP CONSTRAINT IF EXISTS [DF_tChar_HatCode_1]
GO
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[tChar]') AND type in (N'U'))
ALTER TABLE [dbo].[tChar] DROP CONSTRAINT IF EXISTS [DF_tChar_SkinCode_1]
GO
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[sys_tbl_User]') AND type in (N'U'))
ALTER TABLE [dbo].[sys_tbl_User] DROP CONSTRAINT IF EXISTS [DF_sys_tbl_User_InsertedTime]
GO
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[sys_tbl_User]') AND type in (N'U'))
ALTER TABLE [dbo].[sys_tbl_User] DROP CONSTRAINT IF EXISTS [DF_sys_tbl_User_PunishEndTime]
GO
DROP TABLE IF EXISTS [dbo].[tUser]
GO
DROP TABLE IF EXISTS [dbo].[tQuest]
GO
DROP TABLE IF EXISTS [dbo].[tProductPrice]
GO
DROP TABLE IF EXISTS [dbo].[tCouponUsedUser]
GO
DROP TABLE IF EXISTS [dbo].[tChar]
GO
DROP TABLE IF EXISTS [dbo].[sys_tbl_User]
GO
DROP TABLE IF EXISTS [dbo].[sys_tbl_Friend]
GO
DROP FUNCTION IF EXISTS [dbo].[fTimeToDateTime]
GO
DROP FUNCTION IF EXISTS [dbo].[fTimePointToDateTime]
GO
DROP TYPE IF EXISTS [dbo].[TUIDQuestTypeCounts]
GO
DROP TYPE IF EXISTS [dbo].[TUIDQuestSlotIndexCounts]
GO
DROP TYPE IF EXISTS [dbo].[TUIDQuestCodeCounts]
GO
DROP TYPE IF EXISTS [dbo].[TRankingReward]
GO
DROP TYPE IF EXISTS [dbo].[TQuestTypes]
GO
DROP TYPE IF EXISTS [dbo].[TQuestSlotIndices]
GO
DROP TYPE IF EXISTS [dbo].[TQuestSlotIndexCodes]
GO
DROP TYPE IF EXISTS [dbo].[TQuestCodes]
GO
DROP TYPE IF EXISTS [dbo].[TNickPoint]
GO
DROP TYPE IF EXISTS [dbo].[TGachaGuaranteeCounts]
GO
DROP TYPE IF EXISTS [dbo].[TCodes]
GO
DROP TYPE IF EXISTS [dbo].[TCharCodes]
GO
DROP TYPE IF EXISTS [dbo].[TBattleEndInfos]
GO
CREATE TYPE [dbo].[TBattleEndInfos] AS TABLE(
	[UID] [bigint] NULL,
	[Ticket] [int] NULL,
	[Gold] [int] NULL,
	[Dia00] [int] NULL,
	[Dia01] [int] NULL,
	[Dia02] [int] NULL,
	[Dia03] [int] NULL,
	[eloPoint] [float] NULL,
	[Point] [int] NULL,
	[PointBest] [int] NULL,
	[WinCountSolo] [int] NULL,
	[LoseCountSolo] [int] NULL,
	[WinCountMulti] [int] NULL,
	[LoseCountMulti] [int] NULL,
	[BattlePointBest] [int] NULL,
	[KillTotal] [int] NULL,
	[ChainKillTotal] [int] NULL,
	[BlowBalloonTotal] [int] NULL
)
GO
CREATE TYPE [dbo].[TCharCodes] AS TABLE(
	[CharCode] [int] NULL
)
GO
CREATE TYPE [dbo].[TCodes] AS TABLE(
	[Code] [int] NULL
)
GO
CREATE TYPE [dbo].[TGachaGuaranteeCounts] AS TABLE(
	[Index] [int] NULL,
	[GuaranteeCount] [int] NULL
)
GO
CREATE TYPE [dbo].[TNickPoint] AS TABLE(
	[Nick] [nvarchar](8) NULL,
	[Point] [int] NULL
)
GO
CREATE TYPE [dbo].[TQuestCodes] AS TABLE(
	[Code] [int] NULL
)
GO
CREATE TYPE [dbo].[TQuestSlotIndexCodes] AS TABLE(
	[SlotIndex] [tinyint] NULL,
	[Code] [int] NULL
)
GO
CREATE TYPE [dbo].[TQuestSlotIndices] AS TABLE(
	[SlotIndex] [tinyint] NULL
)
GO
CREATE TYPE [dbo].[TQuestTypes] AS TABLE(
	[QuestType] [int] NULL
)
GO
CREATE TYPE [dbo].[TRankingReward] AS TABLE(
	[UID] [bigint] NULL,
	[Ranking] [int] NULL
)
GO
CREATE TYPE [dbo].[TUIDQuestCodeCounts] AS TABLE(
	[UID] [bigint] NULL,
	[Code] [int] NULL,
	[Count] [int] NULL
)
GO
CREATE TYPE [dbo].[TUIDQuestSlotIndexCounts] AS TABLE(
	[SlotIndex] [tinyint] NULL,
	[Count] [int] NULL,
	[UID] [bigint] NULL
)
GO
CREATE TYPE [dbo].[TUIDQuestTypeCounts] AS TABLE(
	[UID] [bigint] NULL,
	[QuestType] [int] NULL,
	[Count] [int] NULL
)
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE FUNCTION [dbo].[fTimePointToDateTime]
(
	@TimePoint_ BIGINT
)
RETURNS DATETIME
AS
BEGIN
	RETURN DATEADD(S, @TimePoint_ / 10000000, '1970-01-01 9:00:00')
END

GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE FUNCTION [dbo].[fTimeToDateTime]
(
	@TimePoint_ BIGINT
)
RETURNS DATETIME
AS
BEGIN
	RETURN DATEADD(S, @TimePoint_ / 1000, '1970-01-01 9:00:00')
END

GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[sys_tbl_Friend](
	[UID] [bigint] NOT NULL,
	[FriendUID] [bigint] NOT NULL,
	[FriendNick] [nvarchar](32) NOT NULL,
	[FriendState] [tinyint] NOT NULL,
 CONSTRAINT [PK_sys_tbl_Friend] PRIMARY KEY CLUSTERED 
(
	[UID] ASC,
	[FriendUID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[sys_tbl_User](
	[UID] [bigint] NOT NULL,
	[ID] [varbinary](32) NOT NULL,
	[Nick] [nvarchar](32) NOT NULL,
	[State] [tinyint] NOT NULL,
	[PunishEndTime] [bigint] NOT NULL,
	[InsertedTime] [datetime] NOT NULL,
 CONSTRAINT [PK_sys_tbl_User] PRIMARY KEY CLUSTERED 
(
	[UID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[tChar](
	[UID] [bigint] NOT NULL,
	[CharCode] [int] NOT NULL,
	[SkinCode] [int] NOT NULL,
	[HatCode] [int] NOT NULL,
	[BalloonCode] [int] NOT NULL,
 CONSTRAINT [PK_tChar] PRIMARY KEY CLUSTERED 
(
	[UID] ASC,
	[CharCode] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[tCouponUsedUser](
	[UID] [bigint] NOT NULL,
	[Key] [nvarchar](256) NOT NULL
) ON [PRIMARY]
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[tProductPrice](
	[ProductID] [nvarchar](100) NOT NULL,
	[Price] [int] NOT NULL,
 CONSTRAINT [PK_tProductPrice] PRIMARY KEY CLUSTERED 
(
	[ProductID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[tQuest](
	[UID] [bigint] NOT NULL,
	[SlotIndex] [tinyint] NOT NULL,
	[Code] [int] NOT NULL,
	[Count] [int] NOT NULL,
	[CoolEndTime] [bigint] NOT NULL,
 CONSTRAINT [PK_tQuest] PRIMARY KEY CLUSTERED 
(
	[UID] ASC,
	[SlotIndex] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[tUser](
	[UID] [bigint] NOT NULL,
	[Ticket] [int] NOT NULL,
	[Gold] [int] NOT NULL,
	[Dia00] [int] NOT NULL,
	[Dia01] [int] NOT NULL,
	[Dia02] [int] NOT NULL,
	[Dia03] [int] NOT NULL,
	[Debug] [tinyint] NOT NULL,
	[SelectedCharCode] [int] NOT NULL,
	[InsertedTimePoint] [bigint] NOT NULL,
	[OS] [tinyint] NOT NULL,
	[CountryCode] [char](2) NOT NULL,
	[Exp] [int] NOT NULL,
	[CanPushAtNight] [tinyint] NOT NULL,
	[eloPoint] [float] NOT NULL,
	[Point] [int] NOT NULL,
	[PointBest] [int] NOT NULL,
	[NextRewardRankIndex] [int] NOT NULL,
	[WinCountSolo] [int] NOT NULL,
	[LoseCountSolo] [int] NOT NULL,
	[WinCountMulti] [int] NOT NULL,
	[LoseCountMulti] [int] NOT NULL,
	[BattlePointBest] [int] NOT NULL,
	[SingleCount] [int] NOT NULL,
	[SingleRefreshTime] [bigint] NOT NULL,
	[SinglePointBest] [int] NOT NULL,
	[IslandCount] [int] NOT NULL,
	[IslandRefreshTime] [bigint] NOT NULL,
	[IslandPointBest] [int] NOT NULL,
	[IslandComboBest] [int] NOT NULL,
	[KillTotal] [int] NOT NULL,
	[ChainKillTotal] [int] NOT NULL,
	[BlowBalloonTotal] [int] NOT NULL,
	[QuestDailyCompleteCount] [int] NOT NULL,
	[QuestDailyCompleteRefreshTime] [bigint] NOT NULL,
	[ChangeNickFreeCount] [int] NOT NULL,
	[TutorialReward] [tinyint] NOT NULL,
	[RankingRewardedCounter] [bigint] NOT NULL,
	[NewNick] [nvarchar](32) NOT NULL,
	[InvalidDisconnectEndTime] [bigint] NOT NULL,
	[InvalidDisconnectMatchBlockEndTime] [bigint] NOT NULL,
	[InvalidDisconnectCount] [int] NOT NULL,
	[Language] [tinyint] NOT NULL,
 CONSTRAINT [PK_tUser] PRIMARY KEY CLUSTERED 
(
	[UID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
ALTER TABLE [dbo].[sys_tbl_User] ADD  CONSTRAINT [DF_sys_tbl_User_PunishEndTime]  DEFAULT ((0)) FOR [PunishEndTime]
GO
ALTER TABLE [dbo].[sys_tbl_User] ADD  CONSTRAINT [DF_sys_tbl_User_InsertedTime]  DEFAULT (getdate()) FOR [InsertedTime]
GO
ALTER TABLE [dbo].[tChar] ADD  CONSTRAINT [DF_tChar_SkinCode_1]  DEFAULT ((0)) FOR [SkinCode]
GO
ALTER TABLE [dbo].[tChar] ADD  CONSTRAINT [DF_tChar_HatCode_1]  DEFAULT ((0)) FOR [HatCode]
GO
ALTER TABLE [dbo].[tChar] ADD  CONSTRAINT [DF_tChar_BalloonCode_1]  DEFAULT ((0)) FOR [BalloonCode]
GO
ALTER TABLE [dbo].[tQuest] ADD  CONSTRAINT [DF_tQuest_Count]  DEFAULT ((0)) FOR [Count]
GO
ALTER TABLE [dbo].[tQuest] ADD  CONSTRAINT [DF_tQuest_CoolEndTime]  DEFAULT ((0)) FOR [CoolEndTime]
GO
ALTER TABLE [dbo].[tUser] ADD  CONSTRAINT [DF_tUser_Exp]  DEFAULT ((0)) FOR [Exp]
GO
ALTER TABLE [dbo].[tUser] ADD  CONSTRAINT [DF_tUser_CanPushAtNight]  DEFAULT ((0)) FOR [CanPushAtNight]
GO
ALTER TABLE [dbo].[tUser] ADD  CONSTRAINT [DF_tUser_eloPoint]  DEFAULT ((0)) FOR [eloPoint]
GO
ALTER TABLE [dbo].[tUser] ADD  CONSTRAINT [DF_tUser_Point]  DEFAULT ((0)) FOR [Point]
GO
ALTER TABLE [dbo].[tUser] ADD  CONSTRAINT [DF_tUser_PointBest]  DEFAULT ((0)) FOR [PointBest]
GO
ALTER TABLE [dbo].[tUser] ADD  CONSTRAINT [DF_tUser_LastGotRewardRankIndex]  DEFAULT ((0)) FOR [NextRewardRankIndex]
GO
ALTER TABLE [dbo].[tUser] ADD  CONSTRAINT [DF_tUser_WinCount]  DEFAULT ((0)) FOR [WinCountSolo]
GO
ALTER TABLE [dbo].[tUser] ADD  CONSTRAINT [DF_tUser_LoseCount]  DEFAULT ((0)) FOR [LoseCountSolo]
GO
ALTER TABLE [dbo].[tUser] ADD  CONSTRAINT [DF_tUser_WinCountSolo1]  DEFAULT ((0)) FOR [WinCountMulti]
GO
ALTER TABLE [dbo].[tUser] ADD  CONSTRAINT [DF_tUser_LoseCountSolo1]  DEFAULT ((0)) FOR [LoseCountMulti]
GO
ALTER TABLE [dbo].[tUser] ADD  CONSTRAINT [DF_tUser_BestBattlePoint]  DEFAULT ((0)) FOR [BattlePointBest]
GO
ALTER TABLE [dbo].[tUser] ADD  CONSTRAINT [DF_tUser_BattlePointBest1]  DEFAULT ((0)) FOR [SinglePointBest]
GO
ALTER TABLE [dbo].[tUser] ADD  CONSTRAINT [DF_tUser_IslandPointBest]  DEFAULT ((0)) FOR [IslandPointBest]
GO
ALTER TABLE [dbo].[tUser] ADD  CONSTRAINT [DF_tUser_IslandComboBest]  DEFAULT ((0)) FOR [IslandComboBest]
GO
ALTER TABLE [dbo].[tUser] ADD  CONSTRAINT [DF_tUser_KillTotal]  DEFAULT ((0)) FOR [KillTotal]
GO
ALTER TABLE [dbo].[tUser] ADD  CONSTRAINT [DF_tUser_ChainKillTotal]  DEFAULT ((0)) FOR [ChainKillTotal]
GO
ALTER TABLE [dbo].[tUser] ADD  CONSTRAINT [DF_tUser_BlowBalloonTotal]  DEFAULT ((0)) FOR [BlowBalloonTotal]
GO
ALTER TABLE [dbo].[tUser] ADD  CONSTRAINT [DF_tUser_QuestDailyCompleteCount]  DEFAULT ((0)) FOR [QuestDailyCompleteCount]
GO
ALTER TABLE [dbo].[tUser] ADD  CONSTRAINT [DF_tUser_TutorialReward_1]  DEFAULT ((0)) FOR [TutorialReward]
GO
ALTER TABLE [dbo].[tUser] ADD  CONSTRAINT [DF_tUser_RankingRewardCounter]  DEFAULT ((0)) FOR [RankingRewardedCounter]
GO
ALTER TABLE [dbo].[tUser] ADD  CONSTRAINT [DF_tUser_ChangingNick]  DEFAULT (N'') FOR [NewNick]
GO
ALTER TABLE [dbo].[tUser] ADD  CONSTRAINT [DF_tUser_InvalidDisconnectEndTime]  DEFAULT ((0)) FOR [InvalidDisconnectEndTime]
GO
ALTER TABLE [dbo].[tUser] ADD  CONSTRAINT [DF_tUser_InvalidDisconnectMatchBlockEndTime]  DEFAULT ((0)) FOR [InvalidDisconnectMatchBlockEndTime]
GO
ALTER TABLE [dbo].[tUser] ADD  CONSTRAINT [DF_tUser_InvalidDisconnectCount]  DEFAULT ((0)) FOR [InvalidDisconnectCount]
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[spArrowDodgeBattleEnd]
	@UID_ BIGINT
,	@Ticket_ INT
,	@Gold_ INT
,	@Dia00_ INT
,	@Dia01_ INT
,	@Dia02_ INT
,	@Dia03_ INT
,	@PointBest_ INT
,	@DoneQuests_ dbo.TUIDQuestSlotIndexCounts READONLY
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	DECLARE @Ret INT = 0
	
	BEGIN TRY

		BEGIN TRAN

		UPDATE	dbo.tUser
		SET		Ticket = @Ticket_
			,	Gold = @Gold_
			,	Dia00 = @Dia00_
			,	Dia01 = @Dia01_
			,	Dia02 = @Dia02_
			,	Dia03 = @Dia03_
			,	SinglePointBest = @PointBest_
		WHERE	[UID] = @UID_

		UPDATE	dbo.tQuest
		SET		[Count] = tD.[Count]
		FROM	dbo.tQuest tQ
			,	@DoneQuests_ tD
		WHERE	tQ.[UID] = tD.[UID]
			AND	tQ.SlotIndex = tD.SlotIndex

		COMMIT TRAN

		RETURN 0
		
	END TRY
	BEGIN CATCH
		IF
			ERROR_NUMBER() <> 50000 AND
			ERROR_NUMBER() <> 266
		SET @Ret = ERROR_NUMBER()
		
		IF XACT_STATE() <> 0
			ROLLBACK TRAN

		RETURN @Ret
		
	END CATCH
END
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[spArrowDodgeBattleStart]
	@UID_ BIGINT
,	@Ticket_ INT
,	@Gold_ INT
,	@Dia00_ INT
,	@Dia01_ INT
,	@Dia02_ INT
,	@Dia03_ INT
,	@Count_ INT
,	@RefreshTime_ BIGINT
,	@DoneQuests_ dbo.TUIDQuestSlotIndexCounts READONLY
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	DECLARE @Ret INT = 0
	
	BEGIN TRY

		BEGIN TRAN

		UPDATE	dbo.tUser
		SET		Ticket = @Ticket_
			,	Gold = @Gold_
			,	Dia00 = @Dia00_
			,	Dia01 = @Dia01_
			,	Dia02 = @Dia02_
			,	Dia03 = @Dia03_
			,	SingleCount = @Count_
			,	SingleRefreshTime = @RefreshTime_
		WHERE	[UID] = @UID_

		UPDATE	dbo.tQuest
		SET		[Count] = tD.[Count]
		FROM	dbo.tQuest tQ
			,	@DoneQuests_ tD
		WHERE	tQ.[UID] = tD.[UID]
			AND	tQ.SlotIndex = tD.SlotIndex

		COMMIT TRAN

		RETURN 0
		
	END TRY
	BEGIN CATCH
		IF
			ERROR_NUMBER() <> 50000 AND
			ERROR_NUMBER() <> 266
		SET @Ret = ERROR_NUMBER()
		
		IF XACT_STATE() <> 0
			ROLLBACK TRAN

		RETURN @Ret
		
	END CATCH
END
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[spBattleEnd]
	@BattleEndInfos_ dbo.TBattleEndInfos READONLY
,	@DoneQuests_ dbo.TUIDQuestSlotIndexCounts READONLY
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	DECLARE @Ret INT = 0
	
	BEGIN TRY

		BEGIN TRAN

		UPDATE	dbo.tUser
		SET		Ticket = tB.Ticket
			,	Gold = tB.Gold
			,	Dia00 = tB.Dia00
			,	Dia01 = tB.Dia01
			,	Dia02 = tB.Dia02
			,	Dia03 = tB.Dia03
			,	eloPoint = tB.eloPoint
			,	Point = tB.Point
			,	PointBest = tB.PointBest
			,	WinCountSolo = tB.WinCountSolo
			,	LoseCountSolo = tB.LoseCountSolo
			,	WinCountMulti = tB.WinCountMulti
			,	LoseCountMulti = tB.LoseCountMulti
			,	BattlePointBest = tB.BattlePointBest
			,	KillTotal = tB.KillTotal
			,	ChainKillTotal = tB.ChainKillTotal
			,	BlowBalloonTotal = tB.BlowBalloonTotal
		FROM	@BattleEndInfos_ tB
		WHERE	dbo.tUser.[UID] = tB.[UID]

		UPDATE	dbo.tQuest
		SET		[Count] = tD.[Count]
		FROM	dbo.tQuest tQ
			,	@DoneQuests_ tD
		WHERE	tQ.[UID] = tD.[UID]
			AND	tQ.SlotIndex = tD.SlotIndex

		COMMIT TRAN

		RETURN 0
		
	END TRY
	BEGIN CATCH
		IF
			ERROR_NUMBER() <> 50000 AND
			ERROR_NUMBER() <> 266
		SET @Ret = ERROR_NUMBER()
		
		IF XACT_STATE() <> 0
			ROLLBACK TRAN
		
		RETURN @Ret
		
	END CATCH
END
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[spBuy]
	@UID_ BIGINT
,	@Ticket_ INT
,	@Gold_ INT
,	@Dia00_ INT
,	@Dia01_ INT
,	@Dia02_ INT
,	@Dia03_ INT
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	UPDATE	dbo.tUser
	SET		Ticket = @Ticket_
		,	Gold = @Gold_
		,	Dia00 = @Dia00_
		,	Dia01 = @Dia01_
		,	Dia02 = @Dia02_
		,	Dia03 = @Dia03_
	WHERE	[UID] = @UID_

	RETURN 0
END
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[spBuyChar]
	@UID_ BIGINT
,	@Ticket_ INT
,	@Gold_ INT
,	@Dia00_ INT
,	@Dia01_ INT
,	@Dia02_ INT
,	@Dia03_ INT
,	@CharCode_ INT
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	DECLARE @Ret INT = 0
	
	BEGIN TRY

		BEGIN TRAN

		UPDATE	dbo.tUser
		SET		Ticket = @Ticket_
			,	Gold = @Gold_
			,	Dia00 = @Dia00_
			,	Dia01 = @Dia01_
			,	Dia02 = @Dia02_
			,	Dia03 = @Dia03_
		WHERE	[UID] = @UID_

		INSERT INTO dbo.tChar ([UID], CharCode)
		VALUES (@UID_, @CharCode_)

		COMMIT TRAN

		RETURN 0
		
	END TRY
	BEGIN CATCH
		IF
			ERROR_NUMBER() <> 50000 AND
			ERROR_NUMBER() <> 266
		SET @Ret = ERROR_NUMBER()

		IF XACT_STATE() <> 0
			ROLLBACK TRAN

		RETURN @Ret
		
	END CATCH
END
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[spChangeNickBegin]
	@UID_ BIGINT
,	@NewNick_ NVARCHAR(32)
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	UPDATE	dbo.tUser
	SET		NewNick = @NewNick_
	WHERE	[UID] = @UID_

	RETURN 0

END
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[spChangeNickEnd]
	@UID_ BIGINT
,	@Ticket_ INT
,	@Gold_ INT
,	@Dia00_ INT
,	@Dia01_ INT
,	@Dia02_ INT
,	@Dia03_ INT
,	@FreeCount_ INT
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	UPDATE	dbo.tUser
	SET		Ticket = @Ticket_
		,	Gold = @Gold_
		,	Dia00 = @Dia00_
		,	Dia01 = @Dia01_
		,	Dia02 = @Dia02_
		,	Dia03 = @Dia03_
		,	ChangeNickFreeCount = @FreeCount_
		,	NewNick = N''
	WHERE	[UID] = @UID_

	RETURN 0

END
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[spChangeNickEndFail]
	@UID_ BIGINT
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	UPDATE	dbo.tUser
	SET		NewNick = N''
	WHERE	[UID] = @UID_

	RETURN 0

END
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[spCheckID]
	@UID_ BIGINT
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	SELECT	Point
	FROM	dbo.tUser
	WHERE	[UID] = @UID_

	RETURN 0

END
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[spClear]
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	TRUNCATE TABLE dbo.sys_tbl_Friend
	TRUNCATE TABLE dbo.sys_tbl_User
	TRUNCATE TABLE dbo.tChar
	TRUNCATE TABLE dbo.tCouponUsedUser
	TRUNCATE TABLE dbo.tPackage
	TRUNCATE TABLE dbo.tProductPrice
	TRUNCATE TABLE dbo.tQuest
	TRUNCATE TABLE dbo.tUser


	RETURN 0
END

/****** Object:  StoredProcedure [dbo].[spRankingConfigLoad]    Script Date: 2021-01-08 오후 5:57:20 ******/
SET ANSI_NULLS ON
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[spCouponUse]
	@UID_ BIGINT
,	@Ticket_ INT
,	@Gold_ INT
,	@Dia00_ INT
,	@Dia01_ INT
,	@Dia02_ INT
,	@Dia03_ INT
,	@CharsAdded_ dbo.TCharCodes READONLY
,	@Key_ NVARCHAR(256)
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	DECLARE @Ret INT = 0
	
	BEGIN TRY

		BEGIN TRAN

		UPDATE	dbo.tUser
		SET		Ticket = @Ticket_
			,	Gold = @Gold_
			,	Dia00 = @Dia00_
			,	Dia01 = @Dia01_
			,	Dia02 = @Dia02_
			,	Dia03 = @Dia03_
		WHERE	[UID] = @UID_

		INSERT INTO dbo.tChar ([UID], CharCode)
			SELECT @UID_, CharCode FROM @CharsAdded_

		INSERT	dbo.tCouponUsedUser ([UID], [Key])
		VALUES (@UID_, @Key_)

		COMMIT TRAN

		RETURN 0
		
	END TRY
	BEGIN CATCH
		IF
			ERROR_NUMBER() <> 50000 AND
			ERROR_NUMBER() <> 266
		SET @Ret = ERROR_NUMBER()
		
		IF XACT_STATE() <> 0
			ROLLBACK TRAN

		RETURN @Ret
		
	END CATCH
END
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[spFlyAwayBattleEnd]
	@UID_ BIGINT
,	@Ticket_ INT
,	@Gold_ INT
,	@Dia00_ INT
,	@Dia01_ INT
,	@Dia02_ INT
,	@Dia03_ INT
,	@PointBest_ INT
,	@ComboBest_ INT
,	@DoneQuests_ dbo.TUIDQuestSlotIndexCounts READONLY
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	DECLARE @Ret INT = 0
	
	BEGIN TRY

		BEGIN TRAN

		UPDATE	dbo.tUser
		SET		Ticket = @Ticket_
			,	Gold = @Gold_
			,	Dia00 = @Dia00_
			,	Dia01 = @Dia01_
			,	Dia02 = @Dia02_
			,	Dia03 = @Dia03_
			,	IslandPointBest = @PointBest_
			,	IslandComboBest = @ComboBest_
		WHERE	[UID] = @UID_

		UPDATE	dbo.tQuest
		SET		[Count] = tD.[Count]
		FROM	dbo.tQuest tQ
			,	@DoneQuests_ tD
		WHERE	tQ.[UID] = tD.[UID]
			AND	tQ.SlotIndex = tD.SlotIndex

		COMMIT TRAN

		RETURN 0
		
	END TRY
	BEGIN CATCH
		IF
			ERROR_NUMBER() <> 50000 AND
			ERROR_NUMBER() <> 266
		SET @Ret = ERROR_NUMBER()
		
		IF XACT_STATE() <> 0
			ROLLBACK TRAN

		RETURN @Ret
		
	END CATCH
END
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[spFlyAwayBattleStart]
	@UID_ BIGINT
,	@Ticket_ INT
,	@Gold_ INT
,	@Dia00_ INT
,	@Dia01_ INT
,	@Dia02_ INT
,	@Dia03_ INT
,	@Count_ INT
,	@RefreshTime_ BIGINT
,	@DoneQuests_ dbo.TUIDQuestSlotIndexCounts READONLY
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	DECLARE @Ret INT = 0
	
	BEGIN TRY

		BEGIN TRAN

		UPDATE	dbo.tUser
		SET		Ticket = @Ticket_
			,	Gold = @Gold_
			,	Dia00 = @Dia00_
			,	Dia01 = @Dia01_
			,	Dia02 = @Dia02_
			,	Dia03 = @Dia03_
			,	IslandCount = @Count_
			,	IslandRefreshTime = @RefreshTime_
		WHERE	[UID] = @UID_

		UPDATE	dbo.tQuest
		SET		[Count] = tD.[Count]
		FROM	dbo.tQuest tQ
			,	@DoneQuests_ tD
		WHERE	tQ.[UID] = tD.[UID]
			AND	tQ.SlotIndex = tD.SlotIndex

		COMMIT TRAN

		RETURN 0
		
	END TRY
	BEGIN CATCH
		IF
			ERROR_NUMBER() <> 50000 AND
			ERROR_NUMBER() <> 266
		SET @Ret = ERROR_NUMBER()
		
		IF XACT_STATE() <> 0
			ROLLBACK TRAN

		RETURN @Ret
		
	END CATCH
END
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[spJoin]
	@UID_ BIGINT
,	@Ticket_ INT
,	@Gold_ INT
,	@Dia00_ INT
,	@Dia01_ INT
,	@Dia02_ INT
,	@Dia03_ INT
,	@Debug_ TINYINT
,	@DefaultCharCode_ INT
,	@SingleCount_ INT
,	@SingleRefreshTime_ BIGINT
,	@IslandCount_ INT
,	@IslandRefreshTime_ BIGINT
,	@QuestDailyCompleteRefreshTime_ BIGINT
,	@ChangeNickFreeCount_ INT
,	@InsertedTimePoint_ BIGINT
,	@Language_ TINYINT
,	@OS_ TINYINT
,	@CountryCode_ CHAR(2)
,	@CharCodes_ dbo.TCharCodes READONLY
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	DECLARE @Ret INT = 0
	
	BEGIN TRY

		BEGIN TRAN

		INSERT INTO dbo.tUser (
			[UID],
			Ticket,
			Gold,
			Dia00,
			Dia01,
			Dia02,
			Dia03,
			Debug,
			SelectedCharCode,
			SingleCount,
			SingleRefreshTime,
			IslandCount,
			IslandRefreshTime,
			QuestDailyCompleteRefreshTime,
			ChangeNickFreeCount,
			InsertedTimePoint,
			[Language],
			OS,
			CountryCode)
		VALUES (
			@UID_,
			@Ticket_,
			@Gold_,
			@Dia00_,
			@Dia01_,
			@Dia02_,
			@Dia03_,
			@Debug_,
			@DefaultCharCode_,
			@SingleCount_,
			@SingleRefreshTime_,
			@IslandCount_,
			@IslandRefreshTime_,
			@QuestDailyCompleteRefreshTime_,
			@ChangeNickFreeCount_,
			@InsertedTimePoint_,
			@Language_, @OS_,
			@CountryCode_)

		INSERT INTO dbo.tChar ([UID], [CharCode])
			SELECT	@UID_, CharCode
			FROM	@CharCodes_

		EXEC dbo.spLogin @UID_, @OS_, @CountryCode_ -- 서버에서 생성된 계정정보를 직접 넣을 경우 Login 시에 넣는 부분과 코드 중복이 생겨 이렇게 처리하여 Login 부분 재활용

		COMMIT TRAN

		RETURN 0
		
	END TRY
	BEGIN CATCH
		IF
			ERROR_NUMBER() <> 50000 AND
			ERROR_NUMBER() <> 266
		SET @Ret = ERROR_NUMBER()
		
		IF XACT_STATE() <> 0
			ROLLBACK TRAN
		
		RETURN @Ret
		
	END CATCH
END

/****** Object:  StoredProcedure [dbo].[spLogin]    Script Date: 2021-01-08 오후 6:01:49 ******/
SET ANSI_NULLS ON
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[spLogin]
	@UID_ BIGINT
,	@OS_ TINYINT
,	@CountryCode_ CHAR(2)
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	DECLARE @Ret INT = 0

	BEGIN TRY

		SELECT	Ticket,
				Gold,
				Dia00,
				Dia01,
				Dia02,
				Dia03,
				Debug,
				SelectedCharCode,
				SingleCount,
				SingleRefreshTime,
				IslandCount,
				IslandRefreshTime,
				QuestDailyCompleteRefreshTime,
				ChangeNickFreeCount,
				[Exp],
				CanPushAtNight,
				eloPoint,
				Point,
				PointBest,
				NextRewardRankIndex,
				WinCountSolo,
				LoseCountSolo,
				WinCountMulti,
				LoseCountMulti,
				BattlePointBest,
				SinglePointBest,
				IslandPointBest,
				IslandComboBest,
				KillTotal,
				ChainKillTotal,
				BlowBalloonTotal,
				QuestDailyCompleteCount,
				TutorialReward,
				RankingRewardedCounter,
				NewNick,
				InvalidDisconnectEndTime,
				InvalidDisconnectMatchBlockEndTime,
				InvalidDisconnectCount,
				[Language]
		FROM	dbo.tUser
		WHERE	[UID] = @UID_

		SELECT	CharCode, SkinCode, HatCode, BalloonCode
		FROM	dbo.tChar
		WHERE	[UID] = @UID_

		SELECT	SlotIndex, Code, [Count], CoolEndTime
		FROM	dbo.tQuest
		WHERE	[UID] = @UID_

		SELECT	[Key]
		FROM	dbo.tCouponUsedUser
		WHERE	[UID] = @UID_

		RETURN 0

	END TRY
	BEGIN CATCH

		IF
			ERROR_NUMBER() <> 50000 AND
			ERROR_NUMBER() <> 266
		SET @Ret = ERROR_NUMBER()
		
		RETURN @Ret
		
	END CATCH

END

/****** Object:  StoredProcedure [dbo].[spRankingReward]    Script Date: 2021-01-08 오후 6:02:52 ******/
SET ANSI_NULLS ON
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[spQuestDailyCompleteReward]
	@UID_ BIGINT
,	@Ticket_ INT
,	@Gold_ INT
,	@Dia00_ INT
,	@Dia01_ INT
,	@Dia02_ INT
,	@Dia03_ INT
,	@CharsAdded_ dbo.TCharCodes READONLY
,	@RefreshTime_ BIGINT
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	DECLARE @Ret INT = 0
	
	BEGIN TRY

		BEGIN TRAN

		UPDATE	dbo.tUser
		SET		Ticket = @Ticket_
			,	Gold = @Gold_
			,	Dia00 = @Dia00_
			,	Dia01 = @Dia01_
			,	Dia02 = @Dia02_
			,	Dia03 = @Dia03_
			,	QuestDailyCompleteCount = 0
			,	QuestDailyCompleteRefreshTime = @RefreshTime_
		WHERE	[UID] = @UID_

		INSERT INTO dbo.tChar ([UID], CharCode)
			SELECT @UID_, CharCode FROM @CharsAdded_

		COMMIT TRAN

		RETURN 0
		
	END TRY
	BEGIN CATCH
		IF
			ERROR_NUMBER() <> 50000 AND
			ERROR_NUMBER() <> 266
		SET @Ret = ERROR_NUMBER()
		
		IF XACT_STATE() <> 0
			ROLLBACK TRAN

		RETURN @Ret
		
	END CATCH
END
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[spQuestDel]
	@UID_ BIGINT
,	@SlotIndices_ [dbo].[TQuestSlotIndices] READONLY
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	DELETE	dbo.tQuest
	FROM	dbo.tQuest tQ
		,	@SlotIndices_ tD
	WHERE	[UID] = @UID_
		AND	tQ.SlotIndex = tD.SlotIndex

	RETURN 0
		
END
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[spQuestDone]
	@UID_ BIGINT
,	@SlotIndex_ TINYINT
,	@Count_ INT
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	UPDATE	dbo.tQuest
	SET		[Count] = @Count_
	WHERE	[UID] = @UID_
		AND	SlotIndex = @SlotIndex_

	RETURN 0

END
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[spQuestNew]
	@UID_ BIGINT
,	@SlotIndexCodes_ [dbo].[TQuestSlotIndexCodes] READONLY
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	INSERT INTO dbo.tQuest ([UID], SlotIndex, Code, [Count])
		SELECT @UID_, SlotIndex, Code, 0 FROM @SlotIndexCodes_

	RETURN 0
		
END
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[spQuestReward]
	@UID_ BIGINT
,	@Ticket_ INT
,	@Gold_ INT
,	@Dia00_ INT
,	@Dia01_ INT
,	@Dia02_ INT
,	@Dia03_ INT
,	@CharsAdded_ dbo.TCharCodes READONLY
,	@SlotIndex_ TINYINT
,	@NewCode_ INT
,	@CoolEndTime_ BIGINT
,	@DailyCompleteCount_ INT
,	@DailyCompleteRefreshTime_ BIGINT
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	DECLARE @Ret INT = 0
	
	BEGIN TRY

		BEGIN TRAN

		UPDATE	dbo.tUser
		SET		Ticket = @Ticket_
			,	Gold = @Gold_
			,	Dia00 = @Dia00_
			,	Dia01 = @Dia01_
			,	Dia02 = @Dia02_
			,	Dia03 = @Dia03_
			,	QuestDailyCompleteCount = @DailyCompleteCount_
			,	QuestDailyCompleteRefreshTime = @DailyCompleteRefreshTime_
		WHERE	[UID] = @UID_

		INSERT INTO dbo.tChar ([UID], CharCode)
			SELECT @UID_, CharCode FROM @CharsAdded_

		IF @NewCode_ = 0
		BEGIN
			DELETE	dbo.tQuest
			WHERE	[UID] = @UID_
				AND	SlotIndex = @SlotIndex_
		END
		ELSE
		BEGIN
			UPDATE	dbo.tQuest
			SET		Code = @NewCode_
				,	[Count] = 0
				,	CoolEndTime = @CoolEndTime_
			WHERE	[UID] = @UID_
				AND	SlotIndex = @SlotIndex_
		END

		COMMIT TRAN

		RETURN 0
		
	END TRY
	BEGIN CATCH
		IF
			ERROR_NUMBER() <> 50000 AND
			ERROR_NUMBER() <> 266
		SET @Ret = ERROR_NUMBER()
		
		IF XACT_STATE() <> 0
			ROLLBACK TRAN

		RETURN @Ret
		
	END CATCH
END
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[spQuestSet]
	@UID_ BIGINT
,	@SlotIndex_ TINYINT
,	@NewCode_ INT
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	UPDATE	dbo.tQuest
	SET		Code = @NewCode_
		,	[Count] = 0
		,	CoolEndTime = 0
	WHERE	[UID] = @UID_
		AND	SlotIndex = @SlotIndex_

	RETURN 0

END
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO


CREATE PROCEDURE [dbo].[spRankingReward]
	@UID_ BIGINT
,	@Ticket_ INT
,	@Gold_ INT
,	@Dia00_ INT
,	@Dia01_ INT
,	@Dia02_ INT
,	@Dia03_ INT
,	@CharsAdded_ dbo.TCharCodes READONLY
,	@RankingRewardedCounter_ BIGINT
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	DECLARE @Ret INT = 0
	
	BEGIN TRY

		BEGIN TRAN

		UPDATE	dbo.tUser
		SET		Ticket = @Ticket_
			,	Gold = @Gold_
			,	Dia00 = @Dia00_
			,	Dia01 = @Dia01_
			,	Dia02 = @Dia02_
			,	Dia03 = @Dia03_
			,	RankingRewardedCounter = @RankingRewardedCounter_
		WHERE	[UID] = @UID_

		INSERT INTO dbo.tChar ([UID], CharCode)
			SELECT @UID_, CharCode FROM @CharsAdded_

		COMMIT TRAN

		RETURN 0
		
	END TRY
	BEGIN CATCH
		IF
			ERROR_NUMBER() <> 50000 AND
			ERROR_NUMBER() <> 266
		SET @Ret = ERROR_NUMBER()

		IF XACT_STATE() <> 0
			ROLLBACK TRAN

		RETURN @Ret
		
	END CATCH
END
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[spRankReward]
	@UID_ BIGINT
,	@Ticket_ INT
,	@Gold_ INT
,	@Dia00_ INT
,	@Dia01_ INT
,	@Dia02_ INT
,	@Dia03_ INT
,	@CharsAdded_ dbo.TCharCodes READONLY
,	@NextRewardRankIndex_ INT
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	DECLARE @Ret INT = 0
	
	BEGIN TRY

		BEGIN TRAN

		UPDATE	dbo.tUser
		SET		Ticket = @Ticket_
			,	Gold = @Gold_
			,	Dia00 = @Dia00_
			,	Dia01 = @Dia01_
			,	Dia02 = @Dia02_
			,	Dia03 = @Dia03_
			,	NextRewardRankIndex = @NextRewardRankIndex_
		WHERE	[UID] = @UID_

		INSERT INTO dbo.tChar ([UID], CharCode)
			SELECT @UID_, CharCode FROM @CharsAdded_

		COMMIT TRAN

		RETURN 0
		
	END TRY
	BEGIN CATCH
		IF
			ERROR_NUMBER() <> 50000 AND
			ERROR_NUMBER() <> 266
		SET @Ret = ERROR_NUMBER()

		IF XACT_STATE() <> 0
			ROLLBACK TRAN

		RETURN @Ret
		
	END CATCH
END
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[spSelectChar]
	@UID_ BIGINT
,	@CharCode_ INT
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	UPDATE	dbo.tUser
	SET		SelectedCharCode = @CharCode_
	WHERE	[UID] = @UID_

	RETURN 0

END
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[spSetChar]
	@UID_ BIGINT
,	@CharCodes_ dbo.TCharCodes READONLY
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	INSERT INTO dbo.tChar ([UID], CharCode)
		SELECT	@UID_, CharCode
		FROM	@CharCodes_

	RETURN 0

END
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[spSetPoint]
	@UID_ BIGINT
,	@Point_ INT
,	@PointBest_ INT
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	UPDATE	dbo.tUser
	SET		Point = @Point_
		,	PointBest = @PointBest_
	WHERE	[UID] = @UID_

	RETURN 0

END
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[spSetResources]
	@UID_ BIGINT
,	@Ticket_ INT
,	@Gold_ INT
,	@Dia00_ INT
,	@Dia01_ INT
,	@Dia02_ INT
,	@Dia03_ INT
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	UPDATE	dbo.tUser
	SET		Ticket = @Ticket_
		,	Gold = @Gold_
		,	Dia00 = @Dia00_
		,	Dia01 = @Dia01_
		,	Dia02 = @Dia02_
		,	Dia03 = @Dia03_
	WHERE	[UID] = @UID_

	RETURN 0

END
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[spSetUserExp]
	@UID_ BIGINT
,	@Exp_ BIGINT
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	UPDATE	dbo.tUser
	SET		[Exp] = @Exp_
	WHERE	[UID] = @UID_

	RETURN 0

END
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[spTutorialReward]
	@UID_ BIGINT
,	@Ticket_ INT
,	@Gold_ INT
,	@Dia00_ INT
,	@Dia01_ INT
,	@Dia02_ INT
,	@Dia03_ INT
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	UPDATE	dbo.tUser
	SET		Ticket = @Ticket_
		,	Gold = @Gold_
		,	Dia00 = @Dia00_
		,	Dia01 = @Dia01_
		,	Dia02 = @Dia02_
		,	Dia03 = @Dia03_
		,	TutorialReward = 1
	WHERE	[UID] = @UID_

	RETURN 0

END
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[spUnsetChar]
	@UID_ BIGINT
,	@CharCodes_ dbo.TCharCodes READONLY
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	DELETE	dbo.tChar
	FROM	dbo.tChar tC
		,	@CharCodes_ tD
	WHERE	[UID] = @UID_
		AND	tC.CharCode = tD.CharCode

	RETURN 0

END
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[spUpdateInvalidDisconnectInfo]
	@UID_ BIGINT
,	@EndTime_ BIGINT
,	@MatchBlockEndTime_ BIGINT
,	@Count_ INT
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	UPDATE	dbo.tUser
	SET		InvalidDisconnectEndTime = @EndTime_
		,	InvalidDisconnectMatchBlockEndTime = @MatchBlockEndTime_
		,	InvalidDisconnectCount = @Count_
	WHERE	[UID] = @UID_

	RETURN 0
		
END
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[spUpdateMatchBlockEndTime]
	@UID_ BIGINT
,	@MatchBlockEndTime_ BIGINT
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	UPDATE	dbo.tUser
	SET		InvalidDisconnectMatchBlockEndTime = @MatchBlockEndTime_
	WHERE	[UID] = @UID_

	RETURN 0
		
END
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

CREATE PROCEDURE [dbo].[sys_sp_AddFriendBegin]
	@UID_ BIGINT
,	@FriendUID_ BIGINT
,	@FriendNick_ NVARCHAR(MAX)
,	@FriendState_ TINYINT
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	DECLARE @Ret INT = 0
	
	BEGIN TRY

		INSERT	dbo.sys_tbl_Friend ([UID], FriendUID, FriendNick, FriendState)
		VALUES (@UID_, @FriendUID_, @FriendNick_, @FriendState_)

		RETURN 0
		
	END TRY
	BEGIN CATCH
		IF
			ERROR_NUMBER() <> 50000 AND
			ERROR_NUMBER() <> 266
		SET @Ret = ERROR_NUMBER()
		
		RETURN @Ret
		
	END CATCH
END
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

CREATE PROCEDURE [dbo].[sys_sp_AddFriendEnd]
	@UID_ BIGINT
,	@FriendUID_ BIGINT
,	@FriendState_ TINYINT
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	UPDATE	dbo.sys_tbl_Friend
	SET		FriendState = @FriendState_
	WHERE	[UID] = @UID_
		AND	FriendUID = @FriendUID_

	RETURN 0
END
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

CREATE PROCEDURE [dbo].[sys_sp_AddFriendFail]
	@UID_ BIGINT
,	@FriendUID_ BIGINT
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	DELETE	dbo.sys_tbl_Friend
	WHERE	[UID] = @UID_
		AND	FriendUID = @FriendUID_

	RETURN 0
END
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

CREATE PROCEDURE [dbo].[sys_sp_AddFriendRequest]
	@UID_ BIGINT
,	@FriendUID_ BIGINT
,	@FriendNick_ NVARCHAR(MAX)
,	@FriendState_ TINYINT
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	MERGE dbo.sys_tbl_Friend WITH(HOLDLOCK) AS tT
	USING (SELECT @UID_ [UID], @FriendUID_ FriendUID) AS tS
	ON (tT.[UID] = tS.[UID] AND tT.FriendUID = tS.FriendUID)
	WHEN NOT MATCHED BY TARGET THEN
		INSERT ([UID], FriendUID, FriendNick, FriendState)
		VALUES (@UID_, @FriendUID_, @FriendNick_, @FriendState_);

	SELECT @@ROWCOUNT

	RETURN 0
END
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

CREATE PROCEDURE [dbo].[sys_sp_AllowFriend]
	@UID_ BIGINT
,	@FriendUID_ BIGINT
,	@FriendState_ TINYINT
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	UPDATE	dbo.sys_tbl_Friend
	SET		FriendState = @FriendState_
	WHERE	[UID] = @UID_
		AND	FriendUID = @FriendUID_

	RETURN 0
END
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

CREATE PROCEDURE [dbo].[sys_sp_BlockFriend]
	@UID_ BIGINT
,	@FriendUID_ BIGINT
,	@FriendState_ TINYINT
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	UPDATE	dbo.sys_tbl_Friend
	SET		FriendState = @FriendState_
	WHERE	[UID] = @UID_
		AND	FriendUID = @FriendUID_

	RETURN 0
END
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

CREATE PROCEDURE [dbo].[sys_sp_ChangeNick]
	@UID_ BIGINT
,	@Nick_ NVARCHAR(MAX)
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	UPDATE	dbo.sys_tbl_User
	SET		Nick = @Nick_
	WHERE	[UID] = @UID_

	RETURN 0

END
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

CREATE PROCEDURE [dbo].[sys_sp_ChangeState]
	@UID_ BIGINT
,	@State_ TINYINT
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	UPDATE	dbo.sys_tbl_User
	SET		[State] = @State_
	WHERE	[UID] = @UID_

	RETURN 0
END
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

CREATE PROCEDURE [dbo].[sys_sp_Check]
	@UID_ BIGINT
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON
	
	BEGIN TRY

		SELECT	PunishEndTime
		FROM	dbo.sys_tbl_User
		WHERE	[UID] = @UID_

		RETURN 0

	END TRY
	BEGIN CATCH

		RETURN ERROR_NUMBER()

	END CATCH

END
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

CREATE PROCEDURE [dbo].[sys_sp_Clear]
	@UID_ BIGINT
,	@ID_ NVARCHAR(MAX)
,	@Nick_ NVARCHAR(MAX)
,	@State_ TINYINT
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	TRUNCATE TABLE dbo.sys_tbl_User
	TRUNCATE TABLE dbo.sys_tbl_Friend

	RETURN 0

END
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

CREATE PROCEDURE [dbo].[sys_sp_Create]
	@UID_ BIGINT
,	@ID_ NVARCHAR(MAX)
,	@Nick_ NVARCHAR(MAX)
,	@State_ TINYINT
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	DECLARE @Ret INT = 0

	BEGIN TRY

		DECLARE @ID VARBINARY(MAX)
		DECLARE @Nick NVARCHAR(MAX)

		SELECT	@ID = ID, @Nick = Nick
		FROM	dbo.sys_tbl_User
		WHERE	[UID] = @UID_

		IF @ID IS NOT NULL
		BEGIN
			UPDATE	dbo.sys_tbl_User
			SET		ID = HASHBYTES('SHA2_256', @ID_)
			WHERE	[UID] = @UID_
		END
		ELSE
		BEGIN
			INSERT INTO dbo.sys_tbl_User ([UID], ID, Nick, [State])
			VALUES (@UID_, HASHBYTES('SHA2_256', @ID_), @Nick_, @State_)
		END

		RETURN 0

	END TRY
	BEGIN CATCH

		IF
			ERROR_NUMBER() <> 50000 AND
			ERROR_NUMBER() <> 266
		SET @Ret = ERROR_NUMBER()

		RETURN @Ret

	END CATCH

END
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

CREATE PROCEDURE [dbo].[sys_sp_DenyFriend]
	@UID_ BIGINT
,	@FriendUID_ BIGINT
,	@FriendState_ TINYINT
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	UPDATE	dbo.sys_tbl_Friend
	SET		FriendState = @FriendState_
	WHERE	[UID] = @UID_
		AND	FriendUID = @FriendUID_

	RETURN 0
END
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

CREATE PROCEDURE [dbo].[sys_sp_Login]
	@UID_ BIGINT
,	@ID_ NVARCHAR(MAX)
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON
	
	BEGIN TRY

		SELECT	Nick, [State], PunishEndTime
		FROM	dbo.sys_tbl_User
		WHERE	[UID] = @UID_
			AND ID = HASHBYTES('SHA2_256', @ID_)

		SELECT	FriendUID, FriendNick, FriendState
		FROM	dbo.sys_tbl_Friend
		WHERE	[UID] = @UID_

		RETURN 0

	END TRY
	BEGIN CATCH

		RETURN ERROR_NUMBER()

	END CATCH

END
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

CREATE PROCEDURE [dbo].[sys_sp_Punish]
	@UID_ BIGINT
,	@EndTime_ BIGINT
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	BEGIN TRY

		UPDATE	dbo.sys_tbl_User
		SET		PunishEndTime = @EndTime_
		WHERE	[UID] = @UID_

		RETURN 0

	END TRY
	BEGIN CATCH

		RETURN ERROR_NUMBER()

	END CATCH

END
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

CREATE PROCEDURE [dbo].[sys_sp_UnBlockFriend]
	@UID_ BIGINT
,	@FriendUID_ BIGINT
,	@FriendState_ TINYINT
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	UPDATE	dbo.sys_tbl_Friend
	SET		FriendState = @FriendState_
	WHERE	[UID] = @UID_
		AND	FriendUID = @FriendUID_

	RETURN 0
END
GO
