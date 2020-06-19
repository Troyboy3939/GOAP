#pragma once
#include "Renderer2D.h"
#include "Vector2.h"
#include "Tool.h"
#include <vector>


class Person;
class Blacksmith;
class SmithingSite
{
public:
	SmithingSite(Vector2 v2Position);
	void Update(float fDeltaTime);

	void Draw(aie::Renderer2D* pRenderer);

	Vector2 GetPosition();
	void SetPosition(Vector2 v2Position);

	void AddTool(Tool* pTool);
	bool BuyTool(Person* pPerson);

	void CollectMoney(Blacksmith* pBlackSmith);


	float GetMoney();
	int GetAmountOfTools();
private:
	Vector2 m_v2Position;
	std::vector<Tool*>m_aTools;

	float m_fToolCost;
	float m_fMoneyCollected;
	float m_fTimer;
};

