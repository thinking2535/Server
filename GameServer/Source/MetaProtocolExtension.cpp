#include "stdafx.h"

TResource getCostValue(const ExchangeValue& self, TResource targetData)
{
	return static_cast<TResource>(targetData * self.rate); // targetData �� �����̰� �ּ� 1 �̹Ƿ� Ceiling ���� ����
}
