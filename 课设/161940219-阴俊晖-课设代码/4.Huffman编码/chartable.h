#ifndef CHARTABLE_H
#define CHARTABLE_H

#include <string>
#include <map>

using namespace std;

class CharTable{
	public:
		//�����ļ������г����ַ��Ĵ�Ƶ 
		void calculateFreq(const string& filename);
	
	private:
		//��Ŵ�Ƶ 
		map<char, int> table;
		
	friend class HuffmanTree;
};

#endif
