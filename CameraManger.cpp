#include "stdafx.h"
#include "CameraManger.h"

CameraManager::CameraManager()
{
}

CameraManager::~CameraManager()
{
}

HRESULT CameraManager::init(int width, int height)
{
	//backDC와 frontDC크기 설정
	_backX = width;
	_backY = height;
	_frontX = WINSIZEX;
	_frontY = WINSIZEY;



	//스크린 생성
	_screen = RectMake(0, 0, WINSIZEX, WINSIZEY);

	return S_OK;
}

void CameraManager::release()
{
}

void CameraManager::updateScreen(int standardX, int standardY)
{


	//좌우(X)
	if (standardX - _frontX / 2 < 0)
		standardX = 0;
	else if (standardX + _frontX / 2 > _backX)
		standardX = _backX - _frontX;
	else
		standardX -= _frontX / 2;
	//상하(Y)
	if (standardY - 2 * _frontY / 3 < 0)
		standardY = 0;
	else if (standardY + _frontY / 3 > _backY)
		standardY = _backY - _frontY;
	else
		standardY -= 2 * _frontY / 3;

	_getX = standardX;
	_getY = standardY;
	//이미지 출력
	_screen = RectMake(standardX, standardY, _frontX, _frontY);


}

void CameraManager::updateScreenStart(int standardX, int standardY, int startX, int startY)
{
	//좌우(X)
	if (standardX - startX < 0)
		standardX = 0;
	else if (standardX + startX > _backX)
		standardX = _backX - _frontX;
	else
		standardX -= startX;
	//상하(Y)
	if (standardY - 2 * startY < 0)
		standardY = 0;
	else if (standardY + startY > _backY)
		standardY = _backY - _frontY;
	else
		standardY -= 2 * startY;

	_getX = standardX;
	_getY = standardY;
	//이미지 출력
	_screen = RectMake(standardX, standardY, _frontX, _frontY);


}

void CameraManager::render(HDC frontDC, int destX, int destY, HDC backDC, bool mini)
{
	//미니맵 변수가 true면 스크린의 우측상단에 미니맵 출력
	if (mini) {
		SetStretchBltMode(backDC, COLORONCOLOR);
		StretchBlt(
			backDC,
			_screen.right - _frontX / 4,
			_screen.top,
			_frontX / 4,
			_frontY / 5,
			backDC,
			_screen.left,
			_screen.top,
			_frontX,
			_frontY,
			SRCCOPY);
	}

	BitBlt(
		frontDC,				//복사받는 DC
		destX,					//복사받는 좌표(left)
		destY,					//복사받는 좌표(top)
		_frontX,			//복사되는 가로크기
		_frontY,			//복사되는 세로크기
		backDC,					//복사되는 DC
		_screen.left, _screen.top,	//복사되는 시작좌표(left, top)
		SRCCOPY);				//그대로 복사해오기(모드)


}
