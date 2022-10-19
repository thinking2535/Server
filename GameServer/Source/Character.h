#pragma once


struct SCharacterMeta : public CharacterMeta
{
	const CharacterTypeMeta* pCharacterTypeMeta;

	SCharacterMeta(const CharacterMeta& super, const CharacterTypeMeta* pCharacterTypeMeta);
};
class CCharacter : public SCharacterMeta
{
public:
	CCharacter(const SCharacterMeta& Super_) :
		SCharacterMeta(Super_)
	{
	}
	ResourceTypeData getCost(void) const;
	bool isNFTCharacter(void) const;
	bool isShopCharacter(void) const;
	bool isRewardCharacter(void) const;
	bool canBuy(void) const;
private:
	EResource _getCostType(void) const;
};