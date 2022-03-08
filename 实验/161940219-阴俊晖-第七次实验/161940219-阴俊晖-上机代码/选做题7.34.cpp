#include <iostream>
#include "mygraph.cpp"

using namespace std;

int vCount, eCount;
int main()
{
	cin >> vCount >> eCount;
	
	Graph graph(vCount, eCount);
	
	topSort(graph);//Õÿ∆À≈≈–Ú 
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
0 1 2 3 4

input sample2:
5 8
0 1 4
0 2 2
0 3 8
1 2 3
3 2 5
4 1 4
4 2 7
4 3 9

output sample2:
0 2 4 3 1

input sample3:

output sample3:


*/
