#include "stdafx.h"

void CommandHelp(wstringstream& Params_, CUser& User_)
{
	SChatNetSc Proto;
	Proto.Msg = g_Command.GetManual();
	User_.Send(Proto);
}
void CommandSetUserLevel(wstringstream& Params_, CUser& User_)
{
	TLevel Level = 0; // Level 이 int8 (char) 일 수 있으므로 정수형으로 받음.
	Params_ >> Level;

	if (Level > 0)
		--Level; // 외부에서는 1 Base 로 간주

	User_.SetLevel(Level);
}
void CommandAddResources(wstringstream& Params_, CUser& User_)
{
	TResources ResourceAdded{};

	for (size_t i = 0; i < (size_t)EResource::Max; ++i)
	{
		if (!(Params_ >> ResourceAdded[i]))
			break;
	}

	User_.AddResources(ResourceAdded);
}
void CommandSetResources(wstringstream& Params_, CUser& User_)
{
	TResources Resources = User_.GetResources();

	for (size_t i = 0; i < (size_t)EResource::Max; ++i)
	{
		if (!(Params_ >> Resources[i]))
			break;
	}

	User_.SetResources(Resources);
}
void CommandSetMapIndex(wstringstream& Params_, CUser& User_)
{
	int32 MapIndex = -1;
	Params_ >> MapIndex;

	if (MapIndex >= -1 &&
		MapIndex < g_MetaData->GetMultiMapCount())
		g_MapIndex = MapIndex;
}
void CommandSetPoint(wstringstream& Params_, CUser& User_)
{
	int32 Point = 0;
	Params_ >> Point;

	if (Point < 0)
		Point = 0;

	User_.SetPoint(Point);
}
void CommandSetChar(wstringstream& Params_, CUser& User_)
{
	list<int32> CharCodes;
	int32 CharCode = 0;

	while (Params_ >> CharCode)
		CharCodes.emplace_back(CharCode);

	User_.SetChar(CharCodes);
}
void CommandUnsetChar(wstringstream& Params_, CUser& User_)
{
	list<int32> CharCodes;
	int32 CharCode = 0;

	while (Params_ >> CharCode)
		CharCodes.emplace_back(CharCode);

	User_.UnsetChar(CharCodes);
}
void CommandQuestComplete(wstringstream& Params_, CUser& User_)
{
	int32 SlotIndex = 0;
	int32 Count = 0;

	Params_ >> SlotIndex;
	Params_ >> Count;

	User_.QuestDone((TQuestSlotIndex)SlotIndex, Count);
}
void CommandQuestSet(wstringstream& Params_, CUser& User_)
{
	int32 SlotIndex = 0;
	int32 Code = 0;

	Params_ >> SlotIndex;
	Params_ >> Code;

	User_.QuestSet((TQuestSlotIndex)SlotIndex, Code);
}
