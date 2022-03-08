#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int N, M;
int sum = 0;//为最大回报 
int main()
{
	//思路：1.最大正数对应相乘，最小负数对应相乘
	//		2.正负数不交叉相乘
	 
	cin >> N;
	vector<int> a1; //正数优惠券 
	vector<int> a2; //负数优惠券 
	int tem;
	for (int i = 1; i <= N; i++)
	{
		cin >> tem;
		if (tem > 0)
			a1.push_back(tem);
		else
			a2.push_back(tem);
	}
	
	cin >> M;
	vector<int> b1; //正数商品 
	vector<int> b2; //负数商品 
	for (int i = 1; i <= M; i++)
	{
		cin >> tem;
		if (tem > 0)
			b1.push_back(tem);
		else
			b2.push_back(tem);
	}
	
	//正数降序
	sort(a1.begin(), a1.end(), greater<int>());
	sort(b1.begin(), b1.end(), greater<int>());
	//负数升序 
	sort(a2.begin(), a2.end(), less<int>());
	sort(b2.begin(), b2.end(), less<int>());
	
	//对应相乘再累加 
	for (int i = 0; (i < a1.size()) && (i < b1.size()); i++)
		sum += a1[i]*b1[i];
	for (int i = 0; (i < a2.size()) && (i < b2.size()); i++)
		sum += a2[i]*b2[i];
	
	cout << sum;
}

/*
input sample1:
4 1 2 4 -1
4 7 6 -2 -3

output sample1:
43 

input sample2:
4 3 2 6 1 
3 2 6 3

output sample2:
49 

input sample3:
7 3 36 -1 73 2 3 6
6 -1 -1 -1 -1 -1 -1

output sample3:
1
 
*/
