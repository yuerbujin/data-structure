#include "familytree.h"

Person::Person(){} 

Person::Person(string& nameIn, bool genderIn, bool marriedIn, bool aliveIn, string& dateIn, string& addressIn)
			  :name(nameIn), gender(genderIn), married(marriedIn), alive(aliveIn), date(dateIn), address(addressIn)
{
	
}

Couple::Couple(){}

Couple::Couple(Person husbandIn, Person wifeIn, int geIn)
			  : husband(husbandIn), wife(wifeIn), generation(geIn)
{

}

familyTree::familyTree(const string& fileName)
{
	personCnt = 0;
	fstream dataFile(fileName, ios::in);
	
	string name1, name2, date, address, tmp1, tmp2, tmp3;
	bool gender, married, alive;
	char x;
	while (dataFile.get(x))
	{
		if (personCnt != 0)
			dataFile >> name1;
			
		dataFile >> name2 >> tmp1 >> tmp2 >> tmp3 >> date >> address;
		dataFile.ignore();//�������з� 
		
		if (tmp1 == "��")				gender = true;
		else if (tmp1 == "Ů")			gender = false;
		if (tmp2 == "�ѻ�")				married = true;
		else if (tmp2 == "δ��")		married = false; 
		if (tmp3 == "����")				alive = true;
		else if (tmp3 == "�ѹ�")		alive = false;
		Person person(name2, gender, married, alive, date, address);
		
		if (x == '5')//��Ӻ��� 
		{
			if (gender)
				addChild(name1, Couple(person, Person()));
			else
				addChild(name1, Couple(Person(), person));
		}
		else if (x == '6')//�����ż 
		{	
			addCouple(name1, person);
		}
	}
	
	dataFile.close();
}

familyTree::~familyTree(){}

//��ʾ��������Ϣ����������� 
void familyTree::show()
{
	cout << "�����Ǽ����������˵���Ϣ��" << endl;
	
	queue<Couple*> Queue;
	Queue.push(&ancestor);
	
	while (!Queue.empty())
	{
		Couple* cpl = Queue.front();
		Queue.pop();
		
		//�������Ϣ 
		show(cpl->husband);
		show(cpl->wife);
		
		for (int i = 0; i < cpl->offspring.size(); i++)
			Queue.push(&cpl->offspring.at(i));
	}
}

//��ʾ��n����������Ϣ ����������� 
void familyTree::show(int generation)
{
	cout << "�����ǵ� " << generation << " �������˵���Ϣ��" << endl; 
	
	queue<Couple*> Queue;
	Queue.push(&ancestor);
//	Couple* lastPtr = Queue.front();//ָ��ÿ�����һ����� 
//	int level = 1; 
	
	while (!Queue.empty())
	{
		Couple* cpl = Queue.front();
		Queue.pop();
		
		//�������Ϣ 
		if (cpl->generation == generation)
		{
			show(cpl->husband);
			show(cpl->wife);
		}
		else if (cpl->generation > generation)
			return;
		
		for (int i = 0; i < cpl->offspring.size(); i++)
			Queue.push(&cpl->offspring.at(i));
			
//		if (cpl == lastPtr)
//		{
//			lastPtr = Queue.back();
//			level++;
//		}
	}
}

//��ʾ������Ϣ 
void familyTree::show(const Person& person, bool familyMember)
{	
	if (person.name.empty())
		return;
//	cout << "here4" << endl;//debug
	
	cout << "����Ϊ " << person.name << " ��ȫ����Ϣ��" << endl
		 << person.name << " ";
	if (person.gender)		cout << "�� ";
	else				cout << "Ů ";
	if (person.married)		cout << "�ѻ� ";
	else				cout << "δ�� ";
	if (person.alive)		cout << "���� ";
	else				cout << "�ѹ� "; 
	cout << person.date << " " << person.address << endl << endl;
	
	if (familyMember)
	{
		Couple* cpl = findParents(person.name);//�ҵ���˫�� 
		if (cpl != NULL)
		{
			cout << "����Ϊ " << person.name << " ˫�׵�ȫ����Ϣ��" << endl << endl;	 
			show(cpl->husband);
			show(cpl->wife);
		}
		else
			cout << "δ�ҵ� " << person.name << " ��˫�ס�" << endl << endl;
		
		cpl = find(person.name);//�ҵ��䱾�� 
		if (cpl == NULL)
			cout << "δ�ҵ� " << person.name << "�����������Ƿ�Ϸ���" << endl << endl;
		else if (cpl->offspring.size() == 0)
			cout << person.name << " ����Ů��" << endl << endl;
		else
		{
			cout << "����Ϊ " << person.name << " ��Ů��ȫ����Ϣ��" << endl << endl; 
			for (int i = 0; i < cpl->offspring.size(); i++)
			{			
				show(cpl->offspring[i].husband);	
				show(cpl->offspring[i].wife);	
			}
		}
	}
}

