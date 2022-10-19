#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <optional>
#include <iostream>
#include <filesystem>
#include <Rso/Monitor/Proc.h>
#include <Rso/Net/ClientKeepConnect.h>
#include <Rso/Game/Server.h>
#include <Rso/Game/Client.h>
#include <Rso/GameUtil/OptionJson.h>
#include <Rso/Base/List.h>
#include <Rso/Base/Period.h>
#include <Rso/Base/Timers.h>
#include <Rso/Util/RandomGeometry.h>
#include <Rso/GameUtil/TimeSync.h>
#include <Rso/GameUtil/Rank.h>
#include <Rso/GameUtil/RandomBox.h>
#include <Rso/GameUtil/Timer.h>
#include <Rso/GameUtil/KeyCnt.h>
#include <Rso/GameUtil/Base.h>
#include <Rso/GameUtil/Command.h>
#include <Rso/GameUtil/Match.h>
#include <Rso/Physics/Physics.h>
#include <Rso/Physics/ServerEngine.h>

#include <Rso/MSSQL/BulkCopy.h>
#include <Rso/Net/IPInfo.h>
#include <Rso/MobileUtil/ReceiptCheck.h>
#include <GameServer/Common/Base.h>
#include <Rso/GameUtil/EloController.h>

using namespace std;
using namespace experimental::filesystem;
using namespace rso;
using namespace base;
using namespace monitor;
using namespace net;
using namespace game;
using namespace util;
using namespace gameutil;
using namespace base;
using namespace physics;
using namespace mobileutil;
using namespace net;
using namespace mssql;

#include "Protocol.h"
#include "../../GameMaster/Source/MasterProtocol.h"
#include "DBProtocol.h"
#include <GameServer/Common/ServerToServerProtocol.h>
#include "ToolProtocol.h"
#include "NetProtocolOperator.h"

#define LOG(...) g_Log.Push(GET_DEBUG_FORMAT(__VA_ARGS__))
#ifdef _DEBUG
#define DLOG(...) g_Log.Push(GET_DEBUG_FORMAT(__VA_ARGS__))
#else
#define DLOG(...) __noop(__VA_ARGS__)
#endif

namespace bb
{
	bool operator < (const SBattleType& Lhs_, const SBattleType& Rhs_);
}

struct ResourceTypeData;

struct SReward;
struct Quest;

class CCharacter;
struct SCharacterMeta;
class CQuest;
class ShopItem;
class ShopCharacter;
class CMetaData;

class CUser;
class CUsers;
class CBattlePlayer;
class CMultiBattlePlayer;
class CArrowDodgeBattlePlayer;
class CFlyAwayBattlePlayer;
class CBattle;
class CMultiBattle;
class CArrowDodgeBattle;
class CFlyAwayBattle;
class CArrow;
class CArrowDodgeItem;
class CArrowDodgeCoin;
class CArrowDodgeGoldBar;
class CArrowDodgeShield;
class CArrowDodgeStamina;
class CFlyAwayObject;
class CFlyAwayLand;
class CFlyAwayItem;
class CFlyAwayCoin;
class CFlyAwayGoldBar;

class CEngineGlobal;

class CEnginePumpControl;
class CEngineParachuteControl;
class CBattlePlayerObject;

class CEngineStructure;
class CEnginePlayer;

struct SArrowObject;
struct SArrowDodgeItemObject;

using TBattles = CList<unique_ptr<CBattle>>;
using TBattlesIt = TBattles::iterator;
using TMatch = unique_ptr<CMatch<TPeerCnt, SBattleType>>;
using TMatches = map<SBattleType, TMatch>;
using TMetaData = unique_ptr<CMetaData>;
using TServer = game::CServer;
using TSessionsIt = TServer::TSessionsIt;
using TRecvFuncs = CList<TRecvFunc>;
using TRecvCFunc = function<ERet(CUser*, CStream&)>;
using TRecvCFuncs = CList<TRecvCFunc>;
using TRecvSsFuncs = CList<TServer::TRecvSendToServerFunc>;
using TRecvRFunc = function<void(const CKey&, CStream&)>;
using TRecvRFuncs = CList<TRecvRFunc>;
using TReceiptCheck = unique_ptr<CReceiptCheck>;
using TOrder = CReceiptCheck::SOrder;
using TMonitor = unique_ptr<CProc>;
using TNet = unique_ptr<TServer>;
using TNetRanking = unique_ptr<net::CClientKeepConnect>;
using TOutObject = TServer::TOutObject;
using TUser = shared_ptr<CUser>;

