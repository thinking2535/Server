#include "stdafx.h"

void UpdateMultiNetSr(const CKey& Key_, CStream& Stream_)
{
	SRankingUpdateMultiNetSr Proto;
	Stream_ >> Proto;

	auto& RankingMap = g_RankingMapArray[(size_t)ERankingType::Multi];

	list<TUID> Deleted;

	for (auto it = Proto.UsersChanged.begin(); it != Proto.UsersChanged.end();)
	{
		auto itCheck = it;
		++it;

		auto itRanking = RankingMap.find<0>(itCheck->UID);
		if (itRanking != RankingMap.end<0>())
		{
			RankingMap.erase(itRanking->second); // 멀티점수는 실시간으로 줄어드는 것을 허용하므로 기존 랭킹 값보다 작은값이 들어와도 갱신
		}
		else
		{
			if (RankingMap.size() >= g_MaxList)
			{
				auto itBottom = --RankingMap.rbegin<1>().base();
				if (itCheck->Point <= itBottom->first)
				{
					Proto.UsersChanged.erase(itCheck);
					continue;
				}

				Deleted.emplace_back(std::get<0>(RankingMap[itBottom->second].first)->first);
				RankingMap.erase(itBottom->second);
			}
		}

		RankingMap.emplace(*itCheck, itCheck->UID, itCheck->Point);
	}

	DBPush(SRankingUpdateDBIn(std::move(Proto.UsersChanged), std::move(Deleted)));
}
void UpdateSingleNetSr(const CKey& Key_, CStream& Stream_)
{
	SRankingUpdateSingleNetSr Proto;
	Stream_ >> Proto;

	auto& RankingMap = g_RankingMapArray[(size_t)ERankingType::Single ];

	list<TUID> Deleted;

	auto it = RankingMap.find<0>(Proto.UserSingle.UID);
	if (it != RankingMap.end<0>())
	{
		if (Proto.UserSingle.Point <= std::get<1>(RankingMap.get(it->second)->first)->first) // 싱글점수는 최고점수로 갱신되어야 하므로 기존 값보다 크면 갱신
			return;

		RankingMap.erase(it->second);
	}
	else
	{
		if (RankingMap.size() >= g_MaxList)
		{
			auto itBottom = --RankingMap.rbegin<1>().base();
			if (Proto.UserSingle.Point <= itBottom->first)
				return;

			Deleted.emplace_back(std::get<0>(RankingMap[itBottom->second].first)->first);
			RankingMap.erase(itBottom->second);
		}
	}

	RankingMap.emplace(Proto.UserSingle, Proto.UserSingle.UID, Proto.UserSingle.Point);
	DBPush(SRankingUpdateSingleDBIn(TRankingUsers{ Proto.UserSingle }, std::move(Deleted)));
}
void UpdateIslandNetSr(const CKey& Key_, CStream& Stream_)
{
	SRankingUpdateIslandNetSr Proto;
	Stream_ >> Proto;

	auto& RankingMap = g_RankingMapArray[(size_t)ERankingType::Island];

	list<TUID> Deleted;

	auto it = RankingMap.find<0>(Proto.UserIsland.UID);
	if (it != RankingMap.end<0>())
	{
		if (Proto.UserIsland.Point <= std::get<1>(RankingMap.get(it->second)->first)->first) // 싱글점수는 최고점수로 갱신되어야 하므로 기존 값보다 크면 갱신
			return;

		RankingMap.erase(it->second);
	}
	else
	{
		if (RankingMap.size() >= g_MaxList)
		{
			auto itBottom = --RankingMap.rbegin<1>().base();
			if (Proto.UserIsland.Point <= itBottom->first)
				return;

			Deleted.emplace_back(std::get<0>(RankingMap[itBottom->second].first)->first);
			RankingMap.erase(itBottom->second);
		}
	}

	RankingMap.emplace(Proto.UserIsland, Proto.UserIsland.UID, Proto.UserIsland.Point);
	DBPush(SRankingUpdateIslandDBIn(TRankingUsers{ Proto.UserIsland }, std::move(Deleted)));
}
