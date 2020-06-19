#pragma once
#include "Renderer2D.h"
#include "Vector2.h"

class Person;
class Miner;
class Mine
{
public:
	Mine(Vector2 v2Position);
	void Update(float fDeltaTime);

	void Draw(aie::Renderer2D* pRenderer);

	Vector2 GetPosition();
	void SetPosition(Vector2 v2Position);

	float GetOreCost();
	int GetOreCount();


	void CollectMoney(Miner* pMiner);

	float GetMoney();
	bool BuyOre(Person* pPerson, int nAmount);
private:
	friend class Miner;

	void AddOre(int nAmount = 1);
	Vector2 m_v2Position;
	float m_fOreCost;
	int m_nOre;
	float m_fMoneyCollected;
	float m_fTimer;
};

