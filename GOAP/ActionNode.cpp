#include "ActionNode.h"
#include "WorldState.h"
#include "GoapAction.h"
#include "GoalNode.h"

ActionNode::ActionNode(GoapAction* pAction, Node* pParent)
{
	m_pAction = pAction;
	m_eType = Node::Type::ACTION;
	m_pParent = pParent;
}

GoapAction* ActionNode::GetAction()
{
	return m_pAction;
}

WorldState* ActionNode::GetSatisfiesWorldState()
{
	return m_pAction->GetSatisfiesWorldState();
}

std::vector<WorldState*> ActionNode::GetRequiredState()
{
	std::vector<WorldState*> aReturn = m_pAction->GetRequiredWorldState();

	if (m_pParent)
	{
		ActionNode* pAction = nullptr;

		switch (m_pParent->GetType())
		{
		case Node::Type::ACTION:
			pAction = (ActionNode*)m_pParent;
			break;
		case Node::Type::GOAL:
			return aReturn;
			break;

		}

		if (pAction)
		{
			std::vector<WorldState*> pParent = pAction->GetRequiredState();

			for (int i = 0; i < pParent.size(); i++)
			{
				if (pParent[i] == GetSatisfiesWorldState())
				{
					pParent.erase(pParent.begin() + i);
					i--;
					continue;
				}
				if (pParent[i])
				{

				}
			}

			
			std::move(pParent.begin(),pParent.end(),std::back_inserter(aReturn));
		}
		

	}


	
	return aReturn;
}

bool ActionNode::IsSatisfied(GoapAgent* pAgent)
{
	std::vector<WorldState*> aReq = m_pAction->GetRequiredWorldState();


	bool bSatisfied = true;
	for (int i = 0; i < aReq.size(); i++)
	{
		if (!aReq[i]->IsSatisfied(pAgent))
		{
			bSatisfied = false;
		}
	}

	return false;
}

float ActionNode::GetCost(GoapAgent* pAgent)
{
	return m_pAction->GetCost(pAgent);
}

bool ActionNode::operator==(Node* pRHS)
{
	return m_nID == pRHS->GetID();
}
