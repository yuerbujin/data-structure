#include <iostream>
#include <stdio.h>
#include <string.h>
#define COLUMN 10
#define ROW 15

using namespace std;

struct blockPos{
	int row;
	int col;
}; 

int matrix[ROW][COLUMN];
blockPos block[16];
int blockCount = 0;//方块个数 
int leftBegin;//下落的初始位置

void Input();
void Solve();
void Print(); 

int main()
{
	Input();
	
	Solve();
	
	Print();
} 

void Input()
{
	for (int row = 0; row < ROW; row++)
		for (int col = 0; col < COLUMN; col++)
			cin >> matrix[row][col];
			
	int tem;
	int k = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			cin >> tem;
			if (tem)
			{
				block[k].row = i;
				block[k].col = j;
				k++;
			}
		}
	blockCount = k;
	
	cin >> leftBegin;
}

void Solve()
{
	//找到下落的初始列位置
	int min = 3;
	for (int i = 0; i < blockCount; i++)
		if (block[i].col < min)
			min = block[i].col;
			
	leftBegin -= min;
	
	for (int i = 0; i < blockCount; i++)
		block[i].col += leftBegin;
	
	//此时block[]中位置即方块初始位置 
	//下落 
	while (1)
	{
		for (int i = 0; i < blockCount; i++)
			if (	(matrix[block[i].row+1][block[i].col] == 1)
				||	(block[i].row+1 >= ROW)		)
				goto here1;
		
		for (int i = 0; i < blockCount; i++)
			block[i].row++;
	}
	
	here1:;
	
	//填充
	for (int i = 0; i < blockCount; i++)
		matrix[block[i].row][block[i].col] = 1;
}

void Print()
{
	for (int row = 0; row < ROW; row++)
	{
		for (int col = 0; col < COLUMN; col++)
		{
			cout << matrix[row][col] << ' ';
		}
		cout << endl;
	}
}

/*
input sample1:
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 1 0 0
0 0 0 0 0 0 1 0 0 0
0 0 0 0 0 0 1 0 0 0
1 1 1 0 0 0 1 1 1 1
0 0 0 0 1 0 0 0 0 0
0 0 0 0
0 1 1 1
0 0 0 1
0 0 0 0
3

output sample1:
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 1 0 0
0 0 0 0 0 0 1 0 0 0
0 0 0 0 0 0 1 0 0 0
1 1 1 1 1 1 1 1 1 1
0 0 0 0 1 1 0 0 0 0

input sample2: 
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 1 0 0
0 0 0 0 0 0 1 0 0 0
0 0 0 0 0 0 1 0 0 0
1 1 1 0 0 0 1 1 1 1
0 0 0 0 1 0 0 0 0 0
0 0 1 0
0 1 1 1
0 0 1 0
0 0 0 0
2

output sample2:
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 1 0 0
0 0 0 1 0 0 1 0 0 0
0 0 1 1 1 0 1 0 0 0
1 1 1 1 0 0 1 1 1 1
0 0 0 0 1 0 0 0 0 0
*/
