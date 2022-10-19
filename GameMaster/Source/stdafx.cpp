#include "stdafx.h"
#include <Rso/Win/ConsoleCtrlHandler.h>
#include <GameServer/Common/MetaProtocol.h>

using namespace rso;
using namespace win;

extern CConsoleCtrlHandler g_ConsoleCtrlHandler;

CMaster::TDBCallbacks g_BinderDB;
TRecvFuncs g_BinderRecvS;
TMonitor g_Monitor;
__int32 g_CCSSended = -1; // 최초 한번 보내기 위함
__int32 g_CCTSended = -1; // 최초 한번 보내기 위함
TNet g_Net;
TFCM g_FCM;
TTimers g_Timers(TimersCallback);
CLog g_Log(ETarget::Target_Console | ETarget::Target_File, EPeriod::Day, L"Log/", L"Log", ELocale::Korean);
CPeriod<seconds> g_FCMPeriod{ seconds(1) };
CPeriod<seconds> g_CCSLogPeriod{ seconds(30) };

void CloseS(TPeerCnt PeerNum_)
{
	g_Net->CloseS(PeerNum_);
}
void TimersCallback(wstring& Data_)
{
	g_ConsoleCtrlHandler.SetExit();
}
