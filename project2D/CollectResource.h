#pragma once
#include <GoapAction.h>

class CollectResource :
	public GoapAction
{
public:
	CollectResource(WorldState* pSatisifies, std::vector<WorldState*> aRequires);


	bool IsValid(GoapAgent* pAgent);
private:
};

