#pragma once
#include "enemy.h"
class blueFire : public enemy
{
public:
	blueFire() {};
	~blueFire() {};

	virtual HRESULT init();
	virtual HRESULT init(const char* imageName, POINT position);
	virtual void release();
	virtual void update();
	virtual void render();

	void move();
	void draw();

	bool bulletCountFire();
	bool itemCountFire();
};