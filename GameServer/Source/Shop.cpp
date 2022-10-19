#include "stdafx.h"

ShopCharacter::ShopCharacter(const CCharacter* pCharacter) :
	_pCharacter(pCharacter)
{
}
ERet ShopCharacter::buy(CUser* pUser) const
{
	return pUser->buyCharacter(_pCharacter);
}
