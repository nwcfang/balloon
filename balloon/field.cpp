#include "stdafx.h"
#include "element.h"
#include "glob.h"

CElement* InitField( CElement **Elem, const int width, const int height )
{
	*Elem = new CElement;
	if( Elem == NULL )
	{
		fprintf(stderr, "error alloc\n");
		exit(2);
	}
	CElement *Tail = *Elem;
	CElement *PrevTail = NULL;
	CElement *HeadStr = *Elem;
	int correctWidth = width - 1;

	Tail->SetLevel();
	for( int i = 0; i < height; ++ i )
	{

		for( int j = 0; j < correctWidth; ++ j )
		{
 
			Tail->pRight = new CElement;
			if( Tail->pRight == NULL )
			{
				fprintf(stderr, "error alloc\n");
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
			Tail->SetLevel();
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
				fprintf(stderr, "error alloc\n");
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

// Строит график высот 
int Statistic(FILE *outlog, vector<int> *level )
{
	fprintf( outlog, "    ^\n");
	for( int i = VALUE - 1; i >= 0; -- i )
	{
		fprintf( outlog, "%4i|\n", i * 200);
	}
	return 0;
}




