#include <iostream>
#include <windows.h>
#include "curprocess.h"
#include "endedprocess.h"

#define TIMES 10//ͳ�ƴ��� 
#define INTERVAL 1000//ÿ��1�����һ�� 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv)
{
	//1.��ȡԭʼ����
	CurProcess curProcess;
	curProcess.get();
	
	EndedProcess endedProcess; 
	curProcess.print();//debug
	
	//2.ʵʱͳ�� 
	for (int i = 1; i <= TIMES; i++)
	{
		Sleep(INTERVAL);//ÿ�� INTERVAL ����һ�ν�����Ϣ 
		curProcess.renew(endedProcess);//���½�����Ϣ 
		
		curProcess.print();//�����ǰ���� 
		endedProcess.print();//����ѽ������� 
	}
	
	return 0;
}
