#ifdef TEMP

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <stdlib.h>
#include <string.h>

using namespace std;

//1.���������� 
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

//2.���ٶ�����
template<class T>
BiTree<T>::~BiTree()
{
	Delete(root);
}

//3.ǰ�����
template<class T>
void BiTree<T>::PreOrder(BiNode<T>* root)
{
	if (root != NULL){
		cout << root->data << ' ' ;
		BiTree<T>::PreOrder(root->left);
		BiTree<T>::PreOrder(root->right);
	}
}

//4.�������
template<class T>
void BiTree<T>::InOrder(BiNode<T>* root)
{
	if (root != NULL){
		BiTree<T>::InOrder(root->left);
		cout << root->data << ' ' ;
		BiTree<T>::InOrder(root->right);
	}
}

//5.�������
template<class T>
void BiTree<T>::PostOrder(BiNode<T>* root)
{
	if (root != NULL){
		BiTree<T>::PostOrder(root->left);
		BiTree<T>::PostOrder(root->right);
		cout << root->data << ' ' ;
	}
}

//6.�������
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

//12.��������
template<class T>
BiNode<T>* BiTree<T>::GetRoot()
{
	return this->root;
}

//21.ɾ������
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

//23.�ж����Ƿ�Ϊ��ȫ�����������ڲ�������� 
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
				if (flag == true)//������ָ����зǿ�ָ�� 
					return false;
				
				queue.push(p->left);
				queue.push(p->right);
			}
		}
	}
	
	return flag;
} 

//25.���������ڲ�������� 
template<class T>
int Width(BiTree<T>& bt)
{
	queue<BiNode<T>*> queue;
	BiNode<T>* p = bt.GetRoot();
	
	BiNode<T>* levelRear;//�ò�ĩβ���
	int levelNum = 0;//�ò�����
	int max = 0;//���������
	
	if (p != NULL)
	{
		queue.push(p);
		levelRear = p;
		while (!queue.empty())
		{
			p = queue.front();
			queue.pop();
			
			if (p->left != NULL)
				queue.push(p->left);	
			if (p->right != NULL)
				queue.push(p->right);
			
			levelNum++;
			
			if (p == levelRear)
			{
				//1.���� max 
				if (levelNum > max)
					max = levelNum;
				//2.���� levelNum
				levelNum = 0;
				//3.���� levelRear
				if (queue.back() != levelRear)
					levelRear = queue.back();
				else
					return max;
			}
		}
	}
} 

//���俴���ú���-�ֵܱ�ʾ����ʾ���� 
//1.�����x�������Ԫ�أ�����-�ֵܱ�ʾ����ʾ���� ��
template<class T>
void OutputLevelX(BiTree<T>& bt, int x)
{
	queue<BiNode<T>*> queue;
	BiNode<T>* p = bt.GetRoot();
	vector<BiNode<T>*> firstChild;
	if (p != NULL)
		queue.push(p);
	else
		return;
	
	for (int level = 1; level < x; level++)
	{
		//�������г���������� 
		int size = queue.size();
		for (int i = 1; i <= size; i++)
		{
			p = queue.front();
			queue.pop();
			
			if (p->left != NULL){
				queue.push(p->left);
				firstChild.push_back(p->left);
			}
		}
		
		//���ó��ӵ������ֵ���������� 
		for (int i = 0; i < firstChild.size(); i++)
		{
			while (firstChild[i]->right != NULL){
				queue.push(firstChild[i]->right);
				firstChild[i] = firstChild[i]->right; 
			}
		}
	}
	
	while (!queue.empty())
	{
		p = queue.front();
		queue.pop();
		
		cout << p->data << ' ';
	}
}

//2.ͳ��Ҷ�ӵĸ���������-�ֵܱ�ʾ����ʾ���� ��
template<class T>
int LeavesNum(BiTree<T>& bt)//���ڲ������ 
{
	int count = 0; 
	queue<BiNode<T>*> queue;
	BiNode<T>* p = bt.GetRoot();
	
	if (p != NULL)
	{
		queue.push(p);
		while (!queue.empty())
		{
			p = queue.front();
			queue.pop();
			
			if (p->left == NULL)//���ʷ�ʽ 
				count++;
			
			if (p->left != NULL)
				queue.push(p->left);
			if (p->right != NULL)
				queue.push(p->right);
		}
	}
	
	return count;
}

//3. ����������ȣ�����-�ֵܱ�ʾ����ʾ���� ��
template<class T>
int Depth(BiTree<T>& bt)
{
	queue<BiNode<T>*> queue;
	BiNode<T>* p = bt.GetRoot();
	vector<BiNode<T>*> firstChild;
	if (p != NULL)
		queue.push(p);
	else
		return 0;
		
	int level = 1;
	for (; !queue.empty(); level++)
	{
		//�������г���������� 
		int size = queue.size();
		for (int i = 1; i <= size; i++)
		{
			p = queue.front();
			queue.pop();
			
			if (p->left != NULL){
				queue.push(p->left);
				firstChild.push_back(p->left);
			}
		}
		
		//���ó��ӵ������ֵ���������� 
		for (int i = 0; i < firstChild.size(); i++)
		{
			while (firstChild[i]->right != NULL){
				queue.push(firstChild[i]->right);
				firstChild[i] = firstChild[i]->right; 
			}
		}
	}
	
	return level-1;
}

//4.����Huffman��
template<class T>
BiNode<T>* CreateHuffmanTree(BiNode<T>* root)
{
	priority_queue<BiNode<T>*, vector<BiNode<T>*>, cmp<T> > heap;//������С�� 
	
	int n;
	cin >> n;
	T ele;
	for (int i = 1; i <= n; i++)
	{
		cin >> ele;
		BiNode<T>* node = new BiNode<T>;
		node->data = ele;
		node->left = node->right = NULL;
		heap.push(node);
	}
	
	BiNode<T>* min1;
	BiNode<T>* min2;
	
	while (heap.size() != 1) 
	{
		min1 = heap.top();
		heap.pop();
		min2 = heap.top();
		heap.pop();
		
		BiNode<T>* r = new BiNode<T>;
		r->data = min1->data + min2->data;
		r->left = min1;
		r->right = min2;
		
		heap.push(r);
	}
	
	root = heap.top();
	return root;
}

template<class T>
void Encode(BiNode<T>* root)//���ڲ������ 
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
			
			if (p->left != NULL){
				p->left->codes = p->codes + "0";
				queue.push(p->left);
			}
			if (p->right != NULL){
				p->right->codes = p->codes + "1";
				queue.push(p->right);
			}
			
			if ((p->left == NULL) && (p->right == NULL))//��Ҷ��㣬�������� 
			{
				cout << p->data << ": " << p->codes << endl; 
			}
		}
	}
}

#endif
