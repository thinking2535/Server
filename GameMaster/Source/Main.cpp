#include "stdafx.h"
#include "Network.h"
#include <Rso/Core/Core.h>
#include <Rso/Win/ConsoleCtrlHandler.h>
#include <GameServer/Common/MetaProtocol.h>
#include <GameServer/Common/GameServerProtocol.h>

using namespace rso;
using namespace core;
using namespace win;

CConsoleCtrlHandler g_ConsoleCtrlHandler;
string g_FCMServerKey;
string g_ReceiptPackageName;
string g_ReceiptAccessToken;

void DBCallback(TOutObject& OutObject_)
{
	g_BinderDB[OutObject_.SPNum](OutObject_);
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
	cout << "UserProto" << endl;
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

void LinkA(const CKey& Key_)
{
	LOG(L"LinkA PeerNum:%d", Key_.PeerNum);
}
void LinkFailA(TPeerCnt PeerNum_, ENetRet NetRet_)
{
	LOG(L"LinkFailA PeerNum:%d NetRet:%d", PeerNum_, (__int32)NetRet_);
}
void UnLinkA(const CKey& Key_, ENetRet NetRet_)
{
	LOG(L"UnLinkA PeerNum:%d NetRet:%d", Key_.PeerNum, (__int32)NetRet_);
}
void RecvA(const CKey& Key_, CStream& Stream_)
{
	LOG(L"RecvA PeerNum:%d", Key_.PeerNum);

	SGameServerHeader Header;
	Stream_ >> Header;

	switch (Header.Proto)
	{
	case EGameServerProto::AmAuthInfo:
	{
		SAmAuthInfo Proto;
		Stream_ >> Proto;

		g_FCMServerKey = Proto.FCMServerKey;
		g_ReceiptPackageName = Proto.ReceiptPackageName;
		g_ReceiptAccessToken = Proto.ReceiptAccessToken;
		SendSAll(SReceiptInitializeNetMs(g_ReceiptPackageName, g_ReceiptAccessToken));
		break;
	}
	case EGameServerProto::AmReceiveAccessToken:
	{
		SAmReceiveAccessToken Proto;
		Stream_ >> Proto;

		g_ReceiptAccessToken = Proto.Token;
		SendSAll(SReceiptAccessTokenNetMs(g_ReceiptAccessToken));
		break;
	}
	case EGameServerProto::AmPushMessage:
	{
		if (g_FCM)
		{
			// for push message only
			try
			{
				CStream Stream;
				Stream_ >> Stream;

				wstring Title;
				Stream >> Title;

				wstring Msg;
				Stream >> Msg;

				g_FCM->PushAll(WStringToUTF8(Title), WStringToUTF8(Msg));
			}
			catch (...)
			{
			}
		}
		break;
	}
	}
}
void LinkS(const CKey& Key_)
{
	LOG(L"LinkS PeerNum:%d", Key_.PeerNum);

	if (g_ReceiptAccessToken.empty())
		CloseS(Key_.PeerNum);
	else
		SendS(Key_, SReceiptInitializeNetMs(g_ReceiptPackageName, g_ReceiptAccessToken));
}
void UnLinkS(const CKey& Key_, ENetRet NetRet_)
{
	LOG(L"UnLinkS PeerNum:%d NetRet:%d", Key_.PeerNum, (__int32)NetRet_);
}
void RecvS(const CKey& Key_, CStream& Stream_)
{
	LOG(L"RecvS PeerNum:%d", Key_.PeerNum);

	__int32 ProtoNum = 0;
	Stream_ >> ProtoNum;

	auto itRecv = g_BinderRecvS.get(ProtoNum);
	if (!itRecv)
		throw 0;

	(*itRecv)(Key_, Stream_);
}
void LinkC(const CKey& Key_)
{
	DLOG(L"LinkC PeerNum:%d", Key_.PeerNum);
}
void UnLinkC(const CKey& Key_, ENetRet NetRet_)
{
	DLOG(L"UnLinkC PeerNum:%d NetRet:%d", Key_.PeerNum, (__int32)NetRet_);
}
void SessionBegin(TPeerCnt ServerNum_, TUID UID_)
{
	DLOG(L"SessionBegin ServerNum:%d UID:%d", ServerNum_, UID_);
}
void SessionEnd(TPeerCnt ServerNum_, TUID UID_)
{
	DLOG(L"SessionEnd ServerNum:%d UID:%d", ServerNum_, UID_);
}
void RecvPunish(TUID UID_, const TTime& EndTime_)
{
	// 라이브러리에 포함시킬것
	//auto itUser = g_Users.find(UID_);
	//if (itUser == g_Users.end())
	//	return;

	//itUser->second.PunishEndTime = EndTime_;
	LOG(L"RecvPunish UID:%d", UID_);
}

int _tmain(int argc, _TCHAR* argv[])
{
	try
	{
		wcout.imbue(std::locale("korean"));

		LOG(L"Loading Option.ini");
		COptionJson<SOption> Option(L"Option.ini", false);

		LOG(L"Loading DBOption.ini");
		COptionJson<SDBOption> DBOption(L"DBOption.ini", false);

		LOG(L"Loading FCMOption.ini");
		COptionJson<SDBOption> FCMOption(L"FCMOption.ini", false);

		wstring ProcName(MBSToWCS(
			Option->Title +
			" ClientBindPort:" + to_string(Option->ClientBindPort)));
		SetConsoleTitle(ProcName.c_str());

		LOG(L"Initializing Monitor");
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

		LOG(L"Initializing Master");
		g_Net.reset(new TNet::element_type(
			EAddressFamily::INET,
			LinkA, LinkFailA, UnLinkA, RecvA, LinkS, UnLinkS, RecvS, LinkC, UnLinkC, SessionBegin, SessionEnd, RecvPunish, DBCallback,
			TRangeUID(Option->MinUID, Option->MaxUID),
			*DBOption,
			CNamePort(Option->AuthNamePort),
			CNamePort(Option->ServerBindPort),
			Option->NetCThreadCnt,
			CNamePort(Option->ClientBindPort),
			CNamePort(Option->ClientBindNamePortPub),
			Option->MasterBindPort));

		g_BinderRecvS.emplace_at((size_t)EProtoNetSm::FCMTokenSet, FCMTokenSetNetSm);
		g_BinderRecvS.emplace_at((size_t)EProtoNetSm::FCMTokenUnset, FCMTokenUnsetNetSm);
		g_BinderRecvS.emplace_at((size_t)EProtoNetSm::FCMCanPushAtNight, FCMCanPushAtNightNetSm);

		LOG(L"Starting Network");
		g_Net->Start();

		LOG(L"Starting Receipt");
		// 영수증 초기화 안되었으면 메인 루프로 진입하지 않도록
		while (Option->EnableReceipt && g_ReceiptAccessToken.empty())
		{
			if (g_ConsoleCtrlHandler.GetExit())
				THROWEXA(L"ConsoleCtrlHandler Exit");

			g_Net->Proc();
			g_Monitor->Proc();
			g_Timers.Proc();
			this_thread::sleep_for(milliseconds(500));
		}

		LOG(L"Initialized");

		while (!g_ConsoleCtrlHandler.GetExit())
		{
			g_Monitor->Proc();
			g_Net->Proc();

			if (g_FCMPeriod.CheckAndNextLoose())
			{
				if (g_Net->GetSessionCnt() != g_CCSSended)
				{
					g_CCSSended = (__int32)g_Net->GetSessionCnt();
					g_Monitor->SetStat(SKeyData(L"CCS", to_wstring(g_CCSSended)));
				}

				if (g_FCM && g_FCM->GetCCT() != g_CCTSended)
				{
					g_CCTSended = g_FCM->GetCCT();
					g_Monitor->SetStat(SKeyData(L"CCT", to_wstring(g_CCTSended)));
				}

				if (g_CCSLogPeriod.CheckAndNextLoose())
					LOG(L"CCS [%d] CCT [%d]", g_CCSSended, g_CCTSended);

				g_Timers.Proc();

				if (g_FCM) // FCM 이 초기화 되지 않으면 여기 안 들어오도록 할 수 있지만 그것역시 코드가 늘어나고, 이 코드는 g_FCMPeriod 주기마다 실행되므로 그냥 이렇게
				{
					g_FCM->Proc();
				}
				else if (!g_FCMServerKey.empty())
				{
					g_FCM.reset(new TFCM::element_type(
						*FCMOption,
						1,
						5000,
						g_FCMServerKey));

					LOG(L"Initialized FCM");
				}
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
