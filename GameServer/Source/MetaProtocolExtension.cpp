#include "stdafx.h"

TResource getCostValue(const ExchangeValue& self, TResource targetData)
{
	return static_cast<TResource>(targetData * self.rate); // targetData 가 정수이고 최소 1 이므로 Ceiling 하지 않음
}
