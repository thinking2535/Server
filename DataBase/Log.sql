/****** Object:  UserDefinedFunction [dbo].[fDateTimeToTimePoint]    Script Date: 2022-05-23 오후 6:58:33 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE FUNCTION [dbo].[fDateTimeToTimePoint]
(
	@DateTime_ DATETIME
)
RETURNS BIGINT
AS
BEGIN
	RETURN DATEDIFF(S, '1970-01-01 9:00:00', @DateTime_) * CAST(10000000 AS BIGINT)
END
GO
/****** Object:  UserDefinedFunction [dbo].[fTimePointToDateTime]    Script Date: 2022-05-23 오후 6:58:33 ******/
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
/****** Object:  Table [dbo].[tConnect]    Script Date: 2022-05-23 오후 6:58:33 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[tConnect](
	[TimePointLogin] [bigint] NOT NULL,
	[TimePointLogout] [bigint] NOT NULL,
	[UID] [bigint] NOT NULL,
	[OS] [tinyint] NOT NULL,
	[CountryCode] [char](2) NOT NULL,
	[NewRegistered] [tinyint] NOT NULL,
 CONSTRAINT [PK_tConnect] PRIMARY KEY CLUSTERED 
(
	[TimePointLogin] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  StoredProcedure [dbo].[spAU]    Script Date: 2022-05-23 오후 6:58:33 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[spAU]
	@StartDateTime_ DATETIME
,	@EndDateTime_ DATETIME
,	@OS_ TINYINT
,	@CountryCode_ CHAR(2)
,	@NewRegistered_ TINYINT
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	SELECT SUM(Cnt) DAU
	FROM
	(
		SELECT	COUNT(UID) Cnt
		FROM	dbo.tConnect
		WHERE	(
					@StartDateTime_ IS NULL
				OR	TimePointLogout >= dbo.fDateTimeToTimePoint(@StartDateTime_)
				)
			AND	(
					@EndDateTime_ IS NULL
				OR	TimePointLogin < dbo.fDateTimeToTimePoint(@EndDateTime_)
				)
			AND	(
					@CountryCode_ IS NULL
				OR	CountryCode = @CountryCode_
				)
			AND	(
					@OS_ IS NULL
				OR	OS = @OS_
				)
			AND	(
					@NewRegistered_ IS NULL
				OR	NewRegistered = @NewRegistered_
				)
		GROUP BY [UID]
	) AS tDAU

	RETURN 0
END
GO
/****** Object:  StoredProcedure [dbo].[spRetention]    Script Date: 2022-05-23 오후 6:58:33 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[spRetention]
	@Date_ DATE
,	@Days_ INT
,	@OS_ TINYINT
,	@CountryCode_ CHAR(2)
,	@NewRegistered_ TINYINT
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	DECLARE	@DayTicks BIGINT = 864000000000
	DECLARE	@TimePoint BIGINT = dbo.fDateTimeToTimePoint(@Date_)
	DECLARE	@tUID TABLE ([UID] BIGINT)

	INSERT INTO @tUID ([UID])
		SELECT	[UID]
		FROM	dbo.tConnect WITH(NOLOCK)
		WHERE	TimePointLogin >= @TimePoint
			AND	TimePointLogin < (@TimePoint + @DayTicks)
			AND	(
					@CountryCode_ IS NULL
				OR	CountryCode = @CountryCode_
				)
			AND	(
					@OS_ IS NULL
				OR	OS = @OS_
				)
			AND	(
					@NewRegistered_ IS NULL
				OR	NewRegistered = @NewRegistered_
				)
		GROUP BY [UID]


	DECLARE	@tRetention TABLE ([Retention] INT)
	DECLARE	@Day INT = 0

	WHILE @Day < @Days_
	BEGIN
		SET	@TimePoint = @TimePoint + @DayTicks

		INSERT INTO @tRetention
			SELECT	COUNT(*)
			FROM	@tUID tU
			,	(
					SELECT	[UID]
					FROM	dbo.tConnect WITH(NOLOCK)
					WHERE	TimePointLogin >= @TimePoint
						AND	TimePointLogin < (@TimePoint + @DayTicks)
					GROUP BY [UID]
				) tC
			WHERE	tU.[UID] = tC.[UID]

		SET	@Day = @Day + 1
	END

	SELECT	COUNT(*) Users
	FROM	@tUID

	SELECT	*
	FROM	@tRetention

	RETURN 0
END
GO
/****** Object:  StoredProcedure [dbo].[spRetentionReturn]    Script Date: 2022-05-23 오후 6:58:33 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[spRetentionReturn]
	@RetentionDay_ INT
,	@EndDateTime DATETIME
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	DECLARE @BeginDateTime DATETIME = DATEADD(D, -@RetentionDay_, @EndDateTime)
	DECLARE @BaseDateTime DATETIME = DATEADD(D, - 1, @BeginDateTime)

	DECLARE @tBaseUIDs TABLE ([UID] BIGINT)
	INSERT INTO @tBaseUIDs
		SELECT	[UID]
		FROM	dbo.tConnect
		WHERE	TimePointLogin >= dbo.fDateTimeToTimePoint(@BaseDateTime)
			AND	TimePointLogin < dbo.fDateTimeToTimePoint(@BeginDateTime)
		GROUP BY [UID]

	DECLARE @BaseCount INT = @@ROWCOUNT

	IF @BaseCount = 0
	BEGIN
		RETURN 0
	END
	ELSE
	BEGIN
		DECLARE @CheckCount INT = 0

		SELECT @CheckCount = COUNT(*)
		FROM	@tBaseUIDs tB
			,	(
					SELECT	[UID]
					FROM	dbo.tConnect
					WHERE	TimePointLogin >= dbo.fDateTimeToTimePoint(@BeginDateTime)
						AND	TimePointLogin < dbo.fDateTimeToTimePoint(@EndDateTime)
					GROUP BY [UID]
				) tC
		WHERE tB.[UID] = tC.[UID]

		RETURN	@CheckCount * 100 / @BaseCount
	END

END
GO
/****** Object:  StoredProcedure [dbo].[spRetentionRolling]    Script Date: 2022-05-23 오후 6:58:33 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[spRetentionRolling]
	@RetentionDay_ INT
,	@EndDateTime DATETIME
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	DECLARE @BeginDateTime DATETIME = DATEADD(D, -@RetentionDay_, @EndDateTime)
	DECLARE @BaseDateTime DATETIME = DATEADD(D, - 1, @BeginDateTime)

	DECLARE @tBaseUIDs TABLE ([UID] BIGINT)
	INSERT INTO @tBaseUIDs
		SELECT	[UID]
		FROM	dbo.tConnect
		WHERE	TimePointLogin >= dbo.fDateTimeToTimePoint(@BaseDateTime)
			AND	TimePointLogin < dbo.fDateTimeToTimePoint(@BeginDateTime)
		GROUP BY [UID]

	DECLARE @BaseCount INT = @@ROWCOUNT

	IF @BaseCount = 0
	BEGIN
		SELECT 0
	END
	ELSE
	BEGIN
		DECLARE @CheckCount INT = 0

		SELECT @CheckCount = COUNT(*)
		FROM	@tBaseUIDs tB
			,	(
					SELECT	[UID]
					FROM	dbo.tConnect
					WHERE	TimePointLogin >= dbo.fDateTimeToTimePoint(@BeginDateTime)
						AND	TimePointLogin < dbo.fDateTimeToTimePoint(@EndDateTime)
					GROUP BY [UID]
				) tC
		WHERE tB.[UID] = tC.[UID]

		SELECT	@CheckCount * 100 / @BaseCount
	END

	RETURN 0
END
GO
