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

	InitConditions(); // ���� ��������� ��������
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
	if( Head == NULL )
	{
		fprintf(stderr, "Field is not inited\n");
		exit(2);
	}
	currentX = startX;
	currentY = startY;
	if( variant == 0 )
		ShortWay();


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
	int index = 0;
	int plus = 1;
 	//Point = GetPoint( currentX, currentY );
	while( flag )
	{
		if( currentX == endX && currentY < endY )
			direction = 0;	// �����
		else if( currentX < endX && currentY < endY )
			direction = 1; // ������-������
		else if( currentX < endX && currentY == endY )
			direction = 2; // ������
		else if( currentX < endX && currentY > endY )
			direction = 3; // ���-������
		else if( currentX == endX && currentY > endY )
			direction = 4; // ��
		else if( currentX > endX && currentY > endY )
			direction = 5; // ���-�����
		else if( currentX > endX && currentY == endY )
			direction = 6; // �����
		else if( currentX > endX && currentY < endY )
			direction = 7; // ������-�����
		else
			flag = false; // �������� � ����� ����������

		nextLevel = 0;
		index = 0;
		plus = 1;
		for( int i = currentLevel; i < Point->Lvl.volume.size(); ++ i, plus * (-1) )
		{
			index = plus * i; 
			if( direction == Point->Lvl.direction[index] && index >= 0 )
			{
				nextLevel = Point->Lvl.volume[index];
				break;
			}
		}

		if( nextLevel > currentLevel )
			ammo = ammo - (currentLevel - nextLevel);
		if( nextLevel < currentLevel )
			helium = helium - (nextLevel - currentLevel);


	}
	return 0;
}