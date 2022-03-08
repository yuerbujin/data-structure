#include <stdio.h>
#include "mymatrix.h"

int main()
{
	Matrix ma = Input();
	
	SaddlePoint(ma);
}

/*
input sample1:
3 5
5 72 -11 18 9
1 0 -12 91 42
3 -82 -19 32 0 

output sample1:
saddle point: -11 row: 0 col: 2

input sample2:
2 4
5 -11 42 2
0 9 31 -4

output sample2:
There is no saddle point in this matrix.

*/
