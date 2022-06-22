#include "stdafx.h"

void UpdateMultiNetSr(const CKey& Key_, CStream& Stream_)
{
	SRankingUpdateMultiNetSr Proto;
	Stream_ >> Proto;

	list<TUID> Deleted;

	for (auto it = Proto.UsersChanged.begin(); it != Proto.UsersChanged.end();)
	{
		auto itCheck = it;
		++it;

		auto itRanking = g_Ranking.find<0>(itCheck->UID);
		if (itRanking != g_Ranking.end<0>())
		{
			g_Ranking.erase(itRanking->second); // 멀티점수는 실시간으로 줄어드는 것을 허용하므로 기존 랭킹 값보다 작은값이 들어와도 갱신
		}
		else
		{
			if (g_Ranking.size() >= g_MaxList)
			{
				auto itBottom = --g_Ranking.rbegin<1>().base();
				if (itCheck->Point <= itBottom->first)
				{
					Proto.UsersChanged.erase(itCheck);
					continue;
				}

				Deleted.emplace_back(std::get<0>(g_Ranking[itBottom->second].first)->first);
				g_Ranking.erase(itBottom->second);
			}
		}

		g_Ranking.emplace(*itCheck, itCheck->UID, itCheck->Point);
	}

	DBPush(SRankingUpdateDBIn(std::move(Proto.UsersChanged), std::move(Deleted)));
}
void UpdateSingleNetSr(const CKey& Key_, CStream& Stream_)
{
	SRankingUpdateSingleNetSr Proto;
	Stream_ >> Proto;

	list<TUID> Deleted;

	auto it = g_RankingSingle.find<0>(Proto.UserSingle.UID);
	if (it != g_RankingSingle.end<0>())
	{
		if (Proto.UserSingle.Point <= std::get<1>(g_RankingSingle.get(it->second)->first)->first) // 싱글점수는 최고점수로 갱신되어야 하므로 기존 값보다 크면 갱신
			return;

		g_RankingSingle.erase(it->second);
	}
	else
	{
		if (g_RankingSingle.size() >= g_MaxList)
		{
			auto itBottom = --g_RankingSingle.rbegin<1>().base();
			if (Proto.UserSingle.Point <= itBottom->first)
				return;

			Deleted.emplace_back(std::get<0>(g_RankingSingle[itBottom->second].first)->first);
			g_RankingSingle.erase(itBottom->second);
		}
	}

	g_RankingSingle.emplace(Proto.UserSingle, Proto.UserSingle.UID, Proto.UserSingle.Point);
	DBPush(SRankingUpdateSingleDBIn(TRankingUsers{ Proto.UserSingle }, std::move(Deleted)));
}
void UpdateIslandNetSr(const CKey& Key_, CStream& Stream_)
{
	SRankingUpdateIslandNetSr Proto;
	Stream_ >> Proto;

	list<TUID> Deleted;

	auto it = g_RankingIsland.find<0>(Proto.UserIsland.UID);
	if (it != g_RankingIsland.end<0>())
	{
		if (Proto.UserIsland.Point <= std::get<1>(g_RankingIsland.get(it->second)->first)->first) // 싱글점수는 최고점수로 갱신되어야 하므로 기존 값보다 크면 갱신
			return;

		g_RankingIsland.erase(it->second);
	}
	else
	{
		if (g_RankingIsland.size() >= g_MaxList)
		{
			auto itBottom = --g_RankingIsland.rbegin<1>().base();
			if (Proto.UserIsland.Point <= itBottom->first)
				return;

			Deleted.emplace_back(std::get<0>(g_RankingIsland[itBottom->second].first)->first);
			g_RankingIsland.erase(itBottom->second);
		}
	}

	g_RankingIsland.emplace(Proto.UserIsland, Proto.UserIsland.UID, Proto.UserIsland.Point);
	DBPush(SRankingUpdateIslandDBIn(TRankingUsers{ Proto.UserIsland }, std::move(Deleted)));
}
