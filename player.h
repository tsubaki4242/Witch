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
	//���� ���̽�
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
	int wx, wy; //��Ʈ ��ġ
	int ww, wh;  //��Ʈ ũ��
	int cx, cy; //��Ʈ �߽�
	int _speed; //�÷��̾� ���ǵ�
	
	int AFcount; // ���̵�� ���ư���
	bool AFswitch;// ���̵�� ����ġ
	int _count, _count2,_index, _indexD;
	
	//���ݷ�Ʈ
	RECT _witchAteckRC;
	int ARx, ARy;


	//�뽬
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

	//�ɷ�ġ ��
	bool _dash;
	bool _dashR;
	int dashBar;
	int _manaMax;
	int _skillMax;
	int _combatMax;

	int _life; //���
	int _score;

	//������ ���� ������

	RECT _Center;
	int CRX, CRY;

	//�Ѿ�
	bullet* _bullet;

	//���ʹ� ����Ʈ
	enemyManager* _em;
	//������ ����Ʈ
	item* _item;
	item2* _item2;
	SOUL* _soul;
	SOUL1* _soul1;
	SOUL2* _soul2;


	//��ų ����Ʈ
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

	void collision(); //�浹
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
