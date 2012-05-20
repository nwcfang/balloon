// balloon.cpp: ���������� ����� ����� ��� ����������� ����������.
//
 

#include "stdafx.h"
#include "element.h"
#include "field.h"


#define WIDTH 50
#define HEIGHT 50

int main()
{
	srand(time(0));
	FILE *log;			// ���-�����
	FILE *log2;
	CField Field;		// �������� ����������� ���� � ��������� ������

	log = fopen( "log.txt", "w" );
	if( log == NULL )
	{
		fprintf(stderr, "failed open file\n");
		exit(2);
	}
	log2 = fopen( "log2.txt", "w" );
	if( log2 == NULL )
	{
		fprintf(stderr, "failed open file\n");
		exit(2);
	}

	Field.InitField( WIDTH, HEIGHT );

	if( Field.StartMove( 0, log2 ) == 1 )
	{
		printf( "Error: StartMove\n" );
		Field.ReleaseField( WIDTH, HEIGHT );
		exit(2);
	}

	Field.Statistic( log ); // ����������

	fclose( log );
	fclose( log2 );
	Field.ReleaseField( WIDTH, HEIGHT );

	return 0;
}

