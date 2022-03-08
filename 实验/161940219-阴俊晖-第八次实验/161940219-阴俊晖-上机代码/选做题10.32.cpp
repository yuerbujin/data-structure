#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> array;
int main()
{
	int data;
	while (1)
	{
		cin >> data;
		if (data != 0)
			array.push_back(data);
		else
			break;
	}
	
	int p1 = 0;//指向1序列末尾后一位 
	int p2 = 0;//指向2序列末尾后一位 
	int p3 = array.size()-1;//指向3序列开头前一位 
	
	for (; p2 <= p3; )
		switch (array.at(p2))
		{
			case 1:
				swap(array.at(p2), array.at(p1));
				p1++;
				p2++;
				break;
			case 2:
				p2++;
				break;
			case 3:
				swap(array.at(p2), array.at(p3));
				p3--;
				break;
		}
	
	for (int i = 0; i < array.size(); i++)
		cout << array.at(i) << " ";
}

/*
input sample1:
2 3 3 2 1 2 1 3 1 1 3 0

output sample1:
1 1 1 1 2 2 2 3 3 3 3

input sample2:
3 1 0

output sample2:
1 3

input sample3:
0

output sample3:
（NULL） 

*/
