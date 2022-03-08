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
	char key;//关键字 
	string info;//该词信息 
	
	vector<letterNode> nexts;//子树 
	
	letterNode();
	letterNode(char keyIn, string infoIn);
};

class MyTrie{
	public:
		MyTrie(const string& fileName);//读取数据并建树 
		~MyTrie();//销毁树 
		
		void add(const string& word, string& info);//增加单词 
		void Delete(const string& word);//删除单词
		void modify(const string& word, string& info);//修改单词
		void show(const string& word);//显示单词信息 
		letterNode* find(const string& word);//查找单词
		
//	private:
		letterNode root;//根结点
}; 

void Operation(int x, MyTrie& dict);
void operation0();//退出程序 
void operation1(MyTrie& dict);//显示家谱所有人信息
void operation2(MyTrie& dict);//显示第n 代所有人的信息
void operation3(MyTrie& dict);//显示某人的信息
void operation4(MyTrie& dict);//查询两人之间关系

#endif
