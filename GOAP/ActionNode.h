#pragma once
#include "Node.h"

class GoapAction;

class ActionNode :
	public Node
{
public:
	ActionNode(GoapAction* pAction, Node* pParent);
	GoapAction* GetAction();
private:
	//The action that this node represents
	GoapAction* m_pAction;
};

