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

//���캯�� 
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
	//��ԭʼ����д���ļ��У���ʽ���� 
	string command("tasklist /fo csv >> " + fileName);
	system(command.data());
	
	//���ļ��ж���ϵͳ���� 
	fstream curProFile(fileName);
	if (!curProFile){
		cout << "���ļ�" << fileName << "ʧ�ܣ�" << endl;
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
		//һ��ѭ������һ��������Ϣ
		curProFile.ignore();
		curProFile.getline(tem, MAXLENGTH, '"');//��ȡ����name 
		name.assign(tem);
		
		curProFile.ignore();
		curProFile.ignore();
		curProFile.getline(tem, MAXLENGTH, '"');//��ȡ����PID 
		PID.assign(tem);
		
		curProFile.ignore();
		curProFile.getline(tem, MAXLENGTH, ',');
		curProFile.getline(tem, MAXLENGTH, ',');
		curProFile.ignore();
		
		curProFile.getline(tem, MAXLENGTH, ' ');//��ȡ����memory 
		memory.assign(tem);
		
		//ȥ��memory�еĶ��� 
		memory.erase(remove(memory.begin(), memory.end(), ','), memory.end());
		//��memoryתΪint
		int memory_int = atoi(memory.data());
		
		curProFile.getline(tem, MAXLENGTH);
		SLNode* pos1 = NULL;
		if (this->Find(name, pos1))//���ظ��������� 
		{
			continue; 
		}
		//������̽�㣬�����뵽����һ�Ρ�����������
		if (name != "") 
			Insert(SLNode(name, PID, memory_int));
	}
	
	curProFile.close();
	
	//�Ѹ��ļ�ɾ�������� 
	remove(fileName.data());
}

bool CurProcess::Insert(SLNode node)
{
	SLNode* pos = NULL;
	if (Find(node.memory, pos))//�ҵ��˲���λ�� 
	{
		SLNode* tem = pos->next;
		pos->next = new SLNode(node);//���ƹ��캯�� 
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
	if (Find(name, pos))//�ҵ��˸ý��
	{
		SLNode* tem = pos->next;
		pos->next = tem->next;
		delete tem;//�ͷŸý��ռ� 
		num--;
		return true;
	}
	else
	{
		return false;
	}
}

bool CurProcess::Find(string name, SLNode*& pos)//��ѯ�ý����Ƿ���� 
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

//Ѱ���½���Ӧ�����λ�� 
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

//���� 
void CurProcess::renew(EndedProcess& endedPro)
{
	setUncheck();//��ʼ�� 
	
	//����ǰ����д���ļ��У���ʽ���� 
	string command("tasklist /fo csv >> " + fileName);
	system(command.data());
	
	//���ļ��ж���ϵͳ���� 
	fstream curProFile(fileName);
	if (!curProFile){
		cout << "���ļ�" << fileName << "ʧ�ܣ�" << endl;
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
		//һ��ѭ������һ��������Ϣ
		curProFile.ignore();
		curProFile.getline(tem, MAXLENGTH, '"');//��ȡ����name 
		name.assign(tem);
		
		curProFile.ignore();
		curProFile.ignore();
		curProFile.getline(tem, MAXLENGTH, '"');//��ȡ����PID 
		PID.assign(tem);
		
		curProFile.ignore();
		curProFile.getline(tem, MAXLENGTH, ',');
		curProFile.getline(tem, MAXLENGTH, ',');
		curProFile.ignore();
		
		curProFile.getline(tem, MAXLENGTH, ' ');//��ȡ����memory 
		memory.assign(tem);
		
		//ȥ��memory�еĶ��� 
		memory.erase(remove(memory.begin(), memory.end(), ','), memory.end());
		//��memoryתΪint
		int memory_int = atoi(memory.data());
		
		curProFile.getline(tem, MAXLENGTH);
		
		SLNode* pos1 = NULL;
		DLNode* pos2 = NULL;
	
		//1.���³������н��̵�ʱ�� 
		if (this->Find(name, pos1))
		{
			pos1 = pos1->next;
			pos1->duration = (clock() - pos1->startTime) / CLOCKS_PER_SEC;
			pos1->checked = true;
		}
		else//2.�����½��� 
		{
			//���жϸý����Ƿ������ѽ������������У����ڣ�Ӧ����ɾȥ 
			if (endedPro.Find(name, pos2))
				endedPro.Delete(name);
			
			if (name != "") 
				Insert(SLNode(name, PID, memory_int));
		}		
	}
	
	curProFile.close();
	
	//3.ɾ���ѽ����Ľ��� 
	SLNode* p = curHead->next;
	for (; p != NULL; p = p->next)
		if (!p->checked)
		{
			//�Ƚ�����뵽�ѽ�������������
			endedPro.Insert(DLNode(p->name, p->PID, p->memory, time(NULL), (clock() - p->startTime) / CLOCKS_PER_SEC));
			//�ٽ���ӵ�ǰ����������ɾ��
			this->Delete(p->name);
		}

	//�Ѹ��ļ�ɾ�������� 
	remove(fileName.data());
}

void CurProcess::print()
{	
	if (num == 0)
	{
		cout << "��ǰϵͳ�޽��̣�" << endl;
		return;
	}
	else
	{
		SLNode* p = curHead->next;
		cout << endl <<  "�����ǵ�ǰϵͳ���̣�" << endl << endl
			 << "\"ӳ������\",\"PID\",\"�ڴ�ʹ�ã���λ��K�� \",\"����ʱ�䣨��λ��s��\"" << endl;
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
