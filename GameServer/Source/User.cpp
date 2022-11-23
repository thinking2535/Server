#include "stdafx.h"
#include <GameServer/Common/Base.h>

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
void CUser::Certify(void)
{
	g_Net->Certify(Key());
	_SendLogin();

	auto NewQuests = _Quest.FillEmptySlotAndGetNewQuests();
	if (!NewQuests.empty())
	{
		Push(SQuestNewDBIn(GetUID(), NewQuests));
		Send(SQuestGotNetSc(std::move(NewQuests)));
	}
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
		_pBattlePlayer->Link();
	else
		Send(SLobbyNetSc());
}
void CUser::Logout(void)
{
	if (InBattle())
		_pBattlePlayer->UnLink();

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
	_pFatigueUpdater = make_unique<FatigueUpdater>(g_MetaData->ConfigMeta.fatigueHoursPeriod, _User.fatigueLastUpdateTime);

	for (auto& i : Out_.characterDBs)
		_characterInfos.emplace(i.first, CharacterInfo(i.second, TokenIDs()));

	for (auto& i : Out_.characterCodeTokenIDs)
	{
		auto itCharacterInfo = _characterInfos.find(i.code);
		if (itCharacterInfo == _characterInfos.end())
			continue;

		itCharacterInfo->second.tokenIDs.emplace(i.tokenID);
	}

	_pSelectedChar = g_MetaData->GetCharacter(_User.SelectedCharCode);
	_itSelectedCharInfo = _characterInfos.find(_User.SelectedCharCode);

	if (_pSelectedChar == nullptr ||
		_itSelectedCharInfo == _characterInfos.end())
	{
		_itSelectedCharInfo = _characterInfos.begin();
		if (_itSelectedCharInfo == _characterInfos.end())
			throw ERet::InvalidCharCode;

		_pSelectedChar = g_MetaData->GetCharacter(_itSelectedCharInfo->first);
		if (_pSelectedChar == nullptr)
			throw ERet::InvalidCharCode;

		_User.SelectedCharCode = _itSelectedCharInfo->first;
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

		auto defaultCharacters = g_MetaData->getDefaultCharacters();
		auto defaultCharacterCode = defaultCharacters[rand() % defaultCharacters.size()].code;

		TResources resources{};
		AddResource(resources, EResource::Ticket, g_MetaData->ConfigMeta.freeTicket);

		Push(SJoinDBIn(
			GetUID(),
			SJoinDB(
				SUserCore(
					resources,
					0,
					defaultCharacterCode,
					g_MetaData->arrowDodgeConfigMeta.PlayCountMax,
					Now,
					g_MetaData->flyAwayConfigMeta.PlayCountMax,
					Now,
					Now,
					g_MetaData->ConfigMeta.ChangeNickFreeCount)),
			Now,
			Now,
			_User.Language,
			_LoginInfo.Option.OS,
			_LoginInfo.CountryCodeMinuteOffset.CountryCode,
			defaultCharacters));
	}
	else
	{
		SetLoginDBOutCore(Out_);
	}
}

