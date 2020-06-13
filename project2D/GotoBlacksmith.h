#pragma once
#include "GoapAction.h"

class Shop;
class Worldstate;
class Person;
class GotoBlacksmith : public GoapAction
{
public:
	GotoBlacksmith(Shop* pBlacksmithShop ,WorldState* pSatisfies, std::vector<WorldState*> aRequired);

	bool IsValid(GoapAgent* pAgent);
private:
	Shop* m_pShop;
};

