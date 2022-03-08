#ifndef _MYSTACK_H_
#define _MYSTACK_H_ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INT_MAX 0x3f3f3f3f

typedef int ElemType ;
typedef int Position ;

struct SNode{
	ElemType* data;
	int top;
	int maxsize; 
};
typedef struct SNode* Stack;
typedef struct SNode SNode;

//1.��ջ�ĳ�ʼ�� 
Stack CreateStack(int maxsize)
{
	Stack s = (Stack)malloc(sizeof(SNode));
	s->data = (ElemType*)malloc(maxsize * sizeof(ElemType));
	s->top = -1;
	s->maxsize = maxsize;
	return s ;
}

//2.��ջ������ 
void DestroyStack(Stack s)
{
	if (s != NULL){
		free(s->data);
		free(s); 
	}
}

//3.��ջ�����
void ClearStack(Stack s)
{
	if (s != NULL){
		memset( s->data, 0, sizeof(s->data) ) ;
		s->top = -1 ;
	}
}

//4.�ж϶�ջ�Ƿ�Ϊ�� 
bool IsEmpty(Stack s)
{
	return s->top == -1 ;
}

//5.�ж϶�ջ�Ƿ����� 
bool IsFull(Stack s)
{
	return s->top == s->maxsize;
}

//6.���ض�ջջ��Ԫ�� 
ElemType Top(Stack s)
{
	if (s->top > -1)
		return s->data[s->top] ;
}

//7.�����ջ
void PrintStack(Stack s)
{
	if (s != NULL && s->top != -1)
	{
		printf( "Stack: " ) ;
		for( int i = 0; i <= s->top; i++ )
			printf( "%d ", s->data[i] ) ;
		printf( "\n" ) ;
	}
}

//8.��ջ
void Push(Stack s, ElemType elem)
{
	s->data[++s->top] = elem;
}

//9.��ջ
ElemType Pop(Stack s)
{
	return s->data[s->top--];
}

//�������� 
void Input(Stack s)
{
	int N ;
	scanf("%d", &N);
	ElemType elem;
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &elem);
		Push(s, elem);
	}
}

#endif
