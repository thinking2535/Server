#include "stdafx.h"
#include <GameServer/Common/Base.h>
#include "User.h"

CUser::CUser(TSessionsIt itSession_) :
	_itSession(itSession_)
{
}
TLevel CUser::GetLevel(void) const
{
	return g_MetaData->ExpToLevel(_User.Exp);
}
void CUser::SendRet(ERet Ret_)
{
	::SendRet(Key(), Ret_);
	WillClose();
}
void CUser::SendMsg(const wstring& Msg_)
{
	::SendMsg(Key(), Msg_);
}
void CUser::RetAndClose(ERet Ret_)
{
	SendRet(Ret_);
	WillClose();
}
void CUser::_QuestRefresh(void)
{
	TQuestSlotIndexCodes NewQuests;

	_Quest.Refresh(NewQuests);

	if (!NewQuests.empty())
	{
		Push(SQuestNewDBIn(GetUID(), NewQuests));
		Send(SQuestGotNetSc(std::move(NewQuests)));
	}
}
void CUser::Certify(void)
{
	g_Net->Certify(Key());
	_SendLogin();
	_QuestRefresh();
}
void CUser::CertifyAndLobby(void)
{
	_IsDataLoaded = true;
	Certify();
	Send(SLobbyNetSc());
}
void CUser::Login(ELanguage Language_, const SUserLoginInfo& Info_)
{
	_User.Language = Language_;
	_LoginInfo = Info_;
	Push(GetLoginDBIn(GetUID(), Info_));
}
void CUser::LoginAfterBattle(const SUserLoginInfo& Info_)
{
	_LoginInfo = Info_;
	Certify();

	if (InBattle())
		_pBattlePlayer->OnLine();
	else
		Send(SLobbyNetSc());
}
void CUser::Logout(void)
{
	if (InBattle())
		_pBattlePlayer->OffLine();

	g_BulkCopyConnect->Push(SConnectDBIn(_LoginInfo.Time, system_clock::now(), GetUID(), _LoginInfo.Option.OS, _LoginInfo.CountryCodeMinuteOffset.CountryCode, _NewRegistered));
	_LoginInfo.Key = CKey(); // 결제 중에 나가더라도 이후 진행 시킬 수 있으므로 _LoginInfo = SUserLoginInfo(); 로 처리하여도 상관없을듯 하나 그냥 안전하게 Key만 초기화.
}
void CUser::AddExp(TExp Exp_)
{
	auto MaxExp = g_MetaData->GetMaxExp();

	if (_User.Exp + Exp_ < _User.Exp ||
		_User.Exp + Exp_ > MaxExp)
		_User.Exp = MaxExp;
	else
		_User.Exp += Exp_;
}
void CUser::SetLoginDBOutCore(SLoginDBOut& Out_)
{
	auto it = Out_.Users.begin();
	if (it == Out_.Users.end())
		throw ERet::UserDoesNotExist;

	_User = Out_.Users.front();
	_Chars = std::move(Out_.Chars);

	_pSelectedChar = g_MetaData->GetCharacter(_User.SelectedCharCode);
	if (_pSelectedChar == nullptr ||
		_Chars.find(_User.SelectedCharCode) == _Chars.end())
	{
		auto itBeginChar = _Chars.begin();
		if (itBeginChar == _Chars.end())
			throw ERet::InvalidCharCode;

		_pSelectedChar = g_MetaData->GetCharacter(*itBeginChar);
		if (_pSelectedChar == nullptr)
			throw ERet::InvalidCharCode;

		_User.SelectedCharCode = *itBeginChar;
	}

	list<TQuestSlotIndex> QuestsNotExist;

	for (auto& i : Out_.Quests)
	{
		if (!_Quest.Add(i))
			QuestsNotExist.emplace_back(i.first);
	}

	if (!QuestsNotExist.empty())
		Push(SQuestDelDBIn(GetUID(), QuestsNotExist));

	_Coupons = std::move(Out_.Coupons);
	_Packages = std::move(Out_.Packages);

	if (_User.NewNick.empty())
		CertifyAndLobby();
	else
		ChangeNickBeginDB();
}
void CUser::SetJoinDBOut(SLoginDBOut& Out_)
{
	SetLoginDBOutCore(Out_);
	_NewRegistered = true;
}
void CUser::SetLoginDBOut(SLoginDBOut& Out_)
{
	auto Now = steady_now();

	auto it = Out_.Users.begin();
	if (it == Out_.Users.end())
	{
		auto Now = system_clock::now();

		Push(SJoinDBIn(
			GetUID(),
			SJoinDB(
				SUserCore(
					TResources{},
					0,
					g_MetaData->GetDefaultChar(),
					g_MetaData->ArrowDodgeMeta.PlayCountMax,
					Now,
					g_MetaData->IslandMeta.PlayCountMax,
					Now,
					Now,
					g_MetaData->ConfigMeta.ChangeNickFreeCount,
					Now + minutes(g_MetaData->ShopConfig.DailyRewardDurationMinute),
					g_MetaData->ShopConfig.DailyRewardFreeCount + g_MetaData->ShopConfig.DailyRewardAdCount)),
				Now,
				_User.Language,
				_LoginInfo.Option.OS,
				_LoginInfo.CountryCodeMinuteOffset.CountryCode,
				g_MetaData->DefaultChars));
	}
	else
	{
		SetLoginDBOutCore(Out_);
	}
}

