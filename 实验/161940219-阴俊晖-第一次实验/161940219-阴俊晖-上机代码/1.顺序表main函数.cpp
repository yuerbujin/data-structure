#include <stdio.h>
#include "myarray.h"

int main()
{
	P_List L = InitList(MAXSIZE) ;
	
	Input( L ) ;
	
	ListPrint( L ) ;
	
	ClearList( L ) ; 
	
	ListPrint( L ) ;
	DestroyList( L ) ;
//////////////////////////////////////////////////////////
	P_List L2 = InitList(MAXSIZE) ;
	Input( L2 ) ;
	
	ElemType e, pre_e ;
	GetElem( L2, 2, &e ) ;
	printf( "\n%d\n", e ) ;
	
	Position pos = FindList( L2, e ) ;
	printf( "\npos: %d\n", pos ) ;
	
	DestroyList( L2 ) ;
}
