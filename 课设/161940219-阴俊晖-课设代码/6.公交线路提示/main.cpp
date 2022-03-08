#include <iostream>
#include <iomanip>
#include "graph.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv)
{
	vector<Stop> stop;
	vector<Route> route;
	
	const string fileName("南京公交线路.txt");
//	const string fileName("test.txt");
	readIn(fileName, stop, route);//从文件读入数据 
	
	int x;
	while(1)
	{
		system("cls");
		
		cout << "请输入数字实现相应功能噢。" << endl
			 << "若想给出转车次数最少的乘车路线，请按1" << endl
			 << "若想给出经过站点最少的乘车路线，请按2" << endl
			 << "若想退出程序，请按0" << endl << endl 
			 << "请输入：";
		cin >> x;
		cout << endl;
		Operation(x, stop, route);//执行相应操作 
		
		system("pause");
	}
}
