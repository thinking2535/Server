#pragma once

class CArrowDodgeBattle
{
	unique_ptr<CArrowDodgePhysicsEngine> _pEngine;

	TTime _BeginTime = system_clock::now();
	TTime _EndTime;

	inline bool _IsStarted(void) const { return _EndTime > TTime(); }
	void _MoveCallback(int32 PlayerIndex_, int8 Dir_);
	void _FaceCallback(int32 PlayerIndex_, int8 Dir_);
	void _FlyCallback(int32 PlayerIndex_);
	void _LandCallback(int32 PlayerIndex_);
	void _FlapCallback(int32 PlayerIndex_);
	void _PumpCallback(int32 PlayerIndex_);
	void _PumpDoneCallback(int32 PlayerIndex_);
	void _ParachuteOnCallback(int32 PlayerIndex_, bool On_);
	void _BounceCallback(int32 PlayerIndex_);
	void _HitCallback(int32 AttackerIndex_, int32 TargetIndex_, int32 AddedPoint_);
	void _RegenCallback(int32 PlayerIndex_, const SCharacter& Character_);
};