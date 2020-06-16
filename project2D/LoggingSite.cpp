#include "LoggingSite.h"
#include "Person.h"
LoggingSite::LoggingSite(Vector2 v2Position)
{
	m_v2Position = v2Position;
	m_fLogPrice = 100;
	m_fMoneyCollected = 0;
	m_nLogs = 1;
}

void LoggingSite::Update(float fDeltaTime)
{
}

void LoggingSite::Draw(aie::Renderer2D* pRenderer)
{
	pRenderer->setRenderColour(0.8f, 0.52f, 0.24f);
	pRenderer->drawBox(m_v2Position.x, m_v2Position.y, 100, 100, 0, 2);
	pRenderer->setRenderColour(0.0f, 0.0f, 0.0f);
}

Vector2 LoggingSite::GetPosition()
{
	return m_v2Position;
}

void LoggingSite::SetPosition(Vector2 v2Position)
{
	m_v2Position = v2Position;
}

bool LoggingSite::BuyLog(Person* pCustomer)
{
	if (pCustomer->GetMoney() > m_fLogPrice)
	{
		if (m_nLogs > 0)
		{
			pCustomer->SetMoney(pCustomer->GetMoney() - m_fLogPrice);
			m_fMoneyCollected += m_fLogPrice;
			return true;
		}
	}

	return false;
}

float LoggingSite::GetLogPrice()
{
	return m_fLogPrice;
}

void LoggingSite::AddLog()
{
	m_nLogs++;
}
