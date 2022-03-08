#include "minspanningtree.h"

//����ͼ
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

//����ͼ
Graph::~Graph()
{
	vCnt = eCnt = 0;
	matrix.clear();
}

void Prim(const Graph& graph)
{	
	cout << "Prim�㷨��" << endl;
	vector<float> dist(graph.vCnt+1, FLT_MAX);//��㵽�������ľ��� 
	int eCnt = 0;//ͳ�Ƶ�ǰ���ı��� 
	float sum = 0;//��Ȩ֮�� 
	
	vector<float> father(graph.vCnt+1, NONE);//��¼��С���������ñ� 
	vector<Edge> edges;//ͳ����С���������ñ� 
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
		//��һ��distֵ��С��v 
		for (int i = 1; i <= graph.vCnt; i++)
		{
			if ((dist[i] != COLLECTED) && (dist[i] < minCost))
			{
				minCost = dist[i];
				v = i; 
			}
		}
		
		if (v == UNKNOWN)//δ�ҵ���v 
			break;
		else//�ҵ�v 
		{
			edges.push_back(Edge(v, father[v], dist[v]));
			dist[v] = COLLECTED;//���ý��������������
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
		//�����С��������Ȩֵ֮��
		cout << "��С������Ȩֵ֮��Ϊ��" << sum << endl
			 << "���ñ����£�" << endl;
		
		for (int i = 0; i < edges.size(); i++)
			cout << edges[i].v1 << "-" << edges[i].v2 << endl;
	}
	else
		cout << "��С�����������ڣ�" << endl;
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
	cout << "Kruskal�㷨��" << endl;
	
	vector<Edge> edges;
	for (int i = 1; i <= graph.vCnt; i++)
	{
		for (int j = i+1; j <= graph.vCnt; j++)
			if (graph.matrix[i][j] != FLT_MAX)
				edges.push_back(Edge(i, j, graph.matrix[i][j]));
	}
	
	sort(edges.begin(), edges.end());
	
	int root[graph.vCnt+1];
	memset(root, NONE, sizeof(root));//��ʼ�����鼯 
	
	int eCnt = 0;//ͳ�Ƶ�ǰ���ı��� 
	float sum = 0;//��Ȩ֮�� 
	for (int i = 0; i < graph.eCnt; i++)
	{
		if (findRoot(root, edges[i].v1) != findRoot(root, edges[i].v2))
		{
			//�鲢�������� 
			root[findRoot(root, edges[i].v1)] = findRoot(root, edges[i].v2);
			edges[i].collected = true;//������������������¼���ñ� 
			sum += edges[i].weight;
			
			eCnt++;//�����������ı��� 
			if (eCnt == graph.vCnt-1)
				break;
		}
	}
	
	if (eCnt == graph.vCnt-1)
	{
		//�����С��������Ȩֵ֮��
		cout << "��С������Ȩֵ֮��Ϊ��" << sum << endl
			 << "���ñ����£�" << endl;
		
		for (int i = 0; i < graph.eCnt; i++)
			if (edges[i].collected)
				cout << edges[i].v1 << "-" << edges[i].v2 << endl;
	}
	else
		cout << "��С�����������ڣ�" << endl;
}
