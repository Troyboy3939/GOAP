#pragma once
class Tool
{
public:
	enum class ETYPE
	{
		AXE,
		PICKAXE
	};

protected:
	//What type of tool is it
	ETYPE m_eType;
	float m_fDurability;
};

