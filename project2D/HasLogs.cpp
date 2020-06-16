#include "HasLogs.h"
#include "Blacksmith.h"

HasLogs::HasLogs(std::string strKey, bool bValue) : WorldState(strKey,bValue)
{
}

bool HasLogs::IsSatisfied(GoapAgent* pAgent)
{
	Blacksmith* pBlackmith = (Blacksmith*)pAgent;




	return pBlackmith->LogCount() > 0;
}
