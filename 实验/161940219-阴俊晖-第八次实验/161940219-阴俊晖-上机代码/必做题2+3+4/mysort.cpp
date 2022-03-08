#include "mysort.h"

const string sampleFolder("sample");
const string answerFolder("answer");

const string GetFilePath(int i)
{
	char str[5];
	sprintf(str, "%d", i);
	string num(str);
	return ::sampleFolder + string("\\test") + string(str) + string(".txt");
}

bool createTestfile(int fileNum, int dataNum)
{
	srand(time(NULL));
	//若样本文件夹不存在，则创建
	//注：若文件夹不存在，access()函数返回-1 
	if (access(sampleFolder.data(), F_OK)){	
		string cmd(string("md ") + sampleFolder);
		system(cmd.data());
	}
	
	for (int i = 1; i <= fileNum; i++)
	{
		//打开文件 
		fstream testFile(GetFilePath(i).data(), ios::out);
		
		vector<int> array;
		if (i <= 2)
		{
			for (int j = 1; j <= dataNum; j++)
				array.push_back(rand());
			
			if (i == 1)
				sort(array.begin(), array.end());//使第一个样本为正序
			else if (i == 2)
				sort(array.begin(), array.end(), greater<int>());//使第二个样本为逆序
			
			for (int i = 0; i < array.size(); i++)
				testFile << array.at(i) << " ";
		}
		else
		{
			//将随机数写入文件 
			for (int j = 1; j <= dataNum; j++)
				testFile << rand() << " "; 
		}
		
		testFile.close();
	} 
}

void Insertion_Sort(int fileNum)
{
	if (access(answerFolder.data(), F_OK)){	
		string cmd(string("md ") + answerFolder);
		system(cmd.data());
	}
	
	for (int i = 1; i <= fileNum; i++)
	{
		vector<int> array;//存放待排数据 
		
		//读入待排数据 
		fstream sampleFile(GetFilePath(i).data(), ios::in);
		while (!sampleFile.eof())
		{
			int tem;
			sampleFile >> tem;
			array.push_back(tem);
		}
		
		clock_t startTime = clock();//排序起始时间 
		
		for (int i = 1; i < array.size(); i++)
		{
			int tem = array[i];//摸一张牌 
			for (; (i > 0) && (tem < array[i-1]); i--)
				array[i] = array[i-1];//移位 
			array[i] = tem;//新牌落位 
		}
		
		clock_t endTime = clock();//排序终止时间 
		
		if (i == 1)
			cout << "插入排序耗时统计（单位：ms）：" << endl; 		
		cout << "样本" << i << "：" << endTime - startTime << "ms" << endl;
				
		//将排序结果写入文件
		//设置文件名 
		char str[5];
		sprintf(str, "%d", i);
		string num(str);
		string fileName(::answerFolder + string("\\Insertion_Sort_ans") + string(str) + string(".txt"));

		fstream ansFile(fileName, ios::out);
		if (!ansFile){
			cout << "打开文件" << fileName << "失败！" << endl;
			return; 
		}
		ansFile << "插入排序耗时统计（单位：ms）：" << endl;
		ansFile << "样本" << i << "：" << endTime - startTime << "ms" << endl;
		for (int i = 0; i < array.size(); i++)
			ansFile << array.at(i) << " ";
		ansFile.close();	
	}
}

void Shell_Sort(int fileNum)
{

}

void Bubble_Sort(int fileNum)
{
	for (int i = 1; i <= fileNum; i++)
	{
		vector<int> array;//存放待排数据 
		
		//读入待排数据 
		fstream sampleFile(GetFilePath(i).data(), ios::in);
		while (!sampleFile.eof())
		{
			int tem;
			sampleFile >> tem;
			array.push_back(tem);
		}
		
		clock_t startTime = clock();//排序起始时间 
		
		for (int i = 1; i < array.size(); i++)
			for (int j = 0; j < array.size()-i; j++)
				if (array.at(j) > array.at(j+1))
					swap(array.at(j), array.at(j+1));
		
		clock_t endTime = clock();//排序终止时间 
		
		if (i == 1)
			cout << "冒泡排序耗时统计（单位：ms）：" << endl; 		
		cout << "样本" << i << "：" << endTime - startTime << "ms" << endl;
				
		//将排序结果写入文件
		//设置文件名 
		char str[5];
		sprintf(str, "%d", i);
		string num(str);
		string fileName(::answerFolder + string("\\Bubble_Sort_ans") + string(str) + string(".txt"));

		fstream ansFile(fileName, ios::out);
		if (!ansFile){
			cout << "打开文件" << fileName << "失败！" << endl;
			return; 
		}
		ansFile << "冒泡排序耗时统计（单位：ms）：" << endl;
		ansFile << "样本" << i << "：" << endTime - startTime << "ms" << endl;
		for (int i = 0; i < array.size(); i++)
			ansFile << array.at(i) << " ";
		ansFile.close();	
	}	
}

