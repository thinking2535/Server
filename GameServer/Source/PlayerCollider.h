#pragma once

#include <Rso/Physics/RectCollider2D.h>

using namespace rso;
using namespace physics;

class CPlayerCollider
{
public:
	shared_ptr<CRectCollider2D> pBody;
	shared_ptr<CRectCollider2D> pBalloon;
	shared_ptr<CRectCollider2D> pParachute;
	list<shared_ptr<CCollider2D>> Colliders;

	CPlayerCollider(const SCharacter* pCharacter_);
};