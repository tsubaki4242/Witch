#pragma once
#include "singletonBase.h"
#include "image.h"

class savePlayer : public singletonBase<savePlayer>
{
private:
	//카메라가 비추는 화면 크기
	int _coin; //코인
	int _score; //점수
	int _Life; //목숨
	int _mana; //마력
	int _dash; //대쉬
	int _Skill; //스킬
	int _combat; //근겁공격
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
	void getSetBool(int start) { _start = start; }   //능력치 저장 

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