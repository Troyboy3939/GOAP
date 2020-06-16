#pragma once
#include <WorldState.h>
class HasOre :
	public WorldState
{
public:
	HasOre(std::string strKey, bool bValue);


	bool IsSatisfied(GoapAgent* pAgent);
private:

};

