#include "stdafx.h"
#include <Rso/Game/Base.h>
#include <Rso/Win/ConsoleCtrlHandler.h>
#include <GameServer/Common/GameServerProtocol.h>
#include "Network.h"
#include "NetworkServer.h"

using namespace rso;
using namespace win;
using namespace game;

CConsoleCtrlHandler g_ConsoleCtrlHandler;

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

TRankingPointArray GetUserPointMin(void)
{
	TRankingPointArray UserPointMinArray{};

	for (size_t i = 0; i < g_RankingMapArray.size(); ++i)
	{
		if (g_MaxList > 0 && g_RankingMapArray[i].size() >= g_MaxList)
			UserPointMinArray[i] = g_RankingMapArray[i].operator() < 1 > ().rbegin()->first;
	}

	return UserPointMinArray;
}
SRankingRankingInfoNetRs GetSRankingRankingInfoNetRs(void)
{
	return SRankingRankingInfoNetRs(g_RankingConfig.Counter, GetUserPointMin(), g_RewardsArray);
}
void BroadCast(void)
{
	TRankingUsersArray RankingUsersArray{};

	for (size_t i = 0; i < g_RankingMapArray.size(); ++i)
	{
		for (auto& u : g_RankingMapArray[i])
			RankingUsersArray[i].RankingUsers.emplace_back(u.second);
	}

	g_NetBalance->BroadCast(RankingUsersArray, g_RewardsArray);
}

void LinkS(const CKey& Key_)
{
	LOG(L"LinkS PeerNum:%d", Key_.PeerNum);
	g_Net->Certify(Key_.PeerNum);
	g_Net->Send(Key_.PeerNum, __int32(EProtoRankingNetRs::RankingInfo), GetSRankingRankingInfoNetRs());
}
void UnLinkS(const CKey& Key_, ENetRet NetRet_)
{
	LOG(L"UnLinkS PeerNum:%d NetRet:%d", Key_.PeerNum, (__int32)NetRet_);
}
void RecvS(const CKey& Key_, CStream& Stream_)
{
	__int32 ProtoNum = 0;
	Stream_ >> ProtoNum;

	LOG(L"RecvS PeerNum:%d ProtoNum:%d", Key_.PeerNum, ProtoNum);

	auto itRecv = g_BinderRecvS.get(ProtoNum);
	if (!itRecv)
		return g_Net->Close(Key_.PeerNum);

	(*itRecv)(Key_, Stream_);
}

void LinkU(const CKey& Key_)
{
	LOG(L"LinkU PeerNum:%d", Key_.PeerNum);
}
void LinkFailU(TPeerCnt PeerNum_, ENetRet NetRet_)
{
	LOG(L"LinkFailU PeerNum:%d NetRet:%d", PeerNum_, (__int32)NetRet_);
}
void UnLinkU(const CKey& Key_, ENetRet NetRet_)
{
	LOG(L"UnLinkU PeerNum:%d NetRet:%d", Key_.PeerNum, (__int32)NetRet_);
}
void RecvU(const CKey& Key_, CStream& Stream_)
{
	LOG(L"RecvU PeerNum:%d", Key_.PeerNum);
}
void RecvUBroadCast(const CKey& Key_, CStream& Stream_)
{
	LOG(L"RecvUBroadCast PeerNum:%d", Key_.PeerNum);

	TRankingUsersArray RankingUsersArray{};
	Stream_ >> RankingUsersArray;
	Stream_ >> g_RewardsArray;

	for (size_t i = 0; i < RankingUsersArray.size(); ++i)
	{
		g_RankingMapArray[i].clear();

		for (auto& u : RankingUsersArray[i].RankingUsers)
			g_RankingMapArray[i].emplace(u, u.UID, u.Point);
	}
}

void LinkD(const CKey& Key_)
{
	LOG(L"LinkD PeerNum:%d", Key_.PeerNum);
	BroadCast();
}
void UnLinkD(const CKey& Key_, ENetRet NetRet_)
{
	LOG(L"UnLinkD PeerNum:%d NetRet:%d", Key_.PeerNum, (__int32)NetRet_);
}
void RecvD(const CKey& Key_, CStream& Stream_)
{
	LOG(L"RecvD PeerNum:%d", Key_.PeerNum);
}

