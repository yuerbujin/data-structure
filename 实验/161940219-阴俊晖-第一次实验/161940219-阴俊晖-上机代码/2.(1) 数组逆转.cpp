#include <stdio.h>
#include "myarray.h" 

//14.Êý×éÄæ×ª
void Swap( ElemType* e1, ElemType* e2 )
{
	ElemType tem = *e1 ;
	*e1 = *e2 ;
	*e2 = tem ;
}

Status ListReverse( P_List L )
{
	if( L == NULL )
		return PARA_ERROR ;
	else
	{
		if( L->length == 1 )
			return OK ;
		
		for( int i = 0; i < L->length/2; i++ )
			Swap( &L->data[i], &L->data[L->length-i-1] ) ;
		
		return OK ;
	}
}

int main()
{
	P_List L = InitList(MAXSIZE) ;
	
	Input(L);
	
	ListPrint( L ) ;
	ListReverse( L ) ;
	ListPrint( L ) ;
}
/*
10
61 -12 -13 5 7 61 0 0 61 -12
*/
