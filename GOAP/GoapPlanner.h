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
private:

	void CheckGoals();
	GoapAgent* m_pAgent;
	GoapGoal* m_pCurrentGoal;
	Tree* m_pTree;
};

