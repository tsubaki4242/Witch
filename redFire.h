#pragma once
#include "enemy.h"
class redFire : public enemy
{
public:
	redFire() {};
	~redFire() {};

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