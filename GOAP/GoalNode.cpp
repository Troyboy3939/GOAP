#include "GoalNode.h"

GoalNode::GoalNode(GoapGoal* pGoal)
{
	m_pGoal = pGoal;
	m_eType = Node::GOAL;
}

GoapGoal* GoalNode::GetGoal()
{
	return m_pGoal;
}
