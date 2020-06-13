#include "Woodcutter.h"

Woodcutter::Woodcutter( Vector3 v3Colour, Vector2 v2Position) : Person(Person::TYPE::WOODCUTTER,v2Position,v3Colour)
{
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
