#include <iostream>
#include "binaryTree.h"

int main()
{
	BiTree<char> bt;
	BiNode<char>* root = bt.GetRoot();
	
	//1.������ 
	cout << bt.Depth(root) << endl << endl ; 
	
	//2.���������ΪR 
	SetValue(root, 'R');
	bt.LevelOrder();
	cout << endl << endl ;
	
	//3.��E�ĸ������ΪR 
	SetValue(Parent(bt, root->right->left), 'R');
	bt.LevelOrder();
	cout << endl << endl ;
	
	//4.��������������ΪR 
	SetValue(LeftChild(bt, root), 'R');
	bt.LevelOrder();
	cout << endl << endl ;
	
	//5.ɾ�������������� 
	Delete(root->left);
	bt.LevelOrder();
	cout << endl << endl ;
	
	//6.���ٶ����� 
	bt.~BiTree();
	bt.LevelOrder();
	cout << endl << endl ;
}

/*
input sample1:
A B D # G # # # C E # # F # #

output sample1:


input sample2:
1 2 3 # 4 # # # 5 6 # # 7 # #

output sample2:

*/
