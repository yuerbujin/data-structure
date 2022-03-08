#include <iostream>
#include <queue>
#include <stack>
#include <stdlib.h>
#include <string.h>
#include "mygraph.h"

//1.����ͼ
Graph::Graph(int vCnt, int eCnt):vCount(vCnt), eCount(eCnt)
{
	matrix.resize(vCount, vector<int>(vCount, INT_MAX));//��ͼ 
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

//2.����ͼ
Graph::~Graph()
{
	vCount = eCount = 0;
	matrix.resize(vCount, vector<int>(vCount, 0));
}

//6.7.ͼ�ı��� 
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
//	vector<int> path(graph.vCount, NOTFOUND);//�������ǰ����� 
//	
//	dist[start] = 0; 
//	
//	//����ʵ�� 
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
//	//������ 
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

//3.�������� 
void topSort(Graph& graph)
{
	int number[graph.vCount];
	int given = 0;//��ǰӦ����ı�� 
	bool visited[graph.vCount];//�������� 
	memset(visited, false, sizeof(visited));
	
	while (1)
	{
		//��һ�����Ϊ0�Ľ�� 
		int v = NOTFOUND;
		for (int i = 0; i < graph.vCount; i++)
		{
			if ((!visited[i]) && (graph.inDegree[i] == 0))
			{
				v = i;
				break;
			}
		}
		
		if (v == NOTFOUND)//δ�ҵ�v 
			break;
		else//�ҵ�v 
		{
			number[v] = given;//������ 
			given++;
			
			visited[v] = true;//�൱��ɾ���ý�� 
			for (int i = 0; i < graph.vCount; i++)
				if (graph.matrix[v][i] != INT_MAX)//�б����� 
					graph.inDegree[i]--;//�൱��ɾ����������ı� 
		}
	}
	
	for (int i = 0; i < graph.vCount; i++)
		cout << "v" << i << ": " << number[i] << endl;
}

//4.�·��
void longestRoad(Graph& graph, int start)
{
	vector<int> inDegree(graph.inDegree);//�������н�������Ϣ 
	
	bool visited[graph.vCount];//�������� 
	memset(visited, false, sizeof(visited));
	int dist[graph.vCount];//��¼·�� 
	memset(dist, 0, sizeof(dist));
	bool flag = false;//�Ƿ��Ѿ��������� 
	
	while (1)
	{
		//��һ�����Ϊ0�Ľ�� 
		int v = NOTFOUND;
		for (int i = 0; i < graph.vCount; i++)
		{
			if ((!visited[i]) && (inDegree[i] == 0))
			{
				v = i;
				break;
			}
		}
		
		if (v == NOTFOUND)//δ�ҵ�v 
			break;
		else//�ҵ�v
		{
			if (v == start)//�ҵ���㲢��ʼ��¼·�� 
			{
				flag = true;
				dist[v] = 0;//������·��Ϊ0 
			} 
			
			if (!flag)
			{
				dist[v] = INT_MAX;//�ý�㲻�ɴ� 
				
				visited[v] = true;//�൱��ɾ���ý�� 
				for (int i = 0; i < graph.vCount; i++)
					if (graph.matrix[v][i] != INT_MAX)//�б����� 
						inDegree[i]--;//�൱��ɾ����������ı�
			}
			else
			{
				visited[v] = true;//�൱��ɾ���ý�� 
				for (int i = 0; i < graph.vCount; i++)
					if (graph.matrix[v][i] != INT_MAX)//�б����� 
					{
						inDegree[i]--;//�൱��ɾ����������ı�
						
						//���²��� 
						if (dist[i] < dist[v] + graph.matrix[v][i])
							dist[i] = dist[v] + graph.matrix[v][i];
					} 
			}
		}
	}
	
	for (int i = 0; i < graph.vCount; i++)
		cout << "dist[" << i << "]: " << dist[i] << endl;
}
