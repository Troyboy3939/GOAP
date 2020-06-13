#pragma once
#include <GoapAction.h>

class BuyResources :
	public GoapAction
{
public:
	BuyResources(WorldState* pSatisfies, std::vector<WorldState*> pRequires);


	bool IsValid(GoapAgent* pAgent);
private:
};

