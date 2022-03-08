#include <stdio.h>
#include "mymatrix.h"

int main()
{
	Matrix ma = Input();
	
	SetColor(ma);
	
	PrintMa(ma);
}

/*
input sample1:
7 4 
8 0 8 -5
0 0 0 0
0 4 0 0
0 0 0 0
0 0 0 0
0 0 -1 -1
0 0 0 0
2 3
7

output sample1:
8       7       8       -5
7       7       7       7
7       4       7       7
7       7       7       7
7       7       7       7
7       7       -1      -1
7       7       7       7

input sample2:
4 4
2 5 2 5
5 2 5 2
2 5 2 5
5 2 5 2
2 1
9

output sample2:
2       5       2       5
5       2       5       2
2       9       2       5
5       2       5       2

*/
