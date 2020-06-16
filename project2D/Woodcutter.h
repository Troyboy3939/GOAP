#pragma once
#include "Person.h"
#include "Tool.h"
#include "LoggingSite.h"
class Woodcutter : public Person
{
public:
	//Put in default miner colour
	Woodcutter(LoggingSite* pSite, Vector3 v3Colour =  Vector3(1,0.549f,0));

	void Update(float fDeltaTime);

	void Draw(aie::Renderer2D* pRenderer);

	float GetToolDurability();
	bool HasTool();

	bool AtStation();
	bool StationExists();
private:
	LoggingSite* m_pLoggingSite;
	Tool* m_pTool;
	int m_nLogs;
};

