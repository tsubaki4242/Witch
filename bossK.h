#pragma once
#include "enemy.h"



class bossK : public enemy
{
public:
	bossK() {};
	~bossK() {};

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