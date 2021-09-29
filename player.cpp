#include "stdafx.h"
#include "player.h"
#include "enemyManager.h"
#include "item.h"

HRESULT player::init()
{

	ww = 50;
	wh = 110;
	_count = 0;
	_count2 = 0;
	AFcount = 0;
	_index = 0;
	_speed = 5;
	_dashTimer = 0;
	AFswitch = false;
	_dash = false;
	_dashRT = false;
	_dashR = false;
	dashBar = 0;
	_skillMax = 0;
	_combatMax =0 ;
	_score = 0;
	_skilltime = 0;
	_skillboll = false;
	_dashSkill = false;
	_dashSkillT = 0;
	_witcjALP = 255;
	_alpatime = 0;
	_alpatime2 = 0;
	alpawitch = false;

	//½ºµV ÃÑ¾Ë ¾ÆÀÌÅÛ ÃÊ±âÈ­
	_bullet = new bullet;
	_bullet->init(300, 700);
	_item = new item;
	_item->init(30, 100);
	_item2 = new item2;
	_item2->init(30, 100);
	_skill = new skill;
	_skill->init(30, 500);

	_soul = new SOUL;
	_soul->init(30, 900);
	_soul1 = new SOUL1;
	_soul1->init(30, 900);
	_soul2 = new SOUL2;
	_soul2->init(30, 900);

	imgeAll();

	wx = 300;
	wy = 300;

	_witchRC = RectMakeCenter(300, 300, ww, wh);
	ARx = 10;
	ARy = 150;
	_witchAteckRC = RectMakeCenter(wx, wy, ARx, ARy);
	_skillRECT = RectMakeCenter(0, 0, 0, 0);

	cx = (_witchRC.left + _witchRC.right) / 2;
	cy = (_witchRC.top + _witchRC.bottom) / 2;

	_WitchState = IDLE;


	dx = dx1 = dx2 = cx;
	dy = dy1 = dy2 = cy;



	CRX = 700;
	CRY = 300;
	_Center = RectMakeCenter(CRX, CRY, 100, 100);



	return S_OK;
}

void player::release()
{
}

void player::update()
{

	keyAll();


	collision();
	Itemcollision();
	skillCollision();
	soulitemChangeCollision();
	if (_dashSkill)
	{
		playerEnemyCollision();
		_dashSkillT++;
	}
	if (_dashSkillT > 1000)
	{
		_dashSkill = false;
	}
	if (alpawitch)
	{
		_alpatime++;
		if(_alpatime > 600)
		{
			alpawitch = false;
			_alpatime = 0;
			_witcjALP = 255;
		}
		else if (_alpatime < 600)
		{
			_alpatime2++;
			if (_alpatime2 > 100)
			{
				_witcjALP -= 100;
				_alpatime2 = 0;
			}
			else if (_alpatime2 < 100)
			{
				_witcjALP += 100;
			}

		}
	}
	SAVEPLAYER->getSetdash(dashBar);
	SAVEPLAYER->getSetSkill(_skillMax);
	SAVEPLAYER->getSetCombat(_combatMax);
	SAVEPLAYER->getSetMana(_manaMax);
	SAVEPLAYER->getSetLife(_life);
	SAVEPLAYER->getSetScore(_score);
	imgeFrame();
	CRX+= 3;
	_witchRC = RectMakeCenter(wx, wy, ww, wh);
	_witchAteckRC = RectMake(wx -30, wy - 50, ARx, ARy);
	zone();
	CAMERAMANAGER->updateScreen(CRX, CRY);
//	CAMERAMANAGER->updateScreen(cx, cy);
	_bullet->update();
	_item->update();
	_skill->update();
	_soul->update();
	_soul1->update();
	_soul2->update();
	_item2->update();

}

void player::render()
{
//	Rectangle(getMemDC(),_witchRC);
//	Rectangle(getMemDC(), _witchAteckRC);
//	Rectangle(getMemDC(), _skillRECT);
	if (_dash)
	{
		_dashImg2->alphaFrameRender(getMemDC(), dx2 - 115, dy2 - 76,150);
		_dashImg1->alphaFrameRender(getMemDC(), dx1 - 115, dy1 - 76, 150);
		_dashImg->alphaFrameRender(getMemDC(), dx - 115, dy - 76, 150);


	}
	_witch->alphaFrameRender(getMemDC(),cx - 115 , cy - 76, _witcjALP);
	if (_dash && _dashSkill)
	{
		_dasgEffect->alphaFrameRender(getMemDC(), cx - 180, cy - 100, 150);
	}
	//TIMEMANAGER->render(getMemDC(),cx,cy-100);

	_bullet->render();
	_item->render();
	_skill->render();
	_soul->render();
	_soul1->render();
	_soul2->render();
	_item2->render();
}

