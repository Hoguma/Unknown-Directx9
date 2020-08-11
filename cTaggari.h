#pragma once
#include "cMob.h"
class cTaggari :
	public cMob
{
public:
	cTaggari(Vec2 pos, cPlayer* player, vector<cBullet*>& bullet);
	virtual ~cTaggari();

	cTimer* AS = nullptr;
	cTimer* AniS = nullptr;
	vector<cBullet*>& m_bullet;
	vector<cTexture*> m_ani;
	int frame = 0;
	bool fire = true;
	int count = 0;
	bool dir;

	Vec2 dirv;

	// cMob을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;
	virtual void UIRender() override;
};

