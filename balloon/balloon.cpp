// balloon.cpp: определяет точку входа для консольного приложения.
//
 

#include "stdafx.h"
#include "element.h"
#include "field.h"


#define WIDTH 3
#define HEIGHT 3

int main()
{
	FILE *log;
	log = fopen( "log.txt", "w" );
	if( log == NULL )
	{
		fprintf(stderr, "failed open file\n");
		exit(2);
	}

	CElement *Head = NULL;
	CElement *Tail = NULL;

	Tail = InitField( &Head, WIDTH, HEIGHT );
	vector<int> a;
	Statistic( log, &a ); 

	fclose( log );
	ReleaseField( Head, WIDTH, HEIGHT );
	return 0;
}

