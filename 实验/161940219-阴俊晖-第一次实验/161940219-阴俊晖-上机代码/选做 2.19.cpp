#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 256
#define OK 1
#define PARA_ERROR 0
#define ERROR 0
#define OVERFLOW -1
#define NOTFOUND -1

typedef int Status ;
typedef int ElemType ;

typedef struct LNode LNode ;
typedef struct LNode* P_LNode ;
typedef P_LNode Position ;
struct LNode{
	ElemType data ;
	P_LNode next ;
};

typedef struct List List ;
typedef struct List* P_List ;
struct List{
	P_LNode head ;
	P_LNode cur ;
	P_LNode rear ;
	int length ;
};

//1.链表初始化 
P_List InitList()
{
	P_List L = (P_List)malloc(sizeof(List)) ;
	if( L != NULL )
	{
		L->head = (P_LNode)malloc(sizeof(LNode)) ;
		L->head->next = NULL ;
		L->cur = L->rear = L->head ;
		L->length = 0 ;
	}
	return L ;
}

//10.遍历链表 
Status ListPrint( P_List L )
{
	if( L == NULL )
		return PARA_ERROR ;
	else{
		printf( "List: " ) ;
		for( P_LNode p = L->head->next ; p != NULL; p = p->next )
			printf( "%d ", p->data ) ;
		printf( "\n" ) ;
		return OK ;
	}
}

//12.在单链表当前结点后插入新结点 
Status InsertElem( P_List L, ElemType e )
{
	if( L == NULL )
		return PARA_ERROR ;
	else
	{
		P_LNode p = (P_LNode)malloc(sizeof(LNode)) ;
		if( p == NULL )
			exit(OVERFLOW) ;
		
		p->data = e ;
		p->next = L->cur->next ;
		if( L->cur == L->rear )
			L->rear = p ;
		L->cur->next = p ;
		L->cur = p ;
		
		L->length++ ;
		return OK ;
	}
}

int mink = 33, maxk = 56 ;
void DList( P_List L )
{
	if( mink > maxk )
		return ;
	
	Position p1 = L->head, tem, tem2 ;
	while( p1->next->data <= mink ){
		p1 = p1->next ;
	}
	tem = p1 ;
	p1 = p1->next ;
	
	Position p2 = p1 ;
	while( p2->next->data < maxk )
		p2 = p2->next ;
		
	tem->next = p2->next ;
	
	while( p1 != p2 ){
		tem2 = p1 ;
		p1 = p1->next ;
		free(tem2) ;
	}
	free(p2) ;
}

int main()
{
	P_List L = InitList() ;
	
	int N ;
	scanf( "%d", &N ) ;
	ElemType elem ;
	for( int i = 1; i <= N; i++ ){
		scanf( "%d", &elem ) ;
		InsertElem( L, elem ) ;
	}
	
	ListPrint( L ) ;
	DList( L ) ;
	ListPrint( L ) ;
}
/*
10
2 5 33 34 34 34 35 56 56 81
*/
