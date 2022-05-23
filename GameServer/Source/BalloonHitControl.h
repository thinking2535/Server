#pragma once

class CBalloonHitControl
{
	enum class _EHitter
	{
		Me,
		Enemy,
		Max,
		Null
	};
	int32 _PlayerIndex = 0;
	_EHitter _Hitter = _EHitter::Null;

	bool _HitByMe(int8 BalloonCount_, int8 BalloonCountFromClient_);
	bool _HitByEnemy(int8 BalloonCount_, int8 BalloonCountFromClient_);

public:
	CBalloonHitControl(int32 PlayerIndex_);
	bool Hit(int32 PlayerIndex_, int8 BalloonCount_, int8 BalloonCountFromClient_);
	void Clear(void);
};
