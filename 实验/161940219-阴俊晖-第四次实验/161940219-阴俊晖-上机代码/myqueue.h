
///////////////////////////////循环队列//////////////////////////////// 

#ifndef _MYQUEUE_H_
#define _MYQUEUE_H_ 
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mypoint.h"

#define INT_MAX 0x3f3f3f3f

typedef struct Node Node;
typedef Node* Position;
typedef Node* PtrToNode;

typedef struct QNode QNode;
typedef QNode* Queue;

namespace myqueue{
	typedef Point ElemType;
}

struct Node{
	myqueue::ElemType data;
	PtrToNode next;
};

struct QNode{
	Position rear;
	int length;
};

//1.队列初始化 
Queue CreateQueue()
{
	Queue q = (Queue)malloc(sizeof(QNode));
	if (q != NULL){
		q->rear = NULL;
		q->length = 0;
	}
	return q;
}

//2.队列的销毁
myqueue::ElemType Dequeue(Queue q);
void DestroyQueue(Queue q)
{
	if (q != NULL)
	{
		while (q->length > 0)
			Dequeue(q);
			
		free(q);
	}
}

//4.判断队列否为空 
bool IsEmpty(Queue q)
{
	return q->length == 0;
}

//5.返回队列中结点个数
int Length(Queue q)
{
	return q->length;
}

//7.输出队列 
void PrintQueue(Queue q)
{
	if (q != NULL && q->length > 0)
	{
		printf( "Queue: " ) ;
		Position p = q->rear->next;
		for( int i = 1; i <= 20; p = p->next, i++ )
			printf( "%d ", p->data ) ;
		printf( "\n" ) ;
	}
}

//8.入队
void Enqueue(Queue q, myqueue::ElemType elem)
{
	PtrToNode p = (PtrToNode)malloc(sizeof(Node));
	p->data = elem;
	
	if (Length(q) == 0){
		q->rear = p;
		p->next = p;
	}
	else{
		p->next = q->rear->next;
		q->rear->next = p;
		q->rear = p;
	}
	
	q->length++ ;
}

//9.出队
myqueue::ElemType Dequeue(Queue q)
{
	if (q->length > 0)
	{
		PtrToNode tem = q->rear->next;
		myqueue::ElemType elem = tem->data;
		
		if (q->length == 1)
			q->rear = NULL;
		else
			q->rear->next = tem->next;
			
		free(tem);
		q->length-- ;
		return elem;
	}
}

//读入数据 
void Input(Queue q)
{
	int N ;
	scanf("%d", &N);
	myqueue::ElemType elem;
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &elem);
		Enqueue(q, elem);
//		printf("!!!!!!%d\n", sizeof(elem));
	}
}

#endif
