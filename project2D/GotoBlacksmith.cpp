#include "GotoBlacksmith.h"

GotoBlacksmith::GotoBlacksmith(SmithingSite* pBlacksmithShop, WorldState* pSatisfies, std::vector<WorldState*> aRequired) : GoapAction(pSatisfies,aRequired)
{
	m_pShop = pBlacksmithShop;
}

bool GotoBlacksmith::IsValid(GoapAgent* pAgent)
{

	//if both pBlacksmith and pTarget are not null, then it is a valid action
	return (m_pShop && pAgent);
}

float GotoBlacksmith::GetCost(GoapAgent* pAgent)
{
	return 0.0f;
}
