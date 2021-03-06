/****** Object:  Table [dbo].[sys_tbl_User]    Script Date: 2020-03-06 오후 2:40:39 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
IF NOT EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[sys_tbl_User]') AND type in (N'U'))
BEGIN
CREATE TABLE [dbo].[sys_tbl_User](
	[UID] [bigint] NOT NULL,
	[Token] [varchar](200) NOT NULL,
	[CanPushAtNight] [tinyint] NOT NULL,
	[MinuteOffset] [int] NOT NULL,
	[InsertedTime] [datetime] NOT NULL,
 CONSTRAINT [PK_sys_tbl_User] PRIMARY KEY CLUSTERED 
(
	[UID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
END
GO
SET ANSI_PADDING ON
GO
/****** Object:  Index [IX_sys_tbl_User]    Script Date: 2020-03-06 오후 2:40:39 ******/
IF NOT EXISTS (SELECT * FROM sys.indexes WHERE object_id = OBJECT_ID(N'[dbo].[sys_tbl_User]') AND name = N'IX_sys_tbl_User')
CREATE UNIQUE NONCLUSTERED INDEX [IX_sys_tbl_User] ON [dbo].[sys_tbl_User]
(
	[Token] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, IGNORE_DUP_KEY = OFF, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
GO
IF NOT EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[DF_sys_tbl_User_CanPushAtNight]') AND type = 'D')
BEGIN
ALTER TABLE [dbo].[sys_tbl_User] ADD  CONSTRAINT [DF_sys_tbl_User_CanPushAtNight]  DEFAULT ((0)) FOR [CanPushAtNight]
END
GO
IF NOT EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[DF_sys_tbl_User_MinuteOffset]') AND type = 'D')
BEGIN
ALTER TABLE [dbo].[sys_tbl_User] ADD  CONSTRAINT [DF_sys_tbl_User_MinuteOffset]  DEFAULT ((0)) FOR [MinuteOffset]
END
GO
IF NOT EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[DF_sys_tbl_User_InsertedTime]') AND type = 'D')
BEGIN
ALTER TABLE [dbo].[sys_tbl_User] ADD  CONSTRAINT [DF_sys_tbl_User_InsertedTime]  DEFAULT (getdate()) FOR [InsertedTime]
END
GO
/****** Object:  StoredProcedure [dbo].[spClear]    Script Date: 2020-03-06 오후 2:40:39 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
IF NOT EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[spClear]') AND type in (N'P', N'PC'))
BEGIN
EXEC dbo.sp_executesql @statement = N'CREATE PROCEDURE [dbo].[spClear] AS' 
END
GO
ALTER PROCEDURE [dbo].[spClear]
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	DROP TABLE IF EXISTS dbo.sys_tbl_User

	DROP PROCEDURE IF EXISTS dbo.sys_sp_LoadAllUser
	DROP PROCEDURE IF EXISTS dbo.sys_sp_SetUser
	DROP PROCEDURE IF EXISTS dbo.sys_sp_UnsetUser

END
GO
/****** Object:  StoredProcedure [dbo].[sys_sp_DelUser]    Script Date: 2020-03-06 오후 2:40:39 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
IF NOT EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[sys_sp_DelUser]') AND type in (N'P', N'PC'))
BEGIN
EXEC dbo.sp_executesql @statement = N'CREATE PROCEDURE [dbo].[sys_sp_DelUser] AS' 
END
GO

ALTER PROCEDURE [dbo].[sys_sp_DelUser]
	@UID_		BIGINT
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	DELETE
	FROM dbo.sys_tbl_User
	WHERE	[UID] = @UID_

	RETURN 0
END
GO
/****** Object:  StoredProcedure [dbo].[sys_sp_LoadAllUser]    Script Date: 2020-03-06 오후 2:40:39 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
IF NOT EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[sys_sp_LoadAllUser]') AND type in (N'P', N'PC'))
BEGIN
EXEC dbo.sp_executesql @statement = N'CREATE PROCEDURE [dbo].[sys_sp_LoadAllUser] AS' 
END
GO

ALTER PROCEDURE [dbo].[sys_sp_LoadAllUser]
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON
	
	SELECT	[UID], Token
	FROM	dbo.sys_tbl_User

	RETURN 0

END
GO
/****** Object:  StoredProcedure [dbo].[sys_sp_SetUser]    Script Date: 2020-03-06 오후 2:40:39 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
IF NOT EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[sys_sp_SetUser]') AND type in (N'P', N'PC'))
BEGIN
EXEC dbo.sp_executesql @statement = N'CREATE PROCEDURE [dbo].[sys_sp_SetUser] AS' 
END
GO

ALTER PROCEDURE [dbo].[sys_sp_SetUser]
	@UID_		BIGINT
,	@Token_		VARCHAR(MAX)
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	DECLARE @Ret INT = 0
	
	BEGIN TRY

		BEGIN TRAN

		MERGE dbo.sys_tbl_User WITH(HOLDLOCK) AS tT
		USING (SELECT @UID_ [UID]) AS tS
		ON (tT.[UID] = tS.[UID] OR tT.Token = @Token_)
		WHEN MATCHED THEN
			UPDATE
			SET	[UID] = tS.[UID]
			,	Token = @Token_
		WHEN NOT MATCHED THEN
			INSERT ([UID], Token)
			VALUES (@UID_, @Token_);

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
/****** Object:  StoredProcedure [dbo].[sys_sp_UnsetUser]    Script Date: 2020-03-06 오후 2:40:39 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
IF NOT EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[sys_sp_UnsetUser]') AND type in (N'P', N'PC'))
BEGIN
EXEC dbo.sp_executesql @statement = N'CREATE PROCEDURE [dbo].[sys_sp_UnsetUser] AS' 
END
GO

ALTER PROCEDURE [dbo].[sys_sp_UnsetUser]
	@UID_		BIGINT
AS
BEGIN
	SET NOCOUNT ON;

	DECLARE @Ret INT = 0
	
	BEGIN TRY

		BEGIN TRAN

		DELETE
		FROM dbo.sys_tbl_User
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
/****** Object:  StoredProcedure [dbo].[sys_sp_UserChange]    Script Date: 2020-03-06 오후 2:40:39 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
IF NOT EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[sys_sp_UserChange]') AND type in (N'P', N'PC'))
BEGIN
EXEC dbo.sp_executesql @statement = N'CREATE PROCEDURE [dbo].[sys_sp_UserChange] AS' 
END
GO

ALTER PROCEDURE [dbo].[sys_sp_UserChange]
	@UID_ BIGINT
,	@CanPushAtNight_ TINYINT
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	UPDATE	dbo.sys_tbl_User
	SET		CanPushAtNight = @CanPushAtNight_
	WHERE	[UID] = @UID_
END
GO
/****** Object:  StoredProcedure [dbo].[sys_sp_UserChangeToken]    Script Date: 2020-03-06 오후 2:40:39 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
IF NOT EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[sys_sp_UserChangeToken]') AND type in (N'P', N'PC'))
BEGIN
EXEC dbo.sp_executesql @statement = N'CREATE PROCEDURE [dbo].[sys_sp_UserChangeToken] AS' 
END
GO

ALTER PROCEDURE [dbo].[sys_sp_UserChangeToken]
	@UID_ BIGINT
,	@Token_ VARCHAR(200)
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	UPDATE	dbo.sys_tbl_User
	SET		Token = @Token_
	WHERE	[UID] = @UID_
END
GO
/****** Object:  StoredProcedure [dbo].[sys_sp_UserChangeUID]    Script Date: 2020-03-06 오후 2:40:39 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
IF NOT EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[sys_sp_UserChangeUID]') AND type in (N'P', N'PC'))
BEGIN
EXEC dbo.sp_executesql @statement = N'CREATE PROCEDURE [dbo].[sys_sp_UserChangeUID] AS' 
END
GO

ALTER PROCEDURE [dbo].[sys_sp_UserChangeUID]
	@UID_ BIGINT
,	@Token_ VARCHAR(200)
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	UPDATE	dbo.sys_tbl_User
	SET		[UID] = @UID_
	WHERE	Token = @Token_
END
GO
/****** Object:  StoredProcedure [dbo].[sys_sp_UserDel]    Script Date: 2020-03-06 오후 2:40:39 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
IF NOT EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[sys_sp_UserDel]') AND type in (N'P', N'PC'))
BEGIN
EXEC dbo.sp_executesql @statement = N'CREATE PROCEDURE [dbo].[sys_sp_UserDel] AS' 
END
GO

ALTER PROCEDURE [dbo].[sys_sp_UserDel]
	@UID_ BIGINT
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	DELETE
	FROM	dbo.sys_tbl_User
	WHERE	[UID] = @UID_

	RETURN 0
END
GO
/****** Object:  StoredProcedure [dbo].[sys_sp_UserDelUIDChangeToken]    Script Date: 2020-03-06 오후 2:40:39 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
IF NOT EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[sys_sp_UserDelUIDChangeToken]') AND type in (N'P', N'PC'))
BEGIN
EXEC dbo.sp_executesql @statement = N'CREATE PROCEDURE [dbo].[sys_sp_UserDelUIDChangeToken] AS' 
END
GO

ALTER PROCEDURE [dbo].[sys_sp_UserDelUIDChangeToken]
	@DelUID_ BIGINT
,	@UID_ BIGINT
,	@Token_ VARCHAR(200)
,	@MinuteOffset_ INT
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	DELETE
	FROM	dbo.sys_tbl_User
	WHERE	[UID] = @DelUID_

	UPDATE	dbo.sys_tbl_User
	SET		Token = @Token_
		,	MinuteOffset = @MinuteOffset_
	WHERE	[UID] = @UID_
END
GO
/****** Object:  StoredProcedure [dbo].[sys_sp_UserInsert]    Script Date: 2020-03-06 오후 2:40:39 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
IF NOT EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[sys_sp_UserInsert]') AND type in (N'P', N'PC'))
BEGIN
EXEC dbo.sp_executesql @statement = N'CREATE PROCEDURE [dbo].[sys_sp_UserInsert] AS' 
END
GO

ALTER PROCEDURE [dbo].[sys_sp_UserInsert]
	@UID_ BIGINT
,	@Token_ VARCHAR(200)
,	@CanPushAtNight_ TINYINT
,	@MinuteOffset_ INT
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	INSERT INTO dbo.sys_tbl_User ([UID], Token, CanPushAtNight, MinuteOffset)
	VALUES (@UID_, @Token_, @CanPushAtNight_, @MinuteOffset_)
END
GO
/****** Object:  StoredProcedure [dbo].[sys_sp_UserLoadAll]    Script Date: 2020-03-06 오후 2:40:39 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
IF NOT EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[sys_sp_UserLoadAll]') AND type in (N'P', N'PC'))
BEGIN
EXEC dbo.sp_executesql @statement = N'CREATE PROCEDURE [dbo].[sys_sp_UserLoadAll] AS' 
END
GO

ALTER PROCEDURE [dbo].[sys_sp_UserLoadAll]
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON
	
	SELECT	[UID], Token, CanPushAtNight, MinuteOffset
	FROM	dbo.sys_tbl_User

	RETURN 0

END
GO
