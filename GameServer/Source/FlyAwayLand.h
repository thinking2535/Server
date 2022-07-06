#include <Rso/Physics/RectCollider2D.h>
#include <Rso/Physics/Physics.h>
#include "EngineGlobal.h"

using namespace rso;
using namespace physics;

class CFlyAwayLand : public CRectCollider2D
{
    int32 _LandNumber;
public:
    inline int32 GetLandNumber(void) const { return _LandNumber; }
private:
    int32 _Index;
public:
    CList<SFlyAwayLandObject>::iterator Iterator;
    EFlyAwayLandState State = EFlyAwayLandState::Normal;
    int64 NextActionTick = 0;
private:
    float _YVelocity = 0.0f;
public:
    CFlyAwayLand(const SPoint& LocalPosition_, int32 LandNumber_, int32 Index_) :
        CRectCollider2D(GetDefaultTransform(LocalPosition_), CEngineGlobal::c_LandNumber, g_MetaData->MapMeta.FlyAwayMapInfo.Lands[Index_].Collider),
        _LandNumber(LandNumber_),
        _Index(Index_)
    {
    }
    void Proc(int64 Tick_, const shared_ptr<CFlyAwayBattlePlayer>& pPlayer_, CFlyAwayBattle* pBattle_)
    {
    }
    inline SFlyAwayLand GetSFlyAwayLand(void) const
    {
        return SFlyAwayLand(LocalPosition, _LandNumber, _Index, State, NextActionTick);
    }
    bool StartShake(int64 Tick_);
    void FixedUpdate(Int64 Tick_);
};
