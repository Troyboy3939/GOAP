#include "ActionNode.h"
#include "WorldState.h"
#include "GoapAction.h"


ActionNode::ActionNode(GoapAction* pAction, Node* pParent)
{
	m_pAction = pAction;
	m_eType = Node::Type::ACTION;
	m_pParent = pParent;
}

GoapAction* ActionNode::GetAction()
{
	return m_pAction;
}

WorldState* ActionNode::GetSatisfiesWorldState()
{
	return m_pAction->GetSatisfiesWorldState();
}

std::vector<WorldState*> ActionNode::GetRequiredState()
{
	return m_pAction->GetRequiredWorldState();
}

int ActionNode::GetCost()
{
	return m_pAction->GetCost();
}

bool ActionNode::operator==(Node* pRHS)
{
	return m_nID == pRHS->GetID();
}
