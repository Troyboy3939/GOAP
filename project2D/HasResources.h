#pragma once
#include <WorldState.h>
class HasResources :
	public WorldState
{
public:
	HasResources(std::string strKey, bool bValue);

	bool IsSatisfied(GoapAgent* pAgent);
private:
};

