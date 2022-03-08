#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int N, M;
int sum = 0;//Ϊ���ر� 
int main()
{
	//˼·��1.���������Ӧ��ˣ���С������Ӧ���
	//		2.���������������
	 
	cin >> N;
	vector<int> a1; //�����Ż�ȯ 
	vector<int> a2; //�����Ż�ȯ 
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
	vector<int> b1; //������Ʒ 
	vector<int> b2; //������Ʒ 
	for (int i = 1; i <= M; i++)
	{
		cin >> tem;
		if (tem > 0)
			b1.push_back(tem);
		else
			b2.push_back(tem);
	}
	
	//��������
	sort(a1.begin(), a1.end(), greater<int>());
	sort(b1.begin(), b1.end(), greater<int>());
	//�������� 
	sort(a2.begin(), a2.end(), less<int>());
	sort(b2.begin(), b2.end(), less<int>());
	
	//��Ӧ������ۼ� 
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
