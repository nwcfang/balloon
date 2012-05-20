// balloon.cpp: определяет точку входа для консольного приложения.
//
 

#include "stdafx.h"
#include "element.h"
#include "field.h"


#define WIDTH 50
#define HEIGHT 50

int main()
{
	srand(time(0));
	FILE *log;			// лог-файлы
	FILE *log2;
	CField Field;		// содержит статическую базу и остальные данные

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

	Field.Statistic( log ); // статистика

	fclose( log );
	fclose( log2 );
	Field.ReleaseField( WIDTH, HEIGHT );

	return 0;
}

