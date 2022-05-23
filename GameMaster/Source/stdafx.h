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
#include <Rso/Game/Master.h>
#include <Rso/MobileUtil/FCMServer.h>
#include <Rso/Base/Timers.h>
#include <Rso/GameUtil/Timer.h>
#include <Rso/GameUtil/OptionJson.h>
#include "MasterProtocol.h"
#include "Protocol.h"
#include <GameServer/Common/Base.h>

using namespace std;
using namespace rso;
using namespace monitor;
using namespace game;
using namespace mobileutil;
using namespace mssql;
using namespace gameutil;

using TRecvFuncs = CList<TRecvFunc>;
using TMonitor = unique_ptr<CProc>;
using TNet = unique_ptr<CMaster>;
using TFCM = unique_ptr<CFCMServer>;
using TOutObject = CMaster::TOutObject;
using TTimers = CTimers<wstring>;

const minutes c_GuardTimer15MinDelay = minutes(15);

extern CMaster::TDBCallbacks g_BinderDB;
extern TRecvFuncs g_BinderRecvS;
extern TMonitor g_Monitor;
extern __int32 g_CCSSended;
extern __int32 g_CCTSended;
extern TNet g_Net;
extern TFCM g_FCM;
extern TTimers g_Timers;
extern CLog g_Log;
extern CPeriod<seconds> g_FCMPeriod;
extern CPeriod<seconds> g_CCSLogPeriod;

#define LOG(...) g_Log.Push(GET_DEBUG_FORMAT(__VA_ARGS__))
#ifdef _DEBUG
#define DLOG(...) g_Log.Push(GET_DEBUG_FORMAT(__VA_ARGS__))
#else
#define DLOG(...) __noop(__VA_ARGS__)
#endif

#include "Network.h"

template<typename _TType> struct SBinder {};
template<> struct SBinder<SReceiptInitializeNetMs> { static const __int32 ProtoNum = __int32(EProtoNetMs::ReceiptInitialize); };
template<> struct SBinder<SReceiptAccessTokenNetMs> { static const __int32 ProtoNum = __int32(EProtoNetMs::ReceiptAccessToken); };

template<typename _TSP> struct SDBBinder {};
//template<> struct SDBBinder<SJoinDBIn> { static const __int32 SPNum = __int32(EProtoDB::Join); };

void CloseS(TPeerCnt PeerNum_);
template<typename _TProto, typename... _TProtos>
void SendS(const CKey& Key_, const _TProto& Proto_, const _TProtos&... Protos_)
{
	g_Net->SendS(Key_.PeerNum, __int32(SBinder<_TProto>::ProtoNum), Proto_, Protos_...); // 컴파일 에러나기 때문에 __int32 형변환
}
template<typename _TProto, typename... _TProtos>
void SendSAll(const _TProto& Proto_, const _TProtos& ... Protos_)
{
	g_Net->SendSAll(__int32(SBinder<_TProto>::ProtoNum), Proto_, Protos_...);
}

template<typename _TIn, typename _TOut>
void DBAddCmd(const wstring& SPName_, const wstring& Param_, bool Return_, CMaster::TDBCallback Callback_)
{
	g_Net->DBAddCmd<_TIn, _TOut>(SDBBinder<_TIn>::SPNum, SPName_, Param_, Return_);
	g_BinderDB.emplace_at(SDBBinder<_TIn>::SPNum, Callback_);
}

template<typename _TIn>
void DBPush(const _TIn& Data_)
{
	g_Net->DBPush(SDBBinder<_TIn>::SPNum, Data_);
}

void TimersCallback(wstring& Data_);
