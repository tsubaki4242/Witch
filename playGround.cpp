#include "stdafx.h"
#include "playGround.h"

playGround::playGround()
{
}


playGround::~playGround()
{
}

//�ʱ�ȭ�� ����� �ϼ��� ����
HRESULT playGround::init()
{
	gameNode::init(true);

	SCENEMANAGER->addScene("Ÿ��Ʋ", new title);
	SCENEMANAGER->addScene("1����", new Scene1);
	SCENEMANAGER->changeScene("Ÿ��Ʋ");

	EFFECTMANAGER->addEffect("explostion2", "effect/����������2.bmp", 2046, 70, 93, 70, 1, 0.5f, 22,221,51,152);
	EFFECTMANAGER->addEffect("��ų����", "magic/�ذ��� ����.bmp", 7200, 540, 480, 540, 1, 0.5f, 22, 255, 0, 255);





	return S_OK;
}

//�޸� ������ ����� �ϼ��� ����
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
	// ���� �ǵ�������
	//================���� �� ���̿� �� �׸��ô�==========================

	

	SCENEMANAGER->render();

	//==================================================
	//���⵵ �ǵ�������
	//this->getBackBuffer()->render(getHDC(), 0, 0);
	CAMERAMANAGER->render(getHDC(), 0, 0, getMemDC(), false);
}
