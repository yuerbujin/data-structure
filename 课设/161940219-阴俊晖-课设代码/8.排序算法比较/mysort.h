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

//��ȡ��i�������ļ�·�� 
const string GetFilePath(int i);
//��������������ļ� 
bool createTestfile(int fileNum, int dataNum);

void Insertion_Sort(int fileNum);//1.ֱ�Ӳ������� 
void Shell_Sort(int fileNum);//2.ϣ������
void Bubble_Sort(int fileNum);//3.ð������
void Quick_Sort(int fileNum);//4.��������
void Selection_Sort(int fileNum);//5.ѡ������
void Heap_Sort(int fileNum);//6.������
void Merge_Sort(int fileNum);//7.�鲢����
void Radix_Sort(int fileNum);//8.�������� 
	
#endif 
