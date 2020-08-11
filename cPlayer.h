#pragma once
#include "cBullet.h"
class cPlayer
{
public:
	Vec2 m_pos;
	vector<cBullet*>& m_bullet;
	cTimer* playerAS = nullptr;

	bool b_fire = true;

	float fuel;
	float m_Hp;
	float m_MaxHp;
	int m_Score;

	string ItemName;

	cPlayer(vector<cBullet*>& bullet);
	~cPlayer();

	void Update();
	void Render();
	void UIRender();

	void Move();
	void FireBullet();
	void Fuel();
	void ItemUpdate();
};

