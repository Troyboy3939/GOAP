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
	m_bSetup = false;
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

void Tree::AddNode(GoapAction* pAction, Node* pParent)
{
	

	if (pParent)
	{
		ActionNode* pNode = new ActionNode(pAction, pParent);
		pParent->AddChild(pNode);
		m_nNumberOfNodes++;
		m_pLastAdded = pNode;
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
	m_bSetup = false;
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


bool Tree::GetSetup()
{
	return m_bSetup;
}

void Tree::SetSetup(bool bSetup)
{
	m_bSetup = bSetup;
}

Node* Tree::Find(GoapAction* pAction, Node* pStart)
{
	//Check whether pStart is the node you are looking for
	ActionNode* pActionNode = nullptr;
	GoalNode* pGoal = nullptr;
	switch(pStart->GetType())
	{
	case  Node::Type::ACTION: //If pStart is an Action node
		 pActionNode = (ActionNode*)pStart;
		break;
	case  Node::Type::GOAL://If it is a goal
		pGoal = (GoalNode*)pStart;
		break;
	}

	if (pActionNode)
	{
		std::vector<WorldState*> aReq = pActionNode->GetRequiredState();
		//For every required world state
		for (int i = 0; i < aReq.size(); i++)
		{
				//Check whether it meets the requirement
				if (aReq[i] == pAction->GetSatisfiesWorldState())
				{
					//if it is, return it
					return pStart;
				}
			
		}
	}
	else if (pGoal)
	{
		//check whether the desired state is met by the action
		if (pGoal->GetGoal()->GetDesiredWorldState() == pAction->GetSatisfiesWorldState())
		{
			//if it is, return it;
			return pStart;
		}
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


