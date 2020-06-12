#include "Person.h"

Person::Person( Vector2 v2Position , Vector3 v3Colour) : GoapAgent()
{
	m_v2Position = v2Position;
	m_v3Colour = v3Colour;
}

void Person::Update(float fDeltaTime)
{
	GoapAgent::Update();
}

Vector2 Person::GetPosition()
{
	return  m_v2Position;
}

Vector2 Person::GetVelocity()
{
	return m_v2Velocity;
}

void Person::SetPosition(Vector2 v2Position)
{
	m_v2Position = v2Position;
}

void Person::SetVelocity(Vector2 v2Velocity)
{
	m_v2Velocity = v2Velocity;
}
