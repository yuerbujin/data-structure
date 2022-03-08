#include <iostream>
#include "mygraph.cpp"

int main()
{
	int vCount, eCount;
	cin >> vCount >> eCount;
	
	//1.图的创建 
	Graph graph(vCount, eCount);
	
	//6.图的遍历 
	graph.ListComponents(DFS_);
	graph.ListComponents(BFS_);

//	//5.返回v1下一个邻接点 
//	cout << endl;
//	cout << FirstAdjVertax(graph, 4) << endl;
//	
//	//5.返回v1相对于v2下一个邻接点 
//	cout << endl;
//	cout << NextAdjVertax(graph, 4, 1) << endl;
//	
//	//8.新增顶点
//	AddVertax(graph);
//	graph.ListComponents(DFS_);
//	
//	//9.新增边 
//	AddEdge(graph, 5, 8);
//	graph.ListComponents(DFS_);
//	
//	//11.删除边 
//	DeleteEdge(graph, 5, 8);
//	graph.ListComponents(DFS_);
//	
//	//10.删除顶点
//	DeleteVertax(graph);
//	DeleteVertax(graph);
//	DeleteVertax(graph);
//	graph.ListComponents(DFS_);
}

/*
input sample1:
8 6
0 7 3 
0 1 5 
2 0 6 
4 1 2 
2 4 1 
3 5 2 

等价类:
{ 0 1 4 2 7 }
{ 3 5 }
{ 6 }

input sample2:

output sample2:

*/
