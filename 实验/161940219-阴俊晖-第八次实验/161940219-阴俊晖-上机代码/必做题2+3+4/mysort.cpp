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
	//�������ļ��в����ڣ��򴴽�
	//ע�����ļ��в����ڣ�access()��������-1 
	if (access(sampleFolder.data(), F_OK)){	
		string cmd(string("md ") + sampleFolder);
		system(cmd.data());
	}
	
	for (int i = 1; i <= fileNum; i++)
	{
		//���ļ� 
		fstream testFile(GetFilePath(i).data(), ios::out);
		
		vector<int> array;
		if (i <= 2)
		{
			for (int j = 1; j <= dataNum; j++)
				array.push_back(rand());
			
			if (i == 1)
				sort(array.begin(), array.end());//ʹ��һ������Ϊ����
			else if (i == 2)
				sort(array.begin(), array.end(), greater<int>());//ʹ�ڶ�������Ϊ����
			
			for (int i = 0; i < array.size(); i++)
				testFile << array.at(i) << " ";
		}
		else
		{
			//�������д���ļ� 
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
		vector<int> array;//��Ŵ������� 
		
		//����������� 
		fstream sampleFile(GetFilePath(i).data(), ios::in);
		while (!sampleFile.eof())
		{
			int tem;
			sampleFile >> tem;
			array.push_back(tem);
		}
		
		clock_t startTime = clock();//������ʼʱ�� 
		
		for (int i = 1; i < array.size(); i++)
		{
			int tem = array[i];//��һ���� 
			for (; (i > 0) && (tem < array[i-1]); i--)
				array[i] = array[i-1];//��λ 
			array[i] = tem;//������λ 
		}
		
		clock_t endTime = clock();//������ֹʱ�� 
		
		if (i == 1)
			cout << "���������ʱͳ�ƣ���λ��ms����" << endl; 		
		cout << "����" << i << "��" << endTime - startTime << "ms" << endl;
				
		//��������д���ļ�
		//�����ļ��� 
		char str[5];
		sprintf(str, "%d", i);
		string num(str);
		string fileName(::answerFolder + string("\\Insertion_Sort_ans") + string(str) + string(".txt"));

		fstream ansFile(fileName, ios::out);
		if (!ansFile){
			cout << "���ļ�" << fileName << "ʧ�ܣ�" << endl;
			return; 
		}
		ansFile << "���������ʱͳ�ƣ���λ��ms����" << endl;
		ansFile << "����" << i << "��" << endTime - startTime << "ms" << endl;
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
		vector<int> array;//��Ŵ������� 
		
		//����������� 
		fstream sampleFile(GetFilePath(i).data(), ios::in);
		while (!sampleFile.eof())
		{
			int tem;
			sampleFile >> tem;
			array.push_back(tem);
		}
		
		clock_t startTime = clock();//������ʼʱ�� 
		
		for (int i = 1; i < array.size(); i++)
			for (int j = 0; j < array.size()-i; j++)
				if (array.at(j) > array.at(j+1))
					swap(array.at(j), array.at(j+1));
		
		clock_t endTime = clock();//������ֹʱ�� 
		
		if (i == 1)
			cout << "ð�������ʱͳ�ƣ���λ��ms����" << endl; 		
		cout << "����" << i << "��" << endTime - startTime << "ms" << endl;
				
		//��������д���ļ�
		//�����ļ��� 
		char str[5];
		sprintf(str, "%d", i);
		string num(str);
		string fileName(::answerFolder + string("\\Bubble_Sort_ans") + string(str) + string(".txt"));

		fstream ansFile(fileName, ios::out);
		if (!ansFile){
			cout << "���ļ�" << fileName << "ʧ�ܣ�" << endl;
			return; 
		}
		ansFile << "ð�������ʱͳ�ƣ���λ��ms����" << endl;
		ansFile << "����" << i << "��" << endTime - startTime << "ms" << endl;
		for (int i = 0; i < array.size(); i++)
			ansFile << array.at(i) << " ";
		ansFile.close();	
	}	
}

