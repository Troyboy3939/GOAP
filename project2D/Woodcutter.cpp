#include "Woodcutter.h"
#include "GotoBlacksmith.h"
#include "SmithingSite.h"
#include <sstream>
Woodcutter::Woodcutter(aie::Font* pFont, LoggingSite* pSite, Vector3 v3Colour) : Person(Person::TYPE::WOODCUTTER,v3Colour)
{
	m_pLoggingSite = pSite;
	m_v2Position = m_pLoggingSite->GetPosition();
	m_pTool = new Tool();
	m_nLogs = 0;
	m_fTimer = 0.0f;
	m_pFont = pFont;
}

void Woodcutter::Update(float fDeltaTime)
{
	Person::Update(fDeltaTime);

	float fRadius = 30;
	Vector2 v2Steering;
	if (strcmp(m_aCurrentActions[0]->GetName().c_str(), "CollectResource") == 0)
	{
		if (m_pTool)
		{
			Vector2 v2ToLogSite = m_pLoggingSite->GetPosition() - m_v2Position;

			if (v2ToLogSite.magnitudeSq() > fRadius* fRadius)
			{
				v2Steering = (v2ToLogSite.Normalised() * m_fMaxSpeed) - m_v2Velocity;
			}
			else
			{
				m_fTimer += fDeltaTime;

				if (m_fTimer >= 5.0f)
				{
					m_fTimer = 0;
					m_pLoggingSite->AddLog();
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
		m_pLoggingSite->CollectMoney(this);
		Vector2 v2ToSite = pAction->GetSitePosition() - m_v2Position;


		if (v2ToSite.magnitudeSq() > fRadius* fRadius)
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

	if (m_aCurrentActions.size() < 1 || !m_pTool)
	{
		m_pPlanner->CheckGoals();
		m_pPlanner->GetPlan();
	}

	m_v2Velocity = v2Steering;
	m_v2Position += m_v2Velocity * fDeltaTime;
}

void Woodcutter::Draw(aie::Renderer2D* pRenderer)
{
	//Set the colour of the Woodcutter
	pRenderer->setRenderColour(m_v3Colour.x, m_v3Colour.y, m_v3Colour.z);

	//Draw the Woodcutter 
	pRenderer->drawCircle(m_v2Position.x, m_v2Position.y, 10);

	//Set the colour back to white
	pRenderer->setRenderColour(1, 1, 1);

	float fX, fY;
	float fGap = 6;
	pRenderer->getCameraPos(fX, fY);

	std::stringstream money;
	money << "Money:" << ((int)m_fMoney) + m_pLoggingSite->GetMoney();

	std::stringstream logs;
	logs << "Logs:" << (m_nLogs) + m_pLoggingSite->LogCount();

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



	pRenderer->drawText(m_pFont, "Woodcutter:", fX, 720 - (fGap * 20) - 84 + fY);
	pRenderer->drawText(m_pFont, money.str().c_str(), fX + fGap, 720 - (fGap * 22) - 84 + fY);
	pRenderer->drawText(m_pFont, logs.str().c_str(), fX + fGap, 720 - (fGap * 24) - 84 + fY);
	pRenderer->drawText(m_pFont, tool.str().c_str(), fX + fGap, 720 - (fGap * 26) - 84 + fY);
}


float Woodcutter::GetToolDurability()
{
	return m_pTool->GetDurability();
}

bool Woodcutter::HasTool()
{
	return m_pTool;
}

bool Woodcutter::AtStation()
{
	Vector2 v2ToSite = m_pLoggingSite->GetPosition() - m_v2Position;
	float fDistanceTo = 30;

	return v2ToSite.magnitudeSq() < fDistanceTo * fDistanceTo;
}

bool Woodcutter::StationExists()
{
	return m_pLoggingSite;
}

void Woodcutter::SetTool(Tool* pTool)
{
	m_pTool = pTool;
}
