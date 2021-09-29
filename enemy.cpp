#include "stdafx.h"
#include "enemy.h"

HRESULT enemy::init()
{


	return S_OK;
}

HRESULT enemy::init(const char* imageName, POINT position)
{
	_currentFrameX = _currentFrameY = 0;
	_count = _fireCount = 0;

	_rndFireCount = RND->getFromIntTo(1, 800);

	_imageName = IMAGEMANAGER->findImage(imageName);

	_rc = RectMakeCenter(position.x, position.y,
		_imageName->getFrameWidth(), _imageName->getFrameHeight());

	enemyX = position.x;
	enemyY = position.y;
	return S_OK;
}

void enemy::release()
{
}

void enemy::update()
{
	_count++;
	if (_count % 5 == 0)
	{
		if (_currentFrameX >= _imageName->getMaxFrameX()) _currentFrameX = 0;
		_imageName->setFrameX(_currentFrameX);
		_currentFrameX++;

		_count = 0;
	}

}

void enemy::render()
{
	draw();
}

void enemy::move()
{
	//_rc.left++;
	//_rc.right++;
}

void enemy::draw()
{
	_imageName->frameRender(getMemDC(), _rc.left, _rc.top, _currentFrameX, _currentFrameY);
}

//���ʹ̰� �߻��ߴٰ� ��ȣ�� �ִ� �Լ�
bool enemy::bulletCountFire()
{


		_fireCount++;

		if (_fireCount % _rndFireCount == 0)
		{

			_rndFireCount = RND->getFromIntTo(1, 800);
			_fireCount = 0;

			return true;
		}

		return false;
	
}

bool enemy::itemCountFire()
{



	return false;
}
