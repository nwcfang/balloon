// balloon.cpp: ���������� ����� ����� ��� ����������� ����������.
//
 

#include "stdafx.h"
#include "element.h"
#include "field.h"


#define WIDTH 3
#define HEIGHT 3

int main()
{
	FILE *log;			// ���-����
	CField Field;		// �������� ����������� ���� � ��������� ������

	log = fopen( "log.txt", "w" );
	if( log == NULL )
	{
		fprintf(stderr, "failed open file\n");
		exit(2);
	}

	Field.InitField( WIDTH, HEIGHT );
	Field.StartMove( 0 );
	Field.Statistic( log ); // ����������

	fclose( log );
	Field.ReleaseField( WIDTH, HEIGHT );

	return 0;
}

