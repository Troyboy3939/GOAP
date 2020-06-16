#pragma once
#include <String>
class GoapAgent;
class WorldState
{
public:
	WorldState(std::string strKey, bool bValue);

	std::string GetKey();
	bool GetValue();

	void SetValue(bool bValue);
	void SetKey(std::string strKey);

	//Returns whether the required world state is satisfied or not
	virtual bool IsSatisfied(GoapAgent* pAgent) = 0;

	bool operator==(WorldState* pOther);
private:
	//Key, describes the world state
	std::string m_strKey;

	//whether the world state is true or false
	bool m_bValue;
};

