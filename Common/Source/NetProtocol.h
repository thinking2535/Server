#pragma once

#include <string>
#include <array>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <Rso/Core/Stream.h>
#include <Rso/Json/Json.h>

#include <Rso/Game/Protocol.h>
#include <Rso/Physics/Protocol.h>
#include <Rso/GameUtil/Protocol.h>
namespace bb
{
	using namespace rso;
	using namespace net;
	using namespace game;
	using namespace physics;
	using namespace gameutil;
	using TIndex = int64;
	using TLevel = int32;
	using THP = int32;
	using TSlotNo = int8;
	using TExp = int32;
	using TRank = int32;
	using TTeamCnt = int8;
	using TQuestSlotIndex = uint8;
	using TForbiddenWords = vector<wstring>;
	using TokenID = wstring;
	const TVer c_Ver_Main = 49;
	const int32 c_FPS = 60;
	const int64 c_NetworkTickSync = 500000;
	const int64 c_NetworkTickBuffer = c_NetworkTickSync+500000;
	const float c_ContactOffset = 0.0001f;
	const float c_IgnoredGroundMaxDeltaVelocity = 0.01f;
	const float c_GroundAccRatio = 4.0f;
	const float c_AirAccRatio = 2.0f;
	const float c_ScreenWidth = 3.55555f;
	const float c_ScreenHeight = 2.0f;
	const float c_ScreenWidth_2 = c_ScreenWidth*0.5f;
	const float c_ScreenHeight_2 = c_ScreenHeight*0.5f;
	const int64 c_StaminaRegenDelayTick = 10000000;
	const float c_StaminaRegenSpeedInAir = 10.0f;
	const float c_StaminaRegenSpeedOnGround = 10.0f;
	const float c_FlapDeltaVelUp = 0.19f;
	const float c_FlapDeltaVelX = 0.19f;
	const float c_MaxVelDown = 0.56f;
	const float c_MaxVelDeadY = 1.13784f;
	const float c_Gravity = -0.6465f;
	const float c_MaxVelParachuteX = 0.682704f;
	const float c_MaxVelParachuteY = 0.28446f;
	const float c_GravityParachuteRatio = 0.5f;
	const float c_GravityDeadRatio = 2.0f;
	const float c_DieUpVel = 0.7f;
	const float c_PlayerWidth = 0.1258713f;
	const float c_PlayerWidth_2 = c_PlayerWidth*0.5f;
	const float c_PlayerHeight = 0.150337f;
	const float c_PlayerOffsetY = c_PlayerHeight*0.5f;
	const float c_BalloonWidth = 0.2f;
	const float c_BalloonHeight = 0.27f;
	const float c_BalloonOffsetY = 0.5f;
	const float c_BalloonLocalScale = 0.5f;
	const float c_ParachuteWidth = 0.45f;
	const float c_ParachuteHeight = 0.25f;
	const float c_ParachuteOffsetY = 0.37f;
	const float c_ParachuteLocalScale = 0.5f;
	const float c_BalloonExplosionVelocity = 0.5f;
	const int32 c_MaxPlayer = 6;
	const int8 c_BalloonCountForRegen = 2;
	const int8 c_BalloonCountForPump = 1;
	const int8 c_PumpCountForBalloon = 6;
	const int64 c_BattleStartDelayMilliSec = 2000;
	const int64 c_ChainKillDelayTickCount = 50000000;
	const int64 c_RegenDelayTickCount = 20000000;
	const int32 c_QuestCnt_Max = 5;
	const int32 minNicknameLength = 2;
	const int32 maxNicknameLength = 18;
	const float arrowDodgePositionPrecision = 1000.0f;
	const float arrowDodgeItemScreenWidth = c_ScreenWidth*0.9f;
	const float arrowDodgeItemScreenHeight = c_ScreenHeight*0.7f;
	const float arrowDodgeHalfItemScreenWidth = arrowDodgeItemScreenWidth*0.5f;
	const float arrowDodgeHalfItemScreenHeight = arrowDodgeItemScreenHeight*0.5f;
	const float arrowDodgeMinDownVelocity = 0.7f;
	const float arrowDodgeMinHorizontalVelocity = 0.3f;
	const float arrowDodgeArrowCreateScreenGap = 0.1f;
	const float arrowDodgeArrowCreateAreaHalfWidth = c_ScreenWidth*(0.5f+arrowDodgeArrowCreateScreenGap);
	const float arrowDodgeArrowCreateAreaHalfHeight = c_ScreenHeight*(0.5f+arrowDodgeArrowCreateScreenGap);
	const float arrowDodgeArrowActiveScreenGap = 0.2f;
	const float arrowDodgeArrowActiveAreaHalfWidth = c_ScreenWidth*(0.5f+arrowDodgeArrowActiveScreenGap);
	const float arrowDodgeArrowActiveTop = c_ScreenHeight*(1.0f+arrowDodgeArrowActiveScreenGap);
	const float arrowDodgeArrowActiveBottom = -(c_ScreenHeight*arrowDodgeArrowActiveScreenGap);
	const float arrowDodgeArrowActiveAreaHalfHeight = c_ScreenHeight*(0.5f+arrowDodgeArrowActiveScreenGap);
	const int64 arrowDodgeFirstLeftArrowTick = 300000000;
	const int64 arrowDodgeFirstRightArrowTick = 600000000;
	const int64 arrowDodgeMaxArrowTick = 900000000;
	const int64 arrowDodgeArrowBaseVelocityTick = 600000000;
	const float arrowDodgeArrowBaseVelocity = 0.1f;
	const float flyAwayMaxY = 1.7f;
	const float flyAwayMinY = 0.4f;
	const int32 flyAwayMainLevelCount = 5;
	const int32 flyAwaySubLevelCount = 3;
	const float flyAwayItemSlopeFactor = 0.7f;
	const float flyAwayItemCoinXDistanceMultiplier = 3.0f;
	const float flyAwayLandTopY = c_ScreenHeight_2*0.6f;
	const float flyAwayLandBottomY = -c_ScreenHeight_2*0.9f;
	const float flyAwayLandHeightRange = flyAwayLandTopY-flyAwayLandBottomY;
	const int32 flyAwayLandDistanceBase = 30;
	const float flyAwayMinLandDistance = 0.8f;
	enum class EProtoNetCs
	{
		Chat,
		FCMTokenSet,
		FCMTokenUnset,
		FCMCanPushAtNight,
		ChangeLanguage,
		Buy,
		BuyChar,
		BuyResource,
		SelectChar,
		BattleTouch,
		BattlePush,
		MultiBattleJoin,
		MultiBattleOut,
		MultiBattleIcon,
		ArrowDodgeBattleJoin,
		ArrowDodgeBattleEnd,
		FlyAwayBattleJoin,
		FlyAwayBattleEnd,
		RankReward,
		QuestReward,
		QuestDailyCompleteReward,
		ChangeNick,
		CouponUse,
		TutorialReward,
		RankingRewardInfo,
		RankingReward,
		Max,
		Null,
	};
	enum class EProtoNetSc
	{
		Ret,
		Msg,
		Login,
		Lobby,
		Chat,
		UserExp,
		Resources,
		SetPoint,
		SetChar,
		UnsetChar,
		Buy,
		BuyChar,
		BuyNFTChar,
		BuyResource,
		BattleSync,
		BattleDirect,
		BattleFlap,
		BattlePump,
		MultiBattleJoin,
		MultiBattleOut,
		MultiBattleBegin,
		MultiBattleStart,
		MultiBattleEnd,
		MultiBattleEndDraw,
		MultiBattleEndInvalid,
		MultiBattleIcon,
		MultiBattleLink,
		MultiBattleUnLink,
		InvalidDisconnectInfo,
		ArrowDodgeBattleJoin,
		ArrowDodgeBattleBegin,
		ArrowDodgeBattleStart,
		ArrowDodgeBattleEnd,
		FlyAwayBattleJoin,
		FlyAwayBattleBegin,
		FlyAwayBattleStart,
		FlyAwayBattleEnd,
		RankReward,
		QuestGot,
		QuestSet,
		QuestDone,
		QuestReward,
		QuestDailyCompleteReward,
		ChangeNick,
		ChangeNickFail,
		CouponUse,
		CouponUseFail,
		RankingRewardInfo,
		RankingReward,
		RankingRewardFail,
		Max,
	};
	enum class ERet
	{
		Ok,
		InvalidTime,
		UserDoesNotExist,
		SameCanNotPushAtNight,
		SameCode,
		InvalidProtocol,
		InvalidLanguage,
		InvalidShopID,
		InvalidGoodsID,
		InvalidCharCode,
		ReceiptCheckFail,
		SPError,
		NotBattleJoining,
		AlreadyBattleJoining,
		AlreadyInBattle,
		AlreadyHave,
		InvalidBattleType,
		MatchInsertFail,
		BattleBeginFail,
		NotEnoughMoney,
		NoMoreNewCharacter,
		NickLengthUnderMin,
		NickLengthOverMax,
		CouponAlreadyUsed,
		CouponInvalid,
		RankingServerOffLine,
		RankingNoReward,
		RankingRewarded,
		RankingRewardFail,
		Max,
		Null,
	};
	enum class ELanguage : uint8
	{
		English,
		Korean,
		France,
		Germany,
		Spain,
		Italia,
		ChinaCH,
		ChinaTW,
		Japan,
		Portugal,
		Russia,
		Nederland,
		Turkey,
		Finland,
		Malaysia,
		Thailand,
		Indonesia,
		Vietnam,
		India,
		Max,
	};
	enum class EGrade : uint8
	{
		Common,
		Rare,
		Epic,
		Unique,
		Max,
	};
	struct SRankingUser : public SProto
	{
		TUID UID{};
		u16string Nick{};
		int32 CharCode{};
		wstring CountryCode{};
		int32 Point{};
		SRankingUser()
		{
		}
		SRankingUser(const TUID& UID_, const u16string& Nick_, const int32& CharCode_, const wstring& CountryCode_, const int32& Point_) : UID(UID_), Nick(Nick_), CharCode(CharCode_), CountryCode(CountryCode_), Point(Point_)
		{
		}
		SRankingUser(TUID&& UID_, u16string&& Nick_, int32&& CharCode_, wstring&& CountryCode_, int32&& Point_) : UID(std::move(UID_)), Nick(std::move(Nick_)), CharCode(std::move(CharCode_)), CountryCode(std::move(CountryCode_)), Point(std::move(Point_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> UID;
			Stream_ >> Nick;
			Stream_ >> CharCode;
			Stream_ >> CountryCode;
			Stream_ >> Point;
		}
		void operator << (const Value& Value_) override
		{
			Value_["UID"] >> UID;
			Value_["Nick"] >> Nick;
			Value_["CharCode"] >> CharCode;
			Value_["CountryCode"] >> CountryCode;
			Value_["Point"] >> Point;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << UID;
			Stream_ << Nick;
			Stream_ << CharCode;
			Stream_ << CountryCode;
			Stream_ << Point;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["UID"] = UID;
			Value_["Nick"] = Nick;
			Value_["CharCode"] = CharCode;
			Value_["CountryCode"] = CountryCode;
			Value_["Point"] = Point;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(TUID()) + L"," + 
				GetStdName(u16string()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(wstring()) + L"," + 
				GetStdName(int32());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(TUID(), L"UID") + L"," + 
				GetMemberName(u16string(), L"Nick") + L"," + 
				GetMemberName(int32(), L"CharCode") + L"," + 
				GetMemberName(wstring(), L"CountryCode") + L"," + 
				GetMemberName(int32(), L"Point");
		}
	};
	using TRankingUsers = list<SRankingUser>;
	struct SRankingUsers : public SProto
	{
		TRankingUsers RankingUsers{};
		SRankingUsers()
		{
		}
		SRankingUsers(const TRankingUsers& RankingUsers_) : RankingUsers(RankingUsers_)
		{
		}
		SRankingUsers(TRankingUsers&& RankingUsers_) : RankingUsers(std::move(RankingUsers_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> RankingUsers;
		}
		void operator << (const Value& Value_) override
		{
			Value_["RankingUsers"] >> RankingUsers;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << RankingUsers;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["RankingUsers"] = RankingUsers;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(TRankingUsers());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(TRankingUsers(), L"RankingUsers");
		}
	};
	using TRankings = map<TUID,int32>;
	enum class ERankingType
	{
		Multi,
		Single,
		Island,
		Max,
		Null,
	};
	using TRankingArray = array<int32,3>;
	using TRankingPointArray = array<int32,3>;
	using TRankingsArray = array<TRankings,3>;
	using TRankingUsersArray = array<SRankingUsers,3>;
	struct SUserLoginOption : public SProto
	{
		EOS OS{};
		SUserLoginOption()
		{
		}
		SUserLoginOption(const EOS& OS_) : OS(OS_)
		{
		}
		SUserLoginOption(EOS&& OS_) : OS(std::move(OS_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> OS;
		}
		void operator << (const Value& Value_) override
		{
			Value_["OS"] >> OS;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << OS;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["OS"] = OS;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(EOS());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(EOS(), L"OS");
		}
	};
	struct SUserCreateOption : public SProto
	{
		SUserLoginOption LoginOption{};
		ELanguage Language{};
		SUserCreateOption()
		{
		}
		SUserCreateOption(const SUserLoginOption& LoginOption_, const ELanguage& Language_) : LoginOption(LoginOption_), Language(Language_)
		{
		}
		SUserCreateOption(SUserLoginOption&& LoginOption_, ELanguage&& Language_) : LoginOption(std::move(LoginOption_)), Language(std::move(Language_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> LoginOption;
			Stream_ >> Language;
		}
		void operator << (const Value& Value_) override
		{
			Value_["LoginOption"] >> LoginOption;
			Value_["Language"] >> Language;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << LoginOption;
			Stream_ << Language;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["LoginOption"] = LoginOption;
			Value_["Language"] = Language;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(SUserLoginOption()) + L"," + 
				GetStdName(ELanguage());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(SUserLoginOption(), L"LoginOption") + L"," + 
				GetMemberName(ELanguage(), L"Language");
		}
	};
	enum class EResource
	{
		Ticket,
		Gold,
		Dia00,
		Dia01,
		Dia02,
		Dia03,
		Max,
		Null,
	};
	using TResource = int32;
	using TResources = array<TResource,6>;
	enum class EQuestType
	{
		IngameBalloonPopping,
		IngameKill,
		BlowBalloon,
		PlayNormal,
		PlayRare,
		PlayEpic,
		PlaySingle,
		SinglePlayScoreGet,
		PlayIsland,
		IslandScoreGet,
		SoloPlay,
		SoloVictory,
		Max,
		Null=-1,
	};
	struct SQuestSlotIndexCount : public SProto
	{
		TQuestSlotIndex SlotIndex{};
		int32 Count{};
		SQuestSlotIndexCount()
		{
		}
		SQuestSlotIndexCount(const TQuestSlotIndex& SlotIndex_, const int32& Count_) : SlotIndex(SlotIndex_), Count(Count_)
		{
		}
		SQuestSlotIndexCount(TQuestSlotIndex&& SlotIndex_, int32&& Count_) : SlotIndex(std::move(SlotIndex_)), Count(std::move(Count_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> SlotIndex;
			Stream_ >> Count;
		}
		void operator << (const Value& Value_) override
		{
			Value_["SlotIndex"] >> SlotIndex;
			Value_["Count"] >> Count;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << SlotIndex;
			Stream_ << Count;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["SlotIndex"] = SlotIndex;
			Value_["Count"] = Count;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(TQuestSlotIndex()) + L"," + 
				GetStdName(int32());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(TQuestSlotIndex(), L"SlotIndex") + L"," + 
				GetMemberName(int32(), L"Count");
		}
	};
	using TDoneQuests = list<SQuestSlotIndexCount>;
	struct SRetNetSc : public SProto
	{
		ERet Ret{};
		SRetNetSc()
		{
		}
		SRetNetSc(const ERet& Ret_) : Ret(Ret_)
		{
		}
		SRetNetSc(ERet&& Ret_) : Ret(std::move(Ret_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Ret;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Ret"] >> Ret;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Ret;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Ret"] = Ret;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(ERet());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(ERet(), L"Ret");
		}
	};
	struct SMsgNetSc : public SProto
	{
		wstring Msg{};
		SMsgNetSc()
		{
		}
		SMsgNetSc(const wstring& Msg_) : Msg(Msg_)
		{
		}
		SMsgNetSc(wstring&& Msg_) : Msg(std::move(Msg_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Msg;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Msg"] >> Msg;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Msg;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Msg"] = Msg;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(wstring());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(wstring(), L"Msg");
		}
	};
	struct SResourceTypeData : public SProto
	{
		EResource Type{};
		TResource Data{};
		SResourceTypeData()
		{
		}
		SResourceTypeData(const EResource& Type_, const TResource& Data_) : Type(Type_), Data(Data_)
		{
		}
		SResourceTypeData(EResource&& Type_, TResource&& Data_) : Type(std::move(Type_)), Data(std::move(Data_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Type;
			Stream_ >> Data;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Type"] >> Type;
			Value_["Data"] >> Data;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Type;
			Stream_ << Data;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Type"] = Type;
			Value_["Data"] = Data;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(EResource()) + L"," + 
				GetStdName(TResource());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(EResource(), L"Type") + L"," + 
				GetMemberName(TResource(), L"Data");
		}
	};
	struct SUserCore : public SProto
	{
		TResources Resources{};
		int8 Debug{};
		int32 SelectedCharCode{};
		int32 SinglePlayCount{};
		system_clock::time_point SingleRefreshTime{};
		int32 IslandPlayCount{};
		system_clock::time_point IslandRefreshTime{};
		system_clock::time_point QuestDailyCompleteRefreshTime{};
		int32 ChangeNickFreeCount{};
		SUserCore()
		{
		}
		SUserCore(const TResources& Resources_, const int8& Debug_, const int32& SelectedCharCode_, const int32& SinglePlayCount_, const system_clock::time_point& SingleRefreshTime_, const int32& IslandPlayCount_, const system_clock::time_point& IslandRefreshTime_, const system_clock::time_point& QuestDailyCompleteRefreshTime_, const int32& ChangeNickFreeCount_) : Resources(Resources_), Debug(Debug_), SelectedCharCode(SelectedCharCode_), SinglePlayCount(SinglePlayCount_), SingleRefreshTime(SingleRefreshTime_), IslandPlayCount(IslandPlayCount_), IslandRefreshTime(IslandRefreshTime_), QuestDailyCompleteRefreshTime(QuestDailyCompleteRefreshTime_), ChangeNickFreeCount(ChangeNickFreeCount_)
		{
		}
		SUserCore(TResources&& Resources_, int8&& Debug_, int32&& SelectedCharCode_, int32&& SinglePlayCount_, system_clock::time_point&& SingleRefreshTime_, int32&& IslandPlayCount_, system_clock::time_point&& IslandRefreshTime_, system_clock::time_point&& QuestDailyCompleteRefreshTime_, int32&& ChangeNickFreeCount_) : Resources(std::move(Resources_)), Debug(std::move(Debug_)), SelectedCharCode(std::move(SelectedCharCode_)), SinglePlayCount(std::move(SinglePlayCount_)), SingleRefreshTime(std::move(SingleRefreshTime_)), IslandPlayCount(std::move(IslandPlayCount_)), IslandRefreshTime(std::move(IslandRefreshTime_)), QuestDailyCompleteRefreshTime(std::move(QuestDailyCompleteRefreshTime_)), ChangeNickFreeCount(std::move(ChangeNickFreeCount_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Resources;
			Stream_ >> Debug;
			Stream_ >> SelectedCharCode;
			Stream_ >> SinglePlayCount;
			Stream_ >> SingleRefreshTime;
			Stream_ >> IslandPlayCount;
			Stream_ >> IslandRefreshTime;
			Stream_ >> QuestDailyCompleteRefreshTime;
			Stream_ >> ChangeNickFreeCount;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Resources"] >> Resources;
			Value_["Debug"] >> Debug;
			Value_["SelectedCharCode"] >> SelectedCharCode;
			Value_["SinglePlayCount"] >> SinglePlayCount;
			Value_["SingleRefreshTime"] >> SingleRefreshTime;
			Value_["IslandPlayCount"] >> IslandPlayCount;
			Value_["IslandRefreshTime"] >> IslandRefreshTime;
			Value_["QuestDailyCompleteRefreshTime"] >> QuestDailyCompleteRefreshTime;
			Value_["ChangeNickFreeCount"] >> ChangeNickFreeCount;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Resources;
			Stream_ << Debug;
			Stream_ << SelectedCharCode;
			Stream_ << SinglePlayCount;
			Stream_ << SingleRefreshTime;
			Stream_ << IslandPlayCount;
			Stream_ << IslandRefreshTime;
			Stream_ << QuestDailyCompleteRefreshTime;
			Stream_ << ChangeNickFreeCount;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Resources"] = Resources;
			Value_["Debug"] = Debug;
			Value_["SelectedCharCode"] = SelectedCharCode;
			Value_["SinglePlayCount"] = SinglePlayCount;
			Value_["SingleRefreshTime"] = SingleRefreshTime;
			Value_["IslandPlayCount"] = IslandPlayCount;
			Value_["IslandRefreshTime"] = IslandRefreshTime;
			Value_["QuestDailyCompleteRefreshTime"] = QuestDailyCompleteRefreshTime;
			Value_["ChangeNickFreeCount"] = ChangeNickFreeCount;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(TResources()) + L"," + 
				GetStdName(int8()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(system_clock::time_point()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(system_clock::time_point()) + L"," + 
				GetStdName(system_clock::time_point()) + L"," + 
				GetStdName(int32());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(TResources(), L"Resources") + L"," + 
				GetMemberName(int8(), L"Debug") + L"," + 
				GetMemberName(int32(), L"SelectedCharCode") + L"," + 
				GetMemberName(int32(), L"SinglePlayCount") + L"," + 
				GetMemberName(system_clock::time_point(), L"SingleRefreshTime") + L"," + 
				GetMemberName(int32(), L"IslandPlayCount") + L"," + 
				GetMemberName(system_clock::time_point(), L"IslandRefreshTime") + L"," + 
				GetMemberName(system_clock::time_point(), L"QuestDailyCompleteRefreshTime") + L"," + 
				GetMemberName(int32(), L"ChangeNickFreeCount");
		}
	};
	struct SInvalidDisconnectInfo : public SProto
	{
		system_clock::time_point EndTime{};
		system_clock::time_point MatchBlockEndTime{};
		int32 Count{};
		SInvalidDisconnectInfo()
		{
		}
		SInvalidDisconnectInfo(const system_clock::time_point& EndTime_, const system_clock::time_point& MatchBlockEndTime_, const int32& Count_) : EndTime(EndTime_), MatchBlockEndTime(MatchBlockEndTime_), Count(Count_)
		{
		}
		SInvalidDisconnectInfo(system_clock::time_point&& EndTime_, system_clock::time_point&& MatchBlockEndTime_, int32&& Count_) : EndTime(std::move(EndTime_)), MatchBlockEndTime(std::move(MatchBlockEndTime_)), Count(std::move(Count_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> EndTime;
			Stream_ >> MatchBlockEndTime;
			Stream_ >> Count;
		}
		void operator << (const Value& Value_) override
		{
			Value_["EndTime"] >> EndTime;
			Value_["MatchBlockEndTime"] >> MatchBlockEndTime;
			Value_["Count"] >> Count;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << EndTime;
			Stream_ << MatchBlockEndTime;
			Stream_ << Count;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["EndTime"] = EndTime;
			Value_["MatchBlockEndTime"] = MatchBlockEndTime;
			Value_["Count"] = Count;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(system_clock::time_point()) + L"," + 
				GetStdName(system_clock::time_point()) + L"," + 
				GetStdName(int32());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(system_clock::time_point(), L"EndTime") + L"," + 
				GetMemberName(system_clock::time_point(), L"MatchBlockEndTime") + L"," + 
				GetMemberName(int32(), L"Count");
		}
	};
	struct SUserBase : public SUserCore
	{
		TExp Exp{};
		bool CanPushAtNight{};
		double eloPoint{};
		int32 Point{};
		int32 PointBest{};
		int32 NextRewardRankIndex{};
		int32 WinCountSolo{};
		int32 LoseCountSolo{};
		int32 WinCountMulti{};
		int32 LoseCountMulti{};
		int32 BattlePointBest{};
		int32 SinglePointBest{};
		int32 IslandPointBest{};
		int32 IslandComboBest{};
		int32 KillTotal{};
		int32 ChainKillTotal{};
		int32 BlowBalloonTotal{};
		int32 QuestDailyCompleteCount{};
		bool TutorialReward{};
		int64 RankingRewardedCounter{};
		TNick NewNick{};
		SInvalidDisconnectInfo InvalidDisconnectInfo{};
		system_clock::time_point fatigueLastUpdateTime{};
		SUserBase()
		{
		}
		SUserBase(const SUserCore& Super_, const TExp& Exp_, const bool& CanPushAtNight_, const double& eloPoint_, const int32& Point_, const int32& PointBest_, const int32& NextRewardRankIndex_, const int32& WinCountSolo_, const int32& LoseCountSolo_, const int32& WinCountMulti_, const int32& LoseCountMulti_, const int32& BattlePointBest_, const int32& SinglePointBest_, const int32& IslandPointBest_, const int32& IslandComboBest_, const int32& KillTotal_, const int32& ChainKillTotal_, const int32& BlowBalloonTotal_, const int32& QuestDailyCompleteCount_, const bool& TutorialReward_, const int64& RankingRewardedCounter_, const TNick& NewNick_, const SInvalidDisconnectInfo& InvalidDisconnectInfo_, const system_clock::time_point& fatigueLastUpdateTime_) : SUserCore(Super_), Exp(Exp_), CanPushAtNight(CanPushAtNight_), eloPoint(eloPoint_), Point(Point_), PointBest(PointBest_), NextRewardRankIndex(NextRewardRankIndex_), WinCountSolo(WinCountSolo_), LoseCountSolo(LoseCountSolo_), WinCountMulti(WinCountMulti_), LoseCountMulti(LoseCountMulti_), BattlePointBest(BattlePointBest_), SinglePointBest(SinglePointBest_), IslandPointBest(IslandPointBest_), IslandComboBest(IslandComboBest_), KillTotal(KillTotal_), ChainKillTotal(ChainKillTotal_), BlowBalloonTotal(BlowBalloonTotal_), QuestDailyCompleteCount(QuestDailyCompleteCount_), TutorialReward(TutorialReward_), RankingRewardedCounter(RankingRewardedCounter_), NewNick(NewNick_), InvalidDisconnectInfo(InvalidDisconnectInfo_), fatigueLastUpdateTime(fatigueLastUpdateTime_)
		{
		}
		SUserBase(SUserCore&& Super_, TExp&& Exp_, bool&& CanPushAtNight_, double&& eloPoint_, int32&& Point_, int32&& PointBest_, int32&& NextRewardRankIndex_, int32&& WinCountSolo_, int32&& LoseCountSolo_, int32&& WinCountMulti_, int32&& LoseCountMulti_, int32&& BattlePointBest_, int32&& SinglePointBest_, int32&& IslandPointBest_, int32&& IslandComboBest_, int32&& KillTotal_, int32&& ChainKillTotal_, int32&& BlowBalloonTotal_, int32&& QuestDailyCompleteCount_, bool&& TutorialReward_, int64&& RankingRewardedCounter_, TNick&& NewNick_, SInvalidDisconnectInfo&& InvalidDisconnectInfo_, system_clock::time_point&& fatigueLastUpdateTime_) : SUserCore(std::move(Super_)), Exp(std::move(Exp_)), CanPushAtNight(std::move(CanPushAtNight_)), eloPoint(std::move(eloPoint_)), Point(std::move(Point_)), PointBest(std::move(PointBest_)), NextRewardRankIndex(std::move(NextRewardRankIndex_)), WinCountSolo(std::move(WinCountSolo_)), LoseCountSolo(std::move(LoseCountSolo_)), WinCountMulti(std::move(WinCountMulti_)), LoseCountMulti(std::move(LoseCountMulti_)), BattlePointBest(std::move(BattlePointBest_)), SinglePointBest(std::move(SinglePointBest_)), IslandPointBest(std::move(IslandPointBest_)), IslandComboBest(std::move(IslandComboBest_)), KillTotal(std::move(KillTotal_)), ChainKillTotal(std::move(ChainKillTotal_)), BlowBalloonTotal(std::move(BlowBalloonTotal_)), QuestDailyCompleteCount(std::move(QuestDailyCompleteCount_)), TutorialReward(std::move(TutorialReward_)), RankingRewardedCounter(std::move(RankingRewardedCounter_)), NewNick(std::move(NewNick_)), InvalidDisconnectInfo(std::move(InvalidDisconnectInfo_)), fatigueLastUpdateTime(std::move(fatigueLastUpdateTime_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			SUserCore::operator << (Stream_);
			Stream_ >> Exp;
			Stream_ >> CanPushAtNight;
			Stream_ >> eloPoint;
			Stream_ >> Point;
			Stream_ >> PointBest;
			Stream_ >> NextRewardRankIndex;
			Stream_ >> WinCountSolo;
			Stream_ >> LoseCountSolo;
			Stream_ >> WinCountMulti;
			Stream_ >> LoseCountMulti;
			Stream_ >> BattlePointBest;
			Stream_ >> SinglePointBest;
			Stream_ >> IslandPointBest;
			Stream_ >> IslandComboBest;
			Stream_ >> KillTotal;
			Stream_ >> ChainKillTotal;
			Stream_ >> BlowBalloonTotal;
			Stream_ >> QuestDailyCompleteCount;
			Stream_ >> TutorialReward;
			Stream_ >> RankingRewardedCounter;
			Stream_ >> NewNick;
			Stream_ >> InvalidDisconnectInfo;
			Stream_ >> fatigueLastUpdateTime;
		}
		void operator << (const Value& Value_) override
		{
			SUserCore::operator << (Value_);
			Value_["Exp"] >> Exp;
			Value_["CanPushAtNight"] >> CanPushAtNight;
			Value_["eloPoint"] >> eloPoint;
			Value_["Point"] >> Point;
			Value_["PointBest"] >> PointBest;
			Value_["NextRewardRankIndex"] >> NextRewardRankIndex;
			Value_["WinCountSolo"] >> WinCountSolo;
			Value_["LoseCountSolo"] >> LoseCountSolo;
			Value_["WinCountMulti"] >> WinCountMulti;
			Value_["LoseCountMulti"] >> LoseCountMulti;
			Value_["BattlePointBest"] >> BattlePointBest;
			Value_["SinglePointBest"] >> SinglePointBest;
			Value_["IslandPointBest"] >> IslandPointBest;
			Value_["IslandComboBest"] >> IslandComboBest;
			Value_["KillTotal"] >> KillTotal;
			Value_["ChainKillTotal"] >> ChainKillTotal;
			Value_["BlowBalloonTotal"] >> BlowBalloonTotal;
			Value_["QuestDailyCompleteCount"] >> QuestDailyCompleteCount;
			Value_["TutorialReward"] >> TutorialReward;
			Value_["RankingRewardedCounter"] >> RankingRewardedCounter;
			Value_["NewNick"] >> NewNick;
			Value_["InvalidDisconnectInfo"] >> InvalidDisconnectInfo;
			Value_["fatigueLastUpdateTime"] >> fatigueLastUpdateTime;
		}
		void operator >> (CStream& Stream_) const override
		{
			SUserCore::operator >> (Stream_);
			Stream_ << Exp;
			Stream_ << CanPushAtNight;
			Stream_ << eloPoint;
			Stream_ << Point;
			Stream_ << PointBest;
			Stream_ << NextRewardRankIndex;
			Stream_ << WinCountSolo;
			Stream_ << LoseCountSolo;
			Stream_ << WinCountMulti;
			Stream_ << LoseCountMulti;
			Stream_ << BattlePointBest;
			Stream_ << SinglePointBest;
			Stream_ << IslandPointBest;
			Stream_ << IslandComboBest;
			Stream_ << KillTotal;
			Stream_ << ChainKillTotal;
			Stream_ << BlowBalloonTotal;
			Stream_ << QuestDailyCompleteCount;
			Stream_ << TutorialReward;
			Stream_ << RankingRewardedCounter;
			Stream_ << NewNick;
			Stream_ << InvalidDisconnectInfo;
			Stream_ << fatigueLastUpdateTime;
		}
		void operator >> (Value& Value_) const override
		{
			SUserCore::operator >> (Value_);
			Value_["Exp"] = Exp;
			Value_["CanPushAtNight"] = CanPushAtNight;
			Value_["eloPoint"] = eloPoint;
			Value_["Point"] = Point;
			Value_["PointBest"] = PointBest;
			Value_["NextRewardRankIndex"] = NextRewardRankIndex;
			Value_["WinCountSolo"] = WinCountSolo;
			Value_["LoseCountSolo"] = LoseCountSolo;
			Value_["WinCountMulti"] = WinCountMulti;
			Value_["LoseCountMulti"] = LoseCountMulti;
			Value_["BattlePointBest"] = BattlePointBest;
			Value_["SinglePointBest"] = SinglePointBest;
			Value_["IslandPointBest"] = IslandPointBest;
			Value_["IslandComboBest"] = IslandComboBest;
			Value_["KillTotal"] = KillTotal;
			Value_["ChainKillTotal"] = ChainKillTotal;
			Value_["BlowBalloonTotal"] = BlowBalloonTotal;
			Value_["QuestDailyCompleteCount"] = QuestDailyCompleteCount;
			Value_["TutorialReward"] = TutorialReward;
			Value_["RankingRewardedCounter"] = RankingRewardedCounter;
			Value_["NewNick"] = NewNick;
			Value_["InvalidDisconnectInfo"] = InvalidDisconnectInfo;
			Value_["fatigueLastUpdateTime"] = fatigueLastUpdateTime;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(SUserCore()) + L"," + 
				GetStdName(TExp()) + L"," + 
				GetStdName(bool()) + L"," + 
				GetStdName(double()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(bool()) + L"," + 
				GetStdName(int64()) + L"," + 
				GetStdName(TNick()) + L"," + 
				GetStdName(SInvalidDisconnectInfo()) + L"," + 
				GetStdName(system_clock::time_point());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(SUserCore(), L"") + L"," + 
				GetMemberName(TExp(), L"Exp") + L"," + 
				GetMemberName(bool(), L"CanPushAtNight") + L"," + 
				GetMemberName(double(), L"eloPoint") + L"," + 
				GetMemberName(int32(), L"Point") + L"," + 
				GetMemberName(int32(), L"PointBest") + L"," + 
				GetMemberName(int32(), L"NextRewardRankIndex") + L"," + 
				GetMemberName(int32(), L"WinCountSolo") + L"," + 
				GetMemberName(int32(), L"LoseCountSolo") + L"," + 
				GetMemberName(int32(), L"WinCountMulti") + L"," + 
				GetMemberName(int32(), L"LoseCountMulti") + L"," + 
				GetMemberName(int32(), L"BattlePointBest") + L"," + 
				GetMemberName(int32(), L"SinglePointBest") + L"," + 
				GetMemberName(int32(), L"IslandPointBest") + L"," + 
				GetMemberName(int32(), L"IslandComboBest") + L"," + 
				GetMemberName(int32(), L"KillTotal") + L"," + 
				GetMemberName(int32(), L"ChainKillTotal") + L"," + 
				GetMemberName(int32(), L"BlowBalloonTotal") + L"," + 
				GetMemberName(int32(), L"QuestDailyCompleteCount") + L"," + 
				GetMemberName(bool(), L"TutorialReward") + L"," + 
				GetMemberName(int64(), L"RankingRewardedCounter") + L"," + 
				GetMemberName(TNick(), L"NewNick") + L"," + 
				GetMemberName(SInvalidDisconnectInfo(), L"InvalidDisconnectInfo") + L"," + 
				GetMemberName(system_clock::time_point(), L"fatigueLastUpdateTime");
		}
	};
	struct SUserNet : public SUserBase
	{
		wstring CountryCode{};
		SUserNet()
		{
		}
		SUserNet(const SUserBase& Super_, const wstring& CountryCode_) : SUserBase(Super_), CountryCode(CountryCode_)
		{
		}
		SUserNet(SUserBase&& Super_, wstring&& CountryCode_) : SUserBase(std::move(Super_)), CountryCode(std::move(CountryCode_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			SUserBase::operator << (Stream_);
			Stream_ >> CountryCode;
		}
		void operator << (const Value& Value_) override
		{
			SUserBase::operator << (Value_);
			Value_["CountryCode"] >> CountryCode;
		}
		void operator >> (CStream& Stream_) const override
		{
			SUserBase::operator >> (Stream_);
			Stream_ << CountryCode;
		}
		void operator >> (Value& Value_) const override
		{
			SUserBase::operator >> (Value_);
			Value_["CountryCode"] = CountryCode;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(SUserBase()) + L"," + 
				GetStdName(wstring());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(SUserBase(), L"") + L"," + 
				GetMemberName(wstring(), L"CountryCode");
		}
	};
	struct CharacterDB : public SProto
	{
		int32 fatigue{};
		CharacterDB()
		{
		}
		CharacterDB(const int32& fatigue_) : fatigue(fatigue_)
		{
		}
		CharacterDB(int32&& fatigue_) : fatigue(std::move(fatigue_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> fatigue;
		}
		void operator << (const Value& Value_) override
		{
			Value_["fatigue"] >> fatigue;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << fatigue;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["fatigue"] = fatigue;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(int32());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(int32(), L"fatigue");
		}
	};
	using CharacterDBs = map<int32,CharacterDB>;
	struct CodeTokenID : public SProto
	{
		int32 code{};
		TokenID tokenID{};
		CodeTokenID()
		{
		}
		CodeTokenID(const int32& code_, const TokenID& tokenID_) : code(code_), tokenID(tokenID_)
		{
		}
		CodeTokenID(int32&& code_, TokenID&& tokenID_) : code(std::move(code_)), tokenID(std::move(tokenID_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> code;
			Stream_ >> tokenID;
		}
		void operator << (const Value& Value_) override
		{
			Value_["code"] >> code;
			Value_["tokenID"] >> tokenID;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << code;
			Stream_ << tokenID;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["code"] = code;
			Value_["tokenID"] = tokenID;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(int32()) + L"," + 
				GetStdName(TokenID());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(int32(), L"code") + L"," + 
				GetMemberName(TokenID(), L"tokenID");
		}
	};
	using CodeTokenIDs = list<CodeTokenID>;
	struct SQuestBase : public SProto
	{
		int32 Code{};
		int32 Count{};
		system_clock::time_point CoolEndTime{};
		SQuestBase()
		{
		}
		SQuestBase(const int32& Code_, const int32& Count_, const system_clock::time_point& CoolEndTime_) : Code(Code_), Count(Count_), CoolEndTime(CoolEndTime_)
		{
		}
		SQuestBase(int32&& Code_, int32&& Count_, system_clock::time_point&& CoolEndTime_) : Code(std::move(Code_)), Count(std::move(Count_)), CoolEndTime(std::move(CoolEndTime_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Code;
			Stream_ >> Count;
			Stream_ >> CoolEndTime;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Code"] >> Code;
			Value_["Count"] >> Count;
			Value_["CoolEndTime"] >> CoolEndTime;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Code;
			Stream_ << Count;
			Stream_ << CoolEndTime;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Code"] = Code;
			Value_["Count"] = Count;
			Value_["CoolEndTime"] = CoolEndTime;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(system_clock::time_point());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(int32(), L"Code") + L"," + 
				GetMemberName(int32(), L"Count") + L"," + 
				GetMemberName(system_clock::time_point(), L"CoolEndTime");
		}
	};
	using TQuestDBs = map<TQuestSlotIndex,SQuestBase>;
	using TokenIDs = set<TokenID>;
	struct CharacterInfo : public CharacterDB
	{
		TokenIDs tokenIDs{};
		CharacterInfo()
		{
		}
		CharacterInfo(const CharacterDB& Super_, const TokenIDs& tokenIDs_) : CharacterDB(Super_), tokenIDs(tokenIDs_)
		{
		}
		CharacterInfo(CharacterDB&& Super_, TokenIDs&& tokenIDs_) : CharacterDB(std::move(Super_)), tokenIDs(std::move(tokenIDs_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			CharacterDB::operator << (Stream_);
			Stream_ >> tokenIDs;
		}
		void operator << (const Value& Value_) override
		{
			CharacterDB::operator << (Value_);
			Value_["tokenIDs"] >> tokenIDs;
		}
		void operator >> (CStream& Stream_) const override
		{
			CharacterDB::operator >> (Stream_);
			Stream_ << tokenIDs;
		}
		void operator >> (Value& Value_) const override
		{
			CharacterDB::operator >> (Value_);
			Value_["tokenIDs"] = tokenIDs;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(CharacterDB()) + L"," + 
				GetStdName(TokenIDs());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(CharacterDB(), L"") + L"," + 
				GetMemberName(TokenIDs(), L"tokenIDs");
		}
	};
	using CharacterInfos = map<int32,CharacterInfo>;
	struct SLoginNetSc : public SProto
	{
		SUserNet User{};
		CharacterInfos characterInfos{};
		system_clock::time_point ServerTime{};
		TQuestDBs Quests{};
		SLoginNetSc()
		{
		}
		SLoginNetSc(const SUserNet& User_, const CharacterInfos& characterInfos_, const system_clock::time_point& ServerTime_, const TQuestDBs& Quests_) : User(User_), characterInfos(characterInfos_), ServerTime(ServerTime_), Quests(Quests_)
		{
		}
		SLoginNetSc(SUserNet&& User_, CharacterInfos&& characterInfos_, system_clock::time_point&& ServerTime_, TQuestDBs&& Quests_) : User(std::move(User_)), characterInfos(std::move(characterInfos_)), ServerTime(std::move(ServerTime_)), Quests(std::move(Quests_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> User;
			Stream_ >> characterInfos;
			Stream_ >> ServerTime;
			Stream_ >> Quests;
		}
		void operator << (const Value& Value_) override
		{
			Value_["User"] >> User;
			Value_["characterInfos"] >> characterInfos;
			Value_["ServerTime"] >> ServerTime;
			Value_["Quests"] >> Quests;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << User;
			Stream_ << characterInfos;
			Stream_ << ServerTime;
			Stream_ << Quests;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["User"] = User;
			Value_["characterInfos"] = characterInfos;
			Value_["ServerTime"] = ServerTime;
			Value_["Quests"] = Quests;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(SUserNet()) + L"," + 
				GetStdName(CharacterInfos()) + L"," + 
				GetStdName(system_clock::time_point()) + L"," + 
				GetStdName(TQuestDBs());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(SUserNet(), L"User") + L"," + 
				GetMemberName(CharacterInfos(), L"characterInfos") + L"," + 
				GetMemberName(system_clock::time_point(), L"ServerTime") + L"," + 
				GetMemberName(TQuestDBs(), L"Quests");
		}
	};
	struct SLobbyNetSc : public SProto
	{
		void operator << (CStream&) override
		{
		}
		void operator << (const Value&) override
		{
		}
		void operator >> (CStream&) const override
		{
		}
		void operator >> (Value&) const override
		{
		}
		static wstring StdName(void)
		{
			return L"";
		}
		static wstring MemberName(void)
		{
			return L"";
		}
	};
	struct SUserExpNetSc : public SProto
	{
		TExp Exp{};
		SUserExpNetSc()
		{
		}
		SUserExpNetSc(const TExp& Exp_) : Exp(Exp_)
		{
		}
		SUserExpNetSc(TExp&& Exp_) : Exp(std::move(Exp_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Exp;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Exp"] >> Exp;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Exp;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Exp"] = Exp;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(TExp());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(TExp(), L"Exp");
		}
	};
	struct SResourcesNetSc : public SProto
	{
		TResources Resources{};
		SResourcesNetSc()
		{
		}
		SResourcesNetSc(const TResources& Resources_) : Resources(Resources_)
		{
		}
		SResourcesNetSc(TResources&& Resources_) : Resources(std::move(Resources_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Resources;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Resources"] >> Resources;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Resources;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Resources"] = Resources;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(TResources());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(TResources(), L"Resources");
		}
	};
	struct SSetPointNetSc : public SProto
	{
		int32 Point{};
		SSetPointNetSc()
		{
		}
		SSetPointNetSc(const int32& Point_) : Point(Point_)
		{
		}
		SSetPointNetSc(int32&& Point_) : Point(std::move(Point_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Point;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Point"] >> Point;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Point;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Point"] = Point;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(int32());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(int32(), L"Point");
		}
	};
	struct SSetCharNetSc : public SProto
	{
		CodeTokenIDs characters{};
		SSetCharNetSc()
		{
		}
		SSetCharNetSc(const CodeTokenIDs& characters_) : characters(characters_)
		{
		}
		SSetCharNetSc(CodeTokenIDs&& characters_) : characters(std::move(characters_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> characters;
		}
		void operator << (const Value& Value_) override
		{
			Value_["characters"] >> characters;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << characters;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["characters"] = characters;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(CodeTokenIDs());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(CodeTokenIDs(), L"characters");
		}
	};
	struct SUnsetCharNetSc : public SProto
	{
		list<int32> CharCodes{};
		SUnsetCharNetSc()
		{
		}
		SUnsetCharNetSc(const list<int32>& CharCodes_) : CharCodes(CharCodes_)
		{
		}
		SUnsetCharNetSc(list<int32>&& CharCodes_) : CharCodes(std::move(CharCodes_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> CharCodes;
		}
		void operator << (const Value& Value_) override
		{
			Value_["CharCodes"] >> CharCodes;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << CharCodes;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["CharCodes"] = CharCodes;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(list<int32>());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(list<int32>(), L"CharCodes");
		}
	};
	struct SChatNetCs : public SProto
	{
		wstring Msg{};
		SChatNetCs()
		{
		}
		SChatNetCs(const wstring& Msg_) : Msg(Msg_)
		{
		}
		SChatNetCs(wstring&& Msg_) : Msg(std::move(Msg_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Msg;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Msg"] >> Msg;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Msg;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Msg"] = Msg;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(wstring());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(wstring(), L"Msg");
		}
	};
	struct SChatNetSc : public SProto
	{
		wstring Msg{};
		SChatNetSc()
		{
		}
		SChatNetSc(const wstring& Msg_) : Msg(Msg_)
		{
		}
		SChatNetSc(wstring&& Msg_) : Msg(std::move(Msg_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Msg;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Msg"] >> Msg;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Msg;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Msg"] = Msg;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(wstring());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(wstring(), L"Msg");
		}
	};
	struct SFCMTokenSetNetCs : public SProto
	{
		wstring Token{};
		SFCMTokenSetNetCs()
		{
		}
		SFCMTokenSetNetCs(const wstring& Token_) : Token(Token_)
		{
		}
		SFCMTokenSetNetCs(wstring&& Token_) : Token(std::move(Token_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Token;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Token"] >> Token;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Token;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Token"] = Token;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(wstring());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(wstring(), L"Token");
		}
	};
	struct SFCMTokenUnsetNetCs : public SProto
	{
		void operator << (CStream&) override
		{
		}
		void operator << (const Value&) override
		{
		}
		void operator >> (CStream&) const override
		{
		}
		void operator >> (Value&) const override
		{
		}
		static wstring StdName(void)
		{
			return L"";
		}
		static wstring MemberName(void)
		{
			return L"";
		}
	};
	struct SFCMCanPushAtNightNetCs : public SProto
	{
		bool CanPush{};
		SFCMCanPushAtNightNetCs()
		{
		}
		SFCMCanPushAtNightNetCs(const bool& CanPush_) : CanPush(CanPush_)
		{
		}
		SFCMCanPushAtNightNetCs(bool&& CanPush_) : CanPush(std::move(CanPush_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> CanPush;
		}
		void operator << (const Value& Value_) override
		{
			Value_["CanPush"] >> CanPush;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << CanPush;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["CanPush"] = CanPush;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(bool());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(bool(), L"CanPush");
		}
	};
	struct SChangeLanguageNetCs : public SProto
	{
		ELanguage Language{};
		SChangeLanguageNetCs()
		{
		}
		SChangeLanguageNetCs(const ELanguage& Language_) : Language(Language_)
		{
		}
		SChangeLanguageNetCs(ELanguage&& Language_) : Language(std::move(Language_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Language;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Language"] >> Language;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Language;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Language"] = Language;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(ELanguage());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(ELanguage(), L"Language");
		}
	};
	struct SBuyNetCs : public SProto
	{
		int32 Code{};
		SBuyNetCs()
		{
		}
		SBuyNetCs(const int32& Code_) : Code(Code_)
		{
		}
		SBuyNetCs(int32&& Code_) : Code(std::move(Code_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Code;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Code"] >> Code;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Code;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Code"] = Code;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(int32());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(int32(), L"Code");
		}
	};
	struct SRewardCore : public SProto
	{
		TResources ResourcesLeft{};
		CodeTokenIDs CharsAdded{};
		SRewardCore()
		{
		}
		SRewardCore(const TResources& ResourcesLeft_, const CodeTokenIDs& CharsAdded_) : ResourcesLeft(ResourcesLeft_), CharsAdded(CharsAdded_)
		{
		}
		SRewardCore(TResources&& ResourcesLeft_, CodeTokenIDs&& CharsAdded_) : ResourcesLeft(std::move(ResourcesLeft_)), CharsAdded(std::move(CharsAdded_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> ResourcesLeft;
			Stream_ >> CharsAdded;
		}
		void operator << (const Value& Value_) override
		{
			Value_["ResourcesLeft"] >> ResourcesLeft;
			Value_["CharsAdded"] >> CharsAdded;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << ResourcesLeft;
			Stream_ << CharsAdded;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["ResourcesLeft"] = ResourcesLeft;
			Value_["CharsAdded"] = CharsAdded;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(TResources()) + L"," + 
				GetStdName(CodeTokenIDs());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(TResources(), L"ResourcesLeft") + L"," + 
				GetMemberName(CodeTokenIDs(), L"CharsAdded");
		}
	};
	struct SBuyNetSc : public SProto
	{
		TUID UID{};
		TResources ResourcesLeft{};
		SBuyNetSc()
		{
		}
		SBuyNetSc(const TUID& UID_, const TResources& ResourcesLeft_) : UID(UID_), ResourcesLeft(ResourcesLeft_)
		{
		}
		SBuyNetSc(TUID&& UID_, TResources&& ResourcesLeft_) : UID(std::move(UID_)), ResourcesLeft(std::move(ResourcesLeft_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> UID;
			Stream_ >> ResourcesLeft;
		}
		void operator << (const Value& Value_) override
		{
			Value_["UID"] >> UID;
			Value_["ResourcesLeft"] >> ResourcesLeft;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << UID;
			Stream_ << ResourcesLeft;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["UID"] = UID;
			Value_["ResourcesLeft"] = ResourcesLeft;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(TUID()) + L"," + 
				GetStdName(TResources());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(TUID(), L"UID") + L"," + 
				GetMemberName(TResources(), L"ResourcesLeft");
		}
	};
	struct SBuyCharNetCs : public SProto
	{
		int32 Code{};
		SBuyCharNetCs()
		{
		}
		SBuyCharNetCs(const int32& Code_) : Code(Code_)
		{
		}
		SBuyCharNetCs(int32&& Code_) : Code(std::move(Code_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Code;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Code"] >> Code;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Code;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Code"] = Code;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(int32());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(int32(), L"Code");
		}
	};
	struct SBuyCharNetSc : public CodeTokenID
	{
		SBuyCharNetSc()
		{
		}
		SBuyCharNetSc(const CodeTokenID& Super_) : CodeTokenID(Super_)
		{
		}
		SBuyCharNetSc(CodeTokenID&& Super_) : CodeTokenID(std::move(Super_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			CodeTokenID::operator << (Stream_);
		}
		void operator << (const Value& Value_) override
		{
			CodeTokenID::operator << (Value_);
		}
		void operator >> (CStream& Stream_) const override
		{
			CodeTokenID::operator >> (Stream_);
		}
		void operator >> (Value& Value_) const override
		{
			CodeTokenID::operator >> (Value_);
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(CodeTokenID());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(CodeTokenID(), L"");
		}
	};
	struct SBuyNFTCharNetSc : public CodeTokenID
	{
		SBuyNFTCharNetSc()
		{
		}
		SBuyNFTCharNetSc(const CodeTokenID& Super_) : CodeTokenID(Super_)
		{
		}
		SBuyNFTCharNetSc(CodeTokenID&& Super_) : CodeTokenID(std::move(Super_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			CodeTokenID::operator << (Stream_);
		}
		void operator << (const Value& Value_) override
		{
			CodeTokenID::operator << (Value_);
		}
		void operator >> (CStream& Stream_) const override
		{
			CodeTokenID::operator >> (Stream_);
		}
		void operator >> (Value& Value_) const override
		{
			CodeTokenID::operator >> (Value_);
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(CodeTokenID());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(CodeTokenID(), L"");
		}
	};
	struct SBuyResourceNetCs : public SProto
	{
		SResourceTypeData resourceTypeData{};
		SBuyResourceNetCs()
		{
		}
		SBuyResourceNetCs(const SResourceTypeData& resourceTypeData_) : resourceTypeData(resourceTypeData_)
		{
		}
		SBuyResourceNetCs(SResourceTypeData&& resourceTypeData_) : resourceTypeData(std::move(resourceTypeData_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> resourceTypeData;
		}
		void operator << (const Value& Value_) override
		{
			Value_["resourceTypeData"] >> resourceTypeData;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << resourceTypeData;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["resourceTypeData"] = resourceTypeData;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(SResourceTypeData());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(SResourceTypeData(), L"resourceTypeData");
		}
	};
	struct SBuyResourceNetSc : public SProto
	{
		TResources ResourcesLeft{};
		SBuyResourceNetSc()
		{
		}
		SBuyResourceNetSc(const TResources& ResourcesLeft_) : ResourcesLeft(ResourcesLeft_)
		{
		}
		SBuyResourceNetSc(TResources&& ResourcesLeft_) : ResourcesLeft(std::move(ResourcesLeft_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> ResourcesLeft;
		}
		void operator << (const Value& Value_) override
		{
			Value_["ResourcesLeft"] >> ResourcesLeft;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << ResourcesLeft;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["ResourcesLeft"] = ResourcesLeft;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(TResources());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(TResources(), L"ResourcesLeft");
		}
	};
	struct SSelectCharNetCs : public SProto
	{
		int32 Code{};
		SSelectCharNetCs()
		{
		}
		SSelectCharNetCs(const int32& Code_) : Code(Code_)
		{
		}
		SSelectCharNetCs(int32&& Code_) : Code(std::move(Code_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Code;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Code"] >> Code;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Code;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Code"] = Code;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(int32());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(int32(), L"Code");
		}
	};
	struct SBattleType : public SProto
	{
		TTeamCnt TeamCount{};
		int8 TeamMemberCount{};
		SBattleType()
		{
		}
		SBattleType(const TTeamCnt& TeamCount_, const int8& TeamMemberCount_) : TeamCount(TeamCount_), TeamMemberCount(TeamMemberCount_)
		{
		}
		SBattleType(TTeamCnt&& TeamCount_, int8&& TeamMemberCount_) : TeamCount(std::move(TeamCount_)), TeamMemberCount(std::move(TeamMemberCount_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> TeamCount;
			Stream_ >> TeamMemberCount;
		}
		void operator << (const Value& Value_) override
		{
			Value_["TeamCount"] >> TeamCount;
			Value_["TeamMemberCount"] >> TeamMemberCount;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << TeamCount;
			Stream_ << TeamMemberCount;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["TeamCount"] = TeamCount;
			Value_["TeamMemberCount"] = TeamMemberCount;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(TTeamCnt()) + L"," + 
				GetStdName(int8());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(TTeamCnt(), L"TeamCount") + L"," + 
				GetMemberName(int8(), L"TeamMemberCount");
		}
	};
	struct SBattleSyncNetSc : public SProto
	{
		int64 Tick{};
		SBattleSyncNetSc()
		{
		}
		SBattleSyncNetSc(const int64& Tick_) : Tick(Tick_)
		{
		}
		SBattleSyncNetSc(int64&& Tick_) : Tick(std::move(Tick_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Tick;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Tick"] >> Tick;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Tick;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Tick"] = Tick;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(int64());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(int64(), L"Tick");
		}
	};
	struct SBattleTouchNetCs : public SProto
	{
		int8 Dir{};
		SBattleTouchNetCs()
		{
		}
		SBattleTouchNetCs(const int8& Dir_) : Dir(Dir_)
		{
		}
		SBattleTouchNetCs(int8&& Dir_) : Dir(std::move(Dir_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Dir;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Dir"] >> Dir;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Dir;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Dir"] = Dir;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(int8());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(int8(), L"Dir");
		}
	};
	struct SBattleDirectNetSc : public SProto
	{
		int64 Tick{};
		int32 PlayerIndex{};
		int8 Dir{};
		SBattleDirectNetSc()
		{
		}
		SBattleDirectNetSc(const int64& Tick_, const int32& PlayerIndex_, const int8& Dir_) : Tick(Tick_), PlayerIndex(PlayerIndex_), Dir(Dir_)
		{
		}
		SBattleDirectNetSc(int64&& Tick_, int32&& PlayerIndex_, int8&& Dir_) : Tick(std::move(Tick_)), PlayerIndex(std::move(PlayerIndex_)), Dir(std::move(Dir_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Tick;
			Stream_ >> PlayerIndex;
			Stream_ >> Dir;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Tick"] >> Tick;
			Value_["PlayerIndex"] >> PlayerIndex;
			Value_["Dir"] >> Dir;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Tick;
			Stream_ << PlayerIndex;
			Stream_ << Dir;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Tick"] = Tick;
			Value_["PlayerIndex"] = PlayerIndex;
			Value_["Dir"] = Dir;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(int64()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int8());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(int64(), L"Tick") + L"," + 
				GetMemberName(int32(), L"PlayerIndex") + L"," + 
				GetMemberName(int8(), L"Dir");
		}
	};
	struct SBattlePushNetCs : public SProto
	{
		void operator << (CStream&) override
		{
		}
		void operator << (const Value&) override
		{
		}
		void operator >> (CStream&) const override
		{
		}
		void operator >> (Value&) const override
		{
		}
		static wstring StdName(void)
		{
			return L"";
		}
		static wstring MemberName(void)
		{
			return L"";
		}
	};
	struct SBattleFlapNetSc : public SProto
	{
		int64 Tick{};
		int32 PlayerIndex{};
		SBattleFlapNetSc()
		{
		}
		SBattleFlapNetSc(const int64& Tick_, const int32& PlayerIndex_) : Tick(Tick_), PlayerIndex(PlayerIndex_)
		{
		}
		SBattleFlapNetSc(int64&& Tick_, int32&& PlayerIndex_) : Tick(std::move(Tick_)), PlayerIndex(std::move(PlayerIndex_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Tick;
			Stream_ >> PlayerIndex;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Tick"] >> Tick;
			Value_["PlayerIndex"] >> PlayerIndex;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Tick;
			Stream_ << PlayerIndex;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Tick"] = Tick;
			Value_["PlayerIndex"] = PlayerIndex;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(int64()) + L"," + 
				GetStdName(int32());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(int64(), L"Tick") + L"," + 
				GetMemberName(int32(), L"PlayerIndex");
		}
	};
	struct SBattlePumpNetSc : public SProto
	{
		int64 Tick{};
		int32 PlayerIndex{};
		SBattlePumpNetSc()
		{
		}
		SBattlePumpNetSc(const int64& Tick_, const int32& PlayerIndex_) : Tick(Tick_), PlayerIndex(PlayerIndex_)
		{
		}
		SBattlePumpNetSc(int64&& Tick_, int32&& PlayerIndex_) : Tick(std::move(Tick_)), PlayerIndex(std::move(PlayerIndex_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Tick;
			Stream_ >> PlayerIndex;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Tick"] >> Tick;
			Value_["PlayerIndex"] >> PlayerIndex;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Tick;
			Stream_ << PlayerIndex;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Tick"] = Tick;
			Value_["PlayerIndex"] = PlayerIndex;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(int64()) + L"," + 
				GetStdName(int32());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(int64(), L"Tick") + L"," + 
				GetMemberName(int32(), L"PlayerIndex");
		}
	};
	struct SMultiBattleJoinNetCs : public SProto
	{
		SBattleType BattleType{};
		SMultiBattleJoinNetCs()
		{
		}
		SMultiBattleJoinNetCs(const SBattleType& BattleType_) : BattleType(BattleType_)
		{
		}
		SMultiBattleJoinNetCs(SBattleType&& BattleType_) : BattleType(std::move(BattleType_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> BattleType;
		}
		void operator << (const Value& Value_) override
		{
			Value_["BattleType"] >> BattleType;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << BattleType;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["BattleType"] = BattleType;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(SBattleType());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(SBattleType(), L"BattleType");
		}
	};
	struct SMultiBattleJoinNetSc : public SProto
	{
		void operator << (CStream&) override
		{
		}
		void operator << (const Value&) override
		{
		}
		void operator >> (CStream&) const override
		{
		}
		void operator >> (Value&) const override
		{
		}
		static wstring StdName(void)
		{
			return L"";
		}
		static wstring MemberName(void)
		{
			return L"";
		}
	};
	struct SMultiBattleOutNetCs : public SProto
	{
		void operator << (CStream&) override
		{
		}
		void operator << (const Value&) override
		{
		}
		void operator >> (CStream&) const override
		{
		}
		void operator >> (Value&) const override
		{
		}
		static wstring StdName(void)
		{
			return L"";
		}
		static wstring MemberName(void)
		{
			return L"";
		}
	};
	struct SMultiBattleOutNetSc : public SProto
	{
		void operator << (CStream&) override
		{
		}
		void operator << (const Value&) override
		{
		}
		void operator >> (CStream&) const override
		{
		}
		void operator >> (Value&) const override
		{
		}
		static wstring StdName(void)
		{
			return L"";
		}
		static wstring MemberName(void)
		{
			return L"";
		}
	};
	struct SPumpInfo : public SProto
	{
		int8 Count{};
		int8 CountTo{};
		float Scale{};
		SPumpInfo()
		{
		}
		SPumpInfo(const int8& Count_, const int8& CountTo_, const float& Scale_) : Count(Count_), CountTo(CountTo_), Scale(Scale_)
		{
		}
		SPumpInfo(int8&& Count_, int8&& CountTo_, float&& Scale_) : Count(std::move(Count_)), CountTo(std::move(CountTo_)), Scale(std::move(Scale_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Count;
			Stream_ >> CountTo;
			Stream_ >> Scale;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Count"] >> Count;
			Value_["CountTo"] >> CountTo;
			Value_["Scale"] >> Scale;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Count;
			Stream_ << CountTo;
			Stream_ << Scale;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Count"] = Count;
			Value_["CountTo"] = CountTo;
			Value_["Scale"] = Scale;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(int8()) + L"," + 
				GetStdName(int8()) + L"," + 
				GetStdName(float());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(int8(), L"Count") + L"," + 
				GetMemberName(int8(), L"CountTo") + L"," + 
				GetMemberName(float(), L"Scale");
		}
	};
	struct SParachuteInfo : public SProto
	{
		float Scale{};
		float Velocity{};
		SParachuteInfo()
		{
		}
		SParachuteInfo(const float& Scale_, const float& Velocity_) : Scale(Scale_), Velocity(Velocity_)
		{
		}
		SParachuteInfo(float&& Scale_, float&& Velocity_) : Scale(std::move(Scale_)), Velocity(std::move(Velocity_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Scale;
			Stream_ >> Velocity;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Scale"] >> Scale;
			Value_["Velocity"] >> Velocity;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Scale;
			Stream_ << Velocity;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Scale"] = Scale;
			Value_["Velocity"] = Velocity;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(float()) + L"," + 
				GetStdName(float());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(float(), L"Scale") + L"," + 
				GetMemberName(float(), L"Velocity");
		}
	};
	struct SStaminaInfo : public SProto
	{
		int64 LastUsedTick{};
		float Stamina{};
		SStaminaInfo()
		{
		}
		SStaminaInfo(const int64& LastUsedTick_, const float& Stamina_) : LastUsedTick(LastUsedTick_), Stamina(Stamina_)
		{
		}
		SStaminaInfo(int64&& LastUsedTick_, float&& Stamina_) : LastUsedTick(std::move(LastUsedTick_)), Stamina(std::move(Stamina_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> LastUsedTick;
			Stream_ >> Stamina;
		}
		void operator << (const Value& Value_) override
		{
			Value_["LastUsedTick"] >> LastUsedTick;
			Value_["Stamina"] >> Stamina;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << LastUsedTick;
			Stream_ << Stamina;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["LastUsedTick"] = LastUsedTick;
			Value_["Stamina"] = Stamina;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(int64()) + L"," + 
				GetStdName(float());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(int64(), L"LastUsedTick") + L"," + 
				GetMemberName(float(), L"Stamina");
		}
	};
	struct SBattlePlayer : public SProto
	{
		TUID UID{};
		u16string Nick{};
		wstring CountryCode{};
		TTeamCnt TeamIndex{};
		int32 CharCode{};
		SBattlePlayer()
		{
		}
		SBattlePlayer(const TUID& UID_, const u16string& Nick_, const wstring& CountryCode_, const TTeamCnt& TeamIndex_, const int32& CharCode_) : UID(UID_), Nick(Nick_), CountryCode(CountryCode_), TeamIndex(TeamIndex_), CharCode(CharCode_)
		{
		}
		SBattlePlayer(TUID&& UID_, u16string&& Nick_, wstring&& CountryCode_, TTeamCnt&& TeamIndex_, int32&& CharCode_) : UID(std::move(UID_)), Nick(std::move(Nick_)), CountryCode(std::move(CountryCode_)), TeamIndex(std::move(TeamIndex_)), CharCode(std::move(CharCode_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> UID;
			Stream_ >> Nick;
			Stream_ >> CountryCode;
			Stream_ >> TeamIndex;
			Stream_ >> CharCode;
		}
		void operator << (const Value& Value_) override
		{
			Value_["UID"] >> UID;
			Value_["Nick"] >> Nick;
			Value_["CountryCode"] >> CountryCode;
			Value_["TeamIndex"] >> TeamIndex;
			Value_["CharCode"] >> CharCode;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << UID;
			Stream_ << Nick;
			Stream_ << CountryCode;
			Stream_ << TeamIndex;
			Stream_ << CharCode;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["UID"] = UID;
			Value_["Nick"] = Nick;
			Value_["CountryCode"] = CountryCode;
			Value_["TeamIndex"] = TeamIndex;
			Value_["CharCode"] = CharCode;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(TUID()) + L"," + 
				GetStdName(u16string()) + L"," + 
				GetStdName(wstring()) + L"," + 
				GetStdName(TTeamCnt()) + L"," + 
				GetStdName(int32());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(TUID(), L"UID") + L"," + 
				GetMemberName(u16string(), L"Nick") + L"," + 
				GetMemberName(wstring(), L"CountryCode") + L"," + 
				GetMemberName(TTeamCnt(), L"TeamIndex") + L"," + 
				GetMemberName(int32(), L"CharCode");
		}
	};
	struct SCharacter : public SProto
	{
		bool IsGround{};
		int8 Dir{};
		int8 BalloonCount{};
		SPumpInfo PumpInfo{};
		SParachuteInfo ParachuteInfo{};
		SStaminaInfo StaminaInfo{};
		int8 Face{};
		int64 InvulnerableEndTick{};
		int32 ChainKillCount{};
		int64 LastKillTick{};
		int64 RegenTick{};
		SCharacter()
		{
		}
		SCharacter(const bool& IsGround_, const int8& Dir_, const int8& BalloonCount_, const SPumpInfo& PumpInfo_, const SParachuteInfo& ParachuteInfo_, const SStaminaInfo& StaminaInfo_, const int8& Face_, const int64& InvulnerableEndTick_, const int32& ChainKillCount_, const int64& LastKillTick_, const int64& RegenTick_) : IsGround(IsGround_), Dir(Dir_), BalloonCount(BalloonCount_), PumpInfo(PumpInfo_), ParachuteInfo(ParachuteInfo_), StaminaInfo(StaminaInfo_), Face(Face_), InvulnerableEndTick(InvulnerableEndTick_), ChainKillCount(ChainKillCount_), LastKillTick(LastKillTick_), RegenTick(RegenTick_)
		{
		}
		SCharacter(bool&& IsGround_, int8&& Dir_, int8&& BalloonCount_, SPumpInfo&& PumpInfo_, SParachuteInfo&& ParachuteInfo_, SStaminaInfo&& StaminaInfo_, int8&& Face_, int64&& InvulnerableEndTick_, int32&& ChainKillCount_, int64&& LastKillTick_, int64&& RegenTick_) : IsGround(std::move(IsGround_)), Dir(std::move(Dir_)), BalloonCount(std::move(BalloonCount_)), PumpInfo(std::move(PumpInfo_)), ParachuteInfo(std::move(ParachuteInfo_)), StaminaInfo(std::move(StaminaInfo_)), Face(std::move(Face_)), InvulnerableEndTick(std::move(InvulnerableEndTick_)), ChainKillCount(std::move(ChainKillCount_)), LastKillTick(std::move(LastKillTick_)), RegenTick(std::move(RegenTick_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> IsGround;
			Stream_ >> Dir;
			Stream_ >> BalloonCount;
			Stream_ >> PumpInfo;
			Stream_ >> ParachuteInfo;
			Stream_ >> StaminaInfo;
			Stream_ >> Face;
			Stream_ >> InvulnerableEndTick;
			Stream_ >> ChainKillCount;
			Stream_ >> LastKillTick;
			Stream_ >> RegenTick;
		}
		void operator << (const Value& Value_) override
		{
			Value_["IsGround"] >> IsGround;
			Value_["Dir"] >> Dir;
			Value_["BalloonCount"] >> BalloonCount;
			Value_["PumpInfo"] >> PumpInfo;
			Value_["ParachuteInfo"] >> ParachuteInfo;
			Value_["StaminaInfo"] >> StaminaInfo;
			Value_["Face"] >> Face;
			Value_["InvulnerableEndTick"] >> InvulnerableEndTick;
			Value_["ChainKillCount"] >> ChainKillCount;
			Value_["LastKillTick"] >> LastKillTick;
			Value_["RegenTick"] >> RegenTick;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << IsGround;
			Stream_ << Dir;
			Stream_ << BalloonCount;
			Stream_ << PumpInfo;
			Stream_ << ParachuteInfo;
			Stream_ << StaminaInfo;
			Stream_ << Face;
			Stream_ << InvulnerableEndTick;
			Stream_ << ChainKillCount;
			Stream_ << LastKillTick;
			Stream_ << RegenTick;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["IsGround"] = IsGround;
			Value_["Dir"] = Dir;
			Value_["BalloonCount"] = BalloonCount;
			Value_["PumpInfo"] = PumpInfo;
			Value_["ParachuteInfo"] = ParachuteInfo;
			Value_["StaminaInfo"] = StaminaInfo;
			Value_["Face"] = Face;
			Value_["InvulnerableEndTick"] = InvulnerableEndTick;
			Value_["ChainKillCount"] = ChainKillCount;
			Value_["LastKillTick"] = LastKillTick;
			Value_["RegenTick"] = RegenTick;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(bool()) + L"," + 
				GetStdName(int8()) + L"," + 
				GetStdName(int8()) + L"," + 
				GetStdName(SPumpInfo()) + L"," + 
				GetStdName(SParachuteInfo()) + L"," + 
				GetStdName(SStaminaInfo()) + L"," + 
				GetStdName(int8()) + L"," + 
				GetStdName(int64()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int64()) + L"," + 
				GetStdName(int64());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(bool(), L"IsGround") + L"," + 
				GetMemberName(int8(), L"Dir") + L"," + 
				GetMemberName(int8(), L"BalloonCount") + L"," + 
				GetMemberName(SPumpInfo(), L"PumpInfo") + L"," + 
				GetMemberName(SParachuteInfo(), L"ParachuteInfo") + L"," + 
				GetMemberName(SStaminaInfo(), L"StaminaInfo") + L"," + 
				GetMemberName(int8(), L"Face") + L"," + 
				GetMemberName(int64(), L"InvulnerableEndTick") + L"," + 
				GetMemberName(int32(), L"ChainKillCount") + L"," + 
				GetMemberName(int64(), L"LastKillTick") + L"," + 
				GetMemberName(int64(), L"RegenTick");
		}
	};
	struct SCharacterNet : public SCharacter
	{
		SPoint Pos{};
		SPoint Vel{};
		SCharacterNet()
		{
		}
		SCharacterNet(const SCharacter& Super_, const SPoint& Pos_, const SPoint& Vel_) : SCharacter(Super_), Pos(Pos_), Vel(Vel_)
		{
		}
		SCharacterNet(SCharacter&& Super_, SPoint&& Pos_, SPoint&& Vel_) : SCharacter(std::move(Super_)), Pos(std::move(Pos_)), Vel(std::move(Vel_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			SCharacter::operator << (Stream_);
			Stream_ >> Pos;
			Stream_ >> Vel;
		}
		void operator << (const Value& Value_) override
		{
			SCharacter::operator << (Value_);
			Value_["Pos"] >> Pos;
			Value_["Vel"] >> Vel;
		}
		void operator >> (CStream& Stream_) const override
		{
			SCharacter::operator >> (Stream_);
			Stream_ << Pos;
			Stream_ << Vel;
		}
		void operator >> (Value& Value_) const override
		{
			SCharacter::operator >> (Value_);
			Value_["Pos"] = Pos;
			Value_["Vel"] = Vel;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(SCharacter()) + L"," + 
				GetStdName(SPoint()) + L"," + 
				GetStdName(SPoint());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(SCharacter(), L"") + L"," + 
				GetMemberName(SPoint(), L"Pos") + L"," + 
				GetMemberName(SPoint(), L"Vel");
		}
	};
	struct SBattle : public SProto
	{
		SBattleType BattleType{};
		int32 MapIndex{};
		SBattle()
		{
		}
		SBattle(const SBattleType& BattleType_, const int32& MapIndex_) : BattleType(BattleType_), MapIndex(MapIndex_)
		{
		}
		SBattle(SBattleType&& BattleType_, int32&& MapIndex_) : BattleType(std::move(BattleType_)), MapIndex(std::move(MapIndex_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> BattleType;
			Stream_ >> MapIndex;
		}
		void operator << (const Value& Value_) override
		{
			Value_["BattleType"] >> BattleType;
			Value_["MapIndex"] >> MapIndex;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << BattleType;
			Stream_ << MapIndex;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["BattleType"] = BattleType;
			Value_["MapIndex"] = MapIndex;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(SBattleType()) + L"," + 
				GetStdName(int32());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(SBattleType(), L"BattleType") + L"," + 
				GetMemberName(int32(), L"MapIndex");
		}
	};
	struct SBattleRecord : public SProto
	{
		int32 TotalKillCount{};
		int32 TotalBalloonHitCount{};
		SBattleRecord()
		{
		}
		SBattleRecord(const int32& TotalKillCount_, const int32& TotalBalloonHitCount_) : TotalKillCount(TotalKillCount_), TotalBalloonHitCount(TotalBalloonHitCount_)
		{
		}
		SBattleRecord(int32&& TotalKillCount_, int32&& TotalBalloonHitCount_) : TotalKillCount(std::move(TotalKillCount_)), TotalBalloonHitCount(std::move(TotalBalloonHitCount_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> TotalKillCount;
			Stream_ >> TotalBalloonHitCount;
		}
		void operator << (const Value& Value_) override
		{
			Value_["TotalKillCount"] >> TotalKillCount;
			Value_["TotalBalloonHitCount"] >> TotalBalloonHitCount;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << TotalKillCount;
			Stream_ << TotalBalloonHitCount;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["TotalKillCount"] = TotalKillCount;
			Value_["TotalBalloonHitCount"] = TotalBalloonHitCount;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(int32()) + L"," + 
				GetStdName(int32());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(int32(), L"TotalKillCount") + L"," + 
				GetMemberName(int32(), L"TotalBalloonHitCount");
		}
	};
	struct BattleInfo : public SProto
	{
		int32 Point{};
		BattleInfo()
		{
		}
		BattleInfo(const int32& Point_) : Point(Point_)
		{
		}
		BattleInfo(int32&& Point_) : Point(std::move(Point_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Point;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Point"] >> Point;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Point;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Point"] = Point;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(int32());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(int32(), L"Point");
		}
	};
	struct SMultiBattleInfo : public BattleInfo
	{
		SMultiBattleInfo()
		{
		}
		SMultiBattleInfo(const BattleInfo& Super_) : BattleInfo(Super_)
		{
		}
		SMultiBattleInfo(BattleInfo&& Super_) : BattleInfo(std::move(Super_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			BattleInfo::operator << (Stream_);
		}
		void operator << (const Value& Value_) override
		{
			BattleInfo::operator << (Value_);
		}
		void operator >> (CStream& Stream_) const override
		{
			BattleInfo::operator >> (Stream_);
		}
		void operator >> (Value& Value_) const override
		{
			BattleInfo::operator >> (Value_);
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(BattleInfo());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(BattleInfo(), L"");
		}
	};
	struct SMultiBattleBeginNetSc : public SBattle
	{
		vector<SBattlePlayer> Players{};
		map<int32,system_clock::time_point> DisconnectEndTimes{};
		vector<SMultiBattleInfo> BattleInfos{};
		SBattleRecord Record{};
		vector<SCharacterNet> Characters{};
		int64 EndTick{};
		int64 Tick{};
		vector<SStructMovePosition> StructMovePositions{};
		SMultiBattleBeginNetSc()
		{
		}
		SMultiBattleBeginNetSc(const SBattle& Super_, const vector<SBattlePlayer>& Players_, const map<int32,system_clock::time_point>& DisconnectEndTimes_, const vector<SMultiBattleInfo>& BattleInfos_, const SBattleRecord& Record_, const vector<SCharacterNet>& Characters_, const int64& EndTick_, const int64& Tick_, const vector<SStructMovePosition>& StructMovePositions_) : SBattle(Super_), Players(Players_), DisconnectEndTimes(DisconnectEndTimes_), BattleInfos(BattleInfos_), Record(Record_), Characters(Characters_), EndTick(EndTick_), Tick(Tick_), StructMovePositions(StructMovePositions_)
		{
		}
		SMultiBattleBeginNetSc(SBattle&& Super_, vector<SBattlePlayer>&& Players_, map<int32,system_clock::time_point>&& DisconnectEndTimes_, vector<SMultiBattleInfo>&& BattleInfos_, SBattleRecord&& Record_, vector<SCharacterNet>&& Characters_, int64&& EndTick_, int64&& Tick_, vector<SStructMovePosition>&& StructMovePositions_) : SBattle(std::move(Super_)), Players(std::move(Players_)), DisconnectEndTimes(std::move(DisconnectEndTimes_)), BattleInfos(std::move(BattleInfos_)), Record(std::move(Record_)), Characters(std::move(Characters_)), EndTick(std::move(EndTick_)), Tick(std::move(Tick_)), StructMovePositions(std::move(StructMovePositions_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			SBattle::operator << (Stream_);
			Stream_ >> Players;
			Stream_ >> DisconnectEndTimes;
			Stream_ >> BattleInfos;
			Stream_ >> Record;
			Stream_ >> Characters;
			Stream_ >> EndTick;
			Stream_ >> Tick;
			Stream_ >> StructMovePositions;
		}
		void operator << (const Value& Value_) override
		{
			SBattle::operator << (Value_);
			Value_["Players"] >> Players;
			Value_["DisconnectEndTimes"] >> DisconnectEndTimes;
			Value_["BattleInfos"] >> BattleInfos;
			Value_["Record"] >> Record;
			Value_["Characters"] >> Characters;
			Value_["EndTick"] >> EndTick;
			Value_["Tick"] >> Tick;
			Value_["StructMovePositions"] >> StructMovePositions;
		}
		void operator >> (CStream& Stream_) const override
		{
			SBattle::operator >> (Stream_);
			Stream_ << Players;
			Stream_ << DisconnectEndTimes;
			Stream_ << BattleInfos;
			Stream_ << Record;
			Stream_ << Characters;
			Stream_ << EndTick;
			Stream_ << Tick;
			Stream_ << StructMovePositions;
		}
		void operator >> (Value& Value_) const override
		{
			SBattle::operator >> (Value_);
			Value_["Players"] = Players;
			Value_["DisconnectEndTimes"] = DisconnectEndTimes;
			Value_["BattleInfos"] = BattleInfos;
			Value_["Record"] = Record;
			Value_["Characters"] = Characters;
			Value_["EndTick"] = EndTick;
			Value_["Tick"] = Tick;
			Value_["StructMovePositions"] = StructMovePositions;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(SBattle()) + L"," + 
				GetStdName(vector<SBattlePlayer>()) + L"," + 
				GetStdName(map<int32,system_clock::time_point>()) + L"," + 
				GetStdName(vector<SMultiBattleInfo>()) + L"," + 
				GetStdName(SBattleRecord()) + L"," + 
				GetStdName(vector<SCharacterNet>()) + L"," + 
				GetStdName(int64()) + L"," + 
				GetStdName(int64()) + L"," + 
				GetStdName(vector<SStructMovePosition>());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(SBattle(), L"") + L"," + 
				GetMemberName(vector<SBattlePlayer>(), L"Players") + L"," + 
				GetMemberName(map<int32,system_clock::time_point>(), L"DisconnectEndTimes") + L"," + 
				GetMemberName(vector<SMultiBattleInfo>(), L"BattleInfos") + L"," + 
				GetMemberName(SBattleRecord(), L"Record") + L"," + 
				GetMemberName(vector<SCharacterNet>(), L"Characters") + L"," + 
				GetMemberName(int64(), L"EndTick") + L"," + 
				GetMemberName(int64(), L"Tick") + L"," + 
				GetMemberName(vector<SStructMovePosition>(), L"StructMovePositions");
		}
	};
	struct SMultiBattleStartNetSc : public SProto
	{
		int64 EndTick{};
		SMultiBattleStartNetSc()
		{
		}
		SMultiBattleStartNetSc(const int64& EndTick_) : EndTick(EndTick_)
		{
		}
		SMultiBattleStartNetSc(int64&& EndTick_) : EndTick(std::move(EndTick_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> EndTick;
		}
		void operator << (const Value& Value_) override
		{
			Value_["EndTick"] >> EndTick;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << EndTick;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["EndTick"] = EndTick;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(int64());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(int64(), L"EndTick");
		}
	};
	struct BattleEndInfo : public SProto
	{
		double addedEloPoint{};
		int32 battlePoint{};
		TResources addedResources{};
		BattleEndInfo()
		{
		}
		BattleEndInfo(const double& addedEloPoint_, const int32& battlePoint_, const TResources& addedResources_) : addedEloPoint(addedEloPoint_), battlePoint(battlePoint_), addedResources(addedResources_)
		{
		}
		BattleEndInfo(double&& addedEloPoint_, int32&& battlePoint_, TResources&& addedResources_) : addedEloPoint(std::move(addedEloPoint_)), battlePoint(std::move(battlePoint_)), addedResources(std::move(addedResources_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> addedEloPoint;
			Stream_ >> battlePoint;
			Stream_ >> addedResources;
		}
		void operator << (const Value& Value_) override
		{
			Value_["addedEloPoint"] >> addedEloPoint;
			Value_["battlePoint"] >> battlePoint;
			Value_["addedResources"] >> addedResources;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << addedEloPoint;
			Stream_ << battlePoint;
			Stream_ << addedResources;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["addedEloPoint"] = addedEloPoint;
			Value_["battlePoint"] = battlePoint;
			Value_["addedResources"] = addedResources;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(double()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(TResources());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(double(), L"addedEloPoint") + L"," + 
				GetMemberName(int32(), L"battlePoint") + L"," + 
				GetMemberName(TResources(), L"addedResources");
		}
	};
	struct STeamBattleInfo : public SProto
	{
		int32 Ranking{};
		int32 Point{};
		list<int32> playerIndices{};
		STeamBattleInfo()
		{
		}
		STeamBattleInfo(const int32& Ranking_, const int32& Point_, const list<int32>& playerIndices_) : Ranking(Ranking_), Point(Point_), playerIndices(playerIndices_)
		{
		}
		STeamBattleInfo(int32&& Ranking_, int32&& Point_, list<int32>&& playerIndices_) : Ranking(std::move(Ranking_)), Point(std::move(Point_)), playerIndices(std::move(playerIndices_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Ranking;
			Stream_ >> Point;
			Stream_ >> playerIndices;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Ranking"] >> Ranking;
			Value_["Point"] >> Point;
			Value_["playerIndices"] >> playerIndices;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Ranking;
			Stream_ << Point;
			Stream_ << playerIndices;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Ranking"] = Ranking;
			Value_["Point"] = Point;
			Value_["playerIndices"] = playerIndices;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(list<int32>());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(int32(), L"Ranking") + L"," + 
				GetMemberName(int32(), L"Point") + L"," + 
				GetMemberName(list<int32>(), L"playerIndices");
		}
	};
	struct SMultiBattleEndNet : public SProto
	{
		SInvalidDisconnectInfo InvalidDisconnectInfo{};
		SMultiBattleEndNet()
		{
		}
		SMultiBattleEndNet(const SInvalidDisconnectInfo& InvalidDisconnectInfo_) : InvalidDisconnectInfo(InvalidDisconnectInfo_)
		{
		}
		SMultiBattleEndNet(SInvalidDisconnectInfo&& InvalidDisconnectInfo_) : InvalidDisconnectInfo(std::move(InvalidDisconnectInfo_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> InvalidDisconnectInfo;
		}
		void operator << (const Value& Value_) override
		{
			Value_["InvalidDisconnectInfo"] >> InvalidDisconnectInfo;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << InvalidDisconnectInfo;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["InvalidDisconnectInfo"] = InvalidDisconnectInfo;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(SInvalidDisconnectInfo());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(SInvalidDisconnectInfo(), L"InvalidDisconnectInfo");
		}
	};
	struct SMultiBattleEndNetSc : public SMultiBattleEndNet
	{
		int32 myTeamRanking{};
		TResources ResourcesLeft{};
		double eloPoint{};
		int32 point{};
		int32 battlePoint{};
		TDoneQuests DoneQuests{};
		SMultiBattleEndNetSc()
		{
		}
		SMultiBattleEndNetSc(const SMultiBattleEndNet& Super_, const int32& myTeamRanking_, const TResources& ResourcesLeft_, const double& eloPoint_, const int32& point_, const int32& battlePoint_, const TDoneQuests& DoneQuests_) : SMultiBattleEndNet(Super_), myTeamRanking(myTeamRanking_), ResourcesLeft(ResourcesLeft_), eloPoint(eloPoint_), point(point_), battlePoint(battlePoint_), DoneQuests(DoneQuests_)
		{
		}
		SMultiBattleEndNetSc(SMultiBattleEndNet&& Super_, int32&& myTeamRanking_, TResources&& ResourcesLeft_, double&& eloPoint_, int32&& point_, int32&& battlePoint_, TDoneQuests&& DoneQuests_) : SMultiBattleEndNet(std::move(Super_)), myTeamRanking(std::move(myTeamRanking_)), ResourcesLeft(std::move(ResourcesLeft_)), eloPoint(std::move(eloPoint_)), point(std::move(point_)), battlePoint(std::move(battlePoint_)), DoneQuests(std::move(DoneQuests_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			SMultiBattleEndNet::operator << (Stream_);
			Stream_ >> myTeamRanking;
			Stream_ >> ResourcesLeft;
			Stream_ >> eloPoint;
			Stream_ >> point;
			Stream_ >> battlePoint;
			Stream_ >> DoneQuests;
		}
		void operator << (const Value& Value_) override
		{
			SMultiBattleEndNet::operator << (Value_);
			Value_["myTeamRanking"] >> myTeamRanking;
			Value_["ResourcesLeft"] >> ResourcesLeft;
			Value_["eloPoint"] >> eloPoint;
			Value_["point"] >> point;
			Value_["battlePoint"] >> battlePoint;
			Value_["DoneQuests"] >> DoneQuests;
		}
		void operator >> (CStream& Stream_) const override
		{
			SMultiBattleEndNet::operator >> (Stream_);
			Stream_ << myTeamRanking;
			Stream_ << ResourcesLeft;
			Stream_ << eloPoint;
			Stream_ << point;
			Stream_ << battlePoint;
			Stream_ << DoneQuests;
		}
		void operator >> (Value& Value_) const override
		{
			SMultiBattleEndNet::operator >> (Value_);
			Value_["myTeamRanking"] = myTeamRanking;
			Value_["ResourcesLeft"] = ResourcesLeft;
			Value_["eloPoint"] = eloPoint;
			Value_["point"] = point;
			Value_["battlePoint"] = battlePoint;
			Value_["DoneQuests"] = DoneQuests;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(SMultiBattleEndNet()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(TResources()) + L"," + 
				GetStdName(double()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(TDoneQuests());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(SMultiBattleEndNet(), L"") + L"," + 
				GetMemberName(int32(), L"myTeamRanking") + L"," + 
				GetMemberName(TResources(), L"ResourcesLeft") + L"," + 
				GetMemberName(double(), L"eloPoint") + L"," + 
				GetMemberName(int32(), L"point") + L"," + 
				GetMemberName(int32(), L"battlePoint") + L"," + 
				GetMemberName(TDoneQuests(), L"DoneQuests");
		}
	};
	struct SMultiBattleEndDrawNetSc : public SMultiBattleEndNet
	{
		TResources ResourcesLeft{};
		TDoneQuests DoneQuests{};
		SMultiBattleEndDrawNetSc()
		{
		}
		SMultiBattleEndDrawNetSc(const SMultiBattleEndNet& Super_, const TResources& ResourcesLeft_, const TDoneQuests& DoneQuests_) : SMultiBattleEndNet(Super_), ResourcesLeft(ResourcesLeft_), DoneQuests(DoneQuests_)
		{
		}
		SMultiBattleEndDrawNetSc(SMultiBattleEndNet&& Super_, TResources&& ResourcesLeft_, TDoneQuests&& DoneQuests_) : SMultiBattleEndNet(std::move(Super_)), ResourcesLeft(std::move(ResourcesLeft_)), DoneQuests(std::move(DoneQuests_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			SMultiBattleEndNet::operator << (Stream_);
			Stream_ >> ResourcesLeft;
			Stream_ >> DoneQuests;
		}
		void operator << (const Value& Value_) override
		{
			SMultiBattleEndNet::operator << (Value_);
			Value_["ResourcesLeft"] >> ResourcesLeft;
			Value_["DoneQuests"] >> DoneQuests;
		}
		void operator >> (CStream& Stream_) const override
		{
			SMultiBattleEndNet::operator >> (Stream_);
			Stream_ << ResourcesLeft;
			Stream_ << DoneQuests;
		}
		void operator >> (Value& Value_) const override
		{
			SMultiBattleEndNet::operator >> (Value_);
			Value_["ResourcesLeft"] = ResourcesLeft;
			Value_["DoneQuests"] = DoneQuests;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(SMultiBattleEndNet()) + L"," + 
				GetStdName(TResources()) + L"," + 
				GetStdName(TDoneQuests());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(SMultiBattleEndNet(), L"") + L"," + 
				GetMemberName(TResources(), L"ResourcesLeft") + L"," + 
				GetMemberName(TDoneQuests(), L"DoneQuests");
		}
	};
	struct SMultiBattleEndInvalidNetSc : public SMultiBattleEndNet
	{
		SMultiBattleEndInvalidNetSc()
		{
		}
		SMultiBattleEndInvalidNetSc(const SMultiBattleEndNet& Super_) : SMultiBattleEndNet(Super_)
		{
		}
		SMultiBattleEndInvalidNetSc(SMultiBattleEndNet&& Super_) : SMultiBattleEndNet(std::move(Super_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			SMultiBattleEndNet::operator << (Stream_);
		}
		void operator << (const Value& Value_) override
		{
			SMultiBattleEndNet::operator << (Value_);
		}
		void operator >> (CStream& Stream_) const override
		{
			SMultiBattleEndNet::operator >> (Stream_);
		}
		void operator >> (Value& Value_) const override
		{
			SMultiBattleEndNet::operator >> (Value_);
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(SMultiBattleEndNet());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(SMultiBattleEndNet(), L"");
		}
	};
	struct SMultiBattleIconNetCs : public SProto
	{
		int32 Code{};
		SMultiBattleIconNetCs()
		{
		}
		SMultiBattleIconNetCs(const int32& Code_) : Code(Code_)
		{
		}
		SMultiBattleIconNetCs(int32&& Code_) : Code(std::move(Code_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Code;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Code"] >> Code;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Code;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Code"] = Code;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(int32());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(int32(), L"Code");
		}
	};
	struct SMultiBattleIconNetSc : public SProto
	{
		int32 PlayerIndex{};
		int32 Code{};
		SMultiBattleIconNetSc()
		{
		}
		SMultiBattleIconNetSc(const int32& PlayerIndex_, const int32& Code_) : PlayerIndex(PlayerIndex_), Code(Code_)
		{
		}
		SMultiBattleIconNetSc(int32&& PlayerIndex_, int32&& Code_) : PlayerIndex(std::move(PlayerIndex_)), Code(std::move(Code_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> PlayerIndex;
			Stream_ >> Code;
		}
		void operator << (const Value& Value_) override
		{
			Value_["PlayerIndex"] >> PlayerIndex;
			Value_["Code"] >> Code;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << PlayerIndex;
			Stream_ << Code;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["PlayerIndex"] = PlayerIndex;
			Value_["Code"] = Code;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(int32()) + L"," + 
				GetStdName(int32());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(int32(), L"PlayerIndex") + L"," + 
				GetMemberName(int32(), L"Code");
		}
	};
	struct SMultiBattleLinkNetSc : public SProto
	{
		int64 Tick{};
		int32 PlayerIndex{};
		SMultiBattleLinkNetSc()
		{
		}
		SMultiBattleLinkNetSc(const int64& Tick_, const int32& PlayerIndex_) : Tick(Tick_), PlayerIndex(PlayerIndex_)
		{
		}
		SMultiBattleLinkNetSc(int64&& Tick_, int32&& PlayerIndex_) : Tick(std::move(Tick_)), PlayerIndex(std::move(PlayerIndex_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Tick;
			Stream_ >> PlayerIndex;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Tick"] >> Tick;
			Value_["PlayerIndex"] >> PlayerIndex;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Tick;
			Stream_ << PlayerIndex;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Tick"] = Tick;
			Value_["PlayerIndex"] = PlayerIndex;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(int64()) + L"," + 
				GetStdName(int32());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(int64(), L"Tick") + L"," + 
				GetMemberName(int32(), L"PlayerIndex");
		}
	};
	struct SMultiBattleUnLinkNetSc : public SProto
	{
		int64 Tick{};
		int32 PlayerIndex{};
		system_clock::time_point DisconnectEndTime{};
		SMultiBattleUnLinkNetSc()
		{
		}
		SMultiBattleUnLinkNetSc(const int64& Tick_, const int32& PlayerIndex_, const system_clock::time_point& DisconnectEndTime_) : Tick(Tick_), PlayerIndex(PlayerIndex_), DisconnectEndTime(DisconnectEndTime_)
		{
		}
		SMultiBattleUnLinkNetSc(int64&& Tick_, int32&& PlayerIndex_, system_clock::time_point&& DisconnectEndTime_) : Tick(std::move(Tick_)), PlayerIndex(std::move(PlayerIndex_)), DisconnectEndTime(std::move(DisconnectEndTime_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Tick;
			Stream_ >> PlayerIndex;
			Stream_ >> DisconnectEndTime;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Tick"] >> Tick;
			Value_["PlayerIndex"] >> PlayerIndex;
			Value_["DisconnectEndTime"] >> DisconnectEndTime;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Tick;
			Stream_ << PlayerIndex;
			Stream_ << DisconnectEndTime;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Tick"] = Tick;
			Value_["PlayerIndex"] = PlayerIndex;
			Value_["DisconnectEndTime"] = DisconnectEndTime;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(int64()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(system_clock::time_point());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(int64(), L"Tick") + L"," + 
				GetMemberName(int32(), L"PlayerIndex") + L"," + 
				GetMemberName(system_clock::time_point(), L"DisconnectEndTime");
		}
	};
	struct SInvalidDisconnectInfoNetSc : public SInvalidDisconnectInfo
	{
		SInvalidDisconnectInfoNetSc()
		{
		}
		SInvalidDisconnectInfoNetSc(const SInvalidDisconnectInfo& Super_) : SInvalidDisconnectInfo(Super_)
		{
		}
		SInvalidDisconnectInfoNetSc(SInvalidDisconnectInfo&& Super_) : SInvalidDisconnectInfo(std::move(Super_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			SInvalidDisconnectInfo::operator << (Stream_);
		}
		void operator << (const Value& Value_) override
		{
			SInvalidDisconnectInfo::operator << (Value_);
		}
		void operator >> (CStream& Stream_) const override
		{
			SInvalidDisconnectInfo::operator >> (Stream_);
		}
		void operator >> (Value& Value_) const override
		{
			SInvalidDisconnectInfo::operator >> (Value_);
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(SInvalidDisconnectInfo());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(SInvalidDisconnectInfo(), L"");
		}
	};
	struct SingleBattleStartNetSc : public SProto
	{
		void operator << (CStream&) override
		{
		}
		void operator << (const Value&) override
		{
		}
		void operator >> (CStream&) const override
		{
		}
		void operator >> (Value&) const override
		{
		}
		static wstring StdName(void)
		{
			return L"";
		}
		static wstring MemberName(void)
		{
			return L"";
		}
	};
	struct SingleBattleEndNetSc : public SProto
	{
		int64 Tick{};
		TResources ResourcesLeft{};
		TDoneQuests DoneQuests{};
		SingleBattleEndNetSc()
		{
		}
		SingleBattleEndNetSc(const int64& Tick_, const TResources& ResourcesLeft_, const TDoneQuests& DoneQuests_) : Tick(Tick_), ResourcesLeft(ResourcesLeft_), DoneQuests(DoneQuests_)
		{
		}
		SingleBattleEndNetSc(int64&& Tick_, TResources&& ResourcesLeft_, TDoneQuests&& DoneQuests_) : Tick(std::move(Tick_)), ResourcesLeft(std::move(ResourcesLeft_)), DoneQuests(std::move(DoneQuests_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Tick;
			Stream_ >> ResourcesLeft;
			Stream_ >> DoneQuests;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Tick"] >> Tick;
			Value_["ResourcesLeft"] >> ResourcesLeft;
			Value_["DoneQuests"] >> DoneQuests;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Tick;
			Stream_ << ResourcesLeft;
			Stream_ << DoneQuests;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Tick"] = Tick;
			Value_["ResourcesLeft"] = ResourcesLeft;
			Value_["DoneQuests"] = DoneQuests;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(int64()) + L"," + 
				GetStdName(TResources()) + L"," + 
				GetStdName(TDoneQuests());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(int64(), L"Tick") + L"," + 
				GetMemberName(TResources(), L"ResourcesLeft") + L"," + 
				GetMemberName(TDoneQuests(), L"DoneQuests");
		}
	};
	struct SArrowDodgeBattleJoinNetCs : public SProto
	{
		void operator << (CStream&) override
		{
		}
		void operator << (const Value&) override
		{
		}
		void operator >> (CStream&) const override
		{
		}
		void operator >> (Value&) const override
		{
		}
		static wstring StdName(void)
		{
			return L"";
		}
		static wstring MemberName(void)
		{
			return L"";
		}
	};
	struct SArrowDodgeBattleJoinNetSc : public SProto
	{
		TResource GoldCost{};
		int32 PlayCount{};
		system_clock::time_point RefreshTime{};
		TDoneQuests DoneQuests{};
		SArrowDodgeBattleJoinNetSc()
		{
		}
		SArrowDodgeBattleJoinNetSc(const TResource& GoldCost_, const int32& PlayCount_, const system_clock::time_point& RefreshTime_, const TDoneQuests& DoneQuests_) : GoldCost(GoldCost_), PlayCount(PlayCount_), RefreshTime(RefreshTime_), DoneQuests(DoneQuests_)
		{
		}
		SArrowDodgeBattleJoinNetSc(TResource&& GoldCost_, int32&& PlayCount_, system_clock::time_point&& RefreshTime_, TDoneQuests&& DoneQuests_) : GoldCost(std::move(GoldCost_)), PlayCount(std::move(PlayCount_)), RefreshTime(std::move(RefreshTime_)), DoneQuests(std::move(DoneQuests_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> GoldCost;
			Stream_ >> PlayCount;
			Stream_ >> RefreshTime;
			Stream_ >> DoneQuests;
		}
		void operator << (const Value& Value_) override
		{
			Value_["GoldCost"] >> GoldCost;
			Value_["PlayCount"] >> PlayCount;
			Value_["RefreshTime"] >> RefreshTime;
			Value_["DoneQuests"] >> DoneQuests;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << GoldCost;
			Stream_ << PlayCount;
			Stream_ << RefreshTime;
			Stream_ << DoneQuests;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["GoldCost"] = GoldCost;
			Value_["PlayCount"] = PlayCount;
			Value_["RefreshTime"] = RefreshTime;
			Value_["DoneQuests"] = DoneQuests;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(TResource()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(system_clock::time_point()) + L"," + 
				GetStdName(TDoneQuests());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(TResource(), L"GoldCost") + L"," + 
				GetMemberName(int32(), L"PlayCount") + L"," + 
				GetMemberName(system_clock::time_point(), L"RefreshTime") + L"," + 
				GetMemberName(TDoneQuests(), L"DoneQuests");
		}
	};
	struct SArrow : public SProto
	{
		SPoint LocalPosition{};
		SPoint Velocity{};
		SArrow()
		{
		}
		SArrow(const SPoint& LocalPosition_, const SPoint& Velocity_) : LocalPosition(LocalPosition_), Velocity(Velocity_)
		{
		}
		SArrow(SPoint&& LocalPosition_, SPoint&& Velocity_) : LocalPosition(std::move(LocalPosition_)), Velocity(std::move(Velocity_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> LocalPosition;
			Stream_ >> Velocity;
		}
		void operator << (const Value& Value_) override
		{
			Value_["LocalPosition"] >> LocalPosition;
			Value_["Velocity"] >> Velocity;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << LocalPosition;
			Stream_ << Velocity;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["LocalPosition"] = LocalPosition;
			Value_["Velocity"] = Velocity;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(SPoint()) + L"," + 
				GetStdName(SPoint());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(SPoint(), L"LocalPosition") + L"," + 
				GetMemberName(SPoint(), L"Velocity");
		}
	};
	enum class EArrowDodgeItemType
	{
		Coin,
		GoldBar,
		Shield,
		Stamina,
		Max,
		Null,
	};
	struct SArrowDodgeItem : public SProto
	{
		SPoint LocalPosition{};
		EArrowDodgeItemType ItemType{};
		SArrowDodgeItem()
		{
		}
		SArrowDodgeItem(const SPoint& LocalPosition_, const EArrowDodgeItemType& ItemType_) : LocalPosition(LocalPosition_), ItemType(ItemType_)
		{
		}
		SArrowDodgeItem(SPoint&& LocalPosition_, EArrowDodgeItemType&& ItemType_) : LocalPosition(std::move(LocalPosition_)), ItemType(std::move(ItemType_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> LocalPosition;
			Stream_ >> ItemType;
		}
		void operator << (const Value& Value_) override
		{
			Value_["LocalPosition"] >> LocalPosition;
			Value_["ItemType"] >> ItemType;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << LocalPosition;
			Stream_ << ItemType;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["LocalPosition"] = LocalPosition;
			Value_["ItemType"] = ItemType;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(SPoint()) + L"," + 
				GetStdName(EArrowDodgeItemType());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(SPoint(), L"LocalPosition") + L"," + 
				GetMemberName(EArrowDodgeItemType(), L"ItemType");
		}
	};
	struct SingleBattleInfo : public BattleInfo
	{
		TResource Gold{};
		SingleBattleInfo()
		{
		}
		SingleBattleInfo(const BattleInfo& Super_, const TResource& Gold_) : BattleInfo(Super_), Gold(Gold_)
		{
		}
		SingleBattleInfo(BattleInfo&& Super_, TResource&& Gold_) : BattleInfo(std::move(Super_)), Gold(std::move(Gold_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			BattleInfo::operator << (Stream_);
			Stream_ >> Gold;
		}
		void operator << (const Value& Value_) override
		{
			BattleInfo::operator << (Value_);
			Value_["Gold"] >> Gold;
		}
		void operator >> (CStream& Stream_) const override
		{
			BattleInfo::operator >> (Stream_);
			Stream_ << Gold;
		}
		void operator >> (Value& Value_) const override
		{
			BattleInfo::operator >> (Value_);
			Value_["Gold"] = Gold;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(BattleInfo()) + L"," + 
				GetStdName(TResource());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(BattleInfo(), L"") + L"," + 
				GetMemberName(TResource(), L"Gold");
		}
	};
	struct SArrowDodgeBattleInfo : public SingleBattleInfo
	{
		SArrowDodgeBattleInfo()
		{
		}
		SArrowDodgeBattleInfo(const SingleBattleInfo& Super_) : SingleBattleInfo(Super_)
		{
		}
		SArrowDodgeBattleInfo(SingleBattleInfo&& Super_) : SingleBattleInfo(std::move(Super_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			SingleBattleInfo::operator << (Stream_);
		}
		void operator << (const Value& Value_) override
		{
			SingleBattleInfo::operator << (Value_);
		}
		void operator >> (CStream& Stream_) const override
		{
			SingleBattleInfo::operator >> (Stream_);
		}
		void operator >> (Value& Value_) const override
		{
			SingleBattleInfo::operator >> (Value_);
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(SingleBattleInfo());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(SingleBattleInfo(), L"");
		}
	};
	struct SArrowDodgeBattleBuf : public SProto
	{
		bool Enabled{};
		int64 EndTick{};
		SArrowDodgeBattleBuf()
		{
		}
		SArrowDodgeBattleBuf(const bool& Enabled_, const int64& EndTick_) : Enabled(Enabled_), EndTick(EndTick_)
		{
		}
		SArrowDodgeBattleBuf(bool&& Enabled_, int64&& EndTick_) : Enabled(std::move(Enabled_)), EndTick(std::move(EndTick_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Enabled;
			Stream_ >> EndTick;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Enabled"] >> Enabled;
			Value_["EndTick"] >> EndTick;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Enabled;
			Stream_ << EndTick;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Enabled"] = Enabled;
			Value_["EndTick"] = EndTick;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(bool()) + L"," + 
				GetStdName(int64());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(bool(), L"Enabled") + L"," + 
				GetMemberName(int64(), L"EndTick");
		}
	};
	struct SArrowDodgeBattleBufs : public SProto
	{
		SArrowDodgeBattleBuf Shield{};
		SArrowDodgeBattleBuf Stamina{};
		SArrowDodgeBattleBufs()
		{
		}
		SArrowDodgeBattleBufs(const SArrowDodgeBattleBuf& Shield_, const SArrowDodgeBattleBuf& Stamina_) : Shield(Shield_), Stamina(Stamina_)
		{
		}
		SArrowDodgeBattleBufs(SArrowDodgeBattleBuf&& Shield_, SArrowDodgeBattleBuf&& Stamina_) : Shield(std::move(Shield_)), Stamina(std::move(Stamina_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Shield;
			Stream_ >> Stamina;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Shield"] >> Shield;
			Value_["Stamina"] >> Stamina;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Shield;
			Stream_ << Stamina;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Shield"] = Shield;
			Value_["Stamina"] = Stamina;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(SArrowDodgeBattleBuf()) + L"," + 
				GetStdName(SArrowDodgeBattleBuf());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(SArrowDodgeBattleBuf(), L"Shield") + L"," + 
				GetMemberName(SArrowDodgeBattleBuf(), L"Stamina");
		}
	};
	struct SingleBattleBeginNetSc : public SProto
	{
		SBattlePlayer Player{};
		SCharacterNet Character{};
		int64 Tick{};
		uint32 RandomSeed{};
		bool Started{};
		SingleBattleBeginNetSc()
		{
		}
		SingleBattleBeginNetSc(const SBattlePlayer& Player_, const SCharacterNet& Character_, const int64& Tick_, const uint32& RandomSeed_, const bool& Started_) : Player(Player_), Character(Character_), Tick(Tick_), RandomSeed(RandomSeed_), Started(Started_)
		{
		}
		SingleBattleBeginNetSc(SBattlePlayer&& Player_, SCharacterNet&& Character_, int64&& Tick_, uint32&& RandomSeed_, bool&& Started_) : Player(std::move(Player_)), Character(std::move(Character_)), Tick(std::move(Tick_)), RandomSeed(std::move(RandomSeed_)), Started(std::move(Started_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Player;
			Stream_ >> Character;
			Stream_ >> Tick;
			Stream_ >> RandomSeed;
			Stream_ >> Started;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Player"] >> Player;
			Value_["Character"] >> Character;
			Value_["Tick"] >> Tick;
			Value_["RandomSeed"] >> RandomSeed;
			Value_["Started"] >> Started;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Player;
			Stream_ << Character;
			Stream_ << Tick;
			Stream_ << RandomSeed;
			Stream_ << Started;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Player"] = Player;
			Value_["Character"] = Character;
			Value_["Tick"] = Tick;
			Value_["RandomSeed"] = RandomSeed;
			Value_["Started"] = Started;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(SBattlePlayer()) + L"," + 
				GetStdName(SCharacterNet()) + L"," + 
				GetStdName(int64()) + L"," + 
				GetStdName(uint32()) + L"," + 
				GetStdName(bool());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(SBattlePlayer(), L"Player") + L"," + 
				GetMemberName(SCharacterNet(), L"Character") + L"," + 
				GetMemberName(int64(), L"Tick") + L"," + 
				GetMemberName(uint32(), L"RandomSeed") + L"," + 
				GetMemberName(bool(), L"Started");
		}
	};
	struct SArrowDodgeBattleBeginNetSc : public SingleBattleBeginNetSc
	{
		SArrowDodgeBattleInfo BattleInfo{};
		SArrowDodgeBattleBufs Bufs{};
		int64 NextDownArrowTick{};
		int64 NextLeftArrowTick{};
		int64 NextRightArrowTick{};
		int64 NextItemTick{};
		vector<SArrow> Arrows{};
		vector<SArrowDodgeItem> Items{};
		SArrowDodgeBattleBeginNetSc()
		{
		}
		SArrowDodgeBattleBeginNetSc(const SingleBattleBeginNetSc& Super_, const SArrowDodgeBattleInfo& BattleInfo_, const SArrowDodgeBattleBufs& Bufs_, const int64& NextDownArrowTick_, const int64& NextLeftArrowTick_, const int64& NextRightArrowTick_, const int64& NextItemTick_, const vector<SArrow>& Arrows_, const vector<SArrowDodgeItem>& Items_) : SingleBattleBeginNetSc(Super_), BattleInfo(BattleInfo_), Bufs(Bufs_), NextDownArrowTick(NextDownArrowTick_), NextLeftArrowTick(NextLeftArrowTick_), NextRightArrowTick(NextRightArrowTick_), NextItemTick(NextItemTick_), Arrows(Arrows_), Items(Items_)
		{
		}
		SArrowDodgeBattleBeginNetSc(SingleBattleBeginNetSc&& Super_, SArrowDodgeBattleInfo&& BattleInfo_, SArrowDodgeBattleBufs&& Bufs_, int64&& NextDownArrowTick_, int64&& NextLeftArrowTick_, int64&& NextRightArrowTick_, int64&& NextItemTick_, vector<SArrow>&& Arrows_, vector<SArrowDodgeItem>&& Items_) : SingleBattleBeginNetSc(std::move(Super_)), BattleInfo(std::move(BattleInfo_)), Bufs(std::move(Bufs_)), NextDownArrowTick(std::move(NextDownArrowTick_)), NextLeftArrowTick(std::move(NextLeftArrowTick_)), NextRightArrowTick(std::move(NextRightArrowTick_)), NextItemTick(std::move(NextItemTick_)), Arrows(std::move(Arrows_)), Items(std::move(Items_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			SingleBattleBeginNetSc::operator << (Stream_);
			Stream_ >> BattleInfo;
			Stream_ >> Bufs;
			Stream_ >> NextDownArrowTick;
			Stream_ >> NextLeftArrowTick;
			Stream_ >> NextRightArrowTick;
			Stream_ >> NextItemTick;
			Stream_ >> Arrows;
			Stream_ >> Items;
		}
		void operator << (const Value& Value_) override
		{
			SingleBattleBeginNetSc::operator << (Value_);
			Value_["BattleInfo"] >> BattleInfo;
			Value_["Bufs"] >> Bufs;
			Value_["NextDownArrowTick"] >> NextDownArrowTick;
			Value_["NextLeftArrowTick"] >> NextLeftArrowTick;
			Value_["NextRightArrowTick"] >> NextRightArrowTick;
			Value_["NextItemTick"] >> NextItemTick;
			Value_["Arrows"] >> Arrows;
			Value_["Items"] >> Items;
		}
		void operator >> (CStream& Stream_) const override
		{
			SingleBattleBeginNetSc::operator >> (Stream_);
			Stream_ << BattleInfo;
			Stream_ << Bufs;
			Stream_ << NextDownArrowTick;
			Stream_ << NextLeftArrowTick;
			Stream_ << NextRightArrowTick;
			Stream_ << NextItemTick;
			Stream_ << Arrows;
			Stream_ << Items;
		}
		void operator >> (Value& Value_) const override
		{
			SingleBattleBeginNetSc::operator >> (Value_);
			Value_["BattleInfo"] = BattleInfo;
			Value_["Bufs"] = Bufs;
			Value_["NextDownArrowTick"] = NextDownArrowTick;
			Value_["NextLeftArrowTick"] = NextLeftArrowTick;
			Value_["NextRightArrowTick"] = NextRightArrowTick;
			Value_["NextItemTick"] = NextItemTick;
			Value_["Arrows"] = Arrows;
			Value_["Items"] = Items;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(SingleBattleBeginNetSc()) + L"," + 
				GetStdName(SArrowDodgeBattleInfo()) + L"," + 
				GetStdName(SArrowDodgeBattleBufs()) + L"," + 
				GetStdName(int64()) + L"," + 
				GetStdName(int64()) + L"," + 
				GetStdName(int64()) + L"," + 
				GetStdName(int64()) + L"," + 
				GetStdName(vector<SArrow>()) + L"," + 
				GetStdName(vector<SArrowDodgeItem>());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(SingleBattleBeginNetSc(), L"") + L"," + 
				GetMemberName(SArrowDodgeBattleInfo(), L"BattleInfo") + L"," + 
				GetMemberName(SArrowDodgeBattleBufs(), L"Bufs") + L"," + 
				GetMemberName(int64(), L"NextDownArrowTick") + L"," + 
				GetMemberName(int64(), L"NextLeftArrowTick") + L"," + 
				GetMemberName(int64(), L"NextRightArrowTick") + L"," + 
				GetMemberName(int64(), L"NextItemTick") + L"," + 
				GetMemberName(vector<SArrow>(), L"Arrows") + L"," + 
				GetMemberName(vector<SArrowDodgeItem>(), L"Items");
		}
	};
	struct SArrowDodgeBattleStartNetSc : public SingleBattleStartNetSc
	{
		void operator << (CStream&) override
		{
		}
		void operator << (const Value&) override
		{
		}
		void operator >> (CStream&) const override
		{
		}
		void operator >> (Value&) const override
		{
		}
		static wstring StdName(void)
		{
			return L"";
		}
		static wstring MemberName(void)
		{
			return L"";
		}
	};
	struct SArrowDodgeBattleEndNetCs : public SProto
	{
		void operator << (CStream&) override
		{
		}
		void operator << (const Value&) override
		{
		}
		void operator >> (CStream&) const override
		{
		}
		void operator >> (Value&) const override
		{
		}
		static wstring StdName(void)
		{
			return L"";
		}
		static wstring MemberName(void)
		{
			return L"";
		}
	};
	struct SArrowDodgeBattleEndNetSc : public SingleBattleEndNetSc
	{
		SArrowDodgeBattleEndNetSc()
		{
		}
		SArrowDodgeBattleEndNetSc(const SingleBattleEndNetSc& Super_) : SingleBattleEndNetSc(Super_)
		{
		}
		SArrowDodgeBattleEndNetSc(SingleBattleEndNetSc&& Super_) : SingleBattleEndNetSc(std::move(Super_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			SingleBattleEndNetSc::operator << (Stream_);
		}
		void operator << (const Value& Value_) override
		{
			SingleBattleEndNetSc::operator << (Value_);
		}
		void operator >> (CStream& Stream_) const override
		{
			SingleBattleEndNetSc::operator >> (Stream_);
		}
		void operator >> (Value& Value_) const override
		{
			SingleBattleEndNetSc::operator >> (Value_);
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(SingleBattleEndNetSc());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(SingleBattleEndNetSc(), L"");
		}
	};
	struct FlyAwayPathMakerState : public SProto
	{
		int32 currentLevel{};
		int32 levelDirection{};
		int32 destMainLevel{};
		int32 currentCount{};
		int32 destCount{};
		FlyAwayPathMakerState()
		{
		}
		FlyAwayPathMakerState(const int32& currentLevel_, const int32& levelDirection_, const int32& destMainLevel_, const int32& currentCount_, const int32& destCount_) : currentLevel(currentLevel_), levelDirection(levelDirection_), destMainLevel(destMainLevel_), currentCount(currentCount_), destCount(destCount_)
		{
		}
		FlyAwayPathMakerState(int32&& currentLevel_, int32&& levelDirection_, int32&& destMainLevel_, int32&& currentCount_, int32&& destCount_) : currentLevel(std::move(currentLevel_)), levelDirection(std::move(levelDirection_)), destMainLevel(std::move(destMainLevel_)), currentCount(std::move(currentCount_)), destCount(std::move(destCount_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> currentLevel;
			Stream_ >> levelDirection;
			Stream_ >> destMainLevel;
			Stream_ >> currentCount;
			Stream_ >> destCount;
		}
		void operator << (const Value& Value_) override
		{
			Value_["currentLevel"] >> currentLevel;
			Value_["levelDirection"] >> levelDirection;
			Value_["destMainLevel"] >> destMainLevel;
			Value_["currentCount"] >> currentCount;
			Value_["destCount"] >> destCount;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << currentLevel;
			Stream_ << levelDirection;
			Stream_ << destMainLevel;
			Stream_ << currentCount;
			Stream_ << destCount;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["currentLevel"] = currentLevel;
			Value_["levelDirection"] = levelDirection;
			Value_["destMainLevel"] = destMainLevel;
			Value_["currentCount"] = currentCount;
			Value_["destCount"] = destCount;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(int32(), L"currentLevel") + L"," + 
				GetMemberName(int32(), L"levelDirection") + L"," + 
				GetMemberName(int32(), L"destMainLevel") + L"," + 
				GetMemberName(int32(), L"currentCount") + L"," + 
				GetMemberName(int32(), L"destCount");
		}
	};
	struct SFlyAwayBattleJoinNetCs : public SProto
	{
		void operator << (CStream&) override
		{
		}
		void operator << (const Value&) override
		{
		}
		void operator >> (CStream&) const override
		{
		}
		void operator >> (Value&) const override
		{
		}
		static wstring StdName(void)
		{
			return L"";
		}
		static wstring MemberName(void)
		{
			return L"";
		}
	};
	struct SFlyAwayBattleJoinNetSc : public SProto
	{
		TResource GoldCost{};
		int32 PlayCount{};
		system_clock::time_point RefreshTime{};
		TDoneQuests DoneQuests{};
		SFlyAwayBattleJoinNetSc()
		{
		}
		SFlyAwayBattleJoinNetSc(const TResource& GoldCost_, const int32& PlayCount_, const system_clock::time_point& RefreshTime_, const TDoneQuests& DoneQuests_) : GoldCost(GoldCost_), PlayCount(PlayCount_), RefreshTime(RefreshTime_), DoneQuests(DoneQuests_)
		{
		}
		SFlyAwayBattleJoinNetSc(TResource&& GoldCost_, int32&& PlayCount_, system_clock::time_point&& RefreshTime_, TDoneQuests&& DoneQuests_) : GoldCost(std::move(GoldCost_)), PlayCount(std::move(PlayCount_)), RefreshTime(std::move(RefreshTime_)), DoneQuests(std::move(DoneQuests_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> GoldCost;
			Stream_ >> PlayCount;
			Stream_ >> RefreshTime;
			Stream_ >> DoneQuests;
		}
		void operator << (const Value& Value_) override
		{
			Value_["GoldCost"] >> GoldCost;
			Value_["PlayCount"] >> PlayCount;
			Value_["RefreshTime"] >> RefreshTime;
			Value_["DoneQuests"] >> DoneQuests;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << GoldCost;
			Stream_ << PlayCount;
			Stream_ << RefreshTime;
			Stream_ << DoneQuests;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["GoldCost"] = GoldCost;
			Value_["PlayCount"] = PlayCount;
			Value_["RefreshTime"] = RefreshTime;
			Value_["DoneQuests"] = DoneQuests;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(TResource()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(system_clock::time_point()) + L"," + 
				GetStdName(TDoneQuests());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(TResource(), L"GoldCost") + L"," + 
				GetMemberName(int32(), L"PlayCount") + L"," + 
				GetMemberName(system_clock::time_point(), L"RefreshTime") + L"," + 
				GetMemberName(TDoneQuests(), L"DoneQuests");
		}
	};
	enum class EFlyAwayLandState
	{
		Normal,
		Shaking,
		Falling,
	};
	struct SFlyAwayLand : public SProto
	{
		SPoint LocalPosition{};
		int32 Number{};
		int32 Index{};
		EFlyAwayLandState State{};
		int64 NextActionTick{};
		SFlyAwayLand()
		{
		}
		SFlyAwayLand(const SPoint& LocalPosition_, const int32& Number_, const int32& Index_, const EFlyAwayLandState& State_, const int64& NextActionTick_) : LocalPosition(LocalPosition_), Number(Number_), Index(Index_), State(State_), NextActionTick(NextActionTick_)
		{
		}
		SFlyAwayLand(SPoint&& LocalPosition_, int32&& Number_, int32&& Index_, EFlyAwayLandState&& State_, int64&& NextActionTick_) : LocalPosition(std::move(LocalPosition_)), Number(std::move(Number_)), Index(std::move(Index_)), State(std::move(State_)), NextActionTick(std::move(NextActionTick_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> LocalPosition;
			Stream_ >> Number;
			Stream_ >> Index;
			Stream_ >> State;
			Stream_ >> NextActionTick;
		}
		void operator << (const Value& Value_) override
		{
			Value_["LocalPosition"] >> LocalPosition;
			Value_["Number"] >> Number;
			Value_["Index"] >> Index;
			Value_["State"] >> State;
			Value_["NextActionTick"] >> NextActionTick;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << LocalPosition;
			Stream_ << Number;
			Stream_ << Index;
			Stream_ << State;
			Stream_ << NextActionTick;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["LocalPosition"] = LocalPosition;
			Value_["Number"] = Number;
			Value_["Index"] = Index;
			Value_["State"] = State;
			Value_["NextActionTick"] = NextActionTick;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(SPoint()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(EFlyAwayLandState()) + L"," + 
				GetStdName(int64());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(SPoint(), L"LocalPosition") + L"," + 
				GetMemberName(int32(), L"Number") + L"," + 
				GetMemberName(int32(), L"Index") + L"," + 
				GetMemberName(EFlyAwayLandState(), L"State") + L"," + 
				GetMemberName(int64(), L"NextActionTick");
		}
	};
	enum class EFlyAwayItemType
	{
		Coin,
		GoldBar,
		Apple,
		Meat,
		Chicken,
		Max,
		Null,
	};
	struct SFlyAwayItem : public SProto
	{
		SPoint LocalPosition{};
		EFlyAwayItemType ItemType{};
		SFlyAwayItem()
		{
		}
		SFlyAwayItem(const SPoint& LocalPosition_, const EFlyAwayItemType& ItemType_) : LocalPosition(LocalPosition_), ItemType(ItemType_)
		{
		}
		SFlyAwayItem(SPoint&& LocalPosition_, EFlyAwayItemType&& ItemType_) : LocalPosition(std::move(LocalPosition_)), ItemType(std::move(ItemType_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> LocalPosition;
			Stream_ >> ItemType;
		}
		void operator << (const Value& Value_) override
		{
			Value_["LocalPosition"] >> LocalPosition;
			Value_["ItemType"] >> ItemType;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << LocalPosition;
			Stream_ << ItemType;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["LocalPosition"] = LocalPosition;
			Value_["ItemType"] = ItemType;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(SPoint()) + L"," + 
				GetStdName(EFlyAwayItemType());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(SPoint(), L"LocalPosition") + L"," + 
				GetMemberName(EFlyAwayItemType(), L"ItemType");
		}
	};
	struct SFlyAwayBattleInfo : public SingleBattleInfo
	{
		int32 PerfectCombo{};
		SFlyAwayBattleInfo()
		{
		}
		SFlyAwayBattleInfo(const SingleBattleInfo& Super_, const int32& PerfectCombo_) : SingleBattleInfo(Super_), PerfectCombo(PerfectCombo_)
		{
		}
		SFlyAwayBattleInfo(SingleBattleInfo&& Super_, int32&& PerfectCombo_) : SingleBattleInfo(std::move(Super_)), PerfectCombo(std::move(PerfectCombo_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			SingleBattleInfo::operator << (Stream_);
			Stream_ >> PerfectCombo;
		}
		void operator << (const Value& Value_) override
		{
			SingleBattleInfo::operator << (Value_);
			Value_["PerfectCombo"] >> PerfectCombo;
		}
		void operator >> (CStream& Stream_) const override
		{
			SingleBattleInfo::operator >> (Stream_);
			Stream_ << PerfectCombo;
		}
		void operator >> (Value& Value_) const override
		{
			SingleBattleInfo::operator >> (Value_);
			Value_["PerfectCombo"] = PerfectCombo;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(SingleBattleInfo()) + L"," + 
				GetStdName(int32());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(SingleBattleInfo(), L"") + L"," + 
				GetMemberName(int32(), L"PerfectCombo");
		}
	};
	struct SFlyAwayBattleBeginNetSc : public SingleBattleBeginNetSc
	{
		FlyAwayPathMakerState pathMakerState{};
		SFlyAwayBattleInfo BattleInfo{};
		int32 LandCounter{};
		SPoint LastLandPosition{};
		vector<SFlyAwayLand> Lands{};
		vector<SFlyAwayItem> Items{};
		SFlyAwayBattleBeginNetSc()
		{
		}
		SFlyAwayBattleBeginNetSc(const SingleBattleBeginNetSc& Super_, const FlyAwayPathMakerState& pathMakerState_, const SFlyAwayBattleInfo& BattleInfo_, const int32& LandCounter_, const SPoint& LastLandPosition_, const vector<SFlyAwayLand>& Lands_, const vector<SFlyAwayItem>& Items_) : SingleBattleBeginNetSc(Super_), pathMakerState(pathMakerState_), BattleInfo(BattleInfo_), LandCounter(LandCounter_), LastLandPosition(LastLandPosition_), Lands(Lands_), Items(Items_)
		{
		}
		SFlyAwayBattleBeginNetSc(SingleBattleBeginNetSc&& Super_, FlyAwayPathMakerState&& pathMakerState_, SFlyAwayBattleInfo&& BattleInfo_, int32&& LandCounter_, SPoint&& LastLandPosition_, vector<SFlyAwayLand>&& Lands_, vector<SFlyAwayItem>&& Items_) : SingleBattleBeginNetSc(std::move(Super_)), pathMakerState(std::move(pathMakerState_)), BattleInfo(std::move(BattleInfo_)), LandCounter(std::move(LandCounter_)), LastLandPosition(std::move(LastLandPosition_)), Lands(std::move(Lands_)), Items(std::move(Items_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			SingleBattleBeginNetSc::operator << (Stream_);
			Stream_ >> pathMakerState;
			Stream_ >> BattleInfo;
			Stream_ >> LandCounter;
			Stream_ >> LastLandPosition;
			Stream_ >> Lands;
			Stream_ >> Items;
		}
		void operator << (const Value& Value_) override
		{
			SingleBattleBeginNetSc::operator << (Value_);
			Value_["pathMakerState"] >> pathMakerState;
			Value_["BattleInfo"] >> BattleInfo;
			Value_["LandCounter"] >> LandCounter;
			Value_["LastLandPosition"] >> LastLandPosition;
			Value_["Lands"] >> Lands;
			Value_["Items"] >> Items;
		}
		void operator >> (CStream& Stream_) const override
		{
			SingleBattleBeginNetSc::operator >> (Stream_);
			Stream_ << pathMakerState;
			Stream_ << BattleInfo;
			Stream_ << LandCounter;
			Stream_ << LastLandPosition;
			Stream_ << Lands;
			Stream_ << Items;
		}
		void operator >> (Value& Value_) const override
		{
			SingleBattleBeginNetSc::operator >> (Value_);
			Value_["pathMakerState"] = pathMakerState;
			Value_["BattleInfo"] = BattleInfo;
			Value_["LandCounter"] = LandCounter;
			Value_["LastLandPosition"] = LastLandPosition;
			Value_["Lands"] = Lands;
			Value_["Items"] = Items;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(SingleBattleBeginNetSc()) + L"," + 
				GetStdName(FlyAwayPathMakerState()) + L"," + 
				GetStdName(SFlyAwayBattleInfo()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(SPoint()) + L"," + 
				GetStdName(vector<SFlyAwayLand>()) + L"," + 
				GetStdName(vector<SFlyAwayItem>());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(SingleBattleBeginNetSc(), L"") + L"," + 
				GetMemberName(FlyAwayPathMakerState(), L"pathMakerState") + L"," + 
				GetMemberName(SFlyAwayBattleInfo(), L"BattleInfo") + L"," + 
				GetMemberName(int32(), L"LandCounter") + L"," + 
				GetMemberName(SPoint(), L"LastLandPosition") + L"," + 
				GetMemberName(vector<SFlyAwayLand>(), L"Lands") + L"," + 
				GetMemberName(vector<SFlyAwayItem>(), L"Items");
		}
	};
	struct SFlyAwayBattleStartNetSc : public SingleBattleStartNetSc
	{
		void operator << (CStream&) override
		{
		}
		void operator << (const Value&) override
		{
		}
		void operator >> (CStream&) const override
		{
		}
		void operator >> (Value&) const override
		{
		}
		static wstring StdName(void)
		{
			return L"";
		}
		static wstring MemberName(void)
		{
			return L"";
		}
	};
	struct SFlyAwayBattleEndNetCs : public SProto
	{
		void operator << (CStream&) override
		{
		}
		void operator << (const Value&) override
		{
		}
		void operator >> (CStream&) const override
		{
		}
		void operator >> (Value&) const override
		{
		}
		static wstring StdName(void)
		{
			return L"";
		}
		static wstring MemberName(void)
		{
			return L"";
		}
	};
	struct SFlyAwayBattleEndNetSc : public SingleBattleEndNetSc
	{
		SFlyAwayBattleEndNetSc()
		{
		}
		SFlyAwayBattleEndNetSc(const SingleBattleEndNetSc& Super_) : SingleBattleEndNetSc(Super_)
		{
		}
		SFlyAwayBattleEndNetSc(SingleBattleEndNetSc&& Super_) : SingleBattleEndNetSc(std::move(Super_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			SingleBattleEndNetSc::operator << (Stream_);
		}
		void operator << (const Value& Value_) override
		{
			SingleBattleEndNetSc::operator << (Value_);
		}
		void operator >> (CStream& Stream_) const override
		{
			SingleBattleEndNetSc::operator >> (Stream_);
		}
		void operator >> (Value& Value_) const override
		{
			SingleBattleEndNetSc::operator >> (Value_);
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(SingleBattleEndNetSc());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(SingleBattleEndNetSc(), L"");
		}
	};
	struct SRanking : public SProto
	{
		TRankingUsersArray RankingUsersArray{};
		SRanking()
		{
		}
		SRanking(const TRankingUsersArray& RankingUsersArray_) : RankingUsersArray(RankingUsersArray_)
		{
		}
		SRanking(TRankingUsersArray&& RankingUsersArray_) : RankingUsersArray(std::move(RankingUsersArray_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> RankingUsersArray;
		}
		void operator << (const Value& Value_) override
		{
			Value_["RankingUsersArray"] >> RankingUsersArray;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << RankingUsersArray;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["RankingUsersArray"] = RankingUsersArray;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(TRankingUsersArray());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(TRankingUsersArray(), L"RankingUsersArray");
		}
	};
	enum class EProtoRankingNetCs
	{
		RequestRanking,
		Max,
	};
	enum class EProtoRankingNetSc
	{
		RequestRanking,
		Max,
	};
	struct SRankRewardNetCs : public SProto
	{
		void operator << (CStream&) override
		{
		}
		void operator << (const Value&) override
		{
		}
		void operator >> (CStream&) const override
		{
		}
		void operator >> (Value&) const override
		{
		}
		static wstring StdName(void)
		{
			return L"";
		}
		static wstring MemberName(void)
		{
			return L"";
		}
	};
	struct SRankRewardNetSc : public SRewardCore
	{
		int32 NextRewardRankIndex{};
		SRankRewardNetSc()
		{
		}
		SRankRewardNetSc(const SRewardCore& Super_, const int32& NextRewardRankIndex_) : SRewardCore(Super_), NextRewardRankIndex(NextRewardRankIndex_)
		{
		}
		SRankRewardNetSc(SRewardCore&& Super_, int32&& NextRewardRankIndex_) : SRewardCore(std::move(Super_)), NextRewardRankIndex(std::move(NextRewardRankIndex_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			SRewardCore::operator << (Stream_);
			Stream_ >> NextRewardRankIndex;
		}
		void operator << (const Value& Value_) override
		{
			SRewardCore::operator << (Value_);
			Value_["NextRewardRankIndex"] >> NextRewardRankIndex;
		}
		void operator >> (CStream& Stream_) const override
		{
			SRewardCore::operator >> (Stream_);
			Stream_ << NextRewardRankIndex;
		}
		void operator >> (Value& Value_) const override
		{
			SRewardCore::operator >> (Value_);
			Value_["NextRewardRankIndex"] = NextRewardRankIndex;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(SRewardCore()) + L"," + 
				GetStdName(int32());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(SRewardCore(), L"") + L"," + 
				GetMemberName(int32(), L"NextRewardRankIndex");
		}
	};
	struct SQuestSlotIndexCode : public SProto
	{
		TQuestSlotIndex SlotIndex{};
		int32 Code{};
		SQuestSlotIndexCode()
		{
		}
		SQuestSlotIndexCode(const TQuestSlotIndex& SlotIndex_, const int32& Code_) : SlotIndex(SlotIndex_), Code(Code_)
		{
		}
		SQuestSlotIndexCode(TQuestSlotIndex&& SlotIndex_, int32&& Code_) : SlotIndex(std::move(SlotIndex_)), Code(std::move(Code_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> SlotIndex;
			Stream_ >> Code;
		}
		void operator << (const Value& Value_) override
		{
			Value_["SlotIndex"] >> SlotIndex;
			Value_["Code"] >> Code;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << SlotIndex;
			Stream_ << Code;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["SlotIndex"] = SlotIndex;
			Value_["Code"] = Code;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(TQuestSlotIndex()) + L"," + 
				GetStdName(int32());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(TQuestSlotIndex(), L"SlotIndex") + L"," + 
				GetMemberName(int32(), L"Code");
		}
	};
	using TQuestSlotIndexCodes = list<SQuestSlotIndexCode>;
	struct SQuestGotNetSc : public SProto
	{
		TQuestSlotIndexCodes Quests{};
		SQuestGotNetSc()
		{
		}
		SQuestGotNetSc(const TQuestSlotIndexCodes& Quests_) : Quests(Quests_)
		{
		}
		SQuestGotNetSc(TQuestSlotIndexCodes&& Quests_) : Quests(std::move(Quests_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Quests;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Quests"] >> Quests;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Quests;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Quests"] = Quests;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(TQuestSlotIndexCodes());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(TQuestSlotIndexCodes(), L"Quests");
		}
	};
	struct SQuestSetNetSc : public SProto
	{
		TQuestSlotIndex SlotIndex{};
		int32 NewQuestCode{};
		SQuestSetNetSc()
		{
		}
		SQuestSetNetSc(const TQuestSlotIndex& SlotIndex_, const int32& NewQuestCode_) : SlotIndex(SlotIndex_), NewQuestCode(NewQuestCode_)
		{
		}
		SQuestSetNetSc(TQuestSlotIndex&& SlotIndex_, int32&& NewQuestCode_) : SlotIndex(std::move(SlotIndex_)), NewQuestCode(std::move(NewQuestCode_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> SlotIndex;
			Stream_ >> NewQuestCode;
		}
		void operator << (const Value& Value_) override
		{
			Value_["SlotIndex"] >> SlotIndex;
			Value_["NewQuestCode"] >> NewQuestCode;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << SlotIndex;
			Stream_ << NewQuestCode;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["SlotIndex"] = SlotIndex;
			Value_["NewQuestCode"] = NewQuestCode;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(TQuestSlotIndex()) + L"," + 
				GetStdName(int32());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(TQuestSlotIndex(), L"SlotIndex") + L"," + 
				GetMemberName(int32(), L"NewQuestCode");
		}
	};
	struct SQuestDoneNetSc : public SProto
	{
		TQuestSlotIndex SlotIndex{};
		int32 Count{};
		SQuestDoneNetSc()
		{
		}
		SQuestDoneNetSc(const TQuestSlotIndex& SlotIndex_, const int32& Count_) : SlotIndex(SlotIndex_), Count(Count_)
		{
		}
		SQuestDoneNetSc(TQuestSlotIndex&& SlotIndex_, int32&& Count_) : SlotIndex(std::move(SlotIndex_)), Count(std::move(Count_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> SlotIndex;
			Stream_ >> Count;
		}
		void operator << (const Value& Value_) override
		{
			Value_["SlotIndex"] >> SlotIndex;
			Value_["Count"] >> Count;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << SlotIndex;
			Stream_ << Count;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["SlotIndex"] = SlotIndex;
			Value_["Count"] = Count;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(TQuestSlotIndex()) + L"," + 
				GetStdName(int32());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(TQuestSlotIndex(), L"SlotIndex") + L"," + 
				GetMemberName(int32(), L"Count");
		}
	};
	struct SQuestRewardNetCs : public SProto
	{
		TQuestSlotIndex SlotIndex{};
		SQuestRewardNetCs()
		{
		}
		SQuestRewardNetCs(const TQuestSlotIndex& SlotIndex_) : SlotIndex(SlotIndex_)
		{
		}
		SQuestRewardNetCs(TQuestSlotIndex&& SlotIndex_) : SlotIndex(std::move(SlotIndex_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> SlotIndex;
		}
		void operator << (const Value& Value_) override
		{
			Value_["SlotIndex"] >> SlotIndex;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << SlotIndex;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["SlotIndex"] = SlotIndex;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(TQuestSlotIndex());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(TQuestSlotIndex(), L"SlotIndex");
		}
	};
	struct SQuestRewardNetSc : public SRewardCore
	{
		TQuestSlotIndex SlotIndex{};
		int32 newCode{};
		system_clock::time_point CoolEndTime{};
		int32 DailyCompleteCount{};
		system_clock::time_point DailyCompleteRefreshTime{};
		SQuestRewardNetSc()
		{
		}
		SQuestRewardNetSc(const SRewardCore& Super_, const TQuestSlotIndex& SlotIndex_, const int32& newCode_, const system_clock::time_point& CoolEndTime_, const int32& DailyCompleteCount_, const system_clock::time_point& DailyCompleteRefreshTime_) : SRewardCore(Super_), SlotIndex(SlotIndex_), newCode(newCode_), CoolEndTime(CoolEndTime_), DailyCompleteCount(DailyCompleteCount_), DailyCompleteRefreshTime(DailyCompleteRefreshTime_)
		{
		}
		SQuestRewardNetSc(SRewardCore&& Super_, TQuestSlotIndex&& SlotIndex_, int32&& newCode_, system_clock::time_point&& CoolEndTime_, int32&& DailyCompleteCount_, system_clock::time_point&& DailyCompleteRefreshTime_) : SRewardCore(std::move(Super_)), SlotIndex(std::move(SlotIndex_)), newCode(std::move(newCode_)), CoolEndTime(std::move(CoolEndTime_)), DailyCompleteCount(std::move(DailyCompleteCount_)), DailyCompleteRefreshTime(std::move(DailyCompleteRefreshTime_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			SRewardCore::operator << (Stream_);
			Stream_ >> SlotIndex;
			Stream_ >> newCode;
			Stream_ >> CoolEndTime;
			Stream_ >> DailyCompleteCount;
			Stream_ >> DailyCompleteRefreshTime;
		}
		void operator << (const Value& Value_) override
		{
			SRewardCore::operator << (Value_);
			Value_["SlotIndex"] >> SlotIndex;
			Value_["newCode"] >> newCode;
			Value_["CoolEndTime"] >> CoolEndTime;
			Value_["DailyCompleteCount"] >> DailyCompleteCount;
			Value_["DailyCompleteRefreshTime"] >> DailyCompleteRefreshTime;
		}
		void operator >> (CStream& Stream_) const override
		{
			SRewardCore::operator >> (Stream_);
			Stream_ << SlotIndex;
			Stream_ << newCode;
			Stream_ << CoolEndTime;
			Stream_ << DailyCompleteCount;
			Stream_ << DailyCompleteRefreshTime;
		}
		void operator >> (Value& Value_) const override
		{
			SRewardCore::operator >> (Value_);
			Value_["SlotIndex"] = SlotIndex;
			Value_["newCode"] = newCode;
			Value_["CoolEndTime"] = CoolEndTime;
			Value_["DailyCompleteCount"] = DailyCompleteCount;
			Value_["DailyCompleteRefreshTime"] = DailyCompleteRefreshTime;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(SRewardCore()) + L"," + 
				GetStdName(TQuestSlotIndex()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(system_clock::time_point()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(system_clock::time_point());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(SRewardCore(), L"") + L"," + 
				GetMemberName(TQuestSlotIndex(), L"SlotIndex") + L"," + 
				GetMemberName(int32(), L"newCode") + L"," + 
				GetMemberName(system_clock::time_point(), L"CoolEndTime") + L"," + 
				GetMemberName(int32(), L"DailyCompleteCount") + L"," + 
				GetMemberName(system_clock::time_point(), L"DailyCompleteRefreshTime");
		}
	};
	struct SQuestDailyCompleteRewardNetCs : public SProto
	{
		void operator << (CStream&) override
		{
		}
		void operator << (const Value&) override
		{
		}
		void operator >> (CStream&) const override
		{
		}
		void operator >> (Value&) const override
		{
		}
		static wstring StdName(void)
		{
			return L"";
		}
		static wstring MemberName(void)
		{
			return L"";
		}
	};
	struct SQuestDailyCompleteRewardNetSc : public SRewardCore
	{
		system_clock::time_point RefreshTime{};
		SQuestDailyCompleteRewardNetSc()
		{
		}
		SQuestDailyCompleteRewardNetSc(const SRewardCore& Super_, const system_clock::time_point& RefreshTime_) : SRewardCore(Super_), RefreshTime(RefreshTime_)
		{
		}
		SQuestDailyCompleteRewardNetSc(SRewardCore&& Super_, system_clock::time_point&& RefreshTime_) : SRewardCore(std::move(Super_)), RefreshTime(std::move(RefreshTime_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			SRewardCore::operator << (Stream_);
			Stream_ >> RefreshTime;
		}
		void operator << (const Value& Value_) override
		{
			SRewardCore::operator << (Value_);
			Value_["RefreshTime"] >> RefreshTime;
		}
		void operator >> (CStream& Stream_) const override
		{
			SRewardCore::operator >> (Stream_);
			Stream_ << RefreshTime;
		}
		void operator >> (Value& Value_) const override
		{
			SRewardCore::operator >> (Value_);
			Value_["RefreshTime"] = RefreshTime;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(SRewardCore()) + L"," + 
				GetStdName(system_clock::time_point());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(SRewardCore(), L"") + L"," + 
				GetMemberName(system_clock::time_point(), L"RefreshTime");
		}
	};
	struct SChangeNickNetCs : public SProto
	{
		u16string Nick{};
		SChangeNickNetCs()
		{
		}
		SChangeNickNetCs(const u16string& Nick_) : Nick(Nick_)
		{
		}
		SChangeNickNetCs(u16string&& Nick_) : Nick(std::move(Nick_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Nick;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Nick"] >> Nick;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Nick;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Nick"] = Nick;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(u16string());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(u16string(), L"Nick");
		}
	};
	struct SChangeNickNetSc : public SProto
	{
		u16string Nick{};
		SChangeNickNetSc()
		{
		}
		SChangeNickNetSc(const u16string& Nick_) : Nick(Nick_)
		{
		}
		SChangeNickNetSc(u16string&& Nick_) : Nick(std::move(Nick_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Nick;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Nick"] >> Nick;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Nick;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Nick"] = Nick;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(u16string());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(u16string(), L"Nick");
		}
	};
	struct SChangeNickFailNetSc : public SProto
	{
		EGameRet GameRet{};
		wstring ForbiddenWord{};
		SChangeNickFailNetSc()
		{
		}
		SChangeNickFailNetSc(const EGameRet& GameRet_, const wstring& ForbiddenWord_) : GameRet(GameRet_), ForbiddenWord(ForbiddenWord_)
		{
		}
		SChangeNickFailNetSc(EGameRet&& GameRet_, wstring&& ForbiddenWord_) : GameRet(std::move(GameRet_)), ForbiddenWord(std::move(ForbiddenWord_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> GameRet;
			Stream_ >> ForbiddenWord;
		}
		void operator << (const Value& Value_) override
		{
			Value_["GameRet"] >> GameRet;
			Value_["ForbiddenWord"] >> ForbiddenWord;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << GameRet;
			Stream_ << ForbiddenWord;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["GameRet"] = GameRet;
			Value_["ForbiddenWord"] = ForbiddenWord;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(EGameRet()) + L"," + 
				GetStdName(wstring());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(EGameRet(), L"GameRet") + L"," + 
				GetMemberName(wstring(), L"ForbiddenWord");
		}
	};
	struct SNickPoint : public SProto
	{
		int32 Point{};
		SNickPoint()
		{
		}
		SNickPoint(const int32& Point_) : Point(Point_)
		{
		}
		SNickPoint(int32&& Point_) : Point(std::move(Point_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Point;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Point"] >> Point;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Point;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Point"] = Point;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(int32());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(int32(), L"Point");
		}
	};
	struct SCheckIDNetSc : public SProto
	{
		list<SNickPoint> Datas{};
		SCheckIDNetSc()
		{
		}
		SCheckIDNetSc(const list<SNickPoint>& Datas_) : Datas(Datas_)
		{
		}
		SCheckIDNetSc(list<SNickPoint>&& Datas_) : Datas(std::move(Datas_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Datas;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Datas"] >> Datas;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Datas;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Datas"] = Datas;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(list<SNickPoint>());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(list<SNickPoint>(), L"Datas");
		}
	};
	struct SCouponUseNetCs : public SProto
	{
		wstring Key{};
		SCouponUseNetCs()
		{
		}
		SCouponUseNetCs(const wstring& Key_) : Key(Key_)
		{
		}
		SCouponUseNetCs(wstring&& Key_) : Key(std::move(Key_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Key;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Key"] >> Key;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Key;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Key"] = Key;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(wstring());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(wstring(), L"Key");
		}
	};
	struct SCouponUseNetSc : public SRewardCore
	{
		TResources ResourcesAdded{};
		SCouponUseNetSc()
		{
		}
		SCouponUseNetSc(const SRewardCore& Super_, const TResources& ResourcesAdded_) : SRewardCore(Super_), ResourcesAdded(ResourcesAdded_)
		{
		}
		SCouponUseNetSc(SRewardCore&& Super_, TResources&& ResourcesAdded_) : SRewardCore(std::move(Super_)), ResourcesAdded(std::move(ResourcesAdded_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			SRewardCore::operator << (Stream_);
			Stream_ >> ResourcesAdded;
		}
		void operator << (const Value& Value_) override
		{
			SRewardCore::operator << (Value_);
			Value_["ResourcesAdded"] >> ResourcesAdded;
		}
		void operator >> (CStream& Stream_) const override
		{
			SRewardCore::operator >> (Stream_);
			Stream_ << ResourcesAdded;
		}
		void operator >> (Value& Value_) const override
		{
			SRewardCore::operator >> (Value_);
			Value_["ResourcesAdded"] = ResourcesAdded;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(SRewardCore()) + L"," + 
				GetStdName(TResources());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(SRewardCore(), L"") + L"," + 
				GetMemberName(TResources(), L"ResourcesAdded");
		}
	};
	struct SCouponUseFailNetSc : public SProto
	{
		ERet Ret{};
		SCouponUseFailNetSc()
		{
		}
		SCouponUseFailNetSc(const ERet& Ret_) : Ret(Ret_)
		{
		}
		SCouponUseFailNetSc(ERet&& Ret_) : Ret(std::move(Ret_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Ret;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Ret"] >> Ret;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Ret;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Ret"] = Ret;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(ERet());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(ERet(), L"Ret");
		}
	};
	struct STutorialRewardNetCs : public SProto
	{
		void operator << (CStream&) override
		{
		}
		void operator << (const Value&) override
		{
		}
		void operator >> (CStream&) const override
		{
		}
		void operator >> (Value&) const override
		{
		}
		static wstring StdName(void)
		{
			return L"";
		}
		static wstring MemberName(void)
		{
			return L"";
		}
	};
	struct SRankingRewardInfoNetCs : public SProto
	{
		void operator << (CStream&) override
		{
		}
		void operator << (const Value&) override
		{
		}
		void operator >> (CStream&) const override
		{
		}
		void operator >> (Value&) const override
		{
		}
		static wstring StdName(void)
		{
			return L"";
		}
		static wstring MemberName(void)
		{
			return L"";
		}
	};
	struct SRankingRewardInfoNetSc : public SProto
	{
		int64 Counter{};
		TRankingArray RankingArray{};
		SRankingRewardInfoNetSc()
		{
		}
		SRankingRewardInfoNetSc(const int64& Counter_, const TRankingArray& RankingArray_) : Counter(Counter_), RankingArray(RankingArray_)
		{
		}
		SRankingRewardInfoNetSc(int64&& Counter_, TRankingArray&& RankingArray_) : Counter(std::move(Counter_)), RankingArray(std::move(RankingArray_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Counter;
			Stream_ >> RankingArray;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Counter"] >> Counter;
			Value_["RankingArray"] >> RankingArray;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Counter;
			Stream_ << RankingArray;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Counter"] = Counter;
			Value_["RankingArray"] = RankingArray;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(int64()) + L"," + 
				GetStdName(TRankingArray());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(int64(), L"Counter") + L"," + 
				GetMemberName(TRankingArray(), L"RankingArray");
		}
	};
	struct SRankingRewardNetCs : public SProto
	{
		void operator << (CStream&) override
		{
		}
		void operator << (const Value&) override
		{
		}
		void operator >> (CStream&) const override
		{
		}
		void operator >> (Value&) const override
		{
		}
		static wstring StdName(void)
		{
			return L"";
		}
		static wstring MemberName(void)
		{
			return L"";
		}
	};
	struct SRankingRewardNetSc : public SRewardCore
	{
		int64 Counter{};
		TRankingArray myRankingArray{};
		SRankingRewardNetSc()
		{
		}
		SRankingRewardNetSc(const SRewardCore& Super_, const int64& Counter_, const TRankingArray& myRankingArray_) : SRewardCore(Super_), Counter(Counter_), myRankingArray(myRankingArray_)
		{
		}
		SRankingRewardNetSc(SRewardCore&& Super_, int64&& Counter_, TRankingArray&& myRankingArray_) : SRewardCore(std::move(Super_)), Counter(std::move(Counter_)), myRankingArray(std::move(myRankingArray_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			SRewardCore::operator << (Stream_);
			Stream_ >> Counter;
			Stream_ >> myRankingArray;
		}
		void operator << (const Value& Value_) override
		{
			SRewardCore::operator << (Value_);
			Value_["Counter"] >> Counter;
			Value_["myRankingArray"] >> myRankingArray;
		}
		void operator >> (CStream& Stream_) const override
		{
			SRewardCore::operator >> (Stream_);
			Stream_ << Counter;
			Stream_ << myRankingArray;
		}
		void operator >> (Value& Value_) const override
		{
			SRewardCore::operator >> (Value_);
			Value_["Counter"] = Counter;
			Value_["myRankingArray"] = myRankingArray;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(SRewardCore()) + L"," + 
				GetStdName(int64()) + L"," + 
				GetStdName(TRankingArray());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(SRewardCore(), L"") + L"," + 
				GetMemberName(int64(), L"Counter") + L"," + 
				GetMemberName(TRankingArray(), L"myRankingArray");
		}
	};
	struct SRankingRewardFailNetSc : public SProto
	{
		ERet Ret{};
		SRankingRewardFailNetSc()
		{
		}
		SRankingRewardFailNetSc(const ERet& Ret_) : Ret(Ret_)
		{
		}
		SRankingRewardFailNetSc(ERet&& Ret_) : Ret(std::move(Ret_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Ret;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Ret"] >> Ret;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Ret;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Ret"] = Ret;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(ERet());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(ERet(), L"Ret");
		}
	};
}
