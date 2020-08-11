#include "DXUT.h"
#include "cMobAdmin.h"
#include "cBat.h"
#include "cBallon.h"
#include "cBoos.h"
#include "cTaggari.h"

cMobAdmin::cMobAdmin(cPlayer* player, vector<cBullet*>& bullet)
	:m_player(player), m_bullet(bullet)
{
	//m_mobs.push_back(new cBat(Vec2(800, 200), m_player, m_bullet));
	//m_mobs.push_back(new cTaggari(Vec2(100, 200), m_player, m_bullet));
	//m_mobs.push_back(new cTaggari(Vec2(1500, 200), m_player, m_bullet));
	//m_mobs.push_back(new cBoos(Vec2(800, -300), m_player, m_bullet));
}

cMobAdmin::~cMobAdmin()
{
	SAFE_DELETE(BatT);
	SAFE_DELETE(BalT);
	SAFE_DELETE(TaT);
	for (auto iter : m_mobs) SAFE_DELETE(iter);
	m_mobs.clear();
}

void cMobAdmin::Update()
{
	for (auto iter : m_mobs) iter->Update();
	CreateMob();
	IsOut();
	IsDestroy();
}

void cMobAdmin::Render()
{
	for (auto iter : m_mobs) iter->Render();
}

void cMobAdmin::UIRender()
{
	for (auto iter : m_mobs) iter->UIRender();
}

void cMobAdmin::CreateMob()
{
	if (BatT != nullptr) BatT->Update();
	if (BalT != nullptr) BalT->Update();
	if (TaT != nullptr) TaT->Update();
	if (SCENE->mobcount >= 25)
	{
		if (boss)
		{
			m_mobs.push_back(new cBoos(Vec2(800, -300), m_player, m_bullet));
			boss = false;
		}
		if (Ta)
		{
			TaT = new cTimer(4, [&]()->void {Ta = true; TaT = nullptr; });
			m_mobs.push_back(new cTaggari(Vec2(100, -100), m_player, m_bullet));
			m_mobs.push_back(new cTaggari(Vec2(1500, -100), m_player, m_bullet));
			Ta = false;
		}
		if (Bal)
		{
			BalT = new cTimer(5, [&]()->void {Bal = true; BalT = nullptr; });
			m_mobs.push_back(new cBallon(Vec2(rand() % 1320 + 300, -100), m_player, m_bullet));
			Bal = false;
		}
	}
	else
	{
		if (Bat)
		{
			BatT = new cTimer(4, [&]()->void {Bat = true; BatT = nullptr; });
			m_mobs.push_back(new cBat(Vec2(rand() % 1320 + 300, -100), m_player, m_bullet));
			Bat = false;
		}
		if (Bal)
		{
			BalT = new cTimer(1.5, [&]()->void {Bal = true; BalT = nullptr; });
			m_mobs.push_back(new cBallon(Vec2(rand() % 1320 + 300, -100), m_player, m_bullet));
			Bal = false;
		}
	}
}

void cMobAdmin::IsOut()
{
	for (auto& iter = m_mobs.begin(); iter != m_mobs.end();)
	{
		if ((*iter)->IsOutMap() && (*iter)->mobType != "Boss")
		{
			SAFE_DELETE(*iter);
			iter = m_mobs.erase(iter);
		}
		else
			iter++;
	}
}

void cMobAdmin::IsDestroy()
{
	for (auto& iter = m_mobs.begin(); iter != m_mobs.end();)
	{
		if ((*iter)->isDestroy)
		{
			SCENE->mobcount++;
			PART->AddParticle((*iter)->m_pos, 1);
			if ((*iter)->mobType == "Boss")
				bossD = true;
			SAFE_DELETE(*iter);
			iter = m_mobs.erase(iter);
		}
		else
			iter++;
	}
}
