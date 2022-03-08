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
		BiTree();//����������
		~BiTree();//���ٶ�����
		
		void PreOrder(BiNode<T>* root);//ǰ����� 
		void InOrder(BiNode<T>* root);//������� 
		void PostOrder(BiNode<T>* root);//������� 
		void LevelOrder();//������� 
		
		BiNode<T>* GetRoot();
		int Depth(BiNode<T>* root);
		
	private:
		BiNode<T>* root;
};

#define TEMP
#include "binaryTree.cpp"

#endif
