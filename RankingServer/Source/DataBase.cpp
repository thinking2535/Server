#include "stdafx.h"

void DummyDBOut(TOutObject& OutObject_)
{
	if (OutObject_.Ret != 0 || OutObject_.SPRet != 0)
		throw ERet::SPError;
}
void RankingConfigLoadDBOut(TOutObject& OutObject_)
{
	SRankingConfigLoadDBIn In;
	SRankingConfigLoadDBOut Out;

	if (OutObject_.Ret != 0 || OutObject_.SPRet != 0)
		throw ERet::SPError;

	OutObject_.InStream >> In;
	OutObject_.OutStream >> Out;

	if (Out.RankingConfigs.empty())
		throw ERet::SPError;

	g_RankingConfig = Out.RankingConfigs.front();
}
