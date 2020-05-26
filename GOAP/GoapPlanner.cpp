#include "GoapPlanner.h"
#include "GoapAgent.h"
#include "GoapGoal.h"
GoapPlanner::GoapPlanner(GoapAgent* pAgent)
{
	m_pAgent = pAgent;
	m_pCurrentGoal = nullptr;
	m_pTree = nullptr;
	CheckGoals();
}

void GoapPlanner::Update()
{

	//Check whether a higher priority goal has been added, or if the current goal is invalid
	CheckGoals();


	
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
				return;
			}

			//If it is a different goal
			if (m_pCurrentGoal != aGoals[i])
			{
				//and is a valid goal
				if (aGoals[i]->IsValid(m_pAgent))
				{

					//and either the current goal is invalid, or has a higher priority
					if (!m_pCurrentGoal->IsValid(m_pAgent) || m_pCurrentGoal->GetPriority() < aGoals[i]->GetPriority())
					{
						m_pTree->AddNewGoal(aGoals[i]);
						return;
					}
					
				}
			}
		}
	}
}
