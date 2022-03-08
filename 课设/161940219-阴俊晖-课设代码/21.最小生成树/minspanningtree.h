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
		Graph(const string& filePath);//建立图 
		~Graph();//销毁图 
		
//	private:
		vector<vector<float> > matrix;//邻接矩阵 
		int vCnt;//顶点个数 
		int eCnt;//边个数 
};

struct Edge{
	int v1;
	int v2;
	float weight;//边的权值 
	bool collected;//是否收入最小生成树 
	
	Edge(int v1In, int v2In, float weightIn): v1(v1In), v2(v2In), weight(weightIn), collected(false){}
	
	bool operator<(const Edge& edge)
	{
		return weight < edge.weight;
	}
};

void Prim(const Graph& graph);//Prim算法 
void Kruskal(const Graph& graph);//Kruskal算法 

#endif
