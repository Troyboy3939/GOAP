#include "GoapAgent.h"
#include <iostream>


GoapAgent::GoapAgent()
{
	m_pPlanner = new GoapPlanner(this);
}

GoapAgent::~GoapAgent()
{
	delete m_pPlanner;
}

std::vector<GoapAction*> GoapAgent::GetAvailableActions()
{
	return m_aAvailableActions;
}

std::vector<GoapGoal*> GoapAgent::GetGoals()
{
	return m_aGoals;
}

void GoapAgent::SetGoals(std::vector<GoapGoal*> aGoals)
{
	m_aGoals = aGoals;
}

void GoapAgent::SetCurrentActions(std::vector<GoapAction*> aActions)
{
	m_aCurrentActions = aActions;
}

void GoapAgent::SetAvailableActions(std::vector<GoapAction*> aActions)
{
	m_aAvailableActions = aActions;
}

void GoapAgent::Update()
{
	m_pPlanner->Update();

}
