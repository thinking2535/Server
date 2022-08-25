#pragma once

struct SUserLoginInfo
{
	CKey Key;
	SUserLoginOption Option;
	CIPInfo::SCountryCodeMinuteOffset CountryCodeMinuteOffset;
	TTime Time = system_clock::now();

	SUserLoginInfo()
	{
	}
	SUserLoginInfo(const CKey& Key_, const SUserLoginOption& Option_, const CIPInfo::SCountryCodeMinuteOffset& CountryCodeMinuteOffset_) :
		Key(Key_), Option(Option_), CountryCodeMinuteOffset(CountryCodeMinuteOffset_)
	{
	}
};
class CUser
{
	CTimeSync _TimeSync{ c_NetworkDelayTimeSync }; // 클라의 시간이 c_NetworkDelayTimeSync 이상 빨라지면 에러
	TSessionsIt _itSession;
	bool _IsDataLoaded = false;
	SUserDB _User;
	TChars _Chars;
	const CCharacter* _pSelectedChar = nullptr;
	CQuest _Quest;
	SUserLoginInfo _LoginInfo;
	bool _NewRegistered = false;
	bool _BattleJoining = false;
	CBattlePlayer* _pBattlePlayer = nullptr;
	set<wstring> _Coupons;
	TPackages _Packages;

public:
	CUser(TSessionsIt itSession_);
	inline TSessionsIt GetSession(void) { return _itSession; }
	inline TSessionsIt GetSession(void) const { return _itSession; }
	inline int8 GetDebug(void) const { return (g_Option.Debug > _User.Debug ? g_Option.Debug : _User.Debug); }
	inline const CKey& Key(void) const { return _LoginInfo.Key; }
	inline SUserDB& GetUserDB(void) { return _User; }
	inline CKey GetKey(void) const { return _LoginInfo.Key; }
	inline TUID GetUID(void) const { return _itSession->first; }
	inline const TNick& GetNick(void) const { return _itSession->second.Account.Nick; }
	inline EOS GetOS(void) const { return _LoginInfo.Option.OS; }
	inline TResources& GetResources(void) { return _User.Resources; }
	inline const CCharacter* GetSelectedChar(void) const { return _pSelectedChar; }
	inline bool InBattle(void) const
	{
		return _pBattlePlayer != nullptr;
	}
	inline int32 GetSelectedCharCode(void) const { return _User.SelectedCharCode; }
	inline wstring GetCountryCode(void) const { return MBSToWCS(_LoginInfo.CountryCodeMinuteOffset.CountryCode); }
	template<typename _TProto>
	void Send(const _TProto& Proto_)
	{
		::Send(_LoginInfo.Key, Proto_);
	}
	inline bool WillClose(void) { return g_Net->WillClose(_LoginInfo.Key, milliseconds(5000)); }
	template<typename... _TProtos>
	void Push(const _TProtos&... Protos_) { DBPush(_itSession, _LoginInfo.Key, Protos_...); }
	TLevel GetLevel(void) const;
	void SendRet(ERet Ret_);
	void SendMsg(const wstring& Msg_);
	void RetAndClose(ERet Ret_);
	void Certify(void);
	void CertifyAndLobby(void);
	void Login(ELanguage Language_, const SUserLoginInfo& Info_);
	void LoginAfterBattle(const SUserLoginInfo& Info_);
	void Logout(void);
	inline bool IsDataLoaded(void) const { return _IsDataLoaded; }
	inline bool IsBusy(void) const { return !_User.NewNick.empty(); }
	inline int32 GetPoint(void) const { return _User.Point; }
	inline int32 GetSinglePointBest(void) const { return _User.SinglePointBest; }
	inline int32 GetIslandPointBest(void) const { return _User.IslandPointBest; }
	inline TExp GetExp(void) const { return _User.Exp; }
	void AddExp(TExp Exp_);
	void SetLoginDBOutCore(SLoginDBOut& Out_);
	void SetJoinDBOut(SLoginDBOut& Out_);
	void SetLoginDBOut(SLoginDBOut& Out_);
private:
	void _SendLogin(void);
public:
	ERet Buy(const SBuyNetCs& Proto_);
	ERet BuyChar(const SBuyCharNetCs& Proto_);
	ERet BuyPackage(const SBuyPackageNetCs& Proto_);
	ERet BuyResource(const SBuyResourceNetCs& Proto_);
	ERet Purchase(void);
	ERet ReceiptCheck(const TOrder& Order_, const string& OrderID_, int64 PurchaseTime_, int32 PurchaseType_);
	void ChangeNickBeginDB(void);
	void ChangeNickEndDB(void);
	void ChangeNickEndFailDB(EGameRet GameRet_);
	ERet DailyReward(const SDailyRewardNetCs& Proto_);
	void SetLevel(TLevel Level_);
	bool HaveCost(EResource CostType_, TResource Cost_);
	bool HaveCost(const TResources& Cost_);
	inline TResource GetResource(EResource Resource_) const { return _User.Resources[(size_t)Resource_]; }
	void AddResourceCore(SResourceTypeData resourceTypeData);
	void AddResourceCore(EResource ResourceType_, TResource Data_);
	void SubResourceCore(SResourceTypeData resourceTypeData);
	void SubResourceCore(EResource ResourceType_, TResource Data_);
	void AddResourcesCore(const TResources& Resources_);
	void SubResourcesCore(const TResources& Resources_);
	void AddResources(const TResources& Resources_);
	void SetResources(const TResources& Resources_);
	void SetPoint(int32 Point_);
	void SetChar(list<int32>& CharCodes_);
	void UnsetChar(list<int32>& CharCodes_);
	ERet Chat(const SChatNetCs& Proto_);
	ERet ChangeFSM(const SFCMTokenSetNetCs& Proto_);
	ERet CanPushAtNight(const SFCMCanPushAtNightNetCs& Proto_);
	ERet ChangeLanguage(const SChangeLanguageNetCs& Proto_);

