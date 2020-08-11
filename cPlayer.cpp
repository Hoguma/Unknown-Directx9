#include "DXUT.h"
#include "cPlayer.h"
#include "cPBullet.h"

cPlayer::cPlayer(vector<cBullet*>& bullet)
	:m_pos(WINSIZEX / 2, 900), m_bullet(bullet)
{
	m_Hp = SCENE->m_Hp;
	m_MaxHp = SCENE->m_MaxHp;
	m_Score = SCENE->m_Score;
	fuel = SCENE->fuel;
}

cPlayer::~cPlayer()
{
	SAFE_DELETE(playerAS);
	SCENE->m_Hp = m_Hp;
	SCENE->m_MaxHp = m_MaxHp;
	SCENE->m_Score = m_Score;
	SCENE->fuel = fuel;
}

void cPlayer::Update()
{
	if (m_Hp <= 0 || fuel <= 0)
		SCENE->ChangeScene("cResultScene");
	if (playerAS) playerAS->Update();
	if (INPUT->KeyDown(VK_F1)) SCENE->mobcount = 25;
	Move();
	FireBullet();
	Fuel();
	ItemUpdate();
}

void cPlayer::Render()
{
	RENDER->CenterRender(IMAGE->FindImage("player"), m_pos);
}

void cPlayer::UIRender()
{
	UI->CenterRender(IMAGE->FindImage("hp_bg"), Vec2(243, 825.5));
	UI->CenterRender(IMAGE->FindImage("fuel_bg"), Vec2(240, 880));
	for (int i = 0; i < m_Hp; i++)
	{
		UI->CenterRender(IMAGE->FindImage("hp"), Vec2(62.5 + i * 74, 824.5));
	}
	RECT hprc = {
		0,
		0,
		((float)IMAGE->FindImage("fuel")->info.Width / 100) * fuel,
		IMAGE->FindImage("fuel")->info.Height
	};
	UI->CenterRender(IMAGE->FindImage("hp_frame"), Vec2(249.25, 825.5));
	UI->CenterRender(IMAGE->FindImage("hp_hl"), Vec2(249.25, 825.5));
	UI->CenterRender(IMAGE->FindImage("fuel_h.l"), Vec2(240, 880));
	UI->CropRender(IMAGE->FindImage("fuel"), Vec2(240, 880), hprc);
}

void cPlayer::Move()
{
	if (INPUT->KeyPress(VK_UP) && m_pos.y >= 0) { m_pos.y -= 600 * Delta; fuel -= 4 * Delta;}
	if (INPUT->KeyPress(VK_DOWN) && m_pos.y <= WINSIZEY) { m_pos.y += 600 * Delta; fuel -= 4 * Delta;}
	if (INPUT->KeyPress(VK_LEFT) && m_pos.x >= 0) {m_pos.x -= 600 * Delta;fuel -= 4 * Delta;}
	if (INPUT->KeyPress(VK_RIGHT) && m_pos.x <= WINSIZEX) { m_pos.x += 600 * Delta; fuel -= 4 * Delta;}
}

void cPlayer::FireBullet()
{
	if (INPUT->KeyPress(90) && b_fire)
	{
		m_bullet.push_back(new cPBullet(m_pos));
		playerAS = new cTimer(0.1, [&]()->void { b_fire = true; playerAS = nullptr; });
		b_fire = false;
		fuel -= 0.1;
		//SCENE->mobcount+=25;
	}
}

void cPlayer::Fuel()
{
	fuel -= 1 * Delta;
}

void cPlayer::ItemUpdate()
{
	if (m_Hp >= 6) m_Hp = 6;
	if (fuel >= 100) fuel = 100;
	if (ItemName == "Heal")
	{
		m_Hp += 2;
		ItemName = "none";
	}
	if (ItemName == "Fuel")
	{
		fuel += 50;
		ItemName = "none";
	}
}
