#include "HasOre.h"
#include "Blacksmith.h"
HasOre::HasOre(std::string strKey, bool bValue) : WorldState(strKey,bValue)
{
}

bool HasOre::IsSatisfied(GoapAgent* pAgent)
{
	Blacksmith* pBlacksmith = (Blacksmith*)pAgent;


	return pBlacksmith->OreCount() > 0;
}
