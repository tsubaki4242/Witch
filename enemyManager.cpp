#include "stdafx.h"
#include "enemyManager.h"
#include "player.h"

HRESULT enemyManager::init()
{

	_bullet = new flyeyeB;
	_bullet->init(30, 2000);

	_bossBullet = new bossBullet;
	_bossBullet->init(300, 1000);

	return S_OK;
}

void enemyManager::release()
{
}

void enemyManager::update()
{
	for (_viEyefly = _vEyefly.begin(); _viEyefly != _vEyefly.end(); ++_viEyefly)
	{
		(*_viEyefly)->update();
		(*_viEyefly)->move();
	}
	for (_vibluefire = _vbluefire.begin(); _vibluefire != _vbluefire.end(); ++_vibluefire)
	{
		(*_vibluefire)->update();
		(*_vibluefire)->move();
	}
	for (_viredFire = _vredFire.begin(); _viredFire != _vredFire.end(); ++_viredFire)
	{
		(*_viredFire)->update();
		(*_viredFire)->move();
	}
	for (_viBossk = _vBossk.begin(); _viBossk != _vBossk.end(); ++_viBossk)
	{
		(*_viBossk)->update();
		(*_viBossk)->move();
	}
	BulletFire();
	_bullet->update();
	_bossBullet->update();
//	collision();
}

void enemyManager::render()
{
	for (_viEyefly = _vEyefly.begin(); _viEyefly != _vEyefly.end(); ++_viEyefly)
	{
		(*_viEyefly)->render();
	}
	for (_vibluefire = _vbluefire.begin(); _vibluefire != _vbluefire.end(); ++_vibluefire)
	{
		(*_vibluefire)->render();
	}
	for (_viredFire = _vredFire.begin(); _viredFire != _vredFire.end(); ++_viredFire)
	{
		(*_viredFire)->render();
	}
	for (_viBossk = _vBossk.begin(); _viBossk != _vBossk.end(); ++_viBossk)
	{
		(*_viBossk)->render();
	}
	_bullet->render();
	_bossBullet->render();
}

void enemyManager::setEyefly()
{
	for (int i = 0; i < 3; i++)
	{
		enemy* eyeflyImg;
		eyeflyImg = new eyefly;
		eyeflyImg->init("eyefly", PointMake(1000 + i * 200 , 100 + i * 100));

		_vEyefly.push_back(eyeflyImg);
	}
	for (int j = 0; j < 3; j++)
	{
		enemy* eyeflyImg;
		eyeflyImg = new eyefly;
		eyeflyImg->init("eyefly", PointMake(3000 + j * 300, 700 - j * 100));

		_vEyefly.push_back(eyeflyImg);
	}
	for (int j = 0; j < 3; j++)
	{
		enemy* eyeflyImg;
		eyeflyImg = new eyefly;
		eyeflyImg->init("eyefly", PointMake(5000 + j * 200, 100 + j * 50));

		_vEyefly.push_back(eyeflyImg);
	}
	for (int j = 0; j < 2; j++)
	{
		enemy* eyeflyImg;
		eyeflyImg = new eyefly;
		eyeflyImg->init("eyefly", PointMake(7000 + j * 500, 100 + j * 150));

		_vEyefly.push_back(eyeflyImg);
	}
	for (int j = 0; j < 2; j++)
	{
		enemy* eyeflyImg;
		eyeflyImg = new eyefly;
		eyeflyImg->init("eyefly", PointMake(8000 + j * 500, 500 - j * 150));

		_vEyefly.push_back(eyeflyImg);
	}
}

void enemyManager::BulletFire()
{
	for (_viEyefly = _vEyefly.begin(); _viEyefly != _vEyefly.end(); ++_viEyefly)
	{
		if ((*_viEyefly)->bulletCountFire())
		{
			RECT rc = (*_viEyefly)->getRect();
			_bullet->fire((rc.left + rc.right) / 2, (rc.bottom + rc.top) / 2);
		}
	}
	//for (_viBossk = _vBossk.begin(); _viBossk != _vBossk.end(); ++_viBossk)
	//{
	//	if ((*_viBossk)->bulletCountFire())
	//	{
	//		RECT rc = (*_viBossk)->getRect();
	//		_bossBullet->fire((rc.left + rc.right) / 2 , (rc.bottom + rc.top) / 2);
	//		_bossBullet->fire((rc.left + rc.right) / 2 -300, (rc.bottom + rc.top) / 2);
	//	}
	//}
}

