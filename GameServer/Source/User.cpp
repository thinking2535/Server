#include "stdafx.h"
#include <GameServer/Common/Base.h>
#include "User.h"

CUser::CUser(TSessionsIt itSession_) :
	_itSession(itSession_),
	_RoomInfo(-1)
{
}
TLevel CUser::GetLevel(void) const
{
	return g_GameData->ExpToLevel(_User.Exp);
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
		g_Battles[_BattleInfo.BattleIndex].OnLine(_BattleInfo.BattlePlayerIndex);
	else
		Send(SLobbyNetSc());
}
tuple<int, int> CUser::Logout(void)
{
	tuple<int, int> BattleIndexForEnd = make_tuple(-1,-1);
	if (_BattleInfo.InBattle())
	{
		if (g_Battles[_BattleInfo.BattleIndex].OffLine(_BattleInfo.BattlePlayerIndex))
			get<0>(BattleIndexForEnd) = _BattleInfo.BattleIndex;
	}
	if (_SingleBattleInfo.InBattle())
	{
		if (g_SingleBattles[_SingleBattleInfo.BattleIndex].OffLine(_SingleBattleInfo.BattlePlayerIndex))
			get<1>(BattleIndexForEnd) = _SingleBattleInfo.BattleIndex;
	}
	if (_RoomInfo != -1)
	{
		if (g_Rooms.find(_RoomInfo) != g_Rooms.end())
		{
			auto& room = g_Rooms.at(_RoomInfo);
			if (room.RoomUserCount <= 1)
			{
				BroadCast(SRoomChangeNetSc(_RoomInfo, SRoomInfo(room.Mode, room.RoomIdx, room.MasterUserID, room.MasterUser, room.Password, room.RoomUserCount, room.State), true));
				g_Rooms.erase(_RoomInfo);
			}
			else
			{
				RoomOut(SRoomOutNetCs(_RoomInfo));
			}
		}
	}

	g_BulkCopyConnect->Push(SConnectDBIn(_LoginInfo.Time, system_clock::now(), GetUID(), _LoginInfo.Option.OS, _LoginInfo.CountryCodeMinuteOffset.CountryCode, _NewRegistered));
	_LoginInfo.Key = CKey(); // ���� �߿� �������� ���� ���� ��ų �� �����Ƿ� _LoginInfo = SUserLoginInfo(); �� ó���Ͽ��� ��������� �ϳ� �׳� �����ϰ� Key�� �ʱ�ȭ.
	return BattleIndexForEnd;
}
void CUser::AddExp(TExp Exp_)
{
	auto MaxExp = g_GameData->GetMaxExp();

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

	_pSelectedChar = g_GameData->GetCharacter(_User.SelectedCharCode);
	if (_pSelectedChar == nullptr ||
		_Chars.find(_User.SelectedCharCode) == _Chars.end())
	{
		auto itBeginChar = _Chars.begin();
		if (itBeginChar == _Chars.end())
			throw ERet::InvalidCharCode;

		_pSelectedChar = g_GameData->GetCharacter(*itBeginChar);
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
					g_GameData->GetDefaultChar(),
					g_GameData->SingleMeta.PlayCountMax,
					Now,
					g_GameData->IslandMeta.PlayCountMax,
					Now,
					Now,
					g_GameData->ConfigMeta.ChangeNickFreeCount,
					Now + minutes(g_GameData->ShopConfig.DailyRewardDurationMinute),
					g_GameData->ShopConfig.DailyRewardFreeCount + g_GameData->ShopConfig.DailyRewardAdCount)),
				Now,
				_User.Language,
				_LoginInfo.Option.OS,
				_LoginInfo.CountryCodeMinuteOffset.CountryCode,
				g_GameData->DefaultChars));
	}
	else
	{
		SetLoginDBOutCore(Out_);
	}
}

