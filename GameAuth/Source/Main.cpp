#include "stdafx.h"
#include <Rso/Win/ConsoleCtrlHandler.h>
#include <Rso/MobileUtil/ReceiptToken.h>
#include <GameServer/Common/GameServerProtocol.h>

using namespace mobileutil;

CConsoleCtrlHandler g_ConsoleCtrlHandler;
string g_FCMServerKey;
unique_ptr<CReceiptToken> g_Receipt;

void ReceiveAccessTokenCallback(const string& AccessToken_)
{
	g_AuthNet->SendMAll(SGameServerHeader(EGameServerProto::AmReceiveAccessToken), SAmReceiveAccessToken(AccessToken_));
}
void ReceiveAccessTokenFailCallback(const string& Msg_)
{
	LOG(MBSToWCS(Msg_));
}

void LinkAgent(const CKey& Key_)
{
	LOG(L"LinkAgent Key[%d]", Key_.PeerNum);
}
void UnLinkAgent(const CKey& Key_, ENetRet NetRet_)
{
	LOG(L"UnLinkAgent Key[%d]", Key_.PeerNum);
}

void CallbackUserProto(const CKey& ClientKey_, CStream& Stream_)
{
	LOG(L"CallbackUserProto");

	try
	{
		CStream Stream;
		Stream_ >> Stream;

		wstring Protocol;
		Stream >> Protocol;

		if (Protocol == L"PushMessage")
		{
			g_AuthNet->SendMAll(SGameServerHeader(EGameServerProto::AmPushMessage), Stream);
		}
		else if (Protocol == L"Punish")
		{
			TUID UID = 0;
			TTime EndTime;

			Stream >> UID;
			Stream >> EndTime;

			g_AuthNet->Punish(UID, EndTime);
		}
	}
	catch (...)
	{
	}
}
void CallbackStop(const wstring& Message_, const seconds& SecondLeft_)
{
	LOG(L"CallbackStop Message[%s] SecondLeft[%d]", Message_, SecondLeft_.count());
	g_Timers.emplace(SecondLeft_, Message_);
}
void CallbackMessage(const wstring& Message_)
{
	cout << "Message" << endl;
}

void DBCallback(TOutObject& OutObject_)
{
}
void LinkM(const CKey& Key_)
{
	g_AuthNet->SendM(Key_.PeerNum, SGameServerHeader(EGameServerProto::AmAuthInfo), SAmAuthInfo(g_FCMServerKey, g_Receipt->GetOption().PackageName, g_Receipt->GetAccessToken()));
	LOG(L"LinkM PeerNum:%d", Key_.PeerNum);
}
void UnLinkM(const CKey& Key_, ENetRet NetRet_)
{
	LOG(L"UnLinkM PeerNum:%d NetRet:%d", Key_.PeerNum, (__int32)NetRet_);
}
void RecvM(const CKey& Key_, CStream& Stream_)
{
	LOG(L"RecvM PeerNum:%d", Key_.PeerNum);
}
void LinkC(const CKey& Key_)
{
	DLOG(L"LinkC PeerNum:%d", Key_.PeerNum);
}
void UnLinkC(const CKey& Key_, ENetRet NetRet_)
{
	DLOG(L"UnLinkC PeerNum:%d NetRet:%d", Key_.PeerNum, (__int32)NetRet_);
}

int _tmain(int argc, _TCHAR* argv[])
{
	try
	{
		wcout.imbue(std::locale("korean"));

		LOG(L"Initializing");

		g_Receipt.reset(new CReceiptToken(1, L"OptionReceipt.ini", ReceiveAccessTokenCallback, ReceiveAccessTokenFailCallback));

		COptionJson<SOption> Option(L"Option.ini", false);
		COptionJson<SDBOption> DBOption(L"DBOption.ini", false);

		g_FCMServerKey = Option->FCMServerKey;

		wstring ProcName(MBSToWCS(
			Option->Title +
			" ClientBindPort:" + to_string(Option->ClientBindPort)));
		SetConsoleTitle(ProcName.c_str());

		g_Monitor.reset(
			new TMonitor::element_type(
				EAddressFamily::INET,
				LinkAgent, UnLinkAgent,
				CallbackUserProto,
				CallbackStop,
				CallbackMessage,
				ProcName,
				CNamePort(Option->MonitorAgentBindPort),
				wstring(L"{}")
			)
		);

		g_AuthNet.reset(new TAuthNet::element_type(
			EAddressFamily::INET,
			LinkM, UnLinkM, RecvM, LinkC, UnLinkC, DBCallback,
			*DBOption,
			CNamePort(Option->MasterBindPort),
			Option->NetCThreadCnt,
			CNamePort(Option->ClientBindPort)));

		g_AuthNet->Start();

		LOG(L"Initialized");

		while (!g_ConsoleCtrlHandler.GetExit())
		{
			g_Monitor->Proc();
			g_AuthNet->Proc();

			if (g_TimerPeriod.CheckAndNextLoose())
			{
				g_Timers.Proc();
				g_Receipt->Proc();
			}

			this_thread::sleep_for(milliseconds(1));
		}
	}
	catch (const SException& Exception_)
	{
		cout << Exception_.what() << endl;
	}

	return 0;
}
