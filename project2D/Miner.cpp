#include "Miner.h"

#include <iostream>
Miner::Miner(Mine* pMine, Vector3 v3Colour) : Person(Person::TYPE::MINER,v3Colour)
{
	m_pTool = new Tool();
	m_pTool = new Tool();
	m_pMine = pMine;
	m_v2Position = m_pMine->GetPosition();
	m_nOre = 0;
}



void Miner::Update(float fDeltaTime)
{
	//Update the GOAP Agent and whatnot
	Person::Update(fDeltaTime);

	m_v2Position += m_v2Velocity * fDeltaTime;
}

void Miner::Draw(aie::Renderer2D* pRenderer)
{
	//Set the colour of the Miner
	pRenderer->setRenderColour(m_v3Colour.x, m_v3Colour.y, m_v3Colour.z);

	//Draw the miner 
	pRenderer->drawCircle(m_v2Position.x, m_v2Position.y, 10);

	//Set the colour back to black
	pRenderer->setRenderColour(0, 0, 0);
}

float Miner::GetToolDurability()
{
	return m_pTool->GetDurability();
}

bool Miner::HasTool()
{
	return m_pTool;
}

bool Miner::AtStation()
{
	Vector2 v2ToMine = m_pMine->GetPosition() - m_v2Position;


	float fDistanceTo = 30;
	return v2ToMine.magnitudeSq() < fDistanceTo * fDistanceTo;
}

bool Miner::StationExists()
{
	return m_pMine;
}
