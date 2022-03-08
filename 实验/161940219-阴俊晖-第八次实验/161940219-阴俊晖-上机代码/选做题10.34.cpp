#include <iostream>
#include <vector>
using namespace std;

void insert();
void print();

vector<int> arr;//默认大顶堆 
int main()
{
//	arr.push_back(INT_MAX);//0位置放哨兵 
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		insert();
	
	print();
}

void insert()
{
	int data;
	cin >> data;
	arr.push_back(data);
	
	int cur = arr.size()-1;//元素应当放入的位置 
	int pos = (cur-1)/2;//cur父结点位置 
	while (pos >= 0)
	{
		if (arr.at(pos) < data)
		{ 
			arr.at(cur) = arr.at(pos);//向下过滤 
			cur = pos;//更新cur 
			
			if (pos == 0)//此时已到根结点 
				break;
			else
				pos = (pos-1)/2;//更新pos 
		} 
		else
			break;
	}
	
	arr.at(cur) = data;//元素落位 
}

void print()
{
	for (int i = 0; i < arr.size(); i++)
		cout << arr.at(i) << " ";
}

/*
input sample1:
8
48 35 22 91 74 48 18 66

output sample1:
91 74 48 66 48 22 18 35

input sample2:
13
5 36 1 -4 0 0 0 8 -4 -31 0 -17 5 

output sample2:
36 8 5 5 0 1 0 -4 -4 -31 0 -17 0

input sample3:
1
12 

output sample3:
12 

*/
