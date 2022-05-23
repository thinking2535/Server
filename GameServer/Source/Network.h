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
ERet SingleStartNetCs(CUser* User_, CStream& Stream_);
ERet SingleEndNetCs(CUser* User_, CStream& Stream_);
ERet IslandStartNetCs(CUser* User_, CStream& Stream_);
ERet IslandEndNetCs(CUser* User_, CStream& Stream_);
ERet BattleJoinNetCs(CUser* User_, CStream& Stream_);
ERet BattleOutNetCs(CUser* User_, CStream& Stream_);

ERet BattleTouchNetCs(CUser* User_, CStream& Stream_);
ERet BattlePushNetCs(CUser* User_, CStream& Stream_);
ERet BattleIconNetCs(CUser* User_, CStream& Stream_);
ERet SingleBattleIconNetCs(CUser* User_, CStream& Stream_);
ERet SingleBattleScoreNetCs(CUser* User_, CStream& Stream_);
ERet SingleBattleItemNetCs(CUser* User_, CStream& Stream_);

ERet RoomListNetCs(CUser* User_, CStream& Stream_);
ERet RoomCreateNetCs(CUser* User_, CStream& Stream_);
ERet RoomJoinNetCs(CUser* User_, CStream& Stream_);
ERet RoomOutNetCs(CUser* User_, CStream& Stream_);
ERet RoomReadyNetCs(CUser* User_, CStream& Stream_);
ERet RoomChatNetCs(CUser* User_, CStream& Stream_);
ERet RoomNotiNetCs(CUser* User_, CStream& Stream_);

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
