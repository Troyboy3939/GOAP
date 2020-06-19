#include "LoggingSite.h"
#include "Person.h"
#include "Woodcutter.h"
LoggingSite::LoggingSite(Vector2 v2Position)
{
	m_v2Position = v2Position;
	m_fLogPrice = 100;
	m_fMoneyCollected = 0;
	m_nLogs = 1;
	m_fTimer = 0.0f;
}

void LoggingSite::Update(float fDeltaTime)
{
	m_fTimer += fDeltaTime;

	if (m_fTimer > 15.0f)
	{
		if (m_nLogs > 5)
		{
			m_fTimer = 0;
			m_nLogs--;
			m_fMoneyCollected += m_fLogPrice;
		}
	}
}

void LoggingSite::Draw(aie::Renderer2D* pRenderer)
{
	pRenderer->setRenderColour(0.1f, 0.78f, 0.1f);
	pRenderer->drawBox(m_v2Position.x, m_v2Position.y, 100, 100, 0, 2);
	pRenderer->setRenderColour(1, 1, 1);
}

Vector2 LoggingSite::GetPosition()
{
	return m_v2Position;
}

void LoggingSite::SetPosition(Vector2 v2Position)
{
	m_v2Position = v2Position;
}

bool LoggingSite::BuyLog(Person* pCustomer, int nAmount)
{
	if (pCustomer->GetMoney() >= m_fLogPrice * nAmount)
	{
		if (m_nLogs >= nAmount)
		{
			pCustomer->SetMoney(pCustomer->GetMoney() - m_fLogPrice * nAmount);
			m_fMoneyCollected += m_fLogPrice * nAmount;
			m_nLogs -= nAmount;
			return true;
		}
	}

	return false;
}

float LoggingSite::GetLogPrice()
{
	return m_fLogPrice;
}

float LoggingSite::GetMoney()
{
	return m_fMoneyCollected;
}

int LoggingSite::LogCount()
{
	return m_nLogs;
}

void LoggingSite::CollectMoney(Woodcutter* pWoodcutter)
{
	if (pWoodcutter)
	{
		pWoodcutter->SetMoney(pWoodcutter->GetMoney() + m_fMoneyCollected);
		m_fMoneyCollected = 0.0f;
	}
}

void LoggingSite::AddLog()
{
	m_nLogs++;
}
