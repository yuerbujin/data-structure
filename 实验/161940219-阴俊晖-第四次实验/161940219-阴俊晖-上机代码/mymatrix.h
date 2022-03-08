#ifndef _MYMATRIX_H_
#define _MYMATRIX_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myqueue.h"

#define INT_MAX 0x3f3f3f3f

namespace mymatrix{
	typedef int ElemType;
}

struct TripleNode{
	int i, j;
	mymatrix::ElemType data;
};
typedef struct TripleNode TripleNode;
typedef struct TripleNode* Triple;

struct SpMatrixNode{
	Triple triple;
	int row, col;
	int num;//非零元素个数 
};

typedef struct SpMatrixNode SpMatrixNode;
typedef SpMatrixNode* SpMatrix;

struct MatrixNode{
	mymatrix::ElemType** data;
	int row, col;//行、列总数 
	int num;//非零元素个数 
};

typedef struct MatrixNode MatrixNode;
typedef MatrixNode* Matrix;

//1.创建稀疏矩阵三元组 
SpMatrix InitSpMa(Matrix ma)
{
	SpMatrix sma = (SpMatrix)malloc(sizeof(SpMatrixNode));
	sma->row = ma->row;
	sma->col = ma->col;
	sma->num = ma->num;
	
	sma->triple = (Triple)malloc(sma->num*sizeof(TripleNode));
	
	int k = 0;
	for (int i = 0; i < ma->row; i++)
		for (int j = 0; j < ma->col; j++)
			if (ma->data[i][j] != 0)
			{
				sma->triple[k].i = i;
				sma->triple[k].j = j;
				sma->triple[k].data = ma->data[i][j];
				k++ ;
			}
				
	return sma; 
}

//2.1 列序遍历转置
SpMatrix ColTrans(SpMatrix sma1)
{
	SpMatrix sma2 = (SpMatrix)malloc(sizeof(SpMatrixNode));
	sma2->row = sma1->col;
	sma2->col = sma1->row;
	sma2->num = sma1->num;
	
	sma2->triple = (Triple)malloc(sma1->num*sizeof(TripleNode));
	
	int k = 0;
	for (int col = 0; col < sma2->num; col++)
	{
		for (int i = 0; i < sma1->num; i++)
			if (sma1->triple[i].j == col)
			{
				sma2->triple[k].i = sma1->triple[i].j;
				sma2->triple[k].j = sma1->triple[i].i;
				sma2->triple[k].data = sma1->triple[i].data;
				k++ ;
			}
	}
	
	return sma2;
}

//2.2 快速转置
SpMatrix FastTrans(SpMatrix sma1)
{
	SpMatrix sma2 = (SpMatrix)malloc(sizeof(SpMatrixNode));
	sma2->row = sma1->col;
	sma2->col = sma1->row;
	sma2->num = sma1->num;
	sma2->triple = (Triple)malloc(sma1->num*sizeof(TripleNode));
	
	int rowNums[sma2->row];
	int rowStart[sma2->row];
	memset(rowNums, 0, sizeof(rowNums));
	
	//1.统计转置矩阵每行非零元个数 
	for (int i = 0; i < sma1->num; i++)
	{
		int col = sma1->triple[i].j;
		rowNums[col]++ ;
	}
	//2. 计算转置矩阵每行起点 
	rowStart[0] = 0;
	for (int i = 1; i < sma2->row; i++)
		rowStart[i] = rowStart[i-1] + rowNums[i-1]; 
	//3.转置
	for (int i = 0; i < sma1->num; i++)
	{
		int col = sma1->triple[i].j;
		int pos = rowStart[col]++ ;//找到起点并更新 
		
		sma2->triple[pos].i = col; 
		sma2->triple[pos].j = sma1->triple[i].i; 
		sma2->triple[pos].data = sma1->triple[i].data; 
	}
	
	return sma2;
}

