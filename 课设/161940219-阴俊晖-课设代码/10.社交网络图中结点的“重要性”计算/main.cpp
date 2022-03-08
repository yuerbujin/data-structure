#include <iostream>
#include <queue>
#include <string.h>

#define INT_MAX 0x3f3f3f3f
#define N_MAX 1001
#define ERROR -1.0

using namespace std;

void ReadIn();
bool Calculate();
void Print();

bool graph[N_MAX][N_MAX];//��Ÿ���Ȩ����ͼ 
double Cc[N_MAX];//���ܶ�������
int N, M;
int K;

int main()
{
	ReadIn();//�������� 
	
	if (!Calculate())
		memset(Cc, 0, sizeof(Cc));//���Ƿ���ͨͼ��ȫ��0 
	
	Print();//������ 
}

void ReadIn()
{
	cin >> N >> M;
	
	for (int i = 1; i <= M; i++)
	{
		//������Ȩ����ͼ 
		int v1, v2;
		cin >> v1 >> v2;
		graph[v1][v2] = true;
		graph[v2][v1] = true;
	}
}

//��ͼ��ͨ������start���Ľ��ܶ�������
//��ͼ����ͨ����ERROR 
double BFS(int start)
{
	queue<int> queue;
	int dist[N+1];
	memset(dist, INT_MAX, sizeof(dist));
	
	queue.push(start);
	dist[start] = 0;//��� 
	
	int vertex;
	int count = 0;//ͳ�Ʊ����ʽ����� 
	double sum = 0;//�ܵ���̾��� 
	while (!queue.empty())
	{
		vertex = queue.front();
		queue.pop();
		count++;
		
		for (int i = 1; i <= N; i++)
		{
			if ((dist[i] == INT_MAX) && (graph[vertex][i])){
				dist[i] = dist[vertex] + 1;
				sum += (double)dist[i]; 
				queue.push(i);
			}
		}
	}
	
	if (count < N)
		return ERROR;
	else if(count == N)
		return sum;
}

bool Calculate()
{
	for (int i = 1; i <= N; i++)
	{
		double result = BFS(i);
		if (result == ERROR)
			return false;//ͼ����ͨ 
		else
			Cc[i] = (double)(N-1)/result;
	}
	
	return true;
}

void Print()
{
	cin >> K;
	int vertex;
	for (int i = 1; i <= K; i++)
	{
		cin >> vertex;
		printf("Cc(%d)=%.2f\n", vertex, Cc[vertex]);
	}
}

/*

//�����ֱ����PTA���ύ

input sample1:
5 8
1 2
1 3
1 4
2 3
3 4
4 5
2 5
3 5
2 4 3

output sample1:
Cc(4)=0.80
Cc(3)=1.00

input sample2:

output sample2:

input sample3:

output sample3:

*/
