#include "stdafx.h"
#include "blueFire.h"

HRESULT blueFire::init()
{
	enemy::init();
	return S_OK;
}

HRESULT blueFire::init(const char * imageName, POINT position)
{
	enemy::init(imageName, position);
	return S_OK;
}

void blueFire::release()
{
	enemy::release();
}

void blueFire::update()
{
	enemy::update();
}

void blueFire::render()
{
	enemy::render();
}

void blueFire::move()
{
	_rc.left--;
	_rc.right--;
}

void blueFire::draw()
{
	enemy::draw();
}

bool blueFire::bulletCountFire()
{





		return false;

}

bool blueFire::itemCountFire()
{
	return false;
}
