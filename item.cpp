#include "stdafx.h"
#include "item.h"

HRESULT item::init(int itemMAX, float range)
{
	_bulletMax = itemMAX;
	_range = range;

	return S_OK;
}

void item::release()
{
}

void item::update()
{
	
}

void item::render()
{
	for (_viitem = _vitem.begin(); _viitem != _vitem.end(); ++_viitem)
	{
		_viitem->itemImage->frameRender(getMemDC(),
			_viitem->rc.left,
			_viitem->rc.top,
			_viitem->itemImage->getFrameX(), 0);

		_viitem->count++;

		if (_viitem->count % 5 == 0)
		{
			_viitem->itemImage->setFrameX(_viitem->itemImage->getFrameX() + 1);

			//최대 프레임보다 커지면
			if (_viitem->itemImage->getFrameX() >= _viitem->itemImage->getMaxFrameX())
			{
				_viitem->itemImage->setFrameX(0);
			}

			_viitem->count = 0;
		}
	}
}

void item::setitem(float x, float y)
{
	if (_bulletMax < _vitem.size()) return;

	tagItem Item;
	ZeroMemory(&Item, sizeof(tagItem));

	Item.itemImage = new image;
	Item.itemImage->init("item/100점.bmp", 0, 0, 144, 32, 4, 1, true, RGB(255, 0, 255));
	Item.speed = 20.0f;
	Item.x = Item.fireX = x;
	Item.y = Item.fireY = y;
	Item.rc = RectMakeCenter(Item.x, Item.y,
		Item.itemImage->getFrameWidth(),
		Item.itemImage->getFrameHeight());

	_vitem.push_back(Item);
}

void item::move()
{
}

void item::removeitem(int arrNum)
{
	_vitem[arrNum].itemImage->release();
	_vitem.erase(_vitem.begin() + arrNum);
}

HRESULT item2::init(int itemMAX, float range)
{
	_bulletMax = itemMAX;
	_range = range;

	return S_OK;
}

void item2::release()
{
}

void item2::update()
{

}

void item2::render()
{
	for (_viitem = _vitem.begin(); _viitem != _vitem.end(); ++_viitem)
	{
		_viitem->itemImage->frameRender(getMemDC(),
			_viitem->rc.left,
			_viitem->rc.top,
			_viitem->itemImage->getFrameX(), 0);

		_viitem->count++;

		if (_viitem->count % 5 == 0)
		{
			_viitem->itemImage->setFrameX(_viitem->itemImage->getFrameX() + 1);

			//최대 프레임보다 커지면
			if (_viitem->itemImage->getFrameX() >= _viitem->itemImage->getMaxFrameX())
			{
				_viitem->itemImage->setFrameX(0);
			}

			_viitem->count = 0;
		}
	}
}

void item2::setitem(float x, float y)
{
	if (_bulletMax < _vitem.size()) return;

	tagItem Item;
	ZeroMemory(&Item, sizeof(tagItem));

	Item.itemImage = new image;
	Item.itemImage->init("item/200점.bmp", 0, 0, 144, 32, 4, 1, true, RGB(255, 0, 255));
	Item.speed = 20.0f;
	Item.x = Item.fireX = x;
	Item.y = Item.fireY = y;
	Item.rc = RectMakeCenter(Item.x, Item.y,
		Item.itemImage->getFrameWidth(),
		Item.itemImage->getFrameHeight());

	_vitem.push_back(Item);
}

void item2::move()
{
}

void item2::removeitem(int arrNum)
{
	_vitem[arrNum].itemImage->release();
	_vitem.erase(_vitem.begin() + arrNum);
}

//============================================================

HRESULT SOUL::init(int itemMAX, float range)
{
	_bulletMax = itemMAX;
	_range = range;
	Bswitch = false;

	return S_OK;
}

void SOUL::release()
{
}

void SOUL::update()
{
	if (Bswitch)
	{
		_timer++;
		move2();
		if (_timer > 20)
		{
			Bswitch = false;
			_timer = 0;
		}
	}
	else
	{
		move();
	}
}

void SOUL::render()
{
	for (_viitem = _vitem.begin(); _viitem != _vitem.end(); ++_viitem)
	{
		_viitem->itemImage->frameRender(getMemDC(),
			_viitem->rc.left,
			_viitem->rc.top,
			_viitem->itemImage->getFrameX(), 0);

		_viitem->count++;

		if (_viitem->count % 5 == 0)
		{
			_viitem->itemImage->setFrameX(_viitem->itemImage->getFrameX() + 1);

			//최대 프레임보다 커지면
			if (_viitem->itemImage->getFrameX() >= _viitem->itemImage->getMaxFrameX())
			{
				_viitem->itemImage->setFrameX(0);
			}

			_viitem->count = 0;
		}
	}
}

