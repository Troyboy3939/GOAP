#include "Tool.h"

float Tool::GetDurability()
{
	return m_fDurability;
}

void Tool::SetDurability(float fDurability)
{
	m_fDurability = fDurability;
}

Tool::ETYPE Tool::GetType()
{
	return m_eType;
}
