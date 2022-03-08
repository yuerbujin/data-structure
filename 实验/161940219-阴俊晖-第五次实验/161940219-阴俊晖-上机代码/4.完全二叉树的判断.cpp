#include <iostream>
#include "binaryTree.h"

int main()
{
	BiTree<char> bt;

	cout << IsCompleteBT(bt) << endl ;
}

/*
input sample1:
A B D # G # # # C E # # F # #

output sample1:
0

input sample2:
A # #

output sample2:
1

input sample3:
A B D # # E # # C F # # #

output sample3:
1

*/
