#pragma once
#include "cBullet.h"
#include "cPlayer.h"
class cMHBullet :
	public cBullet
{
public:
	cMHBullet(Vec2 pos, cPlayer* player, float damage);
	virtual ~cMHBullet();
	float m_speed;
	cPlayer* m_player;
	cTimer* time = nullptr;
	bool homing = 1;

	// cBullet을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;
};

