#include "stdafx.h"

void RequestRankingNetCs(const CKey& Key_, CStream& Stream_)
{
	SRanking Ranking;

	for (auto& i : g_Ranking.operator() < 1 > ())
	{
		auto itRanking = g_Ranking.get(i.second);
		Ranking.RankingUsers.emplace_back(itRanking->second);
	}

	for (auto& i : g_RankingSingle.operator() < 1 > ())
	{
		auto itRanking = g_RankingSingle.get(i.second);
		Ranking.RankingUserSingles.emplace_back(itRanking->second);
	}

	for (auto& i : g_RankingIsland.operator() < 1 > ())
	{
		auto itRanking = g_RankingIsland.get(i.second);
		Ranking.RankingUserIslands.emplace_back(itRanking->second); // Point
	}

	g_NetBalance->Send(Key_.PeerNum, (__int32)EProtoRankingNetSc::RequestRanking, Ranking);
}
