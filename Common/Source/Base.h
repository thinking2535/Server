#pragma once

#include <Rso/Core/Core.h>
#pragma comment( lib, "GameServer/Common_" RSO_STATIC RSO_RT_LIBRARY RSO_DEBUG_TYPE )

#include "ServerToServerProtocol.h"
#include <Rso/Game/Base.h>

using namespace bb;

SRankingConfigMeta GetSRankingConfigMeta(void);
