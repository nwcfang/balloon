// balloon.cpp: определяет точку входа для консольного приложения.
//
 

#include "stdafx.h"
#include "element.h"
#include "field.h"


#define WIDTH 3
#define HEIGHT 3

int main()
{
	CElement *Head = NULL;
	CElement *Tail = NULL;

	Tail = InitField( &Head, WIDTH, HEIGHT ); 
	ReleaseField( Head, WIDTH, HEIGHT );
	return 0;
}

