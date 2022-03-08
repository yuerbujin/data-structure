#include "endedprocess.h"

DLNode::DLNode(): name("This node is empty.")
{
	last = next = NULL;
}

//���캯�� 
DLNode::DLNode(string nameIn, string PIDin, int memoryIn, time_t endTimeIn, clock_t durationIn)
			  :name(nameIn), PID(PIDin), memory(memoryIn), endTime(endTimeIn), duration(durationIn)	
{
	last = next = NULL;
}

EndedProcess::EndedProcess()
{
	front = tail = new DLNode;
	num = 0;
}

EndedProcess::~EndedProcess()
{
	DLNode* p = front;
	DLNode* tem = p->next;
	
	while (p != NULL)
	{
		delete p;
		p = tem;
		if (tem != NULL)
			tem = tem->next;
		num--;
	}
	
	front = tail = NULL;
}

bool EndedProcess::Insert(DLNode node)
{
	DLNode* pos = NULL;
	if (Find(node.duration, pos))//�ҵ��˲���λ�� 
	{
		DLNode* tem = pos->next;
		DLNode* ptr = new DLNode(node);//���ƹ��캯�� 
		if (pos != tail)
		{
			//�޸��ĸ�ָ�� 
			pos->next = ptr;
			ptr->last = pos;
		 	ptr->next = tem;
			tem->last = ptr;
		}
		else
		{
			//�޸�����ָ�벢����tail 
			tail->next = ptr;
			ptr->last = tail;
			tail = ptr;
		}
		num++;
		return true;
	}
	else
	{
		return false;
	}
}

bool EndedProcess::Delete(string name)
{
	DLNode* pos = NULL;
	if (Find(name, pos))//�ҵ��˸ý��
	{
		DLNode* tem = pos->next;
		if (pos->next != tail)
		{
			DLNode* tem2 = tem->next;
			pos->next = tem2;
			tem2->last = pos;
		}
		else
		{
			pos->next = NULL;
			tail = pos;
		}
		delete tem;//�ͷŸý��ռ� 
		num--;
		return true;
	}
	else
	{
		return false;
	}
}

bool EndedProcess::Find(string name, DLNode*& pos)
{
	DLNode* p = front;
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

bool EndedProcess::Find(clock_t duration, DLNode*& pos)
{
	DLNode* p = front;
	if (p == NULL)
	{
		pos = NULL;
		return false;
	}
	
	while ((p->next != NULL) && (duration > p->next->duration))
	{
		p = p->next;
	}
	pos = p;
	return true;
}

void EndedProcess::print()
{
	if (num == 0)
	{
		cout << "��ǰϵͳ���ѽ����Ľ��̣�" << endl;
		return;
	}
	else
	{
		DLNode* p = front->next;
		cout << endl << "�������ѽ�����ϵͳ���̣�" << endl << endl
			 << "\"ӳ������\",\"PID\",\"�ڴ�ʹ�ã���λ��K�� \",\"����ʱ��\",\"����ʱ�䣨��λ��s��\"" << endl;
		for (; p != NULL; p = p->next)
		{
			char* endTime = ctime(&p->endTime);
			endTime[strlen(endTime)-1] = 0;//Ϊ��ʹ�������ʱ�䲻���� 
			
			cout << "name: " << p->name << " "
				 << "PID: " << p->PID << " "
				 << "memory: " << p->memory << " "
				 << "ended time: " << endTime << " "
				 << "duration: " << p->duration << "s "
				 << endl;
		}
	}
}
