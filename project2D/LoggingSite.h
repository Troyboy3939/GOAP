#pragma once
#include "Renderer2D.h"
#include "Vector2.h"

class Person;

class LoggingSite
{
public:
	LoggingSite(Vector2 v2Position);

	void Update(float fDeltaTime);

	void Draw(aie::Renderer2D* pRenderer);

	Vector2 GetPosition();
	void SetPosition(Vector2 v2Position);

	//returns true if bought log
	bool BuyLog(Person* pCustomer);

	float GetLogPrice();
private:

	friend class Woodcutter;
	void AddLog();
	
	Vector2 m_v2Position;
	int m_nLogs;
	float m_fLogPrice;
	float m_fMoneyCollected;
};

