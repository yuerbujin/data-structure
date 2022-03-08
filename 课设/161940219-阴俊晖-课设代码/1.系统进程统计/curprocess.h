#ifndef CURPROCESS_H
#define CURPROCESS_H

#include <iostream>
#include <time.h>
#include "endedprocess.h"
using namespace std;

typedef struct SLNode{
	string name;//��������
	string PID;//����Ψһ��ʶ 
	int memory;//ռ���ڴ�
	clock_t startTime;//������ʼʱ���־��������ʵ��ʼʱ�䣩 
	clock_t duration;//�������ʱ��
	bool checked;//������ǩ 
	SLNode* next;//���
	
	SLNode();//ȱʡ���� 
	SLNode(string nameIn, string PIDin, int memoryIn);//���캯�� 
}*SList;

class CurProcess{
	public:
		CurProcess();//ȱʡ���캯�� 
		~CurProcess();//�������� 
		void get();//��ȡ��ǰ���н��� 
		
		bool Insert(SLNode node);//�������в����� 
		bool Delete(string name);//��������ɾ����� 

		//Find����pos���صĶ���ǰһ��λ�õ�ָ�� 
//		bool Find(string PID, SLNode*& pos);//��ѯ�ý����Ƿ���� 
		bool Find(string name, SLNode*& pos);//��ѯ�ý����Ƿ���� 
		bool Find(int memory, SLNode*& pos);//Ѱ���½���Ӧ�����λ�� 
		
		void setUncheck();//renew�ĸ������� 
		void renew(EndedProcess& endedPro);//���µ�ǰ���� 
		void print();//�����ǰ���� 
		
	private:
		SList curHead;//��ǰ��������ͷ��㣨ͷ���Ϊ�գ� 
		int num;//��ǰ������ 
}; 

#endif
