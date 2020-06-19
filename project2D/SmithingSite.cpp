#include "SmithingSite.h"
#include "Person.h"
#include "Blacksmith.h"
SmithingSite::SmithingSite(Vector2 v2Position)
{
	m_v2Position = v2Position;
	m_fMoneyCollected = 0.0f;
	m_fToolCost = 300;
	m_fTimer = 0.0f;
}

void SmithingSite::Update(float fDeltaTime)
{
	m_fTimer += fDeltaTime;

	if (m_fTimer >= 20.0f)
	{
		if (m_aTools.size() > 0)
		{
			m_fTimer = 0;
			Tool* pTool = m_aTools[m_aTools.size() - 1];
			m_aTools.erase(m_aTools.begin() + m_aTools.size() - 1);
			delete pTool;
			m_fMoneyCollected += m_fToolCost;
		}
	}
}

void SmithingSite::Draw(aie::Renderer2D* pRenderer)
{
	pRenderer->setRenderColour(0.5f, 0.5f, 0.5f);
	pRenderer->drawBox(m_v2Position.x,m_v2Position.y,100,100,0,2);
	pRenderer->setRenderColour(1, 1, 1);

}

Vector2 SmithingSite::GetPosition()
{
	return m_v2Position;
}

void SmithingSite::SetPosition(Vector2 v2Position)
{
	m_v2Position = v2Position;
}

void SmithingSite::AddTool(Tool* pTool)
{
	m_aTools.push_back(pTool);

}

bool SmithingSite::BuyTool(Person* pPerson)
{
	if (pPerson->GetMoney() >= m_fToolCost)
	{
		if (m_aTools.size() > 0)
		{
			pPerson->SetMoney(pPerson->GetMoney() - m_fToolCost);
			pPerson->SetTool(m_aTools[m_aTools.size() - 1]);
			m_aTools.pop_back();
			m_fMoneyCollected += m_fToolCost;
			return true;
		}
	}
	return false;
}

void SmithingSite::CollectMoney(Blacksmith* pBlackSmith)
{
	if (pBlackSmith)
	{
		pBlackSmith->SetMoney(pBlackSmith->GetMoney() + m_fMoneyCollected);
		m_fMoneyCollected = 0.0f;
	}
}

float SmithingSite::GetMoney()
{
	return m_fMoneyCollected;
}

int SmithingSite::GetAmountOfTools()
{
	return m_aTools.size();
}
