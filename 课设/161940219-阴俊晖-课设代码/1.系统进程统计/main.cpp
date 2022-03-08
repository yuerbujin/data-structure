#include <iostream>
#include <windows.h>
#include "curprocess.h"
#include "endedprocess.h"

#define TIMES 10//统计次数 
#define INTERVAL 1000//每隔1秒更新一次 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv)
{
	//1.获取原始进程
	CurProcess curProcess;
	curProcess.get();
	
	EndedProcess endedProcess; 
	curProcess.print();//debug
	
	//2.实时统计 
	for (int i = 1; i <= TIMES; i++)
	{
		Sleep(INTERVAL);//每隔 INTERVAL 更新一次进程信息 
		curProcess.renew(endedProcess);//更新进程信息 
		
		curProcess.print();//输出当前进程 
		endedProcess.print();//输出已结束进程 
	}
	
	return 0;
}
