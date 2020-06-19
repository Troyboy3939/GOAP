#include "Blacksmith.h"
#include "BuyLogs.h"
#include "BuyOre.h"
#include "GotoBlacksmith.h"
#include "MakeTool.h"
#include <sstream>
Blacksmith::Blacksmith(aie::Font* pFont, SmithingSite* pSmithingSite, Vector3 v3Colour) : Person(Person::TYPE::BLACKSMITH,v3Colour)
{
	m_pSmithingSite = pSmithingSite;
	m_v2Position = m_pSmithingSite->GetPosition();
	//Must make the tool
	m_pTool = nullptr;
	m_nLogs = 5;
	m_nOre = 5;
	//Initial investment spent on logs and ore
	m_fMoney = 0.0f;
	m_fTimer = 0.0f;
	m_pFont = pFont;
}

void Blacksmith::Update(float fDeltaTime)
{
	//Update the GOAP Agent and whatnot
	Person::Update(fDeltaTime);

	Vector2 v2Steering;
	float fRadius = 30;
	
	


	if (m_aCurrentActions.size() > 0)
	{
		if (strcmp(m_aCurrentActions[0]->GetName().c_str(), "MakeTool") == 0)
		{
			Vector2 v2DistanceToSite = m_pSmithingSite->GetPosition() - m_v2Position;

			if (!m_pTool)
			{
				if (v2DistanceToSite.magnitudeSq() < fRadius * fRadius)
				{
					if (m_nOre > 0 && m_nLogs > 0)
					{
						m_fTimer += fDeltaTime;


						if (m_fTimer > 10.0f)
						{
							m_fTimer = 0.0f;

							m_nOre--;
							m_nLogs--;

							m_pTool = new Tool();
							m_pSmithingSite->AddTool(m_pTool);
							m_pTool = nullptr;
						}
					}
					else
					{
						//Action is complete
						m_aCurrentActions.erase(m_aCurrentActions.begin());
					}

				}
				else
				{
					v2Steering = (v2DistanceToSite.Normalised() * m_fMaxSpeed) - m_v2Velocity;
				}


			}
			else
			{
				if (v2DistanceToSite.magnitudeSq() < fRadius * fRadius)
				{
					m_pSmithingSite->AddTool(m_pTool);
					m_pTool = nullptr;
				}
			}

		}
		else if (strcmp(m_aCurrentActions[0]->GetName().c_str(), "BuyLogs") == 0)
		{
			BuyLogs* pAction = (BuyLogs*)m_aCurrentActions[0];

			Vector2 v2SitePos = pAction->GetSitePosition();

			Vector2 v2ToSite = (v2SitePos - m_v2Position);


			if (v2ToSite.magnitudeSq() > fRadius* fRadius)
			{
				v2Steering = (v2ToSite.Normalised() * m_fMaxSpeed) - m_v2Velocity;
				m_pSmithingSite->CollectMoney(this);
			}
			else
			{
				float fHalfMoney = m_fMoney / 2;
				float fLogPrice = pAction->GetSite()->GetLogPrice();


				if (pAction->GetSite()->BuyLog(this, (int)(fHalfMoney / fLogPrice)))
				{
					m_nLogs += (int)(fHalfMoney / fLogPrice);
					//Action is complete
					m_aCurrentActions.erase(m_aCurrentActions.begin());
				}
			}



		}
		else if (strcmp(m_aCurrentActions[0]->GetName().c_str(), "BuyOre") == 0)
		{
			m_pSmithingSite->CollectMoney(this);
			BuyOre* pAction = (BuyOre*)m_aCurrentActions[0];


			Vector2 v2SitePos = pAction->GetSitePosition();

			Vector2 v2ToSite = (v2SitePos - m_v2Position);


			if (v2ToSite.magnitudeSq() > fRadius* fRadius)
			{
				v2Steering = (v2ToSite.Normalised() * m_fMaxSpeed) - m_v2Velocity;
			}
			else
			{
				float fOrePrice = pAction->GetSite()->GetOreCost();
				float fHalfMoney = m_fMoney / 2;

				if (pAction->GetSite()->BuyOre(this,(int)(fHalfMoney / fOrePrice)))
				{
					m_nOre += (int)(fHalfMoney / fOrePrice);
					//Action is complete
					m_aCurrentActions.erase(m_aCurrentActions.begin());
				}
			}

		}
		else if (strcmp(m_aCurrentActions[0]->GetName().c_str(), "GotoBlacksmith") == 0)
		{
			GotoBlacksmith* pAction = (GotoBlacksmith*)m_aCurrentActions[0];


			Vector2 v2SitePos = m_pSmithingSite->GetPosition();

			Vector2 v2ToSite = (v2SitePos - m_v2Position);


			if (v2ToSite.magnitudeSq() > fRadius* fRadius)
			{
				v2Steering = (v2ToSite.Normalised() * m_fMaxSpeed) - m_v2Velocity;
			}
			else
			{
				//Action is complete
				m_aCurrentActions.erase(m_aCurrentActions.begin());
			}

		}
	}


	if (m_aCurrentActions.size() < 1)
	{
		m_pPlanner->CheckGoals();
		m_pPlanner->GetPlan();
	}

	m_v2Velocity = v2Steering;
	m_v2Position += m_v2Velocity * fDeltaTime;
}

void Blacksmith::Draw(aie::Renderer2D* pRenderer)
{
	//Set the colour of the Blacksmith
	pRenderer->setRenderColour(m_v3Colour.x, m_v3Colour.y, m_v3Colour.z);

	//Draw the Blacksmith 
	pRenderer->drawCircle(m_v2Position.x, m_v2Position.y, 10,0);

	//Set the colour back to white
	pRenderer->setRenderColour(1, 1, 1);





	std::stringstream money;
	money << "Money:" << ((int)m_fMoney) + m_pSmithingSite->GetMoney();

	std::stringstream logs;
	logs << "Logs:" << (m_nLogs);

	std::stringstream tool;
	tool << "Tool:" << m_pSmithingSite->GetAmountOfTools();

	std::stringstream ore;
	ore << "Ore:" << (m_nOre);

	


	
	float fX, fY;
	float fGap = 6;
	pRenderer->getCameraPos(fX, fY);

	pRenderer->drawText(m_pFont, "Blacksmith:", fX, 720 - (fGap * 2) -84 + fY);
	pRenderer->drawText(m_pFont, money.str().c_str(), fX + fGap, 720 - (fGap* 4) - 84 + fY);
	pRenderer->drawText(m_pFont, logs.str().c_str(), fX + fGap, 720 - (fGap * 6) - 84 + fY);
	pRenderer->drawText(m_pFont, ore.str().c_str(), fX + fGap, 720 - (fGap * 8) - 84 + fY);
	pRenderer->drawText(m_pFont, tool.str().c_str(), fX + fGap, 720 - (fGap * 10) - 84 + fY);

}

bool Blacksmith::HasResources()
{

	
	return (m_nLogs > 0 && m_nOre > 0);
}

bool Blacksmith::HasTool()
{
	return m_pTool;
}

bool Blacksmith::AtStation()
{
	Vector2 v2ToSite = m_pSmithingSite->GetPosition() - m_v2Position;

	float fDistanceTo = 30;

	return v2ToSite.magnitudeSq() < (fDistanceTo * fDistanceTo);
}

bool Blacksmith::StationExists()
{
	return m_pSmithingSite;
}

int Blacksmith::LogCount()
{
	return m_nLogs;
}

int Blacksmith::OreCount()
{
	return m_nOre;
}

void Blacksmith::SetTool(Tool* pTool)
{
	m_pTool = pTool;
}
