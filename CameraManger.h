#pragma once
#include "singletonBase.h"
#include "image.h"

class CameraManager : public singletonBase<CameraManager>
{
private:
	//카메라가 비추는 화면 크기
	RECT _screen;
	int _backX, _backY;	//backDC 크기
	int _frontX, _frontY;	//frontDC 크기
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

