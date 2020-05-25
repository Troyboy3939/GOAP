#include "GoapAction.h"

GoapAction::GoapAction(WorldState* pSatisfies, std::vector<WorldState*> aRequired)
{
	m_aRequiredWorldState = aRequired;
	m_pSatisfiesWorldState = pSatisfies;
}

float GoapAction::GetCost()
{
	return m_fCost;
}

void GoapAction::SetCost(float fCost)
{
	m_fCost = fCost;
}

WorldState* GoapAction::GetSatisfiesWorldState()
{
	return m_pSatisfiesWorldState;
}

std::vector<WorldState*> GoapAction::GetRequiredWorldState()
{
	return m_aRequiredWorldState;
}
