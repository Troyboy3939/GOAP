#pragma once

#include "WorldState.h"
#include <Vector>

class GoapAgent;

class GoapGoal
{
public:
	GoapGoal(float fPriority, WorldState* pDesiredWorldState);

	float GetPriority();
	void SetPriority(float fPriority);

	WorldState* GetDesiredWorldState();

	//This function is what is called to check if this goal is a valid goal, check whether it is possible to do
	//For example, to kill player, the agent needs to be able to see the player
	virtual bool IsValid(GoapAgent* pAgent) = 0;
private:
	//How Important the goal is, higher is more important
	float m_fPriority;

	//What world state/s will mean that this goal has been completed, what it needs to be doing for it to be completed
	//For example to kill the player it needs to have been attacking the player
	WorldState* m_pDesiredWorldState;
};

