#pragma once

struct SReward
{
	static unique_ptr<SReward> create(const wstring& type, int32 value);

	TResources Resources{};
	set<const CCharacter*> Chars;

	list<int32> getCharacterCodes(void) const;
};
list<int32> getCharacterCodesWithRewards(const list<const SReward*>& rewards);
struct SRankReward : public SRankRewardMeta
{
	unique_ptr<SReward> pReward;

	SRankReward(const SRankRewardMeta& super) :
		SRankRewardMeta(super),
		pReward(SReward::create(super.rewardType, super.rewardValue))
	{
	}
};
using TMapIndexPoses = pair<int32, const TPoses*>;

struct Quest : public SQuestMeta
{
	unique_ptr<SReward> pReward;

public:
	Quest(const SQuestMeta& super) :
		SQuestMeta(super),
		pReward(SReward::create(super.rewardType, super.rewardValue))
	{
	}
};
struct QuestConfig : public QuestConfigMeta
{
	unique_ptr<SReward> pReward;

	QuestConfig() :
		pReward(nullptr)
	{
	}
	QuestConfig(const QuestConfigMeta& Super_) :
		QuestConfigMeta(Super_),
		pReward(SReward::create(Super_.dailyRewardType, Super_.dailyRewardValue))
	{
	}
};

using TCouponKeys = set<wstring>;
struct SCoupon
{
	int32 Code = 0;
	TTime StartTime;
	TTime EndTime;
	unique_ptr<SReward> pReward;

	SCoupon(const SCouponMeta& meta) :
		Code(meta.Code),
		StartTime(CDateTime(SDateTime(meta.StartYear, meta.StartMonth, meta.StartDay, meta.StartHour, 0, 0), true).ToTimePoint()),
		EndTime(CDateTime(SDateTime(meta.EndYear, meta.EndMonth, meta.EndDay, meta.EndHour, 0, 0), true).ToTimePoint()),
		pReward(SReward::create(meta.rewardType, meta.rewardValue))
	{
	}
};

struct MultiBattleConfig : MultiBattleConfigMeta
{
	milliseconds DisconnectableMilliseconds;
	minutes PunishMinutesForDisconnect;
	CClosedRank<uint32, seconds> MatchDeniedSecondsSelector;

	MultiBattleConfig(const MultiBattleConfigMeta& super, milliseconds DisconnectableMilliseconds_, minutes PunishMinutesForDisconnect_) :
		MultiBattleConfigMeta(super),
		DisconnectableMilliseconds(DisconnectableMilliseconds_),
		PunishMinutesForDisconnect(PunishMinutesForDisconnect_)
	{
	}
};

class CMetaData
{
	map<wstring, CharacterTypeMeta> _characterTypeMetas;
	map<int32, CCharacter> _Characters;
	float _MinVelAir = (std::numeric_limits<float>::max)();
public:
	float GetMinVelAir(void) const { return _MinVelAir; }
private:
	CClosedRank<TExp, TLevel, greater<TExp>> _ExpToLevel;
	vector<TExp> ExpMetas;
public:
	CClosedRank<int32, SRankTierMeta> RankTiers;
private:
	vector<SRankReward> _RankRewards;
public:
	unique_ptr<MultiBattleConfig> pMultiBattleConfig;
	mt19937_64 _randomEngine;
	CClosedRank<double, EResource> _multiBattleDiaRewardTypes;
	ArrowDodgeConfigMeta arrowDodgeConfigMeta;
	FlyAwayConfigMeta flyAwayConfigMeta;
private:
	vector<SArrowDodgeItemMeta> _ArrowDodgeItemMetas;
public:
	inline const vector<SArrowDodgeItemMeta>& GetArrowDodgeItemMetas(void) const
	{
		return _ArrowDodgeItemMetas;
	}
	CClosedRank<uint32, EArrowDodgeItemType> _ArrowDodgeItemSelector;
	inline EArrowDodgeItemType GetRandomArrowDodgeItemType(uint32 RandomNumber_)
	{
		auto itLast = _ArrowDodgeItemSelector.cend();
		--itLast;
		return _ArrowDodgeItemSelector.get(RandomNumber_ % itLast->first)->second;
	}
private:
	vector<SFlyAwayItemMeta> _FlyAwayItemMetas;
public:
	inline const vector<SFlyAwayItemMeta>& GetFlyAwayItemMetas(void) const
	{
		return _FlyAwayItemMetas;
	}

	CClosedRank<uint32, EFlyAwayItemType> _FlyAwayStaminaItemSelector;
	inline EFlyAwayItemType GetRandomFlyAwayStaminaItemType(uint32 RandomNumber_)
	{
		auto itLast = _FlyAwayStaminaItemSelector.cend();
		--itLast;
		return _FlyAwayStaminaItemSelector.get(RandomNumber_ % itLast->first)->second;
	}
	SMapMeta MapMeta;
private:
	vector<vector<Quest>> _QuestTypes;
	map<int32, const Quest*> _QuestsMap;
	map<int32, SCoupon> _Coupons;
	map<wstring, const SCoupon*> _CouponKeys;

public:
	QuestConfig questConfig;
	TForbiddenWords ForbiddenWords;
	SServerConfigMeta ServerConfigMeta;
	SConfigMeta ConfigMeta;
	TResources MaxResources;
	map<int32, unique_ptr<const ShopItem>> shopItems;
private:
	map<EResource, ExchangeValue> _exchangeValues;
public:
	vector<int32> DefaultChars;
	TCoreCheckSum CheckSumMeta = 0;
	SRankingConfigMeta RankingConfigMeta;
	vector<CRank<int32, shared_ptr<SReward>>> RankingReward; // IndexOrder (Multi, Arrow, Island), second { first : Ranking, second : RewardCode }

	CMetaData();
	TLevel ExpToLevel(TExp Exp_) const;
	TExp LevelToExp(TLevel Level_) const;
	TExp GetMaxExp(void) const;
	int32 GetDefaultChar(void) const;
	const SReward* GetRankReward(int32 PointBest_, int32 RewardIndex_) const;
	const CCharacter* GetCharacter(int32 Code_) const;
	const map<int32, CCharacter>& GetCharacters(void) const { return _Characters; }
	const SMultiMap* GetMultiMap(void) const;
	inline size_t GetMultiMapCount(void) const { return MapMeta.OneOnOneMaps.size(); }
	const SArrowDodgeMap* GetArrowDodgeMap(void) const {
		return &MapMeta.ArrowDodgeMapInfo.Maps.front();
	}
	const SFlyAwayMap* GetFlyAwayMap(void) const {
		return &MapMeta.FlyAwayMapInfo.Maps.front();
	}
	const vector<Quest>& GetQuest(EQuestType QuestType_) const { return _QuestTypes[(size_t)QuestType_]; }
	const Quest* GetQuest(int32 Code_) const;
	const SCoupon* GetCoupon(int32 Code_) const;
	const SCoupon* GetCoupon(const wstring& Key_) const;
	optional<ExchangeValue> getExchangeValue(EResource targetResource);
	EResource getMultiBattleDiaRewardType(void);
};
