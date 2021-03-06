/****** Object:  StoredProcedure [dbo].[sys_sp_Login]    Script Date: 2022-06-16 오후 6:15:55 ******/
DROP PROCEDURE IF EXISTS [dbo].[sys_sp_Login]
GO
/****** Object:  StoredProcedure [dbo].[sys_sp_Create]    Script Date: 2022-06-16 오후 6:15:55 ******/
DROP PROCEDURE IF EXISTS [dbo].[sys_sp_Create]
GO
/****** Object:  StoredProcedure [dbo].[sys_sp_ChangeNick]    Script Date: 2022-06-16 오후 6:15:55 ******/
DROP PROCEDURE IF EXISTS [dbo].[sys_sp_ChangeNick]
GO
/****** Object:  StoredProcedure [dbo].[sys_sp_AddFriendGetUID]    Script Date: 2022-06-16 오후 6:15:55 ******/
DROP PROCEDURE IF EXISTS [dbo].[sys_sp_AddFriendGetUID]
GO
/****** Object:  StoredProcedure [dbo].[spClear]    Script Date: 2022-06-16 오후 6:15:55 ******/
DROP PROCEDURE IF EXISTS [dbo].[spClear]
GO
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[sys_tbl_User]') AND type in (N'U'))
ALTER TABLE [dbo].[sys_tbl_User] DROP CONSTRAINT IF EXISTS [DF_sys_tbl_User_InsertedTime]
GO
/****** Object:  Index [IX_sys_tbl_User]    Script Date: 2022-06-16 오후 6:15:55 ******/
DROP INDEX IF EXISTS [IX_sys_tbl_User] ON [dbo].[sys_tbl_User]
GO
/****** Object:  Index [IX_Nick_sys_tbl_User]    Script Date: 2022-06-16 오후 6:15:55 ******/
DROP INDEX IF EXISTS [IX_Nick_sys_tbl_User] ON [dbo].[sys_tbl_User]
GO
/****** Object:  Table [dbo].[sys_tbl_User]    Script Date: 2022-06-16 오후 6:15:55 ******/
DROP TABLE IF EXISTS [dbo].[sys_tbl_User]
GO
/****** Object:  Table [dbo].[sys_tbl_User]    Script Date: 2022-06-16 오후 6:15:55 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[sys_tbl_User](
	[UID] [bigint] IDENTITY(1,1) NOT NULL,
	[ID] [varbinary](32) NOT NULL,
	[Nick] [nvarchar](32) NOT NULL,
	[InsertedTime] [datetime] NOT NULL,
 CONSTRAINT [PK_sys_tbl_User] PRIMARY KEY CLUSTERED 
(
	[UID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
SET ANSI_PADDING ON
GO
/****** Object:  Index [IX_Nick_sys_tbl_User]    Script Date: 2022-06-16 오후 6:15:55 ******/
CREATE UNIQUE NONCLUSTERED INDEX [IX_Nick_sys_tbl_User] ON [dbo].[sys_tbl_User]
(
	[Nick] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, IGNORE_DUP_KEY = OFF, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
GO
/****** Object:  Index [IX_sys_tbl_User]    Script Date: 2022-06-16 오후 6:15:55 ******/
CREATE UNIQUE NONCLUSTERED INDEX [IX_sys_tbl_User] ON [dbo].[sys_tbl_User]
(
	[UID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, IGNORE_DUP_KEY = OFF, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
GO
ALTER TABLE [dbo].[sys_tbl_User] ADD  CONSTRAINT [DF_sys_tbl_User_InsertedTime]  DEFAULT (getdate()) FOR [InsertedTime]
GO
/****** Object:  StoredProcedure [dbo].[spClear]    Script Date: 2022-06-16 오후 6:15:55 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[spClear]
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	TRUNCATE TABLE dbo.sys_tbl_User

	RETURN 0
END

/****** Object:  StoredProcedure [dbo].[spRankingConfigLoad]    Script Date: 2021-01-08 오후 5:57:20 ******/
SET ANSI_NULLS ON
GO
/****** Object:  StoredProcedure [dbo].[sys_sp_AddFriendGetUID]    Script Date: 2022-06-16 오후 6:15:55 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

CREATE PROCEDURE [dbo].[sys_sp_AddFriendGetUID]
	@Nick_ NVARCHAR(32)
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	SELECT	[UID]
	FROM	dbo.sys_tbl_User
	WHERE	Nick = @Nick_

	RETURN 0
END
GO
/****** Object:  StoredProcedure [dbo].[sys_sp_ChangeNick]    Script Date: 2022-06-16 오후 6:15:55 ******/
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

	BEGIN TRY

		UPDATE	dbo.sys_tbl_User
		SET		Nick = @Nick_
		WHERE	[UID] = @UID_

		RETURN 0

	END TRY
	BEGIN CATCH

		RETURN ERROR_NUMBER()

	END CATCH

END
GO
/****** Object:  StoredProcedure [dbo].[sys_sp_Create]    Script Date: 2022-06-16 오후 6:15:55 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

CREATE PROCEDURE [dbo].[sys_sp_Create]
	@ID_ NVARCHAR(255)
,	@Nick_ NVARCHAR(32)
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	BEGIN TRY

		DECLARE @UID BIGINT
		DECLARE @Nick NVARCHAR(32) = @Nick_

		-- MERGE는 행 추가 실패해도 Index가 증가하므로 아래와 같이 구현
		SELECT	@UID = [UID], @Nick = Nick
		FROM	dbo.sys_tbl_User
		WHERE	ID = HASHBYTES('SHA2_256', @ID_)

		IF @UID IS NOT NULL
		BEGIN
			SELECT	@UID, @Nick
		END
		ELSE
		BEGIN
			INSERT INTO dbo.sys_tbl_User(ID, Nick)
			VALUES (HASHBYTES('SHA2_256', @ID_), @Nick)

			SELECT	@@IDENTITY, @Nick
		END

		RETURN 0

	END TRY
	BEGIN CATCH

		RETURN ERROR_NUMBER()

	END CATCH

END
GO
/****** Object:  StoredProcedure [dbo].[sys_sp_Login]    Script Date: 2022-06-16 오후 6:15:55 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

CREATE PROCEDURE [dbo].[sys_sp_Login]
	@ID_ NVARCHAR(255)
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	SELECT	[UID], Nick
	FROM	dbo.sys_tbl_User
	WHERE	ID = HASHBYTES('SHA2_256', @ID_)

	RETURN 0
END
GO
