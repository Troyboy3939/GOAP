#pragma once
#include "Person.h"
#include "Tool.h"
#include "Mine.h"
class Miner : public Person
{
public: 
	Miner(Mine* pMine, Vector3 v3Colour = Vector3(1, 0.843f, 0));
	void Update(float fDeltaTime);

	void Draw(aie::Renderer2D* pRenderer);

	float GetToolDurability();
	bool HasTool();

	bool AtStation();
	bool StationExists();

private:
	Tool* m_pTool;
	int m_nOre;
	Mine* m_pMine;
};

