#ifndef _MYBITREE_H_
#define _MYBITREE_H_

template<class T>
struct BiNode{
	T data;
	BiNode<T>* left;
	BiNode<T>* right;
}; 

template<class T>
class BiTree{
	public:
		BiTree();//建立二叉树
		~BiTree();//销毁二叉树
		
		void PreOrder(BiNode<T>* root);//前序遍历 
		void InOrder(BiNode<T>* root);//中序遍历 
		void PostOrder(BiNode<T>* root);//后序遍历 
		void LevelOrder();//层序遍历 
		
		BiNode<T>* GetRoot();
		int Depth(BiNode<T>* root);
		
	private:
		BiNode<T>* root;
};

#define TEMP
#include "binaryTree.cpp"

#endif
