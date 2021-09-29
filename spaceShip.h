#pragma once
#include "gameNode.h"
#include "bullets.h"
#include "progressBar.h"

#pragma warning(disable:4996)

//1. �����Ϸ� ���ѷ����� ���������� ����
//2. ����ӵ��� ���̱� ����
//��ȣ������ ���� Ŭ�� ���漱��
class enemyManager;

class spaceShip : public gameNode
{
private:
	image* _ship;
	missile* _missile;
	hyunMoo* _hm;

	//�굵 ������ �󲮵�����
	enemyManager* _em;

	progressBar* _hpBar;
	float _currentHP, _maxHP;

	int _alphaValue;

public:
	spaceShip();
	~spaceShip();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	//�浹�Խ�
	void collision();

	//�÷��̾� ������ ����ݽô�
	void hitDamage(float damage);

	//�̸��� ��ɽ� �׷����� ������ �Լ�
	void setEmMemoryAddressLink(enemyManager* em) { _em = em; }

	//������ ���� ������
	hyunMoo* getHyunMoo() { return _hm; }

	//�����̽��� �̹����� ���� ������
	image* getShipImage() { return _ship; }

};

