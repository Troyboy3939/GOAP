#include "Blacksmith.h"

Blacksmith::Blacksmith(SmithingSite* pSmithingSite, Vector3 v3Colour) : Person(Person::TYPE::BLACKSMITH,v3Colour)
{
	m_pSmithingSite = pSmithingSite;
	m_v2Position = m_pSmithingSite->GetPosition();
	//Must make the tool
	m_pTool = nullptr;
	m_nLogs = 5;
	m_nOre = 5;
	//Initial investment spent on logs and ore
	m_fMoney = 0.0f;
}

void Blacksmith::Update(float fDeltaTime)
{
	//Update the GOAP Agent and whatnot
	Person::Update(fDeltaTime);

	m_v2Position += m_v2Velocity * fDeltaTime;
}

void Blacksmith::Draw(aie::Renderer2D* pRenderer)
{
	//Set the colour of the Blacksmith
	pRenderer->setRenderColour(m_v3Colour.x, m_v3Colour.y, m_v3Colour.z);

	//Draw the Blacksmith 
	pRenderer->drawCircle(m_v2Position.x, m_v2Position.y, 10,0);

	//Set the colour back to black
	pRenderer->setRenderColour(0, 0, 0);
}

bool Blacksmith::HasResources()
{

	
	return (m_nLogs > 0 && m_nOre > 0);
}

bool Blacksmith::HasTool()
{
	return m_pTool;
}

bool Blacksmith::AtStation()
{
	Vector2 v2ToSite = m_pSmithingSite->GetPosition() - m_v2Position;

	float fDistanceTo = 30;

	return v2ToSite.magnitudeSq() < (fDistanceTo * fDistanceTo);
}

bool Blacksmith::StationExists()
{
	return m_pSmithingSite;
}

int Blacksmith::LogCount()
{
	return m_nLogs;
}

int Blacksmith::OreCount()
{
	return m_nOre;
}
