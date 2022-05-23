#pragma once

class CSingleBattlePlayer : public SBattlePlayer
{
	int32 _PlayerIndex = 0;
	const SCharacterMeta* _pMeta;
	CUser* _Player = nullptr;
	TQuests _DoneQuests; // 전투중 완료한 퀘스트
	bool _IsAlive = true;
	EGameMode _GameMode = EGameMode::Null;

public:
	CSingleBattlePlayer(const SBattlePlayer Super_, const SCharacterMeta* pMeta_, int32 PlayerIndex_, CUser* Player_);
	template<typename _TProto>
	void Send(const _TProto& Proto_) { _Player->Send(Proto_); }
	bool WillClose(void) { return _Player->WillClose(); }
	inline int32 GetPlayerIndex(void) const { return _PlayerIndex; }
	inline const SCharacterMeta* GetMeta(void) const { return _pMeta; }
	inline int32 GetPoint(void) const { return _Player->GetPoint(); }
	inline bool IsBot(void) const { return _Player->IsBot(); }
	inline const u16string& GetNick(void) const { return _Player->GetNick(); }
	bool IsAlive(void) const;
	void BattleBegin(const SBattleInfo& Info_, EGameMode GameMode_);
	CUser* GetUser() { return _Player; }
private:
	void _QuestDone(EQuestType QuestType_, int32 Count_);
public:
	SBattleEndInfo BattleEnd(const CEngineGameMode* pGameMode_, const SBattleEndPlayer& BattleEndPlayer_, const STeamEndInfo& TeamEndInfo_, bool BestPlayer_, TDoneQuestDBs& DoneQuestDBs_, TDoneQuests& DoneQuestNets_);
	void SendSSingleBattleEndNetSc(const list<SBattleEndPlayer>& BattleEndPlayers_, const TTeamBattleInfos& TeamBattleInfos_, const TDoneQuests& DoneQuests_);
	void SetPoint(int32 Point_) { Point = Point_; }
};
