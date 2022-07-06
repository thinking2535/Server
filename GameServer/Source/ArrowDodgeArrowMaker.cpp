#include "stdafx.h"

const float CArrowDodgeArrowMaker::_PositionPrecision = 1000.0f;
const float CArrowDodgeArrowMaker::_PositionMultiplier = 1.0f / _PositionPrecision;
const uint32 CArrowDodgeArrowMaker::_IntScreenWidth = (uint32)(c_ScreenWidth * _PositionPrecision);
const uint32 CArrowDodgeArrowMaker::_IntScreenHeight = (uint32)(c_ScreenHeight * _PositionPrecision);
const float CArrowDodgeArrowMaker::_MinDownVelocity = 0.7f;
const float CArrowDodgeArrowMaker::_MinHorizontalVelocity = 0.3f;
const uint32 CArrowDodgeArrowMaker::_VelocityRange = 20;
const float CArrowDodgeArrowMaker::_VelocityMultiplier = 0.01f;
const float CArrowDodgeArrowMaker::_ArrowCreateAreaHalfWidth = c_ScreenWidth * 0.6f;
const float CArrowDodgeArrowMaker::_ArrowCreateAreaHalfHeight = c_ScreenHeight * 0.6f;
const float CArrowDodgeArrowMaker::_ArrowCreateScreenLeft = -_ArrowCreateAreaHalfWidth;
const float CArrowDodgeArrowMaker::_ArrowCreateScreenRight = _ArrowCreateAreaHalfWidth;
const float CArrowDodgeArrowMaker::_ArrowCreateScreenBottom = -_ArrowCreateAreaHalfHeight;
const float CArrowDodgeArrowMaker::_ArrowCreateScreenTop = _ArrowCreateAreaHalfHeight;
const float CArrowDodgeArrowMaker::_ArrowActiveAreaHalfWidth = c_ScreenWidth * 0.7f;
const float CArrowDodgeArrowMaker::_ArrowActiveAreaHalfHeight = c_ScreenHeight * 0.7f;
const float CArrowDodgeArrowMaker::ArrowDeleteScreenLeft = -_ArrowActiveAreaHalfWidth;
const float CArrowDodgeArrowMaker::ArrowDeleteScreenRight = _ArrowActiveAreaHalfWidth;
const float CArrowDodgeArrowMaker::ArrowDeleteScreenBottom = -_ArrowActiveAreaHalfHeight;
const float CArrowDodgeArrowMaker::ArrowDeleteScreenTop = _ArrowActiveAreaHalfHeight;
const int64 CArrowDodgeArrowMaker::_FirstLeftArrowTick = 300000000;
const int64 CArrowDodgeArrowMaker::_FirstRightArrowTick = 600000000;
const int64 CArrowDodgeArrowMaker::_MaxArrowTick = 900000000;


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

void CArrowDodgeArrowMaker::FixedUpdate(int64 Tick_, function<void(const shared_ptr<CArrow>& pArrow_)> fAddArrow_)
{
	if (Tick_ > _NextDownArrowTick)
	{
		_NextDownArrowTick += _GetDownArrowDuration(Tick_);

		auto RandomNumber = _FixedRandom.Get();
		SPoint Velocity(0.0f, -((RandomNumber % _VelocityRange) * _VelocityMultiplier + _MinDownVelocity));
		fAddArrow_(MakeArrow(SPoint((RandomNumber % _IntScreenWidth) * _PositionMultiplier - c_ScreenWidth_2, _ArrowCreateScreenTop), Velocity));
	}

	if (Tick_ > _NextLeftArrowTick)
	{
		_NextLeftArrowTick += _GetLeftArrowDuration(Tick_);

		auto RandomNumber = _FixedRandom.Get();
		SPoint Velocity(-((RandomNumber % _VelocityRange) * _VelocityMultiplier + _MinHorizontalVelocity), 0.0f);
		fAddArrow_(MakeArrow(SPoint(_ArrowCreateScreenRight, (RandomNumber % _IntScreenHeight) * _PositionMultiplier - c_ScreenHeight_2), Velocity));
	}

	if (Tick_ > _NextRightArrowTick)
	{
		_NextRightArrowTick += _GetRightArrowDuration(Tick_);

		auto RandomNumber = _FixedRandom.Get();
		SPoint Velocity(((RandomNumber % _VelocityRange) * _VelocityMultiplier + _MinHorizontalVelocity), 0.0f);
		fAddArrow_(MakeArrow(SPoint(_ArrowCreateScreenLeft, (RandomNumber % _IntScreenHeight) * _PositionMultiplier - c_ScreenHeight_2), Velocity));
	}
}
shared_ptr<CArrow> CArrowDodgeArrowMaker::MakeArrow(const SPoint& LocalPosition_, const SPoint& Velocity_)
{
	auto pArrow = make_shared<CArrow>(
		LocalPosition_,
		Velocity_);

	SetColliderToMovingObject2D(make_shared<CRectCollider2D>(ZeroTransform, CEngineGlobal::c_ArrowNumber, _GetArrowCollider2D(Velocity_)), pArrow);

	return pArrow;
}
