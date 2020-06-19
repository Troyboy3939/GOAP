#pragma once
#include <GoapAction.h>
#include "Mine.h"
class BuyOre :
	public GoapAction
{
public:
	BuyOre(Mine* pMine, WorldState* pSatisfied, std::vector<WorldState*>aRequired);

	bool IsValid(GoapAgent* pAgent);

	float GetCost(GoapAgent* pAgent);


	Vector2 GetSitePosition();

	Mine* GetSite();
private:
	Mine* m_pMine;
};

