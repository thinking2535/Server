#include "stdafx.h"
#include <Rso/Win/ConsoleCtrlHandler.h>

using namespace rso;
using namespace win;

extern CConsoleCtrlHandler g_ConsoleCtrlHandler;

TMonitor g_Monitor;
TTimers g_Timers(TimersCallback);
CLog g_Log(ETarget::Target_Console | ETarget::Target_File, EPeriod::Day, L"Log/", L"Log", ELocale::Korean);
CPeriod<seconds> g_TimerPeriod = seconds(1);
TAuthNet  g_AuthNet;
TGameData g_MetaData;

void TimersCallback(wstring& Data_)
{
	g_ConsoleCtrlHandler.SetExit();
}