#include <iostream>
#include "binaryTree.h"

int main()
{
	BiTree<char> bt;
	cout << "LevelOrder:" << endl ;
	bt.LevelOrder();
	cout << endl << endl ;
	
	DeleteX(bt, 'D');
	DeleteX(bt, 'E');
	
	cout << "LevelOrder:" << endl ;
	bt.LevelOrder();
	cout << endl << endl ;
}

/*
input sample1:
A B D # G # # # C E # # F # #

output sample1:
A B C F
*/
