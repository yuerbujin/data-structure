#include <iostream>
#include <stdio.h>
#include <string.h>
#define MAX 3

using namespace std;

bool Skip(int i);

int N;
int main()
{
	int A, B, C, D;//¼×¡¢ÒÒ¡¢±û¡¢¶¡ 
	A = B = C = D = 0;
	cin >> N;
	
	for (int i = 1; N != 0; i++) 
	{
		if (Skip(i)){
			switch (i % 4)
			{
				case 1:
					A++;
					break;
				case 2:
					B++;
					break;
				case 3:
					C++;
					break;
				case 0:
					D++;
					break;
			}
		}
		else{
			N-- ;
		}
	}
	
	cout << A << endl
		 << B << endl
		 << C << endl
		 << D ;
}

bool Skip(int i)//ÅÐ¶ÏÊÇ·ñÒªÌø¹ý 
{
	char s[MAX];
	sprintf(s, "%d", i );
	
	if (i % 7 == 0)
		return true;
	else{
		for (int j = 0; j < strlen(s); j++)
			if (s[j] == '7')
				return true;
	}
	
	return false;
}

/*
input sample1:
20

output sample1:
2
1
1
0 

input sample2:
66 

output sample1:
7
5
11
5
*/
