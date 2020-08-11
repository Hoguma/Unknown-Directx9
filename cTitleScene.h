#pragma once
#include "cScene.h"
class cTitleScene :
	public cScene
{
public:
	int select = 1;
	int optionS = 1;
	bool option = 0;

	cTitleScene();
	virtual ~cTitleScene();
	// cScene을(를) 통해 상속됨
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void UIRender() override;
	virtual void Release() override;
};