void CUser::_SendLogin(void)
{
	Send(SLoginNetSc(SUserNet(_User, GetCountryCode()), _Chars, system_clock::now(), _Quest.GetQuestDBs(), _Packages));
}
ERet CUser::Buy(const SBuyNetCs& Proto_)
{
	auto itGoods = g_MetaData->GoodsItems.find(Proto_.Code);
	if (itGoods == g_MetaData->GoodsItems.end())
		return ERet::InvalidGoodsID;

	if (!HaveCost(itGoods->second.Cost))
		return ERet::NotEnoughMoney;

	SubResourcesCore(itGoods->second.Cost);
	Push(SBuyDBIn(RewardCore(*itGoods->second.pReward, 1)));
	Send(SBuyNetSc(Proto_.Code));
	
	return ERet::Ok;
}
ERet CUser::BuyChar(const SBuyCharNetCs& Proto_)
{
	if (_Chars.find(Proto_.Code) != _Chars.end())
		return ERet::InvalidProtocol;

	auto pChar = g_MetaData->GetCharacter(Proto_.Code);
	if (!HaveCost(pChar->Cost_Type, pChar->Price))
	{
		return ERet::NotEnoughMoney;
	}

	SubResourceCore(pChar->Cost_Type, pChar->Price);
	_Chars.emplace(Proto_.Code);

	Push(SBuyCharDBIn(GetUID(), _User.Resources, Proto_.Code));
	Send(SBuyCharNetSc(Proto_.Code));

	return ERet::Ok;
}
ERet CUser::BuyPackage(const SBuyPackageNetCs& Proto_)
{
	auto itPackage = g_MetaData->Packages.find(Proto_.Code);
	if (itPackage == g_MetaData->Packages.end())
		return ERet::InvalidProtocol;

	//if (_Packages.find(Proto_.Code) != _Packages.end())
	//	return ERet::AlreadyHave;

	if (!HaveCost(itPackage->second.CostType, itPackage->second.CostValue))
		return ERet::NotEnoughMoney;

	SubResourceCore(itPackage->second.CostType, itPackage->second.CostValue);
	//_Packages.emplace(Proto_.Code);

	Push(SBuyPackageDBIn(RewardCore(*itPackage->second.pReward, 1), Proto_.Code));
	Send(SBuyPackageNetSc(Proto_.Code));

	return ERet::Ok;
}
ERet CUser::Purchase(const SPurchaseNetCs& Proto_)
{
	LOG(L"Purchase Try UID[%d] ProductID[%s] Token[%s]", GetUID(), Proto_.ProductID, Proto_.PurchaseToken);

	if (!g_ReceiptCheck->Check(_LoginInfo.Option.OS, TOrder(GetUID(), WCSToMBS(Proto_.ProductID), WCSToMBS(Proto_.PurchaseToken))))
	{
		LOG(L"Purchase ReceiptCheckFail");

		return ERet::ReceiptCheckFail;
	}

	return ERet::Ok;
}
ERet CUser::ReceiptCheck(const TOrder& Order_, const string& OrderID_, int64 PurchaseTime_, int32 PurchaseType_)
{
	LOG(L"Purchase ReceiptCheck Callback UID[%d] ProductID[%s] Token[%s]", GetUID(), MBSToWCS(Order_.ProductID), MBSToWCS(Order_.PurchaseToken));

	auto it = g_MetaData->CashItems.find(MBSToWCS(Order_.ProductID));
	if (it == g_MetaData->CashItems.end())
	{
		LOG(L"Purchase InvalidShopID");

		return ERet::InvalidShopID;
	}

	Push(SPurchaseDBIn(_LoginInfo.Option.OS, OrderID_, GetUID(), _LoginInfo.CountryCodeMinuteOffset.CountryCode, PurchaseTime_, PurchaseType_, Order_.ProductID, it->second.DiaCount));

	return ERet::Ok;
}
void CUser::SendSPurchaseNetSc(const string& ProductID_, TResource PaidDiaAdded_)
{
	Send(SPurchaseNetSc(MBSToWCS(ProductID_), PaidDiaAdded_));
}
void CUser::PurchaseDB(const SPurchaseDBIn& In_, int32 SPRet_)
{
	if (SPRet_ == 0)
	{
		AddResourceCore(EResource::DiaPaid, In_.DiaCount);
		LOG(L"PurchaseDB OK UID[%d] ProductID[%s]", GetUID(), MBSToWCS(In_.ProductID));
	}
	else if (SPRet_ == 2601 || SPRet_ == 2627)
	{
		LOG(L"PurchaseDB Duplicate UID[%d] ProductID[%s] SPRet[%d]", GetUID(), MBSToWCS(In_.ProductID), SPRet_);
	}
	else // 중복 요청
	{
		LOG(L"PurchaseDB SPError UID[%d] ProductID[%s] SPRet[%d]", GetUID(), MBSToWCS(In_.ProductID), SPRet_);
		throw ERet::SPError;
	}

	SendSPurchaseNetSc(In_.ProductID, In_.DiaCount);
}
void CUser::ChangeNickBeginDB(void)
{
	g_Net->ChangeNick(SSmChangeNick(GetUID(), _User.NewNick, GetKey()));
}
void CUser::ChangeNickEndDB(void)
{
	_User.NewNick = u"";

	if (_IsDataLoaded)
		Send(SChangeNickNetSc(_itSession->second.Account.Nick));
	else
		CertifyAndLobby();
}
void CUser::ChangeNickEndFailDB(EGameRet GameRet_)
{
	_User.NewNick = u"";

	if (_IsDataLoaded)
		Send(SChangeNickFailNetSc(GameRet_, L""));
	else
		CertifyAndLobby();
}
ERet CUser::DailyReward(const SDailyRewardNetCs& Proto_)
{
	auto Now = system_clock::now();

	if (Now >= _User.DailyRewardExpiredTime)
	{
		_User.DailyRewardExpiredTime += (((Now - _User.DailyRewardExpiredTime) / minutes(g_MetaData->ShopConfig.DailyRewardDurationMinute)) + 1) * minutes(g_MetaData->ShopConfig.DailyRewardDurationMinute);
		_User.DailyRewardCountLeft = g_MetaData->ShopConfig.DailyRewardAdCount + g_MetaData->ShopConfig.DailyRewardFreeCount;
	}

	if (_User.DailyRewardCountLeft <= 0 || (_User.DailyRewardCountLeft <= g_MetaData->ShopConfig.DailyRewardAdCount && !Proto_.IsWatchedAd))
	{
		Send(SDailyRewardFailNetSc());
		return ERet::Ok;
	}

	--_User.DailyRewardCountLeft;
	auto& DailyRewardMeta = g_MetaData->DailyReward.Get();

	AddResourceCore(DailyRewardMeta.RewardType, DailyRewardMeta.RewardValue);
	Push(SDailyRewardDBIn(GetUID(), _User.Resources, _User.DailyRewardExpiredTime, _User.DailyRewardCountLeft));
	Send(SDailyRewardNetSc(SResourceTypeData(DailyRewardMeta.RewardType, DailyRewardMeta.RewardValue), _User.DailyRewardExpiredTime, _User.DailyRewardCountLeft));

	return ERet::Ok;
}