void SOUL::setitem(float x, float y)
{
	if (_bulletMax < _vitem.size()) return;

	tagItem Item;
	ZeroMemory(&Item, sizeof(tagItem));

	Item.itemImage = new image;
	Item.itemImage->init("item/bell.bmp", 0, 0, 468, 72, 8, 1, true, RGB(255, 0, 255));
	Item.speed = 20.0f;
	Item.x = Item.fireX = x;
	Item.y = Item.fireY = y;
	Item.rc = RectMakeCenter(Item.x, Item.y,
		Item.itemImage->getFrameWidth(),
		Item.itemImage->getFrameHeight());

	_vitem.push_back(Item);
}

void SOUL::move()
{
	for (_viitem = _vitem.begin(); _viitem != _vitem.end();)
	{
		_viitem->x --;
		_viitem->rc = RectMakeCenter(_viitem->x, _viitem->y,
			_viitem->itemImage->getFrameWidth(),
			_viitem->itemImage->getFrameHeight());

		//사거리보다 더 멀리 나가면(?)
		if (_range < getDistance(_viitem->x, _viitem->y, _viitem->fireX, _viitem->fireY))
		{

			SAFE_RELEASE(_viitem->itemImage);
			SAFE_DELETE(_viitem->itemImage);
			_viitem = _vitem.erase(_viitem);



		}
		else ++_viitem;

	}
}

void SOUL::move2()
{
	for (_viitem = _vitem.begin(); _viitem != _vitem.end();)
	{
		_viitem->x += 5;
		_viitem->rc = RectMakeCenter(_viitem->x, _viitem->y,
			_viitem->itemImage->getFrameWidth(),
			_viitem->itemImage->getFrameHeight());

		//사거리보다 더 멀리 나가면(?)
		if (_range < getDistance(_viitem->x, _viitem->y, _viitem->fireX, _viitem->fireY))
		{

			SAFE_RELEASE(_viitem->itemImage);
			SAFE_DELETE(_viitem->itemImage);
			_viitem = _vitem.erase(_viitem);



		}
		else ++_viitem;

	}
}

void SOUL::moveateck()
{

	Bswitch = true;


}

void SOUL::removeitem(int arrNum)
{
	_vitem[arrNum].itemImage->release();
	_vitem.erase(_vitem.begin() + arrNum);
}

//=================================================

HRESULT SOUL1::init(int itemMAX, float range)
{
	_bulletMax = itemMAX;
	_range = range;
	Bswitch = false;
	return S_OK;
}

void SOUL1::release()
{
}

void SOUL1::update()
{
	if (Bswitch)
	{
		_timer++;
		move2();
		if (_timer > 20)
		{
			Bswitch = false;
			_timer = 0;
		}
	}
	else
	{
		move();
	}
}

void SOUL1::render()
{
	for (_viitem = _vitem.begin(); _viitem != _vitem.end(); ++_viitem)
	{
		_viitem->itemImage->frameRender(getMemDC(),
			_viitem->rc.left,
			_viitem->rc.top,
			_viitem->itemImage->getFrameX(), 0);

		_viitem->count++;

		if (_viitem->count % 5 == 0)
		{
			_viitem->itemImage->setFrameX(_viitem->itemImage->getFrameX() + 1);

			//최대 프레임보다 커지면
			if (_viitem->itemImage->getFrameX() >= _viitem->itemImage->getMaxFrameX())
			{
				_viitem->itemImage->setFrameX(0);
			}

			_viitem->count = 0;
		}
	}
}

void SOUL1::setitem(float x, float y)
{
	if (_bulletMax < _vitem.size()) return;

	tagItem Item;
	ZeroMemory(&Item, sizeof(tagItem));

	Item.itemImage = new image;
	Item.itemImage->init("item/bell1.bmp", 0, 0, 468, 72, 8, 1, true, RGB(255, 0, 255));
	Item.speed = 20.0f;
	Item.x = Item.fireX = x;
	Item.y = Item.fireY = y;
	Item.rc = RectMakeCenter(Item.x, Item.y,
		Item.itemImage->getFrameWidth(),
		Item.itemImage->getFrameHeight());

	_vitem.push_back(Item);
}

void SOUL1::move()
{
	for (_viitem = _vitem.begin(); _viitem != _vitem.end();)
	{
		_viitem->x--;
		_viitem->rc = RectMakeCenter(_viitem->x, _viitem->y,
			_viitem->itemImage->getFrameWidth(),
			_viitem->itemImage->getFrameHeight());

		//사거리보다 더 멀리 나가면(?)
		if (_range < getDistance(_viitem->x, _viitem->y, _viitem->fireX, _viitem->fireY))
		{

			SAFE_RELEASE(_viitem->itemImage);
			SAFE_DELETE(_viitem->itemImage);
			_viitem = _vitem.erase(_viitem);



		}
		else ++_viitem;

	}
}

