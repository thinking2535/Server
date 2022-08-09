#include "stdafx.h"

TResources CGacha::_GetRefund(const CCharacter* pCharGot_) const
{
	return GetResources(pCharGot_->RefundType, pCharGot_->RefundValue);
}
CGacha::CGacha(const SGachaMeta& Super_, int32 GachaIndex_, const TProbabilityGrades& ProbabilityGrades_) :
	SGachaMeta(Super_),
	_GachaIndex(GachaIndex_),
	_ProbabilityGrades(ProbabilityGrades_),
	_Cost(CheckAndGetResources(SResourceTypeData(Super_.CostResource, Super_.CostValue))),
	_TenCost(CheckAndGetResources(SResourceTypeData(Super_.TenCostResource, Super_.TenCostValue)))
{
	for (auto& g : ProbabilityGrades_)
	{
		TMachine Machine;

		for (auto& i : g.second.second)
			Machine.Insert(i.first, i.second);

		_Machines.Insert(g.second.first, Machine);
	}
}
bool CGacha::DoesAllHave(const TChars& CharsHave_) const
{
	for (auto& m : _Machines)
	{
		for (auto& c : m.second)
		{
			if (CharsHave_.find(c.second->Code) == CharsHave_.end())
				return false;
		}
	}

	return true;
}
ERet CGacha::Get(CUser* User_, const TChars& CharsHave_)
{
	if (!User_->HaveCost(_Cost))
		return ERet::NotEnoughMoney;

	auto& Machine = _Machines.Get();
	auto& GachaChar = Machine.Get();

	if (CharsHave_.find(GachaChar->Code) == CharsHave_.end())
		User_->GachaSucceeded(
			_Cost,
			_GachaIndex,
			GachaChar->Code);
	else
		User_->GachaFailed(
			_Cost,
			_GachaIndex,
			GachaChar->Code,
			_GetRefund(GachaChar));

	return ERet::Ok;
}
ERet CGacha::GetX10(CUser* User_, const TChars& CharsHave_)
{
	if (!User_->HaveCost(_TenCost))
		return ERet::NotEnoughMoney;

	list<int32> CharList;
	map<int32, int32> MyChars;
	for (auto& i : CharsHave_)
		MyChars.emplace(i, 0);

	TResources Resources = TResources();

	for (int i = 0; i < 10; ++i)
	{
		auto& Machine = _Machines.Get();
		auto& GachaChar = Machine.Get();
		CharList.emplace_back(GachaChar->Code);
		if (MyChars.find(GachaChar->Code) != MyChars.end())
			Resources += _GetRefund(GachaChar);
		else
			MyChars.emplace(GachaChar->Code, 0);
	}
	User_->GachaX10Succeeded(_TenCost, _GachaIndex, CharList, Resources);
	return ERet::Ok;
}