#ifndef ENDEDPROCESS_H
#define ENDEDPROCESS_H

#include <iostream>
#include <time.h>
#include <string.h>
using namespace std;

typedef struct DLNode{
	string name;//进程名称
	string PID;//进程唯一标识 
	int memory;//占用内存
//	clock_t startTime;//程序起始时间 
	time_t endTime;//程序结束时间 
	clock_t duration;//程序持续时间 
	DLNode* last;//前驱
	DLNode* next;//后继 
	
	DLNode();//缺省构造 
	DLNode(string nameIn, string PIDin, int memoryIn,
			time_t endTimeIn, clock_t durationIn);//构造函数 
}*DList;

class EndedProcess{
	public:
		EndedProcess();//缺省构造函数 
		~EndedProcess();//析构函数 
		
		bool Insert(DLNode node);//在链表中插入结点 
		bool Delete(string name);//在链表中删除结点 

		bool Find(string name, DLNode*& pos);//查询该进程是否存在 
		bool Find(clock_t duration, DLNode*& pos);//寻找进程应插入的位置 
		
		void print();//输出已结束进程 
		
	private:
		DList front;//已结束进程链表头结点 
		DList tail;//已结束进程链表尾结点 
		int num;//结点个数 
}; 

#endif
