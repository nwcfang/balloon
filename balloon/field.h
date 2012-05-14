#include "stdafx.h"
#include "element.h"

class CField
{
private:
	CElement *Head;
	vector<int> level;
	int startX;
	int startY;
	int endX;
	int endY;

public:
	// инициализирует поле
	CElement* InitField( const int width, const int height );
	// удаляет поле
	void ReleaseField( const int width, const int height );
	// статистика высот, на каторые
	int Statistic(FILE *outlog );
	// сбор начальных значений
	int InitConditions();
};


CElement* InitField( CElement **Elem, const int width, const int height );	
void ReleaseField( CElement *Elem, const int width, const int height );		// удаляет поле
int Statistic(FILE *outlog, vector<int> *level );	// статистика высот, на каторые
													// поднимался аэростат
int InitConditions();
