#include "ActionNode.h"

ActionNode::ActionNode(GoapAction* pAction)
{
	m_pAction = pAction;
	m_eType = Node::ACTION;
}

GoapAction* ActionNode::GetAction()
{
	return m_pAction;
}
