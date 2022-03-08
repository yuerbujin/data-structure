#include <iostream>
#include "mytrie.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv)
{
	const string fileName("data.txt");//原始数据文件 
//	const string fileName("test.txt");//debug
	
	MyTrie dict(fileName);
	
	int x;
	while(1)
	{
		system("cls");
		
		cout << "请输入数字实现相应功能噢。" << endl
			 << "若想增加单词，请按1" << endl
			 << "若想删除单词，请按2" << endl
			 << "若想修改单词，请按3" << endl
			 << "若想显示单词信息，请按4" << endl
			 << "若想退出程序，请按0" << endl << endl 
			 << "请输入：";
		cin >> x;
		cout << endl;
		Operation(x, dict);//执行相应操作 
		
		system("pause");
	}
}
