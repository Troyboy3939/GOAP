#include "SmithingSite.h"

SmithingSite::SmithingSite(Vector2 v2Position)
{
	m_v2Position = v2Position;
}

void SmithingSite::Update(float fDeltaTime)
{
}

void SmithingSite::Draw(aie::Renderer2D* pRenderer)
{
	pRenderer->setRenderColour(0.5f, 0.5f, 0.5f);
	pRenderer->drawBox(m_v2Position.x,m_v2Position.y,100,100,0,2);
	pRenderer->setRenderColour(0.0f, 0.0f, 0.0f);

}

Vector2 SmithingSite::GetPosition()
{
	return m_v2Position;
}

void SmithingSite::SetPosition(Vector2 v2Position)
{
	m_v2Position = v2Position;
}
