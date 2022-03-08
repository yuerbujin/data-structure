#include <stdio.h>
#include "mymatrix.h"

int main()
{
	Matrix ma = Input();
	
	SpMatrix sma1 = InitSpMa(ma);
	
	PrintSpMa(sma1);
	
	SpMatrix sma2 = ColTrans(sma1);
	
	PrintSpMa(sma2);
	
	SpMatrix sma3 = FastTrans(sma2);
	
	PrintSpMa(sma3);
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

output sample1:
8	0	0	0	0	0	0
0	0	4	0	0	0	0
8	0	0	0	0	-1	0
-5	0	0	0	0	-1	0

*/
