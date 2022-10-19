#include <Rso/Physics/RectCollider2D.h>
#include <Rso/Physics/Physics.h>
#include "EngineGlobal.h"

using namespace rso;
using namespace physics;

class CArrowDodgeItem abstract : public CRectCollider2D
{
public:
    CList<SArrowDodgeItemObject>::iterator Iterator;

    CArrowDodgeItem(const SPoint& LocalPosition_, SRectCollider2D Collider_) :
        CRectCollider2D(GetDefaultTransform(LocalPosition_), CEngineGlobal::c_ItemNumber, Collider_)
    {
        IsTrigger = true;
    }
    virtual void Proc(int64 tick, const shared_ptr<CArrowDodgeBattlePlayer>& pPlayer_, CArrowDodgeBattle* pBattle_) const
    {
        pPlayer_->SetItem(g_MetaData->GetArrowDodgeItemMetas()[(size_t)GetItemType()]);
    }
    virtual EArrowDodgeItemType GetItemType(void) const = 0;
};
class CArrowDodgeCoin : public CArrowDodgeItem
{
public:
    CArrowDodgeCoin(const SPoint& LocalPosition_) :
        CArrowDodgeItem(LocalPosition_, g_MetaData->MapMeta.ArrowDodgeMapInfo.Coin.Collider)
    {
    }
    EArrowDodgeItemType GetItemType(void) const override
    {
        return EArrowDodgeItemType::Coin;
    }
};
class CArrowDodgeGoldBar : public CArrowDodgeItem
{
public:
    CArrowDodgeGoldBar(const SPoint& LocalPosition_) :
        CArrowDodgeItem(LocalPosition_, g_MetaData->MapMeta.ArrowDodgeMapInfo.GoldBar.Collider)
    {
    }
    EArrowDodgeItemType GetItemType(void) const override
    {
        return EArrowDodgeItemType::GoldBar;
    }
};
class CArrowDodgeShield : public CArrowDodgeItem
{
public:
    CArrowDodgeShield(const SPoint& LocalPosition_) :
        CArrowDodgeItem(LocalPosition_, g_MetaData->MapMeta.ArrowDodgeMapInfo.Shield.Collider)
    {
    }
    void Proc(int64 tick, const shared_ptr<CArrowDodgeBattlePlayer>& pPlayer_, CArrowDodgeBattle* pBattle_) const override
    {
        __super::Proc(tick, pPlayer_, pBattle_);
        pPlayer_->SetShieldItem(tick, this);
    }
    EArrowDodgeItemType GetItemType(void) const override
    {
        return EArrowDodgeItemType::Shield;
    }
};
class CArrowDodgeStamina : public CArrowDodgeItem
{
public:
    CArrowDodgeStamina(const SPoint& LocalPosition_) :
        CArrowDodgeItem(LocalPosition_, g_MetaData->MapMeta.ArrowDodgeMapInfo.Stamina.Collider)
    {
    }
    void Proc(int64 tick, const shared_ptr<CArrowDodgeBattlePlayer>& pPlayer_, CArrowDodgeBattle* pBattle_) const override
    {
        __super::Proc(tick, pPlayer_, pBattle_);
        pPlayer_->SetStaminaItem(tick, this);
    }
    EArrowDodgeItemType GetItemType(void) const override
    {
        return EArrowDodgeItemType::Stamina;
    }
};
