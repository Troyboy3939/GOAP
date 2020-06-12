#pragma once
#include "Node.h"
#include "WorldState.h"

class GoapGoal;


class GoalNode : 
	public Node
{
public:
	GoalNode(GoapGoal* pGoal);
	GoapGoal* GetGoal();
	WorldState* GetDesiredWorldState();
private:
	GoapGoal* m_pGoal;
};

