#include "stdafx.h"
#include <GameServer/Common/Base.h>

CGameData::CGameData() :
	RankingConfigMeta(GetSRankingConfigMeta())
{
	try
	{
		CStream Stream;

		Stream.LoadFile(L"../../MetaData/RankingReward.bin");
		list<SRankingRewardMeta> RankingRewardMetas;
		Stream >> RankingRewardMetas;
		RankingMaxes.resize((size_t)ERankingType::Max, -1);

		for (auto& i : RankingRewardMetas)
		{
			ERankingType RankingType = ERankingType::Null;

			if (i.Mode == L"MULTI")
				RankingType = ERankingType::Multi;
			else if (i.Mode == L"ARROW")
				RankingType = ERankingType::Single;
			else if (i.Mode == L"ISLAND")
				RankingType = ERankingType::Island;
			else
				THROWEXA(L"Invalid RankingReward ModeName[%s]", i.Mode);

			if (RankingMaxes[(size_t)RankingType] < i.End)
				RankingMaxes[(size_t)RankingType] = i.End;
		}
	}
	catch (const SException& Exception_)
	{
		cout << Exception_.what() << endl;
		throw Exception_;
	}
	catch (...)
	{
		THROWEX();
	}
}
