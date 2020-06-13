#pragma once
#include <WorldState.h>
class GotTool :
	public WorldState
{
public:
	GotTool(std::string strKey, bool bValue);


	bool IsSatisfied(GoapAgent* pAgent);
private:
};

