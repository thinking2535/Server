#pragma once

struct SFlyAwayLandObject
{
    shared_ptr<CFlyAwayLand> pLand;
    CList<shared_ptr<CCollider2D>>::iterator LandIterator;

    SFlyAwayLandObject(const shared_ptr<CFlyAwayLand>& pLand_, const CList<shared_ptr<CCollider2D>>::iterator& LandIterator_);
    SFlyAwayLand GetSFlyAwayLand(void) const;
};
struct SFlyAwayItemObject
{
    shared_ptr<CFlyAwayItem> pItem;
    CList<shared_ptr<CCollider2D>>::iterator ItemIterator;

    SFlyAwayItemObject(const shared_ptr<CFlyAwayItem>& pItem_, const CList<shared_ptr<CCollider2D>>::iterator& ItemIterator_);
    SFlyAwayItem GetSFlyAwayItem(void) const;
};

class CFlyAwayBattle : public CBattle
{
    static const float _LandTopY;
    static const float _LandBottomY;
    static const float _LandHeightRange;
    static const uint32 _IntHeightRange;
    static const int32 _MaxDistanceLandCounter;
    static const float _LimitLandDistance;
    static const float _MinLandDistance;
    static const float _LandDistanceRange;
    static const float _RandomMinLandDistance;
    static const float _RandomLandDistanceRange;
    static const int64 _LandTypeFactor;
    static const float _ItemYOffset;
    static const SPoint _InitialPos;

    shared_ptr<CObject2D> _pRootObject;
    shared_ptr<CFlyAwayBattlePlayer> _pFlyAwayBattlePlayer;
    float _XMoveDelta;
    float _LandUpYFactor;
    float _LandDownYFactor;

    CFixedRandom32 _FixedRandom{ (uint32)(system_clock::now().time_since_epoch().count() % 0xffffffff) };
    int32 _LandCounter = 0;
    CList<SFlyAwayLandObject> _LandIts;
    CList<SFlyAwayItemObject> _ItemIts;
    SPoint _LastLandPosition;
    TTime _EndTime = (std::chrono::time_point<std::chrono::system_clock>::max)();

protected:
    void _AddBattlePlayer(const shared_ptr<CFlyAwayBattlePlayer>& pBattlePlayer_);
private:
    void _RegenCallback(int32 PlayerIndex_);
    void _GetItemCallback(int64 Tick_, const shared_ptr<CFlyAwayItem>& pItem_);
    void _LandCallback(int64 Tick_, const shared_ptr<CFlyAwayLand>& pLand_);
public:
    CFlyAwayBattle(CUser* pUser_, TBattlesIt itBattle_);
    virtual ~CFlyAwayBattle();
    ERet Touch(int32 PlayerIndex_, const SBattleTouchNetCs& Proto_) override;
    SFlyAwayBattleBeginNetSc GetFlyAwayBattleBeginNetSc(void) const;
    bool Update(void) override;
    void OnLine(int32 PlayerIndex_) override;
    void OffLine(int32 PlayerIndex_) override;
private:
    void _FixedUpdate(int64 Tick_);
    void _AddLand(const shared_ptr<CFlyAwayLand>& pLand_);
    bool _LateAddLand(int64 Tick_); // true : Added
    void _RemoveLand(CList<SFlyAwayLandObject>::iterator LandObjectIt_);
    void _AddItem(const shared_ptr<CFlyAwayItem>& pItem_);
    void _LateAddItem(const SPoint& LocalPosition_);
    void _RemoveItem(CList<SFlyAwayItemObject>::iterator ItemObjectIt_);
    shared_ptr<CFlyAwayLand> _MakeLand(const SPoint& LocalPosition_, int32 Number_, int32 Index_);
    shared_ptr<CFlyAwayItem> _MakeItem(const SPoint& LocalPosition_, EFlyAwayItemType ItemType_);
};