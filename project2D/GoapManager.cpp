#include "GoapManager.h"

GoapManager::GoapManager(Mine* pMine, LoggingSite* pLogSite, SmithingSite* pSmithSite)
{

	
	//You said miner, 


	//initialise people
	m_pMiner = new Miner(pMine);
	m_pBlacksmith = new Blacksmith(pSmithSite);
	m_pWoodcutter = new Woodcutter(pLogSite);

	//initialise action lists
	std::vector<GoapAction*> aMinerActions;
	std::vector<GoapAction*> aWoodcutterActions;
	std::vector<GoapAction*> aBlacksmithActions;

								//WORLDSTATES
	//------------------------------------------------------------------------------
	m_pAtBlacksmith = new AtBlacksmith(m_pBlacksmith, "AtBlacksmith", true);
	m_pGotTool = new GotTool("GotTool",true);
	m_pNoTool = new GotTool("GotTool", false);
	m_pGotLogs = new HasLogs("HasLogs",true);
	m_pNoLogs = new HasLogs("HasLogs", false);
	m_pNoOre = new HasOre("HasOre", false);
	m_pGotOre = new HasOre("HasOre",true);
	m_pWorking = new Working("Working",true);
	//------------------------------------------------------------------------------

								//Goals
	//------------------------------------------------------------------------------
	m_pWorkGoal = new Work(1,m_pWorking);
	m_pBuyToolGoal = new BuyTool(0.5f,m_pAtBlacksmith);

	//------------------------------------------------------------------------------




								//ARRAY CREATION FOR ACTION REQUIREMENTS
	//------------------------------------------------------------------------------

	//Vector than has nothing it, meaning an action that has this requires nothing
	std::vector<WorldState*> aNothing;

	std::vector<WorldState*> aBuyTool;
	aBuyTool.push_back(m_pNoTool);
	aBuyTool.push_back(m_pAtBlacksmith);

	
	
	std::vector<WorldState*> aMakeTool;
	//need to be at the blacksmith
	aMakeTool.push_back(m_pAtBlacksmith);




	std::vector<WorldState*> aBuyLogs;
	aBuyLogs.push_back(m_pNoLogs);

	std::vector<WorldState*> aBuyOre;
	aBuyOre.push_back(m_pNoOre);
	//------------------------------------------------------------------------------




							//ACTIONS
	//------------------------------------------------------------------------------
	m_pGotoBlacksmith = new GotoBlacksmith(pSmithSite,m_pAtBlacksmith, aNothing);
	m_pMakeTool = new MakeTool(m_pWorking,aMakeTool);
	m_pCollectResource = new CollectResource(m_pWorking,aNothing);
	m_pBuyLogs = new BuyLogs(pLogSite,m_pGotLogs,aBuyLogs);
	m_pBuyOre = new BuyOre(pMine,m_pGotOre, aBuyOre);
	//------------------------------------------------------------------------------

							//ADD ACTIONS AND GOALS TO PEOPLE
	//------------------------------------------------------------------------------

	aMinerActions.push_back(m_pGotoBlacksmith);
	aMinerActions.push_back(m_pCollectResource);

	m_pMiner->SetAvailableActions(aMinerActions);

	aWoodcutterActions.push_back(m_pGotoBlacksmith);
	aWoodcutterActions.push_back(m_pCollectResource);
	m_pWoodcutter->SetAvailableActions(aWoodcutterActions);


	aBlacksmithActions.push_back(m_pGotoBlacksmith);
	aBlacksmithActions.push_back(m_pMakeTool);
	aBlacksmithActions.push_back(m_pBuyLogs);
	aBlacksmithActions.push_back(m_pBuyOre);
	m_pBlacksmith->SetAvailableActions(aBlacksmithActions);
	std::vector<GoapGoal*> aBlacksmithGoals;
	aBlacksmithGoals.push_back(m_pWorkGoal);
	m_pBlacksmith->SetGoals(aBlacksmithGoals);

	std::vector<GoapGoal*>aOtherGoals;
	aOtherGoals.push_back(m_pWorkGoal);
	aOtherGoals.push_back(m_pBuyToolGoal);
	m_pMiner->SetGoals(aOtherGoals);
	m_pWoodcutter->SetGoals(aOtherGoals);

	//------------------------------------------------------------------------------

}

GoapManager::~GoapManager()
{
	delete m_pMiner;
	delete m_pBlacksmith;
	delete m_pWoodcutter;
}

//Nothing, only person

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
