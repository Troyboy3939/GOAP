#pragma once
#include "GoapAction.h"

class Blacksmith;
class Worldstate;
class Person;
class GotoBlacksmith : public GoapAction
{
public:
	GotoBlacksmith(Blacksmith* pBlacksmith ,WorldState* pSatisfies, std::vector<WorldState*> aRequired);

	bool IsValid(GoapAgent* pAgent);
private:
	Blacksmith* m_pBlacksmith;
};

