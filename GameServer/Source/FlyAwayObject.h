#pragma once

#include <Rso/Physics/Physics.h>

using namespace rso;
using namespace physics;

class CFlyAwayObject abstract : public CRectCollider2D
{
public:
	CFlyAwayObject(const STransform& Transform_, int32 objectNumber, SRectCollider2D Collider_);
	virtual void Proc(const shared_ptr<CFlyAwayBattlePlayer>& pPlayer_, CFlyAwayBattle* pBattle_) const = 0;
};