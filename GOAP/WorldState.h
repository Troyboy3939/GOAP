#pragma once
#include <String>

class WorldState
{
public:
	WorldState(std::string strKey, bool bValue);

	std::string GetKey();
	bool GetValue();

	void SetValue(bool bValue);
	void SetKey(std::string strKey);

	//Comparing world states
	bool operator==(WorldState otherState);

private:
	//Key, describes the world state
	std::string m_strKey;

	//whether the world state is true or false
	bool m_bValue;
};

