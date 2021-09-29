#include "stdafx.h"
#include "UI.h"

HRESULT UI::init()
{
	IMAGEMANAGER->addFrameImage("manacry", "UI/마력수정.bmp", 216, 57, 8, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("dashBar", "UI/대쉬보석.bmp", 264, 48, 8, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("combat", "UI/근접 수정.bmp", 387, 45, 9, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Skill", "UI/스킬공격.bmp", 387, 42, 9, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Life", "UI/목숨.bmp", 346, 43, 8, 1, true, RGB(255, 0, 255));
	//노 프레임
	IMAGEMANAGER->addImage("manacryS", "UI/마나그림자.bmp", 27, 57, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("dashBarS", "UI/대쉬그림자.bmp", 33, 48,  true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("combatS", "UI/근접 수정그림자.bmp", 43, 45, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("skillS", "UI/스킬공격그림자.bmp", 43, 42, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("face", "UI/플레이어얼굴.bmp", 150, 150, true, RGB(255, 0, 255));

	_mana = IMAGEMANAGER->findImage("manacry"); //마나 이미지
	dashBar = IMAGEMANAGER->findImage("dashBar"); //대쉬 게이지 이미지
	_skillImg = IMAGEMANAGER->findImage("Skill");

	combat = IMAGEMANAGER->findImage("combat"); //근접공격
	//그림자
	_manaS = IMAGEMANAGER->findImage("manacryS"); //마나 그림자 이미지
	_dashS = IMAGEMANAGER->findImage("dashBarS"); //대쉬 그림자 게이지 이미지
	_combatS = IMAGEMANAGER->findImage("combatS"); //근접공격 그림자 게이지 이미지
	_skillS = IMAGEMANAGER->findImage("skillS"); //스킬 그림자 게이지 이미지
	//목숨
	for (int i = 0; i < 3; i++)
	{
		_lifeImg[i] = IMAGEMANAGER->findImage("Life");
	}
	IMAGEMANAGER->addImage("타이틀3", "num/코인.bmp", 130, 30, true, RGB(24, 24, 24));
	IMAGEMANAGER->addImage("스코어", "num/스코어.bmp", 117, 30, true, RGB(24, 24, 24));
	coinImg = IMAGEMANAGER->findImage("타이틀3");
	ScoreImg = IMAGEMANAGER->findImage("스코어");
	_face = IMAGEMANAGER->findImage("face");  //얼굴 이미지
	char strNum[100];
	for (int i = 0; i < 10; i++)
	{
		coinNum[i] = new image;
		sprintf_s(strNum, "num/%d.bmp", i);
		coinNum[i]->init(strNum, 20, 23, true, RGB(24, 24, 24));
	}
	for (int i = 0; i < 10; i++)
	{
		ScoreNum[i] = new image;
		sprintf_s(strNum, "num/%d.bmp", i);
		ScoreNum[i]->init(strNum, 20, 23, true, RGB(24, 24, 24));
	}



	_life =0;
	_coin = 0;
	_Score = 0;
	_state = false;
	return S_OK;
}

void UI::release()
{


}

void UI::update()
{	
	
	dashMax = SAVEPLAYER->getDash();
	combatMax = SAVEPLAYER->getCombat();
	_skilMax = SAVEPLAYER->getSkill();
	_life = SAVEPLAYER->getLife();
	_Score = SAVEPLAYER->getScore();
	_manaMAX = SAVEPLAYER->getMana();
	_count++;
	if (_count % 6 == 0)
	{
		//마나 크리스탈
		_mana->setFrameY(0);
		_mana->setFrameX(_index);
		dashBar->setFrameY(0);
		dashBar->setFrameX(_index);
		for (int i = 0; i < 3; i++)
		{
			_lifeImg[i]->setFrameY(0);
			_lifeImg[i]->setFrameX(_index);
		}
		_index++;
		_index2++;
		combat->setFrameY(0);
		combat->setFrameX(_index2);
		_skillImg->setFrameY(0);
		_skillImg->setFrameX(_index2);
		if (_index >= 8) _index = 0;
		if (_index2 >= 9) _index2 = 0;
	}



	/*	dashBar->setFrameX(dashMax);*/

	
	if (KEYMANAGER->isOnceKeyDown('1') && _coin > 0)
	{
		_coin -= 1;
		SAVEPLAYER->getSetCoin(_coin);
		_state = true;
		SAVEPLAYER->getSetBool(_state);
		SCENEMANAGER->changeScene("1번맵");



	}
	if (KEYMANAGER->isOnceKeyDown('5'))
	{	

		_coin++;
		SAVEPLAYER->getSetCoin(_coin);
	}


}

void UI::render()
{
	RECT rc = CAMERAMANAGER->getRect();

	if (_state)
	{
		_mana->frameRender(getMemDC(), rc.left + 170, rc.top + 50);
		_manaS->alphaRender(getMemDC(), rc.left + 170, rc.top + 50, _manaMAX);


		//라이프 이미지
		if (_life == 0)
		{
			_lifeImg[0] -> frameRender(getMemDC(), rc.left + 165, rc.top + 120);
			_lifeImg[1]->frameRender(getMemDC(), rc.left + 200, rc.top + 120);
			_lifeImg[2]->frameRender(getMemDC(), rc.left + 235, rc.top + 120);//목숨
		}
		if (_life == 1)
		{
			_lifeImg[0]->frameRender(getMemDC(), rc.left + 165, rc.top + 120);
			_lifeImg[1]->frameRender(getMemDC(), rc.left + 200, rc.top + 120);

		}
		if (_life == 2)
		{
			_lifeImg[0]->frameRender(getMemDC(), rc.left + 165, rc.top + 120);

		}
		//스킬 렌더
		_skillImg->frameRender(getMemDC(), rc.left + 203, rc.top + 60);
		_skillS->alphaRender(getMemDC(), rc.left + 203, rc.top + 60, _skilMax);
		//근접공격 렌더
		combat->frameRender(getMemDC(), rc.left + 250, rc.top + 58);
		_combatS->alphaRender(getMemDC(), rc.left + 250, rc.top + 58, combatMax);

		//대쉬 렌더
		dashBar->frameRender(getMemDC(), rc.left + 298, rc.top + 55);
		_dashS->alphaRender(getMemDC(), rc.left + 298, rc.top + 55, dashMax);




		_face->alphaRender(getMemDC(), rc.left + 10, rc.top + 10, 230);
		ScoreImg->render(getMemDC(), rc.left + 170, rc.top + 15);


		//장식
		ScoreNum[0]->render(getMemDC(), rc.left + 400, rc.top + 17);
		ScoreNum[0]->render(getMemDC(), rc.left + 380, rc.top + 17);

		//진짜숫자
		ScoreNum[_Score % 10]->render(getMemDC(), rc.left + 360, rc.top + 17);

		if (_Score / 10 >= 1)
		{
			ScoreNum[_Score / 10]->render(getMemDC(), rc.left + 340, rc.top + 17);
		}
		else
		{
			ScoreNum[0]->render(getMemDC(), rc.left + 340, rc.top + 17);
		}
		if (_Score / 100 >= 1)
		{
			ScoreNum[_Score / 10]->render(getMemDC(), rc.left + 320, rc.top + 17);
		}
		else
		{
			ScoreNum[0]->render(getMemDC(), rc.left + 320, rc.top + 17);
		}
		if (_Score / 1000 >= 1)
		{
			ScoreNum[_Score / 10]->render(getMemDC(), rc.left + 300, rc.top + 17);
		}
		else
		{
			ScoreNum[0]->render(getMemDC(), rc.left + 300, rc.top + 17);
		}

	}

	coinImg->render(getMemDC(), rc.left + 1320, rc.top + 770);
	coinNum[_coin % 10]->render(getMemDC(), rc.left + 1480, rc.top + 771);

	if (_coin / 10 >= 1)
	{
		coinNum[_coin / 10]->render(getMemDC(), rc.left + 1460,rc.top + 771);
	}
	else
	{
		coinNum[0]->render(getMemDC(), rc.left + 1460, rc.top + 771);
	}

	
}