void LinkC(const CKey& Key_)
{
	LOG(L"LinkC PeerNum:%d", Key_.PeerNum);
}
void UnLinkC(const CKey& Key_, ENetRet NetRet_)
{
	LOG(L"UnLinkC PeerNum:%d NetRet:%d", Key_.PeerNum, (__int32)NetRet_);
}
void RecvC(const CKey& Key_, CStream& Stream_)
{
	__int32 ProtoNum = 0;
	Stream_ >> ProtoNum;

	DLOG(L"RecvC PeerNum:%d ProtoNum:%d", Key_.PeerNum, ProtoNum);

	auto itRecv = g_BinderRecvC.get(ProtoNum);
	if (!itRecv)
		return g_Net->Close(Key_.PeerNum);

	(*itRecv)(Key_, Stream_);
}

bool g_RankingLoaded = false;
bool RowCallback(SQLLEN RowNum_, CStream& Row_)
{
	SRankingUser RankingUser;
	Row_ >> RankingUser;

	g_RankingMapArray[(size_t)ERankingType::Multi].emplace(RankingUser, RankingUser.UID, RankingUser.Point);
	return true;
}
void ParamCallback(SQLRETURN Ret_, __int32 SpRet_, CStream& OutParams_)
{
	cout << "Ranking Load Completed Ret:" << Ret_ << " SPRet:" << SpRet_ << endl;
	g_RankingLoaded = true;
}

bool g_RankingSingleLoaded = false;
bool RowCallbackSingle(SQLLEN RowNum_, CStream& Row_)
{
	SRankingUser RankingUser;
	Row_ >> RankingUser;

	g_RankingMapArray[(size_t)ERankingType::Single].emplace(RankingUser, RankingUser.UID, RankingUser.Point);
	return true;
}
void ParamCallbackSingle(SQLRETURN Ret_, __int32 SpRet_, CStream& OutParams_)
{
	cout << "RankingSingle Load Completed Ret:" << Ret_ << " SPRet:" << SpRet_ << endl;
	g_RankingSingleLoaded = true;
}

bool g_RankingIslandLoaded = false;
bool RowCallbackIsland(SQLLEN RowNum_, CStream& Row_)
{
	SRankingUser RankingUser;
	Row_ >> RankingUser;

	g_RankingMapArray[(size_t)ERankingType::Island].emplace(RankingUser, RankingUser.UID, RankingUser.Point);
	return true;
}
void ParamCallbackIsland(SQLRETURN Ret_, __int32 SpRet_, CStream& OutParams_)
{
	cout << "RankingIsland Load Completed Ret:" << Ret_ << " SPRet:" << SpRet_ << endl;
	g_RankingIslandLoaded = true;
}

bool g_RewardLoaded = false;
bool RowCallbackReward(SQLLEN RowNum_, CStream& Row_)
{
	TUID UID;
	__int32 Ranking;
	Row_ >> UID;
	Row_ >> Ranking;

	g_RewardsArray[(size_t)ERankingType::Multi].emplace(UID, Ranking);
	return true;
}
void ParamCallbackReward(SQLRETURN Ret_, __int32 SpRet_, CStream& OutParams_)
{
	cout << "Reward Load Completed Ret:" << Ret_ << " SPRet:" << SpRet_ << endl;
	g_RewardLoaded = true;
}

bool g_RewardSingleLoaded = false;
bool RowCallbackRewardSingle(SQLLEN RowNum_, CStream& Row_)
{
	TUID UID;
	__int32 Ranking;
	Row_ >> UID;
	Row_ >> Ranking;

	g_RewardsArray[(size_t)ERankingType::Single].emplace(UID, Ranking);
	return true;
}
void ParamCallbackRewardSingle(SQLRETURN Ret_, __int32 SpRet_, CStream& OutParams_)
{
	cout << "RewardSingle Load Completed Ret:" << Ret_ << " SPRet:" << SpRet_ << endl;
	g_RewardSingleLoaded = true;
}

bool g_RewardIslandLoaded = false;
bool RowCallbackRewardIsland(SQLLEN RowNum_, CStream& Row_)
{
	TUID UID;
	__int32 Ranking;
	Row_ >> UID;
	Row_ >> Ranking;

	g_RewardsArray[(size_t)ERankingType::Island].emplace(UID, Ranking);
	return true;
}
void ParamCallbackRewardIsland(SQLRETURN Ret_, __int32 SpRet_, CStream& OutParams_)
{
	cout << "RewardIsland Load Completed Ret:" << Ret_ << " SPRet:" << SpRet_ << endl;
	g_RewardIslandLoaded = true;
}