using TBulkCopyConnect = unique_ptr<bulkcopy::CBulkCopy<SConnectDBIn>>;
using TTimers = CTimers<wstring>;
using TCommand = CCommand<CUser>;
using TQuests = map<EQuestType, int32>;
using TCouponSP = CStoredProcedure<CKey>;
using TCouponDB = unique_ptr<TCouponSP>;
using FQuestDone = function<void(EQuestType QuestType_, int32 Count_)>;

const TIndex c_Index_Null = -1;
const t_duration c_TicksForHour = hours(1);
const milliseconds c_NetworkDelayTimeSync = milliseconds(3000);
const milliseconds c_NetworkDelayBattleEnd = milliseconds(100000);
const seconds c_RegenDelay = seconds(2);
const minutes c_TimeError = minutes(1);

extern TMatches g_Matches;
extern TServer::TDBCallbacks g_BinderDB;
extern TRecvSsFuncs g_BinderRecvSessionHold;
extern TRecvFuncs g_BinderRecvM;
extern TRecvCFuncs g_BinderRecvC;
extern TRecvSsFuncs g_BinderRecvSs;
extern TRecvRFuncs g_BinderRecvR;
extern TReceiptCheck g_ReceiptCheck;
extern TMetaData g_MetaData;
extern TMonitor g_Monitor;
extern int32 g_CCUSended;
extern CKey g_MasterKey;
extern TNet g_Net;
extern CKey g_NetRankingKey;
extern TNetRanking g_NetRanking;
extern SRankingRankingInfoNetRs g_RankingInfo;
extern TTimers g_Timers;
extern CLog g_Log;
extern CUsers g_Users;
extern TCommand g_Command;
extern CPeriod<seconds> g_TimerPeriod;
extern CPeriod<milliseconds> g_BattlePeriod;
extern CPeriod<seconds> g_CCULogPeriod;
extern TBattles g_Battles;
extern TBulkCopyConnect g_BulkCopyConnect;
extern CIPInfo g_IPInfo;
extern SOption g_Option;
extern int32 g_MapIndex;
extern TCouponDB g_pCouponDB;
extern EloController eloController;

#include "Character.h"
#include "Quest.h"
#include "Shop.h"
#include "MetaData.h"
#include "Network.h"
#include "NetworkServerToServer.h"
#include "NetworkRanking.h"
#include "User.h"
#include "Users.h"
#include "DataBase.h"
#include "BattlePlayer.h"
#include "MultiBattlePlayer.h"
#include "ArrowDodgeBattlePlayer.h"
#include "FlyAwayBattlePlayer.h"
#include "Battle.h"
#include "MultiBattle.h"
#include "ArrowDodgeBattle.h"
#include "Arrow.h"
#include "ArrowDodgeItem.h"
#include "FlyAwayBattle.h"
#include "FlyAwayObject.h"
#include "FlyAwayLand.h"
#include "FlyAwayItem.h"

#include "EngineGlobal.h"
#include "EnginePumpControl.h"
#include "EngineParachuteControl.h"
#include "BattlePlayerObject.h"
#include "MetaProtocolExtension.h"

template<typename _TType> struct SBinder {};
template<> struct SBinder<SRetNetSc> { static const int32 ProtoNum = int32(EProtoNetSc::Ret); };
template<> struct SBinder<SMsgNetSc> { static const int32 ProtoNum = int32(EProtoNetSc::Msg); };
template<> struct SBinder<SLoginNetSc> { static const int32 ProtoNum = int32(EProtoNetSc::Login); };
template<> struct SBinder<SLobbyNetSc> { static const int32 ProtoNum = int32(EProtoNetSc::Lobby); };
template<> struct SBinder<SChatNetSc> { static const int32 ProtoNum = int32(EProtoNetSc::Chat); };
template<> struct SBinder<SUserExpNetSc> { static const int32 ProtoNum = int32(EProtoNetSc::UserExp); };
template<> struct SBinder<SResourcesNetSc> { static const int32 ProtoNum = int32(EProtoNetSc::Resources); };
template<> struct SBinder<SSetPointNetSc> { static const int32 ProtoNum = int32(EProtoNetSc::SetPoint); };
template<> struct SBinder<SSetCharNetSc> { static const int32 ProtoNum = int32(EProtoNetSc::SetChar); };
template<> struct SBinder<SUnsetCharNetSc> { static const int32 ProtoNum = int32(EProtoNetSc::UnsetChar); };
template<> struct SBinder<SBuyNetSc> { static const int32 ProtoNum = int32(EProtoNetSc::Buy); };
template<> struct SBinder<SBuyCharNetSc> { static const int32 ProtoNum = int32(EProtoNetSc::BuyChar); };
template<> struct SBinder<SBuyResourceNetSc> { static const int32 ProtoNum = int32(EProtoNetSc::BuyResource); };

