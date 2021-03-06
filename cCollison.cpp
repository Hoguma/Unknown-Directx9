#include "DXUT.h"
#include "cCollison.h"

cCollison::cCollison(vector<cBullet*>& bullet, vector<cMob*>& m_mob, cPlayer* player, cItemAdmin* itemAd)
	:m_bullet(bullet), m_player(player), m_mob(m_mob), m_itemAd(itemAd), m_item(m_itemAd->m_itmes)
{
}

cCollison::~cCollison()
{
}

void cCollison::Update()
{
	MPColl();
	MBPColl();
	MPBColl();
	IPColl();
}

void cCollison::MPColl()
{
	for (auto iter = m_mob.begin(); iter != m_mob.end();)
	{
		if (7 + (*iter)->m_size >= D3DXVec2Length(&(m_player->m_pos - (*iter)->m_pos)))
		{
			if (b_PMcoll)
			{
				if ((*iter)->mobType == "Boss")
					b_PMcoll = false;
				m_player->m_Hp -= (*iter)->m_damage * 3;
				if ((*iter)->mobType != "Boss")
					(*iter)->isDestroy = true;
			}
		}
		else
		{
			if ((*iter)->mobType == "Boss") b_PMcoll = true;
		}
		iter++;
	}
}

void cCollison::MPBColl()
{
	for (auto miter = m_mob.begin(); miter != m_mob.end();)
	{
		bool b_coll = false;
		for (auto biter = m_bullet.begin(); biter != m_bullet.end();)
		{
			if ((*biter)->bulletType == "player")
			{
				if ((*biter)->size + (*miter)->m_size >= D3DXVec2Length(&((*biter)->m_pos - (*miter)->m_pos)) && (*miter)->m_hp > 0)
				{
					m_player->m_Score += rand() % 50 + 50;
					(*miter)->m_hp -= 10;
					PART->AddParticle((*biter)->m_pos, 0.3);
					b_coll = true;
					(*biter)->isDestroy = true;
				}
			}
			biter++;
		}
		if (b_coll)
		{
			if ((*miter)->m_hp <= 0)
			{
				m_itemAd->mobDead = true;
				m_itemAd->mobPos = (*miter)->m_pos;
				if ((*miter)->mobType != "Boss")
					(*miter)->isDestroy = true;
			}
		}
		miter++;
	}
}

void cCollison::MBPColl()
{
	for (auto iter = m_bullet.begin(); iter != m_bullet.end();)
	{
		if ((*iter)->bulletType == "mob")
		{
			if (7 + (*iter)->size >= D3DXVec2Length(&(m_player->m_pos - (*iter)->m_pos)))
			{
				m_player->m_Hp -= (*iter)->m_Damage;
				PART->AddParticle((*iter)->m_pos, 0.3);
				(*iter)->isDestroy = true;
			}
		}
		iter++;
	}
}

void cCollison::IPColl()
{
	for (auto iter = m_item.begin(); iter != m_item.end();)
	{
		if (7 + (*iter)->m_size >= D3DXVec2Length(&(m_player->m_pos - (*iter)->m_pos)))
		{
			m_player->ItemName = (*iter)->itemName;
			(*iter)->isDestroy = true;
		}
		iter++;
	}
}
