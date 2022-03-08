#include "avl_tree.h"

BiNode::BiNode(ElemType dataIn): data(dataIn)
{
	left = right = NULL;
}

AVL_Tree::AVL_Tree()
{
	root = NULL;
}

AVL_Tree::~AVL_Tree()
{
	Delete(root);
}

bool AVL_Tree::Create(const string fileName)
{
	fstream dataFile(fileName, ios::in);
	if (!dataFile){
		cout << "���ļ�" << fileName << "ʧ�ܣ�" << endl;
		return false; 
	}
	
	int data;
	while (!dataFile.eof())
	{
		dataFile >> data;
		root = Insert(root, data);
	}
	
	dataFile.close();
	return true;
}

Position AVL_Tree::Find(ElemType data)
{
	Position pos = root;
	while (pos != NULL)
	{
		if (data < pos->data)
			pos = pos->left;
		else if (data > pos->data)
			pos = pos->right;
		else
			return pos;
	}
	return NULL;
}

Position AVL_Tree::FindMax(BiTree root)
{
	BiNode* p = root;
	if (p == NULL)
		return NULL;
	else
	{
		while (p->right != NULL)
		{
			p = p->right;
		}
	}
	return p;
}

Position AVL_Tree::FindMin(BiTree root)
{
	BiNode* p = root;
	if (p == NULL)
		return NULL;
	else
	{
		while (p->left != NULL)
		{
			p = p->left;
		}
	}
	return p;
}

Position AVL_Tree::Insert(BiTree root, ElemType data)
{
	if(root == NULL)
	{
		root = new BiNode(data);
	}
	else
	{
		if(data < root->data)
		{
			//���뵽������ 
			root->left = Insert(root->left, data);
			//����ƽ�����ӣ����ж������ת 
			if(height(root->left) - height(root->right) == 2)
			{
				if(data < root->left->data)
					root = LL_rotation(root);
				else if(data > root->left->data)
					root = LR_rotation(root);
			}
		}
		else if(data > root->data)
		{
			//���뵽������ 
			root->right = Insert(root->right, data);
			//����ƽ�����ӣ����ж������ת 
			if(height(root->right) - height(root->left) == 2)
			{
				if(data > root->right->data)
					root = RR_rotation(root);
				else if(data < root->right->data)
					root = RL_rotation(root);
			}
		}
	}
	return root;
}

Position AVL_Tree::Delete(BiTree root)
{
	if (root != NULL){
		root->left = Delete(root->left);
		root->right = Delete(root->right);
		delete root;
		return NULL;
	}
}

Position AVL_Tree::Delete(BiTree root, ElemType data)
{
	//˼·�� 
	//1.�ҵ���㣨����ΪҶ��㣬ת��ΪҶ��㣩
	//2.ɾ�� 
	//3.ƽ����� 
	if (root == NULL)
		return NULL;
	else
	{
		if (data < root->data) //1.�ҽ��
		{
			root->left = Delete(root->left, data);
		}
		else if (data > root->data) //1.�ҽ��
		{
			root->right = Delete(root->right, data);
		}
		else
		{
			//2.ɾ��
			if ((root->left == NULL) && (root->right == NULL))
			{
				delete root;
				if (root == this->root)//������� 
					this->root = NULL;
				return NULL;
			}
			else//1.������ΪҶ��㣬ת��ΪҶ��㣩
			{
				Position pos;
				if (height(root->left) > height(root->right))
				{
					pos = FindMax(root->left);
					//����data�����������ֵ 
					swap(root->data, pos->data);
					root->left = Delete(root->left, data);
				}
				else
				{
					pos = FindMin(root->right);
					//����data����������Сֵ 
					swap(root->data, pos->data);
					root->right = Delete(root->right, data);
				}
			}
		}
	}
	
	//3.ƽ����� 
	if (height(root->left) - height(root->right) == 2)
	{
		if (height(root->left->left) >= height(root->left->right))
			root = LL_rotation(root);
		else
			root = LR_rotation(root);
	}
	else if (height(root->left) - height(root->right) == -2)
	{
		if (height(root->right->right) >= height(root->right->left))
			root = RR_rotation(root);
		else
			root = RL_rotation(root);
	}
	
	return root; 
}

int AVL_Tree::height(BiNode* root)
{
	if (root == NULL)
		return 0;
	else
		return 1 + max(height(root->left), height(root->right));
}

Position AVL_Tree::LL_rotation(BiTree root)
{
	BiNode* p1 = root->left;
	BiNode* p2 = p1->right;
	root->left = p2;
	p1->right = root;
	return p1;
}

Position AVL_Tree::LR_rotation(BiTree root)
{
	BiNode* p1 = root->left;
	BiNode* p2 = p1->right;
	root->left = p2->right;
	p2->right = root;
	p1->right = p2->left;
	p2->left = p1;
	return p2;
}

Position AVL_Tree::RL_rotation(BiTree root)
{
	BiNode* p1 = root->right;
	BiNode* p2 = p1->left;
	root->right = p2->left;
	p2->left = root;
	p1->left = p2->right;
	p2->right = p1;
	return p2;
}

Position AVL_Tree::RR_rotation(BiTree root)
{
	BiNode* p1 = root->right;
	BiNode* p2 = p1->left;
	root->right = p2;
	p1->left = root;
	return p1;
}

void AVL_Tree::print(BiTree root)
{
	if (root == this->root)
		cout << endl << "ƽ�������������������£�" << endl;
	if (root == NULL)
		return;
	else if (root != NULL){
		print(root->left);
		cout << root->data << " ";
		print(root->right);
	}
}

//ѡ���� 9.32 
void find_a_b(AVL_Tree& avl_tree, BiTree root, ElemType x, ElemType* a, ElemType* b)
{
	if (root == NULL) 
		return;
	else
	{
		if (root->data < x)
		{
			*a = root->data;
			find_a_b(avl_tree, root->right, x, a, b);
		}
		else if (root->data > x)
		{
			*b = root->data;
			find_a_b(avl_tree, root->left, x, a, b);
		}
		else
		{
			Position pos1 = avl_tree.FindMax(root->left);
			Position pos2 = avl_tree.FindMin(root->right);
			
			if (pos1 != NULL)
				*a = pos1->data;
			if (pos2 != NULL)
				*b = pos2->data;
		}
	}
}
