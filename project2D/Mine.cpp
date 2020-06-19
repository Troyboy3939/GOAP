#include "Mine.h"
#include "Person.h"
#include "Miner.h"
Mine::Mine(Vector2 v2Position)
{
	m_v2Position = v2Position;
	m_fMoneyCollected = 0;
	m_nOre = 0;
	m_fOreCost = 100;
	m_fTimer = 0.0f;
}

void Mine::Update(float fDeltaTime)
{
	m_fTimer += fDeltaTime;

	if (m_fTimer > 15.0f)
	{
		m_fTimer = 0;
		m_nOre--;
		m_fMoneyCollected += m_fOreCost;
	}
}

void Mine::Draw(aie::Renderer2D* pRenderer)
{
	
	pRenderer->setRenderColour(0.4f, 0.4f, 0.4f);
	pRenderer->drawBox(m_v2Position.x, m_v2Position.y, 50, 50, 0, 2);
	pRenderer->setRenderColour(1, 1, 1);
}

Vector2 Mine::GetPosition()
{
	return m_v2Position;
}

void Mine::SetPosition(Vector2 v2Position)
{
	m_v2Position = v2Position;
}

float Mine::GetOreCost()
{
	return m_fOreCost;
}

int Mine::GetOreCount()
{
	return m_nOre;
}

void Mine::CollectMoney(Miner* pMiner)
{
	if (pMiner)
	{
		pMiner->SetMoney(pMiner->GetMoney() + m_fMoneyCollected);
		m_fMoneyCollected = 0.0f;
	}
}

float Mine::GetMoney()
{
	return m_fMoneyCollected;
}

bool Mine::BuyOre(Person* pPerson, int nAmount)
{
	if (pPerson->GetMoney() >= m_fOreCost * nAmount)
	{
		if (m_nOre >= nAmount)
		{
			pPerson->SetMoney(pPerson->GetMoney() - m_fOreCost * nAmount);
			m_fMoneyCollected += m_fOreCost * nAmount;
			return true;
		}
	}

	return false;
}

void Mine::AddOre(int nAmount)
{
	m_nOre += nAmount;
}