void CUser::_SendLogin(void)
{
	Send(SLoginNetSc(SUserNet(_User, GetCountryCode()), _characterInfos, system_clock::now(), _Quest.GetQuestDBs()));
}
void CUser::_addCharacter(int32 code, const TokenID& tokenID)
{
	auto ib = _characterInfos.emplace(code, CharacterInfo());
	if (!ib.first->second.tokenIDs.emplace(tokenID).second)
		THROWEXA(L"Already have character tokenID [%s]", tokenID);
}
ERet CUser::Buy(const SBuyNetCs& Proto_)
{
	auto itGoods = g_MetaData->shopItems.find(Proto_.Code);
	if (itGoods == g_MetaData->shopItems.end())
		return ERet::InvalidProtocol;

	auto ret = itGoods->second->buy(this);
	if (ret != ERet::Ok)
		return ret;

	return ERet::Ok;
}
ERet CUser::BuyChar(const SBuyCharNetCs& Proto_)
{
	auto pCharacter = g_MetaData->GetCharacter(Proto_.Code);
	if (pCharacter == nullptr)
		return ERet::InvalidProtocol;

	return buyCharacter(pCharacter);
}
ERet CUser::buyCharacter(const CCharacter* pCharacter)
{
	if (!pCharacter->canBuy())
		return ERet::InvalidProtocol;

	if (pCharacter->isNFTCharacter())
	{
		_requestNFTCharacter(pCharacter->Code);
	}
	else
	{
		auto cost = pCharacter->getCost();
		if (!doesHaveCost(cost))
			return ERet::NotEnoughMoney;

		AddResourceCore(-cost);

		auto tokenID = newGuid();
		_addCharacter(pCharacter->Code, tokenID);

		Push(SBuyCharDBIn(GetUID(), _User.Resources, pCharacter->Code, tokenID));
		Send(SBuyCharNetSc(CodeTokenID(pCharacter->Code, tokenID)));
	}

	return ERet::Ok;
}
void CUser::_requestNFTCharacter(int32 code)
{
	// todo api 호출
	_responseNFTCharacter(code, newGuid());
}
void CUser::_responseNFTCharacter(int32 code, const TokenID& tokenID)
{
	_addCharacter(code, tokenID);

	Push(SBuyNFTCharDBIn(GetUID(), code, tokenID));
	Send(SBuyNFTCharNetSc(CodeTokenID(code, tokenID)));
}
ERet CUser::BuyResource(const SBuyResourceNetCs& Proto_)
{
	auto exchangeValue = g_MetaData->getExchangeValue(Proto_.resourceTypeData.Type);
	if (!exchangeValue)
		return ERet::InvalidProtocol;

	if (Proto_.resourceTypeData.Data <= 0)
		return ERet::InvalidProtocol;

	if (Proto_.resourceTypeData.Data > getResourceFreeSpace(_User.Resources[(size_t)Proto_.resourceTypeData.Type], Proto_.resourceTypeData.Type))
		return ERet::InvalidProtocol;

	auto costValue = getCostValue(*exchangeValue, Proto_.resourceTypeData.Data);
	if (!doesHaveCost(exchangeValue->costResourceType, costValue))
		return ERet::NotEnoughMoney;

	AddResourceCore(Proto_.resourceTypeData);
	AddResourceCore(exchangeValue->costResourceType, -costValue);
	Push(SSetResourcesDBIn(GetUID(), _User.Resources));
	Send(SBuyResourceNetSc(_User.Resources));

	return ERet::Ok;
}
ERet CUser::Purchase(void)
{
	return ERet::InvalidProtocol;

	//LOG(L"Purchase Try UID[%d] ProductID[%s] Token[%s]", GetUID(), Proto_.ProductID, Proto_.PurchaseToken);

	//if (!g_ReceiptCheck->Check(_LoginInfo.Option.OS, TOrder(GetUID(), WCSToMBS(Proto_.ProductID), WCSToMBS(Proto_.PurchaseToken))))
	//{
	//	LOG(L"Purchase ReceiptCheckFail");

	//	return ERet::ReceiptCheckFail;
	//}

	return ERet::Ok;
}
ERet CUser::ReceiptCheck(const TOrder& Order_, const string& OrderID_, int64 PurchaseTime_, int32 PurchaseType_)
{
	LOG(L"Purchase ReceiptCheck Callback UID[%d] ProductID[%s] Token[%s]", GetUID(), MBSToWCS(Order_.ProductID), MBSToWCS(Order_.PurchaseToken));

	//auto it = g_MetaData->CashItems.find(MBSToWCS(Order_.ProductID));
	//if (it == g_MetaData->CashItems.end())
	//{
	//	LOG(L"Purchase InvalidShopID");

	//	return ERet::InvalidShopID;
	//}

	//Push(SPurchaseDBIn(_LoginInfo.Option.OS, OrderID_, GetUID(), _LoginInfo.CountryCodeMinuteOffset.CountryCode, PurchaseTime_, PurchaseType_, Order_.ProductID, 0));

	return ERet::Ok;
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
void CUser::SetLevel(TLevel Level_)
{
	_User.Exp = g_MetaData->LevelToExp(Level_);
	Push(SSetUserExpDBIn(GetUID(), _User.Exp));
	Send(SUserExpNetSc(_User.Exp));
}
bool CUser::doesHaveCost(EResource costType, TResource costValue)
{
	return ::doesHaveCost(_User.Resources, costType, costValue);
}
bool CUser::doesHaveCost(const SResourceTypeData& cost)
{
	return ::doesHaveCost(_User.Resources, cost);
}
bool CUser::doesHaveCost(const TResources& cost)
{
	return ::doesHaveCost(_User.Resources, cost);
}
void CUser::AddResourceCore(const SResourceTypeData& resourceTypeData)
{
	AddResourceCore(resourceTypeData.Type, resourceTypeData.Data);
}
void CUser::AddResourceCore(EResource ResourceType_, TResource Data_)
{
	_User.Resources[(size_t)ResourceType_] = ::AddResource(_User.Resources[(size_t)ResourceType_], ResourceType_, Data_);
}
void CUser::AddResourcesCore(const TResources& Resources_)
{
	::AddResources(_User.Resources, Resources_);
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
void CUser::_setPoint(int32 point)
{
	_User.Point = point;

	if (_User.Point > _User.PointBest)
		_User.PointBest = _User.Point;
}
void CUser::setPoint(int32 point)
{
	_setPoint(point);
	Push(SSetPointDBIn(GetUID(), _User.Point, _User.PointBest));
	Send(SSetPointNetSc(_User.Point));
}
void CUser::SetChar(list<int32>& CharCodes_)
{
	CodeTokenIDs addedCharacters;

	if (CharCodes_.empty())
	{
		for (auto& i : g_MetaData->GetCharacters())
		{
			auto tokenID = newGuid();
			_addCharacter(i.first, tokenID);
			addedCharacters.emplace_back(i.first, tokenID);
		}
	}
	else
	{
		for (auto& i : CharCodes_)
		{
			auto tokenID = newGuid();
			_addCharacter(i, tokenID);
			addedCharacters.emplace_back(i, tokenID);
		}
	}

	if (!addedCharacters.empty())
		Push(SSetCharDBIn(GetUID(), addedCharacters));

	Send(SSetCharNetSc(addedCharacters));
}
void CUser::UnsetChar(list<int32>& CharCodes_)
{
	if (CharCodes_.empty())
	{
		for (auto it = _characterInfos.begin(); it != _characterInfos.end(); )
		{
			auto itCheck = it;
			++it;

			if (itCheck->first == _User.SelectedCharCode)
				continue;

			CharCodes_.emplace_back(itCheck->first);
			_characterInfos.erase(itCheck);
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

			if (_characterInfos.erase(*itCheck) <= 0)
				CharCodes_.erase(itCheck);
		}
	}

	if (!CharCodes_.empty())
		Push(SUnsetCharDBIn(GetUID(), CharCodes_));

	Send(SUnsetCharNetSc(CharCodes_));
}
ERet CUser::Chat(const SChatNetCs& Proto_)
{
	// BroadCast(SChatNetSc(Proto_.Msg));

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
	if (InBattle())
		return ERet::InvalidProtocol;

	if (Proto_.Code == _User.SelectedCharCode)
		return ERet::SameCode;

	auto itChar = _characterInfos.find(Proto_.Code);
	if (itChar == _characterInfos.end())
		return ERet::InvalidCharCode;

	auto pChar = g_MetaData->GetCharacter(Proto_.Code);
	if (pChar == nullptr)
		return ERet::InvalidCharCode;

	_User.SelectedCharCode = Proto_.Code;
	_pSelectedChar = pChar;
	_itSelectedCharInfo = itChar;
	Push(SSelectCharDBIn(GetUID(), _User.SelectedCharCode));

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
void CUser::_BattleEnd(void)
{
	_pBattlePlayer = nullptr;
}
void CUser::_BattleEndAndUpdateMatchBlockEndTime(TTime Now_)
{
	_BattleEnd();
	UpdateMatchBlockEndTime(Now_);
}
ERet CUser::MultiBattleJoin(void)
{
	if (_BattleJoining)
		return ERet::AlreadyBattleJoining;

	if (InBattle())
		return ERet::AlreadyInBattle;

	if (!_updateFatigueAndHasFreeFatigue(g_MetaData->pMultiBattleConfig->addedFatigue))
		return ERet::InvalidProtocol;

	if (!_CanMatchable(system_clock::now()))
		return ERet::InvalidProtocol;

	if (!doesHaveCost(g_MetaData->ConfigMeta.BattleCostType, g_MetaData->ConfigMeta.BattleCostValue))
		return ERet::InvalidProtocol;

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
SBattleEndInfo CUser::GetSBattleEndInfo(void) const
{
	return SBattleEndInfo(
		GetUID(), _User.Resources, _User.eloPoint, _User.Point, _User.PointBest,
		_User.WinCountSolo, _User.LoseCountSolo, _User.WinCountMulti, _User.LoseCountMulti,
		_User.BattlePointBest, _User.KillTotal, _User.ChainKillTotal, _User.BlowBalloonTotal);
}
BattleEndCharacterInfo CUser::GetBattleEndCharacterInfo(void) const
{
	return BattleEndCharacterInfo(GetUID(), _itSelectedCharInfo->first, _itSelectedCharInfo->second.fatigue);
}
TDoneQuests CUser::_MultiBattleEnd(int32 BattlePoint_, const TQuests& DoneQuests_, TDoneQuestDBs& DoneQuestDBs_)
{
	TDoneQuests DoneQeusts;
	QuestDone(DoneQuests_, DoneQuestDBs_, DoneQeusts);

	if (BattlePoint_ > _User.BattlePointBest)
		_User.BattlePointBest = BattlePoint_;

	return DoneQeusts;
}
void CUser::_addEloPoint(double addedEloPoint)
{
	_User.eloPoint += addedEloPoint;

	decltype(_User.Point) newPoint = 0;

	// 변화치 만큼 정수 변수 증가
	auto intAddedEloPoint = static_cast<decltype(_User.Point)>(addedEloPoint);
	if (intAddedEloPoint > 0)
	{
		if (_User.Point + intAddedEloPoint < _User.Point)
			newPoint = MaxValue<decltype(_User.Point)>();
		else
			newPoint = _User.Point + intAddedEloPoint;
	}
	else
	{
		if (_User.Point + intAddedEloPoint < 0)
			newPoint = 0;
		else
			newPoint = _User.Point + intAddedEloPoint;
	}

	// 정수 elo 만큼 1 이동
	auto intEloPoint = static_cast<decltype(_User.Point)>(_User.eloPoint);
	if (newPoint > intEloPoint)
		--newPoint;
	else if (newPoint < intEloPoint)
		++newPoint;

	// 0보다 작지 않도록
	if (newPoint < 0)
		newPoint = 0;

	_setPoint(newPoint);
}
void CUser::MultiBattleEnd(TTime Now_, const BattleEndInfo& battleEndInfo, int32 myTeamRanking, const TQuests& DoneQuests_, TDoneQuestDBs& DoneQuestDBs_)
{
	auto DoneQeusts = _MultiBattleEnd(battleEndInfo.battlePoint, DoneQuests_, DoneQuestDBs_);

	_addEloPoint(battleEndInfo.addedEloPoint);

	AddResourceCore(g_MetaData->ConfigMeta.BattleCostType, -g_MetaData->ConfigMeta.BattleCostValue);
	AddResourcesCore(battleEndInfo.addedResources);

	_itSelectedCharInfo->second.fatigue += g_MetaData->pMultiBattleConfig->addedFatigue;

	_BattleEndAndUpdateMatchBlockEndTime(Now_);

	Send(SMultiBattleEndNetSc(SMultiBattleEndNet(_User.InvalidDisconnectInfo), myTeamRanking, _User.Resources, _User.eloPoint, _User.Point, battleEndInfo.battlePoint, DoneQeusts));
}
void CUser::MultiBattleEndDraw(TTime Now_, int32 BattlePoint_, const TQuests& DoneQuests_, TDoneQuestDBs& DoneQuestDBs_)
{
	AddResourceCore(g_MetaData->ConfigMeta.BattleCostType, -g_MetaData->ConfigMeta.BattleCostValue);
	_BattleEndAndUpdateMatchBlockEndTime(Now_);
	Send(SMultiBattleEndDrawNetSc(SMultiBattleEndNet(_User.InvalidDisconnectInfo), _User.Resources, _MultiBattleEnd(BattlePoint_, DoneQuests_, DoneQuestDBs_)));
}
void CUser::MultiBattleEndInvalid(TTime Now_)
{
	_BattleEndAndUpdateMatchBlockEndTime(Now_);
	Send(SMultiBattleEndInvalidNetSc(SMultiBattleEndNet(_User.InvalidDisconnectInfo)));
}
void CUser::MultiBattleEndInvalidPunish(void)
{
	auto Now = system_clock::now();

	if (_IsInPunished(Now))
		++_User.InvalidDisconnectInfo.Count;
	else
		_User.InvalidDisconnectInfo.Count = 1;

	_User.InvalidDisconnectInfo.EndTime = Now + g_MetaData->pMultiBattleConfig->PunishMinutesForDisconnect;
	_UpdateMatchBlockEndTime(Now);

	_BattleEnd();
	Push(SUpdateInvalidDisconnectInfoDBIn(GetUID(), _User.InvalidDisconnectInfo));
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

	if (!_updateFatigueAndHasFreeFatigue(g_MetaData->arrowDodgeConfigMeta.addedFatigue))
		return ERet::InvalidProtocol;

	auto NewPlayCount = _User.SinglePlayCount;
	auto NewRefreshTime = _User.SingleRefreshTime;
	auto Now = system_clock::now();

	if (NewPlayCount < g_MetaData->arrowDodgeConfigMeta.PlayCountMax)
	{
		auto UnitDuration = minutes(g_MetaData->arrowDodgeConfigMeta.RefreshDurationMinute);
		auto ElapsedMinutes = duration_cast<minutes>(Now - NewRefreshTime);
		auto ElapsedCount = ElapsedMinutes / UnitDuration;
		NewPlayCount += ElapsedCount;

		if (NewPlayCount > g_MetaData->arrowDodgeConfigMeta.PlayCountMax)
			NewPlayCount = g_MetaData->arrowDodgeConfigMeta.PlayCountMax;

		if (NewPlayCount >= g_MetaData->arrowDodgeConfigMeta.PlayCountMax)
			NewRefreshTime = Now;
		else
			NewRefreshTime += (UnitDuration * ElapsedCount);
	}
	else if (NewPlayCount >= g_MetaData->arrowDodgeConfigMeta.PlayCountMax)
	{
		NewRefreshTime = Now;
	}

	TQuests Quests;
	TDoneQuestDBs DoneQuestDBs;
	TDoneQuests DoneQuests;

	TResource GoldCost = 0;
	if (NewPlayCount < 1)
	{
		auto CostType = EResource::Gold;
		if (!doesHaveCost(CostType, g_MetaData->arrowDodgeConfigMeta.ChargeCostGold))
			return ERet::NotEnoughMoney;

		AddResourceCore(CostType, -g_MetaData->arrowDodgeConfigMeta.ChargeCostGold);
		GoldCost = g_MetaData->arrowDodgeConfigMeta.ChargeCostGold;
		NewPlayCount = g_MetaData->arrowDodgeConfigMeta.PlayCountMax;
		NewRefreshTime = Now;
	}

	--NewPlayCount;
	_User.SinglePlayCount = NewPlayCount;
	_User.SingleRefreshTime = NewRefreshTime;

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
void CUser::ArrowDodgeBattleEnd(int64 tick, const SArrowDodgeBattleInfo& BattleInfo_, const TQuests& DoneQuests_)
{
	int32 CharCode = GetSelectedCharCode();

	if (IsValidRankingInfo() &&
		g_RankingInfo.UserPointMinArray[(size_t)ERankingType::Single] < BattleInfo_.Point &&
		g_NetRankingKey)
		g_NetRanking->Send(g_NetRankingKey.PeerNum, (int32)EProtoRankingNetSr::UpdateSingle,
			SRankingUpdateSingleNetSr(
				SRankingUser(
					GetUID(),
					GetNick(),
					CharCode,
					GetCountryCode(),
					BattleInfo_.Point)));

	if (BattleInfo_.Point > _User.SinglePointBest)
		_User.SinglePointBest = BattleInfo_.Point;

	auto addedGold = (BattleInfo_.Gold + BattleInfo_.Point / g_MetaData->arrowDodgeConfigMeta.scorePerGold);

	TResources Added{};
	::AddResource(Added, EResource::Gold, addedGold);
	AddResourcesCore(Added);

	_itSelectedCharInfo->second.fatigue += g_MetaData->arrowDodgeConfigMeta.addedFatigue;

	TDoneQuestDBs DoneQuestDBs;
	TDoneQuests DoneQuestNets;
	QuestDone(DoneQuests_, DoneQuestDBs, DoneQuestNets);

	Push(SArrowDodgeBattleEndDBIn(GetUID(), _User.Resources, _User.SinglePointBest, std::move(DoneQuestDBs), _itSelectedCharInfo->first, _itSelectedCharInfo->second.fatigue));
	Send(SArrowDodgeBattleEndNetSc(SingleBattleEndNetSc(tick, _User.Resources, std::move(DoneQuestNets))));
	_BattleEnd();
}

ERet CUser::FlyAwayBattleJoin(void)
{
	if (_BattleJoining)
		return ERet::AlreadyBattleJoining;

	if (InBattle())
		return ERet::AlreadyInBattle;

	if (!_updateFatigueAndHasFreeFatigue(g_MetaData->flyAwayConfigMeta.addedFatigue))
		return ERet::InvalidProtocol;

	auto NewPlayCount = _User.IslandPlayCount;
	auto NewRefreshTime = _User.IslandRefreshTime;
	auto Now = system_clock::now();

	if (NewPlayCount < g_MetaData->flyAwayConfigMeta.PlayCountMax)
	{
		auto UnitDuration = minutes(g_MetaData->flyAwayConfigMeta.RefreshDurationMinute);
		auto ElapsedMinutes = duration_cast<minutes>(Now - NewRefreshTime);
		auto ElapsedCount = ElapsedMinutes / UnitDuration;
		NewPlayCount += ElapsedCount;

		if (NewPlayCount > g_MetaData->flyAwayConfigMeta.PlayCountMax)
			NewPlayCount = g_MetaData->flyAwayConfigMeta.PlayCountMax;

		if (NewPlayCount >= g_MetaData->flyAwayConfigMeta.PlayCountMax)
			NewRefreshTime = Now;
		else
			NewRefreshTime += (UnitDuration * ElapsedCount);
	}
	else if (NewPlayCount >= g_MetaData->flyAwayConfigMeta.PlayCountMax)
	{
		NewRefreshTime = Now;
	}

	TQuests Quests;
	TDoneQuestDBs DoneQuestDBs;
	TDoneQuests DoneQuests;

	TResource GoldCost = 0;
	if (NewPlayCount < 1)
	{
		auto CostType = EResource::Gold;
		if (!doesHaveCost(CostType, g_MetaData->flyAwayConfigMeta.ChargeCostGold))
			return ERet::NotEnoughMoney;

		AddResourceCore(CostType, -g_MetaData->flyAwayConfigMeta.ChargeCostGold);
		GoldCost = g_MetaData->flyAwayConfigMeta.ChargeCostGold;
		NewPlayCount = g_MetaData->flyAwayConfigMeta.PlayCountMax;
		NewRefreshTime = Now;
	}

	--NewPlayCount;
	_User.IslandPlayCount = NewPlayCount;
	_User.IslandRefreshTime = NewRefreshTime;

	QuestDone(Quests, DoneQuestDBs, DoneQuests);
	Push(SFlyAwayBattleStartDBIn(GetUID(), _User.Resources, _User.IslandPlayCount, _User.IslandRefreshTime, std::move(DoneQuestDBs)));
	Send(SFlyAwayBattleJoinNetSc(GoldCost, _User.IslandPlayCount, _User.IslandRefreshTime, std::move(DoneQuests)));

	auto itBattle = g_Battles.emplace(nullptr);
	itBattle->reset(new CFlyAwayBattle(this, itBattle));

	return ERet::Ok;
}
ERet CUser::FlyAwayBattleEnd(const SFlyAwayBattleEndNetCs& Proto_)
{
	// 시간차로 이미 끝나있을 수 있으므로
	if (!InBattle())
		return ERet::Ok;

	auto* pFlyAwayBattlePlayer = dynamic_cast<CFlyAwayBattlePlayer*>(_pBattlePlayer);
	if (pFlyAwayBattlePlayer == nullptr)
		return ERet::InvalidProtocol;

	g_Battles.erase(_pBattlePlayer->itBattle);

	return ERet::Ok;
}
void CUser::FlyAwayBattleEnd(int64 tick, const SFlyAwayBattleInfo& BattleInfo_, const TQuests& DoneQuests_)
{
	int32 CharCode = GetSelectedCharCode();

	if (IsValidRankingInfo() &&
		g_RankingInfo.UserPointMinArray[(size_t)ERankingType::Island] < BattleInfo_.Point &&
		g_NetRankingKey)
		g_NetRanking->Send(g_NetRankingKey.PeerNum, (int32)EProtoRankingNetSr::UpdateIsland,
			SRankingUpdateIslandNetSr(
				SRankingUser(
					GetUID(),
					GetNick(),
					CharCode,
					GetCountryCode(),
					BattleInfo_.Point)));

	if (BattleInfo_.Point > _User.IslandPointBest)
		_User.IslandPointBest = BattleInfo_.Point;

	auto addedGold = (BattleInfo_.Gold + BattleInfo_.Point / g_MetaData->flyAwayConfigMeta.scorePerGold);

	TResources Added{};
	::AddResource(Added, EResource::Gold, addedGold);
	AddResourcesCore(Added);

	_itSelectedCharInfo->second.fatigue += g_MetaData->flyAwayConfigMeta.addedFatigue;

	TDoneQuestDBs DoneQuestDBs;
	TDoneQuests DoneQuestNets;
	QuestDone(DoneQuests_, DoneQuestDBs, DoneQuestNets);

	Push(SFlyAwayBattleEndDBIn(GetUID(), _User.Resources, _User.IslandPointBest, _User.IslandComboBest, std::move(DoneQuestDBs), _itSelectedCharInfo->first, _itSelectedCharInfo->second.fatigue));
	Send(SFlyAwayBattleEndNetSc(SingleBattleEndNetSc(tick, _User.Resources, std::move(DoneQuestNets))));
	_BattleEnd();
}

void CUser::_RewardCore(const SReward& Reward_, CodeTokenIDs& CharsAdded_)
{
	AddResourcesCore(Reward_.Resources);

	for (auto& i : Reward_.Chars)
	{
		auto tokenID = newGuid();
		_addCharacter(i->Code, tokenID);
		CharsAdded_.emplace_back(i->Code, tokenID);
	}
}
SRewardDB CUser::RewardCore(const SReward& Reward_)
{
	CodeTokenIDs CharsAdded;

	_RewardCore(Reward_, CharsAdded);

	return SRewardDB(GetUID(), SRewardCore(_User.Resources, std::move(CharsAdded)));
}
SRewardDB CUser::RewardsCore(const list<const SReward*>& Rewards_)
{
	CodeTokenIDs CharsAdded;

	for (auto& i : Rewards_)
		_RewardCore(*i, CharsAdded);

	return SRewardDB(GetUID(), SRewardCore(_User.Resources, std::move(CharsAdded)));
}
ERet CUser::RankReward(const SRankRewardNetCs& Proto_)
{
	auto pRankReward = g_MetaData->GetRankReward(_User.PointBest, _User.NextRewardRankIndex);
	if (pRankReward == nullptr)
		return ERet::InvalidProtocol;

	++_User.NextRewardRankIndex;
	auto RewardDB = RewardCore(*pRankReward);
	Push(SRankRewardDBIn(RewardDB, _User.NextRewardRankIndex));
	Send(SRankRewardNetSc(
		RewardDB.Core,
		_User.NextRewardRankIndex));

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
ERet CUser::QuestReward(const SQuestRewardNetCs& Proto_)
{
	auto Reward = _Quest.Reward(Proto_.SlotIndex);
	if (!Reward)
		return ERet::InvalidProtocol;

	//	time	count	상태
	//	미만	.		쿨타임
	//	이상	미달	진행중
	//	이상	달성	보상대기

	auto Now = system_clock::now();
	if (_User.QuestDailyCompleteCount < g_MetaData->questConfig.dailyRequirementCount && Now >= _User.QuestDailyCompleteRefreshTime) // 미달성이고, 쿨타임이 아니면
	{
		if (Now >= (_User.QuestDailyCompleteRefreshTime + g_MetaData->questConfig.dailyRefreshMinutes)) // 다음 주기에 도래했으면
		{
			auto ElapsedDurationCount = (Now - _User.QuestDailyCompleteRefreshTime) / g_MetaData->questConfig.dailyRefreshMinutes;
			_User.QuestDailyCompleteRefreshTime += (g_MetaData->questConfig.dailyRefreshMinutes * ElapsedDurationCount);
			_User.QuestDailyCompleteCount = 0;
		}

		if (_User.QuestDailyCompleteCount < g_MetaData->questConfig.dailyRequirementCount)
			++_User.QuestDailyCompleteCount;
	}

	auto RewardDB = RewardCore(*Reward->second);

	int32 newCode = 0;
	TTime newCoolEndTime;
	if (Reward->first != nullptr)
	{
		newCode = Reward->first->Code;
		newCoolEndTime = Reward->first->CoolEndTime;
	}

	Push(SQuestRewardDBIn(RewardDB, Proto_.SlotIndex, newCode, newCoolEndTime, _User.QuestDailyCompleteCount, _User.QuestDailyCompleteRefreshTime));
	Send(SQuestRewardNetSc(
		RewardDB.Core,
		Proto_.SlotIndex,
		newCode,
		newCoolEndTime,
		_User.QuestDailyCompleteCount,
		_User.QuestDailyCompleteRefreshTime));

	return ERet::Ok;
}
void CUser::QuestSet(TQuestSlotIndex SlotIndex_, int32 Code_)
{
	if (!_Quest.Set(SlotIndex_, Code_))
		return;

	Push(SQuestSetDBIn(GetUID(), SlotIndex_, Code_));
	Send(SQuestSetNetSc(SlotIndex_, Code_));
}
ERet CUser::QuestDailyCompleteReward(const SQuestDailyCompleteRewardNetCs& Proto_)
{
	if (_User.QuestDailyCompleteCount < g_MetaData->questConfig.dailyRequirementCount)
		return ERet::InvalidProtocol;

	auto Now = system_clock::now();
	// 이미 쿨타임 일지라도, 완료되었다면 시간이 어떠한 사유로 바뀌었으나
	// 시간 변동으로 인해 보상을 더 받게되는 일이 없도록 주기를 정상 1회 증가
	if (Now < _User.QuestDailyCompleteRefreshTime)
	{
		_User.QuestDailyCompleteRefreshTime += g_MetaData->questConfig.dailyRefreshMinutes;
	}
	else // _User.QuestDailyCompleteRefreshTime 이 과거라면, 가장 가까운 미래의 주기에 해당하는 시각으로 변경
	{
		auto ElapsedDurationCount = (Now - _User.QuestDailyCompleteRefreshTime) / g_MetaData->questConfig.dailyRefreshMinutes;
		_User.QuestDailyCompleteRefreshTime += (g_MetaData->questConfig.dailyRefreshMinutes * (ElapsedDurationCount + 1));
	}

	_User.QuestDailyCompleteCount = 0;
	auto RewardDB = RewardCore(*g_MetaData->questConfig.pReward);
	Push(SQuestDailyCompleteRewardDBIn(RewardDB, _User.QuestDailyCompleteRefreshTime));
	Send(SQuestDailyCompleteRewardNetSc(
		RewardDB.Core,
		_User.QuestDailyCompleteRefreshTime));

	return ERet::Ok;
}
ERet CUser::ChangeNickRequest(const SChangeNickNetCs& Proto_)
{
	if (Proto_.Nick.size() < minNicknameLength)
		return ERet::NickLengthUnderMin;

	if (Proto_.Nick.size() > maxNicknameLength)
		return ERet::NickLengthOverMax;

	if (Proto_.Nick == GetNick())
		return ERet::InvalidProtocol;

	auto forbiddenWord = GetForbiddenWord(g_MetaData->ForbiddenWords, Proto_.Nick);
	if (!forbiddenWord.empty())
	{
		Send(SChangeNickFailNetSc(EGameRet::Ok, forbiddenWord));
		return ERet::Ok;
	}

	if (_User.ChangeNickFreeCount <= 0 &&
		!doesHaveCost(g_MetaData->ConfigMeta.ChangeNickCostType, g_MetaData->ConfigMeta.ChangeNickCostValue))
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
			AddResourceCore(g_MetaData->ConfigMeta.ChangeNickCostType, -g_MetaData->ConfigMeta.ChangeNickCostValue);
		else
			--_User.ChangeNickFreeCount;

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

	auto RewardDB = RewardCore(*pCoupon->pReward);
	Push(SCouponUseDBIn(RewardDB, In_.Key));
	Send(SCouponUseNetSc(
		RewardDB.Core,
		pCoupon->pReward->Resources));
}
ERet CUser::TutorialReward(const STutorialRewardNetCs& Proto_)
{
	if (_User.TutorialReward)
		return ERet::InvalidProtocol;

	_User.TutorialReward = true;
	AddResourceCore(g_MetaData->ConfigMeta.TutorialRewardType, g_MetaData->ConfigMeta.TutorialRewardValue);
	Push(STutorialRewardDBIn(GetUID(), _User.Resources));

	return ERet::Ok;
}
ERet CUser::RankingRewardInfo(const SRankingRewardInfoNetCs& Proto_)
{
	TRankingArray RankingArray;

	for (size_t i = 0; i < g_RankingInfo.RewardsArray.size(); ++i)
	{
		auto it = g_RankingInfo.RewardsArray[i].find(GetUID());
		if (it != g_RankingInfo.RewardsArray[i].end())
			RankingArray[i] = it->second;
		else
			RankingArray[i] = -1;
	}

	Send(SRankingRewardInfoNetSc(g_RankingInfo.Counter, std::move(RankingArray)));

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

		// IsValidRankingInfo == true 이면 g_NetRanking 도 유효

		list<const SReward*> Rewards;

		TRankingArray myRankingArray; // 등수를 전송하여 클라에서 등수로 보상 보여주도록
		myRankingArray.fill(-1);

		for (size_t i = 0; i < g_RankingInfo.RewardsArray.size(); ++i)
		{
			auto itReward = g_RankingInfo.RewardsArray[i].find(GetUID());
			if (itReward != g_RankingInfo.RewardsArray[i].end())
			{
				auto itRankingReward = g_MetaData->RankingReward[i].get(itReward->second);
				if (itRankingReward != g_MetaData->RankingReward[i].end())
				{
					myRankingArray[i] = itReward->second; // 등수
					Rewards.emplace_back(itRankingReward->second.get());
				}
			}
		}

		bool DoesHaveReward = false;
		for (auto& i : myRankingArray)
		{
			if (i != 0)
			{
				DoesHaveReward = true;
				break;
			}
		}

		if (!DoesHaveReward)
			throw ERet::RankingNoReward;


		_User.RankingRewardedCounter = g_RankingInfo.Counter;
		auto RewardDB = RewardsCore(Rewards);
		Push(SRankingRewardDBIn(RewardDB, _User.RankingRewardedCounter));
		Send(SRankingRewardNetSc(
			RewardDB.Core,
			_User.RankingRewardedCounter,
			std::move(myRankingArray)));
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
bool CUser::_IsInPunished(TTime Now_) const
{
	return _User.InvalidDisconnectInfo.EndTime > Now_;
}
bool CUser::_CanMatchable(TTime Now_) const
{
	return (_User.InvalidDisconnectInfo.MatchBlockEndTime <= Now_);
}
bool CUser::_updateFatigueAndHasFreeFatigue(int32 addedFatigue)
{
	_updateFatigue();

	auto freeFatigueCapacity = (_itSelectedCharInfo->second.tokenIDs.size() * _pSelectedChar->fatigueCapacity) - _itSelectedCharInfo->second.fatigue;
	return freeFatigueCapacity >= addedFatigue;
}
void CUser::_updateFatigue()
{
	auto now = system_clock::now();

	if (!_pFatigueUpdater->update(now))
		return;

	_User.fatigueLastUpdateTime = _pFatigueUpdater->getLastUpdatedTime();

	for (auto& i : _characterInfos)
		i.second.fatigue = 0;

	Push(UpdateFatigueDBIn(GetUID(), now));
}
void CUser::_FixMatchBLockEndTime(void)
{
	if (_User.InvalidDisconnectInfo.MatchBlockEndTime > _User.InvalidDisconnectInfo.EndTime)
		_User.InvalidDisconnectInfo.MatchBlockEndTime = _User.InvalidDisconnectInfo.EndTime;
}
void CUser::_UpdateMatchBlockEndTime(TTime Now_)
{
	auto itMatchDeniedSecond = g_MetaData->pMultiBattleConfig->MatchDeniedSecondsSelector.get(_User.InvalidDisconnectInfo.Count);

	_User.InvalidDisconnectInfo.MatchBlockEndTime = Now_ + itMatchDeniedSecond->second;
	_FixMatchBLockEndTime();
}
void CUser::UpdateMatchBlockEndTime(TTime Now_)
{
	if (!_IsInPunished(Now_))
		return;

	_UpdateMatchBlockEndTime(Now_);
	Push(SUpdateMatchBlockEndTimeDBIn(GetUID(), _User.InvalidDisconnectInfo.MatchBlockEndTime));
}
void CUser::ResetDisconnect(wstringstream& Params_)
{
	auto Now = system_clock::now();

	int32 MinuteLeftForEnd = 0;
	if (Params_ >> MinuteLeftForEnd)
		_User.InvalidDisconnectInfo.EndTime = Now + minutes(MinuteLeftForEnd);

	int32 MinuteLeftForBlockEnd = 0;
	if (Params_ >> MinuteLeftForBlockEnd)
		_User.InvalidDisconnectInfo.MatchBlockEndTime = Now + minutes(MinuteLeftForBlockEnd);

	int32 Count = 0;
	if (Params_ >> Count)
		_User.InvalidDisconnectInfo.Count = Count;

	_FixMatchBLockEndTime();
	Push(SUpdateInvalidDisconnectInfoDBIn(GetUID(), _User.InvalidDisconnectInfo));
	Send(SInvalidDisconnectInfoNetSc(_User.InvalidDisconnectInfo));
}
