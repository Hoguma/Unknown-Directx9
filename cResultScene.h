#pragma once
#include "cScene.h"
class cResultScene :
	public cScene
{
public:
	cResultScene();
	virtual ~cResultScene();

	// cScene��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void UIRender() override;
	virtual void Release() override;
};

