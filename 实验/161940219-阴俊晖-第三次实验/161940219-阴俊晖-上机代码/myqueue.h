#ifndef _MYQUEUE_H_
#define _MYQUEUE_H_ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INT_MAX 0x3f3f3f3f

typedef int ElemType;
typedef struct Node Node;
typedef Node* Position;
typedef Node* PtrToNode;

struct Node{
	ElemType data;
	PtrToNode next;
};

typedef struct QNode QNode;
typedef QNode* Queue;

struct QNode{
	Position front, rear;
	int length;
};

//1.���г�ʼ�� 
Queue CreateQueue()
{
	Queue q = (Queue)malloc(sizeof(QNode));
	if (q != NULL){
		q->front = q->rear = NULL;
		q->length = 0;
	}
	return q;
}

//2.���е�����
ElemType Dequeue(Queue q);
void DestroyQueue(Queue q)
{
	if (q != NULL)
	{
		while (q->length > 0)
			Dequeue(q);
			
		free(q);
	}
}

//3.���е����
void ClearQueue(Queue q)
{
	if (q != NULL)
		while (q->length > 0)
			Dequeue(q);
}

//4.�ж϶��з�Ϊ�� 
bool IsEmpty(Queue q)
{
	return q->length == 0;
}

//5.���ض����н�����
int Length(Queue q)
{
	return q->length;
}

//6.���ض��ж�ͷԪ�� 
ElemType Front(Queue q)
{
	if (q->length > 0)
		return q->front->data;
}

//7.������� 
void PrintQueue(Queue q)
{
	if (q != NULL && q->length > 0)
	{
		printf( "Queue: " ) ;
		Position p = q->front;
		for( ; p != NULL; p = p->next )
			printf( "%d ", p->data ) ;
		printf( "\n" ) ;
	}
}

//8.���
void Enqueue(Queue q, ElemType elem)
{
	PtrToNode p = (PtrToNode)malloc(sizeof(Node));
	p->data = elem;
	p->next = NULL;
	
	if (q->length == 0)
		q->front = q->rear = p;
	else{
		q->rear->next = p;
		q->rear = p;
	}
	
	q->length++ ;
}

//9.����
ElemType Dequeue(Queue q)
{
	if (q->length > 0)
	{
		ElemType elem = q->front->data;
		PtrToNode tem = q->front;
		
		if (q->length == 1)
			q->front = q->rear = NULL;
		else
			q->front = q->front->next;
			
		free(tem);
		q->length-- ;
		return elem;
	}
}

//�������� 
void Input(Queue q)
{
	int N ;
	scanf("%d", &N);
	ElemType elem;
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &elem);
		Enqueue(q, elem);
	}
}

#endif
