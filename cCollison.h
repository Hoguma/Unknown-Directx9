#pragma once
#include "cBullet.h"
#include "cPlayer.h"
#include "cItemAdmin.h"
#include "cItem.h"
#include "cMob.h"
class cCollison
{
public:
	cCollison(vector<cBullet*>& bullet, vector<cMob*>& m_mob, cPlayer* player, cItemAdmin* itemAd);
	~cCollison();

	vector<cBullet*>& m_bullet;
	vector<cMob*>& m_mob;
	cPlayer* m_player;
	cItemAdmin* m_itemAd;
	vector<cItem*>& m_item;

	bool b_PMcoll = true;

	void Update();

	void MPColl();
	void MPBColl();
	void MBPColl();
	void IPColl();
};

