#ifndef _MYLIST_H_
#define _MYLIST_H_

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

//2.链表销毁 
Status DestroyList( P_List L )
{
	P_LNode tem ;
	while( L->head->next != NULL ){
		tem = L->head->next ;
		L->head = tem ;
		free(tem) ;
	}
	free(L->head) ;
	
	L->head = L->cur = L->rear = NULL ;
	L->length = 0 ;
	return OK ;
}

//3.顺序表清空
Status ClearList( P_List L )
{
	P_LNode tem ;
	while( L->head->next != NULL ){
		tem = L->head->next ;
		L->head = tem ;
		free(tem) ;
	}
	L->head->next = NULL ;
	L->rear = L->head ;
	
	L->cur = NULL ;
	L->length = 0 ;
	return OK ;
}

//4.判断链表是否为空 
Status IsEmpty( P_List L )
{
	return L->length ;
}

//5.返回链表中元素个数
int Length( P_List L )
{
	return L->length ;
}

//6.获取链表中第i个元素 
Status GetElem( P_List L, int i, ElemType* e )
{
	if( L == NULL || i < 1 || i > L->length || e == NULL )
		return PARA_ERROR ;
	else
	{
		P_LNode p = L->head ;
		for( int j = 0; j < i; j++ )
			p = p->next ;
		
		*e = p->data ;
		L->cur = p ;
		return OK ;
	}
}

//7.查找某结点位置 
Status FindList( P_List L, ElemType e )
{
	if( L == NULL )
		return PARA_ERROR ;
	else
	{
		P_LNode p = L->head ;
		for( int j = 0; j < L->length ; j++ ){
			p = p->next ;
			if( p->data == e )
				return j ;
		}
		
		return NOTFOUND ;
	}
}

//8.获取某结点前驱 
Status PreElem( P_List L, ElemType cur_e, ElemType* pre_e )
{
	if( L == NULL || pre_e == NULL )
		return PARA_ERROR ;
	else
	{
		int i = FindList( L, cur_e ) ;
		if( i == NOTFOUND )
			return ERROR ;
		else if( i == 0 )
			return PARA_ERROR ;
		else
		{
			GetElem( L, i-1, pre_e ) ;
			return OK ;
		}
	}
}

//9.获取某结点后继 
Status NextElem( P_List L, ElemType cur_e, ElemType* next_e )
{
	if( L == NULL || next_e == NULL )
		return PARA_ERROR ;
	else
	{
		int i = FindList( L, cur_e ) ;
		if( i == NOTFOUND )
			return ERROR ;
		else if( i == L->length )
			return PARA_ERROR ;
		else
		{
			GetElem( L, i+1, next_e ) ;
			return OK ;
		}
	}
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

//11.修改结点
Status SetElem( P_List L, int i, ElemType e )
{
	if( L == NULL || i < 1 || i > L->length )
		return PARA_ERROR ;
	else{
		P_LNode p = L->head ;
		for( int j = 0; j < i; j++ )
			p = p->next ;
		
		p->data = e ;
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
		
		L->length++ ;
		return OK ;
	}
}

//13.删除单链表指定结点
Status DeleteElem( P_List L, Position pos )
{
	if( L == NULL || pos == NULL )
		return PARA_ERROR ;
	else
	{
		P_LNode p = L->head ;
		for( ; p->next != NULL; p = p->next )
			if( p->next == pos )
				break ;
		
		if( p->next == NULL )
			return PARA_ERROR ;
		else{
			p->next = pos->next ;
			if( pos == L->rear )
				L->rear = p ;
			free(pos) ;
			return OK ;
		}
	}
}

//读入数据 
void Input( P_List L )
{
	int N ;
	scanf( "%d", &N ) ;
	ElemType elem ;
	for( int i = 1; i <= N; i++ ){
		scanf( "%d", &elem ) ;
		InsertElem( L, elem ) ;
	}
}

#endif
