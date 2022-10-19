#include "stdafx.h"

SRectCollider2D CArrowDodgeArrowMaker::_GetArrowCollider2D(const SPoint& Velocity_)
{
	if (Velocity_.X < 0.0f)
		return g_MetaData->MapMeta.ArrowDodgeMapInfo.Arrow.Collider;
	else if (Velocity_.X > 0.0f)
		return RectCollider2DTo180Rotated(g_MetaData->MapMeta.ArrowDodgeMapInfo.Arrow.Collider);
	else if (Velocity_.Y < 0.0f)
		return RectCollider2DTo90Rotated(g_MetaData->MapMeta.ArrowDodgeMapInfo.Arrow.Collider);
	else
		return RectCollider2DTo270Rotated(g_MetaData->MapMeta.ArrowDodgeMapInfo.Arrow.Collider);
}
CArrowDodgeArrowMaker::CArrowDodgeArrowMaker(CFixedRandom32& FixedRandom_) :
	_FixedRandom(FixedRandom_)
{
}

void CArrowDodgeArrowMaker::FixedUpdate(int64 tick, CArrowDodgeBattle& battle, function<void(const shared_ptr<CArrow>& pArrow_)> fAddArrow_)
{
	float velocityAdded = ((float)(tick / arrowDodgeArrowBaseVelocityTick)) * arrowDodgeArrowBaseVelocity;

	if (tick > _NextDownArrowTick)
	{
		_NextDownArrowTick += _GetDownArrowDuration(tick);

		SPoint Velocity(0.0f, -(arrowDodgeMinDownVelocity + velocityAdded));
		fAddArrow_(MakeArrow(SPoint(battle.getRandomItemPointX(), c_ScreenHeight_2 + arrowDodgeArrowCreateAreaHalfHeight), Velocity));
	}

	if (tick > _NextLeftArrowTick)
	{
		_NextLeftArrowTick += _GetLeftArrowDuration(tick);

		SPoint Velocity(-(arrowDodgeMinHorizontalVelocity + velocityAdded), 0.0f);
		fAddArrow_(MakeArrow(SPoint(arrowDodgeArrowCreateAreaHalfWidth, battle.getRandomItemPointY()), Velocity));
	}

	if (tick > _NextRightArrowTick)
	{
		_NextRightArrowTick += _GetRightArrowDuration(tick);

		SPoint Velocity((arrowDodgeMinHorizontalVelocity + velocityAdded), 0.0f);
		fAddArrow_(MakeArrow(SPoint(-arrowDodgeArrowCreateAreaHalfWidth, battle.getRandomItemPointY()), Velocity));
	}
}
shared_ptr<CArrow> CArrowDodgeArrowMaker::MakeArrow(const SPoint& LocalPosition_, const SPoint& Velocity_)
{
	return make_shared<CArrow>(
		LocalPosition_,
		list<shared_ptr<CCollider2D>>{ make_shared<CRectCollider2D>(ZeroTransform, CEngineGlobal::c_ArrowNumber, _GetArrowCollider2D(Velocity_)) },
		Velocity_);
}
