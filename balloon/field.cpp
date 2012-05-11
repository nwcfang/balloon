#include "stdafx.h"
#include "element.h"

CElement* InitField( CElement **Elem, const int width, const int height )
{
	*Elem = new CElement;
	if( Elem != NULL )
	{
		fprintf(stderr, "Ошибка выделения памяти\n");
		exit(2);
	}
	CElement *Tail = *Elem;
	CElement *PrevTail = NULL;
	CElement *HeadStr = *Elem;
	int correctWidth = width - 1;

	for( int i = 0; i < height; ++ i )
	{

		for( int j = 0; j < correctWidth; ++ j )
		{
 
			Tail->pRight = new CElement;
			if( Tail->pRight == NULL )
			{
				fprintf(stderr, "Ошибка выделения памяти\n");
				exit(2);
			}

			Tail->pRight->pLeft = Tail;
			Tail = Tail->pRight;
			if( PrevTail )
			{
				PrevTail =  PrevTail->pRight;
				PrevTail->pUp = Tail;
				Tail->pDown = PrevTail;
				
			}
			
			Tail->x = j + 1;
			Tail->y = i;
			if( i == width - 2 )
			{
				if( PrevTail )
				{
					PrevTail->pUp = Tail;
					Tail->pDown = PrevTail;
				}	
			}
			
		}
		if( i < height - 1 )
		{
			PrevTail = HeadStr;
			HeadStr->pUp = new CElement;
			if( HeadStr->pUp == NULL )
			{
				fprintf(stderr, "Ошибка выделения памяти\n");
				exit(2);
			}
			HeadStr->pUp->pDown = HeadStr;
			HeadStr = HeadStr->pUp;
			HeadStr->y = i + 1;
			Tail = HeadStr;
		}
	}
	return Tail;
}

int WindsCreate(CElement *Elem)
{

	return 0;
}

void ReleaseField( CElement *Elem, const int width, const int height )
{
	CElement *Tail = Elem;
	CElement *NextTail = NULL;
	CElement *HeadStrUp = Elem;

	for( int i = 0; i < height; ++ i )
	{
		HeadStrUp = Tail->pUp;
		for( int j = 0; j < width; ++ j )
		{
				NextTail = Tail->pRight;
				delete Tail;

			Tail = NextTail;
		}
		Tail = HeadStrUp;
	}
}
