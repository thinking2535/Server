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
	const SReward* pReward = nullptr;
	minutes RefreshDuration;

	SQuestDailyComplete()
	{
	}
	SQuestDailyComplete(const SQuestDailyCompleteMeta& Super_, const SReward* pReward_) :
		SQuestDailyCompleteMeta(Super_),
		pReward(pReward_),
		RefreshDuration(minutes(Super_.RefreshMinutes))
	{
	}
};

struct SGoods
{
	TResources Cost;
	const SReward* pReward = nullptr;

	SGoods(const TResources& Cost_, const SReward* pReward_) :
		Cost(Cost_),
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
struct SPackage : public SShopPackageServerMeta
{
	const SReward* pReward = nullptr;

	SPackage(const SShopPackageServerMeta& Package_, const SReward* pReward_) :
		SShopPackageServerMeta(Package_),
		pReward(pReward_)
	{
	}
};

using TRewards = map<int32, SReward>;
using TRewardsIt = TRewards::iterator;

class CMetaData
{
	using _TMapInfo = tuple<int32, const SMultiMap&>;

	map<int32, CCharacter> _Characters;
	vector<SGachaMeta> _GachaMetas;
	vector<unique_ptr<CGacha>> _Gachas;
	CRank<TExp, TLevel, greater<TExp>> _ExpToLevel;
	vector<TExp> ExpMetas;
	TRewards _Rewards;
	map<SBattleType, SBattleTypeInfo> _BattleTypeInfos; // key : 팀수(게임모드)
	CRank<int32, SRankTierMeta> _RankTierMetas;
	vector<SRankReward> _RankRewards;
public:
	SArrowDodgeMeta ArrowDodgeMeta;
	CRank<uint64, int32> _ArrowItemSelector;
	inline int32 GetRandomArrowDodgeItemNumber(uint64 RandomNumber_)
	{
		auto itLast = _ArrowItemSelector.cend();
		--itLast;
		return _ArrowItemSelector.get(RandomNumber_ % itLast->first)->second;
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
	SIslandMeta IslandMeta;
	SShopConfigServerMeta ShopConfig;
	map<int32, SGoods> GoodsItems;
	map<int32, SPackage> Packages;
	CRandomBox<double, SShopDailyRewardServerMeta> DailyReward;
	map<wstring, SShopCashServerMeta> CashItems;
	vector<int32> DefaultChars;
	TCoreCheckSum CheckSumMeta = 0;
	SRankingConfigMeta RankingConfigMeta;
	vector<map<int32, TRewardsIt>> RankingReward; // IndexOrder (Multi, Arrow, Island), second { first : Ranking, second : RewardCode }

	CMetaData();
	TLevel ExpToLevel(TExp Exp_) const;
	TExp LevelToExp(TLevel Level_) const;
	TExp GetMaxExp(void) const;
	const SRankTierMeta& GetRankTier(int32 Point_) const;
	int32 GetDefaultChar(void) const;
	CGacha* GetGacha(int32 Index_) const;
	inline const map<SBattleType, SBattleTypeInfo>& GetBattleTypeInfos(void) const { return _BattleTypeInfos; }
	const SReward* GetRankReward(int32 PointBest_, int32 RewardIndex_) const;
	const CCharacter* GetCharacter(int32 Code_) const;
	const map<int32, CCharacter>& GetCharacters(void) const { return _Characters; }
	int32 GetMaxRewardPoint(void) const { return _RankRewards.back().Point; }
	_TMapInfo GetMultiMap(void) const;
	inline size_t GetMultiMapCount(void) const { return MapMeta.OneOnOneMaps.size(); }
	const SArrowDodgeMap* GetArrowDodgeMap(void) const {
		return &MapMeta.ArrowDodgeMapInfo.Maps.front();
	}
	const SFlyAwayMap* GetFlyAwayMap(void) const {
		return &MapMeta.FlyAwayMaps.front();
	}
	const vector<SQuest>& GetQuest(EQuestType QuestType_) const { return _QuestTypes[(size_t)QuestType_]; }
	const SQuest* GetQuest(int32 Code_) const;
	const SCoupon* GetCoupon(int32 Code_) const;
	const SCoupon* GetCoupon(const wstring& Key_) const;
};
