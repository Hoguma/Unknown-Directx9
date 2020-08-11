#include "DXUT.h"
#include "cItemAdmin.h"
#include "cFuel.h"
#include "cHeal.h"


cItemAdmin::cItemAdmin(cPlayer* player)
	:m_player(player)
{
}


cItemAdmin::~cItemAdmin()
{
	for (auto iter : m_itmes) SAFE_DELETE(iter);
	m_itmes.clear();
}

void cItemAdmin::Update()
{
	for (auto iter : m_itmes) iter->Update();
	CreateItem();
	IsOut();
	IsDestroy();
}

void cItemAdmin::Render()
{
	for (auto iter : m_itmes) iter->Render();
}

void cItemAdmin::CreateItem()
{
	if (mobDead)
	{
		CreatePercent = rand() % 4;
		if (CreatePercent <= 3)
		{
			float percent = rand() % 20;
			if (percent < 16)
			{
				m_itmes.push_back(new cFuel(mobPos));
				mobDead = false;
			}
			if (percent >= 17)
			{
				m_itmes.push_back(new cHeal(mobPos));
				mobDead = false;
			}
		}
		else
			mobDead = false;
	}
}

void cItemAdmin::IsOut()
{
	for (auto& iter = m_itmes.begin(); iter != m_itmes.end();)
	{
		if ((*iter)->IsOutMap())
		{
			SAFE_DELETE(*iter);
			iter = m_itmes.erase(iter);
		}
		else
			iter++;
	}
}

void cItemAdmin::IsDestroy()
{
	for (auto& iter = m_itmes.begin(); iter != m_itmes.end();)
	{
		if ((*iter)->isDestroy)
		{
			SAFE_DELETE(*iter);
			iter = m_itmes.erase(iter);
		}
		else
			iter++;
	}
}