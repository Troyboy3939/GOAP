#include "CollectResource.h"
#include "Person.h"
CollectResource::CollectResource(WorldState* pSatisifies, std::vector<WorldState*> aRequires) : GoapAction("CollectResource",pSatisifies,aRequires)
{
}

bool CollectResource::IsValid(GoapAgent* pAgent)
{

	Person* pPerson = (Person*)pAgent;


	if (pPerson)
	{
		//Valid to collect resource if station exists
		return pPerson->StationExists();
	}
	return false;
}

float CollectResource::GetCost(GoapAgent* pAgent)
{
	return 0.0f;
}
