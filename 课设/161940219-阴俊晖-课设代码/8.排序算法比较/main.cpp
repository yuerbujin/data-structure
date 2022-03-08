#include <iostream>
#include "mysort.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv)
{
	const int fileNum = 10;
////	const int dataNum = 20;
//	const int dataNum = 50000;
//	createTestfile(fileNum, dataNum);//产生随机数样本文件，只调用一次 
	//第一个样本正序 
	//第二个样本逆序 
	//要用相同的样本！！！！！！ 
	
	//1.直接插入排序
	Insertion_Sort(fileNum);
	
	//2.希尔排序
	Shell_Sort(fileNum);
	
	//3.冒泡排序
	Bubble_Sort(fileNum);
	
	//4.快速排序
	Quick_Sort(fileNum);
	
	//5.选择排序
	Selection_Sort(fileNum);
	
	//6.堆排序
	Heap_Sort(fileNum);
	
	//7.归并排序
	Merge_Sort(fileNum);
	
	//8.基数排序
	Radix_Sort(fileNum);
	
	return 0;
}
