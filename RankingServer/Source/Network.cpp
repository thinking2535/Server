#include "stdafx.h"

void RequestRankingNetCs(const CKey& Key_, CStream& Stream_)
{
	SRanking Ranking;

	for (auto& i : g_Ranking.operator() < 1 > ())
	{
		auto itRanking = g_Ranking.get(i.second);
		Ranking.RankingUsers.emplace_back(SRankingUser(
			itRanking->second,
			std::get<0>(itRanking->first)->first, // UID
			std::get<1>(itRanking->first)->first)); // Point
	}

	for (auto& i : g_RankingSingle.operator() < 1 > ())
	{
		auto itRanking = g_RankingSingle.get(i.second);
		Ranking.RankingUserSingles.emplace_back(SRankingUserSingle(
			itRanking->second,
			std::get<0>(itRanking->first)->first, // UID
			std::get<1>(itRanking->first)->first)); // Point
	}

	for (auto& i : g_RankingIsland.operator() < 1 > ())
	{
		auto itRanking = g_RankingIsland.get(i.second);
		Ranking.RankingUserIslands.emplace_back(SRankingUserIsland(
			itRanking->second,
			std::get<0>(itRanking->first)->first, // UID
			std::get<1>(itRanking->first)->first)); // Point
	}

	g_NetBalance->Send(Key_.PeerNum, (__int32)EProtoRankingNetSc::RequestRanking, Ranking);
}
