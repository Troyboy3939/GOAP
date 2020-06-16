#include "Node.h"

int Node::m_nNumberOfNodes = 0;

Node::Node()
{
	m_nID = m_nNumberOfNodes;
	m_nNumberOfNodes++;
	m_pParent = nullptr;
	m_nHScore = 0;
	m_nFScore = 0;
	m_nGScore = 0;
	m_eType = Type::NONE;
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

float Node::GetFScore()
{
	return m_nFScore;
}

float Node::GetHScore()
{
	return m_nHScore;
}

float Node::GetGScore()
{
	return m_nGScore;
}

void Node::SetFScore(float nFScore)
{
	m_nFScore = nFScore;
}

void Node::SetHScore(float nHScore)
{
	m_nHScore = nHScore;
}

void Node::SetGScore(float nGScore)
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
