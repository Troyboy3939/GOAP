#pragma once
#include "GoapAction.h"
class BuyTool :
	public GoapAction
{
public:
	BuyTool(WorldState* pSatisfies, std::vector<WorldState*> aRequired);

	bool IsValid(GoapAgent* pAgent);
private:
};

