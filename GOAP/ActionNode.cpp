#include "ActionNode.h"

ActionNode::ActionNode(GoapAction* pAction, Node* pParent)
{
	m_pAction = pAction;
	m_eType = Node::ACTION;
	m_pParent = pParent;
}

GoapAction* ActionNode::GetAction()
{
	return m_pAction;
}
