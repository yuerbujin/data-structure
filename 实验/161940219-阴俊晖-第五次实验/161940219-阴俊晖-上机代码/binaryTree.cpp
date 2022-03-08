#ifdef TEMP

#include <iostream>
#include <queue>
#include <stack>
#include <stdlib.h>

using namespace std;

//1.建立二叉树 
template<class T>
BiTree<T>::BiTree()
{
	CreateBT(root);
}

template<class T>
void CreateBT(BiNode<T>*& root)
{
	T c;
	cin >> c ;
	if (c == '#')
		root = NULL;
	else
	{
		root = (BiNode<T>*)malloc(sizeof(BiNode<T>));
		root->data = c;
		CreateBT(root->left);
		CreateBT(root->right);
	}
}

//2.销毁二叉树
template<class T>
BiTree<T>::~BiTree()
{
	Delete(root);
}

//3.前序遍历
template<class T>
void BiTree<T>::PreOrder(BiNode<T>* root)
{
	if (root != NULL){
		cout << root->data << ' ' ;
		BiTree<T>::PreOrder(root->left);
		BiTree<T>::PreOrder(root->right);
	}
}

//4.中序遍历
template<class T>
void BiTree<T>::InOrder(BiNode<T>* root)
{
	if (root != NULL){
		BiTree<T>::InOrder(root->left);
		cout << root->data << ' ' ;
		BiTree<T>::InOrder(root->right);
	}
}

//5.后序遍历
template<class T>
void BiTree<T>::PostOrder(BiNode<T>* root)
{
	if (root != NULL){
		BiTree<T>::PostOrder(root->left);
		BiTree<T>::PostOrder(root->right);
		cout << root->data << ' ' ;
	}
}

//6.层序遍历
template<class T>
void BiTree<T>::LevelOrder()
{
	queue<BiNode<T>*> queue;
	BiNode<T>* p = root;
	if (p != NULL)
	{
		queue.push(p);
		while (!queue.empty())
		{
			p = queue.front();
			queue.pop();
			cout << p->data << ' ' ;
			if (p->left != NULL)
				queue.push(p->left);
			if (p->right != NULL)
				queue.push(p->right);
		}
	}
}

//7.先序遍历（非递归） 
template<class T>
void PreOrderNonRec(BiTree<T>& bt)
{
	stack<BiNode<T>*> stack;
	BiNode<T>* p = bt.GetRoot();
	
	while (1)
	{
		if (p != NULL){
			cout << p->data << ' ' ;
			stack.push(p);
			p = p->left;
		}
		else{
			if (!stack.empty()){
				p = stack.top()->right;
				stack.pop();
			}
			else
				break;
		}
	}
}

//8.中序遍历（非递归） 
template<class T>
void InOrderNonRec(BiTree<T>& bt)
{
	stack<BiNode<T>*> stack;
	BiNode<T>* p = bt.GetRoot();
	
	while (1)
	{	
		if (p != NULL){
			stack.push(p);
			p = p->left;
		}
		else{
			if (!stack.empty()){
				p = stack.top();
				cout << p->data << ' ' ;
				stack.pop();
				p = p->right;
			}
			else
				break;
		}
	}
}

//9.后序遍历（非递归） 
template<class T>
void PostOrderNonRec(BiTree<T>& bt)
{
	stack<BiNode<T>*> stack;
	BiNode<T>* p = bt.GetRoot();
	BiNode<T>* prev = NULL;
	
	while (1)
	{	
		if (p != NULL){
			stack.push(p);
			p = p->left;
		}
		else
		{
			if (!stack.empty()){
				p = stack.top();
				
				if ((p->right != NULL) && (p->right != prev)){
					p = p->right;
				}
				else{
					cout << p->data << ' ' ;
					stack.pop();
					prev = p;
					p = NULL;
				}
			}
			else
				break;
		}
	}
}

//10.判断树空 
template<class T>
bool IsEmpty(BiTree<T>& bt)
{
	return (bt.root == NULL);
}

//11.求树高
template<class T>
int BiTree<T>::Depth(BiNode<T>* root)
{
	if (root == NULL)
		return 0;
	else
	{
		int leftDepth = Depth(root->left);
		int rightDepth = Depth(root->right);
		return max(leftDepth, rightDepth) + 1;
	}
}

