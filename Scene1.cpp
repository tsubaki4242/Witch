#include "stdafx.h"
#include "Scene1.h"
#include "UI.h"

HRESULT Scene1::init()
{
	IMAGEMANAGER->addFrameImage("bullet", "magic/�⺻����.bmp", 1024, 96,8,1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("���", "background.bmp", WINSIZEX, WINSIZEY,true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��", "background3.bmp", 9800, 800, true, RGB(255, 0, 255));
	//���� �� ================================
	IMAGEMANAGER->addFrameImage("eyefly", "monster/�����ö���.bmp", 0, 0, 600, 120, 5, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("bluefire", "monster/������̾�.bmp", 0, 0, 448, 84, 8, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("redfire", "monster/�������̾�.bmp", 0, 0, 512, 84, 8, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("boss!!", "monster/����.bmp", 0, 0, 1440, 300, 6, 1, true, RGB(255, 0, 255));
	//=============================================
	background = IMAGEMANAGER->findImage("���");
	backgroundForest = IMAGEMANAGER->findImage("��");


	_player = new player;
	_player->init();

	//���ʹ̸Ŵ��� �����Ҵ�
	_em = new enemyManager;
	_em->init();
	_em->setEyefly();
	_em->setbluefire();
	_em->setredfire();
	_em->setboss();
	_UI = new UI;
	_UI->init();
	_UI->SetCoin(SAVEPLAYER->getCoin());
	_UI->SetStart(SAVEPLAYER->getstart());
	
	_em->playerlink(_player);
	_player->setEmMemoryAddressLink(_em);

	return S_OK;
}

void Scene1::release()
{
	SAFE_DELETE(_player);
}

void Scene1::update()
{

	_UI->update();
	_player->update();
	_em->update();
	
	EFFECTMANAGER->update();
}

void Scene1::render()
{
	RECT rc = CAMERAMANAGER->getRect();
	background->render(getMemDC(),rc.left, rc.top);
	//Rectangle(getMemDC(), _cm);
	backgroundForest->render(getMemDC(), 0, 0);

	_em->render();
	_player->render();

	_UI->render();
	EFFECTMANAGER->render();
}