template<> struct SBinder<SBattleSyncNetSc> { static const int32 ProtoNum = int32(EProtoNetSc::BattleSync); };
template<> struct SBinder<SBattleDirectNetSc> { static const int32 ProtoNum = int32(EProtoNetSc::BattleDirect); };
template<> struct SBinder<SBattleFlapNetSc> { static const int32 ProtoNum = int32(EProtoNetSc::BattleFlap); };
template<> struct SBinder<SBattlePumpNetSc> { static const int32 ProtoNum = int32(EProtoNetSc::BattlePump); };
template<> struct SBinder<SMultiBattleJoinNetSc> { static const int32 ProtoNum = int32(EProtoNetSc::MultiBattleJoin); };
template<> struct SBinder<SMultiBattleOutNetSc> { static const int32 ProtoNum = int32(EProtoNetSc::MultiBattleOut); };
template<> struct SBinder<SMultiBattleBeginNetSc> { static const int32 ProtoNum = int32(EProtoNetSc::MultiBattleBegin); };
template<> struct SBinder<SMultiBattleStartNetSc> { static const int32 ProtoNum = int32(EProtoNetSc::MultiBattleStart); };
template<> struct SBinder<SMultiBattleEndNetSc> { static const int32 ProtoNum = int32(EProtoNetSc::MultiBattleEnd); };
template<> struct SBinder<SMultiBattleEndDrawNetSc> { static const int32 ProtoNum = int32(EProtoNetSc::MultiBattleEndDraw); };
template<> struct SBinder<SMultiBattleEndInvalidNetSc> { static const int32 ProtoNum = int32(EProtoNetSc::MultiBattleEndInvalid); };
template<> struct SBinder<SMultiBattleIconNetSc> { static const int32 ProtoNum = int32(EProtoNetSc::MultiBattleIcon); };
template<> struct SBinder<SMultiBattleLinkNetSc> { static const int32 ProtoNum = int32(EProtoNetSc::MultiBattleLink); };
template<> struct SBinder<SMultiBattleUnLinkNetSc> { static const int32 ProtoNum = int32(EProtoNetSc::MultiBattleUnLink); };
template<> struct SBinder<SInvalidDisconnectInfoNetSc> { static const int32 ProtoNum = int32(EProtoNetSc::InvalidDisconnectInfo); };

template<> struct SBinder<SArrowDodgeBattleJoinNetSc> { static const int32 ProtoNum = int32(EProtoNetSc::ArrowDodgeBattleJoin); };
template<> struct SBinder<SArrowDodgeBattleBeginNetSc> { static const int32 ProtoNum = int32(EProtoNetSc::ArrowDodgeBattleBegin); };
template<> struct SBinder<SArrowDodgeBattleStartNetSc> { static const int32 ProtoNum = int32(EProtoNetSc::ArrowDodgeBattleStart); };
template<> struct SBinder<SArrowDodgeBattleEndNetSc> { static const int32 ProtoNum = int32(EProtoNetSc::ArrowDodgeBattleEnd); };

template<> struct SBinder<SFlyAwayBattleJoinNetSc> { static const int32 ProtoNum = int32(EProtoNetSc::FlyAwayBattleJoin); };
template<> struct SBinder<SFlyAwayBattleBeginNetSc> { static const int32 ProtoNum = int32(EProtoNetSc::FlyAwayBattleBegin); };
template<> struct SBinder<SFlyAwayBattleStartNetSc> { static const int32 ProtoNum = int32(EProtoNetSc::FlyAwayBattleStart); };
template<> struct SBinder<SFlyAwayBattleEndNetSc> { static const int32 ProtoNum = int32(EProtoNetSc::FlyAwayBattleEnd); };

