#include "stdafx.h"
#include "Scene1.h"
#include "UI.h"

HRESULT Scene1::init()
{
	IMAGEMANAGER->addFrameImage("bullet", "magic/기본마법.bmp", 1024, 96,8,1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("배경", "background.bmp", WINSIZEX, WINSIZEY,true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("숲", "background3.bmp", 9800, 800, true, RGB(255, 0, 255));
	//몬스터 들 ================================
	IMAGEMANAGER->addFrameImage("eyefly", "monster/아이플라이.bmp", 0, 0, 600, 120, 5, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("bluefire", "monster/블루파이어.bmp", 0, 0, 448, 84, 8, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("redfire", "monster/레드파이어.bmp", 0, 0, 512, 84, 8, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("boss!!", "monster/보스.bmp", 0, 0, 1440, 300, 6, 1, true, RGB(255, 0, 255));
	//=============================================
	background = IMAGEMANAGER->findImage("배경");
	backgroundForest = IMAGEMANAGER->findImage("숲");


	_player = new player;
	_player->init();

	//에너미매니저 동적할당
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
