#pragma once
#include "gameNode.h"
#include <vector>

struct tagSkill
{
	image* SkillImage;
	RECT rc;
	RECT skillRc;
	float x, y;
	float angle;
	float radius;
	float speed;
	float fireX, fireY;
	bool isFire;
	int count;
};

class skill : public gameNode
{
private:
	vector<tagSkill>			_vskill;
	vector<tagSkill>::iterator _viSkill;


	float _range;
	int _skillMAX;

public:
	skill() {};
	~skill() {};

	HRESULT init(int itemMAX, float range);
	void release();
	void update();
	void render();

	void setSkill(float x, float y);

	void move();


	void removeSkill(int arrNum);


	vector<tagSkill> getVSkill() { return _vskill; }
	vector<tagSkill>::iterator getViSkill() { return _viSkill; }

};