#pragma once
#include "gameNode.h"
#include "player.h"


class UI : public gameNode
{
private:

	image* _mana;
	int _manaMAX;
	image* dashBar; // �뽬 ��
	int dashMax; // �뽬 ��� Ƚ��
	image* combat; // ��������
	int combatMax; // �������� Ƚ������
	image* _skillImg; // ��������
	int _skilMax; // ��ų Ƚ������


	//�׸���
	image* _manaS;
	image* _dashS;
	image* _combatS;
	image* _skillS;

	//str��

	image* coinImg;
	image* coinNum[10];

	image* ScoreImg;
	image* ScoreNum[10];

	int _Score;



	image* _lifeImg[3];
	int _life;



	//��

	image* _face;
	int _count, _index, _index2;
	int _coin;

	bool _state, coinBreack;

	player* _play;

public:
	UI() {};
	~UI() {};



	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void SetCoin(int coin) { _coin = coin; }
	void SetStart(bool state) { _state = state; }

};