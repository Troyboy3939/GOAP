#pragma once

#include <vector>


class Node
{
public:
	enum Type
	{
		GOAL,
		ACTION
	};
	Node* GetChild(int nIndex);
	std::vector<Node*>* GetChildren();
	Type GetType();
	void AddChild(Node* pChild);

	Node* GetParent();
protected:
	
	std::vector<Node*> m_aChildren;
	Node* m_pParent;
	Type m_eType;

};

