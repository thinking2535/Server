#pragma once

#include "FlyAwayPathMaker.h"

struct SFlyAwayLandObject
{
    CFlyAwayLand* pLand;
    CList<shared_ptr<CCollider2D>>::iterator LandIterator;

    SFlyAwayLandObject(CFlyAwayLand* pLand_, const CList<shared_ptr<CCollider2D>>::iterator& LandIterator_);
    SFlyAwayLand GetSFlyAwayLand(void) const;
};
struct SFlyAwayItemObject
{
    CFlyAwayItem* pItem;
    CList<shared_ptr<CCollider2D>>::iterator ItemIterator;

    SFlyAwayItemObject(CFlyAwayItem* pItem_, const CList<shared_ptr<CCollider2D>>::iterator& ItemIterator_);
    SFlyAwayItem GetSFlyAwayItem(void) const;
};

class CFlyAwayBattle : public CBattle
{
    static const float _InitialPosX;

    const SFlyAwayMap* _pFlyAwayMap;
    shared_ptr<CFlyAwayBattlePlayer> _pFlyAwayBattlePlayer;
    float _XMoveDelta;
    float _itemXDistance;
    float _itemLandXDistance;

    CFixedRandom32 _FixedRandom{ (uint32)(system_clock::now().time_since_epoch().count() % 0xffffffff) };
    FlyAwayPathMaker _pathMaker{ flyAwayMinY, flyAwayMaxY, flyAwayMainLevelCount, flyAwaySubLevelCount, _FixedRandom };
    int32 _LandCounter = 0;
    CList<SFlyAwayLandObject> _LandIts;
    CList<SFlyAwayItemObject> _ItemIts;
    SPoint _LastLandPosition{ _InitialPosX, _pathMaker.getCurrentY() - _getItemLandYDistance()};
    TTime _EndTime = (std::chrono::time_point<std::chrono::system_clock>::max)();

    void _GetItemCallback(const CFlyAwayItem* pItem_);
    void _LandCallback(const CFlyAwayLand* pLand_);
    void _deadCallback();
public:
    CFlyAwayBattle(CUser* pUser_, TBattlesIt itBattle_);
    virtual ~CFlyAwayBattle();
    ERet Touch(int32 PlayerIndex_, const SBattleTouchNetCs& Proto_) override;
    SFlyAwayBattleBeginNetSc GetFlyAwayBattleBeginNetSc(void) const;
    bool Update(void) override;
    void Link(int32 PlayerIndex_) override;
private:
    void _AddLand(const shared_ptr<CFlyAwayLand>& pLand_);
    bool _LateAddLand(); // true : Added
    void _RemoveLand(CList<SFlyAwayLandObject>::iterator LandObjectIt_);
    void _AddItem(const shared_ptr<CFlyAwayItem>& pItem_);
    void _LateAddItem(const SPoint& LocalPosition_);
    void _RemoveItem(CList<SFlyAwayItemObject>::iterator ItemObjectIt_);
    shared_ptr<CFlyAwayLand> _MakeLand(const SPoint& LocalPosition_, int32 Number_, int32 Index_);
    shared_ptr<CFlyAwayItem> _MakeItem(const SPoint& LocalPosition_, EFlyAwayItemType ItemType_);
    float _getItemLandYDistance() const
    {
        return _pathMaker.getVerticalStep() * flyAwayItemCoinXDistanceMultiplier;
    }
protected:
    void _fixedUpdate() override;
};