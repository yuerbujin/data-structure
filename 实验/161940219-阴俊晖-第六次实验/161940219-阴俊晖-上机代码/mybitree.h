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

//���ش��ں��Խ�����С�� 
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
#include "mybitree.cpp"

#endif
