#include "DXUT.h"
#include "cTaggari.h"
#include "cMHBullet.h"
#include "cMBullet.h"

cTaggari::cTaggari(Vec2 pos, cPlayer* player, vector<cBullet*>& bullet)
	: cMob(pos), m_bullet(bullet)
{
	m_ani = IMAGE->MakeVecImg("mob_1");
	m_player = player;
	m_hp = 20;
	m_damage = 1;
	m_size = 20;
	mobName = "taggari";
	mobType = "none";
	AniS = new cTimer(0.02, [&]()->void {
		frame++;
		if (frame == m_ani.size())
			frame = 0;
	}, 1);
}

cTaggari::~cTaggari()
{
	SAFE_DELETE(AS);
	SAFE_DELETE(AniS);
}

void cTaggari::Update()
{
	if (AS != nullptr) AS->Update();
	if (AniS != nullptr) AniS->Update();
	m_pos.y += 3;

	if (m_pos.x == 100) dir = true;
	if (m_pos.x == 1500) dir = false;

	if (dir) dirv = Vec2(1, 0);
	if (!dir) dirv = Vec2(-1, 0);

	if (fire)
	{
		AS = new cTimer(1.5, [&]()->void {fire = true; AS = nullptr; });
		m_bullet.push_back(new cMBullet(m_pos, dirv, m_damage));
		fire = false;
	}
}

void cTaggari::Render()
{
	RENDER->CenterRender(m_ani[frame], m_pos);
}

void cTaggari::UIRender()
{
}
