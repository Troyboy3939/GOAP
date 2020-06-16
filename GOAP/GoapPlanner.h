#pragma once
#include "Tree.h"

//forward declarations, prevents circular include scenarios
class GoapAgent;
class GoapGoal;
class GoapAction;

class GoapPlanner
{
public:
	GoapPlanner(GoapAgent* pAgent);
	void Update();

	GoapAgent* GetAgent();
private:

	void CheckGoals();
	GoapAgent* m_pAgent;
	GoapGoal* m_pCurrentGoal;
	std::vector<GoapAction*> m_aAvailableActions;
	Tree* m_pTree;
	bool m_bHasPlan;

	bool GetPlan();
};

