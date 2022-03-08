#ifndef MINSPANNINGTREE_H
#define MINSPANNINGTREE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cfloat>
#include <string.h>
#define NONE -1 
#define UNKNOWN -1
#define COLLECTED 0
using namespace std;

class Graph{
	public:
		Graph(const string& filePath);//����ͼ 
		~Graph();//����ͼ 
		
//	private:
		vector<vector<float> > matrix;//�ڽӾ��� 
		int vCnt;//������� 
		int eCnt;//�߸��� 
};

struct Edge{
	int v1;
	int v2;
	float weight;//�ߵ�Ȩֵ 
	bool collected;//�Ƿ�������С������ 
	
	Edge(int v1In, int v2In, float weightIn): v1(v1In), v2(v2In), weight(weightIn), collected(false){}
	
	bool operator<(const Edge& edge)
	{
		return weight < edge.weight;
	}
};

void Prim(const Graph& graph);//Prim�㷨 
void Kruskal(const Graph& graph);//Kruskal�㷨 

#endif