int Median3(vector<int>& array, int left, int right)
{
	//1.ѡ����Ԫ
	//2.left����С��right�����right-1����Ԫ
	
	int center = (right+left)/2;
	if (array.at(left) > array.at(center))
		swap(array.at(left), array.at(center)); 
	if (array.at(center) > array.at(right))
		swap(array.at(center), array.at(right));
	if (array.at(left) > array.at(center))
		swap(array.at(left), array.at(center));
	
	int pivot = array.at(center);//ѡ����Ԫ
	swap(array.at(center), array.at(right-1));//right-1����Ԫ
	return pivot;
}

void quickSort(vector<int>& array, int left, int right)
{
	if (left >= right)
		return;
	int pivot = Median3(array, left, right);//ѡ����Ԫ 
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
	
	swap(array.at(i), array.at(right-1));//i������Ԫ 
	quickSort(array, left, i-1);
	quickSort(array, i+1, right);
}

void Quick_Sort(int fileNum)
{
	for (int i = 1; i <= fileNum; i++)
	{
		vector<int> array;//��Ŵ������� 
		
		//����������� 
		fstream sampleFile(GetFilePath(i).data(), ios::in);
		while (!sampleFile.eof())
		{
			int tem;
			sampleFile >> tem;
			array.push_back(tem);
		}
		
		clock_t startTime = clock();//������ʼʱ�� 
		
		quickSort(array, 0, array.size()-1);
		
		clock_t endTime = clock();//������ֹʱ�� 
		
		if (i == 1)
			cout << "���������ʱͳ�ƣ���λ��ms����" << endl; 		
		cout << "����" << i << "��" << endTime - startTime << "ms" << endl;
				
		//��������д���ļ�
		//�����ļ��� 
		char str[5];
		sprintf(str, "%d", i);
		string num(str);
		string fileName(::answerFolder + string("\\Quick_Sort_ans") + string(str) + string(".txt"));

		fstream ansFile(fileName, ios::out);
		if (!ansFile){
			cout << "���ļ�" << fileName << "ʧ�ܣ�" << endl;
			return; 
		}
		ansFile << "���������ʱͳ�ƣ���λ��ms����" << endl;
		ansFile << "����" << i << "��" << endTime - startTime << "ms" << endl;
		for (int i = 0; i < array.size(); i++)
			ansFile << array.at(i) << " ";
		ansFile.close();	
	}
}

void Selection_Sort(int fileNum)
{
	for (int i = 1; i <= fileNum; i++)
	{
		vector<int> array;//��Ŵ������� 
		
		//����������� 
		fstream sampleFile(GetFilePath(i).data(), ios::in);
		while (!sampleFile.eof())
		{
			int tem;
			sampleFile >> tem;
			array.push_back(tem);
		}
		
		clock_t startTime = clock();//������ʼʱ�� 
		
		for (int i = 1; i < array.size(); i++)
		{
			int max = INT_MIN;
			int max_j = 0;//���Ԫ���±� 
			
			int j = 0;
			for (; j < array.size()-i; j++)
				if (array.at(j) > max)
				{
					max = array.at(j);//ѡ�������������ֵ 
					max_j = j;
				}
				
			swap(array.at(max_j), array.at(j));
			//�������������ֵ�������������λ��Ԫ�ػ��� 
		}
		
		clock_t endTime = clock();//������ֹʱ�� 
		
		if (i == 1) 
			cout << "ѡ�������ʱͳ�ƣ���λ��ms����" << endl; 		
		cout << "����" << i << "��" << endTime - startTime << "ms" << endl;
				
		//��������д���ļ�
		//�����ļ��� 
		char str[5];
		sprintf(str, "%d", i);
		string num(str);
		string fileName(::answerFolder + string("\\Selection_Sort_ans") + string(str) + string(".txt"));

		fstream ansFile(fileName, ios::out);
		if (!ansFile){
			cout << "���ļ�" << fileName << "ʧ�ܣ�" << endl;
			return; 
		}
		ansFile << "ѡ�������ʱͳ�ƣ���λ��ms����" << endl;
		ansFile << "����" << i << "��" << endTime - startTime << "ms" << endl;
		for (int i = 0; i < array.size(); i++)
			ansFile << array.at(i) << " ";
		ansFile.close();	
	}
}

