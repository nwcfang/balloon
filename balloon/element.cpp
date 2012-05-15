#include "stdafx.h"
#include "element.h"
#include "glob.h"

CElement::CElement()
{
	pUp = NULL;
	pDown = NULL;
	pRight = NULL;
	pLeft = NULL;

	x = 0;
	y = 0;



}

int CElement::SetLevel()
{
	srand(time(0));
	int iValV = 0;
	int iValD = rand() % 8;
	for( int i = 0; i < VALUE; ++ i )
	{
		//iValV = i * STAP;
		iValV = i;
		Lvl.direction.push_back( iValD );
		Lvl.volume.push_back( iValV );
		iValD = Lvl.direction[i] + (rand() % 3 - 1 );
		if( iValD == -1 )
			iValD = 7;
		if( iValD == 8 )
			iValD = 0;
	}
	return 0;
}

CLevel::CLevel()
{
	volume.clear();
	direction.clear();
}