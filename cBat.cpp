#include "DXUT.h"
#include "cBat.h"
#include "cMHBullet.h"
#include "cMBullet.h"

cBat::cBat(Vec2 pos, cPlayer* player, vector<cBullet*>& bullet)
	: cMob(pos), m_bullet(bullet)
{
	m_ani = IMAGE->MakeVecImg("mob_1");
	m_player = player;
	m_hp = 20;
	m_damage = 1;
	m_size = 20;
	mobName = "Bat";
	mobType = "none";
	AniS = new cTimer(0.1, [&]()->void {
		frame++;
		if (frame == m_ani.size())
			frame = 0;
	}, 1);
}

cBat::~cBat()
{
	SAFE_DELETE(AniS);
	SAFE_DELETE(AS);
}

void cBat::Update()
{
	if (AniS != nullptr) AniS->Update();
	if (AS != nullptr) AS->Update();
	m_pos.y += 7;

	if (fire)
	{
		AS = new cTimer(2, [&]()->void { fire = true; AS = nullptr; });
		m_bullet.push_back(new cMHBullet(m_pos, m_player, m_damage));
		fire = false;
	}
}

void cBat::Render()
{
	RENDER->CenterRender(m_ani[frame], m_pos);
}

void cBat::UIRender()
{
}
