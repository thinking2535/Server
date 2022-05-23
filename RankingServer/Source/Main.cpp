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

SRankingUserPointMin GetUserPointMin(void)
{
	__int32 UserPointMin = 0;
	__int32 UserPointMinSingle = 0;
	__int32 UserPointMinIsland = 0;

	if (g_MaxList > 0 && g_Ranking.size() >= g_MaxList)
		UserPointMin = g_Ranking.operator() < 1 > ().rbegin()->first;

	if (g_MaxList > 0 && g_RankingSingle.size() >= g_MaxList)
		UserPointMinSingle = g_RankingSingle.operator() < 1 > ().rbegin()->first;

	if (g_MaxList > 0 && g_RankingIsland.size() >= g_MaxList)
		UserPointMinIsland = g_RankingIsland.operator() < 1 > ().rbegin()->first;

	return SRankingUserPointMin(UserPointMin, UserPointMinSingle, UserPointMinIsland);
}
SRankingRankingInfoNetRs GetSRankingRankingInfoNetRs(void)
{
	return SRankingRankingInfoNetRs(g_RankingConfig.Counter, GetUserPointMin(), g_Rewards, g_RewardsSingle, g_RewardsIsland);
}
void BroadCast(void)
{
	TRankingUsers RankingUsers;
	for (auto& i : g_Ranking)
		RankingUsers.emplace_back(SRankingUser(i.second, std::get<0>(i.first)->first, std::get<1>(i.first)->first));

	TRankingUserSingles RankingUserSingles;
	for (auto& i : g_RankingSingle)
		RankingUserSingles.emplace_back(SRankingUserSingle(i.second, std::get<0>(i.first)->first, std::get<1>(i.first)->first));

	TRankingUserIslands RankingUserIslands;
	for (auto& i : g_RankingIsland)
		RankingUserIslands.emplace_back(SRankingUserIsland(i.second, std::get<0>(i.first)->first, std::get<1>(i.first)->first));

	g_NetBalance->BroadCast(RankingUsers, RankingUserSingles, RankingUserIslands, g_Rewards, g_RewardsSingle, g_RewardsIsland);
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

	TRankingUsers RankingUsers;
	Stream_ >> RankingUsers;

	g_Ranking.clear();

	for (auto& i : RankingUsers)
		g_Ranking.emplace(i, i.UID, i.Point);


	TRankingUserSingles RankingUserSingles;
	Stream_ >> RankingUserSingles;

	g_RankingSingle.clear();

	for (auto& i : RankingUserSingles)
		g_RankingSingle.emplace(i, i.UID, i.Point);


	TRankingUserIslands RankingUserIslands;
	Stream_ >> RankingUserIslands;

	g_RankingIsland.clear();

	for (auto& i : RankingUserIslands)
		g_RankingIsland.emplace(i, i.UID, i.Point);


	g_Rewards.clear();
	Stream_ >> g_Rewards;

	g_RewardsSingle.clear();
	Stream_ >> g_RewardsSingle;

	g_RewardsIsland.clear();
	Stream_ >> g_RewardsIsland;
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

	g_Ranking.emplace(RankingUser, RankingUser.UID, RankingUser.Point);
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
	SRankingUserSingle RankingUser;
	Row_ >> RankingUser;

	g_RankingSingle.emplace(RankingUser, RankingUser.UID, RankingUser.Point);
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
	SRankingUserIsland RankingUser;
	Row_ >> RankingUser;

	g_RankingIsland.emplace(RankingUser, RankingUser.UID, RankingUser.Point);
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

	g_Rewards.emplace(UID, Ranking);
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

	g_RewardsSingle.emplace(UID, Ranking);
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

	g_RewardsIsland.emplace(UID, Ranking);
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
		g_GameData.reset(new TGameData::element_type());

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
				DBPush(SRankingConfigLoadDBIn(CDateTime(SDateTime(WCSToMBS(g_GameData->RankingConfigMeta.BaseTime)), minutes(9 * 60)).ToTimePoint() + minutes(g_GameData->RankingConfigMeta.PeriodMinutes)));

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

				if (Option->MasterNamePort.Port == 0)
				{
					BroadCast();

					auto Now = system_clock::now();
					if (g_RankingConfig.ExpireTimePoint <= Now)
					{
						// Refresh ////////////////////////////////
						++g_RankingConfig.Counter;
						g_RankingConfig.ExpireTimePoint += (((Now - g_RankingConfig.ExpireTimePoint) / minutes(g_GameData->RankingConfigMeta.PeriodMinutes)) + 1) * minutes(g_GameData->RankingConfigMeta.PeriodMinutes);

						{
							g_Rewards.clear();
							__int32 Ranking = 0;
							for (auto& i : g_Ranking.operator() < 1 > ())
							{
								if (g_GameData->RankingMaxes[(size_t)ERankingType::Multi] < Ranking)
									break;

								g_Rewards.emplace(std::get<0>(g_Ranking[i.second].first)->first, Ranking);
								++Ranking;
							}
						}

						{
							g_RewardsSingle.clear();
							__int32 Ranking = 0;
							for (auto& i : g_RankingSingle.operator() < 1 > ())
							{
								if (g_GameData->RankingMaxes[(size_t)ERankingType::Single] < Ranking)
									break;

								g_RewardsSingle.emplace(std::get<0>(g_RankingSingle[i.second].first)->first, Ranking);
								++Ranking;
							}
						}

						{
							g_RewardsIsland.clear();
							__int32 Ranking = 0;
							for (auto& i : g_RankingIsland.operator() < 1 > ())
							{
								if (g_GameData->RankingMaxes[(size_t)ERankingType::Island] < Ranking)
									break;

								g_RewardsIsland.emplace(std::get<0>(g_RankingIsland[i.second].first)->first, Ranking);
								++Ranking;
							}
						}

						g_Ranking.clear();
						g_RankingSingle.clear();
						g_RankingIsland.clear();

						DBPush(SRankingRefreshDBIn(g_RankingConfig, g_Rewards, g_RewardsSingle, g_RewardsIsland));

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

			this_thread::sleep_for(milliseconds(1));
		}
	}
	catch (const SException& Exception_)
	{
		cout << Exception_.what() << endl;
	}

	return 0;
}
