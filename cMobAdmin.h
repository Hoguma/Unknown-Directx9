#pragma once
#include "cMob.h"
#include "cPlayer.h"
#include "cBullet.h"
class cMobAdmin
{
public:
	cMobAdmin(cPlayer* player, vector<cBullet*>& bullet);
	~cMobAdmin();

	vector<cMob*> m_mobs;

	cPlayer* m_player;
	vector<cBullet*>& m_bullet;

	cTimer* BatT = nullptr;
	bool Bat = true;
	cTimer* BalT = nullptr;
	bool Bal = true;
	cTimer* TaT = nullptr;
	bool Ta = true;

	bool boss = true;
	bool bossD = false;

	void Update();
	void Render();
	void UIRender();

	void CreateMob();
	void IsOut();
	void IsDestroy();
};

