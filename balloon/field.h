#include "stdafx.h"
#include "element.h"

CElement* InitField( CElement **Elem, const int width, const int height ); // инициализирует поле
void ReleaseField( CElement *Elem, const int width, const int height ); // удаляет поле
int Statistic(FILE *outlog, vector<int> *level );