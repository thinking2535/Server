/****** Object:  StoredProcedure [dbo].[sys_sp_UnBlockFriend]    Script Date: 2022-07-06 오후 6:59:17 ******/
DROP PROCEDURE IF EXISTS [dbo].[sys_sp_UnBlockFriend]
GO
/****** Object:  StoredProcedure [dbo].[sys_sp_Punish]    Script Date: 2022-07-06 오후 6:59:17 ******/
DROP PROCEDURE IF EXISTS [dbo].[sys_sp_Punish]
GO
/****** Object:  StoredProcedure [dbo].[sys_sp_Login]    Script Date: 2022-07-06 오후 6:59:17 ******/
DROP PROCEDURE IF EXISTS [dbo].[sys_sp_Login]
GO
/****** Object:  StoredProcedure [dbo].[sys_sp_DenyFriend]    Script Date: 2022-07-06 오후 6:59:17 ******/
DROP PROCEDURE IF EXISTS [dbo].[sys_sp_DenyFriend]
GO
/****** Object:  StoredProcedure [dbo].[sys_sp_Create]    Script Date: 2022-07-06 오후 6:59:17 ******/
DROP PROCEDURE IF EXISTS [dbo].[sys_sp_Create]
GO
/****** Object:  StoredProcedure [dbo].[sys_sp_Clear]    Script Date: 2022-07-06 오후 6:59:17 ******/
DROP PROCEDURE IF EXISTS [dbo].[sys_sp_Clear]
GO
/****** Object:  StoredProcedure [dbo].[sys_sp_Check]    Script Date: 2022-07-06 오후 6:59:17 ******/
DROP PROCEDURE IF EXISTS [dbo].[sys_sp_Check]
GO
/****** Object:  StoredProcedure [dbo].[sys_sp_ChangeState]    Script Date: 2022-07-06 오후 6:59:17 ******/
DROP PROCEDURE IF EXISTS [dbo].[sys_sp_ChangeState]
GO
/****** Object:  StoredProcedure [dbo].[sys_sp_ChangeNick]    Script Date: 2022-07-06 오후 6:59:17 ******/
DROP PROCEDURE IF EXISTS [dbo].[sys_sp_ChangeNick]
GO
/****** Object:  StoredProcedure [dbo].[sys_sp_BlockFriend]    Script Date: 2022-07-06 오후 6:59:17 ******/
DROP PROCEDURE IF EXISTS [dbo].[sys_sp_BlockFriend]
GO
/****** Object:  StoredProcedure [dbo].[sys_sp_AllowFriend]    Script Date: 2022-07-06 오후 6:59:17 ******/
DROP PROCEDURE IF EXISTS [dbo].[sys_sp_AllowFriend]
GO
/****** Object:  StoredProcedure [dbo].[sys_sp_AddFriendRequest]    Script Date: 2022-07-06 오후 6:59:17 ******/
DROP PROCEDURE IF EXISTS [dbo].[sys_sp_AddFriendRequest]
GO
/****** Object:  StoredProcedure [dbo].[sys_sp_AddFriendFail]    Script Date: 2022-07-06 오후 6:59:17 ******/
DROP PROCEDURE IF EXISTS [dbo].[sys_sp_AddFriendFail]
GO
/****** Object:  StoredProcedure [dbo].[sys_sp_AddFriendEnd]    Script Date: 2022-07-06 오후 6:59:17 ******/
DROP PROCEDURE IF EXISTS [dbo].[sys_sp_AddFriendEnd]
GO
/****** Object:  StoredProcedure [dbo].[sys_sp_AddFriendBegin]    Script Date: 2022-07-06 오후 6:59:17 ******/
DROP PROCEDURE IF EXISTS [dbo].[sys_sp_AddFriendBegin]
GO
/****** Object:  StoredProcedure [dbo].[spUnsetChar]    Script Date: 2022-07-06 오후 6:59:17 ******/
DROP PROCEDURE IF EXISTS [dbo].[spUnsetChar]
GO
/****** Object:  StoredProcedure [dbo].[spTutorialReward]    Script Date: 2022-07-06 오후 6:59:17 ******/
DROP PROCEDURE IF EXISTS [dbo].[spTutorialReward]
GO
/****** Object:  StoredProcedure [dbo].[spSetUserExp]    Script Date: 2022-07-06 오후 6:59:17 ******/
DROP PROCEDURE IF EXISTS [dbo].[spSetUserExp]
GO
/****** Object:  StoredProcedure [dbo].[spSetResources]    Script Date: 2022-07-06 오후 6:59:17 ******/
DROP PROCEDURE IF EXISTS [dbo].[spSetResources]
GO
/****** Object:  StoredProcedure [dbo].[spSetPoint]    Script Date: 2022-07-06 오후 6:59:17 ******/
DROP PROCEDURE IF EXISTS [dbo].[spSetPoint]
GO
/****** Object:  StoredProcedure [dbo].[spSetChar]    Script Date: 2022-07-06 오후 6:59:17 ******/
DROP PROCEDURE IF EXISTS [dbo].[spSetChar]
GO
/****** Object:  StoredProcedure [dbo].[spSelectChar]    Script Date: 2022-07-06 오후 6:59:17 ******/
DROP PROCEDURE IF EXISTS [dbo].[spSelectChar]
GO
/****** Object:  StoredProcedure [dbo].[spRankReward]    Script Date: 2022-07-06 오후 6:59:17 ******/
DROP PROCEDURE IF EXISTS [dbo].[spRankReward]
GO
/****** Object:  StoredProcedure [dbo].[spRankingReward]    Script Date: 2022-07-06 오후 6:59:17 ******/
DROP PROCEDURE IF EXISTS [dbo].[spRankingReward]
GO
/****** Object:  StoredProcedure [dbo].[spQuestReward]    Script Date: 2022-07-06 오후 6:59:17 ******/
DROP PROCEDURE IF EXISTS [dbo].[spQuestReward]
GO
/****** Object:  StoredProcedure [dbo].[spQuestNext]    Script Date: 2022-07-06 오후 6:59:17 ******/
DROP PROCEDURE IF EXISTS [dbo].[spQuestNext]
GO
/****** Object:  StoredProcedure [dbo].[spQuestNew]    Script Date: 2022-07-06 오후 6:59:17 ******/
DROP PROCEDURE IF EXISTS [dbo].[spQuestNew]
GO
/****** Object:  StoredProcedure [dbo].[spQuestDone]    Script Date: 2022-07-06 오후 6:59:17 ******/
DROP PROCEDURE IF EXISTS [dbo].[spQuestDone]
GO
/****** Object:  StoredProcedure [dbo].[spQuestDel]    Script Date: 2022-07-06 오후 6:59:17 ******/
DROP PROCEDURE IF EXISTS [dbo].[spQuestDel]
GO
/****** Object:  StoredProcedure [dbo].[spQuestDailyCompleteReward]    Script Date: 2022-07-06 오후 6:59:17 ******/
DROP PROCEDURE IF EXISTS [dbo].[spQuestDailyCompleteReward]
GO
/****** Object:  StoredProcedure [dbo].[spPurchase]    Script Date: 2022-07-06 오후 6:59:17 ******/
DROP PROCEDURE IF EXISTS [dbo].[spPurchase]
GO
/****** Object:  StoredProcedure [dbo].[spLogin]    Script Date: 2022-07-06 오후 6:59:17 ******/
DROP PROCEDURE IF EXISTS [dbo].[spLogin]
GO
/****** Object:  StoredProcedure [dbo].[spJoin]    Script Date: 2022-07-06 오후 6:59:17 ******/
DROP PROCEDURE IF EXISTS [dbo].[spJoin]
GO
/****** Object:  StoredProcedure [dbo].[spGacha]    Script Date: 2022-07-06 오후 6:59:17 ******/
DROP PROCEDURE IF EXISTS [dbo].[spGacha]
GO
/****** Object:  StoredProcedure [dbo].[spFlyAwayBattleStart]    Script Date: 2022-07-06 오후 6:59:17 ******/
DROP PROCEDURE IF EXISTS [dbo].[spFlyAwayBattleStart]
GO
/****** Object:  StoredProcedure [dbo].[spFlyAwayBattleEnd]    Script Date: 2022-07-06 오후 6:59:17 ******/
DROP PROCEDURE IF EXISTS [dbo].[spFlyAwayBattleEnd]
GO
/****** Object:  StoredProcedure [dbo].[spDailyReward]    Script Date: 2022-07-06 오후 6:59:17 ******/
DROP PROCEDURE IF EXISTS [dbo].[spDailyReward]
GO
/****** Object:  StoredProcedure [dbo].[spCouponUse]    Script Date: 2022-07-06 오후 6:59:17 ******/
DROP PROCEDURE IF EXISTS [dbo].[spCouponUse]
GO
/****** Object:  StoredProcedure [dbo].[spClear]    Script Date: 2022-07-06 오후 6:59:17 ******/
DROP PROCEDURE IF EXISTS [dbo].[spClear]
GO
/****** Object:  StoredProcedure [dbo].[spCheckID]    Script Date: 2022-07-06 오후 6:59:17 ******/
DROP PROCEDURE IF EXISTS [dbo].[spCheckID]
GO
/****** Object:  StoredProcedure [dbo].[spChangeNickEndFail]    Script Date: 2022-07-06 오후 6:59:17 ******/
DROP PROCEDURE IF EXISTS [dbo].[spChangeNickEndFail]
GO
/****** Object:  StoredProcedure [dbo].[spChangeNickEnd]    Script Date: 2022-07-06 오후 6:59:17 ******/
DROP PROCEDURE IF EXISTS [dbo].[spChangeNickEnd]
GO
/****** Object:  StoredProcedure [dbo].[spChangeNickBegin]    Script Date: 2022-07-06 오후 6:59:17 ******/
DROP PROCEDURE IF EXISTS [dbo].[spChangeNickBegin]
GO
/****** Object:  StoredProcedure [dbo].[spBuyPackage]    Script Date: 2022-07-06 오후 6:59:17 ******/
DROP PROCEDURE IF EXISTS [dbo].[spBuyPackage]
GO
/****** Object:  StoredProcedure [dbo].[spBuyChar]    Script Date: 2022-07-06 오후 6:59:17 ******/
DROP PROCEDURE IF EXISTS [dbo].[spBuyChar]
GO
/****** Object:  StoredProcedure [dbo].[spBuy]    Script Date: 2022-07-06 오후 6:59:17 ******/
DROP PROCEDURE IF EXISTS [dbo].[spBuy]
GO
/****** Object:  StoredProcedure [dbo].[spBattleEnd]    Script Date: 2022-07-06 오후 6:59:17 ******/
DROP PROCEDURE IF EXISTS [dbo].[spBattleEnd]
GO
/****** Object:  StoredProcedure [dbo].[spArrowDodgeBattleStart]    Script Date: 2022-07-06 오후 6:59:17 ******/
DROP PROCEDURE IF EXISTS [dbo].[spArrowDodgeBattleStart]
GO
/****** Object:  StoredProcedure [dbo].[spArrowDodgeBattleEnd]    Script Date: 2022-07-06 오후 6:59:17 ******/
DROP PROCEDURE IF EXISTS [dbo].[spArrowDodgeBattleEnd]
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
ALTER TABLE [dbo].[tUser] DROP CONSTRAINT IF EXISTS [DF_tUser_DailyRewardCountLeft_1]
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
ALTER TABLE [dbo].[tUser] DROP CONSTRAINT IF EXISTS [DF_tUser_IslandPassedCountBest]
GO
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[tUser]') AND type in (N'U'))
ALTER TABLE [dbo].[tUser] DROP CONSTRAINT IF EXISTS [DF_tUser_IslandPointBest]
GO
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[tUser]') AND type in (N'U'))
ALTER TABLE [dbo].[tUser] DROP CONSTRAINT IF EXISTS [DF_tUser_SingleSecondBest]
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
ALTER TABLE [dbo].[tUser] DROP CONSTRAINT IF EXISTS [DF_tUser_LoseCountSurvival]
GO
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[tUser]') AND type in (N'U'))
ALTER TABLE [dbo].[tUser] DROP CONSTRAINT IF EXISTS [DF_tUser_WinCountSurvival]
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
/****** Object:  Table [dbo].[tUser]    Script Date: 2022-07-06 오후 6:59:17 ******/
DROP TABLE IF EXISTS [dbo].[tUser]
GO
/****** Object:  Table [dbo].[tReceipt]    Script Date: 2022-07-06 오후 6:59:17 ******/
DROP TABLE IF EXISTS [dbo].[tReceipt]
GO
/****** Object:  Table [dbo].[tQuest]    Script Date: 2022-07-06 오후 6:59:17 ******/
DROP TABLE IF EXISTS [dbo].[tQuest]
GO
/****** Object:  Table [dbo].[tProductPrice]    Script Date: 2022-07-06 오후 6:59:17 ******/
DROP TABLE IF EXISTS [dbo].[tProductPrice]
GO
/****** Object:  Table [dbo].[tPackage]    Script Date: 2022-07-06 오후 6:59:17 ******/
DROP TABLE IF EXISTS [dbo].[tPackage]
GO
/****** Object:  Table [dbo].[tCouponUsedUser]    Script Date: 2022-07-06 오후 6:59:17 ******/
DROP TABLE IF EXISTS [dbo].[tCouponUsedUser]
GO
/****** Object:  Table [dbo].[tChar]    Script Date: 2022-07-06 오후 6:59:17 ******/
DROP TABLE IF EXISTS [dbo].[tChar]
GO
/****** Object:  Table [dbo].[sys_tbl_User]    Script Date: 2022-07-06 오후 6:59:17 ******/
DROP TABLE IF EXISTS [dbo].[sys_tbl_User]
GO
/****** Object:  Table [dbo].[sys_tbl_Friend]    Script Date: 2022-07-06 오후 6:59:17 ******/
DROP TABLE IF EXISTS [dbo].[sys_tbl_Friend]
GO
/****** Object:  UserDefinedFunction [dbo].[fTimeToDateTime]    Script Date: 2022-07-06 오후 6:59:17 ******/
DROP FUNCTION IF EXISTS [dbo].[fTimeToDateTime]
GO
/****** Object:  UserDefinedFunction [dbo].[fTimePointToDateTime]    Script Date: 2022-07-06 오후 6:59:17 ******/
DROP FUNCTION IF EXISTS [dbo].[fTimePointToDateTime]
GO
/****** Object:  UserDefinedTableType [dbo].[TUIDQuestTypeCounts]    Script Date: 2022-07-06 오후 6:59:17 ******/
DROP TYPE IF EXISTS [dbo].[TUIDQuestTypeCounts]
GO
/****** Object:  UserDefinedTableType [dbo].[TUIDQuestSlotIndexCounts]    Script Date: 2022-07-06 오후 6:59:17 ******/
DROP TYPE IF EXISTS [dbo].[TUIDQuestSlotIndexCounts]
GO
/****** Object:  UserDefinedTableType [dbo].[TUIDQuestCodeCounts]    Script Date: 2022-07-06 오후 6:59:17 ******/
DROP TYPE IF EXISTS [dbo].[TUIDQuestCodeCounts]
GO
/****** Object:  UserDefinedTableType [dbo].[TRankingReward]    Script Date: 2022-07-06 오후 6:59:17 ******/
DROP TYPE IF EXISTS [dbo].[TRankingReward]
GO
/****** Object:  UserDefinedTableType [dbo].[TQuestTypes]    Script Date: 2022-07-06 오후 6:59:17 ******/
DROP TYPE IF EXISTS [dbo].[TQuestTypes]
GO
/****** Object:  UserDefinedTableType [dbo].[TQuestSlotIndices]    Script Date: 2022-07-06 오후 6:59:17 ******/
DROP TYPE IF EXISTS [dbo].[TQuestSlotIndices]
GO
/****** Object:  UserDefinedTableType [dbo].[TQuestSlotIndexCodes]    Script Date: 2022-07-06 오후 6:59:17 ******/
DROP TYPE IF EXISTS [dbo].[TQuestSlotIndexCodes]
GO
/****** Object:  UserDefinedTableType [dbo].[TQuestCodes]    Script Date: 2022-07-06 오후 6:59:17 ******/
DROP TYPE IF EXISTS [dbo].[TQuestCodes]
GO
/****** Object:  UserDefinedTableType [dbo].[TNickPoint]    Script Date: 2022-07-06 오후 6:59:17 ******/
DROP TYPE IF EXISTS [dbo].[TNickPoint]
GO
/****** Object:  UserDefinedTableType [dbo].[TGachaGuaranteeCounts]    Script Date: 2022-07-06 오후 6:59:17 ******/
DROP TYPE IF EXISTS [dbo].[TGachaGuaranteeCounts]
GO
/****** Object:  UserDefinedTableType [dbo].[TCodes]    Script Date: 2022-07-06 오후 6:59:17 ******/
DROP TYPE IF EXISTS [dbo].[TCodes]
GO
/****** Object:  UserDefinedTableType [dbo].[TCharCodes]    Script Date: 2022-07-06 오후 6:59:17 ******/
DROP TYPE IF EXISTS [dbo].[TCharCodes]
GO
/****** Object:  UserDefinedTableType [dbo].[TBattleEndInfos]    Script Date: 2022-07-06 오후 6:59:17 ******/
DROP TYPE IF EXISTS [dbo].[TBattleEndInfos]
GO
/****** Object:  UserDefinedTableType [dbo].[TBattleEndInfos]    Script Date: 2022-07-06 오후 6:59:17 ******/
CREATE TYPE [dbo].[TBattleEndInfos] AS TABLE(
	[UID] [bigint] NULL,
	[Ticket] [int] NULL,
	[Gold] [int] NULL,
	[Dia] [int] NULL,
	[CP] [int] NULL,
	[DiaPaid] [int] NULL,
	[Dia00] [int] NULL,
	[Dia01] [int] NULL,
	[Dia02] [int] NULL,
	[Dia03] [int] NULL,
	[Point] [int] NULL,
	[PointBest] [int] NULL,
	[WinCountSolo] [int] NULL,
	[LoseCountSolo] [int] NULL,
	[WinCountSurvival] [int] NULL,
	[LoseCountSurvival] [int] NULL,
	[WinCountMulti] [int] NULL,
	[LoseCountMulti] [int] NULL,
	[BattlePointBest] [int] NULL,
	[KillTotal] [int] NULL,
	[ChainKillTotal] [int] NULL,
	[BlowBalloonTotal] [int] NULL
)
GO
/****** Object:  UserDefinedTableType [dbo].[TCharCodes]    Script Date: 2022-07-06 오후 6:59:17 ******/
CREATE TYPE [dbo].[TCharCodes] AS TABLE(
	[CharCode] [int] NULL
)
GO
/****** Object:  UserDefinedTableType [dbo].[TCodes]    Script Date: 2022-07-06 오후 6:59:17 ******/
CREATE TYPE [dbo].[TCodes] AS TABLE(
	[Code] [int] NULL
)
GO
/****** Object:  UserDefinedTableType [dbo].[TGachaGuaranteeCounts]    Script Date: 2022-07-06 오후 6:59:17 ******/
CREATE TYPE [dbo].[TGachaGuaranteeCounts] AS TABLE(
	[Index] [int] NULL,
	[GuaranteeCount] [int] NULL
)
GO
/****** Object:  UserDefinedTableType [dbo].[TNickPoint]    Script Date: 2022-07-06 오후 6:59:17 ******/
CREATE TYPE [dbo].[TNickPoint] AS TABLE(
	[Nick] [nvarchar](8) NULL,
	[Point] [int] NULL
)
GO
/****** Object:  UserDefinedTableType [dbo].[TQuestCodes]    Script Date: 2022-07-06 오후 6:59:17 ******/
CREATE TYPE [dbo].[TQuestCodes] AS TABLE(
	[Code] [int] NULL
)
GO
/****** Object:  UserDefinedTableType [dbo].[TQuestSlotIndexCodes]    Script Date: 2022-07-06 오후 6:59:17 ******/
CREATE TYPE [dbo].[TQuestSlotIndexCodes] AS TABLE(
	[SlotIndex] [tinyint] NULL,
	[Code] [int] NULL
)
GO
/****** Object:  UserDefinedTableType [dbo].[TQuestSlotIndices]    Script Date: 2022-07-06 오후 6:59:17 ******/
CREATE TYPE [dbo].[TQuestSlotIndices] AS TABLE(
	[SlotIndex] [tinyint] NULL
)
GO
/****** Object:  UserDefinedTableType [dbo].[TQuestTypes]    Script Date: 2022-07-06 오후 6:59:17 ******/
CREATE TYPE [dbo].[TQuestTypes] AS TABLE(
	[QuestType] [int] NULL
)
GO
/****** Object:  UserDefinedTableType [dbo].[TRankingReward]    Script Date: 2022-07-06 오후 6:59:17 ******/
CREATE TYPE [dbo].[TRankingReward] AS TABLE(
	[UID] [bigint] NULL,
	[Ranking] [int] NULL
)
GO
/****** Object:  UserDefinedTableType [dbo].[TUIDQuestCodeCounts]    Script Date: 2022-07-06 오후 6:59:17 ******/
CREATE TYPE [dbo].[TUIDQuestCodeCounts] AS TABLE(
	[UID] [bigint] NULL,
	[Code] [int] NULL,
	[Count] [int] NULL
)
GO
/****** Object:  UserDefinedTableType [dbo].[TUIDQuestSlotIndexCounts]    Script Date: 2022-07-06 오후 6:59:17 ******/
CREATE TYPE [dbo].[TUIDQuestSlotIndexCounts] AS TABLE(
	[SlotIndex] [tinyint] NULL,
	[Count] [int] NULL,
	[UID] [bigint] NULL
)
GO
/****** Object:  UserDefinedTableType [dbo].[TUIDQuestTypeCounts]    Script Date: 2022-07-06 오후 6:59:17 ******/
CREATE TYPE [dbo].[TUIDQuestTypeCounts] AS TABLE(
	[UID] [bigint] NULL,
	[QuestType] [int] NULL,
	[Count] [int] NULL
)
GO
/****** Object:  UserDefinedFunction [dbo].[fTimePointToDateTime]    Script Date: 2022-07-06 오후 6:59:17 ******/
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
/****** Object:  UserDefinedFunction [dbo].[fTimeToDateTime]    Script Date: 2022-07-06 오후 6:59:17 ******/
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
/****** Object:  Table [dbo].[sys_tbl_Friend]    Script Date: 2022-07-06 오후 6:59:17 ******/
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
/****** Object:  Table [dbo].[sys_tbl_User]    Script Date: 2022-07-06 오후 6:59:17 ******/
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
/****** Object:  Table [dbo].[tChar]    Script Date: 2022-07-06 오후 6:59:17 ******/
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
/****** Object:  Table [dbo].[tCouponUsedUser]    Script Date: 2022-07-06 오후 6:59:17 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[tCouponUsedUser](
	[UID] [bigint] NOT NULL,
	[Key] [nvarchar](256) NOT NULL
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[tPackage]    Script Date: 2022-07-06 오후 6:59:17 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[tPackage](
	[UID] [bigint] NOT NULL,
	[Code] [int] NOT NULL,
 CONSTRAINT [PK_tPackage] PRIMARY KEY CLUSTERED 
(
	[UID] ASC,
	[Code] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[tProductPrice]    Script Date: 2022-07-06 오후 6:59:17 ******/
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
/****** Object:  Table [dbo].[tQuest]    Script Date: 2022-07-06 오후 6:59:17 ******/
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
/****** Object:  Table [dbo].[tReceipt]    Script Date: 2022-07-06 오후 6:59:17 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[tReceipt](
	[OS] [tinyint] NOT NULL,
	[OrderID] [varchar](50) NOT NULL,
	[UID] [bigint] NOT NULL,
	[CountryCode] [char](2) NOT NULL,
	[PurchaseTime] [bigint] NOT NULL,
	[PurchaseType] [int] NOT NULL,
	[ProductID] [varchar](50) NOT NULL,
	[DiaCount] [int] NOT NULL
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[tUser]    Script Date: 2022-07-06 오후 6:59:17 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[tUser](
	[UID] [bigint] NOT NULL,
	[Ticket] [int] NOT NULL,
	[Gold] [int] NOT NULL,
	[Dia] [int] NOT NULL,
	[CP] [int] NOT NULL,
	[DiaPaid] [int] NOT NULL,
	[Dia00] [int] NULL,
	[Dia01] [int] NULL,
	[Dia02] [int] NULL,
	[Dia03] [int] NULL,
	[Debug] [tinyint] NOT NULL,
	[SelectedCharCode] [int] NOT NULL,
	[InsertedTimePoint] [bigint] NOT NULL,
	[OS] [tinyint] NOT NULL,
	[CountryCode] [char](2) NOT NULL,
	[Exp] [int] NOT NULL,
	[CanPushAtNight] [tinyint] NOT NULL,
	[Point] [int] NOT NULL,
	[PointBest] [int] NOT NULL,
	[LastGotRewardRankIndex] [int] NOT NULL,
	[WinCountSolo] [int] NOT NULL,
	[LoseCountSolo] [int] NOT NULL,
	[WinCountSurvival] [int] NOT NULL,
	[LoseCountSurvival] [int] NOT NULL,
	[WinCountMulti] [int] NOT NULL,
	[LoseCountMulti] [int] NOT NULL,
	[BattlePointBest] [int] NOT NULL,
	[SingleCount] [int] NOT NULL,
	[SingleRefreshTime] [bigint] NOT NULL,
	[SinglePointBest] [int] NOT NULL,
	[SingleBestTick] [bigint] NOT NULL,
	[IslandCount] [int] NOT NULL,
	[IslandRefreshTime] [bigint] NOT NULL,
	[IslandPointBest] [int] NOT NULL,
	[IslandPassedCountBest] [int] NOT NULL,
	[KillTotal] [int] NOT NULL,
	[ChainKillTotal] [int] NOT NULL,
	[BlowBalloonTotal] [int] NOT NULL,
	[QuestDailyCompleteCount] [int] NOT NULL,
	[QuestDailyCompleteRefreshTime] [bigint] NOT NULL,
	[ChangeNickFreeCount] [int] NOT NULL,
	[DailyRewardExpiredTime] [bigint] NOT NULL,
	[DailyRewardCountLeft] [int] NOT NULL,
	[TutorialReward] [tinyint] NOT NULL,
	[RankingRewardedCounter] [bigint] NOT NULL,
	[NewNick] [nvarchar](32) NOT NULL,
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
ALTER TABLE [dbo].[tUser] ADD  CONSTRAINT [DF_tUser_Point]  DEFAULT ((0)) FOR [Point]
GO
ALTER TABLE [dbo].[tUser] ADD  CONSTRAINT [DF_tUser_PointBest]  DEFAULT ((0)) FOR [PointBest]
GO
ALTER TABLE [dbo].[tUser] ADD  CONSTRAINT [DF_tUser_LastGotRewardRankIndex]  DEFAULT ((-1)) FOR [LastGotRewardRankIndex]
GO
ALTER TABLE [dbo].[tUser] ADD  CONSTRAINT [DF_tUser_WinCount]  DEFAULT ((0)) FOR [WinCountSolo]
GO
ALTER TABLE [dbo].[tUser] ADD  CONSTRAINT [DF_tUser_LoseCount]  DEFAULT ((0)) FOR [LoseCountSolo]
GO
ALTER TABLE [dbo].[tUser] ADD  CONSTRAINT [DF_tUser_WinCountSurvival]  DEFAULT ((0)) FOR [WinCountSurvival]
GO
ALTER TABLE [dbo].[tUser] ADD  CONSTRAINT [DF_tUser_LoseCountSurvival]  DEFAULT ((0)) FOR [LoseCountSurvival]
GO
ALTER TABLE [dbo].[tUser] ADD  CONSTRAINT [DF_tUser_WinCountSolo1]  DEFAULT ((0)) FOR [WinCountMulti]
GO
ALTER TABLE [dbo].[tUser] ADD  CONSTRAINT [DF_tUser_LoseCountSolo1]  DEFAULT ((0)) FOR [LoseCountMulti]
GO
ALTER TABLE [dbo].[tUser] ADD  CONSTRAINT [DF_tUser_BestBattlePoint]  DEFAULT ((0)) FOR [BattlePointBest]
GO
ALTER TABLE [dbo].[tUser] ADD  CONSTRAINT [DF_tUser_BattlePointBest1]  DEFAULT ((0)) FOR [SinglePointBest]
GO
ALTER TABLE [dbo].[tUser] ADD  CONSTRAINT [DF_tUser_SingleSecondBest]  DEFAULT ((0)) FOR [SingleBestTick]
GO
ALTER TABLE [dbo].[tUser] ADD  CONSTRAINT [DF_tUser_IslandPointBest]  DEFAULT ((0)) FOR [IslandPointBest]
GO
ALTER TABLE [dbo].[tUser] ADD  CONSTRAINT [DF_tUser_IslandPassedCountBest]  DEFAULT ((0)) FOR [IslandPassedCountBest]
GO
ALTER TABLE [dbo].[tUser] ADD  CONSTRAINT [DF_tUser_KillTotal]  DEFAULT ((0)) FOR [KillTotal]
GO
ALTER TABLE [dbo].[tUser] ADD  CONSTRAINT [DF_tUser_ChainKillTotal]  DEFAULT ((0)) FOR [ChainKillTotal]
GO
ALTER TABLE [dbo].[tUser] ADD  CONSTRAINT [DF_tUser_BlowBalloonTotal]  DEFAULT ((0)) FOR [BlowBalloonTotal]
GO
ALTER TABLE [dbo].[tUser] ADD  CONSTRAINT [DF_tUser_QuestDailyCompleteCount]  DEFAULT ((0)) FOR [QuestDailyCompleteCount]
GO
ALTER TABLE [dbo].[tUser] ADD  CONSTRAINT [DF_tUser_DailyRewardCountLeft_1]  DEFAULT ((0)) FOR [DailyRewardCountLeft]
GO
ALTER TABLE [dbo].[tUser] ADD  CONSTRAINT [DF_tUser_TutorialReward_1]  DEFAULT ((0)) FOR [TutorialReward]
GO
ALTER TABLE [dbo].[tUser] ADD  CONSTRAINT [DF_tUser_RankingRewardCounter]  DEFAULT ((0)) FOR [RankingRewardedCounter]
GO
ALTER TABLE [dbo].[tUser] ADD  CONSTRAINT [DF_tUser_ChangingNick]  DEFAULT (N'') FOR [NewNick]
GO
/****** Object:  StoredProcedure [dbo].[spArrowDodgeBattleEnd]    Script Date: 2022-07-06 오후 6:59:17 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[spArrowDodgeBattleEnd]
	@UID_ BIGINT
,	@Ticket_ INT
,	@Gold_ INT
,	@Dia_ INT
,	@CP_ INT
,	@DiaPaid_ INT
,	@Dia00_ INT
,	@Dia01_ INT
,	@Dia02_ INT
,	@Dia03_ INT
,	@PointBest_ INT
,	@BestTick_ INT
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
			,	Dia = @Dia_
			,	CP = @CP_
			,	DiaPaid = @DiaPaid_
			,	Dia00 = @Dia00_
			,	Dia01 = @Dia01_
			,	Dia02 = @Dia02_
			,	Dia03 = @Dia03_
			,	SinglePointBest = @PointBest_
			,	SingleBestTick = @BestTick_
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
/****** Object:  StoredProcedure [dbo].[spArrowDodgeBattleStart]    Script Date: 2022-07-06 오후 6:59:17 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[spArrowDodgeBattleStart]
	@UID_ BIGINT
,	@Ticket_ INT
,	@Gold_ INT
,	@Dia_ INT
,	@CP_ INT
,	@DiaPaid_ INT
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
			,	Dia = @Dia_
			,	CP = @CP_
			,	DiaPaid = @DiaPaid_
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
/****** Object:  StoredProcedure [dbo].[spBattleEnd]    Script Date: 2022-07-06 오후 6:59:17 ******/
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
			,	Dia = tB.Dia
			,	CP = tB.CP
			,	DiaPaid = tB.DiaPaid
			,	Dia00 = tB.Dia00
			,	Dia01 = tB.Dia01
			,	Dia02 = tB.Dia02
			,	Dia03 = tB.Dia03
			,	Point = tB.Point
			,	PointBest = tB.PointBest
			,	WinCountSolo = tB.WinCountSolo
			,	LoseCountSolo = tB.LoseCountSolo
			,	WinCountSurvival = tB.WinCountSurvival
			,	LoseCountSurvival = tB.LoseCountSurvival
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
/****** Object:  StoredProcedure [dbo].[spBuy]    Script Date: 2022-07-06 오후 6:59:17 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[spBuy]
	@UID_ BIGINT
,	@Ticket_ INT
,	@Gold_ INT
,	@Dia_ INT
,	@CP_ INT
,	@DiaPaid_ INT
,	@CharsAdded_ dbo.TCharCodes READONLY
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
			,	Dia = @Dia_
			,	CP = @CP_
			,	DiaPaid = @DiaPaid_
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
/****** Object:  StoredProcedure [dbo].[spBuyChar]    Script Date: 2022-07-06 오후 6:59:17 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[spBuyChar]
	@UID_ BIGINT
,	@Ticket_ INT
,	@Gold_ INT
,	@Dia_ INT
,	@CP_ INT
,	@DiaPaid_ INT
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
			,	Dia = @Dia_
			,	CP = @CP_
			,	DiaPaid = @DiaPaid_
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
/****** Object:  StoredProcedure [dbo].[spBuyPackage]    Script Date: 2022-07-06 오후 6:59:17 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[spBuyPackage]
	@UID_ BIGINT
,	@Ticket_ INT
,	@Gold_ INT
,	@Dia_ INT
,	@CP_ INT
,	@DiaPaid_ INT
,	@Dia00_ INT
,	@Dia01_ INT
,	@Dia02_ INT
,	@Dia03_ INT
,	@CharsAdded_ dbo.TCharCodes READONLY
,	@Code_ INT
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
			,	Dia = @Dia_
			,	CP = @CP_
			,	DiaPaid = @DiaPaid_
			,	Dia00 = @Dia00_
			,	Dia01 = @Dia01_
			,	Dia02 = @Dia02_
			,	Dia03 = @Dia03_
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
/****** Object:  StoredProcedure [dbo].[spChangeNickBegin]    Script Date: 2022-07-06 오후 6:59:17 ******/
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
/****** Object:  StoredProcedure [dbo].[spChangeNickEnd]    Script Date: 2022-07-06 오후 6:59:17 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[spChangeNickEnd]
	@UID_ BIGINT
,	@Ticket_ INT
,	@Gold_ INT
,	@Dia_ INT
,	@CP_ INT
,	@DiaPaid_ INT
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
		,	Dia = @Dia_
		,	CP = @CP_
		,	DiaPaid = @DiaPaid_
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
/****** Object:  StoredProcedure [dbo].[spChangeNickEndFail]    Script Date: 2022-07-06 오후 6:59:17 ******/
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
/****** Object:  StoredProcedure [dbo].[spCheckID]    Script Date: 2022-07-06 오후 6:59:17 ******/
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
/****** Object:  StoredProcedure [dbo].[spClear]    Script Date: 2022-07-06 오후 6:59:17 ******/
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
	TRUNCATE TABLE dbo.tReceipt
	TRUNCATE TABLE dbo.tUser


	RETURN 0
