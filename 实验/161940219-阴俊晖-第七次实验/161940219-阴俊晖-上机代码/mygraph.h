#ifndef MYGRAPH_H
#define MYGRAPH_H

#include <vector>

#define INT_MAX 0x3f3f3f3f
#define NOTFOUND -1

using namespace std;

enum Traversal{DFS_, BFS_};

class Graph{
	public:
		Graph(int vCnt, int eCnt);//����ͼ 
		~Graph();//����ͼ 
		
		void ListComponents(Traversal mode);//ͼ�ı���
		
//	private:
		vector<vector<int> > matrix;//�ڽӾ��� 
		int vCount;//������� 
		int eCount;//�߸��� 
		
		vector<int> inDegree;//��� 
		vector<int> outDegree;//���� 
};

void DFS(Graph& graph, int v, vector<bool>& visited);
void BFS(Graph& graph, int v, vector<bool>& visited);

#endif
