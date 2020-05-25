#include "GoapAgent.h"

GoapAgent::GoapAgent(std::vector<GoapAction*> aAvailableActions)
{
	m_aAvailableActions = aAvailableActions;
	m_pPlanner = new GoapPlanner();
}

std::vector<GoapAction*> GoapAgent::GetAvailableActions()
{
	return m_aAvailableActions;
}

std::vector<GoapGoal*> GoapAgent::GetGoals()
{
	return m_aGoals;
}

void GoapAgent::SetCurrentActions(std::queue<GoapAction*> aActions)
{
	m_aCurrentActions = aActions;
}
