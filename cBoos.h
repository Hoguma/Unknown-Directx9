#pragma once
#include "cMob.h"
class cBoos :
	public cMob
{
public:
	cBoos(Vec2 pos, cPlayer* player, vector<cBullet*>& bullet);
	virtual ~cBoos();

	vector<cBullet*>& m_bullet;

	int pattern = 0;

	int pattern1C = 0;

	bool pattern1 = 0;
	bool pattern2 = 0;
	bool pattern3 = 0;

	bool b_effect = 1;

	bool ready = false;
	bool appearmove = true;

	bool appear = 1;

	bool b_3move = true;
	bool b_3setPos = true;
	bool b_move = true;
	float movePos;

	int count = 0;

	float RenderSize = 0.25;

	cTimer* deathT = nullptr;
	cTimer* AS = nullptr;
	cTimer* pattern1T = nullptr;
	cTimer* normal = nullptr;
	cTimer* reload = nullptr;

	// cMob을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;
	virtual void UIRender() override;

	void Appear();
	void Pattern1();
	void Pattern2();
	void Pattern3();
	void Death();
	void Ready();
};

