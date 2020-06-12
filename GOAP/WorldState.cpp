#include "WorldState.h"

WorldState::WorldState(std::string strKey, bool bValue)
{
	m_strKey = strKey;
	m_bValue = bValue;
}

std::string WorldState::GetKey()
{
	return m_strKey;
}

bool WorldState::GetValue()
{
	return m_bValue;
}

void WorldState::SetValue(bool bValue)
{
	m_bValue = bValue;
}

void WorldState::SetKey(std::string strKey)
{
	m_strKey = strKey;
}

