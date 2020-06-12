#include "Tree.h"
#include "ActionNode.h"
#include "GoalNode.h"
#include "GoapGoal.h"
#include "GoapAction.h"
#include <iostream>
#include "Heap.h"
#include "GoapPlanner.h"
#include "Node.h"

Tree::Tree(GoapGoal* pGoal)
{
	m_nNumberOfNodes = 1;
	m_pRootNode = new GoalNode(pGoal);
	m_pLastAdded = m_pRootNode;
}

Tree::~Tree()
{
	for (int i = 0; i < m_aDeleted.size(); i++)
	{
		delete m_aDeleted.front();
		m_aDeleted.front() = nullptr;
		m_aDeleted.pop_front();
	}
		
	m_aDeleted.clear();
}

void Tree::AddNode(GoapAction* pAction)
{
	Node* pTarget = Find(pAction,m_pRootNode);

	if (pTarget)
	{
		ActionNode* pNode = new ActionNode(pAction, pTarget);
		pTarget->AddChild(pNode);
		m_nNumberOfNodes++;
		m_pLastAdded = pNode;
	}
	else
	{
		std::cout << "Action cannot be added to tree" << std::endl;
	}
	
}

void Tree::RemoveNode(GoapAction* pAction)
{
	Node* pTarget = Find(pAction,(Node*)m_pRootNode);

	DeleteBranch(pTarget);
}

void Tree::AddNewGoal(GoapGoal* pGoal)
{
	DeleteBranch(m_pRootNode);

	m_pRootNode = new GoalNode(pGoal);
	m_nNumberOfNodes++;
	m_pLastAdded = m_pRootNode;
}



GoalNode* Tree::GetGoalNode()
{
	return m_pRootNode;
}

Node* Tree::GetLastAdded()
{
	return m_pLastAdded;
}

int Tree::GetNumberOfNodes()
{
	return m_nNumberOfNodes;
}

bool Tree::GetPlan(std::queue<GoapAction*>& aActionList, GoapPlanner* pPlanner)
{
	ActionNode* pEndNode = nullptr;
	//Open list. List of nodes currently being considered
	Heap aOpenList;

	//Makes sure nodes haven't been checked twice
	std::vector<Node*> aClosedList;

	//Check if the goal is valid
	if (!m_pRootNode->GetGoal()->IsValid(pPlanner->GetAgent()))
	{
		//If it is not a valid goal, then there will be no valid path
		return false;
	}

	
	//Set the G score, the cost of going to this node (nothing since it is the goal node)
	m_pRootNode->SetGScore(0);

	//calculate the heuristic, or guess
	m_pRootNode->SetHScore(CalculateHeuristic(m_pRootNode, pPlanner));

	//Set the total score of the node
	m_pRootNode->SetFScore(m_pRootNode->GetGScore() + m_pRootNode->GetHScore());
	
	//Empty the list of current actions so that the AI does not do anything it isn't supposed to
	bool bTheCreationOfThisVariableIsToGetRidOfAWarningOtherWiseIWouldntHaveIt = aActionList.empty();
	
	//The root node is now being considered
	aOpenList.Add(m_pRootNode);

	//If the open list isn't empty, then the quickest path hasn't been found
	while (aOpenList.Size() > 0)
	{
		//Get the top node (removes and returns it)
		Node* pCurrent = aOpenList.GetTop();

		//and add it to the closed list, therefore, next iteration of the while loop pCurrent is the new top node
		aClosedList.push_back(pCurrent);

		//Create pointers for converting pCurrent to appropiate class
		GoalNode* pCurrentGoal = nullptr;
		ActionNode* pCurrentAction = nullptr;

		//convert it
		switch (pCurrent->GetType())
		{
		case  Node::Type::ACTION:
			pCurrentAction = (ActionNode*)pCurrent;
			break;
		case  Node::Type::GOAL:
			pCurrentGoal = (GoalNode*)pCurrent;
			break;
		}

		//If it is not nullptr, then it exists
		if (pCurrentAction)
		{
			//if the current action satisfies the goal node, then path found
			if (pCurrentAction->GetSatisfiesWorldState() == m_pRootNode->GetDesiredWorldState())
			{
				//Get the set the end node to the current action
				pEndNode = pCurrentAction;

				//break out of loop
				break;
			}

			std::vector<Node*> aChildren = *pCurrentAction->GetChildren();

			//For all of your children
			for (int i = 0; i < aChildren.size(); i++)
			{
				//if they are not on the open list
				if (!aOpenList.Find(aChildren[i]))
				{
					//set the f score
					aChildren[i]->SetGScore(((ActionNode*)aChildren[i])->GetCost());
					aChildren[i]->SetHScore(CalculateHeuristic(aChildren[i], pPlanner));
					aChildren[i]->SetFScore(aChildren[i]->GetGScore() + aChildren[i]->GetHScore());

					//then add it to the open list
					aOpenList.Add(aChildren[i]);
				}
				
			}
		}
		else if (pCurrentGoal)
		{
			std::vector<Node*> aChildren = *pCurrentGoal->GetChildren();
			//For all of your children
			for (int i = 0; i < aChildren.size(); i++)
			{
				//if they are not on the open list
				if (!aOpenList.Find(aChildren[i]))
				{
					//set the f score
					aChildren[i]->SetGScore(((ActionNode*)aChildren[i])->GetCost());
					aChildren[i]->SetHScore(CalculateHeuristic(aChildren[i],pPlanner));
					aChildren[i]->SetFScore(aChildren[i]->GetGScore() + aChildren[i]->GetHScore());

					//then add it to the open list
					aOpenList.Add(aChildren[i]);
				}

			}
		}
		
	}
	
	//If pEndNode exists, than the path is found
	if (pEndNode)
	{
		Node* pTarget = pEndNode;
		std::vector<Node*> aPath;
		//Get the path in a vector
		while (!(pTarget == m_pRootNode))
		{
			aPath.push_back(pTarget);
			pTarget = pTarget->GetParent();
		}

		//once the path has been added to a vector, create the queue from it
		for (int i = (int)(aPath.size() - 1); i >= 0; i--)
		{
			aActionList.push((GoapAction*)aPath[i]);
		}

		return true;
	}

	return false;
}

