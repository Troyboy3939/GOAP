#pragma once
#include <WorldState.h>
#include <string>
class Blacksmith;
class Person;
class AtBlacksmith :
	public WorldState
{
public:
	AtBlacksmith(Blacksmith* pBlacksmith, std::string strKey, bool bValue);

	bool IsSatisfied(GoapAgent* pAgent);


private:
	Blacksmith* m_pBlacksmith;
	float m_fRadius;
};

