#pragma once

// ����� �������� �� ������ �� �����
class CElement
{
private:




public:
	CElement();
	int x;	// ����������
	int y;	// 


	CElement *pUp;		// ��������� �� ������ ����
	CElement *pDown;	// ��������� �� ������ ����
	CElement *pRight;	// ��������� �� ������ ������
	CElement *pLeft;	// ��������� �� ������ �����
	//inline CElement* GetUp();
	//inline CElement* GetDown();
	//inline CElement* GetRight();
	//inline CElement* GetLeft();

	//inline CElement* SetUp();
	//inline CElement* SetDown();
	//inline CElement* SetRight();
	//inline CElement* SetLeft();
};
