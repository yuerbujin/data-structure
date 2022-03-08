#include <iostream>
#include <string.h>

#define MAX 20
#define INT_MAX 0x3f3f3f3f
#define UNKNOWN -1
#define COLLECTED 0//该结点在生成树上 

using namespace std;

void Init();
void Prim();

int N, M;
int graph[MAX][MAX];//存放图 

int main()
{
	Init();//初始化
	
	Prim();
}

void Init()
{
	cin >> N >> M;
	
	//初始化图 
	memset(graph, INT_MAX, sizeof(graph));
	int v1, v2;
	int cost;
	for (int i = 1; i <= M; i++)
	{
		cin >> v1 >> v2 >> cost;
		graph[v1][v2] = cost;
		graph[v2][v1] = cost;
	}
}

void Prim()
{
	int dist[MAX];
	memset(dist, INT_MAX, sizeof(dist));//结点到生成树的距离 
	int sum = 0;//总花费 
	
	const int start = 1;
	dist[start] = COLLECTED;
	for (int i = 1; i <= N; i++)
		if ((dist[i] != COLLECTED) && (graph[start][i] < dist[i]))
			dist[i] = graph[start][i];
	
	while (1)
	{
		int minCost = INT_MAX+1;
		int v = UNKNOWN;
		//找一个dist值最小的v 
		for (int i = 1; i <= N; i++)
		{
			if ((dist[i] != COLLECTED) && (dist[i] < minCost))
			{
				minCost = dist[i];
//				cout << minCost << " "; 
				v = i;
			}
		}
		
		if (v == UNKNOWN)//未找到该v 
			break;
		else//找到v 
		{
			dist[v] = COLLECTED;//将该结点收入生成树中
			sum += minCost; 
		}
			
		for (int i = 1; i <= N; i++)
			if ((dist[i] != COLLECTED) && (graph[v][i] < dist[i]))
				dist[i] = graph[v][i];
	}
	
	cout << sum; 
}

/*
input sample1:
4 4
1 2 1 
2 3 4
2 4 2
3 4 3

output sample1:
6

input sample2:
7 12
1 2 2
1 3 6
1 4 7
2 4 7
2 5 6
3 4 2
3 6 7
4 5 3
4 6 1
4 7 4
5 7 5
6 7 5

output sample2:
18

input sample3:

output sample3:


*/
