#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <iostream>
#include <fstream>
#include <queue>
#include <algorithm>
using namespace std;

typedef int ElemType;
typedef struct BiNode* Position;
typedef Position BiTree;

struct BiNode{
	ElemType data;//�ؼ��� 
	BiTree left;//������ 
	BiTree right;//������ 
	
	BiNode(ElemType dataIn);
};

class AVL_Tree{
	public:
		AVL_Tree();
		~AVL_Tree();//������ 
		
		bool Create(const string fileName);//���� 
		Position Find(ElemType data);//����ֵΪdata�Ľ�� 
		Position FindMax(BiTree root);//������rootΪ���������У����ֵ��� 
		Position FindMin(BiTree root);//������rootΪ���������У���Сֵ��� 
		
		Position Insert(BiTree root, ElemType data);//������ 
		Position Delete(BiTree root);//ɾ������ 
		Position Delete(BiTree root, ElemType data);//ɾ��ֵΪdata�Ľ�� 
		
		int height(BiTree root);//������rootΪ���������� 
		Position LL_rotation(BiTree root);
		Position LR_rotation(BiTree root);
		Position RL_rotation(BiTree root);
		Position RR_rotation(BiTree root);
		
		void print(BiTree root);//�����������ʽ������ 
		
//	private:
		BiTree root;//���� 
};

//ѡ���� 9.32 
void find_a_b(AVL_Tree& avl_tree, BiTree root, ElemType x, ElemType* a, ElemType* b); 

#endif
