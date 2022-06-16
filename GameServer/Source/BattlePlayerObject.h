#pragma once

class CBattlePlayerObject : public CPlayerObject2D
{
public:
	CBattlePlayer* pBattlePlayer;

	CBattlePlayerObject(const STransform& Transform_, const SPoint& Velocity_, CBattlePlayer* pBattlePlayer_);
};