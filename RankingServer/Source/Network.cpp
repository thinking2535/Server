#include "stdafx.h"

void RequestRankingNetCs(const CKey& Key_, CStream& Stream_)
{
	SRanking Ranking;

	for (size_t i = 0; i < g_RankingMapArray.size(); ++i)
	{
		for (auto& u : g_RankingMapArray[i].operator() < 1 > ())
		{
			auto itRanking = g_RankingMapArray[i].get(u.second);
			Ranking.RankingUsersArray[i].RankingUsers.emplace_back(itRanking->second);
		}
	}

	g_NetBalance->Send(Key_.PeerNum, (__int32)EProtoRankingNetSc::RequestRanking, std::move(Ranking));
}
