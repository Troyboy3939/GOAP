#include "GoapManager.h"

GoapManager::GoapManager()
{

	


	//initialise people
	m_pMiner = new Miner();
	m_pBlacksmith = new Blacksmith();
	m_pWoodcutter = new Woodcutter();

	//initialise action lists
	std::vector<GoapAction*> aMinerActions;
	std::vector<GoapAction*> aWoodcutterActions;
	std::vector<GoapAction*> aBlacksmithActions;

								//WORLDSTATES
	//------------------------------------------------------------------------------
	m_pAtBlacksmith = new AtBlacksmith(m_pBlacksmith, "AtBlacksmith", true);
	m_pGotTool = new GotTool("GotTool",true);
	m_pNoTool = new GotTool("GotTool", false);
	m_pNoResources = new HasResources("HasResources",false);
	m_pGotResources = new HasResources("HasResources", true);
	m_pWorking = new Working("Working",true);
	m_pNotWorking = new Working("Working", false);
	//------------------------------------------------------------------------------



								//ARRAY CREATION FOR ACTION REQUIREMENTS
	//------------------------------------------------------------------------------

	//Vector than has nothing it, meaning an action that has this requires nothing
	std::vector<WorldState*> aNothing;

	std::vector<WorldState*> aBuyTool;
	aBuyTool.push_back(m_pNoTool);
	aBuyTool.push_back(m_pAtBlacksmith);

	
	std::vector<WorldState*> aBuyResources;

	//Only buy resources if you have none
	aBuyResources.push_back(m_pNoResources);

	std::vector<WorldState*> aMakeTool;
	//Need to have resources to make tools
	aMakeTool.push_back(m_pGotResources);

	//need to be at the blacksmith
	aMakeTool.push_back(m_pAtBlacksmith);


	std::vector<WorldState*> aCollectResource;
	aCollectResource.push_back(m_pNotWorking);
	//------------------------------------------------------------------------------




							//ACTIONS
	//------------------------------------------------------------------------------
	m_pBuyTool = new BuyTool(m_pNoTool,aBuyTool);
	m_pGotoBlacksmith = new GotoBlacksmith(m_pBlacksmithShop,m_pAtBlacksmith, aNothing);
	m_pBuyResources = new BuyResources(m_pGotResources,aBuyResources);
	m_pMakeTool = new MakeTool(m_pWorking,aMakeTool);
	m_pCollectResource = new CollectResource(m_pWorking,aCollectResource);
	//------------------------------------------------------------------------------
}

GoapManager::~GoapManager()
{
	delete m_pMiner;
	delete m_pBlacksmith;
	delete m_pWoodcutter;
}

void GoapManager::Update(float fDeltaTime)
{
	//Update people
	m_pMiner->Update(fDeltaTime);
	m_pBlacksmith->Update(fDeltaTime);
	m_pWoodcutter->Update(fDeltaTime);
}

void GoapManager::Draw(aie::Renderer2D* pRenderer)
{
	//draw people
	m_pMiner->Draw(pRenderer);
	m_pBlacksmith->Draw(pRenderer);
	m_pWoodcutter->Draw(pRenderer);
}
