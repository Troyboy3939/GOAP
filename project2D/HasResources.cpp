#include "HasResources.h"
#include "Blacksmith.h"

HasResources::HasResources(std::string strKey, bool bValue) : WorldState(strKey,bValue)
{
}

bool HasResources::IsSatisfied(GoapAgent* pAgent)
{
	Blacksmith* pBlacksmith = (Blacksmith*)pAgent;


	if (pBlacksmith)
	{
		return pBlacksmith->HasResources();
	}
	return false;
}
