#include "Working.h"
#include "Person.h"

Working::Working(std::string strKey, bool bValue) : WorldState(strKey,bValue)
{
}

bool Working::IsSatisfied(GoapAgent* pAgent)
{
	Person* pPerson = (Person*)pAgent;

	if (pPerson)
	{
		return pPerson->GetWorking();
	}
	return false;
}
