#pragma once

// 최대수량이 넘을 경우 Reward 시에 쿨타임이 적용되지 않도록 하여 한개씩 감소되도록 처리
class CQuest
{
public:
	using TDone = pair<TQuestSlotIndex, int32>; // SlotIndex, Count
private:
	using _TReward = pair<TTime, const SReward*>;
	struct _SQuest : public SQuestBase
	{
		const SQuest* pQuest = nullptr;

		_SQuest(const SQuestBase& Super_, const SQuest* pQuest_) :
			SQuestBase(Super_), pQuest(pQuest_)
		{
		}
	};
	using _TQuests = map<TQuestSlotIndex, _SQuest>;
public:
	using TQuestsIt = typename _TQuests::iterator;
private:
	_TQuests _Quests;

	const SQuest& _New(void);
	bool _IsValid(const SQuestBase& Quest_) const;

public:
	bool Add(const TQuestDBs::value_type& itQuest_);
	TQuestsIt Get(EQuestType QuestType_);
	TQuestsIt Get(TQuestSlotIndex SlotIndex_);
	TQuestsIt End(void);
	TQuestDBs GetQuestDBs(void) const;
	optional<TDone> Done(TQuestsIt itQuest_, int32 Count_);
	optional<TDone> Done(EQuestType QuestType_, int32 Count_);
	void Refresh(TQuestSlotIndexCodes& NewQuests_);
	optional<_TReward> Reward(TQuestSlotIndex SlotIndex_);
	optional<const SQuest*> Next(const SQuestNextNetCs& Proto_);
	optional<const SQuest*> Set(TQuestSlotIndex SlotIndex_, int32 NewCode_);
};