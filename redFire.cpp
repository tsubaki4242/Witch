#include "stdafx.h"
#include "redFire.h"

HRESULT redFire::init()
{
	enemy::init();
	return S_OK;
}

HRESULT redFire::init(const char * imageName, POINT position)
{
	enemy::init(imageName, position);
	return S_OK;
}

void redFire::release()
{
	enemy::release();
}

void redFire::update()
{
	enemy::update();
}

void redFire::render()
{
	enemy::render();
}

void redFire::move()
{
	_rc.left-=2;
	_rc.right-=2;
}

void redFire::draw()
{
	enemy::draw();
}

bool redFire::bulletCountFire()
{
	return false;
}

bool redFire::itemCountFire()
{
	return false;
}