void enemyManager::setbluefire()
{
	for (int i = 0; i < 3; i++)
	{

		_blueFire = new blueFire;
		_blueFire->init("bluefire", PointMake(1800 + i * 300, 100 + i * 100));

		_vbluefire.push_back(_blueFire);
	}
	for (int i = 0; i < 3; i++)
	{

		_blueFire = new blueFire;
		_blueFire->init("bluefire", PointMake(2900 + i * 300, 400 + i * 50));

		_vbluefire.push_back(_blueFire);
	}
	for (int i = 0; i < 2; i++)
	{

		_blueFire = new blueFire;
		_blueFire->init("bluefire", PointMake(5900 + i * 300, 400 + i * 50));

		_vbluefire.push_back(_blueFire);
	}
}

void enemyManager::setredfire()
{
	for (int i = 0; i < 3; i++)
	{

		_redFire = new redFire;
		_redFire->init("redfire", PointMake(1800 + i * 300, 600 - i * 100));

		_vredFire.push_back(_redFire);
	}
	for (int i = 0; i < 5; i++)
	{

		_redFire = new redFire;
		_redFire->init("redfire", PointMake(3600 + i * 300, 600 - i * 50));

		_vredFire.push_back(_redFire);
	}
	for (int i = 0; i < 5; i++)
	{

		_redFire = new redFire;
		_redFire->init("redfire", PointMake(5600 + i * 300, 100 + i * 50));

		_vredFire.push_back(_redFire);
	}
	for (int i = 0; i < 5; i++)
	{

		_redFire = new redFire;
		_redFire->init("redfire", PointMake(7200 + i * 300, 600 - i * 50));

		_vredFire.push_back(_redFire);
	}
	for (int i = 0; i < 5; i++)
	{

		_redFire = new redFire;
		_redFire->init("redfire", PointMake(9500 + i * 300, 100 + i * 50));

		_vredFire.push_back(_redFire);
	}
}

void enemyManager::setboss()
{
	_Bossk = new bossK;
	_Bossk->init("boss!!", PointMake(9600 , 300));

	_vBossk.push_back(_Bossk);
}

void enemyManager::removeEyefly(int arrNum)
{
	_vEyefly.erase(_vEyefly.begin() + arrNum);
}

void enemyManager::removebluefire(int arrNum)
{
	_vbluefire.erase(_vbluefire.begin() + arrNum);
}

void enemyManager::removeredfire(int arrNum)
{
	_vredFire.erase(_vredFire.begin() + arrNum);
}

void enemyManager::removerBoss(int arrNum)
{
}

void enemyManager::collision()
{

		RECT temp;
		RECT rc = RectMake(_pl->getRCplayer()->left, _pl->getRCplayer()->top, _pl->getRCplayer()->right- _pl->getRCplayer()->left, _pl->getRCplayer()->bottom - _pl->getRCplayer()->top);
		RECT rc2 = RectMake(_pl->getRCplayerAteeck()->left, _pl->getRCplayerAteeck()->top,
			_pl->getRCplayerAteeck()->right - _pl->getRCplayerAteeck()->left, _pl->getRCplayerAteeck()->bottom - _pl->getRCplayerAteeck()->top);
		for (_viEyefly = _vEyefly.begin(); _viEyefly != _vEyefly.end(); ++_viEyefly)
		{
			RECT rc5 = (*_viEyefly)->getRect();
			if (IntersectRect(&temp, &rc5, &rc))
			{

				_pl->lifeDamge(1);
				_pl->death();
				_pl->deathSwith();
			}


		}
		for (_vibluefire = _vbluefire.begin(); _vibluefire != _vbluefire.end(); ++_vibluefire)
		{
			RECT rc2 = (*_vibluefire)->getRect();
			RECT rc3 = CAMERAMANAGER->getRect();

			if (IntersectRect(&temp, &rc2, &rc))
			{

				_pl->lifeDamge(1);
				_pl->death();
				_pl->deathSwith();

			}
		}



		for (int i = 0; i < _bullet->getVflyeyeB().size(); i++)
		{

			if (IntersectRect(&temp, &_bullet->getVflyeyeB()[i].rc, &rc))
			{
				_bullet->removeflyeyeB(i);
				_pl->lifeDamge(1);
				_pl->death();
				_pl->deathSwith();
				break;
			}
			if (IntersectRect(&temp, &_bullet->getVflyeyeB()[i].rc, &rc2))
			{
				_bullet->removeflyeyeB(i);


				break;
			}



		}

		
	
}
