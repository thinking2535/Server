#include "stdafx.h"

extern TReceiptCheck g_ReceiptCheck;

void ReceiptCheckCallback(const TOrder& Order_, const string& OrderID_, int64 PurchaseTime_, int32 PurchaseType_, int32 ConsumptionState_)
{
	auto User = g_Users.get_with_uid(Order_.UID);
	if (!User)
	{
		LOG(L"ReceiptCheckCallback User Not Found UID[%d] ProductID[%s] OrderID[%s] PurchaseType[%d]", Order_.UID, MBSToWCS(Order_.ProductID), MBSToWCS(OrderID_), PurchaseType_);
		return;
	}

	try
	{
		auto Ret = User->ReceiptCheck(Order_, OrderID_, PurchaseTime_, PurchaseType_);
		if (Ret != ERet::Ok)
		{
			LOG(L"ReceiptCheck Error UID[%d] ProductID[%s] OrderID[%s] PurchaseType[%d] Ret[%d]", Order_.UID, MBSToWCS(Order_.ProductID), MBSToWCS(OrderID_), PurchaseType_, int32(Ret));
			User->SendRet(Ret);
		}
	}
	catch (...)
	{
		LOG(L"ReceiptCheck Catch UID[%d] ProductID[%s] OrderID[%s] PurchaseType[%d]", Order_.UID, MBSToWCS(Order_.ProductID), MBSToWCS(OrderID_), PurchaseType_);
	}
}
void ReceiptErrorCallback(const TOrder& Order_, int32 PurchaseState_)
{
	auto User = g_Users.get_with_uid(Order_.UID);
	if (!User)
	{
		LOG(L"ReceiptErrorCallback User Not Found UID[%d] ProductID[%s] PurchaseState[%d]", Order_.UID, MBSToWCS(Order_.ProductID), PurchaseState_);
		return;
	}

	// 에러 나더라도 클라의 영수증 소진시키도록 처리
	User->SendSPurchaseNetSc(Order_.ProductID, 0);
	LOG(L"ReceiptErrorCallback UID[%d] ProductID[%s] PurchaseState[%d]", Order_.UID, MBSToWCS(Order_.ProductID), PurchaseState_);
}
ERet ChatNetCs(CUser* User_, CStream& Stream_)
{
	SChatNetCs Proto;
	Stream_ >> Proto;

	if (User_->GetDebug() <= 0 || !g_Command.Call(Proto.Msg, *User_))
		return User_->Chat(Proto);

	return ERet::Ok;
}
ERet FCMTokenSetNetCs(CUser* User_, CStream& Stream_)
{
	SFCMTokenSetNetCs Proto;
	Stream_ >> Proto;

	return User_->ChangeFSM(Proto);
}
ERet FCMTokenUnsetNetCs(CUser* User_, CStream& Stream_)
{
	SFCMTokenUnsetNetCs Proto;
	Stream_ >> Proto;
	SendM(SFCMTokenUnsetNetSm(User_->GetUID()));
	return ERet::Ok;
}
ERet FCMCanPushAtNightNetCs(CUser* User_, CStream& Stream_)
{
	SFCMCanPushAtNightNetCs Proto;
	Stream_ >> Proto;

	return User_->CanPushAtNight(Proto);
}
ERet ChangeLanguageNetCs(CUser* User_, CStream& Stream_)
{
	SChangeLanguageNetCs Proto;
	Stream_ >> Proto;
	return User_->ChangeLanguage(Proto);
}
ERet BuyNetCs(CUser* User_, CStream& Stream_)
{
	SBuyNetCs Proto;
	Stream_ >> Proto;

	return User_->Buy(Proto);
}
ERet BuyCharNetCs(CUser* User_, CStream& Stream_)
{
	SBuyCharNetCs Proto;
	Stream_ >> Proto;

	return User_->BuyChar(Proto);
}
ERet BuyPackageNetCs(CUser* User_, CStream& Stream_)
{
	SBuyPackageNetCs Proto;
	Stream_ >> Proto;

	return User_->BuyPackage(Proto);
}
ERet PurchaseNetCs(CUser* User_, CStream& Stream_)
{
	SPurchaseNetCs Proto;
	Stream_ >> Proto;

	return User_->Purchase(Proto);
}
ERet DailyRewardNetCs(CUser* User_, CStream& Stream_)
{
	SDailyRewardNetCs Proto;
	Stream_ >> Proto;

	return User_->DailyReward(Proto);
}

ERet SelectCharNetCs(CUser* User_, CStream& Stream_)
{
	SSelectCharNetCs Proto;
	Stream_ >> Proto;

	return User_->SelectChar(Proto);
}
ERet IslandStartNetCs(CUser* User_, CStream& Stream_)
{
	SIslandStartNetCs Proto;
	Stream_ >> Proto;

	return User_->IslandStart(Proto);
}
ERet IslandEndNetCs(CUser* User_, CStream& Stream_)
{
	SIslandEndNetCs Proto;
	Stream_ >> Proto;

	return User_->IslandEnd(Proto);
}