//root����������������Ϊ�ѣ�Ҫ��root����Ϊ�� 
void Heap_Adjust(vector<int>& array, int root, int curSize)
{
	//rootΪҪ�����Ľ��
	//��ʹposָ�����������ϴ���
	int pos = 2*root + 1;
	while (pos < curSize)//��������������������� 
	{
		//ѡ���������ϴ��� 
		if (pos+1 < curSize && array.at(pos+1) > array.at(pos))
			pos = pos+1;
		
		if (array.at(root) >= array.at(pos))//��ʱ�ѵ���Ϊ�� 
			break;
		else
		{
			swap(array.at(root), array.at(pos));
			root = pos;//����root 
			pos = 2*pos + 1;//����pos 
		}
	}
	
}

void Heap_Sort(int fileNum)
{
	for (int i = 1; i <= fileNum; i++)
	{
		vector<int> array;//��Ŵ������� 
		
		//����������� 
		fstream sampleFile(GetFilePath(i).data(), ios::in);
		while (!sampleFile.eof())
		{
			int tem;
			sampleFile >> tem;
			array.push_back(tem);
		}
		
		clock_t startTime = clock();//������ʼʱ�� 
		
		//1.���� 
		int root = (array.size() - 1)/2;//ָ�����һ���������ĸ� 
		for (; root >= 0; root--)
		{
			Heap_Adjust(array, root, array.size());
		}
		
		//2.���� 
		for (int i = array.size()-1; i > 0; i--)
		{
			//ÿ��ѭ�����Ѷ�Ԫ�ص���������ĩβ 
			swap(array.at(i), array[0]);
			Heap_Adjust(array, 0, i);
		}
		
		clock_t endTime = clock();//������ֹʱ�� 
		
		if (i == 1) 
			cout << "�������ʱͳ�ƣ���λ��ms����" << endl; 
		cout << "����" << i << "��" << endTime - startTime << "ms" << endl;
				
		//��������д���ļ�
		//�����ļ��� 
		char str[5];
		sprintf(str, "%d", i);
		string num(str);
		string fileName(::answerFolder + string("\\Heap_Sort_ans") + string(str) + string(".txt"));

		fstream ansFile(fileName, ios::out);
		if (!ansFile){
			cout << "���ļ�" << fileName << "ʧ�ܣ�" << endl;
			return; 
		}
		ansFile << "�������ʱͳ�ƣ���λ��ms����" << endl;
		ansFile << "����" << i << "��" << endTime - startTime << "s" << endl;
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
		Merge(array, left, center);//[left,center]�Ѿ�Ϊ�������� 
		Merge(array, center+1, right);//[center+1,right]�Ѿ�Ϊ�������� 
		
		//�����������������кϲ�Ϊһ���µ��������� 
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
		vector<int> array;//��Ŵ������� 
		
		//����������� 
		fstream sampleFile(GetFilePath(i).data(), ios::in);
		while (!sampleFile.eof())
		{
			int tem;
			sampleFile >> tem;
			array.push_back(tem);
		}
		
		clock_t startTime = clock();//������ʼʱ�� 
		
		Merge(array, 0, array.size()-1);
		
		clock_t endTime = clock();//������ֹʱ�� 
		
		if (i == 1) 
			cout << "�鲢�����ʱͳ�ƣ���λ��ms����" << endl; 		
		cout << "����" << i << "��" << endTime - startTime << "ms" << endl;
	
		//��������д���ļ�
		//�����ļ��� 
		char str[5];
		sprintf(str, "%d", i);
		string num(str);
		string fileName(::answerFolder + string("\\Merge_Sort_ans") + string(str) + string(".txt"));

		fstream ansFile(fileName, ios::out);
		if (!ansFile){
			cout << "���ļ�" << fileName << "ʧ�ܣ�" << endl;
			return; 
		}
		ansFile << "�鲢�����ʱͳ�ƣ���λ��ms����" << endl;
		ansFile << "����" << i << "��" << endTime - startTime << "ms" << endl;
		for (int i = 0; i < array.size(); i++)
			ansFile << array.at(i) << " ";
		ansFile.close();	
	}
}
