USE [Coupon]
GO
/****** Object:  Table [dbo].[tCoupon]    Script Date: 2022-04-20 오후 8:07:02 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[tCoupon](
	[Key] [nvarchar](256) NOT NULL,
	[UID] [bigint] NOT NULL,
 CONSTRAINT [PK_tCoupon_1] PRIMARY KEY CLUSTERED 
(
	[Key] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  StoredProcedure [dbo].[spCouponUse]    Script Date: 2022-04-20 오후 8:07:02 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[spCouponUse]
	@Key_ NVARCHAR(256)
,	@UID_ BIGINT
AS
BEGIN
	SET XACT_ABORT ON
	SET NOCOUNT ON

	DECLARE @Ret INT = 0
	
	BEGIN TRY

		DECLARE @UID BIGINT

		SELECT	@UID = [UID]
		FROM	dbo.tCoupon WITH (NOLOCK)
		WHERE	[Key] = @Key_

		IF @UID IS NULL
		BEGIN
			RETURN 60000 -- Invalid Code, Key
		END
		ELSE IF @UID = -1 -- 모든 유저가 사용가능한 쿠폰이면
		BEGIN
			RETURN 0
		END
		ELSE IF @UID > 0 -- 이미 사용한 쿠폰이면
		BEGIN
			IF @UID = @UID_
				RETURN 0
			ELSE
				RETURN 60001 -- (다른유저가) 이미 사용한 쿠폰
		END
		ELSE -- 이번이 처음 사용이면 (NoNock 이므로 재 쿼리)
		BEGIN
			UPDATE	dbo.tCoupon
			SET		[UID] = @UID_
			WHERE	[Key] = @Key_
				AND	[UID] = 0

			IF @@ROWCOUNT = 0
				RETURN 60002 -- 다른유저가 사용한 쿠폰
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
EXEC sys.sp_addextendedproperty @name=N'MS_Description', @value=N'-1 : 모든 유저에 지급가능,  0 : 한명의 유저에게 지급가능하나 미지급상태,  0+ : 이미 지급됨' , @level0type=N'SCHEMA',@level0name=N'dbo', @level1type=N'TABLE',@level1name=N'tCoupon', @level2type=N'COLUMN',@level2name=N'UID'
GO
