#include <Rso/Physics/RectCollider2D.h>
#include <Rso/Physics/Physics.h>
#include "EngineGlobal.h"

using namespace rso;
using namespace physics;

class CFlyAwayItem abstract : public CRectCollider2D
{
public:
    CList<SFlyAwayItemObject>::iterator Iterator;

    CFlyAwayItem(const STransform& Transform_, SRectCollider2D Collider_) :
        CRectCollider2D(Transform_, CEngineGlobal::c_ItemNumber, Collider_)
    {
    }
    void Proc(int64 Tick_, const shared_ptr<CFlyAwayBattlePlayer>& pPlayer_, CFlyAwayBattle* pBattle_) const
    {
        pPlayer_->SetItem(g_MetaData->GetFlyAwayItemMetas()[(size_t)GetItemType()]);
    }
    virtual EFlyAwayItemType GetItemType(void) const = 0;
};
class CFlyAwayCoin : public CFlyAwayItem
{
public:
    CFlyAwayCoin(const SPoint& LocalPosition_) :
        CFlyAwayItem(GetDefaultTransform(LocalPosition_), g_MetaData->MapMeta.FlyAwayMapInfo.Coin.Collider)
    {
    }
    EFlyAwayItemType GetItemType(void) const override
    {
        return EFlyAwayItemType::Coin;
    }
};
class CFlyAwayGoldBar : public CFlyAwayItem
{
public:
    CFlyAwayGoldBar(const SPoint& LocalPosition_) :
        CFlyAwayItem(GetDefaultTransform(LocalPosition_), g_MetaData->MapMeta.FlyAwayMapInfo.GoldBar.Collider)
    {
    }
    EFlyAwayItemType GetItemType(void) const override
    {
        return EFlyAwayItemType::GoldBar;
    }
};
class CFlyAwayApple : public CFlyAwayItem
{
public:
    CFlyAwayApple(const SPoint& LocalPosition_) :
        CFlyAwayItem(GetDefaultTransform(LocalPosition_), g_MetaData->MapMeta.FlyAwayMapInfo.Apple.Collider)
    {
    }
    EFlyAwayItemType GetItemType(void) const override
    {
        return EFlyAwayItemType::Apple;
    }
};
class CFlyAwayMeat : public CFlyAwayItem
{
public:
    CFlyAwayMeat(const SPoint& LocalPosition_) :
        CFlyAwayItem(GetDefaultTransform(LocalPosition_), g_MetaData->MapMeta.FlyAwayMapInfo.Meat.Collider)
    {
    }
    EFlyAwayItemType GetItemType(void) const override
    {
        return EFlyAwayItemType::Meat;
    }
};
class CFlyAwayChicken : public CFlyAwayItem
{
public:
    CFlyAwayChicken(const SPoint& LocalPosition_) :
        CFlyAwayItem(GetDefaultTransform(LocalPosition_), g_MetaData->MapMeta.FlyAwayMapInfo.Chicken.Collider)
    {
    }
    EFlyAwayItemType GetItemType(void) const override
    {
        return EFlyAwayItemType::Chicken;
    }
};
