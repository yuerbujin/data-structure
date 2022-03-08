#include <stdio.h>
#include "mylist.h"

void Selection_Sort( P_List L ) ;
void Bubble_Sort( P_List L ) ;

int main()
{
	P_List L = InitList() ;
	
	Input( L ) ;
	
//	ListPrint( L ) ;
//	Selection_Sort( L ) ;
	Bubble_Sort( L ) ;
	ListPrint( L ) ;
}

void Swap( ElemType* e1, ElemType* e2 )
{
	ElemType tem = *e1 ;
	*e1 = *e2 ;
	*e2 = tem ;
}

void Selection_Sort( P_List L )
{
	if( L->length == 0 || L->length == 1 )
		return ;
	else{
		ElemType min ;
		Position p1, p2, pos ;
		
		for( p1 = L->head->next ; p1->next != NULL ; p1 = p1->next )
		{
			min = p1->data ;
			pos = p1 ;
			
			for( p2 = p1->next ; p2 != NULL ; p2 = p2->next )
			{
				if( p2->data < min ){
					min = p2->data ;
					pos = p2 ;
				}
			}
				
			Swap( &p1->data, &pos->data ) ;
		}
	}
}

void Bubble_Sort( P_List L )
{
	if( L->length == 0 || L->length == 1 )
		return ;
	else{
		for( int i = 1; i < L->length ; i++ ){
			Position p2 = L->head->next ;
			int j = 0 ;
			
			for( ; j < L->length-i; j++, p2 = p2->next )
				if( p2->data > p2->next->data )
					Swap( &p2->data, &p2->next->data ) ;
		}
	}
}
/*
10
61 -12 -13 5 7 61 0 0 61 -12
*/
