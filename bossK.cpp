#include "stdafx.h"
#include "bossK.h"

HRESULT bossK::init()
{
	enemy::init();
	return S_OK;
}

HRESULT bossK::init(const char * imageName, POINT position)
{
	enemy::init(imageName, position);
	return S_OK;
}

void bossK::release()
{
	enemy::release();
}

void bossK::update()
{
	enemy::update();
}

void bossK::render()
{
	enemy::render();
}

void bossK::move()
{
}

void bossK::draw()
{
	enemy::draw();
}

bool bossK::bulletCountFire()
{
	_fireCount++;

	if (_fireCount % _rndFireCount == 0)
	{

		_rndFireCount = RND->getFromIntTo(1, 100);
		_fireCount = 0;

		return true;
	}

	return false;
}

bool bossK::itemCountFire()
{
	return false;
}
