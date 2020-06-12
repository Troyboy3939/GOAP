#pragma once
#include "GoapPlanner.h"
#include "GoapAction.h"
#include "GoapGoal.h"

#include <Queue>

class GoapAgent
{
public:
	GoapAgent();

	std::vector<GoapAction*> GetAvailableActions();
	std::vector<GoapGoal*> GetGoals();

	void SetGoals(std::vector<GoapGoal*> aGoals);

	void SetCurrentActions(std::queue<GoapAction*> aActions);

	void SetAvailableActions(std::vector<GoapAction*> aActions);

	void Update();

private:
	//Actions the agent should be doing
	std::queue<GoapAction*> m_aCurrentActions;

	//Actions that the agent can do
	std::vector<GoapAction*> m_aAvailableActions;

	//Goals the agent should be doing
	std::vector<GoapGoal*> m_aGoals;

	GoapPlanner* m_pPlanner;
};

