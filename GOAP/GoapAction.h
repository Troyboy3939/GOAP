#pragma once

#include "WorldState.h"
#include <Vector>

class GoapAction
{
public:
	GoapAction(WorldState* pSatisfies, std::vector<WorldState*> aRequired);

	//This function is what is called to check if this action is a valid action, check whether it is possible to do
	//For example, to kill player, the agent needs to be able to see the player
	virtual bool IsValid(GoapAgent* pAgent) = 0;

	virtual float GetCost(GoapAgent* pAgent) = 0;
	void SetCost(float fCost);

	WorldState* GetSatisfiesWorldState();
	std::vector<WorldState*> GetRequiredWorldState();
protected:
	//What is the cost of this action?
	float m_fCost;

	//What world state/s are added to the agent when this action has been taken
	WorldState* m_pSatisfiesWorldState;

	//what world state/s will mean that this action can be undertaken
	std::vector<WorldState*> m_aRequiredWorldState;
};


