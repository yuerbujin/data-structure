#include <stdio.h>
#include "myqueue2.h"

Queue Input();
void Fibonacci(Queue q);

int k, n, max;
int main()
{
	Queue q = Input() ;
	Fibonacci(q);
	PrintQueue(q);
}

Queue Input()
{
	printf("please input k, n, max respectively: ");
	scanf("%d %d %d", &k, &n, &max);
	
	Queue q = CreateQueue();
	
	return q;
}

void Fibonacci(Queue q)
{
	for (int i = 1; i <= n+1; i++)
	{
		if (i <= k-1)
			Enqueue(q, 0);
		else if (i == k)	
			Enqueue(q, 1);
		else if (i > k)	
		{
			int sum = 0, tem;
			for (int i = 1; i <= k; i++)
			{
				tem = Dequeue(q);
				sum += tem;
				Enqueue(q, tem);
			}
			Dequeue(q);
			Enqueue(q, sum);
			
			if (sum > max)
				return ;
		}
	}
}

/*
input sample1:
5 8 7

output sample1:
1 1 2 4 8

input sample2:
3 8 8

output sample2:
4 7 13

*/
