#include "GoapAction.h"

GoapAction::GoapAction(std::string strName, WorldState* pSatisfies, std::vector<WorldState*> aRequired)
{
	m_aRequiredWorldState = aRequired;
	m_pSatisfiesWorldState = pSatisfies;
	m_strName = strName;
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

std::string GoapAction::GetName()
{
	return m_strName;
}

void GoapAction::SetName(std::string strName)
{
	m_strName = strName;
}