template<> struct SBinder<SRankRewardNetSc> { static const int32 ProtoNum = int32(EProtoNetSc::RankReward); };
template<> struct SBinder<SQuestGotNetSc> { static const int32 ProtoNum = int32(EProtoNetSc::QuestGot); };
template<> struct SBinder<SQuestSetNetSc> { static const int32 ProtoNum = int32(EProtoNetSc::QuestSet); };
template<> struct SBinder<SQuestDoneNetSc> { static const int32 ProtoNum = int32(EProtoNetSc::QuestDone); };
template<> struct SBinder<SQuestRewardNetSc> { static const int32 ProtoNum = int32(EProtoNetSc::QuestReward); };
template<> struct SBinder<SQuestDailyCompleteRewardNetSc> { static const int32 ProtoNum = int32(EProtoNetSc::QuestDailyCompleteReward); };
template<> struct SBinder<SChangeNickNetSc> { static const int32 ProtoNum = int32(EProtoNetSc::ChangeNick); };
template<> struct SBinder<SChangeNickFailNetSc> { static const int32 ProtoNum = int32(EProtoNetSc::ChangeNickFail); };
template<> struct SBinder<SCouponUseNetSc> { static const int32 ProtoNum = int32(EProtoNetSc::CouponUse); };
template<> struct SBinder<SCouponUseFailNetSc> { static const int32 ProtoNum = int32(EProtoNetSc::CouponUseFail); };
template<> struct SBinder<SRankingRewardInfoNetSc> { static const int32 ProtoNum = int32(EProtoNetSc::RankingRewardInfo); };
template<> struct SBinder<SRankingRewardNetSc> { static const int32 ProtoNum = int32(EProtoNetSc::RankingReward); };
template<> struct SBinder<SRankingRewardFailNetSc> { static const int32 ProtoNum = int32(EProtoNetSc::RankingRewardFail); };


template<typename _TType> struct SBinderMaster {};
template<> struct SBinderMaster<SFCMTokenSetNetSm> { static const int32 ProtoNum = int32(EProtoNetSm::FCMTokenSet); };
template<> struct SBinderMaster<SFCMTokenUnsetNetSm> { static const int32 ProtoNum = int32(EProtoNetSm::FCMTokenUnset); };
template<> struct SBinderMaster<SFCMCanPushAtNightNetSm> { static const int32 ProtoNum = int32(EProtoNetSm::FCMCanPushAtNight); };
template<> struct SBinderMaster<SChangeLanguageNetSm> { static const int32 ProtoNum = int32(EProtoNetSm::ChangeLanguage); };

template<typename _TSP> struct SDBBinder {};
template<> struct SDBBinder<SJoinDBIn> { static const int32 SpNum = int32(EProtoDB::Join); };
template<> struct SDBBinder<SLoginDBIn> { static const int32 SpNum = int32(EProtoDB::Login); };
template<> struct SDBBinder<SLogoutDBIn> { static const int32 SpNum = int32(EProtoDB::Logout); };
template<> struct SDBBinder<SSetResourcesDBIn> { static const int32 SpNum = int32(EProtoDB::SetResources); };
template<> struct SDBBinder<SSetUserExpDBIn> { static const int32 SpNum = int32(EProtoDB::SetUserExp); };
template<> struct SDBBinder<SSetPointDBIn> { static const int32 SpNum = int32(EProtoDB::SetPoint); };
template<> struct SDBBinder<SSetCharDBIn> { static const int32 SpNum = int32(EProtoDB::SetChar); };
template<> struct SDBBinder<SUnsetCharDBIn> { static const int32 SpNum = int32(EProtoDB::UnsetChar); };
template<> struct SDBBinder<SCanPushAtNightDBIn> { static const int32 SpNum = int32(EProtoDB::CanPushAtNight); };
template<> struct SDBBinder<SChangeLanguageDBIn> { static const int32 SpNum = int32(EProtoDB::ChangeLanguage); };
template<> struct SDBBinder<SBuyDBIn> { static const int32 SpNum = int32(EProtoDB::Buy); };
template<> struct SDBBinder<SBuyCharDBIn> { static const int32 SpNum = int32(EProtoDB::BuyChar); };

