#include <iostream>
#include "mybiTree.h"

int main()
{
	BiTree<char> bt;
	
	int x;
	cin >> x ;
	
	OutputLevelX(bt, x);
}

/*
input sample1:
A B # C D # # E # # #
2

output sample1:
B C E

input sample2:
A B # C D # # E # # #
3

output sample2:
D

*/
