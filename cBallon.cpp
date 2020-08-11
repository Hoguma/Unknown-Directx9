#include "DXUT.h"
#include "cBallon.h"
#include "cMHBullet.h"
#include "cMBullet.h"

cBallon::cBallon(Vec2 pos, cPlayer* player, vector<cBullet*>& bullet)
	: cMob(pos), m_bullet(bullet)
{
	m_ani = IMAGE->MakeVecImg("mob_2");
	m_player = player;
	m_hp = 20;
	m_damage = 1;
	m_size = 20;
	mobName = "Ballon";
	mobType = "none";
	AniS = new cTimer(0.02, [&]()->void {
		frame++;
		if (frame == m_ani.size())
			frame = 0;
	}, 1);
}

cBallon::~cBallon()
{
	SAFE_DELETE(AS);
	SAFE_DELETE(AniS);
}

void cBallon::Update()
{
	if (AS != nullptr) AS->Update();
	if (AniS != nullptr) AniS->Update();
	m_pos.y += 3;

	if (fire)
	{
		Vec2 pos;
		D3DXVec2Normalize(&pos, &(m_player->m_pos - m_pos));
		AS = new cTimer(1.5, [&]()->void {fire = true; AS = nullptr; });
		m_bullet.push_back(new cMBullet(m_pos, pos, m_damage));
		fire = false;
	}
}

void cBallon::Render()
{
	RENDER->CenterRender(m_ani[frame], m_pos);
}

void cBallon::UIRender()
{
}
