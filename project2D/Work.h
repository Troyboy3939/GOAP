#pragma once
#include "GoapGoal.h"
class Work :
	public GoapGoal
{
public:
	Work(float fPriority, WorldState* pDesiredWorldState);


	bool IsValid(GoapAgent* pAgent);
private:
};

