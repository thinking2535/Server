#pragma once

class CBot : public CPlayer
{
public:
	bool IsBot(void) const override { return true; }
};
