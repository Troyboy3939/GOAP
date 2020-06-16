#pragma once
#include "GoapAction.h"

class SmithingSite;
class Worldstate;
class Person;
class GotoBlacksmith : public GoapAction
{
public:
	GotoBlacksmith(SmithingSite* pBlacksmithShop ,WorldState* pSatisfies, std::vector<WorldState*> aRequired);

	bool IsValid(GoapAgent* pAgent);

	float GetCost(GoapAgent* pAgent);
private:
	SmithingSite* m_pShop;
};

