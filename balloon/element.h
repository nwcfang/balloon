#pragma once

// ����� ������������ ��� �������� ����������� ����� ���
// ���� ����� � ����� �����
class CLevel
{
private:

public:
	CLevel();

	vector<int> volume;
	vector<int> direction;
};

// ����� �������� �� ������ �� �����
class CElement
{
private:




public:
	CElement();
	int x;	// ����������
	int y;	// 
	
	CLevel Lvl;

	CElement *pUp;		// ��������� �� ������ ����
	CElement *pDown;	// ��������� �� ������ ����
	CElement *pRight;	// ��������� �� ������ ������
	CElement *pLeft;	// ��������� �� ������ �����

	int SetLevel();
};