void CUser::_SendLogin(void)
{
	_RoomInfo = -1;
	for (auto& i : g_Rooms)
	{
		for (auto& b : i.second.Users)
		{
			if (b.first == GetUID())
			{
				_RoomInfo = i.first;
				break;
			}
		}
		if (_RoomInfo != -1) break;
	}
	Send(SLoginNetSc(SUserNet(_User, GetCountryCode()), _Chars, system_clock::now(), _Quest.GetQuestDBs(), _Packages, _RoomInfo));
}
ERet CUser::Buy(const SBuyNetCs& Proto_)
{
	auto itGoods = g_GameData->GoodsItems.find(Proto_.Code);
	if (itGoods == g_GameData->GoodsItems.end())
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

	auto pChar = g_GameData->GetCharacter(Proto_.Code);
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
	auto itPackage = g_GameData->Packages.find(Proto_.Code);
	if (itPackage == g_GameData->Packages.end())
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

	auto it = g_GameData->CashItems.find(MBSToWCS(Order_.ProductID));
	if (it == g_GameData->CashItems.end())
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
	else // �ߺ� ��û
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
		_User.DailyRewardExpiredTime += (((Now - _User.DailyRewardExpiredTime) / minutes(g_GameData->ShopConfig.DailyRewardDurationMinute)) + 1) * minutes(g_GameData->ShopConfig.DailyRewardDurationMinute);
		_User.DailyRewardCountLeft = g_GameData->ShopConfig.DailyRewardAdCount + g_GameData->ShopConfig.DailyRewardFreeCount;
	}

	if (_User.DailyRewardCountLeft <= 0 || (_User.DailyRewardCountLeft <= g_GameData->ShopConfig.DailyRewardAdCount && !Proto_.IsWatchedAd))
	{
		Send(SDailyRewardFailNetSc());
		return ERet::Ok;
	}

	--_User.DailyRewardCountLeft;
	auto& DailyRewardMeta = g_GameData->DailyReward.Get();

	AddResourceCore(DailyRewardMeta.RewardType, DailyRewardMeta.RewardValue);
	Push(SDailyRewardDBIn(GetUID(), _User.Resources, _User.DailyRewardExpiredTime, _User.DailyRewardCountLeft));
	Send(SDailyRewardNetSc(SResourceTypeData(DailyRewardMeta.RewardType, DailyRewardMeta.RewardValue), _User.DailyRewardExpiredTime, _User.DailyRewardCountLeft));

	return ERet::Ok;
}