//��ʾ���˹�ϵ
void familyTree::showRelation(const string& name1, const string& name2)
{
	if (name1 == name2)
	{
		cout << "����ͬһ�ˡ�" << endl;
		return;
	}
	
	Couple* cpl1 = find(name1);
	Couple* cpl2 = find(name2);
	if (cpl1 == cpl2)
	{
		cout << name1 << "�� "  << name2 << " �Ƿ��޹�ϵ��" << endl; 
		return;
	}
	
	int ge1 = cpl1->generation;
	int ge2 = cpl2->generation;
	int minG = min(ge1, ge2);
	Couple* cpl;
	
	if (ge1 > minG)
	{
		string tmp = name1;
		
		cout << name1 << " ";
		while (ge1-- > minG)
		{
			cout << "�ĸ���";
			cpl = findParents(tmp);
			tmp = cpl->husband.name;
		}
		
		if (cpl->husband.name == name2)
			cout << "�� " << name2 << endl;
		else if (cpl->wife.name == name2)
			cout << "�������� " << name2 << endl;
		else
			cout << "�� "  << name2 << " ���ֵܽ��ù�ϵ��" << endl; 
	}
	else if (ge2 > minG)
	{
		string tmp = name2;
		cout << name2 << " ";
		while (ge2-- > minG)
		{
			cout << "�ĸ���";
			cpl = findParents(tmp);
			tmp = cpl->husband.name;
		}
		
		if (cpl->husband.name == name1)
			cout << "�� " << name1 << endl;
		else if (cpl->wife.name == name1)
			cout << "�������� " << name1 << endl;
		else
			cout << "�� "  << name1 << " ���ֵܽ��ù�ϵ��" << endl; 
	}
	else
		cout << name1 << "�� "  << name2 << " ���ֵܽ��ù�ϵ��" << endl; 
}

//���������ң���������� 
Couple* familyTree::find(const string& name)
{
	queue<Couple*> Queue;
	Queue.push(&ancestor);
	
	while (!Queue.empty())
	{
		Couple* cpl = Queue.front();
		Queue.pop();
		
		if ((cpl->husband.name == name) || (cpl->wife.name == name))//�ҵ� 
			return cpl;
		
		for (int i = 0; i < cpl->offspring.size(); i++)
			Queue.push(&cpl->offspring.at(i));
	}
	//δ�ҵ� 
	return NULL;
}

//������˫�ף���������� 
Couple* familyTree::findParents(const string& name)
{
	queue<Couple*> Queue;
	Queue.push(&ancestor);
	
	while (!Queue.empty())
	{
		Couple* cpl = Queue.front();
		Queue.pop();
		
		for (int i = 0; i < cpl->offspring.size(); i++)
			if ((cpl->offspring[i].husband.name == name) || (cpl->offspring[i].wife.name == name))//�ҵ� 
				return cpl;
		
		for (int i = 0; i < cpl->offspring.size(); i++)
			Queue.push(&cpl->offspring.at(i));
	}
	//δ�ҵ� 
	return NULL;
}

//������/�������ڲ��ң���������� 
void familyTree::show(bool alive, const string& date)
{
	cout << "����Ϊ����Ҫ������г�Ա��Ϣ��" << endl;
	queue<Couple*> Queue;
	Queue.push(&ancestor);
	
	while (!Queue.empty())
	{
		Couple* cpl = Queue.front();
		Queue.pop();
		
		if ((cpl->husband.alive == alive) && (cpl->husband.date == date))
			show(cpl->husband);
		if ((cpl->wife.alive == alive) && (cpl->wife.date == date))
			show(cpl->wife);
					
		for (int i = 0; i < cpl->offspring.size(); i++)
			Queue.push(&cpl->offspring.at(i));
	}
}

//��Ӻ���
void familyTree::addChild(const string& name, Couple couple)
{
	if (personCnt == 0)
	{
		ancestor = couple;
		ancestor.generation = 1;
	}
	else
	{
		Couple* cpl = find(name);
		if (cpl == NULL)
		{
			cout << "δ�ҵ� " << name << "�����������Ƿ�Ϸ���" << endl << endl;
			return;
		}
		couple.generation = cpl->generation+1;
		cpl->offspring.push_back(couple);
	}
	personCnt++;
}

//�����ż 
void familyTree::addCouple(const string& name, const Person person)
{
//	cout << "here5" << endl;//debug
	Couple* cpl = find(name);
	if (cpl->husband.name == name)
		cpl->wife = person;
	else
		cpl->husband = person;
	personCnt++;
}

//ɾ����Ա 
void familyTree::deletePerson(const string& name)
{
	if ((ancestor.husband.name == name) || (ancestor.wife.name == name))
		ancestor.~Couple();
	else
	{
		Couple* cpl = findParents(name);
		if (cpl == NULL)
		{
			cout << "δ�ҵ� " << name << "�����������Ƿ�Ϸ���" << endl << endl;
			return;
		}
		auto iter = cpl->offspring.begin();
		for (; iter != cpl->offspring.end(); )
			if ((iter->husband.name == name) || (iter->wife.name == name))
			{
				iter = cpl->offspring.erase(iter);
			}
			else
				iter++;
	}
}

