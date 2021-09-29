#pragma once
#include "gameNode.h"
#include <vector>

 
struct tagItem
{
	image* itemImage;
	RECT rc;
	float x, y;
	float angle;
	float radius;
	float speed;
	float fireX, fireY;
	bool isFire;
	int count;
};

class item : public gameNode
{
private:
	vector<tagItem>			_vitem;
	vector<tagItem>::iterator _viitem;


	float _range;
	int _bulletMax;

public:
	item() {};
	~item() {};

	HRESULT init(int itemMAX, float range);
	void release();
	void update();
	void render();

	void setitem(float x, float y);

	void move();


	void removeitem(int arrNum);


	vector<tagItem> getVitem() { return _vitem; }
	vector<tagItem>::iterator getViitem() { return _viitem; }

};

class item2 : public gameNode
{
private:
	vector<tagItem>			_vitem;
	vector<tagItem>::iterator _viitem;


	float _range;
	int _bulletMax;

public:
	item2() {};
	~item2() {};

	HRESULT init(int itemMAX, float range);
	void release();
	void update();
	void render();

	void setitem(float x, float y);

	void move();


	void removeitem(int arrNum);


	vector<tagItem> getVitem2() { return _vitem; }
	vector<tagItem>::iterator getViitem2() { return _viitem; }

};


class SOUL : public gameNode
{
private:
	vector<tagItem>			_vitem;
	vector<tagItem>::iterator _viitem;


	float _range;
	int _bulletMax;
	int _timer;
	bool Bswitch;
public:
	SOUL() {};
	~SOUL() {};

	HRESULT init(int itemMAX, float range);
	void release();
	void update();
	void render();

	void setitem(float x, float y);

	void move();
	void move2();
	void moveateck();

	void removeitem(int arrNum);


	vector<tagItem> getSOUL() { return _vitem; }
	vector<tagItem>::iterator getViSOUL() { return _viitem; }

};

class SOUL1 : public gameNode
{
private:
	vector<tagItem>			_vitem;
	vector<tagItem>::iterator _viitem;


	float _range;
	int _bulletMax;
	int _timer;
	bool Bswitch;
public:
	SOUL1() {};
	~SOUL1() {};

	HRESULT init(int itemMAX, float range);
	void release();
	void update();
	void render();

	void setitem(float x, float y);

	void move();
	void move2();
	void moveateck();


	void removeitem(int arrNum);


	vector<tagItem> getSOUL1() { return _vitem; }
	vector<tagItem>::iterator getViSOUL1() { return _viitem; }

};

class SOUL2 : public gameNode
{
private:
	vector<tagItem>			_vitem;
	vector<tagItem>::iterator _viitem;


	float _range;
	int _bulletMax;
	int _timer;
	bool Bswitch;

public:
	SOUL2() {};
	~SOUL2() {};

	HRESULT init(int itemMAX, float range);
	void release();
	void update();
	void render();

	void setitem(float x, float y);

	void move();
	void move2();
	void moveateck();


	void removeitem(int arrNum);


	vector<tagItem> getSOUL2() { return _vitem; }
	vector<tagItem>::iterator getViSOUL2() { return _viitem; }

};