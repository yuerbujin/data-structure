#ifndef CURPROCESS_H
#define CURPROCESS_H

#include <iostream>
#include <time.h>
#include "endedprocess.h"
using namespace std;

typedef struct SLNode{
	string name;//进程名称
	string PID;//进程唯一标识 
	int memory;//占用内存
	clock_t startTime;//程序起始时间标志（并非真实起始时间） 
	clock_t duration;//程序持续时间
	bool checked;//辅助标签 
	SLNode* next;//后继
	
	SLNode();//缺省构造 
	SLNode(string nameIn, string PIDin, int memoryIn);//构造函数 
}*SList;

class CurProcess{
	public:
		CurProcess();//缺省构造函数 
		~CurProcess();//析构函数 
		void get();//获取当前所有进程 
		
		bool Insert(SLNode node);//在链表中插入结点 
		bool Delete(string name);//在链表中删除结点 

		//Find函数pos返回的都是前一个位置的指针 
//		bool Find(string PID, SLNode*& pos);//查询该进程是否存在 
		bool Find(string name, SLNode*& pos);//查询该进程是否存在 
		bool Find(int memory, SLNode*& pos);//寻找新进程应插入的位置 
		
		void setUncheck();//renew的辅助函数 
		void renew(EndedProcess& endedPro);//更新当前进程 
		void print();//输出当前进程 
		
	private:
		SList curHead;//当前进程链表头结点（头结点为空） 
		int num;//当前结点个数 
}; 

#endif
