#include <iostream>
#include "binaryTree.h"

int main()
{
	BiTree<char> bt;
	
	cout << LeafNum(bt.GetRoot());
}

/*
input sample1:
A B D # G # # # C E # # F # #

output sample1:
3

input sample2:
A # #

output sample2:
1

input sample3:
A B D # # E # # C F # # G # # 

output sample3:
4

*/
