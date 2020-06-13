#include "GotTool.h"
#include "Miner.h"
#include "Woodcutter.h"
#include "Blacksmith.h"

GotTool::GotTool(std::string strKey, bool bValue) : WorldState(strKey,bValue)
{
}

bool GotTool::IsSatisfied(GoapAgent* pAgent)
{
	//Create pointers
	Miner* pMiner = nullptr;
	Woodcutter* pWoodcutter = nullptr;
	Blacksmith* pBlacksmith = nullptr;


	//Convert person based on the type
	switch (((Person*)pAgent)->GetType())
	{
	case Person::TYPE::MINER:
		pMiner = (Miner*)pAgent;
		break;

	case Person::TYPE::WOODCUTTER:
		pWoodcutter = (Woodcutter*)pAgent;
		break;
	case Person::TYPE::BLACKSMITH:
		pBlacksmith = (Blacksmith*)pAgent;
		break;
	}

	
	//satisfied if HaveTool() is true
	if (pMiner)
	{
		return (pMiner->HasTool());
	}
	else if (pWoodcutter)
	{
		return!(pWoodcutter->HasTool());
	}
	else if (pBlacksmith)
	{
		return !(pBlacksmith->HasTool());
	}

	return false;
}
