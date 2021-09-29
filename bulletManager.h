#pragma once
#include "gameNode.h"
#include <vector>


class bulletManager : public gameNode
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

	//�Ѿ��� �����޶�� �����ϴ� �Լ�
	void removeBullet(int arrNum);


	vector<tagBullet> getVBullet() { return _vBullet; }
	vector<tagBullet>::iterator getViBullet() { return _viBullet; }

};