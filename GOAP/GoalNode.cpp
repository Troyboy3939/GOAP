#include "GoalNode.h"
#include "WorldState.h"
#include "GoapGoal.h"

GoalNode::GoalNode(GoapGoal* pGoal)
{
	m_pGoal = pGoal;
	m_eType = Node::Type::GOAL;
	m_pParent = nullptr;
}

GoapGoal* GoalNode::GetGoal()
{
	return m_pGoal;
}

WorldState* GoalNode::GetDesiredWorldState()
{
	return m_pGoal->GetDesiredWorldState();
}
