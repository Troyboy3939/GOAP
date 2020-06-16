#pragma once
#include "Renderer2D.h"
#include "Vector2.h"
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

private:
	friend class Miner;

	void AddOre();
	Vector2 m_v2Position;
	float m_fOreCost;
	int m_nOre;
	float m_fMoneyCollected;
};

