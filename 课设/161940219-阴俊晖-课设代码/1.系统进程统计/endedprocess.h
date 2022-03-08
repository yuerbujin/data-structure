#ifndef ENDEDPROCESS_H
#define ENDEDPROCESS_H

#include <iostream>
#include <time.h>
#include <string.h>
using namespace std;

typedef struct DLNode{
	string name;//��������
	string PID;//����Ψһ��ʶ 
	int memory;//ռ���ڴ�
//	clock_t startTime;//������ʼʱ�� 
	time_t endTime;//�������ʱ�� 
	clock_t duration;//�������ʱ�� 
	DLNode* last;//ǰ��
	DLNode* next;//��� 
	
	DLNode();//ȱʡ���� 
	DLNode(string nameIn, string PIDin, int memoryIn,
			time_t endTimeIn, clock_t durationIn);//���캯�� 
}*DList;

class EndedProcess{
	public:
		EndedProcess();//ȱʡ���캯�� 
		~EndedProcess();//�������� 
		
		bool Insert(DLNode node);//�������в����� 
		bool Delete(string name);//��������ɾ����� 

		bool Find(string name, DLNode*& pos);//��ѯ�ý����Ƿ���� 
		bool Find(clock_t duration, DLNode*& pos);//Ѱ�ҽ���Ӧ�����λ�� 
		
		void print();//����ѽ������� 
		
	private:
		DList front;//�ѽ�����������ͷ��� 
		DList tail;//�ѽ�����������β��� 
		int num;//������ 
}; 

#endif
