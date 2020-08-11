#include "DXUT.h"
#include "cFuel.h"

cFuel::cFuel(Vec2 pos)
	:cItem(pos)
{
	itemName = "Fuel";
	m_image = IMAGE->FindImage("fuel+");
}

cFuel::~cFuel()
{
}
