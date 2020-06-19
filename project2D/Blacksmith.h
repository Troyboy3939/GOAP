#pragma once
#include "Person.h"
#include "Tool.h"
#include "SmithingSite.h"

class Blacksmith : public Person
{
public:


	Blacksmith(aie::Font* pFont, SmithingSite* pSmithingSite , Vector3 v3Colour = Vector3(0.2f, 0.2f, 0.2f));
	void Update(float fDeltaTime);

	void Draw(aie::Renderer2D* pRenderer);

	bool HasResources();
	bool HasTool();

	bool AtStation();
	bool StationExists();

	int LogCount();
	int OreCount();

	void SetTool(Tool* pTool);
private:
	SmithingSite* m_pSmithingSite;
	Tool* m_pTool;
	int m_nLogs;
	int m_nOre; 
	float m_fTimer;

	aie::Font* m_pFont;
};

