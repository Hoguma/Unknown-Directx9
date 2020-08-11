#pragma once

#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <time.h>
#include <math.h>

#define g_device DXUTGetD3D9Device()
#define Delta DXUTGetElapsedTime()

using namespace std;

using Vec2 = D3DXVECTOR2;
using Vec3 = D3DXVECTOR3;

const int WINSIZEX = 1600;
const int WINSIZEY = 900;

#include "cTexture.h"
#include "cScene.h"
#include "cTimer.h"
#include "cParticle.h"

#include "cImageManger.h"
#include "cSceneManager.h"
#include "cUIManager.h"
#include "cRenderManager.h"
#include "cInputManager.h"
#include "cParticleManager.h"