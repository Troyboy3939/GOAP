#include "Blacksmith.h"

Blacksmith::Blacksmith( Vector2 v2Position, Vector3 v3Colour) : Person(Person::TYPE::BLACKSMITH, v2Position,v3Colour)
{
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
	pRenderer->drawCircle(m_v2Position.x, m_v2Position.y, 10);

	//Set the colour back to black
	pRenderer->setRenderColour(0, 0, 0);
}
