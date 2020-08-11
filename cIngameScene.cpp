#include "DXUT.h"
#include "cIngameScene.h"

cIngameScene::cIngameScene()
{
	
}

cIngameScene::~cIngameScene()
{
}

void cIngameScene::Init()
{
	srand(time(NULL));
	map = new cScrollMap();
	bullet = new cBulletAdmin();
	player = new cPlayer(bullet->m_bullets);
	mob = new cMobAdmin(player, bullet->m_bullets);
	item = new cItemAdmin(player);
	coll = new cCollison(bullet->m_bullets, mob->m_mobs, player, item);
}

void cIngameScene::Update()
{
	if (SCENE->mobcount == 25)
	{
		stage = 2;
		SCENE->mobcount++;
	}
	if (mob->bossD)
	{
		SCENE->ChangeScene("cResultScene");
	}
	map->Update(50);
	player->Update();
	bullet->Update();
	mob->Update();
	coll->Update();
	item->Update();
}

void cIngameScene::Render()
{
	map->Render(stage);
	mob->Render();
	player->Render();
	bullet->Render();
	item->Render();
}

void cIngameScene::UIRender()
{
	player->UIRender();
	mob->UIRender();
	char str[20];
	sprintf(str, "%05d/", player->m_Score);
	UI->PrintText(str +to_string(stage), Vec2(150, 760), 60);
	UI->PrintText(to_string(SCENE->mobcount), Vec2(100, 800), 30);
}

void cIngameScene::Release()
{
	SAFE_DELETE(map);
	SAFE_DELETE(player);
	SAFE_DELETE(bullet);
	SAFE_DELETE(mob);
	SAFE_DELETE(coll);
	SAFE_DELETE(item);
}
