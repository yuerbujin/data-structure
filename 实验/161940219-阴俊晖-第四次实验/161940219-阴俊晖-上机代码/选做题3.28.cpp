#include <stdio.h>
#include "myqueue.h"

int main()
{
	Queue q = CreateQueue();
	
	Input(q) ;
	
	PrintQueue(q);
	
	Dequeue(q);
	Dequeue(q);
	Dequeue(q);
	Dequeue(q);
	
	PrintQueue(q);
}

/*
input:
10
61 -12 -13 5 7 61 0 0 61 -12
*/