void CUser::SetLevel(TLevel Level_)
{
	_User.Exp = g_GameData->LevelToExp(Level_);
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
		for (auto& i : g_GameData->GetCharacters())
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

	auto pChar = g_GameData->GetCharacter(Proto_.Code);
	if (pChar == nullptr)
		return ERet::InvalidCharCode;

	_User.SelectedCharCode = Proto_.Code;
	_pSelectedChar = pChar;
	Push(SSelectCharDBIn(GetUID(), _User.SelectedCharCode));

	return ERet::Ok;
}
ERet CUser::SingleStart(const SSingleStartNetCs& Proto_)
{
	if (_BattleJoining)
		return ERet::AlreadyBattleJoining;

	if (InBattle())
		return ERet::AlreadyInBattle;

	auto NewSinglePlayCount = _User.SinglePlayCount;
	auto NewSingleRefreshTime = _User.SingleRefreshTime;
	auto Now = system_clock::now();

	if (NewSinglePlayCount < g_GameData->SingleMeta.PlayCountMax)
	{
		auto UnitDuration = minutes(g_GameData->SingleMeta.RefreshDurationMinute);
		auto ElapsedMinutes = duration_cast<minutes>(Now - NewSingleRefreshTime);
		auto ElapsedCount = ElapsedMinutes / UnitDuration;
		NewSinglePlayCount += ElapsedCount;

		if (NewSinglePlayCount > g_GameData->SingleMeta.PlayCountMax)
			NewSinglePlayCount = g_GameData->SingleMeta.PlayCountMax;

		if (NewSinglePlayCount >= g_GameData->SingleMeta.PlayCountMax)
			NewSingleRefreshTime = Now;
		else
			NewSingleRefreshTime += (UnitDuration * ElapsedCount);
	}
	else if (NewSinglePlayCount >= g_GameData->SingleMeta.PlayCountMax)
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
		if (!HaveCost(CostType, g_GameData->SingleMeta.ChargeCostGold))
			return ERet::NotEnoughMoney;

		SubResourceCore(CostType, g_GameData->SingleMeta.ChargeCostGold);
		GoldCost = g_GameData->SingleMeta.ChargeCostGold;
		NewSinglePlayCount = g_GameData->SingleMeta.PlayCountMax;
		NewSingleRefreshTime = Now;
	}

	--NewSinglePlayCount;
	_User.SinglePlayCount = NewSinglePlayCount;
	_User.SingleRefreshTime = NewSingleRefreshTime;
	_User.SingleStarted = true;

	QuestDone(Quests, DoneQuestDBs, DoneQuests);
	Push(SSingleStartDBIn(GetUID(), _User.Resources, _User.SinglePlayCount, _User.SingleRefreshTime, std::move(DoneQuestDBs)));
	Send(SSingleStartNetSc(GoldCost, _User.SinglePlayCount, _User.SingleRefreshTime, std::move(DoneQuests)));

	return ERet::Ok;
}
ERet CUser::SingleEnd(const SSingleEndNetCs& Proto_)
{
	if (_BattleJoining)
		return ERet::AlreadyBattleJoining;

	if (InBattle())
		return ERet::AlreadyInBattle;

	if (!_User.SingleStarted)
		return ERet::InvalidProtocol;

	// single ccc ���� �������� üũ

	auto SinglePoint = (Proto_.Wave - 1) * g_GameData->SingleMeta.ScoreFactorWave + Proto_.Second * g_GameData->SingleMeta.ScoreFactorTime + Proto_.Gold * g_GameData->SingleMeta.ScoreFactorGold;

	int32 CharCode = GetSelectedCharCode();

	if (IsValidRankingInfo() &&
		g_RankingInfo.UserPointMin.UserPointMinSingle < SinglePoint &&
		g_NetRankingKey)
		g_NetRanking->Send(g_NetRankingKey.PeerNum, (int32)EProtoRankingNetSr::UpdateSingle,
			SRankingUserSingle(
				SRankingUserSingleCore(
					SRankingUserCore(
						GetNick(),
						CharCode,
						GetCountryCode()),
					Proto_.Wave,
					Proto_.Second,
					Proto_.Gold),
				GetUID(),
				SinglePoint));

	if (SinglePoint > _User.SinglePointBest)
		_User.SinglePointBest = SinglePoint;

	if (Proto_.Second > _User.SingleSecondBest)
		_User.SingleSecondBest = Proto_.Second;

	TResources Added{};
	::AddResource(Added, EResource::Gold, Proto_.GoldAdded);
	::AddResource(Added, EResource::Dia, Proto_.DiaAdded);
	AddResourcesCore(Added);
	_User.SingleStarted = false;

	TQuests Quests;
	TDoneQuestDBs DoneQuestDBs;
	TDoneQuests DoneQuests;

	Quests.emplace(EQuestType::PlaySingle, 1);

	if (Proto_.Second > 0)
		Quests.emplace(EQuestType::SingleTime, Proto_.Second);

	if (Proto_.Gold > 0)
		Quests.emplace(EQuestType::SinglePlayGoldGet, Proto_.Gold);

	if (SinglePoint > 0)
		Quests.emplace(EQuestType::SinglePlayScoreGet, SinglePoint);

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
	Push(SSingleEndDBIn(GetUID(), _User.Resources, _User.SinglePointBest, _User.SingleSecondBest, std::move(DoneQuestDBs)));
	Send(SSingleEndNetSc(std::move(DoneQuests)));

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

	if (NewIslandPlayCount < g_GameData->IslandMeta.PlayCountMax)
	{
		auto UnitDuration = minutes(g_GameData->IslandMeta.RefreshDurationMinute);
		auto ElapsedMinutes = duration_cast<minutes>(Now - NewIslandRefreshTime);
		auto ElapsedCount = ElapsedMinutes / UnitDuration;
		NewIslandPlayCount += ElapsedCount;

		if (NewIslandPlayCount > g_GameData->IslandMeta.PlayCountMax)
			NewIslandPlayCount = g_GameData->IslandMeta.PlayCountMax;

		if (NewIslandPlayCount >= g_GameData->IslandMeta.PlayCountMax)
			NewIslandRefreshTime = Now;
		else
			NewIslandRefreshTime += (UnitDuration * ElapsedCount);
	}
	else if (NewIslandPlayCount >= g_GameData->IslandMeta.PlayCountMax)
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
		if (!HaveCost(CostType, g_GameData->IslandMeta.ChargeCostGold))
			return ERet::NotEnoughMoney;

		SubResourceCore(CostType, g_GameData->IslandMeta.ChargeCostGold);
		GoldCost = g_GameData->IslandMeta.ChargeCostGold;
		NewIslandPlayCount = g_GameData->IslandMeta.PlayCountMax;
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

	auto IslandPoint = Proto_.PassedIslandCount * g_GameData->IslandMeta.ScoreFactorIsland + Proto_.Gold * g_GameData->IslandMeta.ScoreFactorGold;

	int32 CharCode = GetSelectedCharCode();

	if (IsValidRankingInfo() &&
		g_RankingInfo.UserPointMin.UserPointMinIsland < IslandPoint &&
		g_NetRankingKey)
		g_NetRanking->Send(g_NetRankingKey.PeerNum, (int32)EProtoRankingNetSr::UpdateIsland,
			SRankingUserIsland(
				SRankingUserIslandCore(
					SRankingUserCore(
						GetNick(),
						CharCode,
						GetCountryCode()),
					Proto_.PassedIslandCount,
					Proto_.Gold),
				GetUID(),
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
ERet CUser::BattleJoin(void)
{
	if (_BattleJoining)
		return ERet::AlreadyBattleJoining;

	if (InBattle())
		return ERet::AlreadyInBattle;

	_BattleJoining = true;
	Send(SBattleJoinNetSc());

	return ERet::Ok;
}
ERet CUser::BattleOut(void)
{
	if (!_BattleJoining)
		return ERet::NotBattleJoining;

	if (InBattle())
		return ERet::AlreadyInBattle;

	_BattleJoining = false;

	Send(SBattleOutNetSc());

	return ERet::Ok;
}
void CUser::BattleBegin(const SBattleInfo& BattleInfo_)
{
	_BattleJoining = false;
	_BattleInfo = BattleInfo_;
}
void CUser::SingleBattleBegin(const SBattleInfo& BattleInfo_)
{
	_BattleJoining = false;
	_SingleBattleInfo = BattleInfo_;
}
SBattleEndInfo CUser::BattleEnd(const CEngineGameMode* pGameMode_, const SBattleEndPlayer& BattleEndPlayer_, bool Win_)
{
	if (BattleEndPlayer_.AddedPoint > 0)
	{
		if (_User.Point + BattleEndPlayer_.AddedPoint > _User.Point)
			_User.Point += BattleEndPlayer_.AddedPoint;
		else
			_User.Point = MaxValue<int32>();
	}
	else if (BattleEndPlayer_.AddedPoint < 0)
	{
		if (_User.Point + BattleEndPlayer_.AddedPoint > 0)
			_User.Point += BattleEndPlayer_.AddedPoint;
		else
			_User.Point = 0;
	}

	if (_User.Point > _User.PointBest)
		_User.PointBest = _User.Point;

	if (BattleEndPlayer_.BattlePoint > _User.BattlePointBest)
		_User.BattlePointBest = BattleEndPlayer_.BattlePoint;

	pGameMode_->BattleEnd(_User, Win_);

	AddResourceCore(EResource::Gold, BattleEndPlayer_.AddedGold);
	_BattleInfo = SBattleInfo();
	_SingleBattleInfo = SBattleInfo();

	return SBattleEndInfo(
		GetUID(), _User.Resources, _User.Point, _User.PointBest,
		_User.WinCountSolo, _User.LoseCountSolo, _User.WinCountSurvival, _User.LoseCountSurvival, _User.WinCountMulti, _User.LoseCountMulti,
		_User.BattlePointBest, _User.KillTotal, _User.ChainKillTotal, _User.BlowBalloonTotal);
}

ERet CUser::BattleTouch(const SBattleTouchNetCs& Proto_)
{
	auto itBattle = g_Battles.get(_BattleInfo.BattleIndex);
	if (!itBattle)
		return ERet::Ok; // �ð����� ���� ������ �������� ���� ���� �����Ƿ� ���� �뺸���� ����.

	return itBattle->Touch(_BattleInfo.BattlePlayerIndex, Proto_);
}
ERet CUser::BattlePush(const SBattlePushNetCs& Proto_)
{
	auto itBattle = g_Battles.get(_BattleInfo.BattleIndex);
	if (!itBattle)
		return ERet::Ok; // �ð����� ���� ������ �������� ���� ���� �����Ƿ� ���� �뺸���� ����.

	return itBattle->Push(_BattleInfo.BattlePlayerIndex, Proto_);
}
ERet CUser::BattleIcon(const SBattleIconNetCs& Proto_)
{
	auto itBattle = g_Battles.get(_BattleInfo.BattleIndex);
	if (itBattle)
		return itBattle->Icon(_BattleInfo.BattlePlayerIndex, Proto_);

	return ERet::Ok; // �ð����� ���� ������ �������� ���� ���� �����Ƿ� ���� �뺸���� ����.
}
ERet CUser::SingleBattleIcon(const SSingleBattleIconNetCs& Proto_)
{
	auto isSingleBattle = g_SingleBattles.get(_SingleBattleInfo.BattleIndex);
	if (isSingleBattle)
		return isSingleBattle->Icon(_SingleBattleInfo.BattlePlayerIndex, Proto_);

	return ERet::Ok; // �ð����� ���� ������ �������� ���� ���� �����Ƿ� ���� �뺸���� ����.
}
ERet CUser::SingleBattleScore(const SSingleBattleScoreNetCs& Proto_)
{
	auto isSingleBattle = g_SingleBattles.get(_SingleBattleInfo.BattleIndex);
	if (isSingleBattle)
		return isSingleBattle->Score(_SingleBattleInfo.BattlePlayerIndex, Proto_);

	return ERet::Ok; // �ð����� ���� ������ �������� ���� ���� �����Ƿ� ���� �뺸���� ����.
}
ERet CUser::SingleBattleItem(const SSingleBattleItemNetCs& Proto_)
{
	auto isSingleBattle = g_SingleBattles.get(_SingleBattleInfo.BattleIndex);
	if (isSingleBattle)
		return isSingleBattle->Item(_SingleBattleInfo.BattlePlayerIndex, Proto_);

	return ERet::Ok; // �ð����� ���� ������ �������� ���� ���� �����Ƿ� ���� �뺸���� ����.
}

ERet CUser::Gacha(const SGachaNetCs& Proto_)
{
	auto Gacha = g_GameData->GetGacha(Proto_.GachaIndex);
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
	auto Gacha = g_GameData->GetGacha(Proto_.GachaIndex);
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
	auto pRankReward = g_GameData->GetRankReward(_User.PointBest, _User.LastGotRewardRankIndex + 1);
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

	//	count	time	����
	//	�޼�	�̸�	�޼�, ������
	//	�޼�	�̻�	�޼�, ������
	//	�̴�	�̸�	��Ÿ��
	//	�̴�	�̻�	�̴޼�

	auto Now = system_clock::now();
	if (_User.QuestDailyCompleteCount < g_GameData->QuestDailyComplete.RequirmentCount && Now >= _User.QuestDailyCompleteRefreshTime) // �̴޼��̰�, ��Ÿ���� �ƴϸ�
	{
		if (Now >= (_User.QuestDailyCompleteRefreshTime + g_GameData->QuestDailyComplete.RefreshDuration)) // ���� �ֱ⿡ ����������
		{
			auto ElapsedDurationCount = (Now - _User.QuestDailyCompleteRefreshTime) / g_GameData->QuestDailyComplete.RefreshDuration;
			_User.QuestDailyCompleteRefreshTime += (g_GameData->QuestDailyComplete.RefreshDuration * ElapsedDurationCount);
			_User.QuestDailyCompleteCount = 0;
		}

		if (_User.QuestDailyCompleteCount < g_GameData->QuestDailyComplete.RequirmentCount)
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
	if (_User.QuestDailyCompleteCount < g_GameData->QuestDailyComplete.RequirmentCount)
		return ERet::InvalidProtocol;

	auto Now = system_clock::now();
	if (Now < _User.QuestDailyCompleteRefreshTime) // �̹� ��Ÿ��������, �Ϸ�Ǿ��ٸ� �ð��� ��� ������ �ٲ������, �ð� ������������ ������ �� �ްԵǴ� ���� ������ �ֱ⸦ ���� 1ȸ ����
	{
		_User.QuestDailyCompleteRefreshTime += g_GameData->QuestDailyComplete.RefreshDuration;
	}
	else // _User.QuestDailyCompleteRefreshTime �� ���Ŷ��, ���� ����� �̷��� �ֱ⿡ �ش��ϴ� �ð����� ����
	{
		auto ElapsedDurationCount = (Now - _User.QuestDailyCompleteRefreshTime) / g_GameData->QuestDailyComplete.RefreshDuration;
		_User.QuestDailyCompleteRefreshTime += (g_GameData->QuestDailyComplete.RefreshDuration * (ElapsedDurationCount + 1));
	}

	_User.QuestDailyCompleteCount = 0;
	Push(SQuestDailyCompleteRewardDBIn(RewardCore(*g_GameData->QuestDailyComplete.pReward, Proto_.WatchAd ? 2 : 1), _User.QuestDailyCompleteRefreshTime));
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

	for (auto& i : g_GameData->ForbiddenWords)
	{
		if (Nick.find(i) != string::npos)
		{
			Send(SChangeNickFailNetSc(EGameRet::Ok, i));
			return ERet::Ok;
		}
	}

	if (_User.ChangeNickFreeCount <= 0 &&
		!HaveCost(EResource::Dia, g_GameData->ConfigMeta.ChangeNickCostDia))
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
			SubResourceCore(EResource::Dia, g_GameData->ConfigMeta.ChangeNickCostDia);
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
		Send(SCouponUseFailNetSc(ERet::CouponAlreadyUsed)); // ��� ���̰� �Ǵ� �������̹Ƿ� ������ �������� �뺸���� �����Ƿ� Ŭ��� �ڽ��� ����ߴ��� �� �� �����Ƿ� �������� ���� ���� �ʵ���
		return ERet::Ok;
	}

	auto pCoupon = g_GameData->GetCoupon(Proto_.Key);
	if (!pCoupon)
	{
		Send(SCouponUseFailNetSc(ERet::CouponInvalid)); // ������ �߸� �Է��� Ȯ���� ������ ���� ���� �ʵ���
		return ERet::Ok;
	}

	g_pCouponDB->Push(0, _LoginInfo.Key, SCouponUseCouponDBIn(Proto_.Key, GetUID()), pCoupon->Code);

	return ERet::Ok;
}
void CUser::CouponUseOut(const SCouponUseCouponDBIn& In_, int32 Code_)
{
	auto pCoupon = g_GameData->GetCoupon(Code_);
	if (!pCoupon)
		return; // ���� �⵿�� üũ�����Ƿ� �̷л� �� �� ����

	auto ib = _Coupons.emplace(In_.Key);
	if (!ib.second)
		THROWEX(); // ������ ���޾� ������� (����)

	auto Reward = RewardCore(*pCoupon->pReward, 1);
	Push(SCouponUseDBIn(Reward, In_.Key));
	Send(SCouponUseNetSc(Reward));
}
ERet CUser::TutorialReward(const STutorialRewardNetCs& Proto_)
{
	if (_User.TutorialReward)
		return ERet::InvalidProtocol;

	_User.TutorialReward = true;
	AddResourceCore(EResource::Dia, g_GameData->ConfigMeta.TutorialRewardDia);
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

		// IsValidRankingInfo == true �̸� g_NetRanking �� ��ȿ

		list<const SReward*> Rewards;
		int32 RewardCode = 0;
		int32 RewardCodeSingle = 0;
		int32 RewardCodeIsland = 0;

		auto itReward = g_RankingInfo.Rewards.find(GetUID());
		if (itReward != g_RankingInfo.Rewards.end())
		{
			auto itRankingReward = g_GameData->RankingReward[(size_t)ERankingType::Multi].lower_bound(itReward->second);
			if (itRankingReward != g_GameData->RankingReward[(size_t)ERankingType::Multi].end())
			{
				RewardCode = itRankingReward->second->first;
				Rewards.emplace_back(&itRankingReward->second->second);
			}
		}

		auto itRewardSingle = g_RankingInfo.RewardsSingle.find(GetUID());
		if (itRewardSingle != g_RankingInfo.RewardsSingle.end())
		{
			auto itRankingReward = g_GameData->RankingReward[(size_t)ERankingType::Single].lower_bound(itRewardSingle->second);
			if (itRankingReward != g_GameData->RankingReward[(size_t)ERankingType::Single].end())
			{
				RewardCodeSingle = itRankingReward->second->first;
				Rewards.emplace_back(&itRankingReward->second->second);
			}
		}

		auto itRewardIsland = g_RankingInfo.RewardsIsland.find(GetUID());
		if (itRewardIsland != g_RankingInfo.RewardsIsland.end())
		{
			auto itRankingReward = g_GameData->RankingReward[(size_t)ERankingType::Island].lower_bound(itRewardIsland->second);
			if (itRankingReward != g_GameData->RankingReward[(size_t)ERankingType::Island].end())
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
ERet CUser::RoomList(const SRoomListNetCs& Proto_)
{
	SRooms rooms;
	for (auto& i : g_Rooms)
	{
		auto User = GetUser(i.second.MasterUserKey);
		if(User)
			rooms.emplace(i.first, SRoomInfo(i.second.Mode, i.second.RoomIdx, User->GetUID(), User->GetNick(), i.second.Password, (int32)i.second.Users.size(), i.second.State));
	}

	Send(SRoomListNetSc(rooms));
	return ERet::Ok; // �ð����� ���� ������ �������� ���� ���� �����Ƿ� ���� �뺸���� ����.
}
ERet CUser::RoomCreate(const SRoomCreateNetCs& Proto_)
{
	int count = 1;
	while (true)
	{
		if (g_Rooms.find(count) == g_Rooms.end())
		{
			break;
		}
		count++;
	}
	g_Rooms.emplace(count, CRoom(Proto_.Mode, this, Proto_.Password, count));
	_RoomInfo = count;
	Send(SRoomCreateNetSc(SRoomInfo(Proto_.Mode, count, GetUID(), GetNick(), Proto_.Password, g_Rooms.at(count).RoomUserCount, ERoomState::RoomWait)));
	BroadCast(SRoomChangeNetSc(count,SRoomInfo(Proto_.Mode,count, GetUID(), GetNick(), Proto_.Password, g_Rooms.at(count).RoomUserCount, ERoomState::RoomWait), false));
	return ERet::Ok; // �ð����� ���� ������ �������� ���� ���� �����Ƿ� ���� �뺸���� ����.
}
ERet CUser::RoomJoin(const SRoomJoinNetCs& Proto_)
{
	auto& room = g_Rooms.at(Proto_.RoomIdx);
	if (room.JoinRoom(this))
	{
		BroadCast(SRoomChangeNetSc(Proto_.RoomIdx, SRoomInfo(room.Mode, Proto_.RoomIdx, room.MasterUserID, room.MasterUser, room.Password, room.RoomUserCount, room.State), false));
		Send(SRoomJoinNetSc(SRoomInfo(room.Mode, Proto_.RoomIdx, room.MasterUserID, room.MasterUser, room.Password, room.RoomUserCount, room.State)));

		if(room.State == ERoomState::RoomAllReady)
			room.RoomSend(SRoomReadyNetSc(room.Mode));

		_RoomInfo = Proto_.RoomIdx;
	}
	else
	{
		Send(SRoomJoinFailedNetSc());
	}
	return ERet::Ok; // �ð����� ���� ������ �������� ���� ���� �����Ƿ� ���� �뺸���� ����.
}
ERet CUser::RoomOut(const SRoomOutNetCs& Proto_)
{
	auto& room = g_Rooms.at(Proto_.RoomIdx);
	if (room.OutRoom(this))
	{
		if(room.RoomUserCount > 0)
			BroadCast(SRoomChangeNetSc(Proto_.RoomIdx, SRoomInfo(room.Mode, Proto_.RoomIdx, room.MasterUserID, room.MasterUser, room.Password, room.RoomUserCount, room.State), false));
		else
		{
			BroadCast(SRoomChangeNetSc(Proto_.RoomIdx, SRoomInfo(room.Mode, Proto_.RoomIdx, room.MasterUserID, room.MasterUser, room.Password, room.RoomUserCount, room.State), true));
			g_Rooms.erase(Proto_.RoomIdx);
		}
		Send(SRoomOutNetSc());
		_RoomInfo = -1;
	}
	else
	{
		Send(SRoomOutFailedNetSc());
	}
	return ERet::Ok; // �ð����� ���� ������ �������� ���� ���� �����Ƿ� ���� �뺸���� ����.
}
ERet CUser::RoomReady(const SRoomReadyNetCs& Proto_) 
{
	return ERet::Ok; // �ð����� ���� ������ �������� ���� ���� �����Ƿ� ���� �뺸���� ����.
}
ERet CUser::RoomChat(const SRoomChatNetCs& Proto_) 
{
	auto& room = g_Rooms.at(Proto_.RoomIdx);
	room.ChatRoom(this, Proto_.Message);
	return ERet::Ok; // �ð����� ���� ������ �������� ���� ���� �����Ƿ� ���� �뺸���� ����.
}
ERet CUser::RoomNoti(const SRoomNotiNetCs& Proto_) 
{
	auto& room = g_Rooms.at(Proto_.RoomIdx);
	BroadCast(SRoomNotiNetSc(SRoomInfo(room.Mode, Proto_.RoomIdx, room.MasterUserID, room.MasterUser, room.Password, room.RoomUserCount, room.State)));
	return ERet::Ok; // �ð����� ���� ������ �������� ���� ���� �����Ƿ� ���� �뺸���� ����.
}
