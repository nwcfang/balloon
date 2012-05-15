#include "stdafx.h"
#include "element.h"

class CField
{
private:
	CElement *Head;
	CElement *Tail;
	vector<int> level;	// ������ �������� ���������� �����, �� ������� ���������� ���
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

	// ���� ��������� ��������
	int InitConditions();
	// ���������� ����������� ����� ����
	CElement* GetPoint( int x, int y );
	// �������� �� ��������� ����
	int ShortWay();
	// ����� ������� ����������� �����
	int SearchDirect(CElement *Point, int direction);
	// ����� ������������� � �������
	//int SecondSearchDirect();
	// ������������� ����������� 
	int Correction(int *dr);
	//
	int MoveObj( int dr );



public:
	CField();
	// �������������� ����
	CElement* InitField( const int width, const int height );
	// ������� ����
	void ReleaseField( const int width, const int height );
	// ���������� �����, �� ������� ���������� ��������
	int Statistic(FILE *outlog );
	// ������ ��������� ��������
	int StartMove( int variant );

	
};


CElement* InitField( CElement **Elem, const int width, const int height );	
void ReleaseField( CElement *Elem, const int width, const int height );		// ������� ����
int Statistic(FILE *outlog, vector<int> *level );	// ���������� �����, �� �������
													// ���������� ��������
int InitConditions();
