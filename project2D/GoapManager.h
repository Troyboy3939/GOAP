#pragma once
#include "Miner.h"
#include "Woodcutter.h"
#include "Blacksmith.h"
#include "WorldState.h"
#include "Renderer2D.h"

//Worldstates
#include "AtBlacksmith.h"
#include "GotTool.h"
#include "HasLogs.h"
#include "HasOre.h"
#include "Working.h"
//Actions
#include "GotoBlacksmith.h"
#include "MakeTool.h"
#include "CollectResource.h"
#include "BuyLogs.h"
#include "BuyOre.h"

//Goals
#include "Work.h"
#include "BuyTool.h"


class GoapManager
{
public:
	GoapManager(Mine* pMine, LoggingSite* pLogSite, SmithingSite* pSmithSite);
	~GoapManager();

	void Update(float fDeltaTime);
	void Draw(aie::Renderer2D* pRenderer);
private:

	//people
	Miner* m_pMiner;
	Blacksmith* m_pBlacksmith;
	Woodcutter* m_pWoodcutter;



	//Worldstates
	AtBlacksmith* m_pAtBlacksmith;
	GotTool* m_pNoTool;
	GotTool* m_pGotTool;
	HasLogs* m_pGotLogs;
	HasLogs* m_pNoLogs;
	HasOre* m_pGotOre;
	HasOre* m_pNoOre;
	Working* m_pWorking;

	//Actions
	GotoBlacksmith* m_pGotoBlacksmith;
	MakeTool* m_pMakeTool;
	CollectResource* m_pCollectResource;
	BuyLogs* m_pBuyLogs;
	BuyOre* m_pBuyOre;

	//Goals
	Work* m_pWorkGoal;
	BuyTool* m_pBuyToolGoal;
};

