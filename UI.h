#pragma once
#include "gameNode.h"
#include "player.h"


class UI : public gameNode
{
private:

	image* _mana;
	int _manaMAX;
	image* dashBar; // 대쉬 바
	int dashMax; // 대쉬 사용 횟수
	image* combat; // 근접공격
	int combatMax; // 근접공격 횟수제한
	image* _skillImg; // 근접공격
	int _skilMax; // 스킬 횟수제한


	//그림자
	image* _manaS;
	image* _dashS;
	image* _combatS;
	image* _skillS;

	//str들

	image* coinImg;
	image* coinNum[10];

	image* ScoreImg;
	image* ScoreNum[10];

	int _Score;



	image* _lifeImg[3];
	int _life;



	//얼굴

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