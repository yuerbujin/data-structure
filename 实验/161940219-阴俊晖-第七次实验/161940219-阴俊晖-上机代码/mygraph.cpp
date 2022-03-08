#include <iostream>
#include <queue>
#include <stack>
#include <stdlib.h>
#include <string.h>
#include "mygraph.h"

//1.建立图
Graph::Graph(int vCnt, int eCnt):vCount(vCnt), eCount(eCnt)
{
	matrix.resize(vCount, vector<int>(vCount, INT_MAX));//零图 
	inDegree.resize(vCount, 0); 
	outDegree.resize(vCount, 0); 
	
	int v1, v2, edge;
	for (int i = 1; i <= eCount; i++)
	{
		cin >> v1 >> v2 >> edge;
		matrix[v1][v2] = edge;
		
		outDegree[v1]++;
		inDegree[v2]++;
	}
}

//2.销毁图
Graph::~Graph()
{
	vCount = eCount = 0;
	matrix.resize(vCount, vector<int>(vCount, 0));
}

//6.7.图的遍历 
void Graph::ListComponents(Traversal mode)
{
	vector<bool> visited(vCount, false);
	
	cout << endl;
	
	switch (mode)
	{
		case DFS_:
			for (int i = 0; i < vCount; i++)
				if (!visited[i]){
					DFS(*this, i, visited);
				}

			break;
		case BFS_:
			for (int i = 0; i < vCount; i++)
				if (!visited[i])
					BFS(*this, i, visited);
					
			break;
	}
	
	cout << endl;
}

//6.DFS
void DFS(Graph& graph, int v, vector<bool>& visited)
{
	cout << v << ' ';
	visited[v] = true;
	
	for (int i = 0; i < graph.vCount; i++)
		if ((!visited[i]) && (graph.matrix[v][i] != 0))
			DFS(graph, i, visited);
}

//7.BFS
void BFS(Graph& graph, int v, vector<bool>& visited)
{
	queue<int> q;
	q.push(v);
	visited[v] = true;
	
	int vertax;
	while (!q.empty())
	{
		vertax = q.front();
		q.pop();
		
		cout << vertax << ' ';
		
		for (int i = 0; i < graph.vCount; i++)
			if ((!visited[i]) && (graph.matrix[vertax][i] != 0))
			{
				visited[i] = true;
				
				q.push(i);
			}
	}
}

//2. Dijkstra
void Dijkstra(Graph& graph, int start)
{
	vector<int> visited(graph.vCount, false);
	vector<int> dist(graph.vCount, INT_MAX);
	
	dist[start] = 0;
	
	while (1)
	{
		int v = NOTFOUND;
		int min = INT_MAX;
		
		for (int i = 0; i < graph.vCount; i++)
			if ((!visited[i]) && (dist[i] < min))
			{
				min = dist[i];
				v = i;
			}
			
		if (v == NOTFOUND)
			break;
		
		visited[v] = true;
		for (int i = 0; i < graph.vCount; i++)
			if ((!visited[i]) && (dist[v] + graph.matrix[v][i] < dist[i]))
				dist[i] = dist[v] + graph.matrix[v][i];
	}
	
	for (int i = 0; i < graph.vCount; i++)
		cout << "dist[i]: " << dist[i] << endl;
	
//	vector<bool> collected(graph.vCount, false);
//	vector<int> dist(graph.vCount, INT_MAX);
//	vector<int> path(graph.vCount, NOTFOUND);//起初都无前驱结点 
//	
//	dist[start] = 0; 
//	
//	//核心实现 
//	while (1)
//	{
//		int minD = INT_MAX;
//		int minV = NOTFOUND;
//		for (int i = 0; i < graph.vCount; i++)
//		{
//			if ((!collected[i]) && (dist[i] < minD))
//			{
//				minD = dist[i];
//				minV = i;
//			}
//		}
//		
//		if (minV == NOTFOUND)
//			break;
//		
//		collected[minV] = true;
//		for (int i = 0; i < graph.vCount; i++)
//		{
//			if ((!collected[i]) && (dist[minV] + graph.matrix[minV][i] < dist[i]))
//			{
//				dist[i] = dist[minV] + graph.matrix[minV][i];
//				path[i] = minV;
//			}
//		}
//	}
//	
//	//输出结果 
//	cout << endl << "dist[]: ";
//	for (int i = 0; i < dist.size(); i++)
//	{
//		cout << dist[i] << " ";
//	}
//	cout << endl;
//	
//	cout << "path[]: ";
//	for (int i = 0; i < dist.size(); i++)
//	{
//		cout << path[i] << " ";
//	}
}

//3.拓扑排序 
void topSort(Graph& graph)
{
	int number[graph.vCount];
	int given = 0;//当前应赋予的编号 
	bool visited[graph.vCount];//辅助数组 
	memset(visited, false, sizeof(visited));
	
	while (1)
	{
		//找一个入度为0的结点 
		int v = NOTFOUND;
		for (int i = 0; i < graph.vCount; i++)
		{
			if ((!visited[i]) && (graph.inDegree[i] == 0))
			{
				v = i;
				break;
			}
		}
		
		if (v == NOTFOUND)//未找到v 
			break;
		else//找到v 
		{
			number[v] = given;//赋予编号 
			given++;
			
			visited[v] = true;//相当于删除该结点 
			for (int i = 0; i < graph.vCount; i++)
				if (graph.matrix[v][i] != INT_MAX)//有边相连 
					graph.inDegree[i]--;//相当于删除结点所连的边 
		}
	}
	
	for (int i = 0; i < graph.vCount; i++)
		cout << "v" << i << ": " << number[i] << endl;
}

//4.最长路径
void longestRoad(Graph& graph, int start)
{
	vector<int> inDegree(graph.inDegree);//拷贝所有结点入度信息 
	
	bool visited[graph.vCount];//辅助数组 
	memset(visited, false, sizeof(visited));
	int dist[graph.vCount];//记录路径 
	memset(dist, 0, sizeof(dist));
	bool flag = false;//是否已经从起点出发 
	
	while (1)
	{
		//找一个入度为0的结点 
		int v = NOTFOUND;
		for (int i = 0; i < graph.vCount; i++)
		{
			if ((!visited[i]) && (inDegree[i] == 0))
			{
				v = i;
				break;
			}
		}
		
		if (v == NOTFOUND)//未找到v 
			break;
		else//找到v
		{
			if (v == start)//找到起点并开始记录路径 
			{
				flag = true;
				dist[v] = 0;//到自身路径为0 
			} 
			
			if (!flag)
			{
				dist[v] = INT_MAX;//该结点不可达 
				
				visited[v] = true;//相当于删除该结点 
				for (int i = 0; i < graph.vCount; i++)
					if (graph.matrix[v][i] != INT_MAX)//有边相连 
						inDegree[i]--;//相当于删除结点所连的边
			}
			else
			{
				visited[v] = true;//相当于删除该结点 
				for (int i = 0; i < graph.vCount; i++)
					if (graph.matrix[v][i] != INT_MAX)//有边相连 
					{
						inDegree[i]--;//相当于删除结点所连的边
						
						//更新策略 
						if (dist[i] < dist[v] + graph.matrix[v][i])
							dist[i] = dist[v] + graph.matrix[v][i];
					} 
			}
		}
	}
	
	for (int i = 0; i < graph.vCount; i++)
		cout << "dist[" << i << "]: " << dist[i] << endl;
}
