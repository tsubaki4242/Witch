#pragma once
#include "gameNode.h"
#include "UI.h"

class title : public gameNode
{
private:
	image* titleImg;
	image* titleImg2;
	image* backGround;
	image* please;
	image* coinImg;
	image* coinNum[10];


	UI* _UI;

	int _alphaValue;
	int coin;

	bool magic;
public:
	title() {};
	~title() {};

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();



};