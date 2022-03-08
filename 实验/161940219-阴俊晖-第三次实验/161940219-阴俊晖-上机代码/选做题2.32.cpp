#include <stdio.h>
#include "mylist.h"

void ListReversePrint(P_List L);
	
int N;
int main()
{
	P_List L = InitList() ;
	
	Input( L ) ;
	
	DoubleLinked( L ) ;
	ListReversePrint( L ) ;
}

void ListReversePrint(P_List L)
{
	int i = 1;
	
	printf( "ReverseList: " ) ;
	for( P_LNode p = L->rear ; p != NULL; p = p->pre ){
		printf( "%d ", p->data ) ;
		
		if (i > 25)
			break;
		i++ ;
	}
	printf( "\n" ) ;
}

/* 
10
61 -12 -13 5 7 61 0 0 61 -12
*/ 
