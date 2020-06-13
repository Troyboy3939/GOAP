#include "BuyTool.h"
#include "Woodcutter.h"
#include "Miner.h"

BuyTool::BuyTool(WorldState* pSatisfies, std::vector<WorldState*> aRequired) : GoapAction(pSatisfies, aRequired)
{
}

bool BuyTool::IsValid(GoapAgent* pAgent)
{
	//Create pointers
	Miner* pMiner = nullptr;
	Woodcutter* pWoodcutter = nullptr;

	//Convert person based on the type
	switch (((Person*)pAgent)->GetType())
	{
	case Person::TYPE::MINER:
		pMiner = (Miner*)pAgent;
		break;

	case Person::TYPE::WOODCUTTER:
		pWoodcutter = (Woodcutter*)pAgent;
		break;
	}

		//if you have a tool, then this is not a valid action, otherwise it is

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
