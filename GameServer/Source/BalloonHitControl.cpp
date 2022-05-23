#include "stdafx.h"
#include "BalloonHitControl.h"

bool CBalloonHitControl::_HitByMe(int8 BalloonCount_, int8 BalloonCountFromClient_)
{
	if (BalloonCountFromClient_ <= 0)
		return false;

	if (_Hitter == _EHitter::Null)
	{
		_Hitter = _EHitter::Me;
	}
	else if (_Hitter == _EHitter::Enemy)
	{
		_Hitter = _EHitter::Me;

		if (BalloonCount_ != BalloonCountFromClient_)
			return false;
	}

	return true;
}
bool CBalloonHitControl::_HitByEnemy(int8 BalloonCount_, int8 BalloonCountFromClient_)
{
	if (BalloonCountFromClient_ <= 0)
		return false;

	if (_Hitter == _EHitter::Null)
	{
		_Hitter = _EHitter::Enemy;
	}
	else if (_Hitter == _EHitter::Me)
	{
		_Hitter = _EHitter::Enemy;

		if (BalloonCount_ != BalloonCountFromClient_)
			return false;
	}

	return true;
}
CBalloonHitControl::CBalloonHitControl(int32 PlayerIndex_) :
	_PlayerIndex(PlayerIndex_)
{
}
bool CBalloonHitControl::Hit(int32 PlayerIndex_, int8 BalloonCount_, int8 BalloonCountFromClient_)
{
	if (_PlayerIndex == PlayerIndex_)
		return _HitByMe(BalloonCount_, BalloonCountFromClient_);
	else
		return _HitByEnemy(BalloonCount_, BalloonCountFromClient_);
}
void CBalloonHitControl::Clear(void)
{
	_Hitter = _EHitter::Null;
}