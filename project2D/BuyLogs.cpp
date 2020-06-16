#include "BuyLogs.h"
#include "Blacksmith.h"

BuyLogs::BuyLogs(LoggingSite* pSite, WorldState* pSatisfies, std::vector<WorldState*> pRequired) : GoapAction(pSatisfies, pRequired)
{
	m_pLoggingSite = pSite;
	m_fCost = m_pLoggingSite->GetLogPrice();
}

bool BuyLogs::IsValid(GoapAgent* pAgent)
{
	Blacksmith* pBlacksmith = (Blacksmith*)pAgent;

	if (pBlacksmith)
	{
		return pBlacksmith->LogCount() < 1;
	}


	return false;
}

float BuyLogs::GetCost(GoapAgent* pAgent)
{
	


	return m_fCost;
}
