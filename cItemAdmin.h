#pragma once
#include "cPlayer.h"
#include "cItem.h"
class cItemAdmin
{
public:
	cItemAdmin(cPlayer* player);
	~cItemAdmin();

	vector<cItem*> m_itmes;

	cPlayer* m_player;
	float CreatePercent;
	bool mobDead = false;
	Vec2 mobPos;

	void Update();
	void Render();
	void CreateItem();
	void IsOut();
	void IsDestroy();
};

