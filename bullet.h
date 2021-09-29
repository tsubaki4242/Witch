#pragma once
#include "gameNode.h"
#include <vector>

struct tagBullet
{
	image* bulletImage;		//총알 이미지 
	RECT rc;				//총알 렉트
	float x, y;				//총알 좌표(실시간)
	float angle;			//총알 각도
	float radius;			//총알 반지름
	float speed;			//총알 스피드
	float fireX, fireY;		//총알 발사시 처음 좌표(발사된 좌표)
	bool isFire;			//발사됐누?
	int count;				//총알 프레임카운트용
};

class bullet : public gameNode
{
private:
	vector<tagBullet>			_vBullet;
	vector<tagBullet>::iterator _viBullet;

		
	float _range;	
	int _bulletMax;

public:
	bullet() {};
	~bullet() {};

	HRESULT init(int bulletMax, float range);
	void release();
	void update();
	void render();

	void fire(float x, float y);

	void move();

	//총알을 지워달라고 소통하는 함수
	void removeBullet(int arrNum);


	vector<tagBullet> getVBullet() { return _vBullet; }
	vector<tagBullet>::iterator getViBullet() { return _viBullet; }

};

class flyeyeB : public gameNode
{
private:
	vector<tagBullet>			_vBullet;
	vector<tagBullet>::iterator _viBullet;

	float _range;
	int _bulletMax;

public:
	flyeyeB() {};
	~flyeyeB() {};

	HRESULT init(int bulletMax, float range);
	void release();
	void update();
	void render();

	void fire(float x, float y);

	void move();

	void removeflyeyeB(int arrNum);

	vector<tagBullet> getVflyeyeB() { return _vBullet; }
	vector<tagBullet>::iterator getVIflyeyeB() { return _viBullet; }
};

class bossBullet : public gameNode
{
private:
	vector<tagBullet>			_vBullet;
	vector<tagBullet>::iterator _viBullet;


	float _range;
	int _bulletMax;

public:
	bossBullet() {};
	~bossBullet() {};

	HRESULT init(int bulletMax, float range);
	void release();
	void update();
	void render();

	void fire(float x, float y);

	void move();

	//총알을 지워달라고 소통하는 함수
	void removeBullet(int arrNum);


	vector<tagBullet> getVBullet() { return _vBullet; }
	vector<tagBullet>::iterator getViBullet() { return _viBullet; }

};