#include <iostream>
#include <list>
#include <stack>
#include <string.h>

using namespace std;

void Init(list<int> listArray[]);
bool roadLength(list<int> listArray[], int v1, int v2, int k);
void DFS(list<int> listArray[], bool visited[], int start, int des, int& length, int k, bool& found);

int N, M;
int main()
{
	cin >> N >> M;
	list<int> listArray[N];//以对象数组作为邻接表 
	
	Init(listArray);
	
	roadLength(listArray, 7, 2, 0);
	roadLength(listArray, 7, 2, 1);
	roadLength(listArray, 7, 2, 2);
	roadLength(listArray, 7, 2, 3);
	roadLength(listArray, 7, 2, 4);
}

void Init(list<int> listArray[])
{
	int v1, v2;
	for (int i = 0; i < M; i++)
	{
		cin >> v1 >> v2;
		//无向图 
		listArray[v1].push_back(v2);
		listArray[v2].push_back(v1);
	}
}

bool roadLength(list<int> listArray[], int start, int des, int k)
{	 
	bool visited[N];
	memset(visited, false, sizeof(visited));
	int length = 0;
	bool found = false;
	
	DFS(listArray, visited, start, des, length, k, found);
	
	if (found)
		cout << "Yes!" << endl;
	else
		cout << "No!" << endl;
}

void DFS(list<int> listArray[], bool visited[], int start, int des, int& length, int k, bool& found)
{
	if ((length == k) && (start == des))//若找到终点 
	{
		found = true;
	}
	else//若未找到终点 
	{
		visited[start] = true;
		length++;
		
		for (list<int>::iterator iter = listArray[start].begin(); iter != listArray[start].end(); iter++)
			if ((!found) && (!visited[*iter]))
				DFS(listArray, visited, *iter, des, length, k, found);
	
		visited[start] = false;
		length--;		
	}
}

/*
input sample1:
8 6
0 7
0 1
2 0
4 1
2 4
3 5

等价类:
{ 0 1 4 2 7 }
{ 3 5 }
{ 6 }

input sample2:

output sample2:

*/
