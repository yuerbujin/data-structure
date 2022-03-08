#include <stdio.h>
#include "myarray.h"

Position FindList( P_List L, Position pos, ElemType e )
{
	int i = pos;
	for( ; i < L->length; i++ )
		if( e == L->data[i] )
			return i ;
	
	if (i == L->length)
		return NOTFOUND ;
}

void DList( P_List L )
{
	Position pos ;
	for( int i = 1; i <= L->length; i++ )
	{
		while(1){
			pos = FindList( L, i, L->data[i-1] ) ;
//			printf( "pos: %d\n", pos ) ;
			if( pos == NOTFOUND )
				break ;
			else
				DeleteElem( L, pos ) ;
//			ListPrint( L ) ;
		}
	}
}

int main()
{
	P_List L = InitList(MAXSIZE) ;
	
	Input(L);
	
	ListPrint( L ) ;
	DList( L ) ;
	ListPrint( L ) ;
}
/*
10
61 -12 -13 5 7 61 0 0 61 -12
*/
