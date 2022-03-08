#include <iostream>
#include "binaryTree.h"

int main()
{
	BiTree<char> bt;
	BiNode<char>* root = bt.GetRoot();
	
	//1.求树高 
	cout << bt.Depth(root) << endl << endl ; 
	
	//2.将根结点设为R 
	SetValue(root, 'R');
	bt.LevelOrder();
	cout << endl << endl ;
	
	//3.将E的父结点设为R 
	SetValue(Parent(bt, root->right->left), 'R');
	bt.LevelOrder();
	cout << endl << endl ;
	
	//4.将根结点的左孩子设为R 
	SetValue(LeftChild(bt, root), 'R');
	bt.LevelOrder();
	cout << endl << endl ;
	
	//5.删除根结点的左子树 
	Delete(root->left);
	bt.LevelOrder();
	cout << endl << endl ;
	
	//6.销毁二叉树 
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
