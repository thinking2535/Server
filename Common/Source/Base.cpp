#pragma once

#include "Base.h"

SRankingConfigMeta GetSRankingConfigMeta(void)
{
	CStream Stream;

	Stream.LoadFile(L"../../MetaData/RankingConfig.bin");
	list<SRankingConfigMeta> RankingConfigMetas;
	Stream >> RankingConfigMetas;

	if (RankingConfigMetas.empty())
		THROWEX();

	return RankingConfigMetas.front();
}