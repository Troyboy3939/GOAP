#include "BuyOre.h"
#include "Blacksmith.h"
BuyOre::BuyOre(Mine* pMine, WorldState* pSatisfied, std::vector<WorldState*> aRequired) : GoapAction("BuyOre",pSatisfied,aRequired)
{
	m_pMine = pMine;
	m_fCost = m_pMine->GetOreCost();
}

bool BuyOre::IsValid(GoapAgent* pAgent)
{
	Blacksmith* pBlacksmith = (Blacksmith*)pAgent;

	if (pBlacksmith)
	{
		return pBlacksmith->OreCount() < 1;
	}


	return false;
}

float BuyOre::GetCost(GoapAgent* pAgent)
{
	

	

	return m_fCost;
}

Vector2 BuyOre::GetSitePosition()
{
	return m_pMine->GetPosition();
}

Mine* BuyOre::GetSite()
{
	return m_pMine;
}
