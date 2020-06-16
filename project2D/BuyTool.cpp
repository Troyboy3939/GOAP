#include "BuyTool.h"
#include "Miner.h"
#include "Woodcutter.h"

BuyTool::BuyTool(float fPriority, WorldState* pDesiredWorldState) : GoapGoal(fPriority,pDesiredWorldState)
{
}

bool BuyTool::IsValid(GoapAgent* pAgent)
{
	Miner* pMiner = nullptr;
	Woodcutter* pWoodcutter = nullptr;


	switch (((Person*)pAgent)->GetType())
	{
	case Person::TYPE::MINER:
		pMiner = (Miner*)pAgent;
		break;
	case  Person::TYPE::WOODCUTTER:
		pWoodcutter = (Woodcutter*)pAgent;
		break;
	}

	if (pMiner)
	{
		return !(pMiner->HasTool());
	}
	else if (pWoodcutter)
	{
		return !(pWoodcutter->HasTool());
	}


	return false;
}
