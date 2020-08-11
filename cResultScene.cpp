#include "DXUT.h"
#include "cResultScene.h"

cResultScene::cResultScene()
{
}

cResultScene::~cResultScene()
{
}

void cResultScene::Init()
{
}

void cResultScene::Update()
{
	if (INPUT->KeyDown(VK_RETURN))
		SCENE->ChangeScene("cTitleScene");
}

void cResultScene::Render()
{
	RENDER->CenterRender(IMAGE->FindImage("Main"), Vec2(WINSIZEX / 2, WINSIZEY / 2));
}

void cResultScene::UIRender()
{
	if (SCENE->m_Hp <= 0 || SCENE->fuel <= 0)
		UI->PrintText("GAME OVER...", Vec2(WINSIZEX / 2 + 100, 100), 100);
	else
		UI->PrintText("GAME CLEAR!!!", Vec2(WINSIZEX / 2 + 100, 100), 100);
	UI->PrintText(to_string(SCENE->m_Score), Vec2(WINSIZEX/2, 500), 100);
}

void cResultScene::Release()
{
}
