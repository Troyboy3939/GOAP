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

bool WorldState::operator==(WorldState otherState)
{
	//If the key is the same
	if (strcmp(m_strKey.c_str(),otherState.GetKey().c_str()) == 0)
	{
		//as well as the value
		if (m_bValue == otherState.GetValue())
		{
			//return true
			return true;
		}
	}
	//Otherwise return false
	return false;
}
