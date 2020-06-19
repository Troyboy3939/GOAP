#include "BuyLogs.h"
#include "Blacksmith.h"

BuyLogs::BuyLogs(LoggingSite* pSite, WorldState* pSatisfies, std::vector<WorldState*> pRequired) : GoapAction("BuyLogs",pSatisfies, pRequired)
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

Vector2 BuyLogs::GetSitePosition()
{
	return m_pLoggingSite->GetPosition();
}

LoggingSite* BuyLogs::GetSite()
{
	return m_pLoggingSite;
}
