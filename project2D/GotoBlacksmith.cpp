#include "GotoBlacksmith.h"

GotoBlacksmith::GotoBlacksmith(Blacksmith* pBlacksmith, WorldState* pSatisfies, std::vector<WorldState*> aRequired) : GoapAction(pSatisfies,aRequired)
{
	m_pBlacksmith = pBlacksmith;
}

bool GotoBlacksmith::IsValid(GoapAgent* pAgent)
{

	//if both pBlacksmith and pTarget are not null, then it is a valid action
	return (m_pBlacksmith && pAgent);
}
