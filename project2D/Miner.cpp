#include "Miner.h"
#include "GotoBlacksmith.h"
#include <iostream>
#include "SmithingSite.h"
#include <sstream>
Miner::Miner(aie::Font* pFont, Mine* pMine, Vector3 v3Colour) : Person(Person::TYPE::MINER,v3Colour)
{
	m_pTool = new Tool();
	m_pMine = pMine;
	m_v2Position = m_pMine->GetPosition();
	m_nOre = 0;
	m_pFont = pFont;
	m_fTimer = 0.0f;
}



void Miner::Update(float fDeltaTime)
{
	//Update the GOAP Agent and whatnot
	Person::Update(fDeltaTime);

	float fRadius = 30;
	Vector2 v2Steering;
	if (strcmp(m_aCurrentActions[0]->GetName().c_str(), "CollectResource") == 0)
	{
		if (m_pTool)
		{
			Vector2 v2ToMine = m_pMine->GetPosition() - m_v2Position;

			if (v2ToMine.magnitudeSq() > fRadius* fRadius)
			{
				v2Steering = (v2ToMine.Normalised() * m_fMaxSpeed) - m_v2Velocity;
			}
			else
			{
				m_fTimer += fDeltaTime;

				if (m_fTimer >= 5.0f)
				{
					m_fTimer = 0.0f;
					m_nOre++;
					m_pTool->SetDurability(m_pTool->GetDurability() - 0.1f);

					if (m_pTool->GetDurability() <= 0.0f)
					{
						m_aUsedTools.push_back(m_pTool);
						m_pTool = nullptr;

						//Action is complete
						m_aCurrentActions.erase(m_aCurrentActions.begin());
					}

				}
			}
		}
	}
	else if (strcmp(m_aCurrentActions[0]->GetName().c_str(), "GotoBlacksmith") == 0)
	{
		GotoBlacksmith* pAction = (GotoBlacksmith*)m_aCurrentActions[0];
		Vector2 v2ToSite = pAction->GetSitePosition() - m_v2Position;
		m_pMine->CollectMoney(this);

		if (v2ToSite.magnitudeSq() > fRadius * fRadius)
		{
			v2Steering = (v2ToSite.Normalised() * m_fMaxSpeed) - m_v2Velocity;
		}
		else
		{
			if (pAction->GetSite()->BuyTool(this))
			{
				//Action is complete
				m_aCurrentActions.erase(m_aCurrentActions.begin());
			}
		}

	}
	
	if (m_nOre > 4)
	{
		m_pMine->AddOre(5);
		m_nOre -= 5;
	}

	m_v2Velocity = v2Steering;
	m_v2Position += m_v2Velocity * fDeltaTime;

	if (m_aCurrentActions.size() < 1 || (!m_pTool && strcmp(m_aCurrentActions[0]->GetName().c_str(),"CollectResource") == 0))
	{
		m_pPlanner->CheckGoals();
		m_pPlanner->GetPlan();
	}

}

void Miner::Draw(aie::Renderer2D* pRenderer)
{
	//Set the colour of the Miner
	pRenderer->setRenderColour(m_v3Colour.x, m_v3Colour.y, m_v3Colour.z);

	//Draw the miner 
	pRenderer->drawCircle(m_v2Position.x, m_v2Position.y, 10);

	//Set the colour back to white
	pRenderer->setRenderColour(1, 1, 1);

	float fX, fY;
	float fGap = 6;
	pRenderer->getCameraPos(fX, fY);

	std::stringstream money;
	money << "Money:" << ((int)m_fMoney) + m_pMine->GetMoney();

	std::stringstream ore;
	ore << "Ore:" << (m_nOre) + m_pMine->GetOreCount();

	std::stringstream tool;
	tool << "Tool:";

	if (m_pTool)
	{
		tool << "Yes";

	}
	else
	{
		tool << "No";
	}


	pRenderer->drawText(m_pFont, "Miner:", fX, 720 - (fGap * 12) - 84 + fY);
	pRenderer->drawText(m_pFont, money.str().c_str(), fX + fGap, 720 - (fGap * 14) - 84 + fY);
	pRenderer->drawText(m_pFont, ore.str().c_str(), fX + fGap, 720 - (fGap * 16) - 84 + fY);
	pRenderer->drawText(m_pFont, tool.str().c_str(), fX + fGap, 720 - (fGap * 18) - 84 + fY);
}

float Miner::GetToolDurability()
{
	return m_pTool->GetDurability();
}

bool Miner::HasTool()
{
	return m_pTool;
}

bool Miner::AtStation()
{
	Vector2 v2ToMine = m_pMine->GetPosition() - m_v2Position;


	float fDistanceTo = 30;
	return v2ToMine.magnitudeSq() < fDistanceTo * fDistanceTo;
}

bool Miner::StationExists()
{
	return m_pMine;
}

void Miner::SetTool(Tool* pTool)
{
	m_pTool = pTool;
}