template<> struct SDBBinder<SSelectCharDBIn> { static const int32 SpNum = int32(EProtoDB::SelectChar); };
template<> struct SDBBinder<SBattleEndDBIn> { static const int32 SpNum = int32(EProtoDB::BattleEnd); };
template<> struct SDBBinder<SUpdateInvalidDisconnectInfoDBIn> { static const int32 SpNum = int32(EProtoDB::UpdateInvalidDisconnectInfo); };
template<> struct SDBBinder<SUpdateMatchBlockEndTimeDBIn> { static const int32 SpNum = int32(EProtoDB::UpdateMatchBlockEndTime); };
template<> struct SDBBinder<SArrowDodgeBattleStartDBIn> { static const int32 SpNum = int32(EProtoDB::ArrowDodgeBattleStart); };
template<> struct SDBBinder<SArrowDodgeBattleEndDBIn> { static const int32 SpNum = int32(EProtoDB::ArrowDodgeBattleEnd); };
template<> struct SDBBinder<SFlyAwayBattleStartDBIn> { static const int32 SpNum = int32(EProtoDB::FlyAwayBattleStart); };
template<> struct SDBBinder<SFlyAwayBattleEndDBIn> { static const int32 SpNum = int32(EProtoDB::FlyAwayBattleEnd); };

template<> struct SDBBinder<SRankRewardDBIn> { static const int32 SpNum = int32(EProtoDB::RankReward); };
template<> struct SDBBinder<SQuestSetDBIn> { static const int32 SpNum = int32(EProtoDB::QuestSet); };
template<> struct SDBBinder<SQuestNewDBIn> { static const int32 SpNum = int32(EProtoDB::QuestNew); };
template<> struct SDBBinder<SQuestDelDBIn> { static const int32 SpNum = int32(EProtoDB::QuestDel); };
template<> struct SDBBinder<SQuestDoneDBIn> { static const int32 SpNum = int32(EProtoDB::QuestDone); };
template<> struct SDBBinder<SQuestRewardDBIn> { static const int32 SpNum = int32(EProtoDB::QuestReward); };
template<> struct SDBBinder<SQuestDailyCompleteRewardDBIn> { static const int32 SpNum = int32(EProtoDB::QuestDailyCompleteReward); };
template<> struct SDBBinder<SChangeNickBeginDBIn> { static const int32 SpNum = int32(EProtoDB::ChangeNickBegin); };
template<> struct SDBBinder<SChangeNickEndDBIn> { static const int32 SpNum = int32(EProtoDB::ChangeNickEnd); };
template<> struct SDBBinder<SChangeNickEndFailDBIn> { static const int32 SpNum = int32(EProtoDB::ChangeNickEndFail); };
template<> struct SDBBinder<SCouponUseDBIn> { static const int32 SpNum = int32(EProtoDB::CouponUse); };
template<> struct SDBBinder<STutorialRewardDBIn> { static const int32 SpNum = int32(EProtoDB::TutorialReward); };
template<> struct SDBBinder<SRankingRewardDBIn> { static const int32 SpNum = int32(EProtoDB::RankingReward); };

template<> struct SDBBinder<SCheckIDDBIn> { static const int32 SpNum = int32(EProtoDB::CheckID); };

template<typename _TProto, typename... _TProtos>
void SendM(const _TProto& Proto_, const _TProtos&... Protos_)
{
	g_Net->SendM(g_MasterKey, SBinderMaster<_TProto>::ProtoNum, Proto_, Protos_...);
}
template<typename _TProto, typename... _TProtos>
void SendMAll(const _TProto& Proto_, const _TProtos&... Protos_)
{
	g_Net->SendMAll(SBinderMaster<_TProto>::ProtoNum, Proto_, Protos_...);
}
template<typename _TProto, typename... _TProtos>
void Send(TPeerCnt PeerNum_, const _TProto& Proto_, const _TProtos&... Protos_)
{
	g_Net->Send(PeerNum_, int32(SBinder<_TProto>::ProtoNum), Proto_, Protos_...); // 컴파일 에러 때문에 int32 형변환
}
template<typename _TProto, typename... _TProtos>
void Send(const CKey& Key_, const _TProto& Proto_, const _TProtos&... Protos_)
{
	g_Net->Send(Key_, int32(SBinder<_TProto>::ProtoNum), Proto_, Protos_...); // 컴파일 에러 때문에 int32 형변환
}
template<typename _TProto, typename... _TProtos>
void SendAll(const _TProto& Proto_, const _TProtos&... Protos_)
{
	g_Net->SendAll(SBinder<_TProto>::ProtoNum, Proto_, Protos_...);
}
inline void Close(const CKey& Key_)
{
	g_Net->Close(Key_);
}
inline void WillClose(TPeerCnt PeerNum_)
{
	g_Net->WillClose(PeerNum_, milliseconds(5000));
}
inline void WillClose(const CKey& Key_)
{
	g_Net->WillClose(Key_, milliseconds(5000));
}

