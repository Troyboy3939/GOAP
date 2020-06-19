#include "Person.h"

#include <iostream>


Person::Person(TYPE eType , Vector3 v3Colour) : GoapAgent()
{

	m_v3Colour = v3Colour;
	m_eType = eType;
	m_bWorking = false;
	//Initial investment
	m_fMoney = 500.0f;
	m_fMaxSpeed = 100.0f;

	
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

bool Person::GetWorking()
{
	return m_bWorking;
}

void Person::SetPosition(Vector2 v2Position)
{
	m_v2Position = v2Position;
}

void Person::SetVelocity(Vector2 v2Velocity)
{
	m_v2Velocity = v2Velocity;
}

Person::TYPE Person::GetType()
{
	return m_eType;
}

float Person::GetMoney()
{
	return m_fMoney;
}

void Person::SetMoney(float fMoney)
{
	m_fMoney = fMoney;
}
