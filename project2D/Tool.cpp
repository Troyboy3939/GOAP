#include "Tool.h"

Tool::Tool()
{
	m_fDurability = 1.0f;
}

float Tool::GetDurability()
{
	return m_fDurability;
}

void Tool::SetDurability(float fDurability)
{
	m_fDurability = fDurability;
}

