#include "GoapGoal.h"

GoapGoal::GoapGoal(float fPriority, WorldState* pDesiredWorldState)
{
	m_fPriority = fPriority;
	m_pDesiredWorldState = pDesiredWorldState;
}

float GoapGoal::GetPriority()
{
	return m_fPriority;
}

void GoapGoal::SetPriority(float fPriority)
{
	m_fPriority = fPriority;
}

WorldState* GoapGoal::GetDesiredWorldState()
{
	return m_pDesiredWorldState;
}
