#include <stdio.h>
#include "myqueue.h"

int N, K;
void Input2(Queue q);
void DistributeCake(Queue q);

int main()
{
	Queue q = CreateQueue();
	Input2(q);
	
	DistributeCake(q);
}

void Input2(Queue q)
{
	scanf("%d%d", &N, &K);
	ElemType elem;
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &elem);
		Enqueue(q, elem);
	}
}

void DistributeCake(Queue q)
{
	int k = K;
	int sum = 0;
	
	while (!IsEmpty(q)){
		k -= Dequeue(q);
		if (k <= 0){
			k = K;
			sum++ ;
		}
	}
	
	if (k < K)
		sum++ ;
	
	printf("%d", sum);
}

/*
6 9
2 6 5 6 3 5
*/
