#pragma once
#include "cMob.h"
class cBallon :
	public cMob
{
public:
	cBallon(Vec2 pos, cPlayer* player, vector<cBullet*>& bullet);
	virtual ~cBallon();

	cTimer* AS = nullptr;
	cTimer* AniS = nullptr;
	vector<cBullet*>& m_bullet;
	vector<cTexture*> m_ani;
	int frame = 0;
	bool fire = true;
	int count = 0;
	bool dir;

	// cMob을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;
	virtual void UIRender() override;
};

