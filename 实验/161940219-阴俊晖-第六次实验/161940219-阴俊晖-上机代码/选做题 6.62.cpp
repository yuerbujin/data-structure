#include <iostream>
#include "mybitree.h"

int main()
{
	BiTree<char> bt;
	
	cout << Depth(bt);
}

/*
input sample1:
A B # C D # # E # # #

output sample1:
3

input sample2:
G H # I # # #

output sample2:
2 

*/
