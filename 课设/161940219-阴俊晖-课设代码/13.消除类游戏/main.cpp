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
int board[MAX][MAX];//棋盘 
bool marked[MAX][MAX];//标记是否删除 

int main()
{
	Init();//初始化棋盘 
	
	mark();//对删除位置做标记 

	print();//输出结果 
}

void Init()
{
	cin >> N >> M;
	//初始化原棋盘 
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];
		}
	}
	
	//初始化标记棋盘 
	memset(marked, REMAINED, sizeof(marked));
}

void mark()
{
	int cur = UNKONWN;//当前棋子 
	int last = UNKONWN;//前一个棋子 
	int last_last = UNKONWN;//前一个的前一个棋子 
	
	//1.先按行进行标记
	for (int i = 0; i < N; i++)
	{
		//重置寄存器
		cur = last = last_last = UNKONWN;
		
		for (int j = 0; j < M; j++)
		{
			//移位寄存 
			last_last = last;
			last = cur;
			cur = board[i][j];
			
			//若需删除则标记 
			if ((cur == last) && (last == last_last))
			{
				marked[i][j] = marked[i][j-1] = marked[i][j-2] = DELETE;
			}
		}
	}
	
	//2.再按列进行标记
	for (int j = 0; j < M; j++)
	{
		//重置寄存器
		cur = last = last_last = UNKONWN; 
		
		for (int i = 0; i < N; i++)
		{
			//移位寄存 
			last_last = last;
			last = cur;
			cur = board[i][j];
			
			//若需删除则标记 
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
			//未删除的按原棋盘输出 
			if (marked[i][j] == REMAINED)
			{
				cout << board[i][j] << ' ';
			}
			else//删除的输出0 
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
