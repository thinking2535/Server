#include "stdafx.h"

CBattlePlayerObject::CBattlePlayerObject(const STransform& Transform_, const list<shared_ptr<CCollider2D>>& Colliders_, const SPoint& Velocity_, CBattlePlayer* pBattlePlayer_) :
	CPlayerObject2D(Transform_, Colliders_, Velocity_),
	pBattlePlayer(pBattlePlayer_)
{
	Mass = pBattlePlayer->pMeta->pCharacterTypeMeta->Weight;
}