void CUser::SetLevel(TLevel Level_)
{
	_User.Exp = g_MetaData->LevelToExp(Level_);
	Push(SSetUserExpDBIn(GetUID(), _User.Exp));
	Send(SUserExpNetSc(_User.Exp));
}
bool CUser::HaveCost(EResource CostType_, TResource Cost_)
{
	return ::HaveCost(_User.Resources, CostType_, Cost_);
}
bool CUser::HaveCost(const TResources& Cost_)
{
	return ::HaveCost(_User.Resources, Cost_);
}
void CUser::AddResourceCore(EResource Resource_, TResource Data_)
{
	::AddResource(_User.Resources, Resource_, Data_);
}
void CUser::SubResourceCore(EResource Resource_, TResource Data_)
{
	::SubResource(_User.Resources, Resource_, Data_);
}
void CUser::AddResourcesCore(const TResources& Resources_)
{
	::AddResources(_User.Resources, Resources_);
}
void CUser::SubResourcesCore(const TResources& Resources_)
{
	::SubResources(_User.Resources, Resources_);
}
void CUser::AddResources(const TResources& Resources_)
{
	AddResourcesCore(Resources_);
	Push(SSetResourcesDBIn(GetUID(), _User.Resources));
	Send(SResourcesNetSc(_User.Resources));
}
void CUser::SetResources(const TResources& Resources_)
{
	::SetResources(_User.Resources, Resources_);
	Push(SSetResourcesDBIn(GetUID(), _User.Resources));
	Send(SResourcesNetSc(_User.Resources));
}
void CUser::SetPoint(int32 Point_)
{
	_User.Point = Point_;
	if (_User.Point > _User.PointBest)
		_User.PointBest = _User.Point;

	Push(SSetPointDBIn(GetUID(), _User.Point, _User.PointBest));
	Send(SSetPointNetSc(Point_));
}
void CUser::SetChar(list<int32>& CharCodes_)
{
	if (CharCodes_.empty())
	{
		for (auto& i : g_MetaData->GetCharacters())
		{
			auto ib = _Chars.emplace(i.first);
			if (!ib.second)
				continue;

			CharCodes_.emplace_back(i.first);
		}
	}
	else
	{
		for (auto it = CharCodes_.begin(); it != CharCodes_.end(); )
		{
			auto itCheck = it;
			++it;

			auto ib = _Chars.emplace(*itCheck);
			if (!ib.second)
				CharCodes_.erase(itCheck);
		}
	}

	if (!CharCodes_.empty())
		Push(SSetCharDBIn(GetUID(), CharCodes_));

	Send(SSetCharNetSc(CharCodes_));
}
void CUser::UnsetChar(list<int32>& CharCodes_)
{
	if (CharCodes_.empty())
	{
		for (auto it = _Chars.begin(); it != _Chars.end(); )
		{
			auto itCheck = it;
			++it;

			if (*itCheck == _User.SelectedCharCode)
				continue;

			CharCodes_.emplace_back(*itCheck);
			_Chars.erase(itCheck);
		}
	}
	else
	{
		for (auto it = CharCodes_.begin(); it != CharCodes_.end(); )
		{
			auto itCheck = it;
			++it;

			if (_User.SelectedCharCode == *itCheck)
				continue;

			if (_Chars.erase(*itCheck) <= 0)
				CharCodes_.erase(itCheck);
		}
	}

	if (!CharCodes_.empty())
		Push(SUnsetCharDBIn(GetUID(), CharCodes_));

	Send(SUnsetCharNetSc(CharCodes_));
}
ERet CUser::Chat(const SChatNetCs& Proto_)
{
	BroadCast(SChatNetSc(Proto_.Msg));

	return ERet::Ok;
}
ERet CUser::ChangeFSM(const SFCMTokenSetNetCs& Proto_)
{
	SendM(SFCMTokenSetNetSm(GetUID(), Proto_.Token, _LoginInfo.CountryCodeMinuteOffset.MinuteOffset.count()));

	return ERet::Ok;
}
ERet CUser::CanPushAtNight(const SFCMCanPushAtNightNetCs& Proto_)
{
	if (_User.CanPushAtNight == Proto_.CanPush)
		return ERet::SameCanNotPushAtNight;

	_User.CanPushAtNight = Proto_.CanPush;
	Push(SCanPushAtNightDBIn(GetUID(), Proto_.CanPush));
	SendM(SFCMCanPushAtNightNetSm(GetUID(), Proto_.CanPush));

	return ERet::Ok;
}
ERet CUser::ChangeLanguage(const SChangeLanguageNetCs& Proto_)
{
	if ((uint8)Proto_.Language < 0 || Proto_.Language >= ELanguage::Max)
		return ERet::InvalidLanguage;

	_User.Language = Proto_.Language;
	Push(SChangeLanguageDBIn(GetUID(), Proto_.Language));
	SendM(SChangeLanguageNetSm(GetUID(), Proto_.Language));

	return ERet::Ok;
}
ERet CUser::SelectChar(const SSelectCharNetCs& Proto_)
{
	if (Proto_.Code == _User.SelectedCharCode)
		return ERet::SameCode;

	auto it = _Chars.find(Proto_.Code);
	if (it == _Chars.end())
		return ERet::InvalidCharCode;

	auto pChar = g_MetaData->GetCharacter(Proto_.Code);
	if (pChar == nullptr)
		return ERet::InvalidCharCode;

	_User.SelectedCharCode = Proto_.Code;
	_pSelectedChar = pChar;
	Push(SSelectCharDBIn(GetUID(), _User.SelectedCharCode));

	return ERet::Ok;
}
ERet CUser::IslandStart(const SIslandStartNetCs& Proto_)
{
	if (_BattleJoining)
		return ERet::AlreadyBattleJoining;

	if (InBattle())
		return ERet::AlreadyInBattle;

	auto NewIslandPlayCount = _User.IslandPlayCount;
	auto NewIslandRefreshTime = _User.IslandRefreshTime;
	auto Now = system_clock::now();

	if (NewIslandPlayCount < g_MetaData->IslandMeta.PlayCountMax)
	{
		auto UnitDuration = minutes(g_MetaData->IslandMeta.RefreshDurationMinute);
		auto ElapsedMinutes = duration_cast<minutes>(Now - NewIslandRefreshTime);
		auto ElapsedCount = ElapsedMinutes / UnitDuration;
		NewIslandPlayCount += ElapsedCount;

		if (NewIslandPlayCount > g_MetaData->IslandMeta.PlayCountMax)
			NewIslandPlayCount = g_MetaData->IslandMeta.PlayCountMax;

		if (NewIslandPlayCount >= g_MetaData->IslandMeta.PlayCountMax)
			NewIslandRefreshTime = Now;
		else
			NewIslandRefreshTime += (UnitDuration * ElapsedCount);
	}
	else if (NewIslandPlayCount >= g_MetaData->IslandMeta.PlayCountMax)
	{
		NewIslandRefreshTime = Now;
	}

	TQuests Quests;
	TDoneQuestDBs DoneQuestDBs;
	TDoneQuests DoneQuests;

	TResource GoldCost = 0;
	if (NewIslandPlayCount < 1)
	{
		auto CostType = EResource::Gold;
		if (!HaveCost(CostType, g_MetaData->IslandMeta.ChargeCostGold))
			return ERet::NotEnoughMoney;

		SubResourceCore(CostType, g_MetaData->IslandMeta.ChargeCostGold);
		GoldCost = g_MetaData->IslandMeta.ChargeCostGold;
		NewIslandPlayCount = g_MetaData->IslandMeta.PlayCountMax;
		NewIslandRefreshTime = Now;
	}

	--NewIslandPlayCount;
	_User.IslandPlayCount = NewIslandPlayCount;
	_User.IslandRefreshTime = NewIslandRefreshTime;
	_User.IslandStarted = true;

	QuestDone(Quests, DoneQuestDBs, DoneQuests);
	Push(SIslandStartDBIn(GetUID(), _User.Resources, _User.IslandPlayCount, _User.IslandRefreshTime, std::move(DoneQuestDBs)));
	Send(SIslandStartNetSc(GoldCost, _User.IslandPlayCount, _User.IslandRefreshTime, std::move(DoneQuests)));

	return ERet::Ok;
}
ERet CUser::IslandEnd(const SIslandEndNetCs& Proto_)
{
	if (_BattleJoining)
		return ERet::AlreadyBattleJoining;

	if (InBattle())
		return ERet::AlreadyInBattle;

	if (!_User.IslandStarted)
		return ERet::InvalidProtocol;

	auto IslandPoint = Proto_.PassedIslandCount * g_MetaData->IslandMeta.ScoreFactorIsland + Proto_.Gold * g_MetaData->IslandMeta.ScoreFactorGold;

	int32 CharCode = GetSelectedCharCode();

	if (IsValidRankingInfo() &&
		g_RankingInfo.UserPointMin.UserPointMinIsland < IslandPoint &&
		g_NetRankingKey)
		g_NetRanking->Send(g_NetRankingKey.PeerNum, (int32)EProtoRankingNetSr::UpdateIsland,
			SRankingUser(
				GetUID(),
				GetNick(),
				CharCode,
				GetCountryCode(),
				IslandPoint));

	if (IslandPoint > _User.IslandPointBest)
		_User.IslandPointBest = IslandPoint;

	if (Proto_.PassedIslandCount > _User.IslandPassedCountBest)
		_User.IslandPassedCountBest = Proto_.PassedIslandCount;

	TResources Added{};
	::AddResource(Added, EResource::Gold, Proto_.GoldAdded);
	::AddResource(Added, EResource::Dia, Proto_.DiaAdded);
	AddResourcesCore(Added);
	_User.IslandStarted = false;

	TQuests Quests;
	TDoneQuestDBs DoneQuestDBs;
	TDoneQuests DoneQuests;

	Quests.emplace(EQuestType::PlayIsland, 1);

	if (Proto_.PassedIslandCount > 0)
		Quests.emplace(EQuestType::IslandCount, Proto_.PassedIslandCount);

	if (Proto_.Gold > 0)
		Quests.emplace(EQuestType::IslandGoldGet, Proto_.Gold);

	if (IslandPoint > 0)
		Quests.emplace(EQuestType::IslandScoreGet, IslandPoint);

	switch (_pSelectedChar->Grade)
	{
	case EGrade::Normal:
		Quests.emplace(EQuestType::PlayNormal, 1);
		break;

	case EGrade::Rare:
		Quests.emplace(EQuestType::PlayRare, 1);
		break;

	case EGrade::Epic:
		Quests.emplace(EQuestType::PlayEpic, 1);
		break;
	}

	QuestDone(Quests, DoneQuestDBs, DoneQuests);
	Push(SIslandEndDBIn(GetUID(), _User.Resources, _User.IslandPointBest, _User.IslandPassedCountBest, std::move(DoneQuestDBs)));
	Send(SIslandEndNetSc(std::move(DoneQuests)));

	return ERet::Ok;
}

