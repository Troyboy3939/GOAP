#include "GoapPlanner.h"
#include "GoapAgent.h"
#include "GoapGoal.h"
#include "Heap.h"
#include <iostream>




GoapPlanner::GoapPlanner(GoapAgent* pAgent)
{
	m_pAgent = pAgent;
	m_pCurrentGoal = nullptr;
	m_pTree = nullptr;
	m_bHasPlan = false;
	CheckGoals();
}

GoapPlanner::~GoapPlanner()
{
	if (m_pTree)
	{
		delete m_pTree;
	}


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
			//and is a valid goal
			if (aGoals[i]->IsValid(m_pAgent))
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
							m_pCurrentGoal = aGoals[i];
							m_bHasPlan = false;
							return;
						}

					}

				}
			}
		}
	}



}

bool GoapPlanner::GetPlan()
{
	//A* algorithm!



	
		//This will clears the tree, so that the previous plan does not mesh with the algorithm
	m_pTree->AddNewGoal(m_pCurrentGoal);


	//Get the actions available to the agent
	m_aAvailableActions = m_pAgent->GetAvailableActions();



	Node* pTarget = m_pTree->GetGoalNode();


	Heap openList;
	std::vector<Node*> aClosedList;


	GoalNode* pGoal = ((GoalNode*)pTarget);

	//Set the G score, the cost of going to this node (nothing since it is the goal node)
	pGoal->SetGScore(0);

	//calculate the heuristic, or guess
	pGoal->SetHScore(1);

	//Set the total score of the node
	pGoal->SetFScore(pGoal->GetGScore() + pGoal->GetHScore());

	//Add goal to closed list
	aClosedList.push_back(pTarget);

	for (int i = 0; i < m_aAvailableActions.size(); i++)
	{
		if (m_aAvailableActions[i]->IsValid(m_pAgent))
		{
			
				if (m_aAvailableActions[i]->GetSatisfiesWorldState() == pGoal->GetDesiredWorldState())
				{



					//Add the node to the tree
					m_pTree->AddNode(m_aAvailableActions[i], pTarget);

					ActionNode* pAdded = (ActionNode*)m_pTree->GetLastAdded();

					//Set the G score, the cost of going to this node (nothing since it is the goal node)
					pAdded->SetGScore(pAdded->GetCost(m_pAgent));

					//calculate the heuristic, or guess
					pAdded->SetHScore((float)((ActionNode*)(m_pTree->GetLastAdded()))->GetRequiredState().size());

					//Set the total score of the node
					pAdded->SetFScore(pAdded->GetGScore() + pAdded->GetHScore());

					pTarget = pAdded;

					//Add the node to the open list
					openList.Add(pAdded);
				}
		}
	}


		bool bFoundPath = false; 
	
		if (openList.Size() == 0)
		{
			if (pTarget != pGoal)
			{
				bFoundPath = true;
			}
			else
			{
				std::cout << "cannot find valid path" << std::endl;
				return false;
			}
			
		}
		


	//While you haven't found the path
	while (!bFoundPath && pTarget)
	{

		pTarget = openList.GetTop();

		if (!pTarget)
		{
			return false;
		}

		
	
		//CHANGE THIS CODE IF IT DOES NOT WORK  if pTarget is in the closed list
		if (std::find(aClosedList.begin(),aClosedList.end(),pTarget) != aClosedList.end())
		{
			continue;
		}

		ActionNode* pActionNode = (ActionNode*)pTarget;
	
		if (pActionNode)
		{

			//Gets the remaining requirements of node and its parents, removes requirements fulfilled by actions
			std::vector<WorldState*> aReq = pActionNode->GetRequiredState();
			for (int i = 0; i < aReq.size(); i++)
			{
				//If it the world state is satisfied, then 
				if (aReq[i]->IsSatisfied(m_pAgent))
				{
					//erase it from the requirements, as no need to do it
					aReq.erase(aReq.begin() + i);
					i--;

					if (aReq.size() == 0)
					{
						break;
					}
				}
			}
		

			for (int i = 0; i < aReq.size(); i++)
			{
				


				for (int j = 0; j < m_aAvailableActions.size(); j++)
				{
					if (m_aAvailableActions[j]->IsValid(m_pAgent))
					{
						
						
							if (aReq[i] == m_aAvailableActions[j]->GetSatisfiesWorldState())
							{
								m_pTree->AddNode(m_aAvailableActions[j], pTarget);

								ActionNode* pAdded = (ActionNode*)m_pTree->GetLastAdded();

								//Set the G score, the cost of going to this node (nothing since it is the goal node)
								pAdded->SetGScore(pAdded->GetCost(m_pAgent));

								//calculate the heuristic, or guess
								pAdded->SetHScore((float)((ActionNode*)(m_pTree->GetLastAdded()))->GetRequiredState().size());

								//Set the total score of the node
								pAdded->SetFScore(pAdded->GetGScore() + pAdded->GetHScore());

								openList.Add(m_pTree->GetLastAdded());
							}
					}
				}
			}
			

			//if the size is zero, that means there are no more remaining requirements and the path has been found
			if (aReq.size() == 0)
			{
				//Found Path
				bFoundPath = true;
				break;
			}

		}

		

	}


	Node* pPathTarget = pTarget;

	std::vector<GoapAction*> aActions;
	//Set Current actions
	if (bFoundPath)
	{
		//While the target is not the goal node, and while the target is not nullptr
		while ((pPathTarget != pGoal) && pPathTarget)
		{
			//and it to the array
			aActions.push_back(((ActionNode*)pPathTarget)->GetAction());

			//Set the new target to the targets parent
			pPathTarget = pPathTarget->GetParent();
		}

		m_pAgent->SetCurrentActions(aActions);
		return true;

	} 


	//add pTarget to closed list
	aClosedList.push_back(pTarget);
	
	

	return false;
}