//�޸ĳ�Ա��Ϣ 
void familyTree::modify(const string& name, Person person)
{
	Couple* cpl = find(name);
	if (cpl->husband.name == name)
		cpl->husband = person;
	else if (cpl->wife.name == name)
		cpl->wife = person;
}

void Operation(int x, familyTree& family)
{
	switch (x)
	{
		case 0: operation0();break;
		case 1: operation1(family);break;
		case 2: operation2(family);break;
		case 3: operation3(family);break;
		case 4: operation4(family);break;
		case 5: operation5(family);break;
		case 6: operation6(family);break;
		case 7: operation7(family);break;
		case 8: operation8(family);break;
		case 9: operation9(family);break;
		default :operation0();break;
	}
}

void operation0()
{
	cout<< "�������˳���" << endl;
	exit(0);
}

void operation1(familyTree& family)
{
	family.show();
}

void operation2(familyTree& family)
{
	int generation;
	cout << "������ʾ�ڼ����˵���Ϣ�أ�" << endl;
	cin >> generation;
	family.show(generation);
}

void operation3(familyTree& family)
{
	string name;
	cout << "������ʾ˭����Ϣ�أ�" << endl;
	cin >> name;
	bool familyMember;
	cout << "������ʾ " << name << " ��ͥ��Ա����Ϣ����������1����֮����0��" << endl;
	cin >> familyMember;
	Couple* cpl = family.find(name);
	if (cpl == NULL)
	{
		cout << "δ�ҵ� " << name << "�����������Ƿ�Ϸ���" << endl << endl;
		return;
	}
	else if (cpl->husband.name == name)
		family.show(cpl->husband, familyMember);
	else
		family.show(cpl->wife, familyMember);
}
 
void operation4(familyTree& family)
{
	string name1, name2;
	cout << "�����ѯ˭��˭֮�����Ϣ�أ�" << endl;
	cin >> name1 >> name2;
	family.showRelation(name1, name2);
}

void operation5(familyTree& family)
{
	string name1, name2, date, address, tmp1, tmp2, tmp3;
	bool gender, married, alive;
	
	cout << "����Ϊ˭��Ӻ����أ�" << endl;
	cin >> name1;
	cout << "���������������Ϣ��" << endl;
	cin >> name2 >> tmp1 >> tmp2 >> tmp3 >> date >> address;
	
	if (tmp1 == "��")				gender = true;
	else if (tmp1 == "Ů")			gender = false;
	if (tmp2 == "�ѻ�")				married = true;
	else if (tmp2 == "δ��")		married = false; 
	if (tmp3 == "����")				alive = true;
	else if (tmp3 == "�ѹ�")		alive = false;
	Person person(name2, gender, married, alive, date, address);
	
	if (gender)
		family.addChild(name1, Couple(person, Person()));
	else
		family.addChild(name1, Couple(Person(), person));
}
 
void operation6(familyTree& family)
{
	string name1, name2, date, address, tmp1, tmp2, tmp3;
	bool gender, married, alive;
	
	cout << "����Ϊ˭�����ż�أ�" << endl;
	cin >> name1;
	cout << "���������������Ϣ��" << endl;
	cin >> name2 >> tmp1 >> tmp2 >> tmp3 >> date >> address;
	
	if (tmp1 == "��")				gender = true;
	else if (tmp1 == "Ů")			gender = false;
	if (tmp2 == "�ѻ�")				married = true;
	else if (tmp2 == "δ��")		married = false; 
	if (tmp3 == "����")				alive = true;
	else if (tmp3 == "�ѹ�")		alive = false;
	Person person(name2, gender, married, alive, date, address);
	
	family.addCouple(name1, person); 
}
 
void operation7(familyTree& family)
{
	string name;
	cout << "����ɾ����λ��Ա�أ�" << endl;
	cin >> name;
	
	family.deletePerson(name);
}

void operation8(familyTree& family)
{
	string name1, name2, date, address, tmp1, tmp2, tmp3;
	bool gender, married, alive;
	
	cout << "�����޸���λ��Ա����Ϣ�أ�" << endl;
	cin >> name1;
	cout << "���������������Ϣ��" << endl;
	cin >> name2 >> tmp1 >> tmp2 >> tmp3 >> date >> address;
	
	if (tmp1 == "��")				gender = true;
	else if (tmp1 == "Ů")			gender = false;
	if (tmp2 == "�ѻ�")				married = true;
	else if (tmp2 == "δ��")		married = false; 
	if (tmp3 == "����")				alive = true;
	else if (tmp3 == "�ѹ�")		alive = false;
	Person person(name2, gender, married, alive, date, address);
	
	family.modify(name1, person);
}

void operation9(familyTree& family)
{
	bool alive;
	cout << "�����Ƿ��ڣ���������1����֮����0��" << endl;
	cin >> alive;
	string date;
	cout << "���������/�������ڣ�" << endl;
	cin >> date;
	
	family.show(alive, date);
}
