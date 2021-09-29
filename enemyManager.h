#pragma once
#include "gameNode.h"
#include "enemy.h"
#include "eyefly.h"
#include "blueFire.h"
#include "redFire.h"
#include "bullet.h"
#include "bossK.h"
#include "item.h"
#include <vector>

class player;


class enemyManager : public gameNode
{
private:
	typedef vector<enemy*>				vEnemy;
	typedef vector<enemy*>::iterator	viEnemy;

	typedef vector<blueFire*>			vblueFire;
	typedef vector<blueFire*>::iterator	viblueFire;

	typedef vector<redFire*>			vredFire;
	typedef vector<redFire*>::iterator	viredFire;

	typedef vector<bossK*>			    vBossk;
	typedef vector<bossK*>::iterator	viBossk;

private:
	vEnemy _vEyefly;
	viEnemy _viEyefly;
	vblueFire _vbluefire;
	viblueFire _vibluefire;
	vredFire  _vredFire;
	viredFire _viredFire;
	vBossk   _vBossk;
	viBossk    _viBossk;




	enemy* _em;
	blueFire* _blueFire;
	redFire* _redFire;
	bossK* _Bossk;

	flyeyeB* _bullet;
	bossBullet* _bossBullet;


	item* _item;
	player* _pl;


	bool itemSet;
public:
	enemyManager() {};
	~enemyManager() {};

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void setEyefly();
	void BulletFire();
	void setbluefire();
	void setredfire();
	void setboss();

	void removeEyefly(int arrNum);
	void removebluefire(int arrNum);
	void removeredfire(int arrNum);
	void removerBoss(int arrNum);

	void collision();

	void playerlink(player* player) { _pl = player; }

	vector<enemy*> getVEyefly() { return _vEyefly; }
	vector<enemy*>::iterator getVIEyefly() { return _viEyefly; }
	vector<blueFire*>	getvblueFire() { return _vbluefire; }
	vector<blueFire*>::iterator	getviblueFire() { return _vibluefire; }
	vector<redFire*>	getvredFire() { return _vredFire; }
	vector<redFire*>::iterator	getviredFire() { return _viredFire; }
	vector<bossK*>			    getvBossk() { return _vBossk; }
	vector<bossK*>::iterator	getviBossk() { return _viBossk; }
};

