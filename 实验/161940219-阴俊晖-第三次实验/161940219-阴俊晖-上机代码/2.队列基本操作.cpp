#include <stdio.h>
#include "myqueue.h"

int main()
{
	Queue q = CreateQueue(); 
	Input(q);
	PrintQueue(q);
	
	printf("\n%d\n", Dequeue(q));
	PrintQueue(q);
	
	printf("\n%d\n", Front(q));
	PrintQueue(q);
	
	printf("\n%d\n", Length(q));
	
	ClearQueue(q);
	PrintQueue(q);
}

/*
8
91 -7 0 0 -7 22 -1 -43
*/ 
