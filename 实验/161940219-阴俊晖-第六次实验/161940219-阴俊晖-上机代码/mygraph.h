#ifndef MYGRAPH_H
#define MYGRAPH_H

#include <vector>

//#define INT_MAX 0x3f3f3f3f
#define NOTFOUND -1

using namespace std;

enum Traversal{DFS_, BFS_};

class Graph{
	public:
		Graph(int vCnt, int eCnt);//建立图 
		~Graph();//销毁图 
		
		void ListComponents(Traversal mode);//图的遍历
		
//	private:
		vector<vector<int> > matrix;//邻接矩阵 
		int vCount;//顶点个数 
		int eCount;//边个数 
};

void DFS(Graph& graph, int v, vector<bool>& visited);
void BFS(Graph& graph, int v, vector<bool>& visited);

#endif
