#include <iostream>
#include "mybitree.h"

int main()
{
	BiNode<int>* root = NULL;
	
	root = CreateHuffmanTree(root);
	Encode(root);
}

/*
input sample1:
4
2 4 7 9

output sample1:
9: 0
7: 11
2: 100
4: 101

input sample2:
5
10 15 12 3 4

output sample2:
10: 01
15: 10
12: 11
3: 000
4: 001

*/
