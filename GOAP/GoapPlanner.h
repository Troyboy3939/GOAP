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
private:
	GoapAgent* m_pAgent;
	Tree* m_pTree;
};

