#include "Mine.h"

Mine::Mine(Vector2 v2Position)
{
	m_v2Position = v2Position;
	m_fMoneyCollected = 0;
	m_nOre = 0;
	m_fOreCost = 100;
}

void Mine::Update(float fDeltaTime)
{
}

void Mine::Draw(aie::Renderer2D* pRenderer)
{
	
	pRenderer->setRenderColour(0.4f, 0.4f, 0.4f);
	pRenderer->drawBox(m_v2Position.x, m_v2Position.y, 50, 50, 0, 2);
	pRenderer->setRenderColour(0.0f, 0.0f, 0.0f);
}

Vector2 Mine::GetPosition()
{
	return m_v2Position;
}

void Mine::SetPosition(Vector2 v2Position)
{
	m_v2Position = v2Position;
}

float Mine::GetOreCost()
{
	return m_fOreCost;
}

int Mine::GetOreCount()
{
	return m_nOre;
}

void Mine::AddOre()
{
	m_nOre++;
}
