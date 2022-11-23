#include "stdafx.h"
#include <GameServer/Common/Base.h>
#include <Rso/Core/SafeInt64.h>
#include <random>

unique_ptr<SReward> SReward::create(const wstring& type, int32 value)
{
	auto pReward = make_unique<SReward>();

	if (type == L"Gold")
	{
		pReward->Resources[(size_t)EResource::Gold] += value;
	}
	else
	{
		THROWEX();
	}

	return pReward;
}

CMetaData::CMetaData() :
	_QuestTypes((size_t)EQuestType::Max),
	MaxResources(getFullResources()),
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
		ForbiddenWords = GetForbiddenWords();


		// Character ////////////////////
		{
			// CharacterType
			Stream.LoadFile(L"../../MetaData/CharacterType.bin");
			Stream >> _characterTypeMetas;
			ASSERTIONA(!_characterTypeMetas.empty(), L"_characterTypeMetas is empty");

			for (auto& i : _characterTypeMetas)
			{
				if (i.second.MaxVelAir < _MinVelAir)
					_MinVelAir = i.second.MaxVelAir;
			}


			// Character
			vector<CharacterMeta> characterMetas;
			Stream.LoadFile(L"../../MetaData/Character.bin");
			Stream >> characterMetas;
			ASSERTIONA(!characterMetas.empty(), L"characterMetas is empty");

			for (auto& i : characterMetas)
			{
				auto itCharacterTypeMeta = _characterTypeMetas.find(i.type);
				if (itCharacterTypeMeta == _characterTypeMetas.end())
					THROWEX();

				_Characters.emplace(i.Code, CCharacter(SCharacterMeta(i, &itCharacterTypeMeta->second)));
			}
		}

		{
			// Shop ///////////////////////////////
			{
			}


			// Check Characters ///////////////////////////
			{
				for (auto& i : _Characters)
				{
					if (i.second.isNFTCharacter())
					{
					}
					else if (i.second.isShopCharacter())
					{
//						ASSERTION(shopCharacterCodesForCheck.find(i.first) != shopCharacterCodesForCheck.end());
					}
					else if (i.second.isRewardCharacter())
					{
						// rso todo character reward 체크할것.
						continue;
					}
					else
					{
						THROWEXA(L"Invalid howToGet [%s]", i.second.pCharacterTypeMeta->howToGet);
					}

					if (i.second.isDefault)
						_defaultChars.emplace_back(i.first);
				}

				ASSERTIONA(!_defaultChars.empty(), L"Default Char Not Found");
			}
		}

		// Shop Exchange //////////////////////////
		{
			Stream.LoadFile(L"../../MetaData/ShopExchange.bin");
			list<ShopExchangeMeta> shopExchangeMetas;
			Stream >> shopExchangeMetas;

			for (auto& i : shopExchangeMetas)
			{
				ASSERTION(i.targetResourceType != i.exchangeValue.costResourceType);

				auto ib = _exchangeValues.emplace(i.targetResourceType, i.exchangeValue);
				ASSERTION(ib.second);
			}
		}


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
			_RankRewards.emplace_back(SRankReward(i));
		}

		vector<SQuestMeta> QuestMetas;
		Stream.LoadFile(L"../../MetaData/Quest.bin");
		Stream >> QuestMetas;

		for (int i = 0; i < QuestMetas.size(); ++i)
		{
			auto& quest = QuestMetas[i];

			ASSERTIONA(
				quest.unitCompleteCount >= 0 &&
				quest.completeCount >= 0
				, L"Invalid QuestType [%d][%d]", i, (int)quest.QuestType);

			_QuestTypes[(size_t)QuestMetas[i].QuestType].emplace_back(Quest(quest));
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


		list<QuestConfigMeta> QuestConfigMetas;
		Stream.LoadFile(L"../../MetaData/QuestConfig.bin");
		Stream >> QuestConfigMetas;

		ASSERTIONA(!QuestConfigMetas.empty(), L"QuestDailyComplete empty");
		ASSERTIONA(QuestConfigMetas.front().dailyRequirementCount > 0, L"Invalid QuestConfigMeta.dailyRequirementCount");
		questConfig = QuestConfig(QuestConfigMetas.front());


		{
			// MultiBattleConfig ///////////////////////////////////////
			list<MultiBattleConfigMeta> MultiBettleConfigMetas;
			Stream.LoadFile(L"../../MetaData/MultiBattleConfig.bin");
			Stream >> MultiBettleConfigMetas;

			ASSERTION(!MultiBettleConfigMetas.empty());
			pMultiBattleConfig = make_unique<MultiBattleConfig>(MultiBettleConfigMetas.front(), milliseconds(MultiBettleConfigMetas.front().DisconnectableSeconds * 1000), minutes(MultiBettleConfigMetas.front().PunishMinutesForDisconnect));


			// MultiBattleReward ///////////////////////////////////////
			list<MultiBattleDiaRewardMeta> MultiBettleDiaRewardMetas;
			Stream.LoadFile(L"../../MetaData/MultiBattleDiaReward.bin");
			Stream >> MultiBettleDiaRewardMetas;

			ASSERTION(!MultiBettleDiaRewardMetas.empty());
			for (auto& i : MultiBettleDiaRewardMetas)
				_multiBattleDiaRewardTypes.emplace(i.ratio, i.diaType);


			// MultiMatchDeniedDuration ///////////////////////////////////
			vector<SMultiMatchDeniedDurationMeta> MultiMatchDeniedDurationMeta;
			Stream.LoadFile(L"../../MetaData/MultiMatchDeniedDuration.bin");
			Stream >> MultiMatchDeniedDurationMeta;

			ASSERTION(!MultiMatchDeniedDurationMeta.empty());
			sort(MultiMatchDeniedDurationMeta.begin(), MultiMatchDeniedDurationMeta.end(), [](const SMultiMatchDeniedDurationMeta& a, const SMultiMatchDeniedDurationMeta& b) { return a.DisconnectedCount < b.DisconnectedCount; });

			for (auto& i : MultiMatchDeniedDurationMeta)
				pMultiBattleConfig->MatchDeniedSecondsSelector.emplace(i.DisconnectedCount, seconds(i.DeniedSeconds));
		}

		{
			// ArrowDodge ///////////////////////////////////////
			list<ArrowDodgeConfigMeta> arrowDodgeConfigMetas;
			Stream.LoadFile(L"../../MetaData/ArrowDodgeConfig.bin");
			Stream >> arrowDodgeConfigMetas;

			ASSERTION(!arrowDodgeConfigMetas.empty());
			arrowDodgeConfigMeta = arrowDodgeConfigMetas.front();
			ASSERTIONA(arrowDodgeConfigMeta.PlayCountMax > 0 && arrowDodgeConfigMeta.ChargeCostGold > 0, L"Invalid ArrowDodgeMeta");


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
			list<FlyAwayConfigMeta> flyAwayConfigMetas;
			Stream.LoadFile(L"../../MetaData/FlyAwayConfig.bin");
			Stream >> flyAwayConfigMetas;

			ASSERTION(!flyAwayConfigMetas.empty());
			flyAwayConfigMeta = flyAwayConfigMetas.front();
			ASSERTIONA(flyAwayConfigMeta.PlayCountMax > 0 && flyAwayConfigMeta.ChargeCostGold > 0, L"Invalid FlyAwayMeta");


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
		for (auto& m : MapMeta.OneOnOneMaps)
			ASSERTIONA(m.Poses.size() >= 2, L"Invalid Poses Count [%d]", m.Poses.size());


		// Coupon //////////////////////////////////////////////////
		list<SCouponMeta> CouponMetas;
		Stream.LoadFile(L"../../MetaData/Coupon.bin");
		Stream >> CouponMetas;
		for (auto& i : CouponMetas)
		{
			auto ib = _Coupons.emplace(i.Code, SCoupon(i));

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

			if (!RankingReward[(size_t)RankingType].emplace(i.End, SReward::create(i.rewardType, i.rewardValue)).second)
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
const SReward* CMetaData::GetRankReward(int32 PointBest_, int32 RewardIndex_) const
{
	if (RewardIndex_ > _RankRewards.size() - 1)
		return nullptr;

	if (PointBest_ < _RankRewards[RewardIndex_].point)
		return nullptr;

	return _RankRewards[RewardIndex_].pReward.get();
}
const CCharacter* CMetaData::GetCharacter(int32 Code_) const
{
	auto it = _Characters.find(Code_);
	if (it == _Characters.end())
		return nullptr;

	return &it->second;
}
const SMultiMap* CMetaData::GetMultiMap(void) const
{
	auto MapIndex = (g_Option.Debug > 0 ? g_MapIndex : -1);

	if (MapIndex < 0 || MapIndex >= MapMeta.OneOnOneMaps.size())
		MapIndex = rand() % MapMeta.OneOnOneMaps.size();

	return &MapMeta.OneOnOneMaps[MapIndex];
}
const Quest* CMetaData::GetQuest(int32 Code_) const
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
optional<ExchangeValue> CMetaData::getExchangeValue(EResource targetResource)
{
	auto it = _exchangeValues.find(targetResource);
	if (it == _exchangeValues.end())
		return {};

	return it->second;
}
EResource CMetaData::getMultiBattleDiaRewardType(void)
{
	auto randomValue = uniform_real_distribution(0.0, 1.0)(_randomEngine);
	return _multiBattleDiaRewardTypes.get(randomValue)->second;
}
vector<CodeTokenID> CMetaData::getDefaultCharacters() const
{
	vector<CodeTokenID> defaultCharacters;

	for (auto& i : _defaultChars)
		defaultCharacters.emplace_back(i, newGuid());

	return defaultCharacters;
}
