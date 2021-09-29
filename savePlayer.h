#pragma once
#include "singletonBase.h"
#include "image.h"

class savePlayer : public singletonBase<savePlayer>
{
private:
	//ī�޶� ���ߴ� ȭ�� ũ��
	int _coin; //����
	int _score; //����
	int _Life; //���
	int _mana; //����
	int _dash; //�뽬
	int _Skill; //��ų
	int _combat; //�ٰ̰���
	bool _start;


public:
	savePlayer();
	~savePlayer();

	HRESULT init();
	void release();

	void getSetCoin(int coin) { _coin = coin; }
	void getSetScore(int score) { _score = score; }
	void getSetLife(int life) { _Life = life; }
	void getSetMana(int mana) { _mana = mana; }
	void getSetdash(int dash) { _dash = dash; }
	void getSetSkill(int skill) { _Skill = skill; }
	void getSetCombat(int combat) { _combat = combat; }
	void getSetBool(int start) { _start = start; }   //�ɷ�ġ ���� 

	int getCoin() { return _coin; }
	bool getstart() { return _start; }
	int getDash() { return _dash; }
	int getMana() { return _mana; }
	int getSkill() { return _Skill; }
	int getCombat() { return _combat; }
	int getLife() { return _Life; }
	int getScore() { return _score; }
	//void singcuro(int dash) { dash = _dash; }

};