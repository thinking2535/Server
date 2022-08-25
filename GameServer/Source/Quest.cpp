#include "stdafx.h"

bool CQuest::_SQuest::isCompleted()
{
	return Count >= pQuest->completeCount;
}
bool CQuest::_SQuest::done(int32 count)
{
	if (CoolEndTime > system_clock::now())
		return false;

	if (isCompleted())
		return false;

	if (count < pQuest->unitCompleteCount)
		return false;

	++Count;

	return true;
}

// �ִ��� ������ EQuestType �� ������ �ʵ��� (��, EQuestType::Max�� ������ �� �ִ� ����Ʈ �������� ���� ���� ���)
const SQuest& CQuest::_New(void)
{
	auto NewQuestIndex = rand() % ((size_t)EQuestType::Max - _Quests.size());

	set<EQuestType> QuestTypes;
	for (auto& i : _Quests)
		QuestTypes.emplace(i.second.pQuest->QuestType);

	// ������ NewQuestIndex �� ������ ���� QuestType �̶� ������ _Quests.size() ��ŭ �������� �ξ����Ƿ� NewQuestIndex �� �ϳ��� �������Ѽ� ������ ���� ���� ȸ��
	// ��, EQuestType::Max >= _Quests.size() ���� �����Ұ�.
	for (auto& i : QuestTypes)
	{
		if ((int32)i > NewQuestIndex)
			break;

		++NewQuestIndex;
	}

	auto& Quests = g_MetaData->GetQuest((EQuestType)NewQuestIndex);
	return Quests[rand() % Quests.size()];
}
bool CQuest::Add(const TQuestDBs::value_type& itQuest_)
{
	auto* pQuest = g_MetaData->GetQuest(itQuest_.second.Code);
	if (pQuest == nullptr)
		return false;

	_Quests.emplace(itQuest_.first, _SQuest(itQuest_.second, pQuest));

	return true;
}
CQuest::TQuestsIt CQuest::Get(EQuestType QuestType_)
{
	for (auto it = _Quests.begin(); it != _Quests.end(); ++it)
	{
		if (it->second.pQuest->QuestType == QuestType_)
			return it;
	}

	return _Quests.end();
}
CQuest::TQuestsIt CQuest::Get(TQuestSlotIndex SlotIndex_)
{
	return _Quests.find(SlotIndex_);
}
CQuest::TQuestsIt CQuest::End(void)
{
	return _Quests.end();
}
TQuestDBs CQuest::GetQuestDBs(void) const
{
	TQuestDBs Quests;

	for (auto it = _Quests.begin(); it != _Quests.end(); ++it)
		Quests.emplace(it->first, it->second);

	return Quests;
}
optional<CQuest::TDone> CQuest::Done(TQuestsIt itQuest_, int32 Count_)
{
	if (!itQuest_->second.done(Count_))
		return {};

	return TDone(itQuest_->first, itQuest_->second.Count);
}
// return {}; // �߸��Ǿ��ų� ������ ����
optional<CQuest::TDone> CQuest::Done(EQuestType QuestType_, int32 Count_)
{
	auto itQuest = Get(QuestType_);
	if (itQuest == _Quests.end())
		return {};

	return Done(itQuest, Count_);
}
TQuestSlotIndexCodes CQuest::FillEmptySlotAndGetNewQuests(void) // �α�ÿ� c_QuestCnt_Max ���� ���� ����Ʈ�� �ִ°�� �߰��ϱ� ����
{
	TQuestSlotIndexCodes NewQuests;

	TQuestSlotIndex SlotIndex = 0;
	auto it = _Quests.begin();

	while (_Quests.size() < c_QuestCnt_Max)
	{
		while (it != _Quests.end() && it->first <= SlotIndex)
		{
			SlotIndex = it->first + 1;
			++it;
		}

		auto& NewQuest = _New();
		_Quests.emplace(SlotIndex, _SQuest(SQuestBase(NewQuest.Code, 0, TTime()), &NewQuest));
		NewQuests.emplace_back(SQuestSlotIndexCode(SlotIndex, NewQuest.Code));

		++SlotIndex;

		if (it == _Quests.end())
			it = _Quests.begin();
	}

	return NewQuests;
}
optional<CQuest::_TReward> CQuest::Reward(TQuestSlotIndex SlotIndex_) // return : New Quest Type
{
	auto itQuest = _Quests.find(SlotIndex_);
	if (itQuest == _Quests.end())
		return {};

	if (!itQuest->second.isCompleted())
		return {};

	auto reward = itQuest->second.pQuest->pReward;
	if (_Quests.size() > c_QuestCnt_Max)
	{
		_Quests.erase(itQuest);
		return _TReward(nullptr, reward);
	}
	else
	{
		auto* pNewQuest = &_New();
		itQuest->second = _SQuest(SQuestBase(pNewQuest->Code, 0, system_clock::now() + minutes(g_MetaData->ConfigMeta.QuestCoolMinutes)), pNewQuest);
		return _TReward(&itQuest->second, reward);
	}
}
optional<const SQuest*> CQuest::Set(TQuestSlotIndex SlotIndex_, int32 NewCode_)
{
	auto itQuest = _Quests.find(SlotIndex_);
	if (itQuest == _Quests.end())
		return {};

	auto pNewQuest = g_MetaData->GetQuest(NewCode_);
	if (!pNewQuest)
		return {};

	// �ٲٷ��� ����Ʈ Ÿ���� �ٸ����Կ� �����ϸ� ó�� ����
	for (auto& i : _Quests)
	{
		if (i.first == SlotIndex_)
			continue;

		if (i.second.pQuest->QuestType == pNewQuest->QuestType)
			return {};
	}

	itQuest->second = _SQuest(SQuestBase(pNewQuest->Code, 0, TTime()), pNewQuest);
	return pNewQuest;
}
