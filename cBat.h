#pragma once
#include "cMob.h"
class cBat :
	public cMob
{
public:
	cBat(Vec2 pos, cPlayer* player, vector<cBullet*>& bullet);
	virtual ~cBat();

	cTimer* AniS = nullptr;
	cTimer* AS = nullptr;
	vector<cTexture*> m_ani;
	vector<cBullet*>& m_bullet;
	int frame = 0;
	bool fire = true;
	int count = 0;
	bool dir;

	// cMob을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;
	virtual void UIRender() override;
};

