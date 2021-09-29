#include "stdafx.h"
#include "playGround.h"

playGround::playGround()
{
}


playGround::~playGround()
{
}

//초기화는 여기다 하세요 제발
HRESULT playGround::init()
{
	gameNode::init(true);

	SCENEMANAGER->addScene("타이틀", new title);
	SCENEMANAGER->addScene("1번맵", new Scene1);
	SCENEMANAGER->changeScene("타이틀");

	EFFECTMANAGER->addEffect("explostion2", "effect/몬스터터지기2.bmp", 2046, 70, 93, 70, 1, 0.5f, 22,221,51,152);
	EFFECTMANAGER->addEffect("스킬폭발", "magic/해골스컬 폭발.bmp", 7200, 540, 480, 540, 1, 0.5f, 22, 255, 0, 255);





	return S_OK;
}

//메모리 해제는 여기다 하세요 제발
void playGround::release()
{
	gameNode::release();


}


void playGround::update()
{
	gameNode::update();

	SCENEMANAGER->update();


}


void playGround::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	// 위에 건들지마라
	//================제발 이 사이에 좀 그립시다==========================

	

	SCENEMANAGER->render();

	//==================================================
	//여기도 건들지마라
	//this->getBackBuffer()->render(getHDC(), 0, 0);
	CAMERAMANAGER->render(getHDC(), 0, 0, getMemDC(), false);
}
