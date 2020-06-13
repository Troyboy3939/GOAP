#pragma once
#include <WorldState.h>
class Working :
	public WorldState
{
public:
	Working(std::string strKey, bool bValue);

	bool IsSatisfied(GoapAgent* pAgent);
private:
};

