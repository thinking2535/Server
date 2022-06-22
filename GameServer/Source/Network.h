#pragma once

ERet ChatNetCs(CUser* User_, CStream& Stream_);
ERet FCMTokenSetNetCs(CUser* User_, CStream& Stream_);
ERet FCMTokenUnsetNetCs(CUser* User_, CStream& Stream_);
ERet FCMCanPushAtNightNetCs(CUser* User_, CStream& Stream_);
ERet ChangeLanguageNetCs(CUser* User_, CStream& Stream_);
ERet BuyNetCs(CUser* User_, CStream& Stream_);
ERet BuyCharNetCs(CUser* User_, CStream& Stream_);
ERet BuyPackageNetCs(CUser* User_, CStream& Stream_);
ERet PurchaseNetCs(CUser* User_, CStream& Stream_);
ERet DailyRewardNetCs(CUser* User_, CStream& Stream_);

ERet SelectCharNetCs(CUser* User_, CStream& Stream_);
ERet IslandStartNetCs(CUser* User_, CStream& Stream_);
ERet IslandEndNetCs(CUser* User_, CStream& Stream_);

ERet BattleTouchNetCs(CUser* User_, CStream& Stream_);
ERet BattlePushNetCs(CUser* User_, CStream& Stream_);

ERet MultiBattleJoinNetCs(CUser* User_, CStream& Stream_);
ERet MultiBattleOutNetCs(CUser* User_, CStream& Stream_);
ERet MultiBattleIconNetCs(CUser* User_, CStream& Stream_);

ERet ArrowDodgeBattleJoinNetCs(CUser* User_, CStream& Stream_);
ERet ArrowDodgeBattleEndNetCs(CUser* User_, CStream& Stream_);

ERet GachaNetCs(CUser* User_, CStream& Stream_);
ERet GachaX10NetCs(CUser* User_, CStream& Stream_);
ERet RankRewardNetCs(CUser* User_, CStream& Stream_);
ERet QuestRewardNetCs(CUser* User_, CStream& Stream_);
ERet QuestNextNetCs(CUser* User_, CStream& Stream_);
ERet QuestDailyCompleteRewardNetCs(CUser* User_, CStream& Stream_);
ERet ChangeNickNetCs(CUser* User_, CStream& Stream_);
ERet CouponUseNetCs(CUser* User_, CStream& Stream_);
ERet TutorialRewardNetCs(CUser* User_, CStream& Stream_);
ERet RankingRewardInfoNetCs(CUser* User_, CStream& Stream_);
ERet RankingRewardNetCs(CUser* User_, CStream& Stream_);

void ReceiptInitializeNetMs(const CKey& Key_, CStream& Stream_);
void ReceiptAccessTokenNetMs(const CKey& Key_, CStream& Stream_);
