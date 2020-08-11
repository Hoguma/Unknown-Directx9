#pragma once
#include "cScene.h"
#include "cScrollMap.h"
#include "cPlayer.h"
#include "cBulletAdmin.h"
#include "cMobAdmin.h"
#include "cCollison.h"
#include "cItemAdmin.h"
class cIngameScene :
	public cScene
{
	cScrollMap* map = nullptr;
	cPlayer* player = nullptr;
	cBulletAdmin* bullet = nullptr;
	cMobAdmin* mob = nullptr;
	cCollison* coll = nullptr;
	cItemAdmin* item = nullptr;

	int stage = 1;
public:
	cIngameScene();
	virtual ~cIngameScene();

	// cScene을(를) 통해 상속됨
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void UIRender() override;
	virtual void Release() override;
};