//12.返回树根
template<class T>
BiNode<T>* BiTree<T>::GetRoot()
{
	return this->root;
}

//13.返回结点数据 
template<class T>
T Value(BiNode<T>* p)
{
	return p->data;
}

//14.设置结点数据 
template<class T>
void SetValue(BiNode<T>* p, T data)
{
	p->data = data;
}

//15.返回父结点指针（基于层序遍历） 
template<class T>
BiNode<T>* Parent(BiTree<T>& bt, BiNode<T>* child)
{
	queue<BiNode<T>*> queue;
	BiNode<T>* p = bt.GetRoot();
	if (p != NULL)
	{
		queue.push(p);
		while (!queue.empty())
		{
			p = queue.front();
			queue.pop();
			
			if ((p->left == child) || (p->right == child))
				return p; //访问操作 
						  //找到则返回 
			
			if (p->left != NULL)
				queue.push(p->left);
			if (p->right != NULL)
				queue.push(p->right);
		}
	}
}

//16.返回左孩子指针 
template<class T>
BiNode<T>* LeftChild(BiTree<T>& bt, BiNode<T>* parent)
{
	if (parent != NULL)
		return parent->left;
}

//17.返回右孩子指针 
template<class T>
BiNode<T>* RightChild(BiTree<T>& bt, BiNode<T>* parent)
{
	if (parent != NULL)
		return parent->right;
}

//18.返回左兄弟指针 
template<class T>
BiNode<T>* LeftBrother(BiTree<T>& bt, BiNode<T>* self)
{
	BiNode<T>* p = Parent(bt, self);
	if (p != NULL)
		return p->left;
}

//19.返回右兄弟指针 
template<class T>
BiNode<T>* RightBrother(BiTree<T>& bt, BiNode<T>* self)
{
	BiNode<T>* p = Parent(bt, self);
	if (p != NULL)
		return p->right;
}

//20.插入子树
template<class T>
void InsertChild(BiNode<T>*& pos, BiNode<T>* child)
{
	pos = child;
}

//21.删除子树
template<class T>
void Delete(BiNode<T>*& p)
{
	if (p != NULL){
		Delete(p->left);
		Delete(p->right);
		BiNode<T>* tem = (BiNode<T>*)p;
		p = NULL;
		free(tem);
	}
}

//22.删除以元素值为x的结点为根的子树（基于层序遍历） 
template<class T>
void DeleteX(BiTree<T>& bt, T x)
{
	queue<BiNode<T>*> queue;
	BiNode<T>* p = bt.GetRoot();
	if (p != NULL)
	{
		queue.push(p);
		while (!queue.empty())
		{
			p = queue.front();
			queue.pop();
			
			if (p->left != NULL){
				if (p->left->data == x){
					Delete(p->left);
					p->left = NULL;
				}
				else
					queue.push(p->left);
			}
			if (p->right != NULL){
				if (p->right->data == x){
					Delete(p->right);
					p->right = NULL;
				}
				else
					queue.push(p->right);
			}
		}
	}
}

//23.判断其是否为完全二叉树（基于层序遍历） 
template<class T>
bool IsCompleteBT(BiTree<T>& bt)
{
	bool flag = false;
	
	queue<BiNode<T>*> queue;
	BiNode<T>* p = bt.GetRoot();
	
	if (p == NULL)
		return true;
	else
	{
		queue.push(p);
		while (!queue.empty())
		{
			p = queue.front();
			queue.pop();
			
			if (p == NULL)
			{
				flag = true;
			}
			else
			{
				if (flag == true)//表明空指针后还有非空指针 
					return false;
				
				queue.push(p->left);
				queue.push(p->right);
			}
		}
	}
	
	return flag;
}

//24.求叶结点个数
template<class T>
int LeafNum(BiTree<T>& bt)
{
	return LeafNum(bt.GetRoot());
}

//24.求叶结点个数
template<class T>
int LeafNum(BiNode<T>* root)
{
	if (root == NULL)
		return 0;
	else if ((root->left == NULL) && (root->right == NULL))
		return 1;
	else
		return LeafNum(root->left) + LeafNum(root->right);
}

#endif
