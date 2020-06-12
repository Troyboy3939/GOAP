#include "Node.h"

int Node::m_nNumberOfNodes = 0;

Node::Node()
{
	m_nID = m_nNumberOfNodes;
	m_nNumberOfNodes++;
}

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

int Node::GetFScore()
{
	return m_nFScore;
}

int Node::GetHScore()
{
	return m_nHScore;
}

int Node::GetGScore()
{
	return m_nGScore;
}

void Node::SetFScore(int nFScore)
{
	m_nFScore = nFScore;
}

void Node::SetHScore(int nHScore)
{
	m_nHScore = nHScore;
}

void Node::SetGScore(int nGScore)
{
	m_nGScore = nGScore;
}

bool Node::operator==(Node* pRHS)
{
	return (m_nID == pRHS->m_nID);
}

int Node::GetID()
{
	return m_nID;
}
