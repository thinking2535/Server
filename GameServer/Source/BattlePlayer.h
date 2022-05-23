#pragma once

#include "BalloonHitControl.h"

class CBattlePlayer : public SBattlePlayer
{
	int32 _PlayerIndex = 0;
	const SCharacterMeta* _pMeta;
	const SCharacter* _pCharacter = nullptr;
	CUser* _Player = nullptr;
	CBalloonHitControl _BalloonHitControl;
	TQuests _DoneQuests; // 전투중 완료한 퀘스트

public:
	CBattlePlayer(const SBattlePlayer Super_, const SCharacterMeta* pMeta_, const SCharacter* pCharacter_, int32 PlayerIndex_, CUser* Player_);
	template<typename _TProto>
	void Send(const _TProto& Proto_) { _Player->Send(Proto_); }
	bool WillClose(void) { return _Player->WillClose(); }
	inline int32 GetPlayerIndex(void) const { return _PlayerIndex; }
	inline const SCharacterMeta* GetMeta(void) const { return _pMeta; }
	inline int32 GetPoint(void) const { return _Player->GetPoint(); }
	inline const SCharacter* GetCharacter(void) const { return _pCharacter; }
	inline bool IsBot(void) const { return _Player->IsBot(); }
	inline const u16string& GetNick(void) const { return _Player->GetNick(); }
	bool IsAlive(void) const;
	void BattleBegin(const SBattleInfo& Info_);
	CUser* GetUser() { return _Player; }
private:
	void _QuestDone(EQuestType QuestType_, int32 Count_);
public:
	SBattleEndInfo BattleEnd(const CEngineGameMode* pGameMode_, const SBattleEndPlayer& BattleEndPlayer_, const STeamEndInfo& TeamEndInfo_, bool BestPlayer_, TDoneQuestDBs& DoneQuestDBs_, TDoneQuests& DoneQuestNets_);
	void Kill(int32 AddedPoint_);
	void AttackBalloon(int32 AddedPoint_);
	void PumpDone(void);
	void SendSBattleEndNetSc(const list<SBattleEndPlayer>& BattleEndPlayers_, const TTeamBattleInfos& TeamBattleInfos_, const TDoneQuests& DoneQuests_);
};
