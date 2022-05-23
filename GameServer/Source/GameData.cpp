#include "stdafx.h"
#include <GameServer/Common/Base.h>
#include <Rso/Core/SafeInt64.h>
#include <random>

CGameData::CGameData() :
	_QuestTypes((size_t)EQuestType::Max),
	RankingConfigMeta(GetSRankingConfigMeta())
{
	try
	{
		CStream Stream;

		Stream.LoadFile(L"../../MetaData/Checksum.bin");
		Stream >> CheckSumMeta;

		//	Stream.LoadFile(L"../../MetaData/server_config.bin");
		//	list<SServerConfigMeta> ServerConfigMetas;
		//	Stream >> ServerConfigMetas;

		//	if (ServerConfigMetas.empty())
		//		THROWEX();

		//	ServerConfigMeta = ServerConfigMetas.front();

		Stream.LoadFile(L"../../MetaData/Config.bin");
		list<SConfigMeta> ConfigMetas;
		Stream >> ConfigMetas;

		if (ConfigMetas.empty())
			THROWEX();

		ConfigMeta = ConfigMetas.front();

		// Single
		Stream.LoadFile(L"../../MetaData/Single.bin");
		list<SSingleMeta> SingleMetas;
		Stream >> SingleMetas;

		if (SingleMetas.empty())
			THROWEX();

		SingleMeta = SingleMetas.front();
		ASSERTIONA(SingleMeta.PlayCountMax > 0 && SingleMeta.ChargeCostGold > 0 && SingleMeta.ScoreFactorWave > 0 && SingleMeta.ScoreFactorTime > 0 && SingleMeta.ScoreFactorGold, L"Invalid SingleMeta");

		// Island
		Stream.LoadFile(L"../../MetaData/Island.bin");
		list<SIslandMeta> IslandMetas;
		Stream >> IslandMetas;

		if (IslandMetas.empty())
			THROWEX();

		IslandMeta = IslandMetas.front();
		ASSERTIONA(IslandMeta.PlayCountMax > 0 && IslandMeta.ChargeCostGold > 0 && IslandMeta.ScoreFactorIsland > 0 && IslandMeta.ScoreFactorGold, L"Invalid IslandMeta");

		// ForbiddenWords
		Stream.LoadFile(L"../../MetaData/ForbiddenWord.bin");
		Stream >> ForbiddenWords;
		for (auto& i : ForbiddenWords)
			wcslwr((wchar_t*)i.c_str());


		// Character ////////////////////
		vector<SCharacterServerMeta> CharacterMetas;
		Stream.LoadFile(L"../../MetaData/Character.bin");
		Stream >> CharacterMetas;
		ASSERTIONA(!CharacterMetas.empty(), L"CharacterMetas is empty");

		for (auto& i : CharacterMetas)
		{
			_Characters.emplace(i.Code, CCharacter(i));

			if (i.Default)
				DefaultChars.emplace_back(i.Code);
		}

		ASSERTIONA(!DefaultChars.empty(), L"Default Char Not Found");

		// Rewards
		list<SKeyRewardMeta> RewardMetas;
		Stream.LoadFile(L"../../MetaData/Reward.bin");
		Stream >> RewardMetas;

		for (auto& i : RewardMetas)
		{
			auto itReward = _Rewards.emplace(i.Code, SReward{});

			switch (i.Reward.Type)
			{
			case ERewardType::Resource_Ticket:
				itReward.first->second.Resources[(size_t)EResource::Ticket] += i.Reward.Data;
				break;

			case ERewardType::Resource_Gold:
				itReward.first->second.Resources[(size_t)EResource::Gold] += i.Reward.Data;
				break;

			case ERewardType::Resource_Dia:
				itReward.first->second.Resources[(size_t)EResource::Dia] += i.Reward.Data;
				break;

			case ERewardType::Resource_CP:
				itReward.first->second.Resources[(size_t)EResource::CP] += i.Reward.Data;
				break;

			case ERewardType::Character:
			{
				auto itCharacter = _Characters.find(i.Reward.Data);
				if (itCharacter == _Characters.end())
					THROWEX();

				if (!itReward.first->second.Chars.emplace(&itCharacter->second).second)
					THROWEXA(L"Reward.bin Dup CharCode[%d]", i.Reward.Data);

				break;
			}

			default:
				THROWEX();
			}
		}

		ASSERTION(!_Rewards.empty());


		// Gacha Grade //////////////////////////////////////
		Stream.LoadFile(L"../../MetaData/GachaGrade.bin");
		map<EGrade, double> GradeProbabilityMetas;
		Stream >> GradeProbabilityMetas;


		// GachaReward ///////////////////////////////
		Stream.LoadFile(L"../../MetaData/GachaReward.bin");
		list<SGachaRewardMeta> GachaRewardMetas;
		Stream >> GachaRewardMetas;
		ASSERTIONA(!GachaRewardMetas.empty(), L"GachaRewardMetas is empty");

		map<int32, TProbabilityGrades> Gacha;

		for (auto& i : GachaRewardMetas)
		{
			auto itChar = _Characters.find(i.CharCode);
			ASSERTIONA(itChar != _Characters.end(), L"Invalid Gacha Reward CharCode [%d]", i.CharCode);

			auto itProbabilityGrades = Gacha.find(i.Code);
			if (itProbabilityGrades == Gacha.end())
				itProbabilityGrades = Gacha.emplace(i.Code, TProbabilityGrades()).first;

			// Grade 의 확률 찾기
			auto itGradeProbability = GradeProbabilityMetas.find(itChar->second.Grade);
			ASSERTIONA(itGradeProbability != GradeProbabilityMetas.end(), L"Not Found Grade [%d] For GachaGrade", (int32)itChar->second.Grade);

			auto itProbabilityGrade = itProbabilityGrades->second.find(itChar->second.Grade);
			if (itProbabilityGrade == itProbabilityGrades->second.end())
				itProbabilityGrade = itProbabilityGrades->second.emplace(itChar->second.Grade, TProbabilityGrade(itGradeProbability->second, TProbabilityCharacters())).first;

			itProbabilityGrade->second.second.emplace_back(TProbabilityCharacter(i.Probability, &itChar->second));
		}


		// Shop ///////////////////////////////
		Stream.LoadFile(L"../../MetaData/Shop.bin");
		list<SShopServerMeta> ShopServerMetas;
		Stream >> ShopServerMetas;

		for (auto& i : ShopServerMetas)
		{
			auto Reward = _Rewards.find(i.RewardCode);
			if (Reward == _Rewards.end())
				THROWEX();

			auto Cost = CheckAndGetResources(SResourceTypeData(i.CostType, i.CostValue));
			GoodsItems.emplace(i.Code, SGoods(Cost, &Reward->second));
		}


		// ShopConfig //////////////////////////
		Stream.LoadFile(L"../../MetaData/ShopConfig.bin");
		list<SShopConfigServerMeta> ShopConfigs;
		Stream >> ShopConfigs;
		ASSERTION(ShopConfigs.size() == 1);
		ShopConfig = ShopConfigs.front();


		// ShopPackage //////////////////////////
		Stream.LoadFile(L"../../MetaData/ShopPackage.bin");
		list<SShopPackageServerMeta> ShopPackages;
		Stream >> ShopPackages;

		for (auto& i : ShopPackages)
		{
			auto Reward = _Rewards.find(i.RewardCode);
			if (Reward == _Rewards.end())
				THROWEX();

			Packages.emplace(i.Code, SPackage(i, &Reward->second));
		}

		// ShopDailyReward //////////////////////////
		Stream.LoadFile(L"../../MetaData/ShopDailyReward.bin");
		list<SShopDailyRewardServerMeta> ShopDailyRewards;
		Stream >> ShopDailyRewards;

		for (auto& i : ShopDailyRewards)
			DailyReward.Insert(i.Probability, i);


		// ShopCash ///////////////////////////////
		Stream.LoadFile(L"../../MetaData/ShopCash.bin");
		list<SShopCashServerMeta> ShopCashServerMetas;
		Stream >> ShopCashServerMetas;

		for (auto& i : ShopCashServerMetas)
			CashItems.emplace(i.Pid, i);


		// Gacha ///////////////////////////////
		Stream.LoadFile(L"../../MetaData/Gacha.bin");
		Stream >> _GachaMetas;
		ASSERTIONA(!_GachaMetas.empty(), L"_GachaMetas is empty");

		for (int i = 0; i < _GachaMetas.size(); ++i)
		{
			auto& Meta = _GachaMetas[i];

			auto itRewardMeta = Gacha.find(Meta.RewardCode);
			ASSERTIONA(itRewardMeta != Gacha.end(), L"Invalid RewardCode [%d]", Meta.RewardCode);

			_Gachas.emplace_back(new CGacha(Meta, i, itRewardMeta->second));
		}

		//	Stream.LoadFile(L"../../MetaData/exp.bin");
		//	Stream >> ExpMetas;

		//	for (size_t i = 0; i < ExpMetas.size(); ++i)
		//		_ExpToLevel.emplace(ExpMetas[i], TLevel(i));

		//	if (_ExpToLevel.empty())
		//		THROWEX();

		//	
		//	Stream.LoadFile(L"../../MetaData/shop_cash_item.bin");
		//	list<SShopCashItemMeta> ShopCashItemMetas;
		//	Stream >> ShopCashItemMetas;
		//	for (auto& i : ShopCashItemMetas)
		//	{
		//		switch (i.type)
		//		{
		//		case ECashItemType::ResourcesPack:
		//		{
		//			auto ib = CashItems.emplace(WCSToMBS(i.product_id), new CCashItemResourcesPack(i.data));
		//			if (!ib.second)
		//				THROWEX();

		//			break;
		//		}
		//		default:
		//			THROWEX();
		//		}
		//	}

		//	Stream.LoadFile(L"../../MetaData/shop_goods_item.bin");
		//	list<SShopGoodsItemMeta> ShopGoodsItemMetas;
		//	Stream >> ShopGoodsItemMetas;
		//	for (auto& i : ShopGoodsItemMetas)
		//	{
		//		switch (i.type)
		//		{
		//		case EGoodsItemType::AvatarColor:
		//		{
		//			break;
		//		}
		//		default:
		//			THROWEX();
		//		}
		//	}


		list<SRankMeta> RankMetas;
		Stream.LoadFile(L"../../MetaData/Rank.bin");
		Stream >> RankMetas;

		ASSERTIONA(ERank(RankMetas.size()) == ERank::Max, L"Invalid Rank Size");


		list<SRankTierMeta> RankTierMetas;
		Stream.LoadFile(L"../../MetaData/RankTier.bin");
		Stream >> RankTierMetas;

		for (auto& i : RankTierMetas)
		{
			auto ib = _RankTierMetas.emplace(i.MinPoint, i);
			if (!ib.second)
				THROWEX();
		}
		ASSERTION(!_RankTierMetas.empty());


		list<SRankRewardMeta> RankRewardMetas;
		Stream.LoadFile(L"../../MetaData/RankReward.bin");
		Stream >> RankRewardMetas;
		ASSERTION(!RankRewardMetas.empty());

		// Check that RewardCode Exist
		for (auto& i : RankRewardMetas)
		{
			auto Reward = _Rewards.find(i.RewardCode);
			if (Reward == _Rewards.end())
				THROWEX();

			_RankRewards.emplace_back(SRankReward(i, &Reward->second));
		}

		vector<SQuestMeta> Quests;
		Stream.LoadFile(L"../../MetaData/Quest.bin");
		Stream >> Quests;

		for (int i = 0; i < Quests.size(); ++i)
		{
			auto& Quest = Quests[i];
			auto itReward = _Rewards.find(Quest.RewardCode);

			ASSERTIONA(
				Quest.RequirmentCount >= 0 &&
				itReward != _Rewards.end()
				, L"Invalid QuestType [%d][%d]", i, (int)Quest.QuestType);

			TQuestCheckFunc QuestCheckFunc;

			if (Quest.Operator == L"<=")
			{
				QuestCheckFunc = [](int32 Param_, int32 CheckValue_) { return Param_ <= CheckValue_; };
			}
			else if (Quest.Operator == L"<")
			{
				QuestCheckFunc = [](int32 Param_, int32 CheckValue_) { return Param_ < CheckValue_; };
			}
			else if (Quest.Operator == L">=")
			{
				QuestCheckFunc = [](int32 Param_, int32 CheckValue_) { return Param_ >= CheckValue_; };
			}
			else if (Quest.Operator == L">")
			{
				QuestCheckFunc = [](int32 Param_, int32 CheckValue_) { return Param_ > CheckValue_; };
			}
			else if (Quest.Operator == L"==")
			{
				QuestCheckFunc = [](int32 Param_, int32 CheckValue_) { return Param_ == CheckValue_; };
			}
			else
			{
				THROWEXA(L"Invalid Quest Operator [%s]", Quest.Operator);
			}

			_QuestTypes[(size_t)Quests[i].QuestType].emplace_back(SQuest(Quest, &itReward->second, QuestCheckFunc));
		}

		// 포인터를 얻어와야 하므로 vecter가 모두 추가된 후에 처리
		for (auto& t : _QuestTypes)
		{
			for (auto& i : t)
				ASSERTIONA(_QuestsMap.emplace(i.Code, &i).second, L"Invalid QuestCode[%d]", i.Code);
		}

		for (auto& i : _QuestTypes)
		{
			if (i.empty())
				THROWEX();
		}

		// 현재 완료하여 보상받는 퀘스트를 지우지 않고, 하나 더 새로운 퀘스트를 랜덤으로 뽑으려면 최대보유량 보다 전체퀘스트가 1개 이상 더 많아야 함.
		ASSERTIONA((size_t)EQuestType::Max > c_QuestCnt_Max && _QuestTypes.size() == (size_t)EQuestType::Max, L"Invalid _QuestTypes.size()");


		list<SQuestDailyCompleteMeta> QuestDailyCompletes;
		Stream.LoadFile(L"../../MetaData/QuestDailyComplete.bin");
		Stream >> QuestDailyCompletes;

		ASSERTIONA(!QuestDailyCompletes.empty(), L"QuestDailyComplete empty");

		auto itQuestDailyCompleteReward = _Rewards.find(QuestDailyCompletes.front().RewardCode);
		if (itQuestDailyCompleteReward == _Rewards.end())
			THROWEX();

		ASSERTIONA(QuestDailyCompletes.front().RequirmentCount > 0, L"Invalid QuestDailyCompleteMeta.RequirmentCount");
		QuestDailyComplete = SQuestDailyComplete(QuestDailyCompletes.front(), &itQuestDailyCompleteReward->second);


		// BattleReward ///////////////////////////////////////
		list<SBattleRewardMeta> BattleRewards;
		Stream.LoadFile(L"../../MetaData/BattleReward.bin");
		Stream >> BattleRewards;

		for (auto& i : BattleRewards)
		{
			DLOG(L"BattleRewards %d", (int)i.GameMode);
			SBattleType BattleType = SBattleType(i.GameMode, i.TeamMemberCount, i.TeamCount);
			auto ib = _BattleTypeInfos.emplace(i.GameMode, SBattleTypeInfo(BattleType, CEngineGlobal::GetGameModeMulti(BattleType)));
			ib.first->second.BattleReward.emplace_back(SBattleReward(i.AddGold, TPoints{ i.Unranked, i.Bronze, i.Silver, i.Gold, i.Diamond, i.Champion }));
			ASSERTION(ib.first->second.BattleReward.back().Points.size() == (size_t)ERank::Max);
		}

		// Map /////////////////////////////////////////////
		Stream.LoadFile(L"../../MetaData/Map.bin");
		Stream >> _MapMeta;

		for (int i = 0; i < _MapMeta.OneOnOneMaps.size(); ++i)
			ASSERTIONA(_MapMeta.OneOnOneMaps[i].Poses.size() <= c_MaxPlayer, L"Invalid PlayerPos.Poses size");


		// Check Map ///////////
		for (auto& i : _BattleTypeInfos)
		{
			for (auto& m : GetMaps(i.second.pGameMode.get()))
			{
				auto AllMemberCount = i.second.pGameMode->GetAllMemberCount();
				ASSERTIONA(m.Poses.size() >= AllMemberCount, L"Invalid Poses Count [%d]", m.Poses.size());
			}
		}


		// Coupon //////////////////////////////////////////////////
		list<SCouponMeta> CouponMetas;
		Stream.LoadFile(L"../../MetaData/Coupon.bin");
		Stream >> CouponMetas;
		for (auto& i : CouponMetas)
		{
			auto Reward = _Rewards.find(i.RewardCode);
			if (Reward == _Rewards.end())
				THROWEX();

			auto ib = _Coupons.emplace(i.Code,
				SCoupon(
					i.Code,
					CDateTime(SDateTime(i.StartYear, i.StartMonth, i.StartDay, i.StartHour, 0, 0), true).ToTimePoint(),
					CDateTime(SDateTime(i.EndYear, i.EndMonth, i.EndDay, i.EndHour, 0, 0), true).ToTimePoint(),
					&Reward->second));

			ASSERTIONA(ib.second, L"Already used Coupon Code[%d]", i.Code);
			ASSERTIONA(ib.first->second.StartTime < ib.first->second.EndTime, L"Invalid Coupont Start, End Time");
		}

		list<SCouponKeyMeta> CouponKeyMetas;
		Stream.LoadFile(L"../../MetaData/CouponKey.bin");
		Stream >> CouponKeyMetas;
		for (auto& i : CouponKeyMetas)
		{
			auto itCoupon = _Coupons.find(i.Code);
			if (itCoupon == _Coupons.end())
				THROWEX();

			auto ib = _CouponKeys.emplace(i.Key, &itCoupon->second);
			ASSERTIONA(ib.second, L"Already used Coupon Key[%s]", i.Key);
		}

		Stream.LoadFile(L"../../MetaData/RankingReward.bin");
		list<SRankingRewardMeta> RankingRewardMetas;
		Stream >> RankingRewardMetas;
		RankingReward.resize((size_t)ERankingType::Max);

		for (auto& i : RankingRewardMetas)
		{
			ERankingType RankingType = ERankingType::Null;

			if (i.Mode == L"MULTI")
				RankingType = ERankingType::Multi;
			else if (i.Mode == L"ARROW")
				RankingType = ERankingType::Single;
			else if (i.Mode == L"ISLAND")
				RankingType = ERankingType::Island;
			else
				THROWEXA(L"Invalid RankingReward ModeName[%s]", i.Mode);

			auto itReward = _Rewards.find(i.RewardCode);
			if (itReward == _Rewards.end())
				THROWEXA(L"Invalid Reward Code[%d]", i.RewardCode);

			if (!RankingReward[(size_t)RankingType].emplace(i.End, itReward).second)
				THROWEX();
		}
	}
	catch (const SException& Exception_)
	{
		cout << Exception_.what() << endl;
		throw Exception_;
	}
	catch (...)
	{
		THROWEX();
	}
}
TLevel CGameData::ExpToLevel(TExp Exp_) const
{
	return 1; // rrr 경험치 테이블 만들것.
	return _ExpToLevel.get(Exp_)->second;
}
TExp CGameData::LevelToExp(TLevel Level_) const
{
	return 0; // rrr 경험치 테이블 만들것.


	if (Level_ < 0)
		return 0;

	if (Level_ >= ExpMetas.size())
		Level_ = TLevel(ExpMetas.size() - 1);

	return ExpMetas[Level_];
}
TExp CGameData::GetMaxExp(void) const
{
	return 0; // rrr 경험치 테이블 만들것.

	return ExpMetas.back();
}
const SRankTierMeta& CGameData::GetRankTier(int32 Point_) const
{
	auto Meta = _RankTierMetas.get(Point_);
	if (Meta != _RankTierMetas.end())
		return Meta->second;
	else
		return _RankTierMetas.begin()->second;
}
int32 CGameData::GetDefaultChar(void) const
{
	return DefaultChars[rand() % DefaultChars.size()];
}
CGacha* CGameData::GetGacha(int32 Index_) const
{
	if (Index_ < 0 || Index_ >= _Gachas.size())
		return nullptr;

	return _Gachas[Index_].get();
}
const SReward* CGameData::GetRankReward(int32 PointBest_, int32 RewardIndex_) const
{
	if (RewardIndex_ > _RankRewards.size() - 1)
		return nullptr;

	if (PointBest_ < _RankRewards[RewardIndex_].Point)
		return nullptr;

	return _RankRewards[RewardIndex_].pReward;
}
const CCharacter* CGameData::GetCharacter(int32 Code_) const
{
	auto it = _Characters.find(Code_);
	if (it == _Characters.end())
		return nullptr;

	return &it->second;
}
const vector<SMultiMap>& CGameData::GetMaps(const CEngineGameMode* pGameMode_) const
{
	return pGameMode_->GetMap(_MapMeta);
}
CGameData::_TMapInfo CGameData::GetMultiMap(const CEngineGameMode* pGameMode_) const
{
	auto& Maps = GetMaps(pGameMode_);

	auto MapIndex = (g_Option.Debug > 0 ? g_MapIndex : -1);

	if (MapIndex < 0 || MapIndex >= Maps.size())
		MapIndex = rand() % Maps.size();

	auto& Map = Maps[MapIndex];
	
	return _TMapInfo(MapIndex, Map); // 체크 했으므로 BattleType 에 맞는 맵이라고 간주
}
const SQuest* CGameData::GetQuest(int32 Code_) const
{
	auto it = _QuestsMap.find(Code_);
	if (it == _QuestsMap.end())
		return nullptr;

	return it->second;
}
const SCoupon* CGameData::GetCoupon(int32 Code_) const // 날짜 검사 하지 않음.
{
	auto itCoupon = _Coupons.find(Code_);
	if (itCoupon == _Coupons.end())
		return nullptr;

	return &itCoupon->second;
}
const SCoupon* CGameData::GetCoupon(const wstring& Key_) const
{
	auto itCoupon = _CouponKeys.find(Key_);
	if (itCoupon == _CouponKeys.end())
		return nullptr;

	auto Now = system_clock::now();
	if (Now < (itCoupon->second->StartTime - c_TimeError) || Now >= (itCoupon->second->EndTime + c_TimeError))
		return nullptr;

	return itCoupon->second;
}