template<typename _TIn, typename _TOut>
void DBAddCmd(const wstring& SPName_, bool Return_, TServer::TDBCallback Callback_)
{
	g_Net->DBAddCmd<_TIn, _TOut>(SDBBinder<_TIn>::SpNum, SPName_, Return_);
	g_BinderDB.emplace_at(SDBBinder<_TIn>::SpNum, Callback_);
}

template<typename _TParam, typename... _TParams>
void DBPush(TSessionsIt itSession_, const CKey& Key_, const _TParam& Param_, const _TParams&... Params_)
{
	g_Net->DBPush(itSession_, SDBBinder<_TParam>::SpNum, Key_, Param_, Params_...);
}
template<typename _TParam, typename... _TParams>
void DBPush(const CKey& Key_, const _TParam& Param_, const _TParams&... Params_)
{
	g_Net->DBPush(SDBBinder<_TParam>::SpNum, Key_, Param_, Params_...);
}

template<typename _TProto>
void BroadCastAll(const _TProto& Proto_)
{
	for (auto& i : g_Users.get_users())
		i->second.User->Send(Proto_);
}
template<typename _TProto>
void BroadCastAllExcept(const _TProto& Proto_, TUID UID_)
{
	for (auto& i : g_Users.get_users())
	{
		if (i->GetUID() == UID_)
			continue;

		i->Send(Proto_);
	}
}
CUser* GetUser(const CKey& Key_);
void SendRet(const CKey& Key_, ERet Ret_);
void SendMsg(const CKey& Key_, const wstring& Msg_);

template<typename _TDuration>
TExp DurationToExp(const _TDuration& Duration_)
{
	auto Seconds = duration_cast<seconds>(Duration_);
	if (Seconds.count() <= 0)
		return 0;

	return TExp(sqrt(Seconds.count()));
}
bool doesHaveCost(const TResources& resources, const SResourceTypeData& cost);
bool doesHaveCost(const TResources& resources, EResource costType, TResource costValue);
bool doesHaveCost(const TResources& resources, const TResources& cost);
TResources getFullResources(void);

TResource getResourceFreeSpace(TResource currentResource, EResource resourceType);
TResource getResourceFreeSpace(TResource currentResource, size_t index);

void AddResource(TResources& Resources_, size_t Index_, TResource Data_);
void AddResource(TResources& Resources_, EResource Resource_, TResource Data_);
void AddResource(TResources& Resources_, const SResourceTypeData& ResourceTypeData_);

TResource AddResource(TResource Resource_, size_t Index_, TResource Data_);
TResource AddResource(TResource Resource_, EResource ResourceType_, TResource Data_);
TResource AddResource(TResource Resource_, const SResourceTypeData& ResourceTypeData_);

void AddResources(TResources& Resources_, const TResources& Added_);
void SetResource(TResources& Resources_, size_t Index_, TResource Data_);
void SetResource(TResources& Resources_, EResource Resource_, TResource Data_);
void SetResources(TResources& Resources_, const TResources& Set_);
void CheckResource(EResource resourceType, TResource resourceValue);
void CheckResourceTypeValue(const SResourceTypeData& Resource_);

void TimersCallback(wstring& Data_);
SLoginDBIn GetLoginDBIn(TUID UID_, const SUserLoginInfo& Info_);
ELocale LanguageToLocale(ELanguage Language_);

inline SRect GetCharRect(const SPoint& Pos_)
{
	return SRect();
}

inline float GetS(float Acc_, float Vel_, float Duration_)
{
	return 0.5f * Acc_ * Duration_ * Duration_ + Vel_ * Duration_;
}
float GetSOverMax(float Acc_, float Vel_, float MaxVel_, float Duration_);
bool canFlap(const SCharacter& character);
bool canPump(const SCharacter& character);
bool IsValidRankingInfo(void);
int32 GetAllMemberCount(const SBattleType& BattleType_);
bool IsOneOnOneBattle(const SBattleType& BattleType_);
bool IsMultiBattle(const SBattleType& BattleType_);
