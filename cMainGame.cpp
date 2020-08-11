#include "DXUT.h"
#include "cMainGame.h"
#include "cIngameScene.h"
#include "cTitleScene.h"
#include "cResultScene.h"

cMainGame::cMainGame()
{
}

cMainGame::~cMainGame()
{
}

void cMainGame::Init()
{
	AddResource();
	SCENE->AddScene("cIngameScene", new cIngameScene);
	SCENE->AddScene("cTitleScene", new cTitleScene);
	SCENE->AddScene("cResultScene", new cResultScene);
	SCENE->ChangeScene("cTitleScene");
}

void cMainGame::Update()
{
	INPUT->Update();
	SCENE->Update();
	PART->Update();
}

void cMainGame::Render()
{
	SCENE->Render();
	PART->Render();
	UI->Begin();
	SCENE->UIRender();
	UI->End();
}

void cMainGame::Release()
{
	cImageManger::ReleaseInstance();
	cInputManager::ReleaseInstance();
	cUIManager::ReleaseInstance();
	cSceneManager::ReleaseInstance();
	cRenderManager::ReleaseInstance();
	cParticleManager::ReleaseInstance();
}

void cMainGame::LostDevice()
{
	UI->Lost();
}

void cMainGame::ResetDevice()
{
	UI->Reset();
}

void cMainGame::AddResource()
{
	IMAGE->AddImage("stage_1_BG", "stage_1_BG");
	IMAGE->AddImage("stage_2_BG", "stage_2_BG");
	IMAGE->AddImage("stage_2_cloud", "stage_2_cloud");
	IMAGE->AddImage("stage_2_SkyIsland", "stage_2_SkyIsland");
	IMAGE->AddImage("player", "player");
	IMAGE->AddImage("effect_round_player", "effect_round_player");
	IMAGE->AddImage("effect_round_red", "effect_round_red");
	IMAGE->AddImage("fuel", "fuel");
	IMAGE->AddImage("fuel_bg", "fuel_bg");
	IMAGE->AddImage("fuel_h.l", "fuel_h.l");
	IMAGE->AddImage("hp", "hp");
	IMAGE->AddImage("hp_bg", "hp_bg");
	IMAGE->AddImage("hp_frame", "hp_frame");
	IMAGE->AddImage("hp_hl", "hp_hl");
	IMAGE->AddImage("mob_boos", "mob_boos");
	IMAGE->AddImage("bosshp", "bosshp");
	IMAGE->AddImage("main_ui_start", "main_ui_start");
	IMAGE->AddImage("main_ui_start_d", "main_ui_start_d");
	IMAGE->AddImage("main_ui_option", "main_ui_option");
	IMAGE->AddImage("main_ui_option_d", "main_ui_option_d");
	IMAGE->AddImage("main_ui_exit", "main_ui_exit");
	IMAGE->AddImage("main_ui_exit_d", "main_ui_exit_d");
	IMAGE->AddImage("main_ui_unknown", "main_ui_unknown");
	IMAGE->AddImage("Main", "Main");
	IMAGE->AddImage("hp+", "hp+");
	IMAGE->AddImage("fuel+", "fuel+");
	IMAGE->AddImage("guided_bullets", "guided_bullets");
	IMAGE->AddImage("option_win", "option_win");
	IMAGE->AddImage("credit_window", "credit_window");
	IMAGE->AddImage("option_background", "option_background");
	IMAGE->AddImage("option_butt", "option_butt");
	IMAGE->AddImage("credit_button", "credit_button");
	IMAGE->AddImage("sound_off", "sound_off");
	IMAGE->AddImage("window_s", "window_s");

	IMAGE->AddImage("mob_1", "mob1/mob_1", 5);
	IMAGE->AddImage("mob_2", "mob2/mob_2", 5);
	IMAGE->AddImage("expl", "explosion/expl", 5);
}
