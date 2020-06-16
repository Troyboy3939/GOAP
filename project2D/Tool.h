#pragma once
class Tool
{
public:
	enum class ETYPE
	{
		AXE,
		PICKAXE
	};

	float GetDurability();
	void SetDurability(float fDurability);

	ETYPE GetType();
protected:
	//What type of tool is it
	ETYPE m_eType;
	float m_fDurability;
};

