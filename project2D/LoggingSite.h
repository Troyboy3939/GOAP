#pragma once
#include "Renderer2D.h"
#include "Vector2.h"

class Person;
class Woodcutter;
class LoggingSite
{
public:
	LoggingSite(Vector2 v2Position);

	void Update(float fDeltaTime);

	void Draw(aie::Renderer2D* pRenderer);

	Vector2 GetPosition();
	void SetPosition(Vector2 v2Position);

	//returns true if bought log
	bool BuyLog(Person* pCustomer, int nAmount);

	float GetLogPrice();

	float GetMoney();
	int LogCount();
	void CollectMoney(Woodcutter* pWoodcutter);
private:

	friend class Woodcutter;
	void AddLog();
	
	Vector2 m_v2Position;
	int m_nLogs;
	float m_fLogPrice;
	float m_fMoneyCollected;
	float m_fTimer;
};

