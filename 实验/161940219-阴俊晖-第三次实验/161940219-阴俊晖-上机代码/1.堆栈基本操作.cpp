#include <stdio.h>
#include "mystack.h"

#define MAXSIZE 256

int main()
{
	Stack s = CreateStack(MAXSIZE); 
	Input(s);
	PrintStack(s);
	
	printf("\n%d\n", Pop(s));
	PrintStack(s);
	
	printf("\n%d\n", Top(s));
	PrintStack(s);
	
	printf("\n%d\n", s->top+1);
	
	ClearStack(s);
	PrintStack(s);
}

/*
8
91 -7 0 0 -7 22 -1 -43
*/ 
