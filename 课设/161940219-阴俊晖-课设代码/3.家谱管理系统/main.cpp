#include <iostream>
#include "familytree.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv)
{
	const string fileName("data.txt");//ԭʼ�����ļ� 
//	const string fileName("test.txt");
	
	familyTree family(fileName);
	
	int x;
	while(1)
	{
//		system("cls");
		
		cout << "����������ʵ����Ӧ�����ޡ�" << endl
			 << "������ʾ������������Ϣ���밴1" << endl
			 << "������ʾ��n �������˵���Ϣ���밴2" << endl
			 << "������ʾĳ�˵���Ϣ���밴3" << endl
			 << "�����ѯ����֮���ϵ���밴4" << endl
			 << "����Ϊĳ����Ӻ��ӣ��밴5" << endl
			 << "����Ϊĳ�������ż���밴6" << endl
			 << "����ɾ��ĳ��Ա���밴7" << endl
			 << "�����޸�ĳ��Ա��Ϣ���밴8" << endl
			 << "���밴�ճ���/�������ڲ�ѯ��Ա��Ϣ���밴9" << endl
			 << "�����˳������밴0" << endl << endl 
			 << "�����룺";
		cin >> x;
		cout << endl;
		Operation(x, family);//ִ����Ӧ���� 
		
		system("pause");
	}
}
