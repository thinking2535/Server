#pragma once

class CPlayer
{
public:
	virtual bool IsBot(void) const { return false; }
	virtual TSessionsIt GetSession(void) const { return TSessionsIt(); }
	virtual TSessionsIt GetSession(void) { return TSessionsIt(); }
	virtual TUID GetUID(void) const { return 0; }
	virtual CKey GetKey(void) const { return CKey(); }
	virtual void BattleBegin(const SBattleInfo& BattleInfo_) {}
	virtual void SingleBattleBegin(const SBattleInfo& BattleInfo_) {}
	virtual SBattleEndInfo BattleEnd(const CEngineGameMode* pGameMode_, const SBattleEndPlayer& BattleEndPlayer_, bool Win_) { return SBattleEndInfo(); }
};
