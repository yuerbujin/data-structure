#include <stdio.h>

int n, k, t, xl, yd, xr, yu; 
int n1 = 0;
int n2 = 0;
void Input();

int main()
{
	scanf("%d%d%d%d%d%d%d", &n, &k, &t, &xl, &yd, &xr, &yu);
	
	for (int i = 1; i <= n; i++)
		Input();

	printf("%d\n%d", n1, n2);
}

bool In( int x, int y )
{
	if (xl <= x && x <= xr && yd <= y && y <= yu )
		return true;
	else
		return false;
}

void Input()
{
	int x, y;
	bool stay1 = false;//记录是否有点经过 
	int count2 = 0;//记录连续位于高位区域内点的个数
	bool stay2 = false;//记录是否有点逗留 
	
	for (int i = 1; i <= t; i++)
	{
		scanf("%d%d", &x, &y);
		if (In(x, y)){
			stay1 = true;
			count2++;
				
			if (count2 >= k)
				stay2 = true;
		}
		else
			count2 = 0;
	}
	
	if (stay1)
		n1++;
		
	if (stay2)
		n2++;
}

/*
input sample1:
5 2 6 20 40 100 80
100 80 100 80 100 80 100 80 100 80 100 80
60 50 60 46 60 42 60 38 60 34 60 30
10 60 14 62 18 66 22 74 26 86 30 100
90 31 94 35 98 39 102 43 106 47 110 51
0 20 4 20 8 20 12 20 16 20 20 20

output sample1:
3
2

input sample2:
1 3 8 0 0 10 10
-1 -1 0 0 0 0 -1 -1 0 0 -1 -1 0 0 0 0

output sample2:
1
0
*/
