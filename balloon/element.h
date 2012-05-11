#pragma once

// Класс отвечает за клетку на карте
class CElement
{
private:




public:
	CElement();
	int x;	// координаты
	int y;	// 


	CElement *pUp;		// указатель на клетку выше
	CElement *pDown;	// указатель на клетку ниже
	CElement *pRight;	// указатель на клетку справа
	CElement *pLeft;	// указатель на клетку слева
	//inline CElement* GetUp();
	//inline CElement* GetDown();
	//inline CElement* GetRight();
	//inline CElement* GetLeft();

	//inline CElement* SetUp();
	//inline CElement* SetDown();
	//inline CElement* SetRight();
	//inline CElement* SetLeft();
};
