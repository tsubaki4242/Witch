#include "stdafx.h"
#include "saveLoadTest.h"


saveLoadTest::saveLoadTest()
{
}


saveLoadTest::~saveLoadTest()
{
}

void saveLoadTest::update()
{
	//if (KEYMANAGER->isOnceKeyDown(VK_F1)) save();
	//if (KEYMANAGER->isOnceKeyDown(VK_F2)) load();
}

void saveLoadTest::save()
{
	//���� �����
	//C   - FILE* ��ɾ��� ��ɾ������ ����
	//C++ - ifstream, ofstream - ��� ���� �׷������� ����
	//WIN32 - CreateFile - ������ ���������� ����.
	//����Ƽ - jSon

	HANDLE file;
	DWORD write;

	char str[128] = "�����̴� �������� ������ �������� �̸������ض�";

	file = CreateFile("����.txt", GENERIC_WRITE, FALSE,
		NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	WriteFile(file, str, strlen(str), &write, NULL);

	CloseHandle(file);
}

void saveLoadTest::load()
{
	HANDLE file;
	DWORD read;

	//���ڿ� �о���̴� ���ۼ���ŭ �׶��׶� �����Ҵ� �ϸ�
	//�� ����ϰ� �������ϴ�
	char str[128];

	file = CreateFile("����.txt", GENERIC_READ, FALSE,
		NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	ReadFile(file, str, strlen(str), &read, NULL);

	CloseHandle(file);

	//MessageBox(_hWnd, str, "���� �ݿ��� ��ȹ�� ����?", MB_OK);
}
