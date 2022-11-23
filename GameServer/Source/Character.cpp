#include "stdafx.h"

SCharacterMeta::SCharacterMeta(const CharacterMeta& super, const CharacterTypeMeta* pCharacterTypeMeta) :
	CharacterMeta(super),
	pCharacterTypeMeta(pCharacterTypeMeta)
{
}
ResourceTypeData CCharacter::getCost(void) const
{
	auto costType = _getCostType();
	if (costType == EResource::Null)
		return ResourceTypeData();

	return ResourceTypeData(costType, pCharacterTypeMeta->CostValue);
}
bool CCharacter::isNFTCharacter(void) const
{
	return pCharacterTypeMeta->howToGet == L"NFT";
}
bool CCharacter::isShopCharacter(void) const
{
	return _getCostType() != EResource::Null;
}
bool CCharacter::isRewardCharacter(void) const
{
	return pCharacterTypeMeta->howToGet == L"Reward";
}
bool CCharacter::canBuy(void) const
{
	return isShopCharacter() || isNFTCharacter();
}
EResource CCharacter::_getCostType(void) const
{
	if (pCharacterTypeMeta->howToGet == L"Ticket")
		return EResource::Ticket;
	else if (pCharacterTypeMeta->howToGet == L"Gold")
		return EResource::Gold;
	else if (pCharacterTypeMeta->howToGet == L"Dia00")
		return EResource::Dia00;
	else if (pCharacterTypeMeta->howToGet == L"Dia01")
		return EResource::Dia01;
	else if (pCharacterTypeMeta->howToGet == L"Dia02")
		return EResource::Dia02;
	else if (pCharacterTypeMeta->howToGet == L"Dia03")
		return EResource::Dia03;
	else
		return EResource::Null;
}
