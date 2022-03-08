#include <iostream>
#include "binaryTree.h"

int main()
{
	BiTree<char> bt;
	
	cout << "PreOrder:" << endl ;
	bt.PreOrder(bt.GetRoot());
	cout << endl << endl ;
	cout << "PreOrderNonRec:" << endl ;
	PreOrderNonRec(bt);
	cout << endl << endl ;
	
	cout << "InOrder:" << endl ;
	bt.InOrder(bt.GetRoot());
	cout << endl << endl ;
	cout << "InOrderNonRec:" << endl ;
	InOrderNonRec(bt);
	cout << endl << endl ;
	
	cout << "PostOrder:" << endl ;
	bt.PostOrder(bt.GetRoot());
	cout << endl << endl ;
	cout << "PostOrderNonRec:" << endl ;
	PostOrderNonRec(bt);
	cout << endl << endl ;
	
	cout << "LevelOrder:" << endl ;
	bt.LevelOrder();
	cout << endl << endl ;
}

/*
input sample1:
A B D # G # # # C E # # F # #

output sample1:

input sample2:
1 2 4 # 7 # # # 3 5 # # 6 # #

output sample2:

*/
