#include "mytrie.h"

letterNode::letterNode(){}

letterNode::letterNode(char keyIn, string infoIn)
					  : key(keyIn), info(infoIn){} 

MyTrie::MyTrie(const string& fileName)
{
	fstream dataFile(fileName, ios::in);
	root.key = '#';//������ 
	
	while (!dataFile.eof())
	{
		string newWord, newInfo;
		dataFile >> newWord >> newInfo;
		add(newWord, newInfo);
		dataFile.ignore();
	}
	
	dataFile.close();
}

MyTrie::~MyTrie(){} 

void MyTrie::add(const string& word, string& info)
{
	if (find(word) != NULL)
	{
		cout << "���Ӹõ���ʧ�ܣ���Ϊ���Ѿ����ڣ��������޸ĸõ��ʡ�" << endl;
		return;
	}
	
	//1.�õ���ǰ�벿�ֲ������ 
	letterNode* p = &root;
	int i = 0;
	while (i < word.size())
	{		
		if (p->nexts.empty())
			break;
		else
			for (int j = 0; j < p->nexts.size(); j++)
				if (p->nexts[j].key == word.at(i))//�ɹ�ƥ��һ�ַ�
				{
					i++;
					p = &(p->nexts[j]);//����p 
					break; 
				}
				else if (j+1 == p->nexts.size())
				{
					goto here;
				}
	}
	here:
		
	//2.�õ��ʺ�벿����Ҫ���� 
	for (; i < word.size(); i++)
	{	
		if (i+1 == word.size())
		{
			p->nexts.push_back(letterNode(word.at(i), info));
		}
		else
		{
			p->nexts.push_back(letterNode(word.at(i), string()));
		}
		
		int pos = p->nexts.size()-1;
		p = &(p->nexts.at(pos));//����p 
	}
}

void MyTrie::Delete(const string& word)
{
	letterNode* p = find(word);
	if (p == NULL)
	{
		cout << "ɾ���õ���ʧ�ܣ���Ϊ�䲻���ڡ�" << endl;
		return;
	}
	
	letterNode* tmp1 = &root; 
	char tmp2; 
	p = &root;
	int i = 0;
	while (i < word.size())
	{		
		if (p->nexts.empty())
			break;
		for (int j = 0; j < p->nexts.size(); j++)
			if (p->nexts[j].key == word.at(i))//�ɹ�ƥ��һ�ַ� 
			{
				if (p->nexts.size() > 1)//����tmp 
				{
					tmp1 = p;
					tmp2 = word.at(i);
				}
				
				i++;
				p = &(p->nexts[j]);//����p 
				break;
			}
			else if (j+1 == p->nexts.size())
				return;
	}
	
	auto iter = tmp1->nexts.begin();
	for (; iter->key != tmp2; iter++);
	
	tmp1->nexts.erase(iter);
}

void MyTrie::modify(const string& word, string& info)
{
	letterNode* p = find(word);
	if (p == NULL)
	{
		cout << "�õ��ʲ����ڣ����������Ƿ�Ϸ���" << endl;
		return;
	}
	else
	{
		p->info = info;
		cout << "�ɹ��޸ĵ��� " << word << " �������Ϣ��" << endl;
	}
}

void MyTrie::show(const string& word)
{
	letterNode* p = find(word);
	if (p == NULL)
	{
		cout << "�õ��ʲ����ڣ����������Ƿ�Ϸ���" << endl;
		return;
	}
	else
	{
		cout << "���� " << word << " �������Ϣ���£�" << endl
			 << p->info << endl << endl;
	}
}

letterNode* MyTrie::find(const string& word)
{
	letterNode* p = &root;
	int i = 0;
	while (i < word.size())
	{		
		if (p->nexts.empty())
			return NULL;
		for (int j = 0; j < p->nexts.size(); j++)
		{
			if (p->nexts[j].key == word.at(i))//�ɹ�ƥ��һ�ַ� 
			{
				i++;
				p = &(p->nexts[j]);//����p 
				break;
			}
			else if (j+1 == p->nexts.size())
				return NULL;
		}
	}
	if (!(p->info.empty()))
		return p;
	else
		return NULL;
}

void Operation(int x, MyTrie& dict)
{
	switch (x)
	{
		case 0: operation0();break;
		case 1: operation1(dict);break;
		case 2: operation2(dict);break;
		case 3: operation3(dict);break;
		case 4: operation4(dict);break;
		default :operation0();break;
	}
}

void operation0()
{
	cout<< "�������˳���" << endl;
	exit(0);
}

void operation1(MyTrie& dict)
{
	string newWord, newInfo;
	cout << "��������ʲô�����أ�" << endl;
	cin >> newWord;
	cout << "������õ��ʵ������Ϣ��" << endl;
	cin >> newInfo;
	dict.add(newWord, newInfo);
}

void operation2(MyTrie& dict)
{
	string word;
	cout << "����ɾ����һ�������أ�" << endl;
	cin >> word;
	dict.Delete(word);
}

void operation3(MyTrie& dict)
{
	string word, newInfo;
	cout << "�����޸���һ�������أ�" << endl;
	cin >> word;
	cout << "������õ��ʵ�����Ϣ��" << endl;
	cin >> newInfo;
	dict.modify(word, newInfo);
}
 
void operation4(MyTrie& dict)
{
	string word;
	cout << "������ʾ��һ�����ʵ������Ϣ�أ�" << endl;
	cin >> word;
	dict.show(word);
}
