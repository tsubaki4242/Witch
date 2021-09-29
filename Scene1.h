#pragma once
#include "gameNode.h"
#include "player.h"
#include "UI.h"
#include "enemyManager.h"



class Scene1 : public gameNode
{
private:
	image* background;
	image* backgroundForest;
	enemyManager* _em;

	player* _player;

	UI* _UI;

public:
	Scene1() {};
	~Scene1() {};

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();


};
