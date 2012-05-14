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
	// �������������� ����
	CElement* InitField( const int width, const int height );
	// ������� ����
	void ReleaseField( const int width, const int height );
	// ���������� �����, �� �������
	int Statistic(FILE *outlog );
	// ���� ��������� ��������
	int InitConditions();
};


CElement* InitField( CElement **Elem, const int width, const int height );	
void ReleaseField( CElement *Elem, const int width, const int height );		// ������� ����
int Statistic(FILE *outlog, vector<int> *level );	// ���������� �����, �� �������
													// ���������� ��������
int InitConditions();