ERet BattleTouchNetCs(CUser* User_, CStream& Stream_)
{
	SBattleTouchNetCs Proto;
	Stream_ >> Proto;

	return User_->BattleTouch(Proto);
}
ERet BattlePushNetCs(CUser* User_, CStream& Stream_)
{
	SBattlePushNetCs Proto;
	Stream_ >> Proto;

	return User_->BattlePush(Proto);
}

ERet MultiBattleJoinNetCs(CUser* User_, CStream& Stream_)
{
	SMultiBattleJoinNetCs Proto;
	Stream_ >> Proto;

	auto it = g_Matches.find(Proto.BattleType);
	if (it == g_Matches.end())
		return ERet::InvalidBattleType;

	auto Ret = User_->MultiBattleJoin();
	if (Ret != ERet::Ok)
		return Ret;

	try
	{
		if (!it->second->insert((double)User_->GetPoint(), User_->Key().PeerNum))
			throw ERet::MatchInsertFail;
	}
	catch (const ERet Ret_)
	{
		User_->MultiBattleOut();
		return Ret_;
	}

	return ERet::Ok;
}
ERet MultiBattleOutNetCs(CUser* User_, CStream& Stream_)
{
	SMultiBattleOutNetCs Proto;
	Stream_ >> Proto;

	auto Ret = User_->MultiBattleOut();
	if (Ret == ERet::AlreadyInBattle)
		return ERet::Ok;

	if (Ret != ERet::Ok)
		return Ret;

	for (auto& i : g_Matches)
		i.second->erase(User_->Key().PeerNum);

	return ERet::Ok;
}
ERet MultiBattleIconNetCs(CUser* User_, CStream& Stream_)
{
	SMultiBattleIconNetCs Proto;
	Stream_ >> Proto;

	return User_->MultiBattleIcon(Proto);
}

ERet ArrowDodgeBattleJoinNetCs(CUser* User_, CStream& Stream_)
{
	SArrowDodgeBattleJoinNetCs Proto;
	Stream_ >> Proto;

	return User_->ArrowDodgeBattleJoin();
}
ERet ArrowDodgeBattleEndForceNetCs(CUser* User_, CStream& Stream_)
{
	SArrowDodgeBattleEndForceNetCs Proto;
	Stream_ >> Proto;

	return User_->ArrowDodgeBattleEndForce(Proto);
}

ERet GachaNetCs(CUser* User_, CStream& Stream_)
{
	SGachaNetCs Proto;
	Stream_ >> Proto;

	return User_->Gacha(Proto);
}

ERet GachaX10NetCs(CUser* User_, CStream& Stream_)
{
	SGachaX10NetCs Proto;
	Stream_ >> Proto;

	return User_->GachaX10(Proto);
}
ERet RankRewardNetCs(CUser* User_, CStream& Stream_)
{
	SRankRewardNetCs Proto;
	Stream_ >> Proto;

	return User_->RankReward(Proto);
}
ERet QuestRewardNetCs(CUser* User_, CStream& Stream_)
{
	SQuestRewardNetCs Proto;
	Stream_ >> Proto;

	return User_->QuestReward(Proto);
}
ERet QuestNextNetCs(CUser* User_, CStream& Stream_)
{
	SQuestNextNetCs Proto;
	Stream_ >> Proto;

	return User_->QuestNext(Proto);
}
ERet QuestDailyCompleteRewardNetCs(CUser* User_, CStream& Stream_)
{
	SQuestDailyCompleteRewardNetCs Proto;
	Stream_ >> Proto;

	return User_->QuestDailyCompleteReward(Proto);
}
ERet ChangeNickNetCs(CUser* User_, CStream& Stream_)
{
	SChangeNickNetCs Proto;
	Stream_ >> Proto;

	return User_->ChangeNickRequest(Proto);
}

ERet CouponUseNetCs(CUser* User_, CStream& Stream_)
{
	SCouponUseNetCs Proto;
	Stream_ >> Proto;

	return User_->CouponUse(Proto);
}
ERet TutorialRewardNetCs(CUser* User_, CStream& Stream_)
{
	STutorialRewardNetCs Proto;
	Stream_ >> Proto;

	return User_->TutorialReward(Proto);
}
ERet RankingRewardInfoNetCs(CUser* User_, CStream& Stream_)
{
	SRankingRewardInfoNetCs Proto;
	Stream_ >> Proto;

	return User_->RankingRewardInfo(Proto);
}
ERet RankingRewardNetCs(CUser* User_, CStream& Stream_)
{
	SRankingRewardNetCs Proto;
	Stream_ >> Proto;

	return User_->RankingReward(Proto);
}

void ReceiptInitializeNetMs(const CKey& /*Key_*/, CStream& Stream_)
{
	SReceiptInitializeNetMs Proto;
	Stream_ >> Proto;

	g_ReceiptCheck.reset(new CReceiptCheck(2, ReceiptCheckCallback, ReceiptErrorCallback, Proto.PackageName, Proto.AccessToken));
}
void ReceiptAccessTokenNetMs(const CKey& /*Key_*/, CStream& Stream_)
{
	SReceiptAccessTokenNetMs Proto;
	Stream_ >> Proto;

	g_ReceiptCheck->SetAccessToken(Proto.Token);
}
