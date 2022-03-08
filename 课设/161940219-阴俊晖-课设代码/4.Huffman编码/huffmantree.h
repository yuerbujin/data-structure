#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <iomanip>
#include <string.h>
#include <bitset>
#include "chartable.h"

using namespace std;

struct BiNode{
	char data;//Ӣ���ַ�
	int weight;//�ַ�Ȩֵ�������Ƶ 
	BiNode* left;
	BiNode* right;
	string codes;//������ 
	
	BiNode(char c, int w);
	BiNode(int w);
	~BiNode();
	
	void show();//��ӡ��Ƶ������
};

//��д�º����Խ�����С�� 
struct cmp{
	bool operator()(BiNode* n1, BiNode* n2);
};

class HuffmanTree{
	public:
		HuffmanTree(CharTable& charTable);//���� 
		~HuffmanTree();//����Huffman tree���ݹ飩
		
		void encode(const string& filename1, const string& filename2);//���� 
		void decode(const string& filename1, const string& filename2);//����
		
		void show(const string& filename);//��ӡ��Ƶ�����룬��д���ļ�
	
	private:
		BiNode* root;//���� 
		map<char, string> codeTable;//����� 
};

#endif
