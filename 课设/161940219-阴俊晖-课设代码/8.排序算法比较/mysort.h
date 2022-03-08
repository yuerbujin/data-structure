#ifndef MYSORT_H
#define MYSORT_H

#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <io.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>

using namespace std;

//获取第i个样本文件路径 
const string GetFilePath(int i);
//产生随机数样本文件 
bool createTestfile(int fileNum, int dataNum);

void Insertion_Sort(int fileNum);//1.直接插入排序 
void Shell_Sort(int fileNum);//2.希尔排序
void Bubble_Sort(int fileNum);//3.冒泡排序
void Quick_Sort(int fileNum);//4.快速排序
void Selection_Sort(int fileNum);//5.选择排序
void Heap_Sort(int fileNum);//6.堆排序
void Merge_Sort(int fileNum);//7.归并排序
void Radix_Sort(int fileNum);//8.基数排序 
	
#endif 
