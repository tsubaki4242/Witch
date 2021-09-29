#pragma once
#include "gameNode.h"
#include "bullet.h"
#include "item.h"
#include "skill.h"

class enemyManager;


enum MYTHSTATE
{
	IDLE,
	ATECK,
	SKILL,
	COUNTER,
	DASH
};

class player : public gameNode
{
private:
	//마녀 베이스
	image* _witch;
	int _witcjALP;
	int _alpatime;
	int _alpatime2;
	MYTHSTATE _WitchState;
	bool alpawitch;
	image* _witchS;
	animation* _witchStand;
	//-----------------------------
	image* _witchA;
	animation* _witchAteck;


	RECT _witchRC;
	int wx, wy; //렉트 위치
	int ww, wh;  //렉트 크기
	int cx, cy; //렉트 중심
	int _speed; //플레이어 스피드
	
	int AFcount; // 아이들로 돌아가기
	bool AFswitch;// 아이들로 스위치
	int _count, _count2,_index, _indexD;
	
	//공격렉트
	RECT _witchAteckRC;
	int ARx, ARy;


	//대쉬
	image* _dashImg;
	image* _dashImg1;
	image* _dashImg2;
	image* _dasgEffect;
	bool _dashSkill;
	int _dashSkillT;
	int _dashTimer;
	bool _dashRT;
	int dx, dy;
	int dx1, dy1;
	int dx2, dy2;

	//능력치 값
	bool _dash;
	bool _dashR;
	int dashBar;
	int _manaMax;
	int _skillMax;
	int _combatMax;

	int _life; //목숨
	int _score;

	//실질적 맵의 움직임

	RECT _Center;
	int CRX, CRY;

	//총알
	bullet* _bullet;

	//에너미 포인트
	enemyManager* _em;
	//아이템 포인트
	item* _item;
	item2* _item2;
	SOUL* _soul;
	SOUL1* _soul1;
	SOUL2* _soul2;


	//스킬 포인트
	skill* _skill;
	RECT _skillRECT;
	int _skilltime;
	bool _skillboll;
public:
	player() {};
	~player() {};

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void imgeAll();
	void imgeFrame();
	void keyAll();
	void zone();
	void death();
	void deathalpa();
	void deathSwith();
	void lifeDamge(int damge);

	void collision(); //충돌
	void Itemcollision();
	void skillCollision();
	void soulitemChangeCollision();
	void playerEnemyCollision();


	void setEmMemoryAddressLink(enemyManager* em) { _em = em; }

	int getX() { return cx;}
	int getY() { return cy; }

	RECT* getRCplayer() { return &_witchRC; }
	RECT* getRCplayerAteeck() { return &_witchAteckRC; }
	bullet* getMana() { return _bullet; }
	item* getitem() { return _item; }
	item2* getitem2() { return _item2; }
	SOUL* getsoul() { return _soul; }
	SOUL1* getsoul1() { return _soul1; }
	SOUL2* getsoul2() { return _soul2; }
	skill* getSkill() { return _skill; }
};
