#pragma once

#include <Rso/Core/Core.h>
#pragma comment( lib, "GameServer/Common_" RSO_STATIC RSO_RT_LIBRARY RSO_DEBUG_TYPE )

#include "NetProtocol.h"
#include "ServerToServerProtocol.h"
#include <Rso/Game/Base.h>

using namespace bb;

SRankingConfigMeta GetSRankingConfigMeta(void);
TForbiddenWords GetForbiddenWords(void);
wstring GetForbiddenWord(const TForbiddenWords& forbiddenWords, const wstring& word);
wstring GetForbiddenWord(const TForbiddenWords& forbiddenWords, const u16string& u16Word);