void DBCallback(TOutObject& OutObject_)
{
	g_BinderDB[OutObject_.SPNum](OutObject_);
}

int _tmain(int argc, _TCHAR* argv[])
{
	try
	{
		wcout.imbue(std::locale("korean"));

		LOG(L"Initializing GameData");
		g_MetaData.reset(new TGameData::element_type());

		COptionJson<SOption> Option(L"Option.ini", false);
		COptionJson<SDBOption> DBOption(L"DBOption.ini", false);

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

		g_Net.reset(new TNet::element_type(
			EAddressFamily::INET,
			LinkS, UnLinkS, RecvS,
			false, 10240000, 10240000,
			milliseconds(), milliseconds(0), 4, 0,
			CNamePort(Option->GameServerBindPort), SOMAXCONN));

		g_NetBalance.reset(new TNetBalance::element_type(
			EAddressFamily::INET,
			LinkU, LinkFailU, UnLinkU, RecvU, RecvUBroadCast,
			LinkD, UnLinkD, RecvD,
			LinkC, UnLinkC, RecvC,
			CNamePort(Option->MasterNamePort),
			5, 100, 4,
			CNamePort(Option->ChildBindPort),
			CNamePort(Option->ClientBindPort),
			CNamePort(Option->ClientBindNamePortPub)));

		g_DB.reset(new TDB::element_type(*DBOption, DBCallback));
		DBAddCmd<SRankingConfigLoadDBIn, SRankingConfigLoadDBOut>(L"dbo.spRankingConfigLoad", true, RankingConfigLoadDBOut);
		DBAddCmd<SRankingRefreshDBIn, SDummyDBOut>(L"dbo.spRankingRefresh", true, DummyDBOut);
		DBAddCmd<SRankingUpdateDBIn, SDummyDBOut>(L"dbo.spRankingUpdate", true, DummyDBOut);
		DBAddCmd<SRankingUpdateSingleDBIn, SDummyDBOut>(L"dbo.spRankingUpdateSingle", true, DummyDBOut);
		DBAddCmd<SRankingUpdateIslandDBIn, SDummyDBOut>(L"dbo.spRankingUpdateIsland", true, DummyDBOut);
		g_DB->Start(5);

		g_BinderRecvC.emplace_at((size_t)EProtoRankingNetCs::RequestRanking, RequestRankingNetCs);

		g_BinderRecvS.emplace_at((size_t)EProtoRankingNetSr::UpdateMulti, UpdateMultiNetSr);
		g_BinderRecvS.emplace_at((size_t)EProtoRankingNetSr::UpdateSingle, UpdateSingleNetSr);
		g_BinderRecvS.emplace_at((size_t)EProtoRankingNetSr::UpdateIsland, UpdateIslandNetSr);

		ASSERTION(Option->MaxList > 0);
		g_MaxList = Option->MaxList;

		if (Option->MasterNamePort.Port == 0)
		{
			{
				DBPush(SRankingConfigLoadDBIn(CDateTime(SDateTime(WCSToMBS(g_MetaData->RankingConfigMeta.BaseTime)), minutes(9 * 60)).ToTimePoint() + minutes(g_MetaData->RankingConfigMeta.PeriodMinutes)));

				while (g_RankingConfig.Counter == 0)
				{
					g_DB->Proc();
					this_thread::sleep_for(milliseconds(10));
				}
			}

			{
				CBulkSelect<SRankingLoadDBIn, SRankingLoadDBOut> bs(
					*DBOption,
					RowCallback,
					ParamCallback,
					L"dbo.spRankingLoad");

				if (!bs.Push(SRankingLoadDBIn(g_MaxList)))
					THROWEX();

				while (!g_RankingLoaded)
				{
					bs.Proc();
					this_thread::sleep_for(milliseconds(10));
				}
			}

			{
				CBulkSelect<SRankingLoadDBIn, SRankingLoadSingleDBOut> bs(
					*DBOption,
					RowCallbackSingle,
					ParamCallbackSingle,
					L"dbo.spRankingLoadSingle");

				if (!bs.Push(SRankingLoadDBIn(g_MaxList)))
					THROWEX();

				while (!g_RankingSingleLoaded)
				{
					bs.Proc();
					this_thread::sleep_for(milliseconds(10));
				}
			}

			{
				CBulkSelect<SRankingLoadDBIn, SRankingLoadIslandDBOut> bs(
					*DBOption,
					RowCallbackIsland,
					ParamCallbackIsland,
					L"dbo.spRankingLoadIsland");

				if (!bs.Push(SRankingLoadDBIn(g_MaxList)))
					THROWEX();

				while (!g_RankingIslandLoaded)
				{
					bs.Proc();
					this_thread::sleep_for(milliseconds(10));
				}
			}

			{
				CBulkSelect<SRewardLoadDBIn, SRewardLoadDBOut> bs(
					*DBOption,
					RowCallbackReward,
					ParamCallbackReward,
					L"dbo.spRewardLoad");

				if (!bs.Push(SRewardLoadDBIn()))
					THROWEX();

				while (!g_RewardLoaded)
				{
					bs.Proc();
					this_thread::sleep_for(milliseconds(10));
				}
			}

			{
				CBulkSelect<SRewardLoadDBIn, SRewardLoadDBOut> bs(
					*DBOption,
					RowCallbackRewardSingle,
					ParamCallbackRewardSingle,
					L"dbo.spRewardLoadSingle");

				if (!bs.Push(SRewardLoadDBIn()))
					THROWEX();

				while (!g_RewardSingleLoaded)
				{
					bs.Proc();
					this_thread::sleep_for(milliseconds(10));
				}
			}

			{
				CBulkSelect<SRewardLoadDBIn, SRewardLoadDBOut> bs(
					*DBOption,
					RowCallbackRewardIsland,
					ParamCallbackRewardIsland,
					L"dbo.spRewardLoadIsland");

				if (!bs.Push(SRewardLoadDBIn()))
					THROWEX();

				while (!g_RewardIslandLoaded)
				{
					bs.Proc();
					this_thread::sleep_for(milliseconds(10));
				}
			}
		}

		LOG(L"Initialized");

		while (!g_ConsoleCtrlHandler.GetExit())
		{
			g_Monitor->Proc();
			g_Net->Proc();
			g_NetBalance->Proc();
			g_DB->Proc();

			if (g_TimerPeriod.CheckAndNextLoose())
			{
				g_Timers.Proc();

				if (g_RankingRefreshPeriod.CheckAndNextLoose())
				{
					if (Option->MasterNamePort.Port == 0)
					{
						BroadCast();

						auto Now = system_clock::now();
						if (g_RankingConfig.ExpireTimePoint <= Now)
						{
							// Refresh ////////////////////////////////
							++g_RankingConfig.Counter;
							g_RankingConfig.ExpireTimePoint += (((Now - g_RankingConfig.ExpireTimePoint) / minutes(g_MetaData->RankingConfigMeta.PeriodMinutes)) + 1) * minutes(g_MetaData->RankingConfigMeta.PeriodMinutes);

							for (size_t i = 0; i < g_RankingMapArray.size(); ++i)
							{
								g_RewardsArray[i].clear();
								__int32 Ranking = 0;
								for (auto& u : g_RankingMapArray[i].operator() < 1 > ())
								{
									if (g_MetaData->RankingMaxes[i] < Ranking)
										break;

									g_RewardsArray[i].emplace(std::get<0>(g_RankingMapArray[i][u.second].first)->first, Ranking);
									++Ranking;
								}

								g_RankingMapArray[i].clear();
							}

							DBPush(SRankingRefreshDBIn(
								g_RankingConfig,
								g_RewardsArray[(size_t)ERankingType::Multi],
								g_RewardsArray[(size_t)ERankingType::Single],
								g_RewardsArray[(size_t)ERankingType::Island]));

							// g_UserPointMin 값이 크게 낮아져서 랭킹에 들 수 있는 유저가 있지만 바로 갱신되지 않더라도 다음번 갱신때 반영될 것이므로 무시
							// 이를 해결하려면 여분의 유저까지 랭킹 목록에 보관해야 하고 로직 복잡해지므로
							g_Net->SendAll(__int32(EProtoRankingNetRs::RankingInfo), GetSRankingRankingInfoNetRs());
						}
						else
						{
							// g_UserPointMin 값이 크게 낮아져서 랭킹에 들 수 있는 유저가 있지만 바로 갱신되지 않더라도 다음번 갱신때 반영될 것이므로 무시
							// 이를 해결하려면 여분의 유저까지 랭킹 목록에 보관해야 하고 로직 복잡해지므로
							g_Net->SendAll(__int32(EProtoRankingNetRs::UserPointMin), GetUserPointMin());
						}
					}
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
