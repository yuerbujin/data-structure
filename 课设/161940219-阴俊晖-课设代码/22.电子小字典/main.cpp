#include <iostream>
#include "mytrie.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv)
{
	const string fileName("data.txt");//ԭʼ�����ļ� 
//	const string fileName("test.txt");//debug
	
	MyTrie dict(fileName);
	
	int x;
	while(1)
	{
		system("cls");
		
		cout << "����������ʵ����Ӧ�����ޡ�" << endl
			 << "�������ӵ��ʣ��밴1" << endl
			 << "����ɾ�����ʣ��밴2" << endl
			 << "�����޸ĵ��ʣ��밴3" << endl
			 << "������ʾ������Ϣ���밴4" << endl
			 << "�����˳������밴0" << endl << endl 
			 << "�����룺";
		cin >> x;
		cout << endl;
		Operation(x, dict);//ִ����Ӧ���� 
		
		system("pause");
	}
}
