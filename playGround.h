#pragma once
#include "gameNode.h"
#include "title.h"
#include "Scene1.h"

class playGround : public gameNode
{
private:





public:
	playGround();
	~playGround();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	
};

