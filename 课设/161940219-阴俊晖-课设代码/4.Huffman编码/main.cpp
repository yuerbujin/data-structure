#include <iostream>
#include "huffmantree.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv)
{	
	const string sourceFile("source.txt");//δ�����ļ��� 
//	const string sourceFile("test.txt");//�����ļ� 
	
	//Ҫ��һ 
	CharTable charTable;
	charTable.calculateFreq(sourceFile);//ͳ�ƴ�Ƶ 
	HuffmanTree hTree(charTable);//����
	hTree.show("Huffman.txt");//��ӡ��Ƶ�����룬��д���ļ�
	
	//Ҫ���	
	hTree.encode(sourceFile, "code.dat");//���ļ����� 
	
	//Ҫ���� 
	hTree.decode("code.dat", "������.txt");//���ļ����� 
	
	return 0;
}
