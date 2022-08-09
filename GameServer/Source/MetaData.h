#pragma once

struct SReward
{
	TResources Resources{};
	set<const CCharacter*> Chars;
};
struct SRankReward : public SRankRewardMeta
{
	const SReward* pReward = nullptr;

	SRankReward(const SRankRewardMeta& Super_, const SReward* pReward_) :
		SRankRewardMeta(Super_), pReward(pReward_)
	{
	}
};
using TMapIndexPoses = pair<int32, const TPoses*>;

using TQuestCheckFunc = function<bool(int32 Param_, int32 CheckValue_)>;
struct SQuest : public SQuestMeta
{
	const SReward* pReward = nullptr;

private:
	TQuestCheckFunc CheckFunc;
	int32 Param = 0;

public:
	SQuest(const SQuestMeta& Super_, const SReward* pReward_, TQuestCheckFunc CheckFunc_) :
		SQuestMeta(Super_),
		pReward(pReward_),
		CheckFunc(CheckFunc_)
	{
		try
		{
			Param = stoi(Super_.Param);
		}
		catch (...)
		{
		}
	}
	bool Check(int32 CheckValue_) const
	{
		return CheckFunc(Param, CheckValue_);
	}
};
struct SQuestDailyComplete : public SQuestDailyCompleteMeta
{
	const SReward* pReward;
	minutes RefreshDuration;

	SQuestDailyComplete() :
		pReward(nullptr),
		RefreshDuration(minutes(0))
	{
	}
	SQuestDailyComplete(const SQuestDailyCompleteMeta& Super_, const SReward* pReward_) :
		SQuestDailyCompleteMeta(Super_),
		pReward(pReward_),
		RefreshDuration(minutes(Super_.RefreshMinutes))
	{
	}
};

struct SShopItem
{
	TResources Cost;
	const SReward* pReward = nullptr;

	SShopItem(const TResources& Cost_, const SReward* pReward_) :
		Cost(Cost_),
		pReward(pReward_)
	{
	}
};
struct SShopPackage : public SShopPackageServerMeta
{
	const SReward* pReward = nullptr;

	SShopPackage(const SShopPackageServerMeta& Meta_, const SReward* pReward_) :
		SShopPackageServerMeta(Meta_),
		pReward(pReward_)
	{
	}
};

using TCouponKeys = set<wstring>;
struct SCoupon
{
	int32 Code = 0;
	TTime StartTime;
	TTime EndTime;
	const SReward* pReward = nullptr;

	SCoupon(int32 Code_, const TTime& StartTime_, const TTime& EndTime_, const SReward* pReward_) :
		Code(Code_), StartTime(StartTime_), EndTime(EndTime_), pReward(pReward_)
	{
	}
};

using TRewards = map<int32, SReward>;
using TRewardsIt = TRewards::iterator;

struct SMultiBattleMeta
{
	milliseconds DisconnectableMilliseconds;
	minutes PunishMinutesForDisconnect;
	CClosedRank<uint32, seconds> MatchDeniedSecondsSelector;

	SMultiBattleMeta(milliseconds DisconnectableMilliseconds_, minutes PunishMinutesForDisconnect_) :
		DisconnectableMilliseconds(DisconnectableMilliseconds_),
		PunishMinutesForDisconnect(PunishMinutesForDisconnect_)
	{
	}
};

class CMetaData
{
	using _TMapInfo = tuple<int32, const SMultiMap&>;

	map<int32, CCharacter> _Characters;
	float _MinVelXAir = (std::numeric_limits<float>::max)();
	float _MinVelUp = (std::numeric_limits<float>::max)();
	float _MinVelDown = (std::numeric_limits<float>::max)();
public:
	float GetMinVelXAir(void) const { return _MinVelXAir; }
	float GetMinVelUp(void) const { return _MinVelUp; }
	float GetMinVelDown(void) const { return _MinVelDown; }
private:
	vector<SGachaMeta> _GachaMetas;
	vector<unique_ptr<CGacha>> _Gachas;
	CClosedRank<TExp, TLevel, greater<TExp>> _ExpToLevel;
	vector<TExp> ExpMetas;
	TRewards _Rewards;
	map<SBattleType, SBattleTypeInfo> _BattleTypeInfos; // key : 팀수(게임모드)
public:
	CClosedRank<int32, SRankTierMeta> RankTiers;
private:
	vector<SRankReward> _RankRewards;
public:
	unique_ptr<SMultiBattleMeta> pMultiBattleMeta;
	SArrowDodgeMeta ArrowDodgeMeta;
	SFlyAwayMeta FlyAwayMeta;
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
	vector<vector<SQuest>> _QuestTypes;
	map<int32, const SQuest*> _QuestsMap;
	map<int32, SCoupon> _Coupons;
	map<wstring, const SCoupon*> _CouponKeys;

public:
	SQuestDailyComplete QuestDailyComplete;
	vector<wstring> ForbiddenWords;
	SServerConfigMeta ServerConfigMeta;
	SConfigMeta ConfigMeta;
	TResources MaxResources;
	SShopConfigServerMeta ShopConfig;
	map<int32, SShopItem> ShopItems;
	map<int32, SShopPackage> ShopPackages;
	CRandomBox<double, SShopDailyRewardServerMeta> DailyReward;
	vector<int32> DefaultChars;
	TCoreCheckSum CheckSumMeta = 0;
	SRankingConfigMeta RankingConfigMeta;
	vector<CRank<int32, TRewardsIt>> RankingReward; // IndexOrder (Multi, Arrow, Island), second { first : Ranking, second : RewardCode }

	CMetaData();
	TLevel ExpToLevel(TExp Exp_) const;
	TExp LevelToExp(TLevel Level_) const;
	TExp GetMaxExp(void) const;
	int32 GetDefaultChar(void) const;
	CGacha* GetGacha(int32 Index_) const;
	inline const map<SBattleType, SBattleTypeInfo>& GetBattleTypeInfos(void) const { return _BattleTypeInfos; }
	const SReward* GetRankReward(int32 PointBest_, int32 RewardIndex_) const;
	const CCharacter* GetCharacter(int32 Code_) const;
	const map<int32, CCharacter>& GetCharacters(void) const { return _Characters; }
	_TMapInfo GetMultiMap(void) const;
	inline size_t GetMultiMapCount(void) const { return MapMeta.OneOnOneMaps.size(); }
	const SArrowDodgeMap* GetArrowDodgeMap(void) const {
		return &MapMeta.ArrowDodgeMapInfo.Maps.front();
	}
	const SFlyAwayMap* GetFlyAwayMap(void) const {
		return &MapMeta.FlyAwayMapInfo.Maps.front();
	}
	const vector<SQuest>& GetQuest(EQuestType QuestType_) const { return _QuestTypes[(size_t)QuestType_]; }
	const SQuest* GetQuest(int32 Code_) const;
	const SCoupon* GetCoupon(int32 Code_) const;
	const SCoupon* GetCoupon(const wstring& Key_) const;
};
