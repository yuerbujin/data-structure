#ifndef _MYLIST_H_
#define _MYLIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 256
#define NOTFOUND -1

typedef int ElemType ;

typedef struct LNode LNode ;
typedef struct LNode* P_LNode ;
typedef struct LNode* PtrToNode;
typedef P_LNode Position ;
struct LNode{
	ElemType data ;
	P_LNode pre, next ;
	int freq;
};

typedef struct List List ;
typedef struct List* P_List ;
struct List{
	P_LNode head ;
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
		L->rear = L->head ;
		L->length = 0 ;
	}
	return L ;
}

//2.链表销毁 
void DestroyList( P_List L )
{
	P_LNode tem ;
	while( L->head->next != NULL ){
		tem = L->head->next ;
		L->head = tem ;
		free(tem) ;
	}
	free(L->head) ;
	
	L->head = L->rear = NULL ;
	L->length = 0 ;
}

//4.判断链表是否为空 
bool IsEmpty( P_List L )
{
	return L->length == 0 ;
}

//10.遍历链表 
void ListPrint( P_List L )
{
	if (L != NULL)
	{
		printf( "List: " ) ;
		P_LNode p = L->head->next;
		for ( ; p != L->rear; p = p->next)
			printf( "%d ", p->data ) ;
			
		printf( "%d ", p->data ) ;
		printf( "\n" ) ;
	}
}

//12.在pos后插入结点，并累加频率 
void InsertElem(P_List L, Position pos, ElemType e, int f = 0)
{
	P_LNode p = (P_LNode)malloc(sizeof(LNode)) ;
	p->data = e;
	p->freq = f;
	
	if (L->length == 0){
		p->next = p->pre = p;
		L->head->next = L->rear = p;
	}
	else
	{
		p->next = pos->next ;
		pos->next->pre = p;
		pos->next = p;
		p->pre = pos;
		
		if (pos == L->head)
			L->head->next = p;
		if (pos == L->rear)
			L->rear = p;
	}
	
	L->length++ ;
}

//13.删除结点
void DeleteElem( P_List L, Position pos )
{
	if (L != NULL && pos != NULL)
	{
		P_LNode p = L->head ;
		for( ; p->next != NULL; p = p->next )
			if( p->next == pos )
				break ;
		
		if (p->next != NULL)
		{
			p->next = pos->next ;
			pos->next->pre = p;
			
			if (pos == L->head->next)
				L->head->next = pos->next;
			if (pos == L->rear)
				L->rear = p;
			
			free(pos) ;
			L->length-- ;
		}
	}
}

//14.使之为双向循环链表
void DoubleLinked(P_List L)
{
	L->rear->next = L->head->next;
	
	Position p1 = L->head->next;
	Position p2 = p1->next;
	
	while (p1 != L->rear)//一次循环设置一个pre指针 
	{
		p2->pre = p1;
		p1 = p1->next; 
		p2 = p2->next;
	}
	p2->pre = p1;
}


//15-1查找该结点应调换的位置
Position FindUpperPos(P_List L, PtrToNode p)
{
	int freq = p->freq;
	
	//找到最前一个小于等于freq的结点 
	while (p != L->head->next && p->pre->freq <= freq)
		p = p->pre;
	
	return p; 
}

//15.依据频率更新结点 
int Locate(P_List L, ElemType e)
{
	if (L != NULL)
	{
		P_LNode p = L->head ;
		for (int j = 0; j < L->length ; j++)
		{
			p = p->next ;
			if( p->data == e ){
				p->freq++ ;
				
				Position pos = FindUpperPos(L, p);
				//为了能在pos之后插入 
				if (pos == L->head->next)
					pos = L->head;
				else
					pos = pos->pre;
				
				InsertElem(L, pos, p->data, p->freq);
				DeleteElem(L, p);
				//返回e原始位置 
				return j;
			}
		}
	}
	
	return NOTFOUND;
}

//读入数据 
void Input(P_List L)
{
	int N ;
	scanf( "%d", &N ) ;
	ElemType elem ;
	for( int i = 1; i <= N; i++ ){
		scanf( "%d", &elem ) ;
		InsertElem(L, L->rear, elem) ;
	}
}

#endif 
