#pragma once
#include "GoapAction.h"

class MakeTool : public GoapAction
{
public:
	MakeTool(WorldState* pSatisfies, std::vector<WorldState*>aRequired);


	bool IsValid(GoapAgent* pAgent);
	float GetCost(GoapAgent* pAgent);
private:
};

