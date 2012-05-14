// balloon.cpp: ���������� ����� ����� ��� ����������� ����������.
//
 

#include "stdafx.h"
#include "element.h"
#include "field.h"


#define WIDTH 3
#define HEIGHT 3

int main()
{
	FILE *log;
	vector<int> vStat; // ������ �������� ���������� �����, �� ������� ���������� ���
	log = fopen( "log.txt", "w" );
	if( log == NULL )
	{
		fprintf(stderr, "failed open file\n");
		exit(2);
	}

	CElement *Head = NULL;
	CElement *Tail = NULL;

	Tail = InitField( &Head, WIDTH, HEIGHT ); // �������� ����������� ����
	InitConditions();

	Statistic( log, &vStat ); // ����������

	fclose( log );
	ReleaseField( Head, WIDTH, HEIGHT );
	vStat.clear();
	return 0;
}

