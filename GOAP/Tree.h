#pragma once
#include <vector>
#include "GoalNode.h"
#include "ActionNode.h"
class GoapAction;
class GoapGoal;

class Tree
{
public:
	//pAction is the action being added to the tree
	void AddNode(GoapAction* pAction);

private:
	//pAction is the action being added to the tree
	Node* Find(GoapAction* pAction, Node* pStart);

	GoalNode* m_pRootNode;
};

