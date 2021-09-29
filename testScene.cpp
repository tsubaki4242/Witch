#include "stdafx.h"
#include "testScene.h"


testScene::testScene()
{
}


testScene::~testScene()
{
}

HRESULT testScene::init()
{
	IMAGEMANAGER->addImage("����", "����.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));

	_rc = RectMakeCenter(WINSIZEX / 2 - 200, WINSIZEY / 2, 100, 100);

	return S_OK;
}

void testScene::release()
{
}

void testScene::update()
{
	if (KEYMANAGER->isOnceKeyDown(VK_F1)) SCENEMANAGER->changeScene("�׽�Ʈ��2");

	_rc.left += 2;
	_rc.right += 2;
}

void testScene::render()
{
	IMAGEMANAGER->findImage("����")->render(getMemDC());

	Rectangle(getMemDC(), _rc);
}
