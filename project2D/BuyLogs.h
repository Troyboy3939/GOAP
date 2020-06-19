#pragma once
#include "GoapAction.h"
#include "LoggingSite.h"
class BuyLogs :
	public GoapAction
{
public:
	BuyLogs(LoggingSite* pSite,WorldState* pSatisfies, std::vector<WorldState*>pRequired);

	bool IsValid(GoapAgent* pAgent);
	float GetCost(GoapAgent* pAgent);

	Vector2 GetSitePosition();

	LoggingSite* GetSite();
private:
	LoggingSite* m_pLoggingSite;
};

