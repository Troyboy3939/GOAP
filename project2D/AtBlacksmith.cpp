#include "AtBlacksmith.h"
#include "Blacksmith.h"

AtBlacksmith::AtBlacksmith(Blacksmith* pBlacksmith, std::string strKey, bool bValue) : WorldState(strKey,bValue)
{
	m_pBlacksmith = pBlacksmith;
	m_fRadius = 20;
}

bool AtBlacksmith::IsSatisfied(GoapAgent* pAgent)
{
	//If both the blacksmith and person exist
	if (m_pBlacksmith && pAgent)
	{
		//if the person is with m_fRadius of the blacksmith, return true, otherwise false
		return (m_pBlacksmith->GetPosition() - ((Person*)(pAgent))->GetPosition()).magnitudeSq() < (m_fRadius * m_fRadius);
	}

	return false;
}
