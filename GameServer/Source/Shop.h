#pragma once

class ShopItem abstract
{
public:
	virtual ERet buy(CUser* pUser) const = 0;
};

class ShopCharacter : public ShopItem
{
	const CCharacter* _pCharacter;

public:
	ShopCharacter(const CCharacter* pCharacter);

	ERet buy(CUser* pUser) const override;
};