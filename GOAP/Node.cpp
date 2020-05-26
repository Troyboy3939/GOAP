#include "Node.h"

Node* Node::GetChild(int nIndex)
{
	return m_aChildren[nIndex];
}

std::vector<Node*>* Node::GetChildren()
{
	return &m_aChildren;
}

Node::Type Node::GetType()
{
	return m_eType;
}

void Node::AddChild(Node* pChild)
{
	m_aChildren.push_back((Node*)pChild);
}

Node* Node::GetParent()
{
	return m_pParent;
}
