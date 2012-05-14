#include "stdafx.h"
#include "element.h"

class CField
{
private:
	CElement *Head;
	vector<int> level;	// вектор содержит статистику высот, на которые поднималс€ шар
	int startX;
	int startY;
	int endX;
	int endY;
	int ammo;

	int currentLevel; 
	int currentAmmo;
	int currentX;
	int currentY;

	// сбор начальных значений
	int InitConditions();

public:
	CField();
	// инициализирует поле
	CElement* InitField( const int width, const int height );
	// удал€ет поле
	void ReleaseField( const int width, const int height );
	// статистика высот, на каторые поднималс€ аэростат
	int Statistic(FILE *outlog );
	
};


CElement* InitField( CElement **Elem, const int width, const int height );	
void ReleaseField( CElement *Elem, const int width, const int height );		// удал€ет поле
int Statistic(FILE *outlog, vector<int> *level );	// статистика высот, на каторые
													// поднималс€ аэростат
int InitConditions();
