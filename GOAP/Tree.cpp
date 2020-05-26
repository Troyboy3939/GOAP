#include "Tree.h"
#include "ActionNode.h"
#include "GoalNode.h"
#include "GoapGoal.h"
#include "GoapAction.h"
#include <iostream>


Tree::Tree(GoapGoal* pGoal)
{
	m_pRootNode = new GoalNode(pGoal);
}

Tree::~Tree()
{
	for (int i = m_aDeleted.size() - 1; i > 0; i--)
	{
		delete m_aDeleted[i];
		m_aDeleted[i] = nullptr;
	}

	m_aDeleted.clear();
}

void Tree::AddNode(GoapAction* pAction)
{
	Node* pTarget = Find(pAction,m_pRootNode);

	if (pTarget)
	{
		pTarget->AddChild(new ActionNode(pAction,pTarget));
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
}



GoalNode* Tree::GetGoalNode()
{
	return m_pRootNode;
}

Node* Tree::Find(GoapAction* pAction, Node* pStart)
{
	//Check whether pStart is the node you are looking for
	ActionNode* pActionNode;
	GoalNode* pGoal;
	switch(pStart->GetType())
	{
	case Node::ACTION: //If pStart is an Action node
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
	case Node::GOAL://If it is a goal
		 pGoal = (GoalNode*)pStart;
		//check whether the desired state is met by the action
		if (pGoal->GetGoal()->GetDesiredWorldState() == pAction->GetSatisfiesWorldState())
		{ 
			//if it is, return it;
			return pGoal;
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


