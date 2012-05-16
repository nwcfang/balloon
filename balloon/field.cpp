#include "stdafx.h"
#include "element.h"
#include "glob.h"
#include "field.h"


CField::CField()
{
	Head = NULL;
	Tail = NULL;
	startX = 0;
	startY = 0;
	endX = 0;
	endY = 0;
	ammo = 0;
	helium = 0;
	currentLevel = 0; 
	currentAmmo = 0;
	currentX = 0;
	currentY = 0;
}

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

	InitConditions(); // сбор начальных значений
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
	cout << "Enter number of load:";
	cin >> ammo;
	helium = ammo;

	return 0;
}

int CField::StartMove( int variant )
{
	int res = 0;
	if( Head == NULL )
	{
		fprintf(stderr, "Field is not inited\n");
		exit(2);
	}
	currentX = startX;
	currentY = startY;
	if( variant == 0 )
	{
		if( ShortWay() == 1)
			return 1;
	}

	return 0;
}

CElement* CField::GetPoint( int x, int y )
{
	Tail = Head;
	while( x != 0 )
	{
		Tail = Tail->pRight;
		-- x;
	}

	while( y != 0 )
	{
		Tail = Tail->pUp;
		-- y;
	}

	return Tail;
}

int CField::ShortWay()
{
	CElement *Point = GetPoint( currentX, currentY );
	bool flag = true;
	int direction = 0;
	int nextLevel = 0;

	while( flag )
	{
		if( currentX == endX && currentY < endY )
			direction = 0;	// север
		else if( currentX < endX && currentY < endY )
			direction = 1; // северо-восток
		else if( currentX < endX && currentY == endY )
			direction = 2; // восток
		else if( currentX < endX && currentY > endY )
			direction = 3; // юго-восток
		else if( currentX == endX && currentY > endY )
			direction = 4; // юг
		else if( currentX > endX && currentY > endY )
			direction = 5; // юго-запад
		else if( currentX > endX && currentY == endY )
			direction = 6; // запад
		else if( currentX > endX && currentY < endY )
			direction = 7; // северо-запад
		else
			break;
			//flag = false; // аэростат в точке назначения

		nextLevel = SearchDirect( Point, direction );

		if( nextLevel == -1 )
		{
			direction = direction + 1;
			Correction( &direction );

			nextLevel = SearchDirect( Point, direction );
		}

		if( nextLevel == -1 )
		{
			direction = direction - 1;
			Correction( &direction );

			direction = direction - 1;
			Correction( &direction );

			nextLevel = SearchDirect( Point, direction );
		}

		if( nextLevel == -1 )
		{
			printf( "Error: no pass\n" );
			return 1;
		}

		if( nextLevel > currentLevel )
			ammo = ammo - (currentLevel - nextLevel);
			
		if( nextLevel < currentLevel )
			helium = helium - (nextLevel - currentLevel);
		currentLevel = nextLevel;
		level.push_back( currentLevel * 200 );
		currentX = Point->x;
		currentY = Point->y;
		MoveObj( &Point, direction );







	}
	return 0;
}
 
int CField::SearchDirect(CElement *Point, int direction)
{
	int nextLevel = -1;
	int plus = 1;
	int index = 0;
	for( int i = currentLevel; i < Point->Lvl.volume.size(); ++ i, plus *= (-1) )
	{
		index += plus * i;
		if( index >= 0 )
		{
			if( direction == Point->Lvl.direction[index] )
			{
				nextLevel = Point->Lvl.volume[index];
				break;
			}
		}
	}
	return nextLevel;
}

int CField::Correction(int *dr)
{
	if( *dr == 8 )
		*dr = 0;
	if( *dr == -1 )
		*dr = 7;
	return 0; 
}

int CField::MoveObj( CElement **Point, int dr )
{
	// отклонение от статической базы
	//dr = dr + (rand() % 3 - 1 );
	Correction( &dr );
	if( dr == 0 )
	{
		*Point = (*Point)->pUp;
	}
	else if( dr == 1 )
	{
		*Point = (*Point)->pUp;
		*Point = (*Point)->pRight;
	}
	else if( dr == 2 )
	{
		*Point = (*Point)->pRight;
	}
	else if( dr == 3 )
	{
		*Point = (*Point)->pRight;
		*Point = (*Point)->pDown;
	}
	else if( dr == 4 )
	{
		*Point = (*Point)->pDown;
	}
	else if( dr == 5 )
	{
		*Point = (*Point)->pDown;
		*Point = (*Point)->pLeft;
	}
	else if( dr == 6 )
	{
		*Point = (*Point)->pLeft;
	}
	else if( dr == 7 )
	{
		*Point = (*Point)->pLeft;
		*Point = (*Point)->pUp;
	}
	else
		return -1;
	return dr;
}