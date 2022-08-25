#include "stdafx.h"
#include <GameServer/Common/Base.h>

CMetaData::CMetaData() :
	forbiddenWords(GetForbiddenWords())
{
	try
	{
		CStream Stream;
	}
	catch (const SException& Exception_)
	{
		cout << Exception_.what() << endl;
		throw Exception_;
	}
	catch (...)
	{
		THROWEX();
	}
}
