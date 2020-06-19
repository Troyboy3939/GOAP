#pragma once
#include "GoapAction.h"
#include "Vector2.h"
class SmithingSite;
class Worldstate;
class Person;

class GotoBlacksmith : public GoapAction
{
public:
	GotoBlacksmith(SmithingSite* pBlacksmithShop ,WorldState* pSatisfies, std::vector<WorldState*> aRequired);

	bool IsValid(GoapAgent* pAgent);

	float GetCost(GoapAgent* pAgent);


	Vector2 GetSitePosition();

	SmithingSite* GetSite();
private:
	SmithingSite* m_pShop;
};

