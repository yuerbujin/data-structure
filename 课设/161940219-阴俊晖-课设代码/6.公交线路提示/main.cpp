#include <iostream>
#include <iomanip>
#include "graph.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv)
{
	vector<Stop> stop;
	vector<Route> route;
	
	const string fileName("�Ͼ�������·.txt");
//	const string fileName("test.txt");
	readIn(fileName, stop, route);//���ļ��������� 
	
	int x;
	while(1)
	{
		system("cls");
		
		cout << "����������ʵ����Ӧ�����ޡ�" << endl
			 << "�������ת���������ٵĳ˳�·�ߣ��밴1" << endl
			 << "�����������վ�����ٵĳ˳�·�ߣ��밴2" << endl
			 << "�����˳������밴0" << endl << endl 
			 << "�����룺";
		cin >> x;
		cout << endl;
		Operation(x, stop, route);//ִ����Ӧ���� 
		
		system("pause");
	}
}
