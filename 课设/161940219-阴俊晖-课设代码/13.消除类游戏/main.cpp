#include <iostream>
#include <string.h>

#define MAX 20
#define UNKONWN -1
#define REMAINED 0
#define DELETE 1

using namespace std;

void Init();
void mark();
void print();

int N, M;
int board[MAX][MAX];//���� 
bool marked[MAX][MAX];//����Ƿ�ɾ�� 

int main()
{
	Init();//��ʼ������ 
	
	mark();//��ɾ��λ������� 

	print();//������ 
}

void Init()
{
	cin >> N >> M;
	//��ʼ��ԭ���� 
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];
		}
	}
	
	//��ʼ��������� 
	memset(marked, REMAINED, sizeof(marked));
}

void mark()
{
	int cur = UNKONWN;//��ǰ���� 
	int last = UNKONWN;//ǰһ������ 
	int last_last = UNKONWN;//ǰһ����ǰһ������ 
	
	//1.�Ȱ��н��б��
	for (int i = 0; i < N; i++)
	{
		//���üĴ���
		cur = last = last_last = UNKONWN;
		
		for (int j = 0; j < M; j++)
		{
			//��λ�Ĵ� 
			last_last = last;
			last = cur;
			cur = board[i][j];
			
			//����ɾ������ 
			if ((cur == last) && (last == last_last))
			{
				marked[i][j] = marked[i][j-1] = marked[i][j-2] = DELETE;
			}
		}
	}
	
	//2.�ٰ��н��б��
	for (int j = 0; j < M; j++)
	{
		//���üĴ���
		cur = last = last_last = UNKONWN; 
		
		for (int i = 0; i < N; i++)
		{
			//��λ�Ĵ� 
			last_last = last;
			last = cur;
			cur = board[i][j];
			
			//����ɾ������ 
			if (last_last == last == cur)
			{
				marked[i][j] = marked[i-1][j] = marked[i-2][j] = DELETE;
			}
		}
	}
}

void print()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			//δɾ���İ�ԭ������� 
			if (marked[i][j] == REMAINED)
			{
				cout << board[i][j] << ' ';
			}
			else//ɾ�������0 
			{
				cout << "0" << ' ';
			}
		}
		cout << endl;
	}
}

/*
input sample1:
4 5
2 2 3 1 2
3 4 5 1 4
2 3 2 1 3
2 2 2 4 4

output sample1:
2 2 3 0 2
3 4 5 0 4
2 3 2 0 3
0 0 0 4 4

input sample2:
4 5
2 2 3 1 2
3 1 1 1 1
2 3 2 1 3
2 2 3 3 3

output sample2:
2 2 3 0 2
3 0 0 0 0
2 3 2 0 3
2 2 0 0 0

input sample3:

output sample3:

*/
