#include "Tree.h"
#include "ActionNode.h"
#include "GoalNode.h"
#include "GoapGoal.h"
#include "GoapAction.h"



void Tree::AddNode(GoapAction* pAction)
{
	bool bDone = false;

	Node* pTarget  = m_pRootNode;
	//Do not forget to do a comparison operator overload
	//If the action meets the goals desired world state
	if (m_pRootNode->GetGoal()->GetDesiredWorldState() == pAction->GetSatisfiesWorldState())
	{
		//Add the child to that node
		m_pRootNode->AddChild(new ActionNode(pAction));
	}
	else //Else if it isn't, while loop to find the correct parent node
	{
		
	}
	
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
	for (int i = 0; i < pStart->GetChildren().size(); i++)
	{

		Node* pTarget = Find(pAction,pStart->GetChild(i));

		if (pTarget)
		{
			return pTarget;
		}
	}

	
	return nullptr;
}




/*

	//If you are not done
	while (!bDone)
	{
		std::vector<Node*> aTargetChildren = pTarget->GetChildren();
		//For every child the target has
		for (int i = 0; i < aTargetChildren.size(); i++)
		{
			ActionNode* pChild = (ActionNode*)aTargetChildren[i];
			for (int j = 0; j < pChild->GetAction()->GetRequiredWorldState().size(); j++)
			{
				//if the world state that the new node satisfies, satisfies the world state required
				if (pChild->GetAction()->GetRequiredWorldState()[j] == pAction->GetSatisfiesWorldState())
				{
					//Then it is the appropiate parent
					pChild->AddChild(new ActionNode(pAction));
					bDone = true;
					break;
				}
			}

			if (bDone)
			{
				break;
			}

		}
	}


*/