//3.求马鞍点
void SaddlePoint(Matrix ma)
{
	int min[ma->row];
	int max[ma->col];
	
	int m;
	//1.求每行最小值 
	for (int i = 0; i < ma->row; i++)
	{
		m = INT_MAX;
		for (int j = 0; j < ma->col; j++)
		{
			if (ma->data[i][j] < m){
				m = ma->data[i][j];
			}
		}
		
		min[i] = m;
	}
	
	//2.求每列最大值
	for (int i = 0; i < ma->col; i++)
	{
		m = INT_MIN;
		for (int j = 0; j < ma->row; j++)
		{
			if (ma->data[j][i] > m)
				m = ma->data[j][i];
		}
		max[i] = m;
	}
	
	//3.求马鞍点
	int saddle_point;
	int row, col;
	bool found = false;
	int i, j;
	for (i = 0; i < ma->row; i++)
	{
		for (j = 0; j < ma->col; j++)
		{
			if (min[i] == max[j]){
				saddle_point = min[i];
				row = i;
				col = j;
				found = true;
				goto here ;
			}
		}
	}
	here:;
	
	//4.输出结果 
	if (found)
		printf("saddle point: %d row: %d col: %d\n", saddle_point, i, j );
	else
		printf("There is no saddle point in this matrix.\n");
}

//4.1输出矩阵 
void PrintMa(Matrix ma)
{
	printf( "Matrix:\n" ) ;
	int k = 0;
	for (int i = 0; i < ma->row; i++)
	{
		for (int j = 0; j < ma->col; j++)
			printf("%d\t", ma->data[i][j]); 
	
		printf("\n") ;
	}
		
	printf("\n") ;
}

//4.2输出稀疏矩阵 
void PrintSpMa(SpMatrix sma)
{
	printf( "Sparse Matrix:\n" ) ;
	int k = 0;
	for (int i = 0; i < sma->row; i++)
	{
		for (int j = 0; j < sma->col; j++)
		{
			if (i == sma->triple[k].i && j == sma->triple[k].j)
			{
				printf("%d\t", sma->triple[k].data) ;
				k++ ;
			}
			else
				printf("0\t") ;
		}
		printf("\n") ;
	}
		
	printf("\n") ;
}

//5.同色区域置换
void SetColor(Matrix ma)
{
	int x0, y0;
	printf("please input i0 and j0: ");
	scanf("%d%d", &x0, &y0);
	
	int newColor;
	printf("please input new color: ");
	scanf("%d", &newColor);
	// 准备工作 
	bool visited[ma->row][ma->col];
	memset(visited, false, sizeof(visited));
	
	Queue q = CreateQueue();
	Enqueue(q, Point(x0, y0));
	visited[x0][y0] = true;
	
	// BFS
	Point p;
	while (!IsEmpty(q))
	{
		p = Dequeue(q);
		
		//1.点p的同色四邻域入队
		mymatrix::ElemType oriColor = ma->data[p.x][p.y];
		if (	(!visited[p.x][p.y-1])
			&&	(p.y-1 >= 0)
			&&	(ma->data[p.x][p.y-1] == oriColor)	)
		{
			Enqueue(q, Point(p.x, p.y-1));
			visited[p.x][p.y-1] = true;
		}
		
		if (	(!visited[p.x+1][p.y])
			&&	(p.x+1 < ma->row)
			&&	(ma->data[p.x+1][p.y] == oriColor)	)
		{
			Enqueue(q, Point(p.x+1, p.y));
			visited[p.x+1][p.y] = true;
		}
		
		if (	(!visited[p.x][p.y+1])
			&&	(p.y+1 < ma->col)
			&&	(ma->data[p.x][p.y+1] == oriColor)	)
		{
			Enqueue(q, Point(p.x, p.y+1));
			visited[p.x][p.y+1] = true;
		}
		
		if (	(!visited[p.x-1][p.y])
			&&	(p.x-1 >= 0)
			&&	(ma->data[p.x-1][p.y] == oriColor)	)
		{
			Enqueue(q, Point(p.x-1, p.y));
			visited[p.x-1][p.y] = true;
		}
		//2.该点出队并访问 
		ma->data[p.x][p.y] = newColor;
	}
} 

//读入数据 
Matrix Input()
{
	Matrix ma = (Matrix)malloc(sizeof(MatrixNode));
	scanf( "%d%d", &(ma->row), &(ma->col)) ;
	//开辟二维数组 
	ma->data = (mymatrix::ElemType**)malloc(ma->row*sizeof(mymatrix::ElemType*));
	ma->data[0] = (mymatrix::ElemType*)malloc(ma->row*ma->col*sizeof(mymatrix::ElemType));
	for (int i = 1; i < ma->row; i++)
		ma->data[i] = ma->data[i-1] + ma->col;

	ma->num = 0;
	
	for(int i = 0; i < ma->row; i++)
		for(int j = 0; j < ma->col; j++)
		{
			scanf("%d", &(ma->data[i][j])) ;
			if (ma->data[i][j] != 0)
				ma->num++ ;
		}
	
	return ma;
}

#endif