void player::imgeAll()
{
	IMAGEMANAGER->addFrameImage("nomarl", "Witch/Nomarl2.bmp", 3200, 152,16,1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ateck", "Witch/atteck2.bmp", 3080, 152,11,1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("skill", "Witch/Skill.bmp", 3080, 152, 11, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Teck", "Witch/Teck.bmp", 4212, 180, 13, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("dash", "Witch/dash.bmp", 840, 152, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("dash1", "Witch/dash.bmp", 840, 152, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("dash2", "Witch/dash.bmp", 840, 152, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("dasheffect", "Witch/´ë½¬ÀÌÆåÆ®2.bmp", 764, 240, 3, 1, true, RGB(255, 0, 255));

	_witch = IMAGEMANAGER->findImage("nomarl");

	_dashImg = IMAGEMANAGER->findImage("dash");
	_dashImg1 = IMAGEMANAGER->findImage("dash1");
	_dashImg2 = IMAGEMANAGER->findImage("dash2");
	_dasgEffect = IMAGEMANAGER->findImage("dasheffect");
}

void player::imgeFrame()
{
	_count++;
	_count2++;
	if (_count % 5 == 0)
	{

		if (_WitchState == IDLE)
		{
			_witch = IMAGEMANAGER->findImage("nomarl");
			_witch->setFrameY(0);
			_witch->setFrameX(_index);
			_index++;

			if (_index >= 16) _index = 0;
		}
		if (_WitchState == ATECK)
		{

			_witch = IMAGEMANAGER->findImage("ateck");
			_witch->setFrameY(0);
			_witch->setFrameX(_index);
			_index++;

			if (_index >= 9)
			{
				_manaMax += 3;
				_index = 0;
				_WitchState = IDLE;
				wx += 30;
				AFswitch = false;
			}

		}
		if (_WitchState == SKILL)
		{

			_witch = IMAGEMANAGER->findImage("skill");
			_witch->setFrameY(0);
			_witch->setFrameX(_index);
			_index++;

			if (_index >= 8)
			{
				_skillMax += 10;
				_index = 0;
				_WitchState = IDLE;
				AFswitch = false;
			}

		}
		if (_WitchState == COUNTER)
		{

			_witch = IMAGEMANAGER->findImage("Teck");
			_witch->setFrameY(0);
			_witch->setFrameX(_index);
			_index++;

			if (_index == 5)
			{
				ARx = 10;
			}
			if (_index >= 13)
			{

				_combatMax +=20;
				_index = 0;
				_WitchState = IDLE;
				AFswitch = false;
			}

		}
		if (_WitchState == DASH)
		{
			_index = 0;
			_witch = IMAGEMANAGER->findImage("Teck");
			_witch->setFrameY(0);
			_witch->setFrameX(_index);
			_dashImg1->setFrameX(1);
			_dashImg2->setFrameX(2);

			_index++;

		}

		_count = 0;
	}
	if (_count2 % 2 == 0)
	{
		if (_WitchState == DASH)
		{
			_indexD++;
			_dasgEffect->setFrameY(0);
			_dasgEffect->setFrameX(_indexD);

			if (_indexD > 3)
			{
				_indexD = 0;
				if (_dashSkill)
				{
					ARx = 10;
				}
			}

		}
		_count2 = 0;
	}
}

void player::keyAll()
{
	if (KEYMANAGER->isStayKeyDown(VK_UP) && !_dash)
	{

		cy -= _speed;
		wy -= _speed;
		dy -= _speed;
		dy1 -= _speed;
		dy2 -= _speed;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN) && !_dash)
	{

		cy += _speed;
		wy += _speed;
		dy += _speed;
		dy1 += _speed;
		dy2 += _speed;
	}
	if (KEYMANAGER->isStayKeyDown(VK_LEFT) && !_dash)
	{
		cx -= _speed;
		wx -= _speed;
		dx -= _speed;
		dx1 -= _speed;
		dx2 -= _speed;
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT) &&! _dash)
	{

		cx += _speed;
		wx += _speed;
		dx += _speed;
		dx1 += _speed;
		dx2 += _speed;
	}
	if (KEYMANAGER->isStayKeyDown('C') && !AFswitch && dashBar < 200)
	{
		_dashTimer++;
		if (_dashTimer < 30)
		{
			_speed = 13;
			_index = 0;
			_WitchState = DASH;
			_dash = true;
			_dashR = true;
			cx += _speed;
			wx += _speed;
			dx += 12;
			dx1 += 11;
			dx2 += 10;
			if (_dashSkill)
			{

				ARx = 110;

			}

			

		}
		else if(_dashTimer > 30)
		{
			_speed = 5;
			AFswitch = false;
			_dashRT = true;
		}
	}
	if (KEYMANAGER->isOnceKeyUp('C') && _dashR)
	{
		_speed = 5;

		AFswitch = false;
		_dashRT = true;
		_dashTimer = 0;
		_dashR = false;


	}
	if (_dashRT)
	{

			if (dx < cx)
			{
				dx += 12;
			}
			else
			{
			dx = cx;
			}

			if (dx1 < cx)
			{
				dx1 += 11;
			}
			else
			{
				dx1 = cx;
			}
			if (dx2 < cx)
			{
				dx2 += 10;
			}
			else
			{
			dx2 = cx;
			}

		if (dx >= cx && dx1 >= cx  && dx2 >= cx )
		{
		_dash = false;
		_dashRT = false;	
		_WitchState = IDLE;
	
			dashBar+=10;
		}
	}

	if (KEYMANAGER->isStayKeyDown('A') && !AFswitch && !_dash&& _manaMax < 200)
	{
		_bullet->fire(cx, cy);
		if (_score >= 4)
		{
		 _bullet->fire(cx, cy -50);
		}
		if (_score >= 8)
		{
			_bullet->fire(cx, cy + 50);
		}
		_index = 0;
		_WitchState = ATECK;
		wx -= 30;
		AFswitch = true;



	}

	if (KEYMANAGER->isStayKeyDown('S') && !AFswitch && !_dash && _skillMax < 200)
	{
		_skill->setSkill(cx, cy);
		_index = 1;
		_WitchState = SKILL;
		AFswitch = true;
	}
	if (KEYMANAGER->isStayKeyDown('D') && !AFswitch && !_dash && _combatMax < 200)
	{
		_index = 0;
		_WitchState = COUNTER;
		ARx = 240;
		AFswitch = true;
	}
}

void player::zone()
{
	RECT rc = CAMERAMANAGER->getRect();

	if (_witchRC.left < rc.left)
	{
		cx += 5;
		wx += 5;
		dx += 5;
		dx1 += 5;
		dx2 += 5;
	}
	if (_witchRC.top < rc.top)
	{
		cy += 5;
		wy += 5;
		dy += 5;
		dy1 += 5;
		dy2 += 5;
	}
	if (_witchRC.right > rc.right)
	{
		cx -= 5;
		wx -= 5;
		dx -= 5;
		dx1 -= 5;
		dx2 -= 5;
	}
	if (_witchRC.bottom > rc.bottom)
	{
		cy -= 5;
		wy -= 5;
		dy -= 5;
		dy1 -= 5;
		dy2 -= 5;
	}

}

void player::death()
{
	RECT rc = CAMERAMANAGER->getRect();

	cx  = rc.left;
	wx = rc.left;
	dx = rc.left;
	dx1 = rc.left;
	dx2 = rc.left;
	cy = rc.top + 300;
	wy = rc.top + 300;
	dy = rc.top + 300;
	dy1 = rc.top + 300;
	dy2 = rc.top + 300;

}

void player::deathalpa()
{



	
}

void player::deathSwith()
{
	alpawitch = true;
}

void player::lifeDamge(int damge)
{
	_life += damge;


}

void player::collision()
{
	for (int i = 0; i < _em->getVEyefly().size(); i++)
	{

		for (int j = 0; j < _bullet->getVBullet().size(); j++)
		{
			RECT temp;
			RECT rc = _em->getVEyefly()[i]->getRect();
			int x = (_em->getVEyefly()[i]->getRect().left + _em->getVEyefly()[i]->getRect().right) /2;
			int y = (_em->getVEyefly()[i]->getRect().top + _em->getVEyefly()[i]->getRect().bottom) /2;

			if (IntersectRect(&temp, &_bullet->getVBullet()[j].rc,
				&rc))
			{
				int R = rand() % 20;

				EFFECTMANAGER->play("explostion2",x , y);
				_em->removeEyefly(i );
				_bullet->removeBullet(j);

				if (R == 0)
				{
					_item2->setitem(x, y);
				}
				if (R == 1)
				{
					_item->setitem(x, y);
				}
				if (R == 2)
				{
					_soul->setitem(x, y);
				}
				if (R == 3)
				{
					_soul1->setitem(x, y);
				}
				if (R == 4)
				{
					_soul2->setitem(x, y);
				}
				break;
			}
			
		}
	}
	for (int i = 0; i < _em->getvblueFire().size(); i++)
	{

		for (int j = 0; j < _bullet->getVBullet().size(); j++)
		{
			RECT temp;
			RECT rc = _em->getvblueFire()[i]->getRect();
			int x = (_em->getvblueFire()[i]->getRect().left + _em->getvblueFire()[i]->getRect().right) / 2;
			int y = (_em->getvblueFire()[i]->getRect().top + _em->getvblueFire()[i]->getRect().bottom) / 2;

			if (IntersectRect(&temp, &_bullet->getVBullet()[j].rc,
				&rc))
			{
				int R = rand() % 20;

				EFFECTMANAGER->play("explostion2", x, y);
				_em->removebluefire(i);
				_bullet->removeBullet(j);

				if (R == 0)
				{
					_item2->setitem(x, y);
				}
				if (R == 1)
				{
					_item->setitem(x, y);
				}
				if (R == 2)
				{
					_soul->setitem(x, y);
				}
				if (R == 3)
				{
					_soul1->setitem(x, y);
				}
				if (R == 4)
				{
					_soul2->setitem(x, y);
				}
				break;
			}

		}
	}
	for (int i = 0; i < _em->getvredFire().size(); i++)
	{

		for (int j = 0; j < _bullet->getVBullet().size(); j++)
		{
			RECT temp;
			RECT rc = _em->getvredFire()[i]->getRect();
			int x = (_em->getvredFire()[i]->getRect().left + _em->getvredFire()[i]->getRect().right) / 2;
			int y = (_em->getvredFire()[i]->getRect().top + _em->getvredFire()[i]->getRect().bottom) / 2;

			if (IntersectRect(&temp, &_bullet->getVBullet()[j].rc,
				&rc))
			{
				int R = rand() % 20;

				EFFECTMANAGER->play("explostion2", x, y);
				_em->removeredfire(i);
				_bullet->removeBullet(j);

				if (R == 0)
				{
					_item2->setitem(x, y);
				}
				if (R == 1)
				{
					_item->setitem(x, y);
				}
				if (R == 2)
				{
					_soul->setitem(x, y);
				}
				if (R == 3)
				{
					_soul1->setitem(x, y);
				}
				if (R == 4)
				{
					_soul2->setitem(x, y);
				}
				break;
			}

		}
	}
}

void player::Itemcollision()
{
	RECT temp;
	for (int j = 0; j < _item->getVitem().size(); j++)
	{
		if (IntersectRect(&temp, &_item->getVitem()[j].rc, &_witchRC))
		{

			_score += 1;
			_item->removeitem(j);
			break;
		}
	}
	for (int j = 0; j < _item2->getVitem2().size(); j++)
	{
		if (IntersectRect(&temp, &_item2->getVitem2()[j].rc, &_witchRC))
		{

			_score += 2;
			_item2->removeitem(j);
			break;
		}
	}
	for (int i = 0; i < _soul->getSOUL().size(); i++)
	{
		if (IntersectRect(&temp, &_witchRC, &_soul->getSOUL()[i].rc))
		{

			 _manaMax =0;
			 _skillMax =0;
			 _combatMax =0;
			 dashBar = 0;


			_soul->removeitem(i);
			break;
		}

	}
	for (int i = 0; i < _soul1->getSOUL1().size(); i++)
	{
		for (int j = 0; j < _em->getVEyefly().size(); j++)
		{
			int x = (_em->getVEyefly()[j]->getRect().left + _em->getVEyefly()[j]->getRect().right) / 2;
			int y = (_em->getVEyefly()[j]->getRect().top + _em->getVEyefly()[j]->getRect().bottom) / 2;


			if (IntersectRect(&temp, &_witchRC, &_soul1->getSOUL1()[i].rc))
			{




				_em->removeEyefly(j);
				_em->removeEyefly(j);
				_soul1->removeitem(i);
				break;

			}
		}


	}

	for (int i = 0; i < _soul1->getSOUL1().size(); i++)
	{

		if (IntersectRect(&temp, &_witchRC, &_soul1->getSOUL1()[i].rc))
		{



			_soul1->removeitem(i);


			break;
		}

	}
	for (int i = 0; i < _soul2->getSOUL2().size(); i++)
	{

		if (IntersectRect(&temp, &_witchRC, &_soul2->getSOUL2()[i].rc))
		{


			_dashSkill = true;
			_soul2->removeitem(i);


			break;
		}

	}

}

void player::skillCollision()
{
	for (int i = 0; i < _em->getVEyefly().size(); i++)
	{

		for (int j = 0; j < _skill->getVSkill().size(); j++)
		{
			RECT temp;
			RECT rc = _em->getVEyefly()[i]->getRect();
			int x = (_em->getVEyefly()[i]->getRect().left + _em->getVEyefly()[i]->getRect().right) / 2;
			int y = (_em->getVEyefly()[i]->getRect().top + _em->getVEyefly()[i]->getRect().bottom) / 2;

			if (IntersectRect(&temp, &_skill->getVSkill()[j].rc,
				&rc))
			{
				int R = rand() % 20;
				EFFECTMANAGER->play("½ºÅ³Æø¹ß", x, y);
				_skillRECT = RectMakeCenter(x, y, 480, 540);
				_em->removeEyefly(i);
				_skill->removeSkill(j);
				if (R > 8)
				{
					_item->setitem(x, y);
				}
				if (R == 1)
				{
					_item2->setitem(x, y);
				}
				if (R == 2)
				{
					_soul->setitem(x, y);
				}
				if (R == 3)
				{
					_soul1->setitem(x, y);
				}
				if (R == 4)
				{
					_soul2->setitem(x, y);
				}
				_skillboll = true;

				break;
			}

		}
	}
	if (_skillboll)
	{
		_skilltime++;
	}
	if (_skilltime > 30)
	{
		_skillRECT = RectMakeCenter(0, 0, 480, 540);
		_skillboll = false;
	}
	for (int i = 0; i < _em->getVEyefly().size(); i++)
	{


			RECT temp;
			RECT rc = _em->getVEyefly()[i]->getRect();
			int x = (_em->getVEyefly()[i]->getRect().left + _em->getVEyefly()[i]->getRect().right) / 2;
			int y = (_em->getVEyefly()[i]->getRect().top + _em->getVEyefly()[i]->getRect().bottom) / 2;

			if (IntersectRect(&temp, &_skillRECT,&rc))
			{
				

				_em->removeEyefly(i);
				_em->removeredfire(i);
				_em->removebluefire(i);


				break;
			}

		
	}
	for (int i = 0; i < _em->getvblueFire().size(); i++)
	{

		for (int j = 0; j < _skill->getVSkill().size(); j++)
		{
			RECT temp;
			RECT rc = _em->getvblueFire()[i]->getRect();
			int x = (_em->getvblueFire()[i]->getRect().left + _em->getvblueFire()[i]->getRect().right) / 2;
			int y = (_em->getvblueFire()[i]->getRect().top + _em->getvblueFire()[i]->getRect().bottom) / 2;

			if (IntersectRect(&temp, &_skill->getVSkill()[j].rc,
				&rc))
			{
				int R = rand() % 20;

				EFFECTMANAGER->play("½ºÅ³Æø¹ß", x, y);
				_skillRECT = RectMakeCenter(x, y, 480, 540);
				_em->removebluefire(i);
				_skill->removeSkill(j);

				if (R > 8)
				{
					_item->setitem(x, y);
				}
				if (R == 1)
				{
					_item2->setitem(x, y);
				}
				if (R == 2)
				{
					_soul->setitem(x, y);
				}
				if (R == 3)
				{
					_soul1->setitem(x, y);
				}
				if (R == 4)
				{
					_soul2->setitem(x, y);
				}
				break;
			}

		}
	}
	for (int i = 0; i < _em->getvredFire().size(); i++)
	{

		for (int j = 0; j < _skill->getVSkill().size(); j++)
		{
			RECT temp;
			RECT rc = _em->getvredFire()[i]->getRect();
			int x = (_em->getvredFire()[i]->getRect().left + _em->getvredFire()[i]->getRect().right) / 2;
			int y = (_em->getvredFire()[i]->getRect().top + _em->getvredFire()[i]->getRect().bottom) / 2;

			if (IntersectRect(&temp, &_skill->getVSkill()[j].rc,
				&rc))
			{
				int R = rand() % 20;

				EFFECTMANAGER->play("½ºÅ³Æø¹ß", x, y);
				_skillRECT = RectMakeCenter(x, y, 480, 540);
				_em->removeredfire(i);
				_skill->removeSkill(j);

				if (R > 8)
				{
					_item->setitem(x, y);
				}
				if (R == 1)
				{
					_item2->setitem(x, y);
				}
				if (R == 2)
				{
					_soul->setitem(x, y);
				}
				if (R == 3)
				{
					_soul1->setitem(x, y);
				}
				if (R == 4)
				{
					_soul2->setitem(x, y);
				}
				break;
			}

		}
	}
}

void player::soulitemChangeCollision()
{

	for (int j = 0; j < _bullet->getVBullet().size(); j++)
	{
		for (int i= 0; i < _soul->getSOUL().size(); i++)
		{

			RECT temp;
			int x = _soul->getSOUL()[i].x;
			int y = _soul->getSOUL()[i].y;
			if (IntersectRect(&temp, &_bullet->getVBullet()[j].rc,&_soul->getSOUL()[i].rc))
			{
				int R = rand() % 3;
				_soul->moveateck();
				_soul->removeitem(i);
				_bullet->removeBullet(j);
				if (R == 0)
				{
					_soul->moveateck();
					_soul->setitem(x, y);
				}
				if (R == 1)
				{
					_soul1->moveateck();
					_soul1->setitem(x, y);
				}
				if (R == 2)
				{
					_soul2->moveateck();
					_soul2->setitem(x, y);
				}



				break;
			}

		}

	}


	for (int j = 0; j < _bullet->getVBullet().size(); j++)
	{
		for (int i = 0; i < _soul1->getSOUL1().size(); i++)
		{

			RECT temp;
			int x = _soul1->getSOUL1()[i].x;
			int y = _soul1->getSOUL1()[i].y;
			if (IntersectRect(&temp, &_bullet->getVBullet()[j].rc, &_soul1->getSOUL1()[i].rc))
			{
				int R = rand() % 3;
				_soul1->moveateck();
				_soul1->removeitem(i);
				_bullet->removeBullet(j);
				if (R == 0)
				{
					_soul->moveateck();
					_soul->setitem(x, y);
				}
				if (R == 1)
				{
					_soul1->moveateck();
					_soul1->setitem(x, y);
				}
				if (R == 2)
				{
					_soul2->moveateck();
					_soul2->setitem(x, y);
				}



				break;
			}

		}

	}
	for (int j = 0; j < _bullet->getVBullet().size(); j++)
	{
		for (int i = 0; i < _soul2->getSOUL2().size(); i++)
		{

			RECT temp;
			int x = _soul2->getSOUL2()[i].x;
			int y = _soul2->getSOUL2()[i].y;
			if (IntersectRect(&temp, &_bullet->getVBullet()[j].rc, &_soul2->getSOUL2()[i].rc))
			{
				int R = rand() % 3;
				_soul2->moveateck();
				_soul2->removeitem(i);
				_bullet->removeBullet(j);
				if (R == 0)
				{
					_soul->moveateck();
					_soul->setitem(x, y);
				}
				if (R == 1)
				{
					_soul1->moveateck();
					_soul1->setitem(x, y);
				}
				if (R == 2)
				{
					_soul2->moveateck();
					_soul2->setitem(x, y);
				}



				break;
			}

		}

	}



}

void player::playerEnemyCollision()
{
	for (int i = 0; i < _em->getVEyefly().size(); i++)
	{


			RECT temp;
			RECT rc = _em->getVEyefly()[i]->getRect();
			int x = (_em->getVEyefly()[i]->getRect().left + _em->getVEyefly()[i]->getRect().right) / 2;
			int y = (_em->getVEyefly()[i]->getRect().top + _em->getVEyefly()[i]->getRect().bottom) / 2;

			if (IntersectRect(&temp, &_witchAteckRC,&rc))
			{
				int R = rand() % 10;


				_em->removeEyefly(i);
				_em->removebluefire(i);
				_em->removeredfire(i);

				if (R == 1)
				{
					_item->setitem(x, y);
				}
				if (R == 2)
				{
					_soul->setitem(x, y);
				}
				if (R == 3)
				{
					_soul1->setitem(x, y);
				}
				if (R == 4)
				{
					_soul2->setitem(x, y);
				}
				break;
			}

		
	}
}
