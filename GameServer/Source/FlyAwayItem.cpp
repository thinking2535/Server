#include "stdafx.h"

CFlyAwayItem::CFlyAwayItem(const STransform& Transform_, SRectCollider2D Collider_) :
    CFlyAwayObject(Transform_, CEngineGlobal::c_ItemNumber, Collider_)
{
    IsTrigger = true;
}
void CFlyAwayItem::Proc(const shared_ptr<CFlyAwayBattlePlayer>& pPlayer_, CFlyAwayBattle* pBattle_) const
{
    pPlayer_->SetItem(g_MetaData->GetFlyAwayItemMetas()[(size_t)GetItemType()]);
}
