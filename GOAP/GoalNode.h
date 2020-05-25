#pragma once
#include "Node.h"
class GoapGoal;


class GoalNode : 
	public Node
{
public:
	GoalNode(GoapGoal* pGoal);
	GoapGoal* GetGoal();
private:
	GoapGoal* m_pGoal;
};