ERet CUser::BattleTouch(const SBattleTouchNetCs& Proto_)
{
	if (!InBattle())
		return ERet::Ok; // 시간차로 게임 종료후 프로토콜 날릴 수도 있으므로 에러 통보하지 않음.

	return _pBattlePlayer->Touch(Proto_);
}
ERet CUser::BattlePush(const SBattlePushNetCs& Proto_)
{
	if (!InBattle())
		return ERet::Ok; // 시간차로 게임 종료후 프로토콜 날릴 수도 있으므로 에러 통보하지 않음.

	return _pBattlePlayer->Push(Proto_);
}

void CUser::BattleBegin(CBattlePlayer* pBattlePlayer_)
{
	_BattleJoining = false;
	_pBattlePlayer = pBattlePlayer_;
}
void CUser::BattleEnd(void)
{
	_pBattlePlayer = nullptr;
}
ERet CUser::MultiBattleJoin(void)
{
	if (_BattleJoining)
		return ERet::AlreadyBattleJoining;

	if (InBattle())
		return ERet::AlreadyInBattle;

	_BattleJoining = true;
	Send(SMultiBattleJoinNetSc());

	return ERet::Ok;
}
ERet CUser::MultiBattleOut(void)
{
	if (!_BattleJoining)
		return ERet::NotBattleJoining;

	if (InBattle())
		return ERet::AlreadyInBattle;

	_BattleJoining = false;

	Send(SMultiBattleOutNetSc());

	return ERet::Ok;
}
SBattleEndInfo CUser::MultiBattleEnd(const vector<SBattleEndPlayer>& BattleEndPlayers_, const TQuests& DoneQuests_, TDoneQuestDBs& DoneQuestDBs_)
{
	TDoneQuests DoneQeusts;
	QuestDone(DoneQuests_, DoneQuestDBs_, DoneQeusts);

	auto& BattleEndPlayer = BattleEndPlayers_[_pBattlePlayer->PlayerIndex];

	if (BattleEndPlayer.AddedPoint > 0)
	{
		if (_User.Point + BattleEndPlayer.AddedPoint > _User.Point)
			_User.Point += BattleEndPlayer.AddedPoint;
		else
			_User.Point = MaxValue<int32>();
	}
	else if (BattleEndPlayer.AddedPoint < 0)
	{
		if (_User.Point + BattleEndPlayer.AddedPoint > 0)
			_User.Point += BattleEndPlayer.AddedPoint;
		else
			_User.Point = 0;
	}

	if (_User.Point > _User.PointBest)
		_User.PointBest = _User.Point;

	if (BattleEndPlayer.BattlePoint > _User.BattlePointBest)
		_User.BattlePointBest = BattleEndPlayer.BattlePoint;

	AddResourceCore(EResource::Gold, BattleEndPlayer.AddedGold);
	BattleEnd();

	Send(SMultiBattleEndNetSc(BattleEndPlayers_, DoneQeusts));

	return SBattleEndInfo(
		GetUID(), _User.Resources, _User.Point, _User.PointBest,
		_User.WinCountSolo, _User.LoseCountSolo, _User.WinCountSurvival, _User.LoseCountSurvival, _User.WinCountMulti, _User.LoseCountMulti,
		_User.BattlePointBest, _User.KillTotal, _User.ChainKillTotal, _User.BlowBalloonTotal);
}
ERet CUser::MultiBattleIcon(const SMultiBattleIconNetCs& Proto_)
{
	if (InBattle())
	{
		auto* pMultiBattlePlayer = dynamic_cast<CMultiBattlePlayer*>(_pBattlePlayer);
		if (pMultiBattlePlayer == nullptr)
			return ERet::InvalidProtocol;

		pMultiBattlePlayer->Icon(Proto_);
	}

	return ERet::Ok; // 시간차로 게임 종료후 프로토콜 날릴 수도 있으므로 에러 통보하지 않음.
}
ERet CUser::ArrowDodgeBattleJoin(void)
{
	if (_BattleJoining)
		return ERet::AlreadyBattleJoining;

	if (InBattle())
		return ERet::AlreadyInBattle;

	auto NewSinglePlayCount = _User.SinglePlayCount;
	auto NewSingleRefreshTime = _User.SingleRefreshTime;
	auto Now = system_clock::now();

	if (NewSinglePlayCount < g_MetaData->ArrowDodgeMeta.PlayCountMax)
	{
		auto UnitDuration = minutes(g_MetaData->ArrowDodgeMeta.RefreshDurationMinute);
		auto ElapsedMinutes = duration_cast<minutes>(Now - NewSingleRefreshTime);
		auto ElapsedCount = ElapsedMinutes / UnitDuration;
		NewSinglePlayCount += ElapsedCount;

		if (NewSinglePlayCount > g_MetaData->ArrowDodgeMeta.PlayCountMax)
			NewSinglePlayCount = g_MetaData->ArrowDodgeMeta.PlayCountMax;

		if (NewSinglePlayCount >= g_MetaData->ArrowDodgeMeta.PlayCountMax)
			NewSingleRefreshTime = Now;
		else
			NewSingleRefreshTime += (UnitDuration * ElapsedCount);
	}
	else if (NewSinglePlayCount >= g_MetaData->ArrowDodgeMeta.PlayCountMax)
	{
		NewSingleRefreshTime = Now;
	}

	TQuests Quests;
	TDoneQuestDBs DoneQuestDBs;
	TDoneQuests DoneQuests;

	TResource GoldCost = 0;
	if (NewSinglePlayCount < 1)
	{
		auto CostType = EResource::Gold;
		if (!HaveCost(CostType, g_MetaData->ArrowDodgeMeta.ChargeCostGold))
			return ERet::NotEnoughMoney;

		SubResourceCore(CostType, g_MetaData->ArrowDodgeMeta.ChargeCostGold);
		GoldCost = g_MetaData->ArrowDodgeMeta.ChargeCostGold;
		NewSinglePlayCount = g_MetaData->ArrowDodgeMeta.PlayCountMax;
		NewSingleRefreshTime = Now;
	}

	--NewSinglePlayCount;
	_User.SinglePlayCount = NewSinglePlayCount;
	_User.SingleRefreshTime = NewSingleRefreshTime;

	QuestDone(Quests, DoneQuestDBs, DoneQuests);
	Push(SArrowDodgeBattleStartDBIn(GetUID(), _User.Resources, _User.SinglePlayCount, _User.SingleRefreshTime, std::move(DoneQuestDBs)));
	Send(SArrowDodgeBattleJoinNetSc(GoldCost, _User.SinglePlayCount, _User.SingleRefreshTime, std::move(DoneQuests)));

	auto itBattle = g_Battles.emplace(nullptr);
	itBattle->reset(new CArrowDodgeBattle(this, itBattle));

	return ERet::Ok;
}
ERet CUser::ArrowDodgeBattleEnd(const SArrowDodgeBattleEndNetCs& Proto_)
{
	// 시간차로 이미 끝나있을 수 있으므로
	if (!InBattle())
		return ERet::Ok;

	auto* pArrowDodgeBattlePlayer = dynamic_cast<CArrowDodgeBattlePlayer*>(_pBattlePlayer);
	if (pArrowDodgeBattlePlayer == nullptr)
		return ERet::InvalidProtocol;

	g_Battles.erase(_pBattlePlayer->itBattle);

	return ERet::Ok;
}
void CUser::ArrowDodgeBattleEnd(int64 Tick_, const SArrowDodgeBattleInfo& BattleInfo_, const TQuests& DoneQuests_)
{
	int32 CharCode = GetSelectedCharCode();

	if (IsValidRankingInfo() &&
		g_RankingInfo.UserPointMin.UserPointMinSingle < BattleInfo_.Point &&
		g_NetRankingKey)
		g_NetRanking->Send(g_NetRankingKey.PeerNum, (int32)EProtoRankingNetSr::UpdateSingle,
			SRankingUser(
				GetUID(),
				GetNick(),
				CharCode,
				GetCountryCode(),
				BattleInfo_.Point));

	if (BattleInfo_.Point > _User.SinglePointBest)
		_User.SinglePointBest = BattleInfo_.Point;

	if (BattleInfo_.Tick > _User.SingleBestTick)
		_User.SingleBestTick = BattleInfo_.Tick;

	TResources Added{};
	::AddResource(Added, EResource::Gold, BattleInfo_.Gold);
	AddResourcesCore(Added);

	TDoneQuestDBs DoneQuestDBs;
	TDoneQuests DoneQuestNets;

	QuestDone(DoneQuests_, DoneQuestDBs, DoneQuestNets);
	BattleEnd();

	Push(SArrowDodgeBattleEndDBIn(GetUID(), _User.Resources, _User.SinglePointBest, _User.SingleBestTick, std::move(DoneQuestDBs)));
	Send(SArrowDodgeBattleEndNetSc(Tick_, _User.Resources, std::move(DoneQuestNets)));
}
ERet CUser::Gacha(const SGachaNetCs& Proto_)
{
	auto Gacha = g_MetaData->GetGacha(Proto_.GachaIndex);
	if (Gacha == nullptr)
		return ERet::InvalidProtocol;

	//if (Gacha->DoesAllHave(_Chars))
	//	return ERet::NoMoreNewCharacter;

	switch (Proto_.GachaIndex)
	{
	case 0:
		QuestDone(EQuestType::GachaRuby, 1);
		break;
	}

	return Gacha->Get(this, _Chars);
}
ERet CUser::GachaX10(const SGachaX10NetCs& Proto_)
{
	auto Gacha = g_MetaData->GetGacha(Proto_.GachaIndex);
	if (Gacha == nullptr)
		return ERet::InvalidProtocol;

	//if (Gacha->DoesAllHave(_Chars))
	//	return ERet::NoMoreNewCharacter;

	switch (Proto_.GachaIndex)
	{
	case 0:
		QuestDone(EQuestType::GachaRuby, 10);
		break;
	}

	return Gacha->GetX10(this, _Chars);
}
void CUser::GachaSucceeded(const TResources& Cost_, int32 GachaIndex_, int32 CharCode_)
{
	SubResourcesCore(Cost_);
	_Chars.emplace(CharCode_);
	Push(SGachaDBIn(GetUID(), _User.Resources, list<int32>{CharCode_}));
	Send(SGachaNetSc(Cost_, GachaIndex_, CharCode_));
}
void CUser::GachaX10Succeeded(const TResources& Cost_, int32 GachaIndex_, list<int32> CharCodeList_, const TResources& Refund_)
{
	SubResourcesCore(Cost_);
	AddResourcesCore(Refund_);
	list<int32> NewCharCodeList;
	for (auto i : CharCodeList_)
	{
		if (_Chars.find(i) == _Chars.end())
		{
			NewCharCodeList.emplace_back(i);
			_Chars.emplace(i);
		}
	}
	Push(SGachaDBIn(GetUID(), _User.Resources, NewCharCodeList));
	Send(SGachaX10NetSc(Cost_, GachaIndex_, CharCodeList_, Refund_));
}
void CUser::GachaFailed(const TResources& Cost_, int32 GachaIndex_, int32 CharCode_, const TResources& Refund_)
{
	SubResourcesCore(Cost_);
	AddResourcesCore(Refund_);
	Push(SGachaDBIn(GetUID(), _User.Resources, list<int32>()));
	Send(SGachaFailedNetSc(SGachaNetSc(Cost_, GachaIndex_, CharCode_), Refund_));
}
void CUser::_RewardCore(const SReward& Reward_, int32 Multiple_, list<int32>& CharsAdded_)
{
	AddResourcesCore(Reward_.Resources * Multiple_);

	for (auto& i : Reward_.Chars)
	{
		if (_Chars.find(i->Code) != _Chars.end())
			AddResourceCore(EResource::CP, i->CPRefund);
		else
		{
			_Chars.emplace(i->Code);
			CharsAdded_.emplace_back(i->Code);
		}
	}
}
SRewardDB CUser::RewardCore(const SReward& Reward_, int32 Multiple_)
{
	list<int32> CharsAdded;

	_RewardCore(Reward_, Multiple_, CharsAdded);

	return SRewardDB(GetUID(), _User.Resources, std::move(CharsAdded));
}
SRewardDB CUser::RewardsCore(const list<const SReward*>& Rewards_, int32 Multiple_)
{
	list<int32> CharsAdded;

	for (auto& i : Rewards_)
		_RewardCore(*i, Multiple_, CharsAdded);

	return SRewardDB(GetUID(), _User.Resources, std::move(CharsAdded));
}
ERet CUser::RankReward(const SRankRewardNetCs& Proto_)
{
	auto pRankReward = g_MetaData->GetRankReward(_User.PointBest, _User.LastGotRewardRankIndex + 1);
	if (pRankReward == nullptr)
		return ERet::InvalidProtocol;

	++_User.LastGotRewardRankIndex;
	Push(SRankRewardDBIn(RewardCore(*pRankReward, 1), _User.LastGotRewardRankIndex));

	return ERet::Ok;
}
ERet CUser::QuestReward(const SQuestRewardNetCs& Proto_)
{
	auto Reward = _Quest.Reward(Proto_.SlotIndex);

	if (!Reward)
		return ERet::InvalidProtocol;

	//	count	time	상태
	//	달성	미만	달성, 보상대기
	//	달성	이상	달성, 보상대기
	//	미달	미만	쿨타임
	//	미달	이상	미달성

	auto Now = system_clock::now();
	if (_User.QuestDailyCompleteCount < g_MetaData->QuestDailyComplete.RequirmentCount && Now >= _User.QuestDailyCompleteRefreshTime) // 미달성이고, 쿨타임이 아니면
	{
		if (Now >= (_User.QuestDailyCompleteRefreshTime + g_MetaData->QuestDailyComplete.RefreshDuration)) // 다음 주기에 도래했으면
		{
			auto ElapsedDurationCount = (Now - _User.QuestDailyCompleteRefreshTime) / g_MetaData->QuestDailyComplete.RefreshDuration;
			_User.QuestDailyCompleteRefreshTime += (g_MetaData->QuestDailyComplete.RefreshDuration * ElapsedDurationCount);
			_User.QuestDailyCompleteCount = 0;
		}

		if (_User.QuestDailyCompleteCount < g_MetaData->QuestDailyComplete.RequirmentCount)
			++_User.QuestDailyCompleteCount;
	}

	Push(SQuestRewardDBIn(RewardCore(*Reward->second, 1), Proto_.SlotIndex, Reward->first, _User.QuestDailyCompleteCount, _User.QuestDailyCompleteRefreshTime));
	Send(SQuestRewardNetSc(Proto_.SlotIndex, Reward->first, _User.QuestDailyCompleteCount, _User.QuestDailyCompleteRefreshTime));

	return ERet::Ok;
}
optional<CQuest::TDone> CUser::_QuestDone(EQuestType QuestType_, int32 Count_)
{
	auto itQuest = _Quest.Get(QuestType_);
	if (itQuest == _Quest.End())
		return {};

	return _Quest.Done(itQuest, Count_);
}
void CUser::QuestDone(const TQuests& DoneQuests_, TDoneQuestDBs& DoneQuestDBs_, TDoneQuests& DoneQuestNets_)
{
	for (auto& i : DoneQuests_)
	{
		auto Done = _QuestDone(i.first, i.second);
		if (!Done)
			continue;

		DoneQuestDBs_.emplace_back(SUIDQuestSlotIndexCount(
			DoneQuestNets_.emplace_back(SQuestSlotIndexCount(Done->first, Done->second)),
			GetUID()));
	}
}
void CUser::QuestDone(CQuest::TQuestsIt itQuest_, int32 Count_)
{
	auto Done = _Quest.Done(itQuest_, Count_);
	if (!Done)
		return;

	Push(SQuestDoneDBIn(GetUID(), Done->first, Done->second));
	Send(SQuestDoneNetSc(Done->first, Done->second));
}
void CUser::QuestDone(TQuestSlotIndex SlotIndex_, int32 Count_)
{
	auto itQuest = _Quest.Get(SlotIndex_);
	if (itQuest == _Quest.End())
		return;

	QuestDone(itQuest, Count_);
}
void CUser::QuestDone(EQuestType QuestType_, int32 Count_)
{
	auto itQuest = _Quest.Get(QuestType_);
	if (itQuest == _Quest.End())
		return;

	QuestDone(itQuest, Count_);
}
ERet CUser::QuestNext(const SQuestNextNetCs& Proto_)
{
	auto Next = _Quest.Next(Proto_);
	if (!Next)
		return ERet::InvalidProtocol;

	int32 NewQuestCode = 0;

	if (*Next)
		NewQuestCode = (*Next)->Code;

	Push(SQuestNextDBIn(GetUID(), Proto_.SlotIndex, NewQuestCode));
	Send(SQuestNextNetSc(Proto_.SlotIndex, NewQuestCode));

	return ERet::Ok;
}
void CUser::QuestSet(TQuestSlotIndex SlotIndex_, int32 Code_)
{
	if (!_Quest.Set(SlotIndex_, Code_))
		return;

	Push(SQuestNextDBIn(GetUID(), SlotIndex_, Code_));
	Send(SQuestNextNetSc(SlotIndex_, Code_));
}
ERet CUser::QuestDailyCompleteReward(const SQuestDailyCompleteRewardNetCs& Proto_)
{
	if (_User.QuestDailyCompleteCount < g_MetaData->QuestDailyComplete.RequirmentCount)
		return ERet::InvalidProtocol;

	auto Now = system_clock::now();
	if (Now < _User.QuestDailyCompleteRefreshTime) // 이미 쿨타임일지라도, 완료되었다면 시간이 어떠한 사유로 바뀌었으나, 시간 변동으로인해 보상을 더 받게되는 일이 없도록 주기를 정상 1회 증가
	{
		_User.QuestDailyCompleteRefreshTime += g_MetaData->QuestDailyComplete.RefreshDuration;
	}
	else // _User.QuestDailyCompleteRefreshTime 이 과거라면, 가장 가까운 미래의 주기에 해당하는 시각으로 변경
	{
		auto ElapsedDurationCount = (Now - _User.QuestDailyCompleteRefreshTime) / g_MetaData->QuestDailyComplete.RefreshDuration;
		_User.QuestDailyCompleteRefreshTime += (g_MetaData->QuestDailyComplete.RefreshDuration * (ElapsedDurationCount + 1));
	}

	_User.QuestDailyCompleteCount = 0;
	Push(SQuestDailyCompleteRewardDBIn(RewardCore(*g_MetaData->QuestDailyComplete.pReward, Proto_.WatchAd ? 2 : 1), _User.QuestDailyCompleteRefreshTime));
	Send(SQuestDailyCompleteRewardNetSc(Proto_.WatchAd, _User.QuestDailyCompleteRefreshTime));

	return ERet::Ok;
}
ERet CUser::ChangeNickRequest(const SChangeNickNetCs& Proto_)
{
	if (Proto_.Nick.size() < c_NickLengthMin)
		return ERet::NickLengthUnderMin;

	if (Proto_.Nick.size() > c_NickLengthMax)
		return ERet::NickLengthOverMax;

	if (Proto_.Nick == GetNick())
		return ERet::InvalidProtocol;

	auto Nick = u16string_to_wstring(Proto_.Nick);
	wcslwr((wchar_t*)Nick.c_str());

	for (auto& i : g_MetaData->ForbiddenWords)
	{
		if (Nick.find(i) != string::npos)
		{
			Send(SChangeNickFailNetSc(EGameRet::Ok, i));
			return ERet::Ok;
		}
	}

	if (_User.ChangeNickFreeCount <= 0 &&
		!HaveCost(EResource::Dia, g_MetaData->ConfigMeta.ChangeNickCostDia))
		return ERet::NotEnoughMoney;

	_User.NewNick = Proto_.Nick;
	Push(SChangeNickBeginDBIn(GetUID(), Proto_.Nick));

	return ERet::Ok;
}
void CUser::ChangeNickResult(EGameRet GameRet_)
{
	if (GameRet_ == EGameRet::Ok)
	{
		if (_User.ChangeNickFreeCount <= 0)
		{
			SubResourceCore(EResource::Dia, g_MetaData->ConfigMeta.ChangeNickCostDia);
		}
		else
		{
			--_User.ChangeNickFreeCount;
		}

		Push(SChangeNickEndDBIn(GetUID(), _User.Resources, _User.ChangeNickFreeCount));
	}
	else
	{
		Push(SChangeNickEndFailDBIn(GetUID()), GameRet_);
	}
}
ERet CUser::CouponUse(const SCouponUseNetCs& Proto_)
{
	auto itCoupon = _Coupons.find(Proto_.Key);
	if (itCoupon != _Coupons.end())
	{
		Send(SCouponUseFailNetSc(ERet::CouponAlreadyUsed)); // 계속 쌓이게 되는 데이터이므로 유저는 유저에게 통보하지 않으므로 클라는 자신이 사용했는지 알 수 없으므로 서버에서 접속 끊지 않도록
		return ERet::Ok;
	}

	auto pCoupon = g_MetaData->GetCoupon(Proto_.Key);
	if (!pCoupon)
	{
		Send(SCouponUseFailNetSc(ERet::CouponInvalid)); // 유저가 잘못 입력할 확률이 있으니 접속 끊지 않도록
		return ERet::Ok;
	}

	g_pCouponDB->Push(0, _LoginInfo.Key, SCouponUseCouponDBIn(Proto_.Key, GetUID()), pCoupon->Code);

	return ERet::Ok;
}
void CUser::CouponUseOut(const SCouponUseCouponDBIn& In_, int32 Code_)
{
	auto pCoupon = g_MetaData->GetCoupon(Code_);
	if (!pCoupon)
		return; // 서버 기동시 체크했으므로 이론상 올 수 없음

	auto ib = _Coupons.emplace(In_.Key);
	if (!ib.second)
		THROWEX(); // 유저가 연달아 날린경우 (접종)

	auto Reward = RewardCore(*pCoupon->pReward, 1);
	Push(SCouponUseDBIn(Reward, In_.Key));
	Send(SCouponUseNetSc(Reward));
}
ERet CUser::TutorialReward(const STutorialRewardNetCs& Proto_)
{
	if (_User.TutorialReward)
		return ERet::InvalidProtocol;

	_User.TutorialReward = true;
	AddResourceCore(EResource::Dia, g_MetaData->ConfigMeta.TutorialRewardDia);
	Push(STutorialRewardDBIn(GetUID(), _User.Resources));

	return ERet::Ok;
}
ERet CUser::RankingRewardInfo(const SRankingRewardInfoNetCs& Proto_)
{
	int32 Ranking = -1;
	int32 RankingSingle = -1;
	int32 RankingIsland = -1;

	{
		auto it = g_RankingInfo.Rewards.find(GetUID());
		if (it != g_RankingInfo.Rewards.end())
			Ranking = it->second;
	}

	{
		auto it = g_RankingInfo.RewardsSingle.find(GetUID());
		if (it != g_RankingInfo.RewardsSingle.end())
			RankingSingle = it->second;
	}

	{
		auto it = g_RankingInfo.RewardsIsland.find(GetUID());
		if (it != g_RankingInfo.RewardsIsland.end())
			RankingIsland = it->second;
	}

	Send(SRankingRewardInfoNetSc(g_RankingInfo.Counter, Ranking, RankingSingle, RankingIsland));

	return ERet::Ok;
}
ERet CUser::RankingReward(const SRankingRewardNetCs& Proto_)
{
	try
	{
		if (!IsValidRankingInfo())
			throw ERet::RankingServerOffLine;

		if (_User.RankingRewardedCounter >= g_RankingInfo.Counter)
			throw ERet::RankingRewarded;

		if (g_RankingInfo.Rewards.find(GetUID()) == g_RankingInfo.Rewards.end() &&
			g_RankingInfo.RewardsSingle.find(GetUID()) == g_RankingInfo.RewardsSingle.end() &&
			g_RankingInfo.RewardsIsland.find(GetUID()) == g_RankingInfo.RewardsIsland.end())
			throw ERet::RankingNoReward;

		// IsValidRankingInfo == true 이면 g_NetRanking 도 유효

		list<const SReward*> Rewards;
		int32 RewardCode = 0;
		int32 RewardCodeSingle = 0;
		int32 RewardCodeIsland = 0;

		auto itReward = g_RankingInfo.Rewards.find(GetUID());
		if (itReward != g_RankingInfo.Rewards.end())
		{
			auto itRankingReward = g_MetaData->RankingReward[(size_t)ERankingType::Multi].lower_bound(itReward->second);
			if (itRankingReward != g_MetaData->RankingReward[(size_t)ERankingType::Multi].end())
			{
				RewardCode = itRankingReward->second->first;
				Rewards.emplace_back(&itRankingReward->second->second);
			}
		}

		auto itRewardSingle = g_RankingInfo.RewardsSingle.find(GetUID());
		if (itRewardSingle != g_RankingInfo.RewardsSingle.end())
		{
			auto itRankingReward = g_MetaData->RankingReward[(size_t)ERankingType::Single].lower_bound(itRewardSingle->second);
			if (itRankingReward != g_MetaData->RankingReward[(size_t)ERankingType::Single].end())
			{
				RewardCodeSingle = itRankingReward->second->first;
				Rewards.emplace_back(&itRankingReward->second->second);
			}
		}

		auto itRewardIsland = g_RankingInfo.RewardsIsland.find(GetUID());
		if (itRewardIsland != g_RankingInfo.RewardsIsland.end())
		{
			auto itRankingReward = g_MetaData->RankingReward[(size_t)ERankingType::Island].lower_bound(itRewardIsland->second);
			if (itRankingReward != g_MetaData->RankingReward[(size_t)ERankingType::Island].end())
			{
				RewardCodeIsland = itRankingReward->second->first;
				Rewards.emplace_back(&itRankingReward->second->second);
			}
		}

		_User.RankingRewardedCounter = g_RankingInfo.Counter;
		Push(SRankingRewardDBIn(RewardsCore(Rewards, 1), _User.RankingRewardedCounter));
		Send(SRankingRewardNetSc(_User.RankingRewardedCounter, RewardCode, RewardCodeSingle, RewardCodeIsland));
	}
	catch (const ERet Ret_)
	{
		Send(SRankingRewardFailNetSc(Ret_));
	}
	catch (...)
	{
		Send(SRankingRewardFailNetSc(ERet::RankingRewardFail));
	}

	return ERet::Ok;
}
