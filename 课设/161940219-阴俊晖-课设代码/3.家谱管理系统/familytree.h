#ifndef FAMILYTREE_H
#define FAMILYTREE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <string>
#include <string.h>
#include <algorithm>
#define NONE -1
using namespace std;

struct Person{
	string name;//���� 
	bool gender;//�Ա�
	bool married;//��� 
	bool alive;//���ڷ� 
	string date;//����/�������� 
	string address;//סַ 
	
	Person();
	Person(string& nameIn, bool genderIn, bool marriedIn, bool aliveIn, string& dateIn, string& addressIn);
};

struct Couple{
//	bool which;//���棬husbandΪ�ӣ����٣�wifeΪŮ 
	Person husband;
	Person wife;
	int generation;//�ڼ����� 
	
	vector<Couple> offspring;//��� 
	
	Couple();
	Couple(Person husbandIn, Person wifeIn, int geIn = NONE);
};

class familyTree{
	public:
		familyTree(const string& fileName);//��ȡ���ݲ����� 
		~familyTree();//������ 
		
		void show();//��ʾ��������Ϣ 
		void show(int generation);//��ʾ��n����������Ϣ 
		void show(const Person& person, bool familyMember = false);//��ʾ������Ϣ 
		void show(bool alive, const string& date);//������/����������ʾ��Ϣ 
		void showRelation(const string& name1, const string& name2);//��ʾ���˹�ϵ
		
		Couple* find(const string& name);//����������
		Couple* findParents(const string& name);//������˫�� 
		
		void addCouple(const string& name, const Person person);//�����ż 
		void addChild(const string& name, Couple couple);//��Ӻ���
		void deletePerson(const string& name);//ɾ����Ա 
		void modify(const string& name, Person person);//�޸ĳ�Ա��Ϣ 
	
//	private:
		Couple ancestor;//����� 
		
		int personCnt;//������ 
}; 

void Operation(int x, familyTree& family);
void operation0();//�˳����� 
void operation1(familyTree& family);//��ʾ������������Ϣ
void operation2(familyTree& family);//��ʾ��n �������˵���Ϣ
void operation3(familyTree& family);//��ʾĳ�˵���Ϣ
void operation4(familyTree& family);//��ѯ����֮���ϵ
void operation5(familyTree& family);//Ϊĳ����Ӻ���
void operation6(familyTree& family);//Ϊĳ�������ż 
void operation7(familyTree& family);//ɾ��ĳ��Ա
void operation8(familyTree& family);//�޸�ĳ��Ա��Ϣ
void operation9(familyTree& family);//���ճ���/�������ڲ�ѯ��Ա��Ϣ

#endif
