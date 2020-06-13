#pragma once
#include "Miner.h"
#include "Woodcutter.h"
#include "Blacksmith.h"
#include "WorldState.h"
#include "Renderer2D.h"
#include "Shop.h"

//Worldstates
#include "AtBlacksmith.h"
#include "GotTool.h"
#include "HasResources.h"
#include "Working.h"
//Actions
#include "GotoBlacksmith.h"
#include "BuyTool.h"
#include "BuyResources.h"
#include "MakeTool.h"
#include "CollectResource.h"
class GoapManager
{
public:
	GoapManager();
	~GoapManager();

	void Update(float fDeltaTime);
	void Draw(aie::Renderer2D* pRenderer);
private:

	//people
	Miner* m_pMiner;
	Blacksmith* m_pBlacksmith;
	Woodcutter* m_pWoodcutter;

	//Stations
	Shop* m_pBlacksmithShop;

	//worldstates
	AtBlacksmith* m_pAtBlacksmith;
	GotTool* m_pNoTool;
	GotTool* m_pGotTool;
	HasResources* m_pGotResources;
	HasResources* m_pNoResources;
	Working* m_pWorking;
	Working* m_pNotWorking;

	//Actions
	GotoBlacksmith* m_pGotoBlacksmith;
	BuyTool* m_pBuyTool;
	BuyResources* m_pBuyResources;
	MakeTool* m_pMakeTool;
	CollectResource* m_pCollectResource;
};

