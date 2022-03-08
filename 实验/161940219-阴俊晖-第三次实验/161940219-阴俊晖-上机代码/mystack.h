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

//1.堆栈的初始化 
Stack CreateStack(int maxsize)
{
	Stack s = (Stack)malloc(sizeof(SNode));
	s->data = (ElemType*)malloc(maxsize * sizeof(ElemType));
	s->top = -1;
	s->maxsize = maxsize;
	return s ;
}

//2.堆栈的销毁 
void DestroyStack(Stack s)
{
	if (s != NULL){
		free(s->data);
		free(s); 
	}
}

//3.堆栈的清空
void ClearStack(Stack s)
{
	if (s != NULL){
		memset( s->data, 0, sizeof(s->data) ) ;
		s->top = -1 ;
	}
}

//4.判断堆栈是否为空 
bool IsEmpty(Stack s)
{
	return s->top == -1 ;
}

//5.判断堆栈是否已满 
bool IsFull(Stack s)
{
	return s->top == s->maxsize;
}

//6.返回堆栈栈顶元素 
ElemType Top(Stack s)
{
	if (s->top > -1)
		return s->data[s->top] ;
}

//7.输出堆栈
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

//8.入栈
void Push(Stack s, ElemType elem)
{
	s->data[++s->top] = elem;
}

//9.出栈
ElemType Pop(Stack s)
{
	return s->data[s->top--];
}

//读入数据 
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