int Median3(vector<int>& array, int left, int right)
{
	//1.选出主元
	//2.left放最小，right放最大，right-1放主元
	
	int center = (right+left)/2;
	if (array.at(left) > array.at(center))
		swap(array.at(left), array.at(center)); 
	if (array.at(center) > array.at(right))
		swap(array.at(center), array.at(right));
	if (array.at(left) > array.at(center))
		swap(array.at(left), array.at(center));
	
	int pivot = array.at(center);//选出主元
	swap(array.at(center), array.at(right-1));//right-1放主元
	return pivot;
}

void quickSort(vector<int>& array, int left, int right)
{
	if (left >= right)
		return;
	int pivot = Median3(array, left, right);//选出主元 
	if (right - left <= 2)
		return;
	
	int i = left;
	int j = right-1;
	while(1)
	{
		while (array.at(++i) < pivot);
		while (array.at(--j) > pivot);
		
		if (i < j)
			swap(array.at(i), array.at(j));
		else
			break;
	}
	
	swap(array.at(i), array.at(right-1));//i处放主元 
	quickSort(array, left, i-1);
	quickSort(array, i+1, right);
}

void Quick_Sort(int fileNum)
{
	for (int i = 1; i <= fileNum; i++)
	{
		vector<int> array;//存放待排数据 
		
		//读入待排数据 
		fstream sampleFile(GetFilePath(i).data(), ios::in);
		while (!sampleFile.eof())
		{
			int tem;
			sampleFile >> tem;
			array.push_back(tem);
		}
		
		clock_t startTime = clock();//排序起始时间 
		
		quickSort(array, 0, array.size()-1);
		
		clock_t endTime = clock();//排序终止时间 
		
		if (i == 1)
			cout << "快速排序耗时统计（单位：ms）：" << endl; 		
		cout << "样本" << i << "：" << endTime - startTime << "ms" << endl;
				
		//将排序结果写入文件
		//设置文件名 
		char str[5];
		sprintf(str, "%d", i);
		string num(str);
		string fileName(::answerFolder + string("\\Quick_Sort_ans") + string(str) + string(".txt"));

		fstream ansFile(fileName, ios::out);
		if (!ansFile){
			cout << "打开文件" << fileName << "失败！" << endl;
			return; 
		}
		ansFile << "快速排序耗时统计（单位：ms）：" << endl;
		ansFile << "样本" << i << "：" << endTime - startTime << "ms" << endl;
		for (int i = 0; i < array.size(); i++)
			ansFile << array.at(i) << " ";
		ansFile.close();	
	}
}

void Selection_Sort(int fileNum)
{
	for (int i = 1; i <= fileNum; i++)
	{
		vector<int> array;//存放待排数据 
		
		//读入待排数据 
		fstream sampleFile(GetFilePath(i).data(), ios::in);
		while (!sampleFile.eof())
		{
			int tem;
			sampleFile >> tem;
			array.push_back(tem);
		}
		
		clock_t startTime = clock();//排序起始时间 
		
		for (int i = 1; i < array.size(); i++)
		{
			int max = INT_MIN;
			int max_j = 0;//最大元素下标 
			
			int j = 0;
			for (; j < array.size()-i; j++)
				if (array.at(j) > max)
				{
					max = array.at(j);//选出无序序列最大值 
					max_j = j;
				}
				
			swap(array.at(max_j), array.at(j));
			//将无序序列最大值与无序序列最后位置元素互换 
		}
		
		clock_t endTime = clock();//排序终止时间 
		
		if (i == 1) 
			cout << "选择排序耗时统计（单位：ms）：" << endl; 		
		cout << "样本" << i << "：" << endTime - startTime << "ms" << endl;
				
		//将排序结果写入文件
		//设置文件名 
		char str[5];
		sprintf(str, "%d", i);
		string num(str);
		string fileName(::answerFolder + string("\\Selection_Sort_ans") + string(str) + string(".txt"));

		fstream ansFile(fileName, ios::out);
		if (!ansFile){
			cout << "打开文件" << fileName << "失败！" << endl;
			return; 
		}
		ansFile << "选择排序耗时统计（单位：ms）：" << endl;
		ansFile << "样本" << i << "：" << endTime - startTime << "ms" << endl;
		for (int i = 0; i < array.size(); i++)
			ansFile << array.at(i) << " ";
		ansFile.close();	
	}
}

