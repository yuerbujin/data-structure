#include "mytrie.h"

letterNode::letterNode(){}

letterNode::letterNode(char keyIn, string infoIn)
					  : key(keyIn), info(infoIn){} 

MyTrie::MyTrie(const string& fileName)
{
	fstream dataFile(fileName, ios::in);
	root.key = '#';//特殊标记 
	
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
		cout << "增加该单词失败，因为其已经存在，您可以修改该单词。" << endl;
		return;
	}
	
	//1.该单词前半部分不需插入 
	letterNode* p = &root;
	int i = 0;
	while (i < word.size())
	{		
		if (p->nexts.empty())
			break;
		else
			for (int j = 0; j < p->nexts.size(); j++)
				if (p->nexts[j].key == word.at(i))//成功匹配一字符
				{
					i++;
					p = &(p->nexts[j]);//更新p 
					break; 
				}
				else if (j+1 == p->nexts.size())
				{
					goto here;
				}
	}
	here:
		
	//2.该单词后半部分需要插入 
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
		p = &(p->nexts.at(pos));//更新p 
	}
}

void MyTrie::Delete(const string& word)
{
	letterNode* p = find(word);
	if (p == NULL)
	{
		cout << "删除该单词失败，因为其不存在。" << endl;
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
			if (p->nexts[j].key == word.at(i))//成功匹配一字符 
			{
				if (p->nexts.size() > 1)//更新tmp 
				{
					tmp1 = p;
					tmp2 = word.at(i);
				}
				
				i++;
				p = &(p->nexts[j]);//更新p 
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
		cout << "该单词不存在，请检查输入是否合法。" << endl;
		return;
	}
	else
	{
		p->info = info;
		cout << "成功修改单词 " << word << " 的相关信息。" << endl;
	}
}

void MyTrie::show(const string& word)
{
	letterNode* p = find(word);
	if (p == NULL)
	{
		cout << "该单词不存在，请检查输入是否合法。" << endl;
		return;
	}
	else
	{
		cout << "单词 " << word << " 的相关信息如下：" << endl
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
			if (p->nexts[j].key == word.at(i))//成功匹配一字符 
			{
				i++;
				p = &(p->nexts[j]);//更新p 
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
	cout<< "程序已退出。" << endl;
	exit(0);
}

void operation1(MyTrie& dict)
{
	string newWord, newInfo;
	cout << "您想增加什么单词呢？" << endl;
	cin >> newWord;
	cout << "请输入该单词的相关信息：" << endl;
	cin >> newInfo;
	dict.add(newWord, newInfo);
}

void operation2(MyTrie& dict)
{
	string word;
	cout << "您想删除哪一个单词呢？" << endl;
	cin >> word;
	dict.Delete(word);
}

void operation3(MyTrie& dict)
{
	string word, newInfo;
	cout << "您想修改哪一个单词呢？" << endl;
	cin >> word;
	cout << "请输入该单词的新信息：" << endl;
	cin >> newInfo;
	dict.modify(word, newInfo);
}
 
void operation4(MyTrie& dict)
{
	string word;
	cout << "您想显示哪一个单词的相关信息呢？" << endl;
	cin >> word;
	dict.show(word);
}
