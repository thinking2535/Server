#pragma once

#include "ArrowDodgeArrowMaker.h"
#include "ArrowDodgeItemMaker.h"

struct SArrowObject
{
    CArrow* pArrow;
    CList<shared_ptr<CMovingObject2D>>::iterator ArrowIterator;

    SArrowObject(CArrow* pArrow_, const CList<shared_ptr<CMovingObject2D>>::iterator& ArrowIterator_);
    SArrow GetSArrow(void) const;
};

struct SArrowDodgeItemObject
{
    CArrowDodgeItem* pItem;
    CList<shared_ptr<CCollider2D>>::iterator ItemIterator;

    SArrowDodgeItemObject(CArrowDodgeItem* pItem_);
    SArrowDodgeItem GetSArrowDodgeItem(void) const;
};

class CArrowDodgeBattle : public CBattle
{
    static const uint32 _intItemScreenWidth;
    static const uint32 _intItemScreenHeight;

    static float _getRandomItemPointX(CFixedRandom32& fixedRandom);
    static float _getRandomItemPointY(CFixedRandom32& fixedRandom);
public:
    inline float getRandomItemPointX()
    {
        return _getRandomItemPointX(_FixedRandom);
    }
    inline float getRandomItemPointY()
    {
        return _getRandomItemPointY(_FixedRandom);
    }
    SPoint getRandomItemPoint();
private:
    const SArrowDodgeMap* _pArrowDodgeMap;
    shared_ptr<CArrowDodgeBattlePlayer> _pArrowDodgeBattlePlayer;

    CFixedRandom32 _FixedRandom{ (uint32)(system_clock::now().time_since_epoch().count() % 0xffffffff) };

    CArrowDodgeArrowMaker _ArrowMaker{ _FixedRandom };
    CArrowDodgeItemMaker _ItemMaker{ _FixedRandom };
    CList<SArrowObject> _ArrowIts;
    CList<SArrowDodgeItemObject> _ItemIts;
    TTime _EndTime = (std::chrono::time_point<std::chrono::system_clock>::max)();

protected:
    void _AddBattlePlayer(const shared_ptr<CArrowDodgeBattlePlayer>& pBattlePlayer_);
private:
    void _HitArrowCallback(const CArrow* pArrow_, bool IsDefended_);
    void _GetItemCallback(const CArrowDodgeItem* pItem_);
public:
    CArrowDodgeBattle(CUser* pUser_, TBattlesIt itBattle_);
    virtual ~CArrowDodgeBattle();
    SArrowDodgeBattleBeginNetSc GetArrowDodgeBattleBeginNetSc(void) const;
    bool Update(void) override;
    void Link(int32 PlayerIndex_) override;
private:
    void _UpdateScore(int32 AddedPoint_);
    void _AddArrow(const shared_ptr<CArrow>& pArrow_);
    void _RemoveArrow(CList<SArrowObject>::iterator ArrowObjectIt_);
    void _AddItem(const shared_ptr<CArrowDodgeItem>& pItem_);
protected:
    void _fixedUpdate() override;
};
