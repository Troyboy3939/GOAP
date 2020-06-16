#pragma once
#include <WorldState.h>
class HasLogs :
	public WorldState
{
public:
	HasLogs(std::string strKey, bool bValue);


	bool IsSatisfied(GoapAgent* pAgent);
private:
};

