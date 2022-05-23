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
#include <Rso/Game/Auth.h>
#include <Rso/GameUtil/OptionJson.h>
#include <Rso/Base/Timers.h>
#include <GameServer/Common/ServerToServerProtocol.h>
#include "Protocol.h"
#include <GameServer/Common/Base.h>

using namespace std;
using namespace rso;
using namespace monitor;
using namespace game;
using namespace gameutil;

using TMonitor = unique_ptr<CProc>;
using TAuthNet = unique_ptr<CAuth>;
using TOutObject = CAuth::TOutObject;
using TTimers = CTimers<wstring>;

extern TMonitor g_Monitor;
extern TTimers g_Timers;
extern CLog g_Log;
extern CPeriod<seconds> g_TimerPeriod;
extern TAuthNet  g_AuthNet;

#define LOG(...) g_Log.Push(GET_DEBUG_FORMAT(__VA_ARGS__))
#ifdef _DEBUG
#define DLOG(...) g_Log.Push(GET_DEBUG_FORMAT(__VA_ARGS__))
#else
#define DLOG(...) __noop(__VA_ARGS__)
#endif

void TimersCallback(wstring& Data_);