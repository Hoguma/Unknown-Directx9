#include "DXUT.h"
#include "cScrollMap.h"

cScrollMap::cScrollMap()
{

}

cScrollMap::~cScrollMap()
{
}

void cScrollMap::Update(float speed)
{
	scroll_f += speed * Delta;
	scroll_m +=( speed + 150)* Delta;
	scroll_p += (speed + 300)* Delta;
}

void cScrollMap::Render(int stage)
{
	if (stage == 1)
	{
		float renderPos_f = (int)scroll_f % IMAGE->FindImage("stage_1_BG")->info.Height;
		RENDER->CenterRender(IMAGE->FindImage("stage_1_BG"), Vec2(WINSIZEX / 2, WINSIZEY / 2 + renderPos_f - IMAGE->FindImage("stage_1_BG")->info.Height));
		RENDER->CenterRender(IMAGE->FindImage("stage_1_BG"), Vec2(WINSIZEX / 2, WINSIZEY / 2 + renderPos_f));
	}
	if (stage == 2)
	{
		float renderPos_f = (int)scroll_f % IMAGE->FindImage("stage_2_BG")->info.Height;
		RENDER->CenterRender(IMAGE->FindImage("stage_2_BG"), Vec2(WINSIZEX / 2, WINSIZEY / 2 + renderPos_f - IMAGE->FindImage("stage_2_BG")->info.Height));
		RENDER->CenterRender(IMAGE->FindImage("stage_2_BG"), Vec2(WINSIZEX / 2, WINSIZEY / 2 + renderPos_f));

		float renderPos_m = (int)scroll_m % IMAGE->FindImage("stage_2_cloud")->info.Height;
		RENDER->CenterRender(IMAGE->FindImage("stage_2_cloud"), Vec2(WINSIZEX / 2, WINSIZEY / 2 + renderPos_m - IMAGE->FindImage("stage_2_cloud")->info.Height));
		RENDER->CenterRender(IMAGE->FindImage("stage_2_cloud"), Vec2(WINSIZEX / 2, WINSIZEY / 2 + renderPos_m));

		float renderPos_p = (int)scroll_p % IMAGE->FindImage("stage_2_SkyIsland")->info.Height;
		RENDER->CenterRender(IMAGE->FindImage("stage_2_SkyIsland"), Vec2(WINSIZEX / 2, WINSIZEY / 2 + renderPos_p - IMAGE->FindImage("stage_2_SkyIsland")->info.Height));
		RENDER->CenterRender(IMAGE->FindImage("stage_2_SkyIsland"), Vec2(WINSIZEX / 2, WINSIZEY / 2 + renderPos_p));
	}
}
