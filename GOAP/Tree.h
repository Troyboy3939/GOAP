#pragma once
#include <vector>
#include "GoalNode.h"
#include "ActionNode.h"
class GoapAction;
class GoapGoal;

class Tree
{
public:
	Tree(GoapGoal* pGoal);
	~Tree();

	//pAction is the action being added to the tree
	void AddNode(GoapAction* pAction);

	//Remove a node from the tree, also removes all children
	void RemoveNode(GoapAction* pAction);

	//Clears the tree and creates a new goal
	void AddNewGoal(GoapGoal* pGoal);


	GoalNode* GetGoalNode();
private:
	//pAction is the action being added to the tree
	Node* Find(GoapAction* pAction, Node* pStart);
	void DeleteBranch(Node* pTarget);
	GoalNode* m_pRootNode;
	std::vector<Node*> m_aDeleted;
};

