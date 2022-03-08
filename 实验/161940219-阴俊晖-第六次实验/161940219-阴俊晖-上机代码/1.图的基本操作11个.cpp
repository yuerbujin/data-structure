#include <iostream>
#include "mygraph.cpp"

int main()
{
	int vCount, eCount;
	cin >> vCount >> eCount;
	
	//1.ͼ�Ĵ��� 
	Graph graph(vCount, eCount);
	
	//6.ͼ�ı��� 
	graph.ListComponents(DFS_);
	graph.ListComponents(BFS_);

	//5.����v1��һ���ڽӵ� 
	cout << endl;
	cout << FirstAdjVertax(graph, 4) << endl;
	
	//5.����v1�����v2��һ���ڽӵ� 
	cout << endl;
	cout << NextAdjVertax(graph, 4, 1) << endl;
	
	//8.��������
	AddVertax(graph);
	graph.ListComponents(DFS_);
	
	//9.������ 
	AddEdge(graph, 5, 8);
	graph.ListComponents(DFS_);
	
	//11.ɾ���� 
	DeleteEdge(graph, 5, 8);
	graph.ListComponents(DFS_);
	
	//10.ɾ������
	DeleteVertax(graph);
	DeleteVertax(graph);
	DeleteVertax(graph);
	graph.ListComponents(DFS_);
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

�ȼ���:
{ 0 1 4 2 7 }
{ 3 5 }
{ 6 }

input sample2:

output sample2:

*/
