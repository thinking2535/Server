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
	const TVer c_Ver_Main = 42;
	const int32 c_FPS = 60;
	const int64 c_NetworkTickSync = 500000;
	const int64 c_NetworkTickBuffer = c_NetworkTickSync+500000;
	const float c_ContactOffset = 0.0001f;
	const float c_LandXDragPerFrame = 1.0f/c_FPS;
	const float c_ScreenWidth = 3.448f;
	const float c_ScreenHeight = 1.8f;
	const float c_ScreenWidth_2 = c_ScreenWidth*0.5f;
	const float c_ScreenHeight_2 = c_ScreenHeight*0.5f;
	const float c_MaxVelDeadY = 1.13784f;
	const float c_Gravity = -0.6465f;
	const float c_MaxVelParachuteX = 0.682704f;
	const float c_MaxVelParachuteY = 0.28446f;
	const float c_GravityParachuteRatio = 0.5f;
	const float c_GravityDeadRatio = 2.0f;
	const float c_ParachuteAccX = 0.6465f;
	const float c_DieUpVel = 0.7f;
	const float c_AirResistance = 1.0f;
	const float c_GroundResistance = 0.1f;
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
	const float c_OnePumpDuration = 0.4f;
	const int32 c_MaxPlayer = 6;
	const float c_GhostSpeed = 3.0f;
	const float c_GameHeight = 3.5f;
	const int8 c_BalloonCountForRegen = 2;
	const int8 c_BalloonCountForPump = 1;
	const int8 c_PumpCountForBalloon = 6;
	const int64 c_BattleStartDelayMilliSec = 2000;
	const int64 c_ChainKillDelayTickCount = 50000000;
	const int64 c_RegenDelayTickCount = 20000000;
	const int32 c_QuestCnt_Max = 5;
	const int32 minNicknameLength = 2;
	const int32 maxNicknameLength = 18;
	enum class EProtoNetCs
	{
		Chat,
		FCMTokenSet,
		FCMTokenUnset,
		FCMCanPushAtNight,
		ChangeLanguage,
		Buy,
		BuyChar,
		BuyPackage,
		BuyResource,
		DailyReward,
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
		Gacha,
		GachaX10,
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
		BuyPackage,
		BuyResource,
		DailyReward,
		DailyRewardFail,
		BattleSync,
		BattleTouch,
		BattlePush,
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
		Gacha,
		GachaX10,
		GachaFailed,
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
		Normal,
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
	using TRankingRewards = map<TUID,int32>;
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
	using TRankingRewardArray = array<int32,3>;
	using TRankingRewardsArray = array<TRankingRewards,3>;
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
		SingleTime,
		SinglePlayScoreGet,
		PlayIsland,
		IslandCount,
		IslandScoreGet,
		RankPointGet,
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
		system_clock::time_point DailyRewardExpiredTime{};
		int32 DailyRewardCountLeft{};
		SUserCore()
		{
		}
		SUserCore(const TResources& Resources_, const int8& Debug_, const int32& SelectedCharCode_, const int32& SinglePlayCount_, const system_clock::time_point& SingleRefreshTime_, const int32& IslandPlayCount_, const system_clock::time_point& IslandRefreshTime_, const system_clock::time_point& QuestDailyCompleteRefreshTime_, const int32& ChangeNickFreeCount_, const system_clock::time_point& DailyRewardExpiredTime_, const int32& DailyRewardCountLeft_) : Resources(Resources_), Debug(Debug_), SelectedCharCode(SelectedCharCode_), SinglePlayCount(SinglePlayCount_), SingleRefreshTime(SingleRefreshTime_), IslandPlayCount(IslandPlayCount_), IslandRefreshTime(IslandRefreshTime_), QuestDailyCompleteRefreshTime(QuestDailyCompleteRefreshTime_), ChangeNickFreeCount(ChangeNickFreeCount_), DailyRewardExpiredTime(DailyRewardExpiredTime_), DailyRewardCountLeft(DailyRewardCountLeft_)
		{
		}
		SUserCore(TResources&& Resources_, int8&& Debug_, int32&& SelectedCharCode_, int32&& SinglePlayCount_, system_clock::time_point&& SingleRefreshTime_, int32&& IslandPlayCount_, system_clock::time_point&& IslandRefreshTime_, system_clock::time_point&& QuestDailyCompleteRefreshTime_, int32&& ChangeNickFreeCount_, system_clock::time_point&& DailyRewardExpiredTime_, int32&& DailyRewardCountLeft_) : Resources(std::move(Resources_)), Debug(std::move(Debug_)), SelectedCharCode(std::move(SelectedCharCode_)), SinglePlayCount(std::move(SinglePlayCount_)), SingleRefreshTime(std::move(SingleRefreshTime_)), IslandPlayCount(std::move(IslandPlayCount_)), IslandRefreshTime(std::move(IslandRefreshTime_)), QuestDailyCompleteRefreshTime(std::move(QuestDailyCompleteRefreshTime_)), ChangeNickFreeCount(std::move(ChangeNickFreeCount_)), DailyRewardExpiredTime(std::move(DailyRewardExpiredTime_)), DailyRewardCountLeft(std::move(DailyRewardCountLeft_))
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
			Stream_ >> DailyRewardExpiredTime;
			Stream_ >> DailyRewardCountLeft;
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
			Value_["DailyRewardExpiredTime"] >> DailyRewardExpiredTime;
			Value_["DailyRewardCountLeft"] >> DailyRewardCountLeft;
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
			Stream_ << DailyRewardExpiredTime;
			Stream_ << DailyRewardCountLeft;
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
			Value_["DailyRewardExpiredTime"] = DailyRewardExpiredTime;
			Value_["DailyRewardCountLeft"] = DailyRewardCountLeft;
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
				GetStdName(int32()) + L"," + 
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
				GetMemberName(int32(), L"ChangeNickFreeCount") + L"," + 
				GetMemberName(system_clock::time_point(), L"DailyRewardExpiredTime") + L"," + 
				GetMemberName(int32(), L"DailyRewardCountLeft");
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
		int32 Point{};
		int32 PointBest{};
		int32 LastGotRewardRankIndex{};
		int32 WinCountSolo{};
		int32 LoseCountSolo{};
		int32 WinCountMulti{};
		int32 LoseCountMulti{};
		int32 BattlePointBest{};
		int32 SinglePointBest{};
		int32 IslandPointBest{};
		int64 SingleBestTick{};
		int32 IslandPassedCountBest{};
		int32 KillTotal{};
		int32 ChainKillTotal{};
		int32 BlowBalloonTotal{};
		int32 QuestDailyCompleteCount{};
		bool TutorialReward{};
		int64 RankingRewardedCounter{};
		TNick NewNick{};
		SInvalidDisconnectInfo InvalidDisconnectInfo{};
		SUserBase()
		{
		}
		SUserBase(const SUserCore& Super_, const TExp& Exp_, const bool& CanPushAtNight_, const int32& Point_, const int32& PointBest_, const int32& LastGotRewardRankIndex_, const int32& WinCountSolo_, const int32& LoseCountSolo_, const int32& WinCountMulti_, const int32& LoseCountMulti_, const int32& BattlePointBest_, const int32& SinglePointBest_, const int32& IslandPointBest_, const int64& SingleBestTick_, const int32& IslandPassedCountBest_, const int32& KillTotal_, const int32& ChainKillTotal_, const int32& BlowBalloonTotal_, const int32& QuestDailyCompleteCount_, const bool& TutorialReward_, const int64& RankingRewardedCounter_, const TNick& NewNick_, const SInvalidDisconnectInfo& InvalidDisconnectInfo_) : SUserCore(Super_), Exp(Exp_), CanPushAtNight(CanPushAtNight_), Point(Point_), PointBest(PointBest_), LastGotRewardRankIndex(LastGotRewardRankIndex_), WinCountSolo(WinCountSolo_), LoseCountSolo(LoseCountSolo_), WinCountMulti(WinCountMulti_), LoseCountMulti(LoseCountMulti_), BattlePointBest(BattlePointBest_), SinglePointBest(SinglePointBest_), IslandPointBest(IslandPointBest_), SingleBestTick(SingleBestTick_), IslandPassedCountBest(IslandPassedCountBest_), KillTotal(KillTotal_), ChainKillTotal(ChainKillTotal_), BlowBalloonTotal(BlowBalloonTotal_), QuestDailyCompleteCount(QuestDailyCompleteCount_), TutorialReward(TutorialReward_), RankingRewardedCounter(RankingRewardedCounter_), NewNick(NewNick_), InvalidDisconnectInfo(InvalidDisconnectInfo_)
		{
		}
		SUserBase(SUserCore&& Super_, TExp&& Exp_, bool&& CanPushAtNight_, int32&& Point_, int32&& PointBest_, int32&& LastGotRewardRankIndex_, int32&& WinCountSolo_, int32&& LoseCountSolo_, int32&& WinCountMulti_, int32&& LoseCountMulti_, int32&& BattlePointBest_, int32&& SinglePointBest_, int32&& IslandPointBest_, int64&& SingleBestTick_, int32&& IslandPassedCountBest_, int32&& KillTotal_, int32&& ChainKillTotal_, int32&& BlowBalloonTotal_, int32&& QuestDailyCompleteCount_, bool&& TutorialReward_, int64&& RankingRewardedCounter_, TNick&& NewNick_, SInvalidDisconnectInfo&& InvalidDisconnectInfo_) : SUserCore(std::move(Super_)), Exp(std::move(Exp_)), CanPushAtNight(std::move(CanPushAtNight_)), Point(std::move(Point_)), PointBest(std::move(PointBest_)), LastGotRewardRankIndex(std::move(LastGotRewardRankIndex_)), WinCountSolo(std::move(WinCountSolo_)), LoseCountSolo(std::move(LoseCountSolo_)), WinCountMulti(std::move(WinCountMulti_)), LoseCountMulti(std::move(LoseCountMulti_)), BattlePointBest(std::move(BattlePointBest_)), SinglePointBest(std::move(SinglePointBest_)), IslandPointBest(std::move(IslandPointBest_)), SingleBestTick(std::move(SingleBestTick_)), IslandPassedCountBest(std::move(IslandPassedCountBest_)), KillTotal(std::move(KillTotal_)), ChainKillTotal(std::move(ChainKillTotal_)), BlowBalloonTotal(std::move(BlowBalloonTotal_)), QuestDailyCompleteCount(std::move(QuestDailyCompleteCount_)), TutorialReward(std::move(TutorialReward_)), RankingRewardedCounter(std::move(RankingRewardedCounter_)), NewNick(std::move(NewNick_)), InvalidDisconnectInfo(std::move(InvalidDisconnectInfo_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			SUserCore::operator << (Stream_);
			Stream_ >> Exp;
			Stream_ >> CanPushAtNight;
			Stream_ >> Point;
			Stream_ >> PointBest;
			Stream_ >> LastGotRewardRankIndex;
			Stream_ >> WinCountSolo;
			Stream_ >> LoseCountSolo;
			Stream_ >> WinCountMulti;
			Stream_ >> LoseCountMulti;
			Stream_ >> BattlePointBest;
			Stream_ >> SinglePointBest;
			Stream_ >> IslandPointBest;
			Stream_ >> SingleBestTick;
			Stream_ >> IslandPassedCountBest;
			Stream_ >> KillTotal;
			Stream_ >> ChainKillTotal;
			Stream_ >> BlowBalloonTotal;
			Stream_ >> QuestDailyCompleteCount;
			Stream_ >> TutorialReward;
			Stream_ >> RankingRewardedCounter;
			Stream_ >> NewNick;
			Stream_ >> InvalidDisconnectInfo;
		}
		void operator << (const Value& Value_) override
		{
			SUserCore::operator << (Value_);
			Value_["Exp"] >> Exp;
			Value_["CanPushAtNight"] >> CanPushAtNight;
			Value_["Point"] >> Point;
			Value_["PointBest"] >> PointBest;
			Value_["LastGotRewardRankIndex"] >> LastGotRewardRankIndex;
			Value_["WinCountSolo"] >> WinCountSolo;
			Value_["LoseCountSolo"] >> LoseCountSolo;
			Value_["WinCountMulti"] >> WinCountMulti;
			Value_["LoseCountMulti"] >> LoseCountMulti;
			Value_["BattlePointBest"] >> BattlePointBest;
			Value_["SinglePointBest"] >> SinglePointBest;
			Value_["IslandPointBest"] >> IslandPointBest;
			Value_["SingleBestTick"] >> SingleBestTick;
			Value_["IslandPassedCountBest"] >> IslandPassedCountBest;
			Value_["KillTotal"] >> KillTotal;
			Value_["ChainKillTotal"] >> ChainKillTotal;
			Value_["BlowBalloonTotal"] >> BlowBalloonTotal;
			Value_["QuestDailyCompleteCount"] >> QuestDailyCompleteCount;
			Value_["TutorialReward"] >> TutorialReward;
			Value_["RankingRewardedCounter"] >> RankingRewardedCounter;
			Value_["NewNick"] >> NewNick;
			Value_["InvalidDisconnectInfo"] >> InvalidDisconnectInfo;
		}
		void operator >> (CStream& Stream_) const override
		{
			SUserCore::operator >> (Stream_);
			Stream_ << Exp;
			Stream_ << CanPushAtNight;
			Stream_ << Point;
			Stream_ << PointBest;
			Stream_ << LastGotRewardRankIndex;
			Stream_ << WinCountSolo;
			Stream_ << LoseCountSolo;
			Stream_ << WinCountMulti;
			Stream_ << LoseCountMulti;
			Stream_ << BattlePointBest;
			Stream_ << SinglePointBest;
			Stream_ << IslandPointBest;
			Stream_ << SingleBestTick;
			Stream_ << IslandPassedCountBest;
			Stream_ << KillTotal;
			Stream_ << ChainKillTotal;
			Stream_ << BlowBalloonTotal;
			Stream_ << QuestDailyCompleteCount;
			Stream_ << TutorialReward;
			Stream_ << RankingRewardedCounter;
			Stream_ << NewNick;
			Stream_ << InvalidDisconnectInfo;
		}
		void operator >> (Value& Value_) const override
		{
			SUserCore::operator >> (Value_);
			Value_["Exp"] = Exp;
			Value_["CanPushAtNight"] = CanPushAtNight;
			Value_["Point"] = Point;
			Value_["PointBest"] = PointBest;
			Value_["LastGotRewardRankIndex"] = LastGotRewardRankIndex;
			Value_["WinCountSolo"] = WinCountSolo;
			Value_["LoseCountSolo"] = LoseCountSolo;
			Value_["WinCountMulti"] = WinCountMulti;
			Value_["LoseCountMulti"] = LoseCountMulti;
			Value_["BattlePointBest"] = BattlePointBest;
			Value_["SinglePointBest"] = SinglePointBest;
			Value_["IslandPointBest"] = IslandPointBest;
			Value_["SingleBestTick"] = SingleBestTick;
			Value_["IslandPassedCountBest"] = IslandPassedCountBest;
			Value_["KillTotal"] = KillTotal;
			Value_["ChainKillTotal"] = ChainKillTotal;
			Value_["BlowBalloonTotal"] = BlowBalloonTotal;
			Value_["QuestDailyCompleteCount"] = QuestDailyCompleteCount;
			Value_["TutorialReward"] = TutorialReward;
			Value_["RankingRewardedCounter"] = RankingRewardedCounter;
			Value_["NewNick"] = NewNick;
			Value_["InvalidDisconnectInfo"] = InvalidDisconnectInfo;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(SUserCore()) + L"," + 
				GetStdName(TExp()) + L"," + 
				GetStdName(bool()) + L"," + 
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
				GetStdName(int64()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(bool()) + L"," + 
				GetStdName(int64()) + L"," + 
				GetStdName(TNick()) + L"," + 
				GetStdName(SInvalidDisconnectInfo());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(SUserCore(), L"") + L"," + 
				GetMemberName(TExp(), L"Exp") + L"," + 
				GetMemberName(bool(), L"CanPushAtNight") + L"," + 
				GetMemberName(int32(), L"Point") + L"," + 
				GetMemberName(int32(), L"PointBest") + L"," + 
				GetMemberName(int32(), L"LastGotRewardRankIndex") + L"," + 
				GetMemberName(int32(), L"WinCountSolo") + L"," + 
				GetMemberName(int32(), L"LoseCountSolo") + L"," + 
				GetMemberName(int32(), L"WinCountMulti") + L"," + 
				GetMemberName(int32(), L"LoseCountMulti") + L"," + 
				GetMemberName(int32(), L"BattlePointBest") + L"," + 
				GetMemberName(int32(), L"SinglePointBest") + L"," + 
				GetMemberName(int32(), L"IslandPointBest") + L"," + 
				GetMemberName(int64(), L"SingleBestTick") + L"," + 
				GetMemberName(int32(), L"IslandPassedCountBest") + L"," + 
				GetMemberName(int32(), L"KillTotal") + L"," + 
				GetMemberName(int32(), L"ChainKillTotal") + L"," + 
				GetMemberName(int32(), L"BlowBalloonTotal") + L"," + 
				GetMemberName(int32(), L"QuestDailyCompleteCount") + L"," + 
				GetMemberName(bool(), L"TutorialReward") + L"," + 
				GetMemberName(int64(), L"RankingRewardedCounter") + L"," + 
				GetMemberName(TNick(), L"NewNick") + L"," + 
				GetMemberName(SInvalidDisconnectInfo(), L"InvalidDisconnectInfo");
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
	using TChars = set<int32>;
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
	using TPackages = set<int32>;
	struct SLoginNetSc : public SProto
	{
		SUserNet User{};
		TChars Chars{};
		system_clock::time_point ServerTime{};
		TQuestDBs Quests{};
		TPackages Packages{};
		SLoginNetSc()
		{
		}
		SLoginNetSc(const SUserNet& User_, const TChars& Chars_, const system_clock::time_point& ServerTime_, const TQuestDBs& Quests_, const TPackages& Packages_) : User(User_), Chars(Chars_), ServerTime(ServerTime_), Quests(Quests_), Packages(Packages_)
		{
		}
		SLoginNetSc(SUserNet&& User_, TChars&& Chars_, system_clock::time_point&& ServerTime_, TQuestDBs&& Quests_, TPackages&& Packages_) : User(std::move(User_)), Chars(std::move(Chars_)), ServerTime(std::move(ServerTime_)), Quests(std::move(Quests_)), Packages(std::move(Packages_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> User;
			Stream_ >> Chars;
			Stream_ >> ServerTime;
			Stream_ >> Quests;
			Stream_ >> Packages;
		}
		void operator << (const Value& Value_) override
		{
			Value_["User"] >> User;
			Value_["Chars"] >> Chars;
			Value_["ServerTime"] >> ServerTime;
			Value_["Quests"] >> Quests;
			Value_["Packages"] >> Packages;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << User;
			Stream_ << Chars;
			Stream_ << ServerTime;
			Stream_ << Quests;
			Stream_ << Packages;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["User"] = User;
			Value_["Chars"] = Chars;
			Value_["ServerTime"] = ServerTime;
			Value_["Quests"] = Quests;
			Value_["Packages"] = Packages;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(SUserNet()) + L"," + 
				GetStdName(TChars()) + L"," + 
				GetStdName(system_clock::time_point()) + L"," + 
				GetStdName(TQuestDBs()) + L"," + 
				GetStdName(TPackages());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(SUserNet(), L"User") + L"," + 
				GetMemberName(TChars(), L"Chars") + L"," + 
				GetMemberName(system_clock::time_point(), L"ServerTime") + L"," + 
				GetMemberName(TQuestDBs(), L"Quests") + L"," + 
				GetMemberName(TPackages(), L"Packages");
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
		list<int32> CharCodes{};
		SSetCharNetSc()
		{
		}
		SSetCharNetSc(const list<int32>& CharCodes_) : CharCodes(CharCodes_)
		{
		}
		SSetCharNetSc(list<int32>&& CharCodes_) : CharCodes(std::move(CharCodes_))
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
	struct SRewardDB : public SProto
	{
		TUID UID{};
		TResources ResourcesLeft{};
		list<int32> CharsAdded{};
		SRewardDB()
		{
		}
		SRewardDB(const TUID& UID_, const TResources& ResourcesLeft_, const list<int32>& CharsAdded_) : UID(UID_), ResourcesLeft(ResourcesLeft_), CharsAdded(CharsAdded_)
		{
		}
		SRewardDB(TUID&& UID_, TResources&& ResourcesLeft_, list<int32>&& CharsAdded_) : UID(std::move(UID_)), ResourcesLeft(std::move(ResourcesLeft_)), CharsAdded(std::move(CharsAdded_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> UID;
			Stream_ >> ResourcesLeft;
			Stream_ >> CharsAdded;
		}
		void operator << (const Value& Value_) override
		{
			Value_["UID"] >> UID;
			Value_["ResourcesLeft"] >> ResourcesLeft;
			Value_["CharsAdded"] >> CharsAdded;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << UID;
			Stream_ << ResourcesLeft;
			Stream_ << CharsAdded;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["UID"] = UID;
			Value_["ResourcesLeft"] = ResourcesLeft;
			Value_["CharsAdded"] = CharsAdded;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(TUID()) + L"," + 
				GetStdName(TResources()) + L"," + 
				GetStdName(list<int32>());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(TUID(), L"UID") + L"," + 
				GetMemberName(TResources(), L"ResourcesLeft") + L"," + 
				GetMemberName(list<int32>(), L"CharsAdded");
		}
	};
	struct SBuyNetSc : public SRewardDB
	{
		int32 Code{};
		SBuyNetSc()
		{
		}
		SBuyNetSc(const SRewardDB& Super_, const int32& Code_) : SRewardDB(Super_), Code(Code_)
		{
		}
		SBuyNetSc(SRewardDB&& Super_, int32&& Code_) : SRewardDB(std::move(Super_)), Code(std::move(Code_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			SRewardDB::operator << (Stream_);
			Stream_ >> Code;
		}
		void operator << (const Value& Value_) override
		{
			SRewardDB::operator << (Value_);
			Value_["Code"] >> Code;
		}
		void operator >> (CStream& Stream_) const override
		{
			SRewardDB::operator >> (Stream_);
			Stream_ << Code;
		}
		void operator >> (Value& Value_) const override
		{
			SRewardDB::operator >> (Value_);
			Value_["Code"] = Code;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(SRewardDB()) + L"," + 
				GetStdName(int32());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(SRewardDB(), L"") + L"," + 
				GetMemberName(int32(), L"Code");
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
	struct SBuyCharNetSc : public SProto
	{
		int32 Code{};
		SBuyCharNetSc()
		{
		}
		SBuyCharNetSc(const int32& Code_) : Code(Code_)
		{
		}
		SBuyCharNetSc(int32&& Code_) : Code(std::move(Code_))
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
	struct SBuyPackageNetCs : public SProto
	{
		int32 Code{};
		SBuyPackageNetCs()
		{
		}
		SBuyPackageNetCs(const int32& Code_) : Code(Code_)
		{
		}
		SBuyPackageNetCs(int32&& Code_) : Code(std::move(Code_))
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
	struct SBuyPackageNetSc : public SRewardDB
	{
		int32 Code{};
		SBuyPackageNetSc()
		{
		}
		SBuyPackageNetSc(const SRewardDB& Super_, const int32& Code_) : SRewardDB(Super_), Code(Code_)
		{
		}
		SBuyPackageNetSc(SRewardDB&& Super_, int32&& Code_) : SRewardDB(std::move(Super_)), Code(std::move(Code_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			SRewardDB::operator << (Stream_);
			Stream_ >> Code;
		}
		void operator << (const Value& Value_) override
		{
			SRewardDB::operator << (Value_);
			Value_["Code"] >> Code;
		}
		void operator >> (CStream& Stream_) const override
		{
			SRewardDB::operator >> (Stream_);
			Stream_ << Code;
		}
		void operator >> (Value& Value_) const override
		{
			SRewardDB::operator >> (Value_);
			Value_["Code"] = Code;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(SRewardDB()) + L"," + 
				GetStdName(int32());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(SRewardDB(), L"") + L"," + 
				GetMemberName(int32(), L"Code");
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
	struct SDailyRewardNetCs : public SProto
	{
		bool IsWatchedAd{};
		SDailyRewardNetCs()
		{
		}
		SDailyRewardNetCs(const bool& IsWatchedAd_) : IsWatchedAd(IsWatchedAd_)
		{
		}
		SDailyRewardNetCs(bool&& IsWatchedAd_) : IsWatchedAd(std::move(IsWatchedAd_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> IsWatchedAd;
		}
		void operator << (const Value& Value_) override
		{
			Value_["IsWatchedAd"] >> IsWatchedAd;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << IsWatchedAd;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["IsWatchedAd"] = IsWatchedAd;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(bool());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(bool(), L"IsWatchedAd");
		}
	};
	struct SDailyRewardNetSc : public SProto
	{
		SResourceTypeData Reward{};
		system_clock::time_point ExpiredTime{};
		int32 CountLeft{};
		SDailyRewardNetSc()
		{
		}
		SDailyRewardNetSc(const SResourceTypeData& Reward_, const system_clock::time_point& ExpiredTime_, const int32& CountLeft_) : Reward(Reward_), ExpiredTime(ExpiredTime_), CountLeft(CountLeft_)
		{
		}
		SDailyRewardNetSc(SResourceTypeData&& Reward_, system_clock::time_point&& ExpiredTime_, int32&& CountLeft_) : Reward(std::move(Reward_)), ExpiredTime(std::move(ExpiredTime_)), CountLeft(std::move(CountLeft_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Reward;
			Stream_ >> ExpiredTime;
			Stream_ >> CountLeft;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Reward"] >> Reward;
			Value_["ExpiredTime"] >> ExpiredTime;
			Value_["CountLeft"] >> CountLeft;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Reward;
			Stream_ << ExpiredTime;
			Stream_ << CountLeft;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Reward"] = Reward;
			Value_["ExpiredTime"] = ExpiredTime;
			Value_["CountLeft"] = CountLeft;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(SResourceTypeData()) + L"," + 
				GetStdName(system_clock::time_point()) + L"," + 
				GetStdName(int32());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(SResourceTypeData(), L"Reward") + L"," + 
				GetMemberName(system_clock::time_point(), L"ExpiredTime") + L"," + 
				GetMemberName(int32(), L"CountLeft");
		}
	};
	struct SDailyRewardFailNetSc : public SProto
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
	struct SBattleTouchNetSc : public SProto
	{
		int64 Tick{};
		int32 PlayerIndex{};
		int8 Dir{};
		SBattleTouchNetSc()
		{
		}
		SBattleTouchNetSc(const int64& Tick_, const int32& PlayerIndex_, const int8& Dir_) : Tick(Tick_), PlayerIndex(PlayerIndex_), Dir(Dir_)
		{
		}
		SBattleTouchNetSc(int64&& Tick_, int32&& PlayerIndex_, int8&& Dir_) : Tick(std::move(Tick_)), PlayerIndex(std::move(PlayerIndex_)), Dir(std::move(Dir_))
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
	struct SBattlePushNetSc : public SProto
	{
		int64 Tick{};
		int32 PlayerIndex{};
		SBattlePushNetSc()
		{
		}
		SBattlePushNetSc(const int64& Tick_, const int32& PlayerIndex_) : Tick(Tick_), PlayerIndex(PlayerIndex_)
		{
		}
		SBattlePushNetSc(int64&& Tick_, int32&& PlayerIndex_) : Tick(std::move(Tick_)), PlayerIndex(std::move(PlayerIndex_))
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
		SPoint Acc{};
		int64 InvulnerableEndTick{};
		int32 ChainKillCount{};
		int64 LastKillTick{};
		int64 RegenTick{};
		SCharacter()
		{
		}
		SCharacter(const bool& IsGround_, const int8& Dir_, const int8& BalloonCount_, const SPumpInfo& PumpInfo_, const SParachuteInfo& ParachuteInfo_, const SStaminaInfo& StaminaInfo_, const int8& Face_, const SPoint& Acc_, const int64& InvulnerableEndTick_, const int32& ChainKillCount_, const int64& LastKillTick_, const int64& RegenTick_) : IsGround(IsGround_), Dir(Dir_), BalloonCount(BalloonCount_), PumpInfo(PumpInfo_), ParachuteInfo(ParachuteInfo_), StaminaInfo(StaminaInfo_), Face(Face_), Acc(Acc_), InvulnerableEndTick(InvulnerableEndTick_), ChainKillCount(ChainKillCount_), LastKillTick(LastKillTick_), RegenTick(RegenTick_)
		{
		}
		SCharacter(bool&& IsGround_, int8&& Dir_, int8&& BalloonCount_, SPumpInfo&& PumpInfo_, SParachuteInfo&& ParachuteInfo_, SStaminaInfo&& StaminaInfo_, int8&& Face_, SPoint&& Acc_, int64&& InvulnerableEndTick_, int32&& ChainKillCount_, int64&& LastKillTick_, int64&& RegenTick_) : IsGround(std::move(IsGround_)), Dir(std::move(Dir_)), BalloonCount(std::move(BalloonCount_)), PumpInfo(std::move(PumpInfo_)), ParachuteInfo(std::move(ParachuteInfo_)), StaminaInfo(std::move(StaminaInfo_)), Face(std::move(Face_)), Acc(std::move(Acc_)), InvulnerableEndTick(std::move(InvulnerableEndTick_)), ChainKillCount(std::move(ChainKillCount_)), LastKillTick(std::move(LastKillTick_)), RegenTick(std::move(RegenTick_))
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
			Stream_ >> Acc;
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
			Value_["Acc"] >> Acc;
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
			Stream_ << Acc;
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
			Value_["Acc"] = Acc;
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
				GetStdName(SPoint()) + L"," + 
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
				GetMemberName(SPoint(), L"Acc") + L"," + 
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
	struct SMultiBattleInfo : public SProto
	{
		int32 Point{};
		SMultiBattleInfo()
		{
		}
		SMultiBattleInfo(const int32& Point_) : Point(Point_)
		{
		}
		SMultiBattleInfo(int32&& Point_) : Point(std::move(Point_))
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
	struct SBattleEndPlayer : public SProto
	{
		int32 AddedPoint{};
		int32 AddedGold{};
		int32 BattlePoint{};
		SBattleEndPlayer()
		{
		}
		SBattleEndPlayer(const int32& AddedPoint_, const int32& AddedGold_, const int32& BattlePoint_) : AddedPoint(AddedPoint_), AddedGold(AddedGold_), BattlePoint(BattlePoint_)
		{
		}
		SBattleEndPlayer(int32&& AddedPoint_, int32&& AddedGold_, int32&& BattlePoint_) : AddedPoint(std::move(AddedPoint_)), AddedGold(std::move(AddedGold_)), BattlePoint(std::move(BattlePoint_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> AddedPoint;
			Stream_ >> AddedGold;
			Stream_ >> BattlePoint;
		}
		void operator << (const Value& Value_) override
		{
			Value_["AddedPoint"] >> AddedPoint;
			Value_["AddedGold"] >> AddedGold;
			Value_["BattlePoint"] >> BattlePoint;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << AddedPoint;
			Stream_ << AddedGold;
			Stream_ << BattlePoint;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["AddedPoint"] = AddedPoint;
			Value_["AddedGold"] = AddedGold;
			Value_["BattlePoint"] = BattlePoint;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(int32(), L"AddedPoint") + L"," + 
				GetMemberName(int32(), L"AddedGold") + L"," + 
				GetMemberName(int32(), L"BattlePoint");
		}
	};
	struct STeamBattleInfo : public SProto
	{
		int32 Ranking{};
		int32 Point{};
		STeamBattleInfo()
		{
		}
		STeamBattleInfo(const int32& Ranking_, const int32& Point_) : Ranking(Ranking_), Point(Point_)
		{
		}
		STeamBattleInfo(int32&& Ranking_, int32&& Point_) : Ranking(std::move(Ranking_)), Point(std::move(Point_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Ranking;
			Stream_ >> Point;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Ranking"] >> Ranking;
			Value_["Point"] >> Point;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Ranking;
			Stream_ << Point;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Ranking"] = Ranking;
			Value_["Point"] = Point;
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
				GetMemberName(int32(), L"Ranking") + L"," + 
				GetMemberName(int32(), L"Point");
		}
	};
	using TTeamIndexGroup = list<TTeamCnt>;
	struct STeamRanking : public STeamBattleInfo
	{
		TTeamIndexGroup TeamIndexGroup{};
		STeamRanking()
		{
		}
		STeamRanking(const STeamBattleInfo& Super_, const TTeamIndexGroup& TeamIndexGroup_) : STeamBattleInfo(Super_), TeamIndexGroup(TeamIndexGroup_)
		{
		}
		STeamRanking(STeamBattleInfo&& Super_, TTeamIndexGroup&& TeamIndexGroup_) : STeamBattleInfo(std::move(Super_)), TeamIndexGroup(std::move(TeamIndexGroup_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			STeamBattleInfo::operator << (Stream_);
			Stream_ >> TeamIndexGroup;
		}
		void operator << (const Value& Value_) override
		{
			STeamBattleInfo::operator << (Value_);
			Value_["TeamIndexGroup"] >> TeamIndexGroup;
		}
		void operator >> (CStream& Stream_) const override
		{
			STeamBattleInfo::operator >> (Stream_);
			Stream_ << TeamIndexGroup;
		}
		void operator >> (Value& Value_) const override
		{
			STeamBattleInfo::operator >> (Value_);
			Value_["TeamIndexGroup"] = TeamIndexGroup;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(STeamBattleInfo()) + L"," + 
				GetStdName(TTeamIndexGroup());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(STeamBattleInfo(), L"") + L"," + 
				GetMemberName(TTeamIndexGroup(), L"TeamIndexGroup");
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
		TResources ResourcesLeft{};
		vector<SBattleEndPlayer> BattleEndPlayers{};
		vector<STeamRanking> OrderedTeamRankings{};
		TDoneQuests DoneQuests{};
		SMultiBattleEndNetSc()
		{
		}
		SMultiBattleEndNetSc(const SMultiBattleEndNet& Super_, const TResources& ResourcesLeft_, const vector<SBattleEndPlayer>& BattleEndPlayers_, const vector<STeamRanking>& OrderedTeamRankings_, const TDoneQuests& DoneQuests_) : SMultiBattleEndNet(Super_), ResourcesLeft(ResourcesLeft_), BattleEndPlayers(BattleEndPlayers_), OrderedTeamRankings(OrderedTeamRankings_), DoneQuests(DoneQuests_)
		{
		}
		SMultiBattleEndNetSc(SMultiBattleEndNet&& Super_, TResources&& ResourcesLeft_, vector<SBattleEndPlayer>&& BattleEndPlayers_, vector<STeamRanking>&& OrderedTeamRankings_, TDoneQuests&& DoneQuests_) : SMultiBattleEndNet(std::move(Super_)), ResourcesLeft(std::move(ResourcesLeft_)), BattleEndPlayers(std::move(BattleEndPlayers_)), OrderedTeamRankings(std::move(OrderedTeamRankings_)), DoneQuests(std::move(DoneQuests_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			SMultiBattleEndNet::operator << (Stream_);
			Stream_ >> ResourcesLeft;
			Stream_ >> BattleEndPlayers;
			Stream_ >> OrderedTeamRankings;
			Stream_ >> DoneQuests;
		}
		void operator << (const Value& Value_) override
		{
			SMultiBattleEndNet::operator << (Value_);
			Value_["ResourcesLeft"] >> ResourcesLeft;
			Value_["BattleEndPlayers"] >> BattleEndPlayers;
			Value_["OrderedTeamRankings"] >> OrderedTeamRankings;
			Value_["DoneQuests"] >> DoneQuests;
		}
		void operator >> (CStream& Stream_) const override
		{
			SMultiBattleEndNet::operator >> (Stream_);
			Stream_ << ResourcesLeft;
			Stream_ << BattleEndPlayers;
			Stream_ << OrderedTeamRankings;
			Stream_ << DoneQuests;
		}
		void operator >> (Value& Value_) const override
		{
			SMultiBattleEndNet::operator >> (Value_);
			Value_["ResourcesLeft"] = ResourcesLeft;
			Value_["BattleEndPlayers"] = BattleEndPlayers;
			Value_["OrderedTeamRankings"] = OrderedTeamRankings;
			Value_["DoneQuests"] = DoneQuests;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(SMultiBattleEndNet()) + L"," + 
				GetStdName(TResources()) + L"," + 
				GetStdName(vector<SBattleEndPlayer>()) + L"," + 
				GetStdName(vector<STeamRanking>()) + L"," + 
				GetStdName(TDoneQuests());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(SMultiBattleEndNet(), L"") + L"," + 
				GetMemberName(TResources(), L"ResourcesLeft") + L"," + 
				GetMemberName(vector<SBattleEndPlayer>(), L"BattleEndPlayers") + L"," + 
				GetMemberName(vector<STeamRanking>(), L"OrderedTeamRankings") + L"," + 
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
	struct SArrowDodgeBattleInfo : public SProto
	{
		int32 Point{};
		int64 Tick{};
		TResource Gold{};
		SArrowDodgeBattleInfo()
		{
		}
		SArrowDodgeBattleInfo(const int32& Point_, const int64& Tick_, const TResource& Gold_) : Point(Point_), Tick(Tick_), Gold(Gold_)
		{
		}
		SArrowDodgeBattleInfo(int32&& Point_, int64&& Tick_, TResource&& Gold_) : Point(std::move(Point_)), Tick(std::move(Tick_)), Gold(std::move(Gold_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Point;
			Stream_ >> Tick;
			Stream_ >> Gold;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Point"] >> Point;
			Value_["Tick"] >> Tick;
			Value_["Gold"] >> Gold;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Point;
			Stream_ << Tick;
			Stream_ << Gold;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Point"] = Point;
			Value_["Tick"] = Tick;
			Value_["Gold"] = Gold;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(int32()) + L"," + 
				GetStdName(int64()) + L"," + 
				GetStdName(TResource());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(int32(), L"Point") + L"," + 
				GetMemberName(int64(), L"Tick") + L"," + 
				GetMemberName(TResource(), L"Gold");
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
	struct SArrowDodgeBattleBeginNetSc : public SProto
	{
		SBattlePlayer Player{};
		SArrowDodgeBattleInfo BattleInfo{};
		SArrowDodgeBattleBufs Bufs{};
		SCharacterNet Character{};
		int64 Tick{};
		uint32 RandomSeed{};
		int64 NextDownArrowTick{};
		int64 NextLeftArrowTick{};
		int64 NextRightArrowTick{};
		int64 NextItemTick{};
		vector<SArrow> Arrows{};
		vector<SArrowDodgeItem> Items{};
		bool Started{};
		SArrowDodgeBattleBeginNetSc()
		{
		}
		SArrowDodgeBattleBeginNetSc(const SBattlePlayer& Player_, const SArrowDodgeBattleInfo& BattleInfo_, const SArrowDodgeBattleBufs& Bufs_, const SCharacterNet& Character_, const int64& Tick_, const uint32& RandomSeed_, const int64& NextDownArrowTick_, const int64& NextLeftArrowTick_, const int64& NextRightArrowTick_, const int64& NextItemTick_, const vector<SArrow>& Arrows_, const vector<SArrowDodgeItem>& Items_, const bool& Started_) : Player(Player_), BattleInfo(BattleInfo_), Bufs(Bufs_), Character(Character_), Tick(Tick_), RandomSeed(RandomSeed_), NextDownArrowTick(NextDownArrowTick_), NextLeftArrowTick(NextLeftArrowTick_), NextRightArrowTick(NextRightArrowTick_), NextItemTick(NextItemTick_), Arrows(Arrows_), Items(Items_), Started(Started_)
		{
		}
		SArrowDodgeBattleBeginNetSc(SBattlePlayer&& Player_, SArrowDodgeBattleInfo&& BattleInfo_, SArrowDodgeBattleBufs&& Bufs_, SCharacterNet&& Character_, int64&& Tick_, uint32&& RandomSeed_, int64&& NextDownArrowTick_, int64&& NextLeftArrowTick_, int64&& NextRightArrowTick_, int64&& NextItemTick_, vector<SArrow>&& Arrows_, vector<SArrowDodgeItem>&& Items_, bool&& Started_) : Player(std::move(Player_)), BattleInfo(std::move(BattleInfo_)), Bufs(std::move(Bufs_)), Character(std::move(Character_)), Tick(std::move(Tick_)), RandomSeed(std::move(RandomSeed_)), NextDownArrowTick(std::move(NextDownArrowTick_)), NextLeftArrowTick(std::move(NextLeftArrowTick_)), NextRightArrowTick(std::move(NextRightArrowTick_)), NextItemTick(std::move(NextItemTick_)), Arrows(std::move(Arrows_)), Items(std::move(Items_)), Started(std::move(Started_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Player;
			Stream_ >> BattleInfo;
			Stream_ >> Bufs;
			Stream_ >> Character;
			Stream_ >> Tick;
			Stream_ >> RandomSeed;
			Stream_ >> NextDownArrowTick;
			Stream_ >> NextLeftArrowTick;
			Stream_ >> NextRightArrowTick;
			Stream_ >> NextItemTick;
			Stream_ >> Arrows;
			Stream_ >> Items;
			Stream_ >> Started;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Player"] >> Player;
			Value_["BattleInfo"] >> BattleInfo;
			Value_["Bufs"] >> Bufs;
			Value_["Character"] >> Character;
			Value_["Tick"] >> Tick;
			Value_["RandomSeed"] >> RandomSeed;
			Value_["NextDownArrowTick"] >> NextDownArrowTick;
			Value_["NextLeftArrowTick"] >> NextLeftArrowTick;
			Value_["NextRightArrowTick"] >> NextRightArrowTick;
			Value_["NextItemTick"] >> NextItemTick;
			Value_["Arrows"] >> Arrows;
			Value_["Items"] >> Items;
			Value_["Started"] >> Started;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Player;
			Stream_ << BattleInfo;
			Stream_ << Bufs;
			Stream_ << Character;
			Stream_ << Tick;
			Stream_ << RandomSeed;
			Stream_ << NextDownArrowTick;
			Stream_ << NextLeftArrowTick;
			Stream_ << NextRightArrowTick;
			Stream_ << NextItemTick;
			Stream_ << Arrows;
			Stream_ << Items;
			Stream_ << Started;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Player"] = Player;
			Value_["BattleInfo"] = BattleInfo;
			Value_["Bufs"] = Bufs;
			Value_["Character"] = Character;
			Value_["Tick"] = Tick;
			Value_["RandomSeed"] = RandomSeed;
			Value_["NextDownArrowTick"] = NextDownArrowTick;
			Value_["NextLeftArrowTick"] = NextLeftArrowTick;
			Value_["NextRightArrowTick"] = NextRightArrowTick;
			Value_["NextItemTick"] = NextItemTick;
			Value_["Arrows"] = Arrows;
			Value_["Items"] = Items;
			Value_["Started"] = Started;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(SBattlePlayer()) + L"," + 
				GetStdName(SArrowDodgeBattleInfo()) + L"," + 
				GetStdName(SArrowDodgeBattleBufs()) + L"," + 
				GetStdName(SCharacterNet()) + L"," + 
				GetStdName(int64()) + L"," + 
				GetStdName(uint32()) + L"," + 
				GetStdName(int64()) + L"," + 
				GetStdName(int64()) + L"," + 
				GetStdName(int64()) + L"," + 
				GetStdName(int64()) + L"," + 
				GetStdName(vector<SArrow>()) + L"," + 
				GetStdName(vector<SArrowDodgeItem>()) + L"," + 
				GetStdName(bool());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(SBattlePlayer(), L"Player") + L"," + 
				GetMemberName(SArrowDodgeBattleInfo(), L"BattleInfo") + L"," + 
				GetMemberName(SArrowDodgeBattleBufs(), L"Bufs") + L"," + 
				GetMemberName(SCharacterNet(), L"Character") + L"," + 
				GetMemberName(int64(), L"Tick") + L"," + 
				GetMemberName(uint32(), L"RandomSeed") + L"," + 
				GetMemberName(int64(), L"NextDownArrowTick") + L"," + 
				GetMemberName(int64(), L"NextLeftArrowTick") + L"," + 
				GetMemberName(int64(), L"NextRightArrowTick") + L"," + 
				GetMemberName(int64(), L"NextItemTick") + L"," + 
				GetMemberName(vector<SArrow>(), L"Arrows") + L"," + 
				GetMemberName(vector<SArrowDodgeItem>(), L"Items") + L"," + 
				GetMemberName(bool(), L"Started");
		}
	};
	struct SArrowDodgeBattleStartNetSc : public SProto
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
	struct SArrowDodgeBattleEndNetSc : public SProto
	{
		int64 Tick{};
		TResources ResourcesLeft{};
		TDoneQuests DoneQuests{};
		SArrowDodgeBattleEndNetSc()
		{
		}
		SArrowDodgeBattleEndNetSc(const int64& Tick_, const TResources& ResourcesLeft_, const TDoneQuests& DoneQuests_) : Tick(Tick_), ResourcesLeft(ResourcesLeft_), DoneQuests(DoneQuests_)
		{
		}
		SArrowDodgeBattleEndNetSc(int64&& Tick_, TResources&& ResourcesLeft_, TDoneQuests&& DoneQuests_) : Tick(std::move(Tick_)), ResourcesLeft(std::move(ResourcesLeft_)), DoneQuests(std::move(DoneQuests_))
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
	struct SFlyAwayBattleInfo : public SProto
	{
		int32 Point{};
		int32 PassedCount{};
		int32 PerfectCombo{};
		TResource Gold{};
		SFlyAwayBattleInfo()
		{
		}
		SFlyAwayBattleInfo(const int32& Point_, const int32& PassedCount_, const int32& PerfectCombo_, const TResource& Gold_) : Point(Point_), PassedCount(PassedCount_), PerfectCombo(PerfectCombo_), Gold(Gold_)
		{
		}
		SFlyAwayBattleInfo(int32&& Point_, int32&& PassedCount_, int32&& PerfectCombo_, TResource&& Gold_) : Point(std::move(Point_)), PassedCount(std::move(PassedCount_)), PerfectCombo(std::move(PerfectCombo_)), Gold(std::move(Gold_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Point;
			Stream_ >> PassedCount;
			Stream_ >> PerfectCombo;
			Stream_ >> Gold;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Point"] >> Point;
			Value_["PassedCount"] >> PassedCount;
			Value_["PerfectCombo"] >> PerfectCombo;
			Value_["Gold"] >> Gold;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Point;
			Stream_ << PassedCount;
			Stream_ << PerfectCombo;
			Stream_ << Gold;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Point"] = Point;
			Value_["PassedCount"] = PassedCount;
			Value_["PerfectCombo"] = PerfectCombo;
			Value_["Gold"] = Gold;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(TResource());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(int32(), L"Point") + L"," + 
				GetMemberName(int32(), L"PassedCount") + L"," + 
				GetMemberName(int32(), L"PerfectCombo") + L"," + 
				GetMemberName(TResource(), L"Gold");
		}
	};
	struct SFlyAwayBattleBeginNetSc : public SProto
	{
		SBattlePlayer Player{};
		SFlyAwayBattleInfo BattleInfo{};
		SCharacterNet Character{};
		int64 Tick{};
		uint32 RandomSeed{};
		int32 LandCounter{};
		SPoint LastLandPosition{};
		vector<SFlyAwayLand> Lands{};
		vector<SFlyAwayItem> Items{};
		bool Started{};
		SFlyAwayBattleBeginNetSc()
		{
		}
		SFlyAwayBattleBeginNetSc(const SBattlePlayer& Player_, const SFlyAwayBattleInfo& BattleInfo_, const SCharacterNet& Character_, const int64& Tick_, const uint32& RandomSeed_, const int32& LandCounter_, const SPoint& LastLandPosition_, const vector<SFlyAwayLand>& Lands_, const vector<SFlyAwayItem>& Items_, const bool& Started_) : Player(Player_), BattleInfo(BattleInfo_), Character(Character_), Tick(Tick_), RandomSeed(RandomSeed_), LandCounter(LandCounter_), LastLandPosition(LastLandPosition_), Lands(Lands_), Items(Items_), Started(Started_)
		{
		}
		SFlyAwayBattleBeginNetSc(SBattlePlayer&& Player_, SFlyAwayBattleInfo&& BattleInfo_, SCharacterNet&& Character_, int64&& Tick_, uint32&& RandomSeed_, int32&& LandCounter_, SPoint&& LastLandPosition_, vector<SFlyAwayLand>&& Lands_, vector<SFlyAwayItem>&& Items_, bool&& Started_) : Player(std::move(Player_)), BattleInfo(std::move(BattleInfo_)), Character(std::move(Character_)), Tick(std::move(Tick_)), RandomSeed(std::move(RandomSeed_)), LandCounter(std::move(LandCounter_)), LastLandPosition(std::move(LastLandPosition_)), Lands(std::move(Lands_)), Items(std::move(Items_)), Started(std::move(Started_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Player;
			Stream_ >> BattleInfo;
			Stream_ >> Character;
			Stream_ >> Tick;
			Stream_ >> RandomSeed;
			Stream_ >> LandCounter;
			Stream_ >> LastLandPosition;
			Stream_ >> Lands;
			Stream_ >> Items;
			Stream_ >> Started;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Player"] >> Player;
			Value_["BattleInfo"] >> BattleInfo;
			Value_["Character"] >> Character;
			Value_["Tick"] >> Tick;
			Value_["RandomSeed"] >> RandomSeed;
			Value_["LandCounter"] >> LandCounter;
			Value_["LastLandPosition"] >> LastLandPosition;
			Value_["Lands"] >> Lands;
			Value_["Items"] >> Items;
			Value_["Started"] >> Started;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Player;
			Stream_ << BattleInfo;
			Stream_ << Character;
			Stream_ << Tick;
			Stream_ << RandomSeed;
			Stream_ << LandCounter;
			Stream_ << LastLandPosition;
			Stream_ << Lands;
			Stream_ << Items;
			Stream_ << Started;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Player"] = Player;
			Value_["BattleInfo"] = BattleInfo;
			Value_["Character"] = Character;
			Value_["Tick"] = Tick;
			Value_["RandomSeed"] = RandomSeed;
			Value_["LandCounter"] = LandCounter;
			Value_["LastLandPosition"] = LastLandPosition;
			Value_["Lands"] = Lands;
			Value_["Items"] = Items;
			Value_["Started"] = Started;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(SBattlePlayer()) + L"," + 
				GetStdName(SFlyAwayBattleInfo()) + L"," + 
				GetStdName(SCharacterNet()) + L"," + 
				GetStdName(int64()) + L"," + 
				GetStdName(uint32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(SPoint()) + L"," + 
				GetStdName(vector<SFlyAwayLand>()) + L"," + 
				GetStdName(vector<SFlyAwayItem>()) + L"," + 
				GetStdName(bool());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(SBattlePlayer(), L"Player") + L"," + 
				GetMemberName(SFlyAwayBattleInfo(), L"BattleInfo") + L"," + 
				GetMemberName(SCharacterNet(), L"Character") + L"," + 
				GetMemberName(int64(), L"Tick") + L"," + 
				GetMemberName(uint32(), L"RandomSeed") + L"," + 
				GetMemberName(int32(), L"LandCounter") + L"," + 
				GetMemberName(SPoint(), L"LastLandPosition") + L"," + 
				GetMemberName(vector<SFlyAwayLand>(), L"Lands") + L"," + 
				GetMemberName(vector<SFlyAwayItem>(), L"Items") + L"," + 
				GetMemberName(bool(), L"Started");
		}
	};
	struct SFlyAwayBattleStartNetSc : public SProto
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
	struct SFlyAwayBattleEndNetSc : public SProto
	{
		int64 Tick{};
		TResources ResourcesLeft{};
		TDoneQuests DoneQuests{};
		SFlyAwayBattleEndNetSc()
		{
		}
		SFlyAwayBattleEndNetSc(const int64& Tick_, const TResources& ResourcesLeft_, const TDoneQuests& DoneQuests_) : Tick(Tick_), ResourcesLeft(ResourcesLeft_), DoneQuests(DoneQuests_)
		{
		}
		SFlyAwayBattleEndNetSc(int64&& Tick_, TResources&& ResourcesLeft_, TDoneQuests&& DoneQuests_) : Tick(std::move(Tick_)), ResourcesLeft(std::move(ResourcesLeft_)), DoneQuests(std::move(DoneQuests_))
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
	struct SGachaNetCs : public SProto
	{
		int32 GachaIndex{};
		SGachaNetCs()
		{
		}
		SGachaNetCs(const int32& GachaIndex_) : GachaIndex(GachaIndex_)
		{
		}
		SGachaNetCs(int32&& GachaIndex_) : GachaIndex(std::move(GachaIndex_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> GachaIndex;
		}
		void operator << (const Value& Value_) override
		{
			Value_["GachaIndex"] >> GachaIndex;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << GachaIndex;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["GachaIndex"] = GachaIndex;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(int32());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(int32(), L"GachaIndex");
		}
	};
	struct SGachaX10NetCs : public SProto
	{
		int32 GachaIndex{};
		SGachaX10NetCs()
		{
		}
		SGachaX10NetCs(const int32& GachaIndex_) : GachaIndex(GachaIndex_)
		{
		}
		SGachaX10NetCs(int32&& GachaIndex_) : GachaIndex(std::move(GachaIndex_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> GachaIndex;
		}
		void operator << (const Value& Value_) override
		{
			Value_["GachaIndex"] >> GachaIndex;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << GachaIndex;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["GachaIndex"] = GachaIndex;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(int32());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(int32(), L"GachaIndex");
		}
	};
	struct SGachaNetSc : public SProto
	{
		TResources Cost{};
		int32 Index{};
		int32 CharCode{};
		SGachaNetSc()
		{
		}
		SGachaNetSc(const TResources& Cost_, const int32& Index_, const int32& CharCode_) : Cost(Cost_), Index(Index_), CharCode(CharCode_)
		{
		}
		SGachaNetSc(TResources&& Cost_, int32&& Index_, int32&& CharCode_) : Cost(std::move(Cost_)), Index(std::move(Index_)), CharCode(std::move(CharCode_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Cost;
			Stream_ >> Index;
			Stream_ >> CharCode;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Cost"] >> Cost;
			Value_["Index"] >> Index;
			Value_["CharCode"] >> CharCode;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Cost;
			Stream_ << Index;
			Stream_ << CharCode;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Cost"] = Cost;
			Value_["Index"] = Index;
			Value_["CharCode"] = CharCode;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(TResources()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(TResources(), L"Cost") + L"," + 
				GetMemberName(int32(), L"Index") + L"," + 
				GetMemberName(int32(), L"CharCode");
		}
	};
	struct SGachaX10NetSc : public SProto
	{
		TResources Cost{};
		int32 Index{};
		list<int32> CharCodeList{};
		TResources Refund{};
		SGachaX10NetSc()
		{
		}
		SGachaX10NetSc(const TResources& Cost_, const int32& Index_, const list<int32>& CharCodeList_, const TResources& Refund_) : Cost(Cost_), Index(Index_), CharCodeList(CharCodeList_), Refund(Refund_)
		{
		}
		SGachaX10NetSc(TResources&& Cost_, int32&& Index_, list<int32>&& CharCodeList_, TResources&& Refund_) : Cost(std::move(Cost_)), Index(std::move(Index_)), CharCodeList(std::move(CharCodeList_)), Refund(std::move(Refund_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Cost;
			Stream_ >> Index;
			Stream_ >> CharCodeList;
			Stream_ >> Refund;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Cost"] >> Cost;
			Value_["Index"] >> Index;
			Value_["CharCodeList"] >> CharCodeList;
			Value_["Refund"] >> Refund;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Cost;
			Stream_ << Index;
			Stream_ << CharCodeList;
			Stream_ << Refund;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Cost"] = Cost;
			Value_["Index"] = Index;
			Value_["CharCodeList"] = CharCodeList;
			Value_["Refund"] = Refund;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(TResources()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(list<int32>()) + L"," + 
				GetStdName(TResources());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(TResources(), L"Cost") + L"," + 
				GetMemberName(int32(), L"Index") + L"," + 
				GetMemberName(list<int32>(), L"CharCodeList") + L"," + 
				GetMemberName(TResources(), L"Refund");
		}
	};
	struct SGachaFailedNetSc : public SGachaNetSc
	{
		TResources Refund{};
		SGachaFailedNetSc()
		{
		}
		SGachaFailedNetSc(const SGachaNetSc& Super_, const TResources& Refund_) : SGachaNetSc(Super_), Refund(Refund_)
		{
		}
		SGachaFailedNetSc(SGachaNetSc&& Super_, TResources&& Refund_) : SGachaNetSc(std::move(Super_)), Refund(std::move(Refund_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			SGachaNetSc::operator << (Stream_);
			Stream_ >> Refund;
		}
		void operator << (const Value& Value_) override
		{
			SGachaNetSc::operator << (Value_);
			Value_["Refund"] >> Refund;
		}
		void operator >> (CStream& Stream_) const override
		{
			SGachaNetSc::operator >> (Stream_);
			Stream_ << Refund;
		}
		void operator >> (Value& Value_) const override
		{
			SGachaNetSc::operator >> (Value_);
			Value_["Refund"] = Refund;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(SGachaNetSc()) + L"," + 
				GetStdName(TResources());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(SGachaNetSc(), L"") + L"," + 
				GetMemberName(TResources(), L"Refund");
		}
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
	struct SRankRewardNetSc : public SRewardDB
	{
		int32 LastGotRewardRankIndex{};
		SRankRewardNetSc()
		{
		}
		SRankRewardNetSc(const SRewardDB& Super_, const int32& LastGotRewardRankIndex_) : SRewardDB(Super_), LastGotRewardRankIndex(LastGotRewardRankIndex_)
		{
		}
		SRankRewardNetSc(SRewardDB&& Super_, int32&& LastGotRewardRankIndex_) : SRewardDB(std::move(Super_)), LastGotRewardRankIndex(std::move(LastGotRewardRankIndex_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			SRewardDB::operator << (Stream_);
			Stream_ >> LastGotRewardRankIndex;
		}
		void operator << (const Value& Value_) override
		{
			SRewardDB::operator << (Value_);
			Value_["LastGotRewardRankIndex"] >> LastGotRewardRankIndex;
		}
		void operator >> (CStream& Stream_) const override
		{
			SRewardDB::operator >> (Stream_);
			Stream_ << LastGotRewardRankIndex;
		}
		void operator >> (Value& Value_) const override
		{
			SRewardDB::operator >> (Value_);
			Value_["LastGotRewardRankIndex"] = LastGotRewardRankIndex;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(SRewardDB()) + L"," + 
				GetStdName(int32());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(SRewardDB(), L"") + L"," + 
				GetMemberName(int32(), L"LastGotRewardRankIndex");
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
	struct SQuestRewardNetSc : public SRewardDB
	{
		TQuestSlotIndex SlotIndex{};
		int32 newCode{};
		system_clock::time_point CoolEndTime{};
		int32 DailyCompleteCount{};
		system_clock::time_point DailyCompleteRefreshTime{};
		SQuestRewardNetSc()
		{
		}
		SQuestRewardNetSc(const SRewardDB& Super_, const TQuestSlotIndex& SlotIndex_, const int32& newCode_, const system_clock::time_point& CoolEndTime_, const int32& DailyCompleteCount_, const system_clock::time_point& DailyCompleteRefreshTime_) : SRewardDB(Super_), SlotIndex(SlotIndex_), newCode(newCode_), CoolEndTime(CoolEndTime_), DailyCompleteCount(DailyCompleteCount_), DailyCompleteRefreshTime(DailyCompleteRefreshTime_)
		{
		}
		SQuestRewardNetSc(SRewardDB&& Super_, TQuestSlotIndex&& SlotIndex_, int32&& newCode_, system_clock::time_point&& CoolEndTime_, int32&& DailyCompleteCount_, system_clock::time_point&& DailyCompleteRefreshTime_) : SRewardDB(std::move(Super_)), SlotIndex(std::move(SlotIndex_)), newCode(std::move(newCode_)), CoolEndTime(std::move(CoolEndTime_)), DailyCompleteCount(std::move(DailyCompleteCount_)), DailyCompleteRefreshTime(std::move(DailyCompleteRefreshTime_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			SRewardDB::operator << (Stream_);
			Stream_ >> SlotIndex;
			Stream_ >> newCode;
			Stream_ >> CoolEndTime;
			Stream_ >> DailyCompleteCount;
			Stream_ >> DailyCompleteRefreshTime;
		}
		void operator << (const Value& Value_) override
		{
			SRewardDB::operator << (Value_);
			Value_["SlotIndex"] >> SlotIndex;
			Value_["newCode"] >> newCode;
			Value_["CoolEndTime"] >> CoolEndTime;
			Value_["DailyCompleteCount"] >> DailyCompleteCount;
			Value_["DailyCompleteRefreshTime"] >> DailyCompleteRefreshTime;
		}
		void operator >> (CStream& Stream_) const override
		{
			SRewardDB::operator >> (Stream_);
			Stream_ << SlotIndex;
			Stream_ << newCode;
			Stream_ << CoolEndTime;
			Stream_ << DailyCompleteCount;
			Stream_ << DailyCompleteRefreshTime;
		}
		void operator >> (Value& Value_) const override
		{
			SRewardDB::operator >> (Value_);
			Value_["SlotIndex"] = SlotIndex;
			Value_["newCode"] = newCode;
			Value_["CoolEndTime"] = CoolEndTime;
			Value_["DailyCompleteCount"] = DailyCompleteCount;
			Value_["DailyCompleteRefreshTime"] = DailyCompleteRefreshTime;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(SRewardDB()) + L"," + 
				GetStdName(TQuestSlotIndex()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(system_clock::time_point()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(system_clock::time_point());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(SRewardDB(), L"") + L"," + 
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
	struct SQuestDailyCompleteRewardNetSc : public SRewardDB
	{
		system_clock::time_point RefreshTime{};
		SQuestDailyCompleteRewardNetSc()
		{
		}
		SQuestDailyCompleteRewardNetSc(const SRewardDB& Super_, const system_clock::time_point& RefreshTime_) : SRewardDB(Super_), RefreshTime(RefreshTime_)
		{
		}
		SQuestDailyCompleteRewardNetSc(SRewardDB&& Super_, system_clock::time_point&& RefreshTime_) : SRewardDB(std::move(Super_)), RefreshTime(std::move(RefreshTime_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			SRewardDB::operator << (Stream_);
			Stream_ >> RefreshTime;
		}
		void operator << (const Value& Value_) override
		{
			SRewardDB::operator << (Value_);
			Value_["RefreshTime"] >> RefreshTime;
		}
		void operator >> (CStream& Stream_) const override
		{
			SRewardDB::operator >> (Stream_);
			Stream_ << RefreshTime;
		}
		void operator >> (Value& Value_) const override
		{
			SRewardDB::operator >> (Value_);
			Value_["RefreshTime"] = RefreshTime;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(SRewardDB()) + L"," + 
				GetStdName(system_clock::time_point());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(SRewardDB(), L"") + L"," + 
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
	struct SCouponUseNetSc : public SRewardDB
	{
		TResources ResourcesAdded{};
		SCouponUseNetSc()
		{
		}
		SCouponUseNetSc(const SRewardDB& Super_, const TResources& ResourcesAdded_) : SRewardDB(Super_), ResourcesAdded(ResourcesAdded_)
		{
		}
		SCouponUseNetSc(SRewardDB&& Super_, TResources&& ResourcesAdded_) : SRewardDB(std::move(Super_)), ResourcesAdded(std::move(ResourcesAdded_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			SRewardDB::operator << (Stream_);
			Stream_ >> ResourcesAdded;
		}
		void operator << (const Value& Value_) override
		{
			SRewardDB::operator << (Value_);
			Value_["ResourcesAdded"] >> ResourcesAdded;
		}
		void operator >> (CStream& Stream_) const override
		{
			SRewardDB::operator >> (Stream_);
			Stream_ << ResourcesAdded;
		}
		void operator >> (Value& Value_) const override
		{
			SRewardDB::operator >> (Value_);
			Value_["ResourcesAdded"] = ResourcesAdded;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(SRewardDB()) + L"," + 
				GetStdName(TResources());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(SRewardDB(), L"") + L"," + 
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
	struct SRankingRewardNetSc : public SRewardDB
	{
		int64 Counter{};
		TRankingRewardArray RankingRewardArray{};
		SRankingRewardNetSc()
		{
		}
		SRankingRewardNetSc(const SRewardDB& Super_, const int64& Counter_, const TRankingRewardArray& RankingRewardArray_) : SRewardDB(Super_), Counter(Counter_), RankingRewardArray(RankingRewardArray_)
		{
		}
		SRankingRewardNetSc(SRewardDB&& Super_, int64&& Counter_, TRankingRewardArray&& RankingRewardArray_) : SRewardDB(std::move(Super_)), Counter(std::move(Counter_)), RankingRewardArray(std::move(RankingRewardArray_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			SRewardDB::operator << (Stream_);
			Stream_ >> Counter;
			Stream_ >> RankingRewardArray;
		}
		void operator << (const Value& Value_) override
		{
			SRewardDB::operator << (Value_);
			Value_["Counter"] >> Counter;
			Value_["RankingRewardArray"] >> RankingRewardArray;
		}
		void operator >> (CStream& Stream_) const override
		{
			SRewardDB::operator >> (Stream_);
			Stream_ << Counter;
			Stream_ << RankingRewardArray;
		}
		void operator >> (Value& Value_) const override
		{
			SRewardDB::operator >> (Value_);
			Value_["Counter"] = Counter;
			Value_["RankingRewardArray"] = RankingRewardArray;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(SRewardDB()) + L"," + 
				GetStdName(int64()) + L"," + 
				GetStdName(TRankingRewardArray());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(SRewardDB(), L"") + L"," + 
				GetMemberName(int64(), L"Counter") + L"," + 
				GetMemberName(TRankingRewardArray(), L"RankingRewardArray");
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
