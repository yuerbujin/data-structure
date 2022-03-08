#include "curprocess.h"
#include <string>
#include <fstream>
#include <algorithm>
#include <windows.h>

#define MAXLENGTH 9999
const string fileName("current_process.txt");

SLNode::SLNode(): name("This node is empty.")
{
	checked = true; 
	next = NULL;
}

//构造函数 
SLNode::SLNode(string nameIn, string PIDin, int memoryIn)
			  :name(nameIn), PID(PIDin), memory(memoryIn)
{
	startTime = clock();
	duration = 0;
	checked = true;
	next = NULL;
}

CurProcess::CurProcess()
{
	curHead = new SLNode;
	num = 0;
} 

CurProcess::~CurProcess()
{
	SLNode* p = curHead;
	SLNode* tem = p->next;
	
	while (p != NULL)
	{
		delete p;
		p = tem;
		if (tem != NULL)
			tem = tem->next;
		num--;
	}
	
	curHead = NULL;
}

void CurProcess::get()
{
	//将原始进程写入文件中（格式化） 
	string command("tasklist /fo csv >> " + fileName);
	system(command.data());
	
	//从文件中读入系统进程 
	fstream curProFile(fileName);
	if (!curProFile){
		cout << "打开文件" << fileName << "失败！" << endl;
		return; 
	} 
	
	const int maxLength = 256;
	char tem[maxLength];
	string format;
	string name, PID, memory;
	curProFile.getline(tem, MAXLENGTH);
	format.assign(tem);
	
	while (!curProFile.eof())
	{
		//一次循环读入一个进程信息
		curProFile.ignore();
		curProFile.getline(tem, MAXLENGTH, '"');//读取进程name 
		name.assign(tem);
		
		curProFile.ignore();
		curProFile.ignore();
		curProFile.getline(tem, MAXLENGTH, '"');//读取进程PID 
		PID.assign(tem);
		
		curProFile.ignore();
		curProFile.getline(tem, MAXLENGTH, ',');
		curProFile.getline(tem, MAXLENGTH, ',');
		curProFile.ignore();
		
		curProFile.getline(tem, MAXLENGTH, ' ');//读取进程memory 
		memory.assign(tem);
		
		//去掉memory中的逗号 
		memory.erase(remove(memory.begin(), memory.end(), ','), memory.end());
		//将memory转为int
		int memory_int = atoi(memory.data());
		
		curProFile.getline(tem, MAXLENGTH);
		SLNode* pos1 = NULL;
		if (this->Find(name, pos1))//若重复，不插入 
		{
			continue; 
		}
		//构造进程结点，并插入到“上一次”进程链表中
		if (name != "") 
			Insert(SLNode(name, PID, memory_int));
	}
	
	curProFile.close();
	
	//把该文件删除！！！ 
	remove(fileName.data());
}

bool CurProcess::Insert(SLNode node)
{
	SLNode* pos = NULL;
	if (Find(node.memory, pos))//找到了插入位置 
	{
		SLNode* tem = pos->next;
		pos->next = new SLNode(node);//复制构造函数 
		pos->next->next = tem;
		num++;
		return true;
	}
	else
	{
		return false;
	}
}

bool CurProcess::Delete(string name)
{
	SLNode* pos = NULL;
	if (Find(name, pos))//找到了该结点
	{
		SLNode* tem = pos->next;
		pos->next = tem->next;
		delete tem;//释放该结点空间 
		num--;
		return true;
	}
	else
	{
		return false;
	}
}

bool CurProcess::Find(string name, SLNode*& pos)//查询该进程是否存在 
{
	SLNode* p = curHead;
	if (p != NULL)
	{
		for (; p->next != NULL; p = p->next)
		{
			if (p->next->name == name)
			{
				pos = p;
				return true;
			}
		}
	}
	
	pos = NULL;
	return false;
}

//寻找新进程应插入的位置 
bool CurProcess::Find(int memory, SLNode*& pos)
{
	SLNode* p = curHead;
	if (p == NULL)
	{
		pos = NULL;
		return false;
	}
	
	while ((p->next != NULL) && (memory < p->next->memory))
	{
		p = p->next;
	}
	pos = p;
	return true;
}

void CurProcess::setUncheck()
{
	SLNode* p = curHead->next;
	for (; p != NULL; p = p->next)
		p->checked = false;
}

//核心 
void CurProcess::renew(EndedProcess& endedPro)
{
	setUncheck();//初始化 
	
	//将当前进程写入文件中（格式化） 
	string command("tasklist /fo csv >> " + fileName);
	system(command.data());
	
	//从文件中读入系统进程 
	fstream curProFile(fileName);
	if (!curProFile){
		cout << "打开文件" << fileName << "失败！" << endl;
		return; 
	} 
	
	const int maxLength = 256;
	char tem[maxLength];
	string format;
	string name, PID, memory;
	curProFile.getline(tem, MAXLENGTH);
	format.assign(tem);
	
	while (!curProFile.eof())
	{//cout << "called while !!!!!" << endl;
		//一次循环读入一个进程信息
		curProFile.ignore();
		curProFile.getline(tem, MAXLENGTH, '"');//读取进程name 
		name.assign(tem);
		
		curProFile.ignore();
		curProFile.ignore();
		curProFile.getline(tem, MAXLENGTH, '"');//读取进程PID 
		PID.assign(tem);
		
		curProFile.ignore();
		curProFile.getline(tem, MAXLENGTH, ',');
		curProFile.getline(tem, MAXLENGTH, ',');
		curProFile.ignore();
		
		curProFile.getline(tem, MAXLENGTH, ' ');//读取进程memory 
		memory.assign(tem);
		
		//去掉memory中的逗号 
		memory.erase(remove(memory.begin(), memory.end(), ','), memory.end());
		//将memory转为int
		int memory_int = atoi(memory.data());
		
		curProFile.getline(tem, MAXLENGTH);
		
		SLNode* pos1 = NULL;
		DLNode* pos2 = NULL;
	
		//1.更新持续运行进程的时间 
		if (this->Find(name, pos1))
		{
			pos1 = pos1->next;
			pos1->duration = (clock() - pos1->startTime) / CLOCKS_PER_SEC;
			pos1->checked = true;
		}
		else//2.增加新进程 
		{
			//先判断该进程是否是在已结束进程链表中，若在，应将其删去 
			if (endedPro.Find(name, pos2))
				endedPro.Delete(name);
			
			if (name != "") 
				Insert(SLNode(name, PID, memory_int));
		}		
	}
	
	curProFile.close();
	
	//3.删除已结束的进程 
	SLNode* p = curHead->next;
	for (; p != NULL; p = p->next)
		if (!p->checked)
		{
			//先将其插入到已结束进程链表中
			endedPro.Insert(DLNode(p->name, p->PID, p->memory, time(NULL), (clock() - p->startTime) / CLOCKS_PER_SEC));
			//再将其从当前进程链表中删除
			this->Delete(p->name);
		}

	//把该文件删除！！！ 
	remove(fileName.data());
}

void CurProcess::print()
{	
	if (num == 0)
	{
		cout << "当前系统无进程！" << endl;
		return;
	}
	else
	{
		SLNode* p = curHead->next;
		cout << endl <<  "以下是当前系统进程：" << endl << endl
			 << "\"映像名称\",\"PID\",\"内存使用（单位：K） \",\"持续时间（单位：s）\"" << endl;
		for (; p != NULL; p = p->next)
		{
			cout << "name: " << p->name << " "
				 << "PID: " << p->PID << " "
				 << "memory: " << p->memory << " "
				 << "duration: " << p->duration << "s "
				 << endl;
		}
	}
}
