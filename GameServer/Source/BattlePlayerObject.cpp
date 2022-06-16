#include "stdafx.h"

CBattlePlayerObject::CBattlePlayerObject(const STransform& Transform_, const SPoint& Velocity_, CBattlePlayer* pBattlePlayer_) :
	CPlayerObject2D(Transform_, Velocity_),
	pBattlePlayer(pBattlePlayer_)
{
}
