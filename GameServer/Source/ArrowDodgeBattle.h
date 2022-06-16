#pragma once

#include "ArrowDodgeArrowMaker.h"
#include "ArrowDodgeItemMaker.h"

struct SArrowObject
{
    shared_ptr<CArrow> pArrow;
    CList<shared_ptr<CMovingObject2D>>::iterator ArrowIterator;

    SArrowObject(const shared_ptr<CArrow>& pArrow_, const CList<shared_ptr<CMovingObject2D>>::iterator& ArrowIterator_);
    SArrow GetSArrow(void) const;
};

struct SItemObject
{
    shared_ptr<CArrowDodgeItem> pItem;
    CList<shared_ptr<CCollider2D>>::iterator ItemIterator;

    SItemObject(const shared_ptr<CArrowDodgeItem>& pItem_, const CList<shared_ptr<CCollider2D>>::iterator& ItemIterator_);
    SItem GetSItem(void) const;
};

class CArrowDodgeBattle : public CBattle
{
    const int32 _MaxItemCount = 10;

    shared_ptr<CObject2D> _pRootObject;
    shared_ptr<CArrowDodgeBattlePlayer> _pArrowDodgeBattlePlayer;

    CFixedRandom _FixedRandom{ (uint64)((((uint64)rand()) << 32) + rand()), 0 };

    CArrowDodgeArrowMaker _ArrowMaker{ _FixedRandom };
    CArrowDodgeItemMaker _ItemMaker{ _FixedRandom };
    CList<SArrowObject> _ArrowIts;
    CList<SItemObject> _ItemIts;
    TTime _EndTime = (std::chrono::time_point<std::chrono::system_clock>::max)();

public:
    bool ForceEnd = false;

protected:
    void _AddBattlePlayer(const shared_ptr<CArrowDodgeBattlePlayer>& pBattlePlayer_);
private:
    void _RegenCallback(int32 PlayerIndex_);
    void _HitArrowCallback(const shared_ptr<CArrow>& pArrow_);
    void _GetItemCallback(const shared_ptr<CArrowDodgeItem>& pItem_);
public:
    CArrowDodgeBattle(CUser* pUser_, TBattlesIt itBattle_);
    virtual ~CArrowDodgeBattle();
    void _SyncMessage(int64 Tick_);
    SArrowDodgeBattleBeginNetSc GetArrowDodgeBattleBeginNetSc(void) const;
    bool Update(void) override;
    void OnLine(int32 PlayerIndex_) override;
    void OffLine(int32 PlayerIndex_) override;
private:
    void _FixedUpdate(int64 Tick_);
    void _AddArrow(const shared_ptr<CArrow>& pArrow_);
    void _RemoveArrow(CList<SArrowObject>::iterator ArrowObjectIt_);
    void _AddItem(const shared_ptr<CArrowDodgeItem>& pItem_);
    void _RemoveItem(CList<SItemObject>::iterator ItemObjectIt_);
};