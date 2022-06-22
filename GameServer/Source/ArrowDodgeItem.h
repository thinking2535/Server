#include <Rso/Physics/RectCollider2D.h>
#include <Rso/Physics/Physics.h>
#include "EngineGlobal.h"

using namespace rso;
using namespace physics;

class CArrowDodgeItem abstract : public CRectCollider2D
{
public:
    CList<SItemObject>::iterator Iterator;

    CArrowDodgeItem(const STransform& Transform_, int32 Number_, SRectCollider2D Collider_) :
        CRectCollider2D(Transform_, Number_, Collider_)
    {
    }
    virtual void Proc(int64 Tick_, const shared_ptr<CArrowDodgeBattlePlayer>& pPlayer_, CArrowDodgeBattle* pBattle_) const = 0;
};
class CArrowDodgeCoin : public CArrowDodgeItem
{
public:
    CArrowDodgeCoin(const SPoint& LocalPosition_) :
        CArrowDodgeItem(GetDefaultTransform(LocalPosition_), CEngineGlobal::c_CoinNumber, g_MetaData->MapMeta.ArrowDodgeMapInfo.Coin.Collider)
    {
    }
    void Proc(int64 Tick_, const shared_ptr<CArrowDodgeBattlePlayer>& pPlayer_, CArrowDodgeBattle* pBattle_) const override
    {
        pPlayer_->SetCoinItem(this);
    }
};
class CArrowDodgeGoldBar : public CArrowDodgeItem
{
public:
    CArrowDodgeGoldBar(const SPoint& LocalPosition_) :
        CArrowDodgeItem(GetDefaultTransform(LocalPosition_), CEngineGlobal::c_GoldBarNumber, g_MetaData->MapMeta.ArrowDodgeMapInfo.GoldBar.Collider)
    {
    }
    void Proc(int64 Tick_, const shared_ptr<CArrowDodgeBattlePlayer>& pPlayer_, CArrowDodgeBattle* pBattle_) const override
    {
        pPlayer_->SetGoldBarItem(this);
    }
};
class CArrowDodgeShield : public CArrowDodgeItem
{
public:
    CArrowDodgeShield(const SPoint& LocalPosition_) :
        CArrowDodgeItem(GetDefaultTransform(LocalPosition_), CEngineGlobal::c_ShieldNumber, g_MetaData->MapMeta.ArrowDodgeMapInfo.Shield.Collider)
    {
    }
    void Proc(int64 Tick_, const shared_ptr<CArrowDodgeBattlePlayer>& pPlayer_, CArrowDodgeBattle* pBattle_) const override
    {
        pPlayer_->SetShieldItem(Tick_, this);
    }
};
class CArrowDodgeStamina : public CArrowDodgeItem
{
public:
    CArrowDodgeStamina(const SPoint& LocalPosition_) :
        CArrowDodgeItem(GetDefaultTransform(LocalPosition_), CEngineGlobal::c_StaminaNumber, g_MetaData->MapMeta.ArrowDodgeMapInfo.Stamina.Collider)
    {
    }
    void Proc(int64 Tick_, const shared_ptr<CArrowDodgeBattlePlayer>& pPlayer_, CArrowDodgeBattle* pBattle_) const override
    {
        pPlayer_->SetStaminaItem(Tick_, this);
    }
};
