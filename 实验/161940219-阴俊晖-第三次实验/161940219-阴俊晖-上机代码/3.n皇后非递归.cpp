#include <stdio.h>
#include "mystack.h"

#define N_OF_QUEEN 8 

typedef struct QueenNode QueenNode;
typedef QueenNode* Queen;

struct QueenNode{
	int row;
	int col;
}; 

QueenNode q[N_OF_QUEEN+1];
int col[N_OF_QUEEN+1];
int sum = 0;

Stack Init();
void PlaceQueen(Stack s);
void PrintResult();

int main()
{
	Stack s = Init();
	
	PlaceQueen(s);
	
	printf("\nThere are %d results in total.", sum );
}

Stack Init()
{
	Stack s = CreateStack(N_OF_QUEEN);
	for (int i = 1; i <= N_OF_QUEEN; i++)
	{
		q[i].row = i;
		q[i].col = 1;
	}
	
	return s;
}

bool Collision(int row)
{
	for (int i = 1; i < row; i++ )
		if (q[row].col == q[i].col)
			return true;
		else if (abs(q[row].col - q[i].col) == abs(q[row].row - q[i].row))
			return true;
	
	return false;
}

void PlaceQueen(Stack s)
{
//	Push(s, 1);
	int cur_row = 1;
	
	while (cur_row != 0)
	{
		bool find = false;
		
		//1.在第row+1行找下一个皇后的位置 
		if (cur_row < N_OF_QUEEN)
		{
			for (int col = 1; col <= N_OF_QUEEN; col++)
			{
				q[cur_row+1].col = col;
				if (!Collision(cur_row+1))
				{
//					Push(s, col);
					cur_row++ ;
					find = true;
					break;
				}
			}
		}				
		//2.找全则输出 
		else if (cur_row == N_OF_QUEEN)
			PrintResult();
		
		//3.回溯 
		if (!find)
		{
			while (cur_row != 0)
			{
				if (q[cur_row].col == N_OF_QUEEN){
//					Pop(s);
					cur_row-- ;
				}
				else
				{
					for (int col = q[cur_row].col + 1; col <= N_OF_QUEEN; col++)
					{
						q[cur_row].col = col;
						if (col > N_OF_QUEEN){
//							Pop(s);
							cur_row-- ;
							break;
						}
						else if (!Collision(cur_row))
						{
//							Push(s, col);
							goto here1 ;
						}
					}
				}
			}
		}
		here1: ; 
	}
	
}

void PrintResult()
{
	printf("\n");
	
	for (int r = 1; r <= N_OF_QUEEN; r++)
	{
		for (int c = 1; c <= N_OF_QUEEN; c++)
		{
			if (r == q[r].row && c == q[r].col)
				printf(" Q");
			else
				printf(" _");
		}
		printf("\n");
	}
	
	sum++ ;
}
