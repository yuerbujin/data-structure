#include <stdio.h>
#include "mylist.h"
#define NOTFOUND NULL

//7.查找某结点第二次出现的位置 
Position FindList( P_List L, Position cur, ElemType e )
{
	if( L == NULL || cur == NULL )
		return NOTFOUND ;
	else
	{
		Position pos = cur ;
		for( ; pos != NULL; pos = pos->next ){
			if( pos->data == e )
				return pos ;
		}
		
		return NOTFOUND ;
	}
}

////13.删除单链表指定结点
//Status DeleteElem( P_List L, Position pos )
//{
//	if( L == NULL || pos == NULL )
//		return PARA_ERROR ;
//	else
//	{
//		P_LNode p = L->head ;
//		for( ; p->next != NULL; p = p->next )
//			if( p->next == pos )
//				break ;
//		
//		if( p->next == NULL )
//			return PARA_ERROR ;
//		else{
//			p->next = pos->next ;
//			if( pos == L->rear )
//				L->rear = p ;
//			free(pos) ;
//			return OK ;
//		}
//	}
//}

void DList( P_List L )
{
	Position pos ;
	for( Position cur = L->head->next; cur != NULL; cur = cur->next )
	{
		while(1){
			pos = FindList( L, cur->next, cur->data ) ;
			
			if( pos == NOTFOUND )
				break ;
			else
				DeleteElem( L, pos ) ;
		}
	}
}

int main()
{
	P_List L = InitList() ;
	
	Input(L);
	
	ListPrint( L ) ;
	DList( L ) ;
	ListPrint( L ) ;
}
/*
10
61 -12 -13 5 7 61 0 0 61 -12
*/
