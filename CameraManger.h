#pragma once
#include "singletonBase.h"
#include "image.h"

class CameraManager : public singletonBase<CameraManager>
{
private:
	//ī�޶� ���ߴ� ȭ�� ũ��
	RECT _screen;
	int _backX, _backY;	//backDC ũ��
	int _frontX, _frontY;	//frontDC ũ��
	int _getX, _getY;


public:
	CameraManager();
	~CameraManager();

	HRESULT init(int width, int height);
	void release();

	void updateScreen(int standardX, int standardY);
	void updateScreenStart(int standardX, int standardY, int startX, int startY);

	void render(HDC frontDC, int destX, int destY, HDC backDC, bool mini = false);
	RECT getRect() { return _screen; }


};

