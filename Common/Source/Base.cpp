#pragma once

#include "Base.h"

SRankingConfigMeta GetSRankingConfigMeta(void)
{
	CStream Stream;

	Stream.LoadFile(L"../../MetaData/RankingConfig.bin");
	list<SRankingConfigMeta> RankingConfigMetas;
	Stream >> RankingConfigMetas;

	if (RankingConfigMetas.empty())
		THROWEX();

	return RankingConfigMetas.front();
}
TForbiddenWords GetForbiddenWords(void)
{
	CStream Stream;

	Stream.LoadFile(L"../../MetaData/ForbiddenWord.bin");
	TForbiddenWords forbiddenWords;
	Stream >> forbiddenWords;
	for (auto& i : forbiddenWords)
		wcslwr((wchar_t*)i.c_str());

	return forbiddenWords;
}
wstring GetForbiddenWord(const TForbiddenWords& forbiddenWords, const wstring& word)
{
	for (auto& i : forbiddenWords)
	{
		if (word.find(i) != string::npos)
			return i;
	}

	return wstring();
}
wstring GetForbiddenWord(const TForbiddenWords& forbiddenWords, const u16string& u16Word)
{
	auto word = u16string_to_wstring(u16Word);
	wcslwr((wchar_t*)word.c_str());

	return GetForbiddenWord(forbiddenWords, word);
}
