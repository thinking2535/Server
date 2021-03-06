#include "stdafx.h"

// 최대한 보유한 EQuestType 이 나오지 않도록 (단, EQuestType::Max가 보유할 수 있는 퀘스트 개수보다 많을 경우는 허용)
const SQuest& CQuest::_New(void)
{
	auto NewQuestIndex = rand() % ((size_t)EQuestType::Max - _Quests.size());

	set<EQuestType> QuestTypes;
	for (auto& i : _Quests)
		QuestTypes.emplace(i.second.pQuest->QuestType);

	// 생성된 NewQuestIndex 가 기존에 가진 QuestType 이라 할지라도 _Quests.size() 만큼 여유분을 두었으므로 NewQuestIndex 를 하나씩 증가시켜서 기존에 가진 값을 회피
	// 단, EQuestType::Max >= _Quests.size() 임을 보장할것.
	for (auto& i : QuestTypes)
	{
		if ((int32)i > NewQuestIndex)
			break;

		++NewQuestIndex;
	}

	auto& Quests = g_MetaData->GetQuest((EQuestType)NewQuestIndex);
	return Quests[rand() % Quests.size()];
}
bool CQuest::_IsValid(const SQuestBase& Quest_) const
{
	return (Quest_.CoolEndTime == TTime());
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
	if (!_IsValid(itQuest_->second))
		return {};

	if (itQuest_->second.Count >= itQuest_->second.pQuest->RequirmentCount) // Is Completed
		return {};

	if (!itQuest_->second.pQuest->Check(Count_))
		return {};

	if (itQuest_->second.Count + Count_ > itQuest_->second.pQuest->RequirmentCount)
		itQuest_->second.Count = itQuest_->second.pQuest->RequirmentCount;
	else
		itQuest_->second.Count += Count_;

	return TDone(itQuest_->first, itQuest_->second.Count);
}
// return {}; // 잘못되었거나 변동이 없음
optional<CQuest::TDone> CQuest::Done(EQuestType QuestType_, int32 Count_)
{
	auto itQuest = Get(QuestType_);
	if (itQuest == _Quests.end())
		return {};

	return Done(itQuest, Count_);
}
void CQuest::Refresh(TQuestSlotIndexCodes& NewQuests_) // 로긴시에 c_QuestCnt_Max 보다 적게 퀘스트가 있는경우 추가하기 위함
{
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
		NewQuests_.emplace_back(SQuestSlotIndexCode(SlotIndex, NewQuest.Code));

		++SlotIndex;

		if (it == _Quests.end())
			it = _Quests.begin();
	}
}
optional<CQuest::_TReward> CQuest::Reward(TQuestSlotIndex SlotIndex_) // return : New Quest Type
{
	auto itQuest = _Quests.find(SlotIndex_);
	if (itQuest == _Quests.end())
		return {};

	if (itQuest->second.Count < itQuest->second.pQuest->RequirmentCount)
		return {};

	if (_Quests.size() > c_QuestCnt_Max)
	{
		_Quests.erase(itQuest);
		return _TReward{};
	}
	else
	{
		return _TReward(itQuest->second.CoolEndTime = system_clock::now() + minutes(g_MetaData->ConfigMeta.QuestCoolMinutes), itQuest->second.pQuest->pReward);
	}
}
optional<const SQuest*> CQuest::Next(const SQuestNextNetCs& Proto_)
{
	auto itQuest = _Quests.find(Proto_.SlotIndex);
	if (itQuest == _Quests.end())
		return {};

	if (_Quests.size() <= c_QuestCnt_Max)
	{
		auto Now = system_clock::now();

		if (_IsValid(itQuest->second))
		{
			if (itQuest->second.Count >= itQuest->second.pQuest->RequirmentCount) // 완료했거나 자원을 안쓰겠다고 했으면
				return {};
		}

		auto* pNewQuest = &_New();
		itQuest->second = _SQuest(SQuestBase(pNewQuest->Code, 0, TTime()), pNewQuest);
		return pNewQuest;
	}
	else
	{
		_Quests.erase(itQuest);
		return nullptr;
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

	// 바꾸려는 퀘스트 타입이 다른슬롯에 존재하면 처리 안함
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
