#include "stdafx.h"
#include "element.h"

class CField
{
private:
	CElement *Head;
	CElement *Tail;
	vector<int> level;	// вектор содержит статистику высот, на которые поднимался шар
	int startX;
	int startY;
	int endX;
	int endY;
	int ammo;
	int helium;

	int currentLevel; 
	int currentAmmo;
	int currentX;
	int currentY;

	// сбор начальных значений
	int InitConditions();
	// возвращает указательна точку поля
	CElement* GetPoint( int x, int y );
	// движение по короткому пути
	int ShortWay();
	// поиск нужного направления ветра
	int SearchDirect(CElement *Point, int direction);
	// поиск приближенного к нужному
	//int SecondSearchDirect();
	// корректировка направления 
	int Correction(int *dr);
	//
	int MoveObj( int dr );



public:
	CField();
	// инициализирует поле
	CElement* InitField( const int width, const int height );
	// удаляет поле
	void ReleaseField( const int width, const int height );
	// статистика высот, на каторые поднимался аэростат
	int Statistic(FILE *outlog );
	// начать отработку маршрута
	int StartMove( int variant );

	
};


CElement* InitField( CElement **Elem, const int width, const int height );	
void ReleaseField( CElement *Elem, const int width, const int height );		// удаляет поле
int Statistic(FILE *outlog, vector<int> *level );	// статистика высот, на каторые
													// поднимался аэростат
int InitConditions();
