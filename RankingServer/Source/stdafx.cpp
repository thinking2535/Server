#include "stdafx.h"
#include <Rso/Win/ConsoleCtrlHandler.h>

using namespace rso;
using namespace win;

extern CConsoleCtrlHandler g_ConsoleCtrlHandler;

TDB::element_type::TCallbacks g_BinderDB;
TMonitor g_Monitor;
TTimers g_Timers(TimersCallback);
CLog g_Log(ETarget::Target_Console | ETarget::Target_File, EPeriod::Day, L"Log/", L"Log", ELocale::Korean);
CPeriod<seconds> g_TimerPeriod = seconds(1);
CPeriod<seconds> g_RankingRefreshPeriod = seconds(10);
TNet g_Net; // for GameServer
TNetBalance g_NetBalance; // for Ranking Balance Group
__int32 g_MaxList = 0;
SRankingConfigDB g_RankingConfig;
TRankingMapArray g_RankingMapArray;
TRankingRewardsArray g_RewardsArray;
TDB g_DB;
TRecvCFuncs g_BinderRecvC;
TRecvSFuncs g_BinderRecvS;
TGameData g_GameData;
CDump g_Dump;

void TimersCallback(wstring& Data_)
{
	g_ConsoleCtrlHandler.SetExit();
}
