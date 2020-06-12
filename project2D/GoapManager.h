#pragma once
#include "Miner.h"
#include "Woodcutter.h"
#include "Blacksmith.h"
#include "WorldState.h"
#include "Renderer2D.h"
#include "AtBlacksmith.h"
#include "GotoBlacksmith.h"

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

	//worldstates
	AtBlacksmith* m_pAtBlacksmith;


	//Actions
	GotoBlacksmith* m_pGotoBlacksmith;

};

