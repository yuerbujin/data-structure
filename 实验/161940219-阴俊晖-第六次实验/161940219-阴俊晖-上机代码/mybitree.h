#ifndef _MYBITREE_H_
#define _MYBITREE_H_

#include <string>
using namespace std;

template<class T>
struct BiNode{
	T data;
	BiNode<T>* left;
	BiNode<T>* right;
	string codes;
}; 

//重载大于号以建立最小堆 
template<class T>
struct cmp{
	bool operator()(BiNode<T>* n1, BiNode<T>* n2)
	{
		return n1->data > n2->data;
	}
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
#include "mybitree.cpp"

#endif
