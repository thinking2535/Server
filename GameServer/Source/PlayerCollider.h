#pragma once

#include <Rso/Physics/RectCollider2D.h>
#include <Rso/Physics/CollectionCollider2D.h>

using namespace rso;
using namespace physics;

class CPlayerCollider
{
public:
	shared_ptr<CRectCollider2D> pBody;
	shared_ptr<CRectCollider2D> pBalloon;
	shared_ptr<CRectCollider2D> pParachute;
	shared_ptr<CCollectionCollider2D> pPlayer;

	CPlayerCollider(const SCharacter* pCharacter_);
};