void SOUL1::move2()
{
	for (_viitem = _vitem.begin(); _viitem != _vitem.end();)
	{
		_viitem->x += 5;
		_viitem->rc = RectMakeCenter(_viitem->x, _viitem->y,
			_viitem->itemImage->getFrameWidth(),
			_viitem->itemImage->getFrameHeight());

		//사거리보다 더 멀리 나가면(?)
		if (_range < getDistance(_viitem->x, _viitem->y, _viitem->fireX, _viitem->fireY))
		{

			SAFE_RELEASE(_viitem->itemImage);
			SAFE_DELETE(_viitem->itemImage);
			_viitem = _vitem.erase(_viitem);



		}
		else ++_viitem;

	}
}

void SOUL1::moveateck()
{
	Bswitch = true;
}

void SOUL1::removeitem(int arrNum)
{
	_vitem[arrNum].itemImage->release();
	_vitem.erase(_vitem.begin() + arrNum);
}

////======================================================
HRESULT SOUL2::init(int itemMAX, float range)
{
	_bulletMax = itemMAX;
	_range = range;
	Bswitch = false;
	return S_OK;
}

void SOUL2::release()
{
}

void SOUL2::update()
{
	if (Bswitch)
	{
		_timer++;
		move2();
		if (_timer > 20)
		{
			Bswitch = false;
			_timer = 0;
		}
	}
	else
	{
		move();
	}
}

void SOUL2::render()
{
	for (_viitem = _vitem.begin(); _viitem != _vitem.end(); ++_viitem)
	{
		_viitem->itemImage->frameRender(getMemDC(),
			_viitem->rc.left,
			_viitem->rc.top,
			_viitem->itemImage->getFrameX(), 0);

		_viitem->count++;

		if (_viitem->count % 5 == 0)
		{
			_viitem->itemImage->setFrameX(_viitem->itemImage->getFrameX() + 1);

			//최대 프레임보다 커지면
			if (_viitem->itemImage->getFrameX() >= _viitem->itemImage->getMaxFrameX())
			{
				_viitem->itemImage->setFrameX(0);
			}

			_viitem->count = 0;
		}
	}
}

void SOUL2::setitem(float x, float y)
{
	if (_bulletMax < _vitem.size()) return;

	tagItem Item;
	ZeroMemory(&Item, sizeof(tagItem));

	Item.itemImage = new image;
	Item.itemImage->init("item/bell2.bmp", 0, 0, 468, 72, 8, 1, true, RGB(255, 0, 255));
	Item.speed = 20.0f;
	Item.x = Item.fireX = x;
	Item.y = Item.fireY = y;
	Item.rc = RectMakeCenter(Item.x, Item.y,
		Item.itemImage->getFrameWidth(),
		Item.itemImage->getFrameHeight());

	_vitem.push_back(Item);
}

void SOUL2::move()
{
	for (_viitem = _vitem.begin(); _viitem != _vitem.end();)
	{
		_viitem->x--;
		_viitem->rc = RectMakeCenter(_viitem->x, _viitem->y,
			_viitem->itemImage->getFrameWidth(),
			_viitem->itemImage->getFrameHeight());

		//사거리보다 더 멀리 나가면(?)
		if (_range < getDistance(_viitem->x, _viitem->y, _viitem->fireX, _viitem->fireY))
		{

			SAFE_RELEASE(_viitem->itemImage);
			SAFE_DELETE(_viitem->itemImage);
			_viitem = _vitem.erase(_viitem);



		}
		else ++_viitem;

	}
}

void SOUL2::move2()
{
	for (_viitem = _vitem.begin(); _viitem != _vitem.end();)
	{
		_viitem->x += 5;
		_viitem->rc = RectMakeCenter(_viitem->x, _viitem->y,
			_viitem->itemImage->getFrameWidth(),
			_viitem->itemImage->getFrameHeight());

		//사거리보다 더 멀리 나가면(?)
		if (_range < getDistance(_viitem->x, _viitem->y, _viitem->fireX, _viitem->fireY))
		{

			SAFE_RELEASE(_viitem->itemImage);
			SAFE_DELETE(_viitem->itemImage);
			_viitem = _vitem.erase(_viitem);



		}
		else ++_viitem;

	}
}

void SOUL2::moveateck()
{
	Bswitch = true;
}

void SOUL2::removeitem(int arrNum)
{
	_vitem[arrNum].itemImage->release();
	_vitem.erase(_vitem.begin() + arrNum);
}