Node* Tree::Find(GoapAction* pAction, Node* pStart)
{
	//Check whether pStart is the node you are looking for
	ActionNode* pActionNode;
	GoalNode* pGoal;
	switch(pStart->GetType())
	{
	case  Node::Type::ACTION: //If pStart is an Action node
		 pActionNode = (ActionNode*)pStart;
		//For every required world state
		for (int i = 0; i < pActionNode->GetAction()->GetRequiredWorldState().size(); i++)
		{

			//Check whether it meets the requirement
			if (pActionNode->GetAction()->GetRequiredWorldState()[i] == pActionNode->GetAction()->GetSatisfiesWorldState())
			{
				//if it is, return it
				return pStart;
			}
		}
		break;
	case  Node::Type::GOAL://If it is a goal
		 pGoal = (GoalNode*)pStart;
		//check whether the desired state is met by the action
		if (pGoal->GetGoal()->GetDesiredWorldState() == pAction->GetSatisfiesWorldState())
		{ 
			//if it is, return it;
			return pStart;
		}
		break;
	}
	
	//If pStart is not the node you are looking for

	//For every child
	for (int i = 0; i < pStart->GetChildren()->size(); i++)
	{

		Node* pTarget = Find(pAction,pStart->GetChild(i));

		if (pTarget)
		{
			return pTarget;
		}
	}

	
	return nullptr;
}

void Tree::DeleteBranch(Node* pTarget)
{
	//Delete Yourself
	m_aDeleted.push_back(pTarget);

	m_nNumberOfNodes--;

	//For every child you have
	for (int i = 0; i < pTarget->GetChildren()->size();i++)
	{
		//If they are not null
		if (pTarget->GetChild(i))
		{
			//Delete them
			DeleteBranch(pTarget->GetChild(i));
		}
		
	}

	pTarget->GetChildren()->clear();
}

int Tree::CalculateHeuristic(Node* pNode, GoapPlanner* pPlanner)
{
	GoapGoal* pGoal = nullptr;
	GoapAction* pAction = nullptr;
	int nHeuristic = 0;
	switch (pNode->GetType())
	{
	case Node::Type::ACTION:
		pAction = ((ActionNode*)pNode)->GetAction();
		break;

	case Node::Type::GOAL:
		pGoal = ((GoalNode*)pNode)->GetGoal();
		break;
	}
	if (pAction)
	{
		std::vector<WorldState*> aWorldState = pAction->GetRequiredWorldState();

		for (int i = 0; i < aWorldState.size(); i++)
		{
			//if the world state is not satisfied
			if (!aWorldState[i]->IsSatisfied(pPlanner->GetAgent()))
			{
				nHeuristic++;
			}
		}
	}
	else if (pGoal)
	{
		if (!pGoal->GetDesiredWorldState()->IsSatisfied(pPlanner->GetAgent()))
		{
			return 1;
		}
	}


	return nHeuristic;
}


