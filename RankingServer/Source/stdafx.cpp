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
TNet g_Net; // for GameServer
TNetBalance g_NetBalance; // for Ranking Balance Group
__int32 g_MaxList = 0;
SRankingConfigDB g_RankingConfig;
TRanking g_Ranking;
TRankingSingle g_RankingSingle;
TRankingIsland g_RankingIsland;
TRankingRewards g_Rewards;
TRankingRewards g_RewardsSingle;
TRankingRewards g_RewardsIsland;
TDB g_DB;
TRecvCFuncs g_BinderRecvC;
TRecvSFuncs g_BinderRecvS;
TGameData g_GameData;
CDump g_Dump;

void TimersCallback(wstring& Data_)
{
	g_ConsoleCtrlHandler.SetExit();
}
