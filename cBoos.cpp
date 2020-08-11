#include "DXUT.h"
#include "cBoos.h"
#include "cMBullet.h"
#include "cTaggari.h"

cBoos::cBoos(Vec2 pos, cPlayer* player, vector<cBullet*>& bullet)
	:cMob(pos), m_bullet(bullet)
{
	m_player = player;
	m_hp = 2000;
	m_damage = 1;
	mobName = "boos";
	mobType = "Boss";
}

cBoos::~cBoos()
{
	SAFE_DELETE(AS);
	SAFE_DELETE(deathT);
	SAFE_DELETE(normal);
	SAFE_DELETE(pattern1T);
	SAFE_DELETE(reload);
}

void cBoos::Update()
{
	if (deathT != nullptr) deathT->Update();
	if (AS != nullptr) AS->Update();
	if (normal != nullptr && pattern1C <= 50) normal->Update();
	if (pattern1T != nullptr) pattern1T->Update();
	if (reload != nullptr) reload->Update();

	if (m_hp <= 0)
	{
		m_hp = 0;
		m_size = -1;
		ready = false;
		AS = nullptr;
		pattern = 0;
		Death();
	}

	if (pattern1C == 51)
	{
		reload = new cTimer(5, [&]()->void {pattern1C = 0; reload = nullptr; });
		pattern1C ++;
	}

	Appear();

	Ready();

	switch (pattern)
	{
	case 0:
		break;
	case 1:
		Pattern1();
		break;
	case 2:
		Pattern2();
		break;
	case 3:
		Pattern3();
		break;
	default:
		break;
	}
	//m_hp -= 15;
}

void cBoos::Render()
{
	RENDER->CenterRender(IMAGE->FindImage("mob_boos"), m_pos, RenderSize);
}

void cBoos::UIRender()
{
	UI->CenterRender(IMAGE->FindImage("fuel_bg"), Vec2(WINSIZEX / 2 + 200, 20));
	RECT hprc = {
		0,
		0,
		((float)IMAGE->FindImage("bosshp")->info.Width / 2000) * m_hp,
		IMAGE->FindImage("bosshp")->info.Height
	};
	UI->CropRender(IMAGE->FindImage("bosshp"), Vec2(WINSIZEX / 2 + 200, 20), hprc);
}

void cBoos::Appear()
{
	if (appear)
	{
		if (m_pos.y <= 200 && appearmove)
		{
			m_pos.y += 300 * Delta;
		}
		else appearmove = false;
		if (!appearmove && RenderSize < 1)
		{
			RenderSize += 0.005;
			m_size = 150;
		}
		else if (!appearmove && RenderSize >= 1) { 
			RenderSize = 1; 
			ready = true; 
			appear = false; 
			normal = new cTimer(0.4, [&]()->void {
				pattern1C++;
				m_bullet.push_back(new cMBullet(m_pos + Vec2(-75, 150), Vec2(0, 1), m_damage));
				m_bullet.push_back(new cMBullet(m_pos + Vec2(87, 150), Vec2(0, 1), m_damage));
			}, 1);
		}
	}
}

void cBoos::Pattern1()
{
	if (pattern1)
	{
		pattern1T = new cTimer(2, [&]()->void { ready = true;  pattern1T = nullptr; });
		pattern1 = false;
	}
}

void cBoos::Pattern2()
{
	if (pattern2)
	{

	}
}

void cBoos::Pattern3()
{
	if (pattern3)
	{

	}
}

void cBoos::Death()
{
	if (b_effect)
	{
		b_effect = false;
		deathT = new cTimer(0.25, [&]()->void
		{
			Vec2 randPos = { (float)(rand() % 400 - 200), (float)(rand() % 400 - 200) };
			PART->AddParticle(m_pos + randPos, 2);
			count++;
			if (count == 20)
			{
				PART->AddParticle(m_pos, 10);
				isDestroy = true;
			}
		}, 1);
	}
}

void cBoos::Ready()
{
	if (ready)
	{
		if (b_3setPos)
		{
			movePos = rand() % 710 + 605;
			b_3setPos = false;
		}
		if (movePos > m_pos.x && b_move)
		{
			D3DXVec2Lerp(&m_pos, &m_pos, &Vec2(movePos + 10, m_pos.y), 0.04);
			if (movePos <= m_pos.x)
			{
				b_move = false;
				ready = false;
			}
		}
		else if (movePos < m_pos.x && b_move)
		{
			D3DXVec2Lerp(&m_pos, &m_pos, &Vec2(movePos - 10, m_pos.y), 0.04);
			if (movePos >= m_pos.x)
			{
				b_move = false;
				ready = false;
			}
		}
		if(!b_move)
		{
			ready = false;
			b_move = true;
			pattern = 0;
			AS = new cTimer(0.5, [&]()->void {
				pattern = 1;//rand() % 3 + 1;
				if (pattern == 1) pattern1 = true;
				if (pattern == 2) pattern2 = true;
				if (pattern == 3) pattern3 = true;
				b_3setPos = true;
				AS = nullptr;
			});
		}
	}
}
