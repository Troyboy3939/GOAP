#include "Woodcutter.h"

Woodcutter::Woodcutter(LoggingSite* pSite, Vector3 v3Colour) : Person(Person::TYPE::WOODCUTTER,v3Colour)
{
	m_pLoggingSite = pSite;
	m_v2Position = m_pLoggingSite->GetPosition();
	m_pTool = new Tool();
	m_fMoney = 0.0f;
	m_nLogs = 0;
}

void Woodcutter::Update(float fDeltaTime)
{
	Person::Update(fDeltaTime);
	m_v2Position += m_v2Velocity * fDeltaTime;
}

void Woodcutter::Draw(aie::Renderer2D* pRenderer)
{
	//Set the colour of the Woodcutter
	pRenderer->setRenderColour(m_v3Colour.x, m_v3Colour.y, m_v3Colour.z);

	//Draw the Woodcutter 
	pRenderer->drawCircle(m_v2Position.x, m_v2Position.y, 10);

	//Set the colour back to black
	pRenderer->setRenderColour(0, 0, 0);
}

float Woodcutter::GetToolDurability()
{
	return m_pTool->GetDurability();
}

bool Woodcutter::HasTool()
{
	return m_pTool;
}

bool Woodcutter::AtStation()
{
	Vector2 v2ToSite = m_pLoggingSite->GetPosition() - m_v2Position;
	float fDistanceTo = 30;

	return v2ToSite.magnitudeSq() < fDistanceTo * fDistanceTo;
}

bool Woodcutter::StationExists()
{
	return m_pLoggingSite;
}
