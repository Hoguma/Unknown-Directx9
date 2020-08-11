#pragma once
#include "cBullet.h"
class cMBullet :
	public cBullet
{
public:
	cMBullet(Vec2 pos, Vec2 dir, float damage, float size = 10, float speed = 700);
	virtual ~cMBullet();
	float m_speed;

	// cBullet을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;
};

