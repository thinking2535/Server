// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 및 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>

#include <iostream>
#include <Rso/Monitor/Proc.h>
#include <Rso/MSSQL/BulkSelect.h>
#include <Rso/MSSQL/StoredProcedure.h>
#include <Rso/Net/Server.h>
#include <Rso/Balance/Server.h>
#include <Rso/GameUtil/OptionJson.h>
#include <Rso/Base/Timers.h>
#include <Rso/Base/MultiIndexMap.h>
#include <GameServer/Common/NetProtocol.h>

#include <GameServer/Common/ServerToServerProtocol.h>
#include "Protocol.h"
#include <GameServer/Common/Base.h>
#include <Rso/Dump/Dump.h>


using namespace std;
using namespace rso;
using namespace monitor;
using namespace mssql;
using namespace net;
using namespace balance;
using namespace gameutil;
using namespace bb;
using namespace dump;

#define LOG(...) g_Log.Push(GET_DEBUG_FORMAT(__VA_ARGS__))
#ifdef _DEBUG
#define DLOG(...) g_Log.Push(GET_DEBUG_FORMAT(__VA_ARGS__))
#else
#define DLOG(...) __noop(__VA_ARGS__)
#endif

class CGameData;

using TMonitor = unique_ptr<CProc>;
using TNet = unique_ptr<net::CServer>;
using TNetBalance = unique_ptr<balance::CServer>;
using TTimers = CTimers<wstring>;
using TRanking = CMultiIndexMap<SRankingUserCore, unique_index<TUID>, non_unique_index<__int32, greater<__int32>>>; // UID, Point
using TRankingSingle = CMultiIndexMap<SRankingUserSingleCore, unique_index<TUID>, non_unique_index<__int32, greater<__int32>>>; // UID, Point
using TRankingIsland = CMultiIndexMap<SRankingUserIslandCore, unique_index<TUID>, non_unique_index<__int32, greater<__int32>>>; // UID, Point
using TDB = unique_ptr<CStoredProcedure<int>>;
using TOutObject = TDB::element_type::SOutObject;
using TRecvCFunc = function<void(const CKey&, CStream&)>;
using TRecvCFuncs = CList<TRecvCFunc>;
using TRecvSFunc = function<void(const CKey&, CStream&)>;
using TRecvSFuncs = CList<TRecvSFunc>;
using TGameData = unique_ptr<CGameData>;

extern TDB::element_type::TCallbacks g_BinderDB;
extern TMonitor g_Monitor;
extern TTimers g_Timers;
extern CLog g_Log;
extern CPeriod<seconds> g_TimerPeriod;
extern TNet g_Net;
extern TNetBalance g_NetBalance;
extern __int32 g_MaxList;
extern SRankingConfigDB g_RankingConfig;
extern TRanking g_Ranking;
extern TRankingSingle g_RankingSingle;
extern TRankingIsland g_RankingIsland;
extern TRankingRewards g_Rewards;
extern TRankingRewards g_RewardsSingle;
extern TRankingRewards g_RewardsIsland;
extern TDB g_DB;
extern TRecvCFuncs g_BinderRecvC;
extern TRecvSFuncs g_BinderRecvS;
extern TGameData g_GameData;

#include "GameData.h"
#include "Network.h"
#include "NetworkServer.h"
#include "DataBase.h"

template<typename _TSP> struct SDBBinder {};
template<> struct SDBBinder<SRankingConfigLoadDBIn> { static const __int32 SpNum = __int32(EProtoRankingDB::RankingConfigLoad); };
template<> struct SDBBinder<SRankingRefreshDBIn> { static const __int32 SpNum = __int32(EProtoRankingDB::RankingRefresh); };
template<> struct SDBBinder<SRankingUpdateDBIn> { static const __int32 SpNum = __int32(EProtoRankingDB::RankingUpdate); };
template<> struct SDBBinder<SRankingUpdateSingleDBIn> { static const __int32 SpNum = __int32(EProtoRankingDB::RankingUpdateSingle); };
template<> struct SDBBinder<SRankingUpdateIslandDBIn> { static const __int32 SpNum = __int32(EProtoRankingDB::RankingUpdateIsland); };

template<typename _TIn, typename _TOut>
void DBAddCmd(const wstring& SPName_, bool Return_, TDB::element_type::TCallback Callback_)
{
	g_DB->AddCmd<_TIn, _TOut>(SDBBinder<_TIn>::SpNum, SPName_, Return_);
	g_BinderDB.emplace_at(SDBBinder<_TIn>::SpNum, Callback_);
}
template<typename _TParam, typename... _TParams>
void DBPush(const _TParam& Param_, const _TParams&... Params_)
{
	g_DB->Push(SDBBinder<_TParam>::SpNum, 0, Param_, Params_...);
}

void TimersCallback(wstring& Data_);
