#ifndef MYTRIE_H
#define MYTRIE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <string>
#include <string.h>
#include <algorithm>
#define NONE -1
#define M 500
using namespace std;

struct letterNode{
	char key;//�ؼ��� 
	string info;//�ô���Ϣ 
	
	vector<letterNode> nexts;//���� 
	
	letterNode();
	letterNode(char keyIn, string infoIn);
};

class MyTrie{
	public:
		MyTrie(const string& fileName);//��ȡ���ݲ����� 
		~MyTrie();//������ 
		
		void add(const string& word, string& info);//���ӵ��� 
		void Delete(const string& word);//ɾ������
		void modify(const string& word, string& info);//�޸ĵ���
		void show(const string& word);//��ʾ������Ϣ 
		letterNode* find(const string& word);//���ҵ���
		
//	private:
		letterNode root;//�����
}; 

void Operation(int x, MyTrie& dict);
void operation0();//�˳����� 
void operation1(MyTrie& dict);//��ʾ������������Ϣ
void operation2(MyTrie& dict);//��ʾ��n �������˵���Ϣ
void operation3(MyTrie& dict);//��ʾĳ�˵���Ϣ
void operation4(MyTrie& dict);//��ѯ����֮���ϵ

#endif
