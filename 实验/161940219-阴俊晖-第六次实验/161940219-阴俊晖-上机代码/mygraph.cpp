#include <iostream>
#include <queue>
#include <stack>
#include <stdlib.h>
#include "mygraph.h" 

//1.����ͼ
Graph::Graph(int vCnt, int eCnt):vCount(vCnt), eCount(eCnt)
{
	matrix.resize(vCount, vector<int>(vCount, 0));
	
	int v1, v2;
	for (int i = 1; i <= eCount; i++)
	{
		cin >> v1 >> v2;
		matrix[v1][v2] = 1;
		matrix[v2][v1] = 1;
	}
}

//2.����ͼ
Graph::~Graph()
{
	vCount = eCount = 0;
	matrix.resize(vCount, vector<int>(vCount, 0));
}

//3.���رߵ�Ȩ 
int GetEdge(Graph& graph, int v1, int v2)
{
	return graph.matrix[v1][v2];
}

//4.���ص�һ���ڽӵ�
int FirstAdjVertax(Graph& graph, int v)
{
	for (int i = 0; i < graph.vCount; i++)
		if (graph.matrix[v][i] != 0)
			return i;
			
	return NOTFOUND;
}

//5.����v1�����v2��һ���ڽӵ� 
int NextAdjVertax(Graph& graph, int v1, int v2)
{
	for (int i = v2+1; i < graph.vCount; i++)
		if (graph.matrix[v1][i] != 0)
			return i;
			
	return NOTFOUND;
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
//					cout << "!!!" << endl;
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

//8.�������� 
void AddVertax(Graph& graph)
{
	//���ڽӾ�������һ�� 
	for (int i = 0; i < graph.vCount; i++)
		graph.matrix[i].push_back(0);
	//���ڽӾ�������һ��	
	graph.matrix.push_back(vector<int>(graph.vCount, 0));
	
	graph.vCount++;
}

//9.������
void AddEdge(Graph& graph, int v1, int v2)
{
	graph.matrix[v1][v2] = 1; 
	graph.eCount++;
}

//10.ɾ������
void DeleteVertax(Graph& graph)
{
	for (int i = 0; i < graph.vCount-1; i++)
		graph.matrix[i].erase(graph.matrix[i].begin()+graph.vCount-1);

	graph.matrix.erase(graph.matrix.begin()+graph.vCount-1);		
	
	graph.vCount--;
}

//11.ɾ���� 
void DeleteEdge(Graph& graph, int v1, int v2)
{
	graph.matrix[v1][v2] = 0;
	graph.eCount--;
}
