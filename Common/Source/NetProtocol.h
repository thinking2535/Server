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
	const TVer c_Ver_Main = 38;
	const int32 c_FPS = 60;
	const int64 c_NetworkTickSync = 500000;
	const int64 c_NetworkTickBuffer = c_NetworkTickSync+500000;
	const float c_ContactOffset = 0.0001f;
	const float c_LandXDragPerFrame = 1.0f/c_FPS;
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
		Purchase,
		DailyReward,
		SelectChar,
		IslandStart,
		IslandEnd,
		BattleTouch,
		BattlePush,
		MultiBattleJoin,
		MultiBattleOut,
		MultiBattleIcon,
		ArrowDodgeBattleJoin,
		ArrowDodgeBattleEnd,
		Gacha,
		GachaX10,
		RankReward,
		QuestReward,
		QuestNext,
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
		Purchase,
		DailyReward,
		DailyRewardFail,
		IslandStart,
		IslandEnd,
		BattleSync,
		BattleTouch,
		BattlePush,
		MultiBattleJoin,
		MultiBattleOut,
		MultiBattleBegin,
		MultiBattleMatching,
		MultiBattleStart,
		MultiBattleEnd,
		MultiBattleIcon,
		MultiBattleLink,
		MultiBattleUnLink,
		ArrowDodgeBattleJoin,
		ArrowDodgeBattleBegin,
		ArrowDodgeBattleStart,
		ArrowDodgeBattleEnd,
		Gacha,
		GachaX10,
		GachaFailed,
		QuestGot,
		QuestDone,
		QuestReward,
		QuestNext,
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
	enum class ERankingType
	{
		Multi,
		Single,
		Island,
		Max,
		Null,
	};
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
		Dia,
		CP,
		DiaPaid,
		Max,
		Null,
	};
	using TResource = int32;
	using TResources = array<TResource,5>;
	enum class ERewardType : uint8
	{
		Resource_Ticket,
		Resource_Gold,
		Resource_Dia,
		Resource_CP,
		Character,
		Max,
	};
	enum class EQuestType
	{
		TeamPlay,
		TeamVictory,
		SurvivalPlay,
		SurvivalVictory,
		IngameConsecutiveKill,
		IngameBalloonPopping,
		IngameKill,
		IngameBestPlayer,
		GachaRuby,
		BlowBalloon,
		PlayNormal,
		PlayRare,
		PlayEpic,
		PlaySingle,
		SingleTime,
		SinglePlayGoldGet,
		SinglePlayScoreGet,
		PlayIsland,
		IslandCount,
		IslandGoldGet,
		IslandScoreGet,
		SurvivalPlayRanking,
		RankPointGet,
		SoloPlay,
		SoloVictory,
		Survival3PPlay,
		Survival3PVictory,
		MultiSinglePlay,
		MultiIslandPlay,
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
	struct SUserBase : public SUserCore
	{
		TExp Exp{};
		bool CanPushAtNight{};
		int32 Point{};
		int32 PointBest{};
		int32 LastGotRewardRankIndex{};
		int32 WinCountSolo{};
		int32 LoseCountSolo{};
		int32 WinCountSurvival{};
		int32 LoseCountSurvival{};
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
		bool IslandStarted{};
		int64 RankingRewardedCounter{};
		TNick NewNick{};
		SUserBase()
		{
		}
		SUserBase(const SUserCore& Super_, const TExp& Exp_, const bool& CanPushAtNight_, const int32& Point_, const int32& PointBest_, const int32& LastGotRewardRankIndex_, const int32& WinCountSolo_, const int32& LoseCountSolo_, const int32& WinCountSurvival_, const int32& LoseCountSurvival_, const int32& WinCountMulti_, const int32& LoseCountMulti_, const int32& BattlePointBest_, const int32& SinglePointBest_, const int32& IslandPointBest_, const int64& SingleBestTick_, const int32& IslandPassedCountBest_, const int32& KillTotal_, const int32& ChainKillTotal_, const int32& BlowBalloonTotal_, const int32& QuestDailyCompleteCount_, const bool& TutorialReward_, const bool& IslandStarted_, const int64& RankingRewardedCounter_, const TNick& NewNick_) : SUserCore(Super_), Exp(Exp_), CanPushAtNight(CanPushAtNight_), Point(Point_), PointBest(PointBest_), LastGotRewardRankIndex(LastGotRewardRankIndex_), WinCountSolo(WinCountSolo_), LoseCountSolo(LoseCountSolo_), WinCountSurvival(WinCountSurvival_), LoseCountSurvival(LoseCountSurvival_), WinCountMulti(WinCountMulti_), LoseCountMulti(LoseCountMulti_), BattlePointBest(BattlePointBest_), SinglePointBest(SinglePointBest_), IslandPointBest(IslandPointBest_), SingleBestTick(SingleBestTick_), IslandPassedCountBest(IslandPassedCountBest_), KillTotal(KillTotal_), ChainKillTotal(ChainKillTotal_), BlowBalloonTotal(BlowBalloonTotal_), QuestDailyCompleteCount(QuestDailyCompleteCount_), TutorialReward(TutorialReward_), IslandStarted(IslandStarted_), RankingRewardedCounter(RankingRewardedCounter_), NewNick(NewNick_)
		{
		}
		SUserBase(SUserCore&& Super_, TExp&& Exp_, bool&& CanPushAtNight_, int32&& Point_, int32&& PointBest_, int32&& LastGotRewardRankIndex_, int32&& WinCountSolo_, int32&& LoseCountSolo_, int32&& WinCountSurvival_, int32&& LoseCountSurvival_, int32&& WinCountMulti_, int32&& LoseCountMulti_, int32&& BattlePointBest_, int32&& SinglePointBest_, int32&& IslandPointBest_, int64&& SingleBestTick_, int32&& IslandPassedCountBest_, int32&& KillTotal_, int32&& ChainKillTotal_, int32&& BlowBalloonTotal_, int32&& QuestDailyCompleteCount_, bool&& TutorialReward_, bool&& IslandStarted_, int64&& RankingRewardedCounter_, TNick&& NewNick_) : SUserCore(std::move(Super_)), Exp(std::move(Exp_)), CanPushAtNight(std::move(CanPushAtNight_)), Point(std::move(Point_)), PointBest(std::move(PointBest_)), LastGotRewardRankIndex(std::move(LastGotRewardRankIndex_)), WinCountSolo(std::move(WinCountSolo_)), LoseCountSolo(std::move(LoseCountSolo_)), WinCountSurvival(std::move(WinCountSurvival_)), LoseCountSurvival(std::move(LoseCountSurvival_)), WinCountMulti(std::move(WinCountMulti_)), LoseCountMulti(std::move(LoseCountMulti_)), BattlePointBest(std::move(BattlePointBest_)), SinglePointBest(std::move(SinglePointBest_)), IslandPointBest(std::move(IslandPointBest_)), SingleBestTick(std::move(SingleBestTick_)), IslandPassedCountBest(std::move(IslandPassedCountBest_)), KillTotal(std::move(KillTotal_)), ChainKillTotal(std::move(ChainKillTotal_)), BlowBalloonTotal(std::move(BlowBalloonTotal_)), QuestDailyCompleteCount(std::move(QuestDailyCompleteCount_)), TutorialReward(std::move(TutorialReward_)), IslandStarted(std::move(IslandStarted_)), RankingRewardedCounter(std::move(RankingRewardedCounter_)), NewNick(std::move(NewNick_))
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
			Stream_ >> WinCountSurvival;
			Stream_ >> LoseCountSurvival;
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
			Stream_ >> IslandStarted;
			Stream_ >> RankingRewardedCounter;
			Stream_ >> NewNick;
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
			Value_["WinCountSurvival"] >> WinCountSurvival;
			Value_["LoseCountSurvival"] >> LoseCountSurvival;
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
			Value_["IslandStarted"] >> IslandStarted;
			Value_["RankingRewardedCounter"] >> RankingRewardedCounter;
			Value_["NewNick"] >> NewNick;
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
			Stream_ << WinCountSurvival;
			Stream_ << LoseCountSurvival;
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
			Stream_ << IslandStarted;
			Stream_ << RankingRewardedCounter;
			Stream_ << NewNick;
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
			Value_["WinCountSurvival"] = WinCountSurvival;
			Value_["LoseCountSurvival"] = LoseCountSurvival;
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
			Value_["IslandStarted"] = IslandStarted;
			Value_["RankingRewardedCounter"] = RankingRewardedCounter;
			Value_["NewNick"] = NewNick;
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
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int64()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(bool()) + L"," + 
				GetStdName(bool()) + L"," + 
				GetStdName(int64()) + L"," + 
				GetStdName(TNick());
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
				GetMemberName(int32(), L"WinCountSurvival") + L"," + 
				GetMemberName(int32(), L"LoseCountSurvival") + L"," + 
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
				GetMemberName(bool(), L"IslandStarted") + L"," + 
				GetMemberName(int64(), L"RankingRewardedCounter") + L"," + 
				GetMemberName(TNick(), L"NewNick");
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
	struct SBuyNetSc : public SProto
	{
		int32 Code{};
		SBuyNetSc()
		{
		}
		SBuyNetSc(const int32& Code_) : Code(Code_)
		{
		}
		SBuyNetSc(int32&& Code_) : Code(std::move(Code_))
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
	struct SBuyPackageNetSc : public SProto
	{
		int32 Code{};
		SBuyPackageNetSc()
		{
		}
		SBuyPackageNetSc(const int32& Code_) : Code(Code_)
		{
		}
		SBuyPackageNetSc(int32&& Code_) : Code(std::move(Code_))
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
	struct SPurchaseNetCs : public SProto
	{
		wstring ProductID{};
		wstring PurchaseToken{};
		SPurchaseNetCs()
		{
		}
		SPurchaseNetCs(const wstring& ProductID_, const wstring& PurchaseToken_) : ProductID(ProductID_), PurchaseToken(PurchaseToken_)
		{
		}
		SPurchaseNetCs(wstring&& ProductID_, wstring&& PurchaseToken_) : ProductID(std::move(ProductID_)), PurchaseToken(std::move(PurchaseToken_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> ProductID;
			Stream_ >> PurchaseToken;
		}
		void operator << (const Value& Value_) override
		{
			Value_["ProductID"] >> ProductID;
			Value_["PurchaseToken"] >> PurchaseToken;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << ProductID;
			Stream_ << PurchaseToken;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["ProductID"] = ProductID;
			Value_["PurchaseToken"] = PurchaseToken;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(wstring()) + L"," + 
				GetStdName(wstring());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(wstring(), L"ProductID") + L"," + 
				GetMemberName(wstring(), L"PurchaseToken");
		}
	};
	struct SPurchaseNetSc : public SProto
	{
		wstring ProductID{};
		TResource DiaPaidAdded{};
		SPurchaseNetSc()
		{
		}
		SPurchaseNetSc(const wstring& ProductID_, const TResource& DiaPaidAdded_) : ProductID(ProductID_), DiaPaidAdded(DiaPaidAdded_)
		{
		}
		SPurchaseNetSc(wstring&& ProductID_, TResource&& DiaPaidAdded_) : ProductID(std::move(ProductID_)), DiaPaidAdded(std::move(DiaPaidAdded_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> ProductID;
			Stream_ >> DiaPaidAdded;
		}
		void operator << (const Value& Value_) override
		{
			Value_["ProductID"] >> ProductID;
			Value_["DiaPaidAdded"] >> DiaPaidAdded;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << ProductID;
			Stream_ << DiaPaidAdded;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["ProductID"] = ProductID;
			Value_["DiaPaidAdded"] = DiaPaidAdded;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(wstring()) + L"," + 
				GetStdName(TResource());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(wstring(), L"ProductID") + L"," + 
				GetMemberName(TResource(), L"DiaPaidAdded");
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
	struct SIslandStartNetCs : public SProto
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
	struct SIslandStartNetSc : public SProto
	{
		TResource GoldCost{};
		int32 PlayCount{};
		system_clock::time_point RefreshTime{};
		TDoneQuests DoneQuests{};
		SIslandStartNetSc()
		{
		}
		SIslandStartNetSc(const TResource& GoldCost_, const int32& PlayCount_, const system_clock::time_point& RefreshTime_, const TDoneQuests& DoneQuests_) : GoldCost(GoldCost_), PlayCount(PlayCount_), RefreshTime(RefreshTime_), DoneQuests(DoneQuests_)
		{
		}
		SIslandStartNetSc(TResource&& GoldCost_, int32&& PlayCount_, system_clock::time_point&& RefreshTime_, TDoneQuests&& DoneQuests_) : GoldCost(std::move(GoldCost_)), PlayCount(std::move(PlayCount_)), RefreshTime(std::move(RefreshTime_)), DoneQuests(std::move(DoneQuests_))
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
	struct SIslandEndNetCs : public SProto
	{
		int32 PassedIslandCount{};
		TResource Gold{};
		TResource GoldAdded{};
		TResource DiaAdded{};
		SIslandEndNetCs()
		{
		}
		SIslandEndNetCs(const int32& PassedIslandCount_, const TResource& Gold_, const TResource& GoldAdded_, const TResource& DiaAdded_) : PassedIslandCount(PassedIslandCount_), Gold(Gold_), GoldAdded(GoldAdded_), DiaAdded(DiaAdded_)
		{
		}
		SIslandEndNetCs(int32&& PassedIslandCount_, TResource&& Gold_, TResource&& GoldAdded_, TResource&& DiaAdded_) : PassedIslandCount(std::move(PassedIslandCount_)), Gold(std::move(Gold_)), GoldAdded(std::move(GoldAdded_)), DiaAdded(std::move(DiaAdded_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> PassedIslandCount;
			Stream_ >> Gold;
			Stream_ >> GoldAdded;
			Stream_ >> DiaAdded;
		}
		void operator << (const Value& Value_) override
		{
			Value_["PassedIslandCount"] >> PassedIslandCount;
			Value_["Gold"] >> Gold;
			Value_["GoldAdded"] >> GoldAdded;
			Value_["DiaAdded"] >> DiaAdded;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << PassedIslandCount;
			Stream_ << Gold;
			Stream_ << GoldAdded;
			Stream_ << DiaAdded;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["PassedIslandCount"] = PassedIslandCount;
			Value_["Gold"] = Gold;
			Value_["GoldAdded"] = GoldAdded;
			Value_["DiaAdded"] = DiaAdded;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(int32()) + L"," + 
				GetStdName(TResource()) + L"," + 
				GetStdName(TResource()) + L"," + 
				GetStdName(TResource());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(int32(), L"PassedIslandCount") + L"," + 
				GetMemberName(TResource(), L"Gold") + L"," + 
				GetMemberName(TResource(), L"GoldAdded") + L"," + 
				GetMemberName(TResource(), L"DiaAdded");
		}
	};
	struct SIslandEndNetSc : public SProto
	{
		TDoneQuests DoneQuests{};
		SIslandEndNetSc()
		{
		}
		SIslandEndNetSc(const TDoneQuests& DoneQuests_) : DoneQuests(DoneQuests_)
		{
		}
		SIslandEndNetSc(TDoneQuests&& DoneQuests_) : DoneQuests(std::move(DoneQuests_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> DoneQuests;
		}
		void operator << (const Value& Value_) override
		{
			Value_["DoneQuests"] >> DoneQuests;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << DoneQuests;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["DoneQuests"] = DoneQuests;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(TDoneQuests());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(TDoneQuests(), L"DoneQuests");
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
		vector<SMultiBattleInfo> BattleInfos{};
		SBattleRecord Record{};
		vector<SCharacterNet> Characters{};
		system_clock::time_point EndTime{};
		int64 Tick{};
		vector<SStructMovePosition> StructMovePositions{};
		SMultiBattleBeginNetSc()
		{
		}
		SMultiBattleBeginNetSc(const SBattle& Super_, const vector<SBattlePlayer>& Players_, const vector<SMultiBattleInfo>& BattleInfos_, const SBattleRecord& Record_, const vector<SCharacterNet>& Characters_, const system_clock::time_point& EndTime_, const int64& Tick_, const vector<SStructMovePosition>& StructMovePositions_) : SBattle(Super_), Players(Players_), BattleInfos(BattleInfos_), Record(Record_), Characters(Characters_), EndTime(EndTime_), Tick(Tick_), StructMovePositions(StructMovePositions_)
		{
		}
		SMultiBattleBeginNetSc(SBattle&& Super_, vector<SBattlePlayer>&& Players_, vector<SMultiBattleInfo>&& BattleInfos_, SBattleRecord&& Record_, vector<SCharacterNet>&& Characters_, system_clock::time_point&& EndTime_, int64&& Tick_, vector<SStructMovePosition>&& StructMovePositions_) : SBattle(std::move(Super_)), Players(std::move(Players_)), BattleInfos(std::move(BattleInfos_)), Record(std::move(Record_)), Characters(std::move(Characters_)), EndTime(std::move(EndTime_)), Tick(std::move(Tick_)), StructMovePositions(std::move(StructMovePositions_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			SBattle::operator << (Stream_);
			Stream_ >> Players;
			Stream_ >> BattleInfos;
			Stream_ >> Record;
			Stream_ >> Characters;
			Stream_ >> EndTime;
			Stream_ >> Tick;
			Stream_ >> StructMovePositions;
		}
		void operator << (const Value& Value_) override
		{
			SBattle::operator << (Value_);
			Value_["Players"] >> Players;
			Value_["BattleInfos"] >> BattleInfos;
			Value_["Record"] >> Record;
			Value_["Characters"] >> Characters;
			Value_["EndTime"] >> EndTime;
			Value_["Tick"] >> Tick;
			Value_["StructMovePositions"] >> StructMovePositions;
		}
		void operator >> (CStream& Stream_) const override
		{
			SBattle::operator >> (Stream_);
			Stream_ << Players;
			Stream_ << BattleInfos;
			Stream_ << Record;
			Stream_ << Characters;
			Stream_ << EndTime;
			Stream_ << Tick;
			Stream_ << StructMovePositions;
		}
		void operator >> (Value& Value_) const override
		{
			SBattle::operator >> (Value_);
			Value_["Players"] = Players;
			Value_["BattleInfos"] = BattleInfos;
			Value_["Record"] = Record;
			Value_["Characters"] = Characters;
			Value_["EndTime"] = EndTime;
			Value_["Tick"] = Tick;
			Value_["StructMovePositions"] = StructMovePositions;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(SBattle()) + L"," + 
				GetStdName(vector<SBattlePlayer>()) + L"," + 
				GetStdName(vector<SMultiBattleInfo>()) + L"," + 
				GetStdName(SBattleRecord()) + L"," + 
				GetStdName(vector<SCharacterNet>()) + L"," + 
				GetStdName(system_clock::time_point()) + L"," + 
				GetStdName(int64()) + L"," + 
				GetStdName(vector<SStructMovePosition>());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(SBattle(), L"") + L"," + 
				GetMemberName(vector<SBattlePlayer>(), L"Players") + L"," + 
				GetMemberName(vector<SMultiBattleInfo>(), L"BattleInfos") + L"," + 
				GetMemberName(SBattleRecord(), L"Record") + L"," + 
				GetMemberName(vector<SCharacterNet>(), L"Characters") + L"," + 
				GetMemberName(system_clock::time_point(), L"EndTime") + L"," + 
				GetMemberName(int64(), L"Tick") + L"," + 
				GetMemberName(vector<SStructMovePosition>(), L"StructMovePositions");
		}
	};
	struct SMultiBattleMatchingNetSc : public SProto
	{
		int32 UserCount{};
		SMultiBattleMatchingNetSc()
		{
		}
		SMultiBattleMatchingNetSc(const int32& UserCount_) : UserCount(UserCount_)
		{
		}
		SMultiBattleMatchingNetSc(int32&& UserCount_) : UserCount(std::move(UserCount_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> UserCount;
		}
		void operator << (const Value& Value_) override
		{
			Value_["UserCount"] >> UserCount;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << UserCount;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["UserCount"] = UserCount;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(int32());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(int32(), L"UserCount");
		}
	};
	struct SMultiBattleStartNetSc : public SProto
	{
		system_clock::time_point EndTime{};
		SMultiBattleStartNetSc()
		{
		}
		SMultiBattleStartNetSc(const system_clock::time_point& EndTime_) : EndTime(EndTime_)
		{
		}
		SMultiBattleStartNetSc(system_clock::time_point&& EndTime_) : EndTime(std::move(EndTime_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> EndTime;
		}
		void operator << (const Value& Value_) override
		{
			Value_["EndTime"] >> EndTime;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << EndTime;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["EndTime"] = EndTime;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(system_clock::time_point());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(system_clock::time_point(), L"EndTime");
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
	struct SMultiBattleEndNetSc : public SProto
	{
		vector<SBattleEndPlayer> BattleEndPlayers{};
		TDoneQuests DoneQuests{};
		SMultiBattleEndNetSc()
		{
		}
		SMultiBattleEndNetSc(const vector<SBattleEndPlayer>& BattleEndPlayers_, const TDoneQuests& DoneQuests_) : BattleEndPlayers(BattleEndPlayers_), DoneQuests(DoneQuests_)
		{
		}
		SMultiBattleEndNetSc(vector<SBattleEndPlayer>&& BattleEndPlayers_, TDoneQuests&& DoneQuests_) : BattleEndPlayers(std::move(BattleEndPlayers_)), DoneQuests(std::move(DoneQuests_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> BattleEndPlayers;
			Stream_ >> DoneQuests;
		}
		void operator << (const Value& Value_) override
		{
			Value_["BattleEndPlayers"] >> BattleEndPlayers;
			Value_["DoneQuests"] >> DoneQuests;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << BattleEndPlayers;
			Stream_ << DoneQuests;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["BattleEndPlayers"] = BattleEndPlayers;
			Value_["DoneQuests"] = DoneQuests;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(vector<SBattleEndPlayer>()) + L"," + 
				GetStdName(TDoneQuests());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(vector<SBattleEndPlayer>(), L"BattleEndPlayers") + L"," + 
				GetMemberName(TDoneQuests(), L"DoneQuests");
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
		SMultiBattleUnLinkNetSc()
		{
		}
		SMultiBattleUnLinkNetSc(const int64& Tick_, const int32& PlayerIndex_) : Tick(Tick_), PlayerIndex(PlayerIndex_)
		{
		}
		SMultiBattleUnLinkNetSc(int64&& Tick_, int32&& PlayerIndex_) : Tick(std::move(Tick_)), PlayerIndex(std::move(PlayerIndex_))
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
		STransform Transform{};
		SPoint Velocity{};
		SArrow()
		{
		}
		SArrow(const STransform& Transform_, const SPoint& Velocity_) : Transform(Transform_), Velocity(Velocity_)
		{
		}
		SArrow(STransform&& Transform_, SPoint&& Velocity_) : Transform(std::move(Transform_)), Velocity(std::move(Velocity_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Transform;
			Stream_ >> Velocity;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Transform"] >> Transform;
			Value_["Velocity"] >> Velocity;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Transform;
			Stream_ << Velocity;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Transform"] = Transform;
			Value_["Velocity"] = Velocity;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(STransform()) + L"," + 
				GetStdName(SPoint());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(STransform(), L"Transform") + L"," + 
				GetMemberName(SPoint(), L"Velocity");
		}
	};
	struct SItem : public SProto
	{
		STransform Transform{};
		int32 ItemNumber{};
		SItem()
		{
		}
		SItem(const STransform& Transform_, const int32& ItemNumber_) : Transform(Transform_), ItemNumber(ItemNumber_)
		{
		}
		SItem(STransform&& Transform_, int32&& ItemNumber_) : Transform(std::move(Transform_)), ItemNumber(std::move(ItemNumber_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Transform;
			Stream_ >> ItemNumber;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Transform"] >> Transform;
			Value_["ItemNumber"] >> ItemNumber;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Transform;
			Stream_ << ItemNumber;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Transform"] = Transform;
			Value_["ItemNumber"] = ItemNumber;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(STransform()) + L"," + 
				GetStdName(int32());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(STransform(), L"Transform") + L"," + 
				GetMemberName(int32(), L"ItemNumber");
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
		uint64 RandomSeed{};
		int64 NextDownArrowTick{};
		int64 NextLeftArrowTick{};
		int64 NextRightArrowTick{};
		int64 NextItemTick{};
		vector<SArrow> Arrows{};
		vector<SItem> Items{};
		bool Started{};
		SArrowDodgeBattleBeginNetSc()
		{
		}
		SArrowDodgeBattleBeginNetSc(const SBattlePlayer& Player_, const SArrowDodgeBattleInfo& BattleInfo_, const SArrowDodgeBattleBufs& Bufs_, const SCharacterNet& Character_, const int64& Tick_, const uint64& RandomSeed_, const int64& NextDownArrowTick_, const int64& NextLeftArrowTick_, const int64& NextRightArrowTick_, const int64& NextItemTick_, const vector<SArrow>& Arrows_, const vector<SItem>& Items_, const bool& Started_) : Player(Player_), BattleInfo(BattleInfo_), Bufs(Bufs_), Character(Character_), Tick(Tick_), RandomSeed(RandomSeed_), NextDownArrowTick(NextDownArrowTick_), NextLeftArrowTick(NextLeftArrowTick_), NextRightArrowTick(NextRightArrowTick_), NextItemTick(NextItemTick_), Arrows(Arrows_), Items(Items_), Started(Started_)
		{
		}
		SArrowDodgeBattleBeginNetSc(SBattlePlayer&& Player_, SArrowDodgeBattleInfo&& BattleInfo_, SArrowDodgeBattleBufs&& Bufs_, SCharacterNet&& Character_, int64&& Tick_, uint64&& RandomSeed_, int64&& NextDownArrowTick_, int64&& NextLeftArrowTick_, int64&& NextRightArrowTick_, int64&& NextItemTick_, vector<SArrow>&& Arrows_, vector<SItem>&& Items_, bool&& Started_) : Player(std::move(Player_)), BattleInfo(std::move(BattleInfo_)), Bufs(std::move(Bufs_)), Character(std::move(Character_)), Tick(std::move(Tick_)), RandomSeed(std::move(RandomSeed_)), NextDownArrowTick(std::move(NextDownArrowTick_)), NextLeftArrowTick(std::move(NextLeftArrowTick_)), NextRightArrowTick(std::move(NextRightArrowTick_)), NextItemTick(std::move(NextItemTick_)), Arrows(std::move(Arrows_)), Items(std::move(Items_)), Started(std::move(Started_))
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
				GetStdName(uint64()) + L"," + 
				GetStdName(int64()) + L"," + 
				GetStdName(int64()) + L"," + 
				GetStdName(int64()) + L"," + 
				GetStdName(int64()) + L"," + 
				GetStdName(vector<SArrow>()) + L"," + 
				GetStdName(vector<SItem>()) + L"," + 
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
				GetMemberName(uint64(), L"RandomSeed") + L"," + 
				GetMemberName(int64(), L"NextDownArrowTick") + L"," + 
				GetMemberName(int64(), L"NextLeftArrowTick") + L"," + 
				GetMemberName(int64(), L"NextRightArrowTick") + L"," + 
				GetMemberName(int64(), L"NextItemTick") + L"," + 
				GetMemberName(vector<SArrow>(), L"Arrows") + L"," + 
				GetMemberName(vector<SItem>(), L"Items") + L"," + 
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
	struct SRanking : public SProto
	{
		TRankingUsers RankingUsers{};
		TRankingUsers RankingUserSingles{};
		TRankingUsers RankingUserIslands{};
		SRanking()
		{
		}
		SRanking(const TRankingUsers& RankingUsers_, const TRankingUsers& RankingUserSingles_, const TRankingUsers& RankingUserIslands_) : RankingUsers(RankingUsers_), RankingUserSingles(RankingUserSingles_), RankingUserIslands(RankingUserIslands_)
		{
		}
		SRanking(TRankingUsers&& RankingUsers_, TRankingUsers&& RankingUserSingles_, TRankingUsers&& RankingUserIslands_) : RankingUsers(std::move(RankingUsers_)), RankingUserSingles(std::move(RankingUserSingles_)), RankingUserIslands(std::move(RankingUserIslands_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> RankingUsers;
			Stream_ >> RankingUserSingles;
			Stream_ >> RankingUserIslands;
		}
		void operator << (const Value& Value_) override
		{
			Value_["RankingUsers"] >> RankingUsers;
			Value_["RankingUserSingles"] >> RankingUserSingles;
			Value_["RankingUserIslands"] >> RankingUserIslands;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << RankingUsers;
			Stream_ << RankingUserSingles;
			Stream_ << RankingUserIslands;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["RankingUsers"] = RankingUsers;
			Value_["RankingUserSingles"] = RankingUserSingles;
			Value_["RankingUserIslands"] = RankingUserIslands;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(TRankingUsers()) + L"," + 
				GetStdName(TRankingUsers()) + L"," + 
				GetStdName(TRankingUsers());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(TRankingUsers(), L"RankingUsers") + L"," + 
				GetMemberName(TRankingUsers(), L"RankingUserSingles") + L"," + 
				GetMemberName(TRankingUsers(), L"RankingUserIslands");
		}
	};
	struct SRankingUserPointMin : public SProto
	{
		int32 UserPointMin{};
		int32 UserPointMinSingle{};
		int32 UserPointMinIsland{};
		SRankingUserPointMin()
		{
		}
		SRankingUserPointMin(const int32& UserPointMin_, const int32& UserPointMinSingle_, const int32& UserPointMinIsland_) : UserPointMin(UserPointMin_), UserPointMinSingle(UserPointMinSingle_), UserPointMinIsland(UserPointMinIsland_)
		{
		}
		SRankingUserPointMin(int32&& UserPointMin_, int32&& UserPointMinSingle_, int32&& UserPointMinIsland_) : UserPointMin(std::move(UserPointMin_)), UserPointMinSingle(std::move(UserPointMinSingle_)), UserPointMinIsland(std::move(UserPointMinIsland_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> UserPointMin;
			Stream_ >> UserPointMinSingle;
			Stream_ >> UserPointMinIsland;
		}
		void operator << (const Value& Value_) override
		{
			Value_["UserPointMin"] >> UserPointMin;
			Value_["UserPointMinSingle"] >> UserPointMinSingle;
			Value_["UserPointMinIsland"] >> UserPointMinIsland;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << UserPointMin;
			Stream_ << UserPointMinSingle;
			Stream_ << UserPointMinIsland;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["UserPointMin"] = UserPointMin;
			Value_["UserPointMinSingle"] = UserPointMinSingle;
			Value_["UserPointMinIsland"] = UserPointMinIsland;
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
				GetMemberName(int32(), L"UserPointMin") + L"," + 
				GetMemberName(int32(), L"UserPointMinSingle") + L"," + 
				GetMemberName(int32(), L"UserPointMinIsland");
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
	struct SQuestRewardNetSc : public SProto
	{
		TQuestSlotIndex SlotIndex{};
		system_clock::time_point CoolEndTime{};
		int32 DailyCompleteCount{};
		system_clock::time_point DailyCompleteRefreshTime{};
		SQuestRewardNetSc()
		{
		}
		SQuestRewardNetSc(const TQuestSlotIndex& SlotIndex_, const system_clock::time_point& CoolEndTime_, const int32& DailyCompleteCount_, const system_clock::time_point& DailyCompleteRefreshTime_) : SlotIndex(SlotIndex_), CoolEndTime(CoolEndTime_), DailyCompleteCount(DailyCompleteCount_), DailyCompleteRefreshTime(DailyCompleteRefreshTime_)
		{
		}
		SQuestRewardNetSc(TQuestSlotIndex&& SlotIndex_, system_clock::time_point&& CoolEndTime_, int32&& DailyCompleteCount_, system_clock::time_point&& DailyCompleteRefreshTime_) : SlotIndex(std::move(SlotIndex_)), CoolEndTime(std::move(CoolEndTime_)), DailyCompleteCount(std::move(DailyCompleteCount_)), DailyCompleteRefreshTime(std::move(DailyCompleteRefreshTime_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> SlotIndex;
			Stream_ >> CoolEndTime;
			Stream_ >> DailyCompleteCount;
			Stream_ >> DailyCompleteRefreshTime;
		}
		void operator << (const Value& Value_) override
		{
			Value_["SlotIndex"] >> SlotIndex;
			Value_["CoolEndTime"] >> CoolEndTime;
			Value_["DailyCompleteCount"] >> DailyCompleteCount;
			Value_["DailyCompleteRefreshTime"] >> DailyCompleteRefreshTime;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << SlotIndex;
			Stream_ << CoolEndTime;
			Stream_ << DailyCompleteCount;
			Stream_ << DailyCompleteRefreshTime;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["SlotIndex"] = SlotIndex;
			Value_["CoolEndTime"] = CoolEndTime;
			Value_["DailyCompleteCount"] = DailyCompleteCount;
			Value_["DailyCompleteRefreshTime"] = DailyCompleteRefreshTime;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(TQuestSlotIndex()) + L"," + 
				GetStdName(system_clock::time_point()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(system_clock::time_point());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(TQuestSlotIndex(), L"SlotIndex") + L"," + 
				GetMemberName(system_clock::time_point(), L"CoolEndTime") + L"," + 
				GetMemberName(int32(), L"DailyCompleteCount") + L"," + 
				GetMemberName(system_clock::time_point(), L"DailyCompleteRefreshTime");
		}
	};
	struct SQuestNextNetCs : public SProto
	{
		TQuestSlotIndex SlotIndex{};
		SQuestNextNetCs()
		{
		}
		SQuestNextNetCs(const TQuestSlotIndex& SlotIndex_) : SlotIndex(SlotIndex_)
		{
		}
		SQuestNextNetCs(TQuestSlotIndex&& SlotIndex_) : SlotIndex(std::move(SlotIndex_))
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
	struct SQuestNextNetSc : public SProto
	{
		TQuestSlotIndex SlotIndex{};
		int32 NewCode{};
		SQuestNextNetSc()
		{
		}
		SQuestNextNetSc(const TQuestSlotIndex& SlotIndex_, const int32& NewCode_) : SlotIndex(SlotIndex_), NewCode(NewCode_)
		{
		}
		SQuestNextNetSc(TQuestSlotIndex&& SlotIndex_, int32&& NewCode_) : SlotIndex(std::move(SlotIndex_)), NewCode(std::move(NewCode_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> SlotIndex;
			Stream_ >> NewCode;
		}
		void operator << (const Value& Value_) override
		{
			Value_["SlotIndex"] >> SlotIndex;
			Value_["NewCode"] >> NewCode;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << SlotIndex;
			Stream_ << NewCode;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["SlotIndex"] = SlotIndex;
			Value_["NewCode"] = NewCode;
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
				GetMemberName(int32(), L"NewCode");
		}
	};
	struct SQuestDailyCompleteRewardNetCs : public SProto
	{
		bool WatchAd{};
		SQuestDailyCompleteRewardNetCs()
		{
		}
		SQuestDailyCompleteRewardNetCs(const bool& WatchAd_) : WatchAd(WatchAd_)
		{
		}
		SQuestDailyCompleteRewardNetCs(bool&& WatchAd_) : WatchAd(std::move(WatchAd_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> WatchAd;
		}
		void operator << (const Value& Value_) override
		{
			Value_["WatchAd"] >> WatchAd;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << WatchAd;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["WatchAd"] = WatchAd;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(bool());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(bool(), L"WatchAd");
		}
	};
	struct SQuestDailyCompleteRewardNetSc : public SProto
	{
		bool WatchAd{};
		system_clock::time_point RefreshTime{};
		SQuestDailyCompleteRewardNetSc()
		{
		}
		SQuestDailyCompleteRewardNetSc(const bool& WatchAd_, const system_clock::time_point& RefreshTime_) : WatchAd(WatchAd_), RefreshTime(RefreshTime_)
		{
		}
		SQuestDailyCompleteRewardNetSc(bool&& WatchAd_, system_clock::time_point&& RefreshTime_) : WatchAd(std::move(WatchAd_)), RefreshTime(std::move(RefreshTime_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> WatchAd;
			Stream_ >> RefreshTime;
		}
		void operator << (const Value& Value_) override
		{
			Value_["WatchAd"] >> WatchAd;
			Value_["RefreshTime"] >> RefreshTime;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << WatchAd;
			Stream_ << RefreshTime;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["WatchAd"] = WatchAd;
			Value_["RefreshTime"] = RefreshTime;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(bool()) + L"," + 
				GetStdName(system_clock::time_point());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(bool(), L"WatchAd") + L"," + 
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
	struct SCouponUseNetSc : public SRewardDB
	{
		SCouponUseNetSc()
		{
		}
		SCouponUseNetSc(const SRewardDB& Super_) : SRewardDB(Super_)
		{
		}
		SCouponUseNetSc(SRewardDB&& Super_) : SRewardDB(std::move(Super_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			SRewardDB::operator << (Stream_);
		}
		void operator << (const Value& Value_) override
		{
			SRewardDB::operator << (Value_);
		}
		void operator >> (CStream& Stream_) const override
		{
			SRewardDB::operator >> (Stream_);
		}
		void operator >> (Value& Value_) const override
		{
			SRewardDB::operator >> (Value_);
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(SRewardDB());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(SRewardDB(), L"");
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
	using TRankingRewards = map<TUID,int32>;
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
		int32 Ranking{};
		int32 RankingSingle{};
		int32 RankingIsland{};
		SRankingRewardInfoNetSc()
		{
		}
		SRankingRewardInfoNetSc(const int64& Counter_, const int32& Ranking_, const int32& RankingSingle_, const int32& RankingIsland_) : Counter(Counter_), Ranking(Ranking_), RankingSingle(RankingSingle_), RankingIsland(RankingIsland_)
		{
		}
		SRankingRewardInfoNetSc(int64&& Counter_, int32&& Ranking_, int32&& RankingSingle_, int32&& RankingIsland_) : Counter(std::move(Counter_)), Ranking(std::move(Ranking_)), RankingSingle(std::move(RankingSingle_)), RankingIsland(std::move(RankingIsland_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Counter;
			Stream_ >> Ranking;
			Stream_ >> RankingSingle;
			Stream_ >> RankingIsland;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Counter"] >> Counter;
			Value_["Ranking"] >> Ranking;
			Value_["RankingSingle"] >> RankingSingle;
			Value_["RankingIsland"] >> RankingIsland;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Counter;
			Stream_ << Ranking;
			Stream_ << RankingSingle;
			Stream_ << RankingIsland;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Counter"] = Counter;
			Value_["Ranking"] = Ranking;
			Value_["RankingSingle"] = RankingSingle;
			Value_["RankingIsland"] = RankingIsland;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(int64()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(int64(), L"Counter") + L"," + 
				GetMemberName(int32(), L"Ranking") + L"," + 
				GetMemberName(int32(), L"RankingSingle") + L"," + 
				GetMemberName(int32(), L"RankingIsland");
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
	struct SRankingRewardNetSc : public SProto
	{
		int64 Counter{};
		int32 RewardCode{};
		int32 RewardCodeSingle{};
		int32 RewardCodeIsland{};
		SRankingRewardNetSc()
		{
		}
		SRankingRewardNetSc(const int64& Counter_, const int32& RewardCode_, const int32& RewardCodeSingle_, const int32& RewardCodeIsland_) : Counter(Counter_), RewardCode(RewardCode_), RewardCodeSingle(RewardCodeSingle_), RewardCodeIsland(RewardCodeIsland_)
		{
		}
		SRankingRewardNetSc(int64&& Counter_, int32&& RewardCode_, int32&& RewardCodeSingle_, int32&& RewardCodeIsland_) : Counter(std::move(Counter_)), RewardCode(std::move(RewardCode_)), RewardCodeSingle(std::move(RewardCodeSingle_)), RewardCodeIsland(std::move(RewardCodeIsland_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Counter;
			Stream_ >> RewardCode;
			Stream_ >> RewardCodeSingle;
			Stream_ >> RewardCodeIsland;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Counter"] >> Counter;
			Value_["RewardCode"] >> RewardCode;
			Value_["RewardCodeSingle"] >> RewardCodeSingle;
			Value_["RewardCodeIsland"] >> RewardCodeIsland;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Counter;
			Stream_ << RewardCode;
			Stream_ << RewardCodeSingle;
			Stream_ << RewardCodeIsland;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Counter"] = Counter;
			Value_["RewardCode"] = RewardCode;
			Value_["RewardCodeSingle"] = RewardCodeSingle;
			Value_["RewardCodeIsland"] = RewardCodeIsland;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(int64()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(int64(), L"Counter") + L"," + 
				GetMemberName(int32(), L"RewardCode") + L"," + 
				GetMemberName(int32(), L"RewardCodeSingle") + L"," + 
				GetMemberName(int32(), L"RewardCodeIsland");
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
