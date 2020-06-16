#include "Work.h"
#include "Miner.h"
#include "Blacksmith.h"
#include "Woodcutter.h"

Work::Work(float fPriority, WorldState* pDesiredWorldState) : GoapGoal(fPriority, pDesiredWorldState)
{

}

bool Work::IsValid(GoapAgent* pAgent)
{
	Miner* pMiner = nullptr;
	Woodcutter* pWoodcutter = nullptr;
	Blacksmith* pBlacksmith = nullptr;

	switch (((Person*)pAgent)->GetType())
	{
	case Person::TYPE::BLACKSMITH:
		pBlacksmith = (Blacksmith*)pAgent;
		break;
	case Person::TYPE::WOODCUTTER:
		pWoodcutter = (Woodcutter*)pAgent;
		break;
	case Person::TYPE::MINER:
		pMiner = (Miner*)pAgent;
		break;
	}

	if (pMiner)
	{
		return pMiner->StationExists() && pMiner->HasTool();
	}
	else if (pWoodcutter)
	{
		return pWoodcutter->StationExists() && pWoodcutter->HasTool();
	}
	else if (pBlacksmith)
	{
		return pBlacksmith->StationExists() && pBlacksmith->HasResources();
		
	}

	return false;
}
