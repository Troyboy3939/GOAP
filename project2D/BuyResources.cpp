#include "BuyResources.h"
#include "Blacksmith.h"


BuyResources::BuyResources(WorldState* pSatisfies, std::vector<WorldState*> pRequires) : GoapAction(pSatisfies,pRequires)
{
}

bool BuyResources::IsValid(GoapAgent* pAgent)
{
	Blacksmith* pBlacksmith = (Blacksmith*)pAgent;


	
	if (pBlacksmith)
	{
		return !(pBlacksmith->HasResources());
	}

	return false;
}
