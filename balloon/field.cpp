#include "stdafx.h"
#include "element.h"
#include "glob.h"
#include "field.h"

//CElement* InitField( CElement **Elem, const int width, const int height )
//{
//	*Elem = new CElement;
//	if( Elem == NULL )
//	{
//		fprintf(stderr, "error alloc\n");
//		exit(2);
//	}
//	CElement *Tail = *Elem;
//	CElement *PrevTail = NULL;
//	CElement *HeadStr = *Elem;
//	int correctWidth = width - 1;
//
//	Tail->SetLevel();
//	for( int i = 0; i < height; ++ i )
//	{
//
//		for( int j = 0; j < correctWidth; ++ j )
//		{
// 
//			Tail->pRight = new CElement;
//			if( Tail->pRight == NULL )
//			{
//				fprintf(stderr, "error alloc\n");
//				exit(2);
//			}
//
//			Tail->pRight->pLeft = Tail;
//			Tail = Tail->pRight;
//			if( PrevTail )
//			{
//				PrevTail =  PrevTail->pRight;
//				PrevTail->pUp = Tail;
//				Tail->pDown = PrevTail;
//				
//			}
//			
//			Tail->x = j + 1;
//			Tail->y = i;
//			Tail->SetLevel();
//			if( i == width - 2 )
//			{
//				if( PrevTail )
//				{
//					PrevTail->pUp = Tail;
//					Tail->pDown = PrevTail;
//				}	
//			}
//			
//		}
//		if( i < height - 1 )
//		{
//			PrevTail = HeadStr;
//			HeadStr->pUp = new CElement;
//			if( HeadStr->pUp == NULL )
//			{
//				fprintf(stderr, "error alloc\n");
//				exit(2);
//			}
//			HeadStr->pUp->pDown = HeadStr;
//			HeadStr = HeadStr->pUp;
//			HeadStr->y = i + 1;
//			Tail = HeadStr;
//		}
//	}
//	return Tail;
//}
//
//int WindsCreate(CElement *Elem)
//{
//
//	return 0;
//}
//
//void ReleaseField( CElement *Elem, const int width, const int height )
//{
//	CElement *Tail = Elem;
//	CElement *NextTail = NULL;
//	CElement *HeadStrUp = Elem;
//
//	for( int i = 0; i < height; ++ i )
//	{
//		HeadStrUp = Tail->pUp;
//		for( int j = 0; j < width; ++ j )
//		{
//				NextTail = Tail->pRight;
//				delete Tail;
//
//			Tail = NextTail;
//		}
//		Tail = HeadStrUp;
//	}
//}
//
//// ������ ������ ����� 
//
//
//int InitConditions()
//{
//	int startX = 0;
//	int startY = 0;
//	int endX = 0;
//	int endY = 0;
//
//	cout << "Enter start X:";
//	cin >> startX;
//	cout << "Enter start Y:";
//	cin >> startY;
//	cout << "Enter end X:";
//	cin >> endX;
//	cout << "Enter end Y:";
//	cin >> endY;
//
//	return 0;
//}

CElement* CField::InitField( const int width, const int height )
{
	Head = new CElement;
	if( Head == NULL )
	{
		fprintf(stderr, "error alloc\n");
		exit(2);
	}
	CElement *Tail = Head;
	CElement *PrevTail = NULL;
	CElement *HeadStr = Head;
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

void CField::ReleaseField( const int width, const int height )
{
	CElement *Tail = Head;
	CElement *NextTail = NULL;
	CElement *HeadStrUp = Head;

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

int CField::Statistic(FILE *outlog )
{
	fprintf( outlog, "    ^\n");
	for( int i = VALUE - 1; i >= 0; -- i )
	{
		fprintf( outlog, "%4i|", i * 200);
		for( int j = 0; j < level.size(); ++ j )
		{
			if( level.at(j) == i * 200 )
			{
				fprintf( outlog, "  *" );
			}
			
		}
		fprintf( outlog, "\n" );
	}
	fprintf( outlog, "     " );
	for( int i = 0; i < level.size(); ++ i )
	{
		fprintf( outlog, "--|");
	}
	fprintf( outlog, "\n     ");
	for( int i = 0; i < level.size(); ++ i )
	{
		fprintf( outlog, "%3i", i + 1 );
	}
	fprintf( outlog, "\n" );
	return 0;
}

int CField::InitConditions()
{


	cout << "Enter start X:";
	cin >> startX;
	cout << "Enter start Y:";
	cin >> startY;
	cout << "Enter end X:";
	cin >> endX;
	cout << "Enter end Y:";
	cin >> endY;

	return 0;
}