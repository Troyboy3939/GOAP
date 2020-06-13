#include "MakeTool.h"
#include "Blacksmith.h"
MakeTool::MakeTool(WorldState* pSatisfies, std::vector<WorldState*> aRequired) : GoapAction(pSatisfies,aRequired)
{

}

bool MakeTool::IsValid(GoapAgent* pAgent)
{
	Blacksmith* pBlacksmith = (Blacksmith*)pAgent;

	if (pBlacksmith)
	{
		//valid action if the blacksmith has resources
		return pBlacksmith->HasResources();
	}
	return false;
}
