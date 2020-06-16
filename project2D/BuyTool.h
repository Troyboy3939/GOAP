#pragma once
#include <GoapGoal.h>
class BuyTool :
	public GoapGoal
{
public:
	BuyTool(float fPriority, WorldState* pDesiredWorldState);

	bool IsValid(GoapAgent* pAgent);
private:


};

