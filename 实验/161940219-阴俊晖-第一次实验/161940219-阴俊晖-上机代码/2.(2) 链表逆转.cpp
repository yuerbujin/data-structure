#include <stdio.h>
#include "mylist.h"

//14.Á´±íÄæ×ª
Status ListReverse( P_List L )
{
	if( L == NULL )
		return PARA_ERROR ;
	else
	{
		if( L->length == 1 )
			return OK ;
		
		P_LNode cur, next, tem, tem2 ;
		cur = L->head->next ;
		next = cur->next ;
		tem = next->next ;
		tem2 = cur ;
		
		for( ; tem != NULL; tem = tem->next ){
			next->next = cur ;
			cur = next ;
			next = tem ;
		}
		next->next = cur ;
		
		L->head->next = next ;
		tem2->next = NULL ;
		L->rear = tem2 ;
		L->cur = L->head ;
		
		return OK ;
	}
}

int main()
{
	P_List L = InitList() ;
	
	Input(L);
	
	ListPrint( L ) ;
	ListReverse( L ) ;
	ListPrint( L ) ;
}
/*
10
61 -12 -13 5 7 61 0 0 61 -12
*/
