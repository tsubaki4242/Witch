#include "stdafx.h"
#include "title.h"

HRESULT title::init()
{
	IMAGEMANAGER->addImage("배경2", "background2.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("타이틀", "titlefile/타이틀.bmp", 656, 114, true, RGB(254, 254, 254));
	IMAGEMANAGER->addImage("타이틀2", "titlefile/마법진.bmp", 471, 473, true, RGB(250, 250, 250));
	IMAGEMANAGER->addImage("타이틀3", "num/코인.bmp", 130, 30, true, RGB(24, 24, 24));
	IMAGEMANAGER->addImage("타이틀4", "num/플리즈.bmp", 435, 50, true, RGB(24, 24, 24));
	titleImg = IMAGEMANAGER->findImage("타이틀");
	titleImg2 = IMAGEMANAGER->findImage("타이틀2");
	backGround = IMAGEMANAGER->findImage("배경2");
	coinImg = IMAGEMANAGER->findImage("타이틀3");
	please = IMAGEMANAGER->findImage("타이틀4");
	_alphaValue = 255;
	char strNum[100];
	for (int i = 0; i < 10; i++)
	{
		coinNum[i] = new image;
		sprintf_s(strNum, "num/%d.bmp", i);
		coinNum[i]->init(strNum, 20, 23, true, RGB(24, 24, 24));
	}
	coin = 0;
	magic = false;

	_UI = new UI;
	_UI->init();

	return S_OK;
}

void title::release()
{
}

void title::update()
{
	_UI->update();
	if (!magic)
	{
		_alphaValue -= 5;
	}
	else
	{
		_alphaValue += 5;
	}
	if (_alphaValue <= 0) magic = true;
	if (_alphaValue >= 255) magic = false;
}

void title::render()
{
	backGround->render(getMemDC(), 0, 0);
	titleImg2->alphaRender(getMemDC(), WINSIZEX / 2 - 234, 20, _alphaValue);
	titleImg->render(getMemDC(), WINSIZEX/2 -328, 200);
	please->alphaRender(getMemDC(), WINSIZEX / 2 - 218, 500, _alphaValue);
	_UI->render();

}


