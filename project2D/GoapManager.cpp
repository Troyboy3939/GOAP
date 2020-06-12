#include "GoapManager.h"

GoapManager::GoapManager()
{

	


	//initialise people
	m_pMiner = new Miner();
	m_pBlacksmith = new Blacksmith();
	m_pWoodcutter = new Woodcutter();

	//initialise actions
	std::vector<GoapAction*> aMinerActions;
	std::vector<GoapAction*> aWoodcutterActions;
	std::vector<GoapAction*> aBlacksmithActions;

	std::vector<WorldState*> aNothing;
	m_pAtBlacksmith = new AtBlacksmith(m_pBlacksmith, "AtBlacksmith", true);
	m_pGotoBlacksmith = new GotoBlacksmith(m_pBlacksmith,m_pAtBlacksmith, aNothing);

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
