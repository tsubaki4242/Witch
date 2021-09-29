#pragma once
#include "gameNode.h"

class enemy : public gameNode
{
protected:
	image* _imageName;		//���ʹ� �̹���
	RECT _rc;				//��Ʈ

	int _currentFrameX;		//�����ӹ�ȣ�� ����� ����
	int _currentFrameY;

	int _count;				//�����ӷ����� ��
	int _fireCount;			//�߻� ī��Ʈ ��
	int _rndFireCount;		//���� �߻� ī��Ʈ ��

	int enemyX, enemyY;

public:
	enemy() {};
	~enemy() {};

	virtual HRESULT init();
	virtual HRESULT init(const char* imageName, POINT position);
	virtual void release();
	virtual void update();
	virtual void render();

	void move();
	void draw();

	bool bulletCountFire();
	bool itemCountFire();


	inline RECT getRect() { return _rc; }

};
