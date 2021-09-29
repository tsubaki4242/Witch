#include "stdafx.h"
#include "title.h"

HRESULT title::init()
{
	IMAGEMANAGER->addImage("���2", "background2.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Ÿ��Ʋ", "titlefile/Ÿ��Ʋ.bmp", 656, 114, true, RGB(254, 254, 254));
	IMAGEMANAGER->addImage("Ÿ��Ʋ2", "titlefile/������.bmp", 471, 473, true, RGB(250, 250, 250));
	IMAGEMANAGER->addImage("Ÿ��Ʋ3", "num/����.bmp", 130, 30, true, RGB(24, 24, 24));
	IMAGEMANAGER->addImage("Ÿ��Ʋ4", "num/�ø���.bmp", 435, 50, true, RGB(24, 24, 24));
	titleImg = IMAGEMANAGER->findImage("Ÿ��Ʋ");
	titleImg2 = IMAGEMANAGER->findImage("Ÿ��Ʋ2");
	backGround = IMAGEMANAGER->findImage("���2");
	coinImg = IMAGEMANAGER->findImage("Ÿ��Ʋ3");
	please = IMAGEMANAGER->findImage("Ÿ��Ʋ4");
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


