#pragma once
#include <vector>
#include <list>
#include "GoalNode.h"
#include "ActionNode.h"
#include <queue>

class GoapPlanner;
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

	//Name says it all
	GoalNode* GetGoalNode();

	Node* GetLastAdded();

	int GetNumberOfNodes();


	bool GetPlan(std::queue<GoapAction*>& aActionList, GoapPlanner* pPlanner);
private:
	//pAction is the action being added to the tree
	Node* Find(GoapAction* pAction, Node* pStart);

	//Removes all children nodes
	void DeleteBranch(Node* pTarget);
	GoalNode* m_pRootNode;

	static int CalculateHeuristic(Node* pNode, GoapPlanner* pPlanner);

	//Never uses random access, only insert and delete, hence linked list is perfect for a list of deleted nodes
	std::list<Node*> m_aDeleted;

	Node* m_pLastAdded;
	int m_nNumberOfNodes;
};

