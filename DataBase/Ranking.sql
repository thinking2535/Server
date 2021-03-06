/****** Object:  StoredProcedure [dbo].[spRewardLoadSingle]    Script Date: 2022-06-17 오후 7:28:14 ******/
DROP PROCEDURE IF EXISTS [dbo].[spRewardLoadSingle]
GO
/****** Object:  StoredProcedure [dbo].[spRewardLoadIsland]    Script Date: 2022-06-17 오후 7:28:14 ******/
DROP PROCEDURE IF EXISTS [dbo].[spRewardLoadIsland]
GO
/****** Object:  StoredProcedure [dbo].[spRewardLoad]    Script Date: 2022-06-17 오후 7:28:14 ******/
DROP PROCEDURE IF EXISTS [dbo].[spRewardLoad]
GO
/****** Object:  StoredProcedure [dbo].[spRankingUpdateSingle]    Script Date: 2022-06-17 오후 7:28:14 ******/
DROP PROCEDURE IF EXISTS [dbo].[spRankingUpdateSingle]
GO
/****** Object:  StoredProcedure [dbo].[spRankingUpdateIsland]    Script Date: 2022-06-17 오후 7:28:14 ******/
DROP PROCEDURE IF EXISTS [dbo].[spRankingUpdateIsland]
GO
/****** Object:  StoredProcedure [dbo].[spRankingUpdate]    Script Date: 2022-06-17 오후 7:28:14 ******/
DROP PROCEDURE IF EXISTS [dbo].[spRankingUpdate]
GO
/****** Object:  StoredProcedure [dbo].[spRankingRefresh]    Script Date: 2022-06-17 오후 7:28:14 ******/
DROP PROCEDURE IF EXISTS [dbo].[spRankingRefresh]
GO
/****** Object:  StoredProcedure [dbo].[spRankingLoadSingle]    Script Date: 2022-06-17 오후 7:28:14 ******/
DROP PROCEDURE IF EXISTS [dbo].[spRankingLoadSingle]
GO
/****** Object:  StoredProcedure [dbo].[spRankingLoadIsland]    Script Date: 2022-06-17 오후 7:28:14 ******/
DROP PROCEDURE IF EXISTS [dbo].[spRankingLoadIsland]
GO
/****** Object:  StoredProcedure [dbo].[spRankingLoad]    Script Date: 2022-06-17 오후 7:28:14 ******/
DROP PROCEDURE IF EXISTS [dbo].[spRankingLoad]
GO
/****** Object:  StoredProcedure [dbo].[spRankingConfigLoad]    Script Date: 2022-06-17 오후 7:28:14 ******/
DROP PROCEDURE IF EXISTS [dbo].[spRankingConfigLoad]
GO
/****** Object:  StoredProcedure [dbo].[spClear]    Script Date: 2022-06-17 오후 7:28:14 ******/
DROP PROCEDURE IF EXISTS [dbo].[spClear]
GO
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[tRankingSingle]') AND type in (N'U'))
ALTER TABLE [dbo].[tRankingSingle] DROP CONSTRAINT IF EXISTS [DF__tRankingS__Inser__71D1E811]
GO
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[tRankingIsland]') AND type in (N'U'))
ALTER TABLE [dbo].[tRankingIsland] DROP CONSTRAINT IF EXISTS [DF__tRankingI__Inser__6E01572D]
GO
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[tRanking]') AND type in (N'U'))
ALTER TABLE [dbo].[tRanking] DROP CONSTRAINT IF EXISTS [DF__tRanking__Insert__6EF57B66]
GO
/****** Object:  Table [dbo].[tRewardSingle]    Script Date: 2022-06-17 오후 7:28:14 ******/
DROP TABLE IF EXISTS [dbo].[tRewardSingle]
GO
/****** Object:  Table [dbo].[tRewardIsland]    Script Date: 2022-06-17 오후 7:28:14 ******/
DROP TABLE IF EXISTS [dbo].[tRewardIsland]
GO
/****** Object:  Table [dbo].[tReward]    Script Date: 2022-06-17 오후 7:28:14 ******/
DROP TABLE IF EXISTS [dbo].[tReward]
GO
/****** Object:  Table [dbo].[tRankingSingle]    Script Date: 2022-06-17 오후 7:28:14 ******/
DROP TABLE IF EXISTS [dbo].[tRankingSingle]
GO
/****** Object:  Table [dbo].[tRankingIsland]    Script Date: 2022-06-17 오후 7:28:14 ******/
DROP TABLE IF EXISTS [dbo].[tRankingIsland]
GO
/****** Object:  Table [dbo].[tRankingConfig]    Script Date: 2022-06-17 오후 7:28:14 ******/
DROP TABLE IF EXISTS [dbo].[tRankingConfig]
GO
/****** Object:  Table [dbo].[tRanking]    Script Date: 2022-06-17 오후 7:28:14 ******/
DROP TABLE IF EXISTS [dbo].[tRanking]
GO
/****** Object:  UserDefinedTableType [dbo].[TUID]    Script Date: 2022-06-17 오후 7:28:14 ******/
DROP TYPE IF EXISTS [dbo].[TUID]
GO
/****** Object:  UserDefinedTableType [dbo].[TRankingUser]    Script Date: 2022-06-17 오후 7:28:14 ******/
DROP TYPE IF EXISTS [dbo].[TRankingUser]
GO
/****** Object:  UserDefinedTableType [dbo].[TRankingReward]    Script Date: 2022-06-17 오후 7:28:14 ******/
DROP TYPE IF EXISTS [dbo].[TRankingReward]
GO
/****** Object:  UserDefinedTableType [dbo].[TRankingReward]    Script Date: 2022-06-17 오후 7:28:14 ******/
CREATE TYPE [dbo].[TRankingReward] AS TABLE(
	[UID] [bigint] NULL,
	[Ranking] [int] NULL
)
GO
/****** Object:  UserDefinedTableType [dbo].[TRankingUser]    Script Date: 2022-06-17 오후 7:28:14 ******/
CREATE TYPE [dbo].[TRankingUser] AS TABLE(
	[UID] [bigint] NULL,
	[Nick] [nvarchar](32) NULL,
	[CharCode] [int] NULL,
	[CountryCode] [nvarchar](2) NULL,
	[Point] [int] NULL
)
GO
/****** Object:  UserDefinedTableType [dbo].[TUID]    Script Date: 2022-06-17 오후 7:28:14 ******/
CREATE TYPE [dbo].[TUID] AS TABLE(
	[UID] [bigint] NULL
)
GO
/****** Object:  Table [dbo].[tRanking]    Script Date: 2022-06-17 오후 7:28:14 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[tRanking](
	[UID] [bigint] NOT NULL,
	[Point] [int] NOT NULL,
	[Nick] [nvarchar](32) NOT NULL,
	[CharCode] [int] NOT NULL,
	[CountryCode] [nvarchar](2) NOT NULL,
	[InsertedTime] [datetime] NOT NULL,
 CONSTRAINT [PK_tRanking] PRIMARY KEY CLUSTERED 
(
	[UID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[tRankingConfig]    Script Date: 2022-06-17 오후 7:28:14 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[tRankingConfig](
	[Counter] [bigint] NOT NULL,
	[ExpireTimePoint] [bigint] NOT NULL
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[tRankingIsland]    Script Date: 2022-06-17 오후 7:28:14 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[tRankingIsland](
	[UID] [bigint] NOT NULL,
	[Point] [int] NOT NULL,
	[Nick] [nvarchar](32) NOT NULL,
	[CharCode] [int] NOT NULL,
	[CountryCode] [nvarchar](2) NOT NULL,
	[InsertedTime] [datetime] NOT NULL,
 CONSTRAINT [PK_tRankingIsland] PRIMARY KEY CLUSTERED 
(
	[UID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[tRankingSingle]    Script Date: 2022-06-17 오후 7:28:14 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[tRankingSingle](
	[UID] [bigint] NOT NULL,
	[Point] [int] NOT NULL,
	[Nick] [nvarchar](32) NOT NULL,
	[CharCode] [int] NOT NULL,
	[CountryCode] [nvarchar](2) NOT NULL,
	[InsertedTime] [datetime] NOT NULL,
 CONSTRAINT [PK_tRankingSingle] PRIMARY KEY CLUSTERED 
(
	[UID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[tReward]    Script Date: 2022-06-17 오후 7:28:14 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[tReward](
	[UID] [bigint] NOT NULL,
	[Ranking] [int] NOT NULL,
 CONSTRAINT [PK_tReward] PRIMARY KEY CLUSTERED 
(
	[UID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[tRewardIsland]    Script Date: 2022-06-17 오후 7:28:14 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[tRewardIsland](
	[UID] [bigint] NOT NULL,
	[Ranking] [int] NOT NULL,
 CONSTRAINT [PK_tRewardIsland] PRIMARY KEY CLUSTERED 
(
	[UID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[tRewardSingle]    Script Date: 2022-06-17 오후 7:28:14 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[tRewardSingle](
	[UID] [bigint] NOT NULL,
	[Ranking] [int] NOT NULL,
 CONSTRAINT [PK_tRewardSingle] PRIMARY KEY CLUSTERED 
(
	[UID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
ALTER TABLE [dbo].[tRanking] ADD  CONSTRAINT [DF__tRanking__Insert__6EF57B66]  DEFAULT (getdate()) FOR [InsertedTime]
GO
ALTER TABLE [dbo].[tRankingIsland] ADD  CONSTRAINT [DF__tRankingI__Inser__6E01572D]  DEFAULT (getdate()) FOR [InsertedTime]
GO
ALTER TABLE [dbo].[tRankingSingle] ADD  CONSTRAINT [DF__tRankingS__Inser__71D1E811]  DEFAULT (getdate()) FOR [InsertedTime]
GO
/****** Object:  StoredProcedure [dbo].[spClear]    Script Date: 2022-06-17 오후 7:28:14 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[spClear]
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	TRUNCATE TABLE dbo.tRankingConfig
	TRUNCATE TABLE dbo.tRanking
	TRUNCATE TABLE dbo.tRankingSingle
	TRUNCATE TABLE dbo.tRankingIsland
	TRUNCATE TABLE dbo.tReward
	TRUNCATE TABLE dbo.tRewardSingle
	TRUNCATE TABLE dbo.tRewardIsland

	RETURN 0
END

/****** Object:  StoredProcedure [dbo].[spRankingConfigLoad]    Script Date: 2021-01-08 오후 5:57:20 ******/
SET ANSI_NULLS ON
GO
/****** Object:  StoredProcedure [dbo].[spRankingConfigLoad]    Script Date: 2022-06-17 오후 7:28:14 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO


CREATE PROCEDURE [dbo].[spRankingConfigLoad]
	@ExpireTimePoint_ BIGINT
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	MERGE dbo.tRankingConfig AS tT
	USING (VALUES (0)) AS Src(x)
	ON [Counter] IS NOT NULL
	WHEN NOT MATCHED THEN
		INSERT ([Counter], ExpireTimePoint)
		VALUES (1, @ExpireTimePoint_);

	SELECT	[Counter], ExpireTimePoint
	FROM	dbo.tRankingConfig

	RETURN 0

END

GO
/****** Object:  StoredProcedure [dbo].[spRankingLoad]    Script Date: 2022-06-17 오후 7:28:14 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[spRankingLoad]
	@MaxList_ INT
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	SELECT	TOP (@MaxList_)	Nick, CharCode, CountryCode, [UID], Point
	FROM	dbo.tRanking
	ORDER BY Point DESC, InsertedTime

	RETURN 0

END
GO
/****** Object:  StoredProcedure [dbo].[spRankingLoadIsland]    Script Date: 2022-06-17 오후 7:28:14 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO


CREATE PROCEDURE [dbo].[spRankingLoadIsland]
	@MaxList_ INT
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	SELECT	TOP (@MaxList_)	[UID], Nick, CharCode, CountryCode, Point
	FROM	dbo.tRankingIsland
	ORDER BY Point DESC, InsertedTime

	RETURN 0

END
GO
/****** Object:  StoredProcedure [dbo].[spRankingLoadSingle]    Script Date: 2022-06-17 오후 7:28:14 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO


CREATE PROCEDURE [dbo].[spRankingLoadSingle]
	@MaxList_ INT
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	SELECT	TOP (@MaxList_)	[UID], Nick, CharCode, CountryCode, Point
	FROM	dbo.tRankingSIngle
	ORDER BY Point DESC, InsertedTime

	RETURN 0

END
GO
/****** Object:  StoredProcedure [dbo].[spRankingRefresh]    Script Date: 2022-06-17 오후 7:28:14 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO


CREATE PROCEDURE [dbo].[spRankingRefresh]
	@Counter_ BIGINT
,	@ExpireTimePoint_ BIGINT
,	@tRewards_ dbo.TRankingReward READONLY
,	@tRewardsSingle_ dbo.TRankingReward READONLY
,	@tRewardsIsland_ dbo.TRankingReward READONLY
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	UPDATE	dbo.tRankingConfig
	SET		[Counter] = @Counter_
		,	ExpireTimePoint = @ExpireTimePoint_

	TRUNCATE TABLE dbo.tRanking
	TRUNCATE TABLE dbo.tRankingSingle
	TRUNCATE TABLE dbo.tRankingIsland
	TRUNCATE TABLE dbo.tReward
	TRUNCATE TABLE dbo.tRewardSingle
	TRUNCATE TABLE dbo.tRewardIsland

	INSERT INTO dbo.tReward ([UID], [Ranking])
		SELECT	[UID], [Ranking]
		FROM	@tRewards_

	INSERT INTO dbo.tRewardSingle ([UID], [Ranking])
		SELECT	[UID], [Ranking]
		FROM	@tRewardsSingle_

	INSERT INTO dbo.tRewardIsland ([UID], [Ranking])
		SELECT	[UID], [Ranking]
		FROM	@tRewardsIsland_

	RETURN 0

END
GO
/****** Object:  StoredProcedure [dbo].[spRankingUpdate]    Script Date: 2022-06-17 오후 7:28:14 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[spRankingUpdate]
	@Merged_ dbo.TRankingUser READONLY
,	@Deleted_ dbo.TUID READONLY
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	DECLARE @Ret INT = 0
	
	BEGIN TRY

		BEGIN TRAN

		MERGE dbo.tRanking AS tT
		USING @Merged_ AS tS
		ON (tT.[UID] = tS.[UID])
		WHEN MATCHED THEN
			UPDATE
			SET	Point = tS.Point
			,	Nick = tS.Nick
			,	CharCode = tS.CharCode
			,	CountryCode = tS.CountryCode
		WHEN NOT MATCHED THEN
			INSERT ([UID], Point, Nick, CharCode, CountryCode)
			VALUES ([UID], Point, Nick, CharCode, CountryCode);

		DELETE	tR
		FROM	dbo.tRanking tR
			,	@Deleted_ tD
		WHERE	tR.[UID] = tD.[UID]

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
/****** Object:  StoredProcedure [dbo].[spRankingUpdateIsland]    Script Date: 2022-06-17 오후 7:28:14 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[spRankingUpdateIsland]
	@Merged_ dbo.TRankingUser READONLY
,	@Deleted_ dbo.TUID READONLY
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	DECLARE @Ret INT = 0
	
	BEGIN TRY

		BEGIN TRAN

		MERGE dbo.tRankingIsland AS tT
		USING @Merged_ AS tS
		ON (tT.[UID] = tS.[UID])
		WHEN MATCHED THEN
			UPDATE
			SET	Point = tS.Point
			,	Nick = tS.Nick
			,	CharCode = tS.CharCode
			,	CountryCode = tS.CountryCode
		WHEN NOT MATCHED THEN
			INSERT ([UID], Point, Nick, CharCode, CountryCode)
			VALUES ([UID], Point, Nick, CharCode, CountryCode);

		DELETE	tR
		FROM	dbo.tRankingIsland tR
			,	@Deleted_ tD
		WHERE	tR.[UID] = tD.[UID]

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
/****** Object:  StoredProcedure [dbo].[spRankingUpdateSingle]    Script Date: 2022-06-17 오후 7:28:14 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[spRankingUpdateSingle]
	@Merged_ dbo.TRankingUser READONLY
,	@Deleted_ dbo.TUID READONLY
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	DECLARE @Ret INT = 0
	
	BEGIN TRY

		BEGIN TRAN

		MERGE dbo.tRankingSingle AS tT
		USING @Merged_ AS tS
		ON (tT.[UID] = tS.[UID])
		WHEN MATCHED THEN
			UPDATE
			SET	Point = tS.Point
			,	Nick = tS.Nick
			,	CharCode = tS.CharCode
			,	CountryCode = tS.CountryCode
		WHEN NOT MATCHED THEN
			INSERT ([UID], Point, Nick, CharCode, CountryCode)
			VALUES ([UID], Point, Nick, CharCode, CountryCode);

		DELETE	tR
		FROM	dbo.tRankingSingle tR
			,	@Deleted_ tD
		WHERE	tR.[UID] = tD.[UID]

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
/****** Object:  StoredProcedure [dbo].[spRewardLoad]    Script Date: 2022-06-17 오후 7:28:14 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO


CREATE PROCEDURE [dbo].[spRewardLoad]
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	SELECT	[UID], Ranking
	FROM	dbo.tReward

	RETURN 0

END
GO
/****** Object:  StoredProcedure [dbo].[spRewardLoadIsland]    Script Date: 2022-06-17 오후 7:28:14 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO


CREATE PROCEDURE [dbo].[spRewardLoadIsland]
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	SELECT	[UID], Ranking
	FROM	dbo.tRewardIsland

	RETURN 0

END
GO
/****** Object:  StoredProcedure [dbo].[spRewardLoadSingle]    Script Date: 2022-06-17 오후 7:28:14 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO


CREATE PROCEDURE [dbo].[spRewardLoadSingle]
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	SELECT	[UID], Ranking
	FROM	dbo.tRewardSingle

	RETURN 0

END
GO
