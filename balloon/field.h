#include "stdafx.h"
#include "element.h"

CElement* InitField( CElement **Elem, const int width, const int height ); // �������������� ����
void ReleaseField( CElement *Elem, const int width, const int height ); // ������� ����
int Statistic(FILE *outlog, vector<int> *level );