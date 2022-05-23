#pragma once

class CGacha : public SGachaMeta
{
	using TMachine = CRandomBox<double, const CCharacter*>;
	using TMachines = CRandomBox<double, TMachine>;

	int32 _GachaIndex = 0;
	TProbabilityGrades _ProbabilityGrades;
	TMachines _Machines;
	TResources _Cost{};
	TResources _TenCost{};

	TResources _GetRefund(const CCharacter* pCharGot_) const;

public:
	CGacha(const SGachaMeta& Super_, int32 GachaIndex_, const TProbabilityGrades& ProbabilityGrades_);
	bool DoesAllHave(const TChars& CharsHave_) const;
	ERet Get(CUser* User_, const TChars& CharsHave_);
	ERet GetX10(CUser* User_, const TChars& CharsHave_);
};