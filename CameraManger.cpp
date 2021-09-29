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
	//backDC�� frontDCũ�� ����
	_backX = width;
	_backY = height;
	_frontX = WINSIZEX;
	_frontY = WINSIZEY;



	//��ũ�� ����
	_screen = RectMake(0, 0, WINSIZEX, WINSIZEY);

	return S_OK;
}

void CameraManager::release()
{
}

void CameraManager::updateScreen(int standardX, int standardY)
{


	//�¿�(X)
	if (standardX - _frontX / 2 < 0)
		standardX = 0;
	else if (standardX + _frontX / 2 > _backX)
		standardX = _backX - _frontX;
	else
		standardX -= _frontX / 2;
	//����(Y)
	if (standardY - 2 * _frontY / 3 < 0)
		standardY = 0;
	else if (standardY + _frontY / 3 > _backY)
		standardY = _backY - _frontY;
	else
		standardY -= 2 * _frontY / 3;

	_getX = standardX;
	_getY = standardY;
	//�̹��� ���
	_screen = RectMake(standardX, standardY, _frontX, _frontY);


}

void CameraManager::updateScreenStart(int standardX, int standardY, int startX, int startY)
{
	//�¿�(X)
	if (standardX - startX < 0)
		standardX = 0;
	else if (standardX + startX > _backX)
		standardX = _backX - _frontX;
	else
		standardX -= startX;
	//����(Y)
	if (standardY - 2 * startY < 0)
		standardY = 0;
	else if (standardY + startY > _backY)
		standardY = _backY - _frontY;
	else
		standardY -= 2 * startY;

	_getX = standardX;
	_getY = standardY;
	//�̹��� ���
	_screen = RectMake(standardX, standardY, _frontX, _frontY);


}

void CameraManager::render(HDC frontDC, int destX, int destY, HDC backDC, bool mini)
{
	//�̴ϸ� ������ true�� ��ũ���� ������ܿ� �̴ϸ� ���
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
		frontDC,				//����޴� DC
		destX,					//����޴� ��ǥ(left)
		destY,					//����޴� ��ǥ(top)
		_frontX,			//����Ǵ� ����ũ��
		_frontY,			//����Ǵ� ����ũ��
		backDC,					//����Ǵ� DC
		_screen.left, _screen.top,	//����Ǵ� ������ǥ(left, top)
		SRCCOPY);				//�״�� �����ؿ���(���)


}
