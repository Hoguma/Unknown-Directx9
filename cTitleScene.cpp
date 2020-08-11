#include "DXUT.h"
#include "cTitleScene.h"

cTitleScene::cTitleScene()
{
}

cTitleScene::~cTitleScene()
{
}

void cTitleScene::Init()
{
	SCENE->PlayerInit();
	SCENE->mobcount = 0;
}

void cTitleScene::Update()
{
	if (option == false)
	{
		if (INPUT->KeyDown(VK_LEFT) && select > 1) { select--; }
		if (INPUT->KeyDown(VK_RIGHT) && select < 3) { select++; }
		switch (select)
		{
		case 1:
			if (INPUT->KeyDown(90))
				SCENE->ChangeScene("cIngameScene");
			break;
		case 2:
			if (INPUT->KeyDown(90))
				option = true;
			break;
		case 3:
			if (INPUT->KeyDown(90))
				exit(0);
			break;
		default:
			break;
		}
	}
	else
	{
		if (INPUT->KeyDown(VK_DOWN) && optionS < 2) { optionS++; }
		if (INPUT->KeyDown(VK_UP) && optionS > 1) { optionS--; }
	}
}

void cTitleScene::Render()
{
	RENDER->CenterRender(IMAGE->FindImage("Main"), Vec2(WINSIZEX / 2, WINSIZEY / 2));
	RENDER->CenterRender(IMAGE->FindImage("main_ui_unknown"), Vec2(WINSIZEX / 2, 200));
}

void cTitleScene::UIRender()
{
	if (select == 1)
		UI->CenterRender(IMAGE->FindImage("main_ui_start_d"), Vec2(270, 800));
	else
		UI->CenterRender(IMAGE->FindImage("main_ui_start"), Vec2(270, 800));
	if (select == 2)
		UI->CenterRender(IMAGE->FindImage("main_ui_option_d"), Vec2(800, 800));
	else
		UI->CenterRender(IMAGE->FindImage("main_ui_option"), Vec2(800, 800));
	if (select == 3)
		UI->CenterRender(IMAGE->FindImage("main_ui_exit_d"), Vec2(1330, 800));
	else
		UI->CenterRender(IMAGE->FindImage("main_ui_exit"), Vec2(1330, 800));

	if (option)
	{
		UI->CenterRender(IMAGE->FindImage("option_background"), Vec2(WINSIZEX / 2, WINSIZEY / 2));
		switch (optionS)
		{
		case 1:
			UI->CenterRender(IMAGE->FindImage("credit_button"), Vec2(400, 188));
			UI->CenterRender(IMAGE->FindImage("option_win"), Vec2(WINSIZEX/2, WINSIZEY/2));
			UI->CenterRender(IMAGE->FindImage("window_s"), Vec2(1115, 412));
			UI->CenterRender(IMAGE->FindImage("sound_off"), Vec2(675, 412));
			break;
		case 2:
			UI->CenterRender(IMAGE->FindImage("option_butt"), Vec2(400, 126.7));
			UI->CenterRender(IMAGE->FindImage("credit_window"), Vec2(WINSIZEX / 2, WINSIZEY / 2));
			break;
		default:
			break;
		}
		if (INPUT->KeyDown(VK_RETURN)) option = false;
	}
}

void cTitleScene::Release()
{
}
