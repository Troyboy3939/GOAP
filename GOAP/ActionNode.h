#pragma once
#include "Node.h"
#include "WorldState.h"
class GoapAction;

class ActionNode :
	public Node
{
public:
	ActionNode(GoapAction* pAction, Node* pParent);

	GoapAction* GetAction();

	WorldState* GetSatisfiesWorldState();

	std::vector<WorldState*> GetRequiredState();

	bool IsSatisfied(GoapAgent* pAgent);
	
	float GetCost(GoapAgent* pAgent);
	bool operator==(Node* pRHS);

private:
	//The action that this node represents
	GoapAction* m_pAction;
	
};

