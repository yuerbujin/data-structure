#include <stdio.h>
#include "mylist.h"

void Solve( P_List L ) ;
	
int N, M ;
int main()
{
	P_List L = InitList() ;
	
	Input( L ) ;
	L->rear->next = L->head->next ;
	scanf( "%d", &M );
	
//	ListPrint( L ) ;
	Solve( L ) ;
}

void Solve( P_List L )
{
	Position p = L->head->next ;
	Position last_p = L->rear ;
	int m = 1 ;
	while( L->length > 0 )
	{
		if( m == M ){
			printf( "%d ", p->data ) ;			
//			delete a node 
			Position tem = last_p->next ;
			p = tem->next ;
			last_p->next = tem->next ;
			free(tem);
			
			L->length-- ;
			
			m = 1 ;
		}
		else{
			m++ ;
			last_p = p ;
			p = p->next ;
		}
	}
}
/*
5
1 2 3 4 5
3
*/ 
