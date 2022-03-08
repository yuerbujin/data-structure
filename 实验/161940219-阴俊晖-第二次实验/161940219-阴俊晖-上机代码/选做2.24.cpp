#include <stdio.h>
#include "mylist.h"

void ListReverse( P_List L );
void Union( P_List L1, P_List L2 ) ;

int main()
{
	P_List L1 = InitList() ;
	Input( L1 ) ;
	P_List L2 = InitList() ;
	Input( L2 ) ;
	
	ListReverse(L1);
	ListReverse(L2);
	
	Union( L1, L2 ) ;
	ListPrint( L1 ) ;
}

void ListReverse( P_List L )
{
	if( L == NULL )
		return;
	else
	{
		if( L->length == 1 )
			return;
		
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
		
		return;
	}
}

P_LNode GetElem(P_List L, P_LNode p)//把p的next取出 
{
	P_LNode tem = p->next;
	p->next = tem->next;
	tem->next = NULL;
	return tem;
}

void InsertElem(P_List L, P_LNode p, P_LNode ele)//把ele插入到p之后 
{
	ele->next = p->next;
	p->next = ele;
}

void Union( P_List L1, P_List L2 )
{
	P_LNode p1 = L1->head ; 
	P_LNode p2 = L2->head ;
	P_LNode ele;
	
	while( p1->next != NULL && p2->next != NULL ){
		if( p2->next->data >= p1->next->data ){
			ele = GetElem(L2, p2);
			InsertElem(L1, p1, ele);
			p1 = p1->next;
		}
		else if( p2->next->data < p1->next->data ){
			p1 = p1->next;
		}
	}
	
	if( p1->next == NULL )
		while( p2->next != NULL ){
			ele = GetElem(L2, p2);
			InsertElem(L1, p1, ele);
			p1 = p1->next;
		}
}
/*
5
-17 -1 -1 0 81
8
-78 -55 -55 -4 -1 0 47 81
*/