	ERet SelectChar(const SSelectCharNetCs& Proto_);

	ERet BattleTouch(const SBattleTouchNetCs& Proto_);
	ERet BattlePush(const SBattlePushNetCs& Proto_);

	void BattleBegin(CBattlePlayer* pBattlePlayer_);
private:
	void _BattleEnd(void);
	void _BattleEndAndUpdateMatchBlockEndTime(TTime Now_);
public:
	ERet MultiBattleJoin(void);
	ERet MultiBattleOut(void);
	SBattleEndInfo GetSBattleEndInfo(void) const;
private:
	TDoneQuests _MultiBattleEnd(int32 BattlePoint_, const TQuests& DoneQuests_, TDoneQuestDBs& DoneQuestDBs_);
public:
	void MultiBattleEnd(TTime Now_, const vector<SBattleEndPlayer>& BattleEndPlayers_, const vector<STeamRanking>& OrderedTeamRankings_, const TQuests& DoneQuests_, TDoneQuestDBs& DoneQuestDBs_);
	void MultiBattleEndDraw(TTime Now_, int32 BattlePoint_, const TQuests& DoneQuests_, TDoneQuestDBs& DoneQuestDBs_);
	void MultiBattleEndInvalid(TTime Now_);
	void MultiBattleEndInvalidPunish(void);
	ERet MultiBattleIcon(const SMultiBattleIconNetCs& Proto_);

	ERet ArrowDodgeBattleJoin(void);
	ERet ArrowDodgeBattleEnd(const SArrowDodgeBattleEndNetCs& Proto_);
	void ArrowDodgeBattleEnd(int64 Tick_, const SArrowDodgeBattleInfo& BattleInfo_, const TQuests& DoneQuests_);

	ERet FlyAwayBattleJoin(void);
	ERet FlyAwayBattleEnd(const SFlyAwayBattleEndNetCs& Proto_);
	void FlyAwayBattleEnd(int64 Tick_, const SFlyAwayBattleInfo& BattleInfo_, const TQuests& DoneQuests_);

	ERet Gacha(const SGachaNetCs& Proto_);
	ERet GachaX10(const SGachaX10NetCs& Proto_);
	void GachaSucceeded(const TResources& Cost_, int32 GachaIndex_, int32 CharCode_);
	void GachaX10Succeeded(const TResources& Cost_, int32 GachaIndex_, list<int32> CharCodeList_, const TResources& Refund_);
	void GachaFailed(const TResources& Cost_, int32 GachaIndex_, int32 CharCode_, const TResources& Refund_);
	void _RewardCore(const SReward& Reward_, list<int32>& CharsAdded_);
	SRewardDB RewardCore(const SReward& Reward_);
	SRewardDB RewardsCore(const list<const SReward*>& Rewards_);
	ERet RankReward(const SRankRewardNetCs& Proto_);
private:
	optional<CQuest::TDone> _QuestDone(EQuestType QuestType_, int32 Count_);
public:
	void QuestDone(const TQuests& DoneQuests_, TDoneQuestDBs& DoneQuestDBs_, TDoneQuests& DoneQuestNets_);
	void QuestDone(CQuest::TQuestsIt itQuest_, int32 Count_);
	void QuestDone(TQuestSlotIndex SlotIndex_, int32 Count_);
	void QuestDone(EQuestType QuestType_, int32 Count_);
	ERet QuestReward(const SQuestRewardNetCs& Proto_);
	void QuestSet(TQuestSlotIndex SlotIndex_, int32 Code_);
	ERet QuestDailyCompleteReward(const SQuestDailyCompleteRewardNetCs& Proto_);
	ERet ChangeNickRequest(const SChangeNickNetCs& Proto_);
	void ChangeNickResult(EGameRet GameRet_);
	ERet CouponUse(const SCouponUseNetCs& Proto_);
	void CouponUseOut(const SCouponUseCouponDBIn& In_, int32 Code_);
	ERet TutorialReward(const STutorialRewardNetCs& Proto_);
	ERet RankingRewardInfo(const SRankingRewardInfoNetCs& Proto_);
	ERet RankingReward(const SRankingRewardNetCs& Proto_);
private:
	bool _IsInPunished(TTime Now_) const;
	bool _CanMatchable(TTime Now_) const;
private:
	void _FixMatchBLockEndTime(void);
	void _UpdateMatchBlockEndTime(TTime Now_);
public:
	void UpdateMatchBlockEndTime(TTime Now_);
	void ResetDisconnect(wstringstream& Params_);
};