#include "stdafx.h"
#include <GameServer/Common/Base.h>
#include <Rso/Core/SafeInt64.h>
#include <random>

CMetaData::CMetaData() :
	_QuestTypes((size_t)EQuestType::Max),
	MaxResources(MakeResources(MaxValue<TResource>())),
	RankingConfigMeta(GetSRankingConfigMeta())
{
	try
	{
		CStream Stream;

		Stream.LoadFile(L"../../MetaData/Checksum.bin");
		Stream >> CheckSumMeta;


		Stream.LoadFile(L"../../MetaData/Config.bin");
		list<SConfigMeta> ConfigMetas;
		Stream >> ConfigMetas;

		if (ConfigMetas.empty())
			THROWEX();

		ConfigMeta = ConfigMetas.front();
		MaxResources[(size_t)EResource::Ticket] = ConfigMeta.MaxTicket;

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
			if (i.MaxVelXAir < _MinVelXAir)
				_MinVelXAir = i.MaxVelXAir;

			if (i.MaxVelUp < _MinVelUp)
				_MinVelUp = i.MaxVelUp;

			if (i.MaxVelDown < _MinVelDown)
				_MinVelDown = i.MaxVelDown;

			_Characters.emplace(i.Code, CCharacter(i));

			if (i.Default)
				DefaultChars.emplace_back(i.Code);
		}

		ASSERTIONA(!DefaultChars.empty(), L"Default Char Not Found");

		// Rewards
		list<SCodeRewardItemMeta> RewardItemMetas;
		Stream.LoadFile(L"../../MetaData/RewardItem.bin");
		Stream >> RewardItemMetas;

		for (auto& i : RewardItemMetas)
		{
			auto itReward = _Rewards.emplace(i.Code, SReward{});

			if (i.RewardItem.Type == L"Resource_Ticket")
			{
				itReward.first->second.Resources[(size_t)EResource::Ticket] += i.RewardItem.Data;
			}
			else if (i.RewardItem.Type == L"Resource_Gold")
			{
				itReward.first->second.Resources[(size_t)EResource::Gold] += i.RewardItem.Data;
			}
			else if (i.RewardItem.Type == L"Character")
			{
				auto itCharacter = _Characters.find(i.RewardItem.Data);
				if (itCharacter == _Characters.end())
					THROWEX();

				if (!itReward.first->second.Chars.emplace(&itCharacter->second).second)
					THROWEXA(L"RewardItem.bin Dup CharCode[%d]", i.RewardItem.Data);
			}
			else
			{
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
		list<SShopMeta> ShopMetas;
		Stream >> ShopMetas;

		for (auto& i : ShopMetas)
		{
			auto Reward = _Rewards.find(i.RewardCode);
			if (Reward == _Rewards.end())
				THROWEX();

			auto Cost = CheckAndGetResources(SResourceTypeData(i.CostType, i.CostValue));
			ShopItems.emplace(i.Code, SShopItem(Cost, &Reward->second));
		}


		// ShopConfig //////////////////////////
		Stream.LoadFile(L"../../MetaData/ShopConfig.bin");
		list<SShopConfigServerMeta> ShopConfigs;
		Stream >> ShopConfigs;
		ASSERTION(ShopConfigs.size() == 1);
		ShopConfig = ShopConfigs.front();


		// ShopPackage //////////////////////////
		Stream.LoadFile(L"../../MetaData/ShopPackage.bin");
		list<SShopPackageServerMeta> ShopPackageMetas;
		Stream >> ShopPackageMetas;

		for (auto& i : ShopPackageMetas)
		{
			auto Reward = _Rewards.find(i.RewardCode);
			if (Reward == _Rewards.end())
				THROWEX();

			ShopPackages.emplace(i.Code, SShopPackage(i, &Reward->second));
		}

		// ShopDailyReward //////////////////////////
		Stream.LoadFile(L"../../MetaData/ShopDailyReward.bin");
		list<SShopDailyRewardServerMeta> ShopDailyRewards;
		Stream >> ShopDailyRewards;

		for (auto& i : ShopDailyRewards)
			DailyReward.Insert(i.Probability, i);


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

		list<SRankMeta> RankMetas;
		Stream.LoadFile(L"../../MetaData/Rank.bin");
		Stream >> RankMetas;

		ASSERTIONA(ERank(RankMetas.size()) == ERank::Max, L"Invalid Rank Size");


		list<SRankTierMeta> RankTierMetas;
		Stream.LoadFile(L"../../MetaData/RankTier.bin");
		Stream >> RankTierMetas;

		for (auto& i : RankTierMetas)
		{
			auto ib = RankTiers.emplace(i.MaxPoint, i);
			if (!ib.second)
				THROWEX();
		}
		ASSERTION(!RankTiers.empty());


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

		{
			size_t EmptyQuestTypeCount = 0;
			for (size_t i = 0; i < _QuestTypes.size(); ++i)
			{
				if (_QuestTypes[i].empty())
				{
					++EmptyQuestTypeCount;
					cout << "Empty Quest Type : " << i << endl;
				}
			}

			ASSERTION(EmptyQuestTypeCount == 0);
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
			auto ib = _BattleTypeInfos.emplace(i.BattleType, SBattleTypeInfo());
			ib.first->second.BattleReward.emplace_back(SBattleReward(i.AddGold, TPoints{ i.Unranked, i.Bronze, i.Silver, i.Gold, i.Diamond, i.Champion }));
			ASSERTION(ib.first->second.BattleReward.back().Points.size() == (size_t)ERank::Max);
		}

		{
			// Multi ///////////////////////////////////////
			list<SMultiMeta> Multis;
			Stream.LoadFile(L"../../MetaData/Multi.bin");
			Stream >> Multis;

			ASSERTION(!Multis.empty());
			pMultiBattleMeta = make_unique<SMultiBattleMeta>(milliseconds(Multis.front().DisconnectableSeconds * 1000), minutes(Multis.front().PunishMinutesForDisconnect));


			// MultiMatchDeniedDuration ///////////////////////////////////
			vector<SMultiMatchDeniedDurationMeta> MultiMatchDeniedDurationMeta;
			Stream.LoadFile(L"../../MetaData/MultiMatchDeniedDuration.bin");
			Stream >> MultiMatchDeniedDurationMeta;

			ASSERTION(!MultiMatchDeniedDurationMeta.empty());
			sort(MultiMatchDeniedDurationMeta.begin(), MultiMatchDeniedDurationMeta.end(), [](const SMultiMatchDeniedDurationMeta& a, const SMultiMatchDeniedDurationMeta& b) { return a.DisconnectedCount < b.DisconnectedCount; });

			for (auto& i : MultiMatchDeniedDurationMeta)
				pMultiBattleMeta->MatchDeniedSecondsSelector.emplace(i.DisconnectedCount, seconds(i.DeniedSeconds));
		}

		{
			// ArrowDodge ///////////////////////////////////////
			list<SArrowDodgeMeta> ArrowDodges;
			Stream.LoadFile(L"../../MetaData/ArrowDodge.bin");
			Stream >> ArrowDodges;

			ASSERTION(!ArrowDodges.empty());
			ArrowDodgeMeta = ArrowDodges.front();
			ASSERTIONA(ArrowDodgeMeta.PlayCountMax > 0 && ArrowDodgeMeta.ChargeCostGold > 0, L"Invalid ArrowDodgeMeta");


			// ArrowDodgeItem ///////////////////////////////////
			Stream.LoadFile(L"../../MetaData/ArrowDodgeItem.bin");
			Stream >> _ArrowDodgeItemMetas;

			ASSERTION(!_ArrowDodgeItemMetas.empty());
			sort(_ArrowDodgeItemMetas.begin(), _ArrowDodgeItemMetas.end(), [](const SArrowDodgeItemMeta& a, const SArrowDodgeItemMeta& b) { return a.ItemType < b.ItemType; });

			uint32 WeightSum = 0;
			for (auto& i : _ArrowDodgeItemMetas)
			{
				WeightSum += i.CreateWeight;
				_ArrowDodgeItemSelector.emplace(WeightSum, i.ItemType);
			}
		}

		{
			// FlyAway ////////////////////////////////////////////
			list<SFlyAwayMeta> FlyAways;
			Stream.LoadFile(L"../../MetaData/FlyAway.bin");
			Stream >> FlyAways;

			ASSERTION(!FlyAways.empty());
			FlyAwayMeta = FlyAways.front();
			ASSERTIONA(FlyAwayMeta.PlayCountMax > 0 && FlyAwayMeta.ChargeCostGold > 0, L"Invalid FlyAwayMeta");


			// FlyAwayItem ///////////////////////////////////
			Stream.LoadFile(L"../../MetaData/FlyAwayItem.bin");
			Stream >> _FlyAwayItemMetas;

			ASSERTION(!_FlyAwayItemMetas.empty());
			sort(_FlyAwayItemMetas.begin(), _FlyAwayItemMetas.end(), [](const SFlyAwayItemMeta& a, const SFlyAwayItemMeta& b) { return a.ItemType < b.ItemType; });

			uint32 WeightSum = 0;
			for (auto& i : _FlyAwayItemMetas)
			{
				WeightSum += i.StaminaCreateWeight;
				_FlyAwayStaminaItemSelector.emplace(WeightSum, i.ItemType);
			}
		}


		// Map /////////////////////////////////////////////
		Stream.LoadFile(L"../../MetaData/Map.bin");
		Stream >> MapMeta;

		for (int i = 0; i < MapMeta.OneOnOneMaps.size(); ++i)
			ASSERTIONA(MapMeta.OneOnOneMaps[i].Poses.size() <= c_MaxPlayer, L"Invalid PlayerPos.Poses size");


		// Check Map ///////////
		for (auto& i : _BattleTypeInfos)
		{
			for (auto& m : MapMeta.OneOnOneMaps)
				ASSERTIONA(m.Poses.size() >= 2, L"Invalid Poses Count [%d]", m.Poses.size());
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
TLevel CMetaData::ExpToLevel(TExp Exp_) const
{
	return 1; // rrr 경험치 테이블 만들것.
	return _ExpToLevel.get(Exp_)->second;
}
TExp CMetaData::LevelToExp(TLevel Level_) const
{
	return 0; // rrr 경험치 테이블 만들것.


	if (Level_ < 0)
		return 0;

	if (Level_ >= ExpMetas.size())
		Level_ = TLevel(ExpMetas.size() - 1);

	return ExpMetas[Level_];
}
TExp CMetaData::GetMaxExp(void) const
{
	return 0; // rrr 경험치 테이블 만들것.

	return ExpMetas.back();
}
int32 CMetaData::GetDefaultChar(void) const
{
	return DefaultChars[rand() % DefaultChars.size()];
}
CGacha* CMetaData::GetGacha(int32 Index_) const
{
	if (Index_ < 0 || Index_ >= _Gachas.size())
		return nullptr;

	return _Gachas[Index_].get();
}
const SReward* CMetaData::GetRankReward(int32 PointBest_, int32 RewardIndex_) const
{
	if (RewardIndex_ > _RankRewards.size() - 1)
		return nullptr;

	if (PointBest_ < _RankRewards[RewardIndex_].Point)
		return nullptr;

	return _RankRewards[RewardIndex_].pReward;
}
const CCharacter* CMetaData::GetCharacter(int32 Code_) const
{
	auto it = _Characters.find(Code_);
	if (it == _Characters.end())
		return nullptr;

	return &it->second;
}
CMetaData::_TMapInfo CMetaData::GetMultiMap(void) const
{
	auto MapIndex = (g_Option.Debug > 0 ? g_MapIndex : -1);

	if (MapIndex < 0 || MapIndex >= MapMeta.OneOnOneMaps.size())
		MapIndex = rand() % MapMeta.OneOnOneMaps.size();

	auto& Map = MapMeta.OneOnOneMaps[MapIndex];
	
	return _TMapInfo(MapIndex, Map); // 체크 했으므로 BattleType 에 맞는 맵이라고 간주
}
const SQuest* CMetaData::GetQuest(int32 Code_) const
{
	auto it = _QuestsMap.find(Code_);
	if (it == _QuestsMap.end())
		return nullptr;

	return it->second;
}
const SCoupon* CMetaData::GetCoupon(int32 Code_) const // 날짜 검사 하지 않음.
{
	auto itCoupon = _Coupons.find(Code_);
	if (itCoupon == _Coupons.end())
		return nullptr;

	return &itCoupon->second;
}
const SCoupon* CMetaData::GetCoupon(const wstring& Key_) const
{
	auto itCoupon = _CouponKeys.find(Key_);
	if (itCoupon == _CouponKeys.end())
		return nullptr;

	auto Now = system_clock::now();
	if (Now < (itCoupon->second->StartTime - c_TimeError) || Now >= (itCoupon->second->EndTime + c_TimeError))
		return nullptr;

	return itCoupon->second;
}