//root左子树和右子树均为堆，要把root调整为堆 
void Heap_Adjust(vector<int>& array, int root, int curSize)
{
	//root为要调整的结点
	//欲使pos指向左右子树较大者
	int pos = 2*root + 1;
	while (pos < curSize)//仍有子树，还需继续调整 
	{
		//选左右子树较大者 
		if (pos+1 < curSize && array.at(pos+1) > array.at(pos))
			pos = pos+1;
		
		if (array.at(root) >= array.at(pos))//此时已调整为堆 
			break;
		else
		{
			swap(array.at(root), array.at(pos));
			root = pos;//更新root 
			pos = 2*pos + 1;//更新pos 
		}
	}
	
}

void Heap_Sort(int fileNum)
{
	for (int i = 1; i <= fileNum; i++)
	{
		vector<int> array;//存放待排数据 
		
		//读入待排数据 
		fstream sampleFile(GetFilePath(i).data(), ios::in);
		while (!sampleFile.eof())
		{
			int tem;
			sampleFile >> tem;
			array.push_back(tem);
		}
		
		clock_t startTime = clock();//排序起始时间 
		
		//1.建堆 
		int root = (array.size() - 1)/2;//指向最后一个有子树的根 
		for (; root >= 0; root--)
		{
			Heap_Adjust(array, root, array.size());
		}
		
		//2.排序 
		for (int i = array.size()-1; i > 0; i--)
		{
			//每次循环将堆顶元素到无序序列末尾 
			swap(array.at(i), array[0]);
			Heap_Adjust(array, 0, i);
		}
		
		clock_t endTime = clock();//排序终止时间 
		
		if (i == 1) 
			cout << "堆排序耗时统计（单位：ms）：" << endl; 
		cout << "样本" << i << "：" << endTime - startTime << "ms" << endl;
				
		//将排序结果写入文件
		//设置文件名 
		char str[5];
		sprintf(str, "%d", i);
		string num(str);
		string fileName(::answerFolder + string("\\Heap_Sort_ans") + string(str) + string(".txt"));

		fstream ansFile(fileName, ios::out);
		if (!ansFile){
			cout << "打开文件" << fileName << "失败！" << endl;
			return; 
		}
		ansFile << "堆排序耗时统计（单位：ms）：" << endl;
		ansFile << "样本" << i << "：" << endTime - startTime << "s" << endl;
		for (int i = 0; i < array.size(); i++)
			ansFile << array.at(i) << " ";
		ansFile.close();	
	}
}

void Merge(vector<int>& array, int left, int right)
{
	if (left >= right)
		return;
	else
	{
		int center = (left+right)/2;
		Merge(array, left, center);//[left,center]已经为有序子列 
		Merge(array, center+1, right);//[center+1,right]已经为有序子列 
		
		//将上述两个有序子列合并为一个新的有序子列 
		vector<int> array2;
		int p1 = left, p2 = center+1;
		while ((p1 <= center) && (p2 <= right))
		{
			if (array.at(p1) <= array.at(p2))
				array2.push_back(array[p1++]);
			else
				array2.push_back(array[p2++]);
		}
		
		for (; p1 <= center; p1++)
			array2.push_back(array[p1]);
		for (; p2 <= right; p2++)
			array2.push_back(array[p2]);
		
		for (int i = 0; i < array2.size(); i++)
			array.at(left++) = array2[i];
	}
}

void Merge_Sort(int fileNum)
{
	for (int i = 1; i <= fileNum; i++)
	{
		vector<int> array;//存放待排数据 
		
		//读入待排数据 
		fstream sampleFile(GetFilePath(i).data(), ios::in);
		while (!sampleFile.eof())
		{
			int tem;
			sampleFile >> tem;
			array.push_back(tem);
		}
		
		clock_t startTime = clock();//排序起始时间 
		
		Merge(array, 0, array.size()-1);
		
		clock_t endTime = clock();//排序终止时间 
		
		if (i == 1) 
			cout << "归并排序耗时统计（单位：ms）：" << endl; 		
		cout << "样本" << i << "：" << endTime - startTime << "ms" << endl;
	
		//将排序结果写入文件
		//设置文件名 
		char str[5];
		sprintf(str, "%d", i);
		string num(str);
		string fileName(::answerFolder + string("\\Merge_Sort_ans") + string(str) + string(".txt"));

		fstream ansFile(fileName, ios::out);
		if (!ansFile){
			cout << "打开文件" << fileName << "失败！" << endl;
			return; 
		}
		ansFile << "归并排序耗时统计（单位：ms）：" << endl;
		ansFile << "样本" << i << "：" << endTime - startTime << "ms" << endl;
		for (int i = 0; i < array.size(); i++)
			ansFile << array.at(i) << " ";
		ansFile.close();	
	}
}
