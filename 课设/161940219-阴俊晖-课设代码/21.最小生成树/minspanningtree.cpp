#include "minspanningtree.h"

//建立图
Graph::Graph(const string& filePath)
{
	fstream dataFile(filePath, ios::in);
	int vCount, eCount;
	dataFile >> vCount >> eCount;
	vCnt = vCount; 
	eCnt = eCount; 
	
	matrix.resize(vCount+1, vector<float>(vCount+1, FLT_MAX));
	
	int v1, v2;
	float edge;
	for (int i = 1; i <= eCount; i++)
	{
		dataFile >> v1 >> v2 >> edge;
		matrix[v1][v2] = edge;
		matrix[v2][v1] = edge;
	}
	
	dataFile.close();
}

//销毁图
Graph::~Graph()
{
	vCnt = eCnt = 0;
	matrix.clear();
}

void Prim(const Graph& graph)
{	
	cout << "Prim算法：" << endl;
	vector<float> dist(graph.vCnt+1, FLT_MAX);//结点到生成树的距离 
	int eCnt = 0;//统计当前树的边数 
	float sum = 0;//边权之和 
	
	vector<float> father(graph.vCnt+1, NONE);//记录最小生成树所用边 
	vector<Edge> edges;//统计最小生成树所用边 
	const int start = 1;
	dist[start] = COLLECTED;
	for (int i = 1; i <= graph.eCnt; i++)
		if ((dist[i] != COLLECTED) && (graph.matrix[start][i] < dist[i]))
		{
			dist[i] = graph.matrix[start][i];
			father[i] = start;
		}
	
	while (1)
	{
		float minCost = FLT_MAX;
		int v = UNKNOWN;
		//找一个dist值最小的v 
		for (int i = 1; i <= graph.vCnt; i++)
		{
			if ((dist[i] != COLLECTED) && (dist[i] < minCost))
			{
				minCost = dist[i];
				v = i; 
			}
		}
		
		if (v == UNKNOWN)//未找到该v 
			break;
		else//找到v 
		{
			edges.push_back(Edge(v, father[v], dist[v]));
			dist[v] = COLLECTED;//将该结点收入生成树中
			sum += minCost;
			eCnt++;
		}
			
		for (int i = 1; i <= graph.vCnt; i++)
			if ((dist[i] != COLLECTED) && (graph.matrix[v][i] < dist[i]))
			{
				dist[i] = graph.matrix[v][i];
				father[i] = v;
			}
	}
	
	if (eCnt == graph.vCnt-1)
	{
		//输出最小生成树的权值之和
		cout << "最小生成树权值之和为：" << sum << endl
			 << "所用边如下：" << endl;
		
		for (int i = 0; i < edges.size(); i++)
			cout << edges[i].v1 << "-" << edges[i].v2 << endl;
	}
	else
		cout << "最小生成树不存在！" << endl;
	cout << endl;
}

int findRoot(int fa[], int v)
{
	if (fa[v] == NONE)
		return v;
	else
		return fa[v] = findRoot(fa, fa[v]);
}

void Kruskal(const Graph& graph)
{
	cout << "Kruskal算法：" << endl;
	
	vector<Edge> edges;
	for (int i = 1; i <= graph.vCnt; i++)
	{
		for (int j = i+1; j <= graph.vCnt; j++)
			if (graph.matrix[i][j] != FLT_MAX)
				edges.push_back(Edge(i, j, graph.matrix[i][j]));
	}
	
	sort(edges.begin(), edges.end());
	
	int root[graph.vCnt+1];
	memset(root, NONE, sizeof(root));//初始化并查集 
	
	int eCnt = 0;//统计当前树的边数 
	float sum = 0;//边权之和 
	for (int i = 0; i < graph.eCnt; i++)
	{
		if (findRoot(root, edges[i].v1) != findRoot(root, edges[i].v2))
		{
			//归并两棵子树 
			root[findRoot(root, edges[i].v1)] = findRoot(root, edges[i].v2);
			edges[i].collected = true;//将其收入生成树，记录所用边 
			sum += edges[i].weight;
			
			eCnt++;//更新生成树的边数 
			if (eCnt == graph.vCnt-1)
				break;
		}
	}
	
	if (eCnt == graph.vCnt-1)
	{
		//输出最小生成树的权值之和
		cout << "最小生成树权值之和为：" << sum << endl
			 << "所用边如下：" << endl;
		
		for (int i = 0; i < graph.eCnt; i++)
			if (edges[i].collected)
				cout << edges[i].v1 << "-" << edges[i].v2 << endl;
	}
	else
		cout << "最小生成树不存在！" << endl;
}
