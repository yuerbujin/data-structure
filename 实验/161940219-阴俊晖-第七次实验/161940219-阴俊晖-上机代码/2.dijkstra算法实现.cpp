#include <iostream>
#include "mygraph.cpp"

int main()
{
	int vCount, eCount;
	cin >> vCount >> eCount;
	
	Graph graph(vCount, eCount);
	
	Dijkstra(graph, 0);
}

/*
input sample1:
5 8
0 1 2
0 2 6
0 3 9
1 2 3
1 4 7
2 3 1
2 4 2
3 4 2

output sample1:

input sample2:

output sample2:

input sample3:

output sample3:


*/
