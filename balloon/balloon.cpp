// balloon.cpp: определяет точку входа для консольного приложения.
//
 

#include "stdafx.h"
#include "element.h"
#include "field.h"


#define WIDTH 3
#define HEIGHT 3

int main()
{
	FILE *log;			// лог-файл
	CField Field;		// содержит статическую базу и остальные данные

	log = fopen( "log.txt", "w" );
	if( log == NULL )
	{
		fprintf(stderr, "failed open file\n");
		exit(2);
	}

	Field.InitField( WIDTH, HEIGHT );
	Field.StartMove( 0 );
	Field.Statistic( log ); // статистика

	fclose( log );
	Field.ReleaseField( WIDTH, HEIGHT );

	return 0;
}

