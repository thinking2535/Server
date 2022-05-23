#include "stdafx.h"

void RankingInfoNetRs(const CKey& Key_, CStream& Stream_)
{
	Stream_ >> g_RankingInfo;
}
void UserPointMinNetRs(const CKey& Key_, CStream& Stream_)
{
	Stream_ >> g_RankingInfo.UserPointMin;
}
