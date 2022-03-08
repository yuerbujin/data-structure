#include "chartable.h"

#include <iostream>
#include <fstream>

void CharTable::calculateFreq(const string& filename) 
{
	fstream file(filename.data());
	if (file.bad()){
		cout << "cann't open " << filename << endl;
		return;
	}
	
	//ÿ�ζ���һ���ַ�
	//�����ڱ��У����������� 
	//���ڱ��У����Ƶ��1
	char c1;
	while (file.get(c1))//ÿ�ζ���һ�ַ� 
	{ 
		auto iter = table.find(c1);
		if (iter == table.end())//c1���ڱ���
		{
			table.insert(pair<char, int>(c1, 1)); 
		}
		else//c1�ڱ���
		{
			iter->second++;
		}
	}
	
	file.close();
}
