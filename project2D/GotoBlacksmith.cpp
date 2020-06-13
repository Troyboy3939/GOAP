#include "GotoBlacksmith.h"

GotoBlacksmith::GotoBlacksmith(Shop* pBlacksmithShop, WorldState* pSatisfies, std::vector<WorldState*> aRequired) : GoapAction(pSatisfies,aRequired)
{
	m_pShop = pBlacksmithShop;
}

bool GotoBlacksmith::IsValid(GoapAgent* pAgent)
{

	//if both pBlacksmith and pTarget are not null, then it is a valid action
	return (m_pShop && pAgent);
}
