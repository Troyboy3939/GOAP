#include "GoapPlanner.h"
#include "GoapAgent.h"
#include "GoapGoal.h"
GoapPlanner::GoapPlanner(GoapAgent* pAgent)
{
	m_pAgent = pAgent;
	m_pCurrentGoal = nullptr;
	m_pTree = nullptr;
	m_bHasPlan = false;
	CheckGoals();
}

void GoapPlanner::Update()
{

	//Check whether a higher priority goal has been added, or if the current goal is invalid
	CheckGoals();

	//If you do not have a plan
	if (!m_bHasPlan)
	{
		m_bHasPlan = GetPlan();
	}

	
}

GoapAgent* GoapPlanner::GetAgent()
{
	return m_pAgent;
}

void GoapPlanner::CheckGoals()
{
	std::vector<GoapGoal*> aGoals = m_pAgent->GetGoals();


	//For every goal
	for (int i = 0; i < aGoals.size(); i++)
	{

		//If it exists
		if (aGoals[i])
		{

			//If tree does not exist, create one with the current goal
			if (!m_pTree)
			{
				m_pTree = new Tree(aGoals[i]);
				m_pCurrentGoal = aGoals[i];
				m_bHasPlan = false;
				continue;
			}

			//If it is a different goal
			if (m_pCurrentGoal != aGoals[i])
			{
				//and is a valid goal
				if (aGoals[i]->IsValid(m_pAgent))
				{

					//and either the current goal is invalid, or the new goal has a higher priority
					if (!m_pCurrentGoal->IsValid(m_pAgent) || m_pCurrentGoal->GetPriority() < aGoals[i]->GetPriority())
					{
						m_pTree->AddNewGoal(aGoals[i]);
						m_bHasPlan = false;
						return;
					}
					
				}
			}
		}
	}



}

bool GoapPlanner::GetPlan()
{
	//If you dont have a plan, and the number of nodes is greater than 1, meaning there are action nodes attached
	if (!m_bHasPlan && m_pTree->GetNumberOfNodes() > 1)
	{
		//This will clear the tree, with the only node being on tree the goal node
		m_pTree->AddNewGoal(m_pCurrentGoal);
	}

	//Get the actions available to the agent
	m_aAvailableActions = m_pAgent->GetAvailableActions();


	Node* pTarget = m_pTree->GetGoalNode();



	//Potentially revamp how GetActions works!
	//Since adding node to tree automatically finds the spot based on whether is satisfies a requirement
	//and if the node added doesn't satisfy anything it doesn't get added
	//Therefore you could potentially try and add everything to it
	//and maybe it could work
	//only problem will be the order in which actions are added

	//Setup tree
	GetActions(pTarget);

	std::queue<GoapAction*> aActions;



	if (m_pTree->GetPlan(aActions,this))
	{
		m_pAgent->SetCurrentActions(aActions);
		m_bHasPlan = true;
		return true;
	}

	m_pAgent->SetCurrentActions(aActions);
	m_bHasPlan = false;
		
	return false;
}

void GoapPlanner::GetActions(Node* pNode)
{
	GoapGoal* pGoal = nullptr;
	GoapAction* pAction = nullptr;

	switch (pNode->GetType())
	{
	case  Node::Type::ACTION:
		pAction = ((ActionNode*)pNode)->GetAction();
		break;
	case  Node::Type::GOAL:
		pGoal = ((GoalNode*)pNode)->GetGoal();
		break;
	}

	//If pGoal is not null, then pNode was the goal node, so use that
	if (pGoal)
	{
		
		for (int i = 0; i < m_aAvailableActions.size(); i++)
		{
			if (m_aAvailableActions[i]->GetSatisfiesWorldState() == pGoal->GetDesiredWorldState())
			{
			
					m_pTree->AddNode(m_aAvailableActions[i]);
					GetActions(m_pTree->GetLastAdded());
	
			}
		}
	}
	else if(pAction) //if action is not null, then use that
	{
		std::vector<WorldState*> aRequiredWorldState = pAction->GetRequiredWorldState();

		//If there is nothing required, then no need to do any of this
		if (aRequiredWorldState.size() > 0)
		{
			//If is it greater than zero, then this is necessary
			//For every required world state
			for (int i = 0; i < aRequiredWorldState.size(); i++)
			{
				//Check if every action will satisfy it
				for (int j = 0; j < m_aAvailableActions.size(); j++)
				{
					if (aRequiredWorldState[i] == m_aAvailableActions[j]->GetSatisfiesWorldState())
					{
						//if it does add it to the tree
						m_pTree->AddNode(m_aAvailableActions[j]);

						//then check the added node
						GetActions(m_pTree->GetLastAdded());

					
					}
				}
			}
		}
		return;
	}
}
