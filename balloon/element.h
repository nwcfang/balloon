#pragma once

// Класс предназначен для хранения направления ветра для
// всех высот в одной точке
class CLevel
{
private:

public:
	CLevel();

	vector<int> volume;
	vector<int> direction;
};

// Класс отвечает за клетку на карте
class CElement
{
private:




public:
	CElement();
	int x;	// координаты
	int y;	// 
	
	CLevel Lvl;

	CElement *pUp;		// указатель на клетку выше
	CElement *pDown;	// указатель на клетку ниже
	CElement *pRight;	// указатель на клетку справа
	CElement *pLeft;	// указатель на клетку слева

	int SetLevel();
};

