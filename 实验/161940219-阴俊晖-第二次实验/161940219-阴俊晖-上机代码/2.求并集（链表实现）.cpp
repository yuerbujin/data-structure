#include <stdio.h>
#include "mylist.h"

void Union( P_List L1, P_List L2 ) ;

int main()
{
	P_List L1 = InitList() ;
	Input( L1 ) ;
	P_List L2 = InitList() ;
	Input( L2 ) ;

//	ListPrint( L1 ) ;
//	ListPrint( L2 ) ;
	Union( L1, L2 ) ;
	ListPrint( L1 ) ;
}

void Union( P_List L1, P_List L2 )
{
	P_LNode p1 = L1->head ; 
	P_LNode p2 = L2->head ;
	
	while( p1->next != NULL && p2->next != NULL ){
		if( p2->next->data > p1->next->data ){
			InsertElem( L1, p1, p2->next->data );
			p2 = p2->next;
		}
		else if( p2->next->data == p1->next->data ){
			p1 = p1->next;
			p2 = p2->next;
		}
		else if( p2->next->data < p1->next->data ){
			p1 = p1->next;
		}
	}
	
	if( p1->next == NULL )
		while( p2->next != NULL ){
			InsertElem( L1, p1, p2->next->data );
			p1 = p1->next;
			p2 = p2->next;
		}
}
/*
5 
84 7 0 -1 -4
7 
81 51 -1 -4 -5 -77 -78
*/ 
