#include <stdio.h>
#include <string.h>

#define ROW 20
#define COL 5

void Init(); 
void Input();
int min(int a, int b);

int n;
int seats[ROW+1];
int main()
{
	Init();
	scanf("%d", &n);
	
	//每次循环处理一次分配 
	for (int i = 1; i <= n; i++)
		Input();
}

//第seats[i]为第i行所剩空座位个数
void Init()
{
	for (int i = 1; i <= ROW; i++)
		seats[i] = 5;
}

void Input()
{
	int p;
	scanf("%d", &p);
	
	bool allocated = false;
	for (int i = 1; i <= ROW; i++)
	{
		if (p <= seats[i]){
			for (int j = 1; j <= p; j++)
				printf("%d ", i*5 - seats[i] + j);
			
			seats[i] -= p;
			allocated = true;
			break; 
		}
	}
	
	if (!allocated)
	{
		int j = 1;
		for (int i = 1; i <= p; i++)
		{
			//找到第一个空位 
			while (seats[j] == 0)
				j++ ;
			
			printf("%d ", j*5 - seats[j] + 1);
			seats[j]-- ;
		}
	}
	
	printf("\n"); 
}

/*

input sample1:
4
2 5 4 2

output sample1:
1 2
6 7 8 9 10
11 12 13 14
3 4


input sample2:
23
4 4 4 4 4    4 4 4 4 4     4 4 4 4 4     4 4 4 4 4       4 2 3

output sample1:
1 2 3 4
6 7 8 9
....
96 97 98 99
5 10 15 20
25 30
35 40 45

*/