END

/****** Object:  StoredProcedure [dbo].[spRankingConfigLoad]    Script Date: 2021-01-08 오후 5:57:20 ******/
SET ANSI_NULLS ON
GO
/****** Object:  StoredProcedure [dbo].[spCouponUse]    Script Date: 2022-07-06 오후 6:59:17 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[spCouponUse]
	@UID_ BIGINT
,	@Ticket_ INT
,	@Gold_ INT
,	@Dia_ INT
,	@CP_ INT
,	@DiaPaid_ INT
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
			,	Dia = @Dia_
			,	CP = @CP_
			,	DiaPaid = @DiaPaid_
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
/****** Object:  StoredProcedure [dbo].[spDailyReward]    Script Date: 2022-07-06 오후 6:59:17 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[spDailyReward]
	@UID_ BIGINT
,	@Ticket_ INT
,	@Gold_ INT
,	@Dia_ INT
,	@CP_ INT
,	@DiaPaid_ INT
,	@Dia00_ INT
,	@Dia01_ INT
,	@Dia02_ INT
,	@Dia03_ INT
,	@ExpiredTime_ BIGINT
,	@CountLeft_ INT
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	UPDATE	dbo.tUser
	SET		Ticket = @Ticket_
		,	Gold = @Gold_
		,	Dia = @Dia_
		,	CP = @CP_
		,	DiaPaid = @DiaPaid_
		,	Dia00 = @Dia00_
		,	Dia01 = @Dia01_
		,	Dia02 = @Dia02_
		,	Dia03 = @Dia03_
		,	DailyRewardExpiredTime = @ExpiredTime_
		,	DailyRewardCountLeft = @CountLeft_
	WHERE	[UID] = @UID_

	RETURN 0
		
END
GO
/****** Object:  StoredProcedure [dbo].[spFlyAwayBattleEnd]    Script Date: 2022-07-06 오후 6:59:17 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[spFlyAwayBattleEnd]
	@UID_ BIGINT
,	@Ticket_ INT
,	@Gold_ INT
,	@Dia_ INT
,	@CP_ INT
,	@DiaPaid_ INT
,	@Dia00_ INT
,	@Dia01_ INT
,	@Dia02_ INT
,	@Dia03_ INT
,	@PointBest_ INT
,	@PassedCountBest_ INT
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
			,	Dia = @Dia_
			,	CP = @CP_
			,	DiaPaid = @DiaPaid_
			,	Dia00 = @Dia00_
			,	Dia01 = @Dia01_
			,	Dia02 = @Dia02_
			,	Dia03 = @Dia03_
			,	IslandPointBest = @PointBest_
			,	IslandPassedCountBest = @PassedCountBest_
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
/****** Object:  StoredProcedure [dbo].[spFlyAwayBattleStart]    Script Date: 2022-07-06 오후 6:59:17 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[spFlyAwayBattleStart]
	@UID_ BIGINT
,	@Ticket_ INT
,	@Gold_ INT
,	@Dia_ INT
,	@CP_ INT
,	@DiaPaid_ INT
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
			,	Dia = @Dia_
			,	CP = @CP_
			,	DiaPaid = @DiaPaid_
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
/****** Object:  StoredProcedure [dbo].[spGacha]    Script Date: 2022-07-06 오후 6:59:17 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[spGacha]
	@UID_ BIGINT
,	@Ticket_ INT
,	@Gold_ INT
,	@Dia_ INT
,	@CP_ INT
,	@DiaPaid_ INT
,	@Dia00_ INT
,	@Dia01_ INT
,	@Dia02_ INT
,	@Dia03_ INT
,	@CharsGot_ dbo.TCharCodes READONLY
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
			,	Dia = @Dia_
			,	CP = @CP_
			,	DiaPaid = @DiaPaid_
			,	Dia00 = @Dia00_
			,	Dia01 = @Dia01_
			,	Dia02 = @Dia02_
			,	Dia03 = @Dia03_
		WHERE	[UID] = @UID_

		INSERT INTO dbo.tChar ([UID], CharCode)
			SELECT @UID_, CharCode FROM @CharsGot_

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
/****** Object:  StoredProcedure [dbo].[spJoin]    Script Date: 2022-07-06 오후 6:59:17 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[spJoin]
	@UID_ BIGINT
,	@Ticket_ INT
,	@Gold_ INT
,	@Dia_ INT
,	@CP_ INT
,	@DiaPaid_ INT
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
,	@DailyRewardExpireTime_ BIGINT
,	@DailyRewardCountLeft_ INT
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
			[UID], Ticket, Gold, Dia, CP, DiaPaid, Dia00, Dia01, Dia02, Dia03, Debug, SelectedCharCode, SingleCount, SingleRefreshTime, IslandCount, IslandRefreshTime,
			QuestDailyCompleteRefreshTime, ChangeNickFreeCount, DailyRewardExpiredTime, DailyRewardCountLeft, InsertedTimePoint, [Language], OS, CountryCode)
		VALUES (
			@UID_, @Ticket_, @Gold_, @Dia_, @CP_, @DiaPaid_, @Dia00_, @Dia01_, @Dia02_, @Dia03_, @Debug_, @DefaultCharCode_, @SingleCount_, @SingleRefreshTime_, @IslandCount_, @IslandRefreshTime_,
			@QuestDailyCompleteRefreshTime_, @ChangeNickFreeCount_, @DailyRewardExpireTime_, @DailyRewardCountLeft_, @InsertedTimePoint_, @Language_, @OS_, @CountryCode_)

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
/****** Object:  StoredProcedure [dbo].[spLogin]    Script Date: 2022-07-06 오후 6:59:17 ******/
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

		SELECT	Ticket, Gold, Dia, CP, DiaPaid, Dia00, Dia01, Dia02, Dia03, Debug, SelectedCharCode,
				SingleCount, SingleRefreshTime, IslandCount, IslandRefreshTime, QuestDailyCompleteRefreshTime, ChangeNickFreeCount, DailyRewardExpiredTime, DailyRewardCountLeft,
				[Exp], CanPushAtNight, Point, PointBest, LastGotRewardRankIndex, WinCountSolo, LoseCountSolo, WinCountSurvival, LoseCountSurvival, WinCountMulti, LoseCountMulti,
				BattlePointBest, SinglePointBest, IslandPointBest, SingleBestTick, IslandPassedCountBest, KillTotal, ChainKillTotal, BlowBalloonTotal,
				QuestDailyCompleteCount, TutorialReward,
				RankingRewardedCounter, NewNick, [Language]
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

		SELECT	Code
		FROM	dbo.tPackage
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
/****** Object:  StoredProcedure [dbo].[spPurchase]    Script Date: 2022-07-06 오후 6:59:17 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[spPurchase]
	@OS_ TINYINT
,	@OrderID_ VARCHAR(50)
,	@UID_ BIGINT
,	@CountryCode_ CHAR(2)
,	@PurchaseTime_ BIGINT
,	@PurchaseType_ INT
,	@ProductID_ VARCHAR(50)
,	@DiaCount_ INT
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	DECLARE @Ret		INT = 0
	
	BEGIN TRY

		BEGIN TRAN

		INSERT INTO dbo.tReceipt (OS, OrderID, [UID], CountryCode, PurchaseTime, PurchaseType, ProductID, DiaCount)
		VALUES (@OS_, @OrderID_, @UID_, @CountryCode_, @PurchaseTime_, @PurchaseType_, @ProductID_, @DiaCount_)

		UPDATE	dbo.tUser
		SET		DiaPaid = DiaPaid + @DiaCount_
		WHERE	[UID] = @UID_

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
/****** Object:  StoredProcedure [dbo].[spQuestDailyCompleteReward]    Script Date: 2022-07-06 오후 6:59:17 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[spQuestDailyCompleteReward]
	@UID_ BIGINT
,	@Ticket_ INT
,	@Gold_ INT
,	@Dia_ INT
,	@CP_ INT
,	@DiaPaid_ INT
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
			,	Dia = @Dia_
			,	CP = @CP_
			,	DiaPaid = @DiaPaid_
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
/****** Object:  StoredProcedure [dbo].[spQuestDel]    Script Date: 2022-07-06 오후 6:59:17 ******/
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
/****** Object:  StoredProcedure [dbo].[spQuestDone]    Script Date: 2022-07-06 오후 6:59:17 ******/
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
/****** Object:  StoredProcedure [dbo].[spQuestNew]    Script Date: 2022-07-06 오후 6:59:17 ******/
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
/****** Object:  StoredProcedure [dbo].[spQuestNext]    Script Date: 2022-07-06 오후 6:59:17 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[spQuestNext]
	@UID_ BIGINT
,	@SlotIndex_ TINYINT
,	@NewCode_ INT
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

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
			,	CoolEndTime = 0
		WHERE	[UID] = @UID_
			AND	SlotIndex = @SlotIndex_
	END

	RETURN 0

END
GO
/****** Object:  StoredProcedure [dbo].[spQuestReward]    Script Date: 2022-07-06 오후 6:59:17 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[spQuestReward]
	@UID_ BIGINT
,	@Ticket_ INT
,	@Gold_ INT
,	@Dia_ INT
,	@CP_ INT
,	@DiaPaid_ INT
,	@Dia00_ INT
,	@Dia01_ INT
,	@Dia02_ INT
,	@Dia03_ INT
,	@CharsAdded_ dbo.TCharCodes READONLY
,	@SlotIndex_ TINYINT
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
			,	Dia = @Dia_
			,	CP = @CP_
			,	DiaPaid = @DiaPaid_
			,	Dia00 = @Dia00_
			,	Dia01 = @Dia01_
			,	Dia02 = @Dia02_
			,	Dia03 = @Dia03_
			,	QuestDailyCompleteCount = @DailyCompleteCount_
			,	QuestDailyCompleteRefreshTime = @DailyCompleteRefreshTime_
		WHERE	[UID] = @UID_

		INSERT INTO dbo.tChar ([UID], CharCode)
			SELECT @UID_, CharCode FROM @CharsAdded_

		IF @CoolEndTime_ = 0
		BEGIN
			DELETE	dbo.tQuest
			WHERE	[UID] = @UID_
				AND	SlotIndex = @SlotIndex_
		END
		ELSE
		BEGIN
			UPDATE	dbo.tQuest
			SET		CoolEndTime = @CoolEndTime_
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
/****** Object:  StoredProcedure [dbo].[spRankingReward]    Script Date: 2022-07-06 오후 6:59:17 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO


CREATE PROCEDURE [dbo].[spRankingReward]
	@UID_ BIGINT
,	@Ticket_ INT
,	@Gold_ INT
,	@Dia_ INT
,	@CP_ INT
,	@DiaPaid_ INT
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
			,	Dia = @Dia_
			,	CP = @CP_
			,	DiaPaid = @DiaPaid_
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
/****** Object:  StoredProcedure [dbo].[spRankReward]    Script Date: 2022-07-06 오후 6:59:17 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[spRankReward]
	@UID_ BIGINT
,	@Ticket_ INT
,	@Gold_ INT
,	@Dia_ INT
,	@CP_ INT
,	@DiaPaid_ INT
,	@Dia00_ INT
,	@Dia01_ INT
,	@Dia02_ INT
,	@Dia03_ INT
,	@CharsAdded_ dbo.TCharCodes READONLY
,	@LastGotRewardRankIndex_ INT
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
			,	Dia = @Dia_
			,	CP = @CP_
			,	DiaPaid = @DiaPaid_
			,	Dia00 = @Dia00_
			,	Dia01 = @Dia01_
			,	Dia02 = @Dia02_
			,	Dia03 = @Dia03_
			,	LastGotRewardRankIndex = @LastGotRewardRankIndex_
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
/****** Object:  StoredProcedure [dbo].[spSelectChar]    Script Date: 2022-07-06 오후 6:59:17 ******/
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
/****** Object:  StoredProcedure [dbo].[spSetChar]    Script Date: 2022-07-06 오후 6:59:17 ******/
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
/****** Object:  StoredProcedure [dbo].[spSetPoint]    Script Date: 2022-07-06 오후 6:59:17 ******/
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
/****** Object:  StoredProcedure [dbo].[spSetResources]    Script Date: 2022-07-06 오후 6:59:17 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[spSetResources]
	@UID_ BIGINT
,	@Ticket_ INT
,	@Gold_ INT
,	@Dia_ INT
,	@CP_ INT
,	@DiaPaid_ INT
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
		,	Dia = @Dia_
		,	CP = @CP_
		,	DiaPaid = @DiaPaid_
		,	Dia00 = @Dia00_
		,	Dia01 = @Dia01_
		,	Dia02 = @Dia02_
		,	Dia03 = @Dia03_
	WHERE	[UID] = @UID_

	RETURN 0

END
GO
/****** Object:  StoredProcedure [dbo].[spSetUserExp]    Script Date: 2022-07-06 오후 6:59:17 ******/
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
/****** Object:  StoredProcedure [dbo].[spTutorialReward]    Script Date: 2022-07-06 오후 6:59:17 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[spTutorialReward]
	@UID_ BIGINT
,	@Ticket_ INT
,	@Gold_ INT
,	@Dia_ INT
,	@CP_ INT
,	@DiaPaid_ INT
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
		,	Dia = @Dia_
		,	CP = @CP_
		,	DiaPaid = @DiaPaid_
		,	Dia00 = @Dia00_
		,	Dia01 = @Dia01_
		,	Dia02 = @Dia02_
		,	Dia03 = @Dia03_
		,	TutorialReward = 1
	WHERE	[UID] = @UID_

	RETURN 0

END
GO
/****** Object:  StoredProcedure [dbo].[spUnsetChar]    Script Date: 2022-07-06 오후 6:59:17 ******/
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
/****** Object:  StoredProcedure [dbo].[sys_sp_AddFriendBegin]    Script Date: 2022-07-06 오후 6:59:17 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

CREATE PROCEDURE [dbo].[sys_sp_AddFriendBegin]
	@UID_ BIGINT
,	@FriendUID_ BIGINT
,	@FriendNick_ NVARCHAR(32)
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
/****** Object:  StoredProcedure [dbo].[sys_sp_AddFriendEnd]    Script Date: 2022-07-06 오후 6:59:17 ******/
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
/****** Object:  StoredProcedure [dbo].[sys_sp_AddFriendFail]    Script Date: 2022-07-06 오후 6:59:17 ******/
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
/****** Object:  StoredProcedure [dbo].[sys_sp_AddFriendRequest]    Script Date: 2022-07-06 오후 6:59:17 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

CREATE PROCEDURE [dbo].[sys_sp_AddFriendRequest]
	@UID_ BIGINT
,	@FriendUID_ BIGINT
,	@FriendNick_ NVARCHAR(32)
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
/****** Object:  StoredProcedure [dbo].[sys_sp_AllowFriend]    Script Date: 2022-07-06 오후 6:59:17 ******/
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
/****** Object:  StoredProcedure [dbo].[sys_sp_BlockFriend]    Script Date: 2022-07-06 오후 6:59:17 ******/
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
/****** Object:  StoredProcedure [dbo].[sys_sp_ChangeNick]    Script Date: 2022-07-06 오후 6:59:17 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

CREATE PROCEDURE [dbo].[sys_sp_ChangeNick]
	@UID_ BIGINT
,	@Nick_ NVARCHAR(32)
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
/****** Object:  StoredProcedure [dbo].[sys_sp_ChangeState]    Script Date: 2022-07-06 오후 6:59:17 ******/
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
/****** Object:  StoredProcedure [dbo].[sys_sp_Check]    Script Date: 2022-07-06 오후 6:59:17 ******/
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
/****** Object:  StoredProcedure [dbo].[sys_sp_Clear]    Script Date: 2022-07-06 오후 6:59:17 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

CREATE PROCEDURE [dbo].[sys_sp_Clear]
	@UID_ BIGINT
,	@ID_ NVARCHAR(255)
,	@Nick_ NVARCHAR(32)
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
/****** Object:  StoredProcedure [dbo].[sys_sp_Create]    Script Date: 2022-07-06 오후 6:59:17 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

CREATE PROCEDURE [dbo].[sys_sp_Create]
	@UID_ BIGINT
,	@ID_ NVARCHAR(255)
,	@Nick_ NVARCHAR(32)
,	@State_ TINYINT
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	DECLARE @Ret INT = 0

	BEGIN TRY

		DECLARE @ID VARBINARY(32)
		DECLARE @Nick NVARCHAR(32)

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
/****** Object:  StoredProcedure [dbo].[sys_sp_DenyFriend]    Script Date: 2022-07-06 오후 6:59:17 ******/
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
/****** Object:  StoredProcedure [dbo].[sys_sp_Login]    Script Date: 2022-07-06 오후 6:59:17 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

CREATE PROCEDURE [dbo].[sys_sp_Login]
	@UID_ BIGINT
,	@ID_ NVARCHAR(255)
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
/****** Object:  StoredProcedure [dbo].[sys_sp_Punish]    Script Date: 2022-07-06 오후 6:59:17 ******/
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
/****** Object:  StoredProcedure [dbo].[sys_sp_UnBlockFriend]    Script Date: 2022-07-06 오후 6:59:17 ******/
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
