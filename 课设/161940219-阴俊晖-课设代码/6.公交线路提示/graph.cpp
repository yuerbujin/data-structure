#include "graph.h"

Stop::Stop(string& nameIn, int routeIn): name(nameIn)
{
	routes.push_back(routeIn);
	path = NONE;
	visited = false; 
}

int findPos(vector<Stop>& stop, const string& name)
{
	for (int k = 0; k < stop.size(); k++)
	{
		if (stop[k].name == name)//��վ���Ѵ��� 
			return k;
		else if (k+1 == stop.size())//��վ�㲻����
			return NONE;
	}
}

Route::Route()
{
//	path = NONE;
//	visited = false; 
}

void readIn(const string fileName, vector<Stop>& stop, vector<Route>& route)
{
	fstream dataFile(fileName);
	int No;
	string stopnName;
	//��ʼ�� 
	string tem("#");
	stop.push_back(Stop(tem, NONE));
	route.push_back(Route());
	
	for (int i = 1; !dataFile.eof(); i++)//i��ʾ���� 
	{
		dataFile >> No;
		for (int j = 1; j <= 4; j++)//����·�����������ո� 
			dataFile.ignore();
		
		string line;
		dataFile >> line;
		line += ",";
		int start = 0;
		int end = 0;
		
//		cout << "line: " << line << endl;//debug
		
		route.push_back(Route());//����route 
		while (string::npos != line.find(',', start))
		{
			end = line.find(',', start);
//			cout << "end: " << end << endl;//debug
			//����stop 
			string newName(line.substr(start, end - start));
			start = end+1;
//			cout << newName << endl;//debug

			int pos = findPos(stop, newName);
			if (pos == NONE)//��վ�㲻����
				stop.push_back(Stop(newName, i));
			else
				stop[pos].routes.push_back(i);
			
			//����route 
			route[i].stations.push_back(newName);
		}
	}
	
	//debug
//	for (auto iter = stop.begin(); iter != stop.end(); iter++)
//	{
//		cout << iter->name << " " << iter->routes[0] << endl;
//		for (int i = 0; i < iter->routes.size(); i++)
//			cout << iter->routes[i] << " ";
//		cout << endl;
//	}
//	for (int j = 0; j < route.size(); j++)
//	{
//		for (int k = 0; k < route.at(j).stations.size(); k++)
//			cout << route.at(j).stations.at(k) << ',';
//		cout << endl;
//	}
	
	dataFile.close();
}

void Operation(int x, vector<Stop>& stop, vector<Route>& route)
{
	switch (x)
	{
		case 0: operation0();break;
		case 1: operation1(stop, route);break;
		case 2: operation2(stop, route);break;
	}
}

void operation0()
{
	cout<< "�������˳�" << endl;
	exit(0);
}

//���߽���BFS 
void operation1(vector<Stop>& stop, vector<Route>& route)
{
	//��Ԥ�����е�path��visited���������������������������������� 
	for (int i = 1; i < stop.size(); i++)
	{
		stop[i].path = NONE;
		stop[i].visited = false;
	}
	
	string start, end;
	cout << "������������վ������ƣ�" << endl;
	cin >> start >> end;
	if (start == end)
	{
		cout << "���յ���ͬ������˳���" << endl;
		return;
	}
	swap(start, end);//�������յ㣬Ŀ�ı���������·�� 
	
	vector<string> pointTmp;//�ݴ�վ�� 
	vector<int> routeTmp;//�ݴ�·�� 
	int n = stop.size();
	vector<int> visited(n+1, false);
	vector<string> path(n+1, string(""));
	
	pointTmp.push_back(start);
	int pos = findPos(stop, start);
	if (pos == NONE)
	{
		cout << "����Ƿ���" << endl;
		return;
	}
	stop[pos].visited = true;//��Ӽ����� 
	
	while (1)
	{
		//�Ƿ���� 
		if (pointTmp.empty())
		{
			cout << "������յ㲻��ͨ�����������Ƿ�Ϸ���" << endl;
			return;
		}
		//�㵽�� 
		for (int i = 0; i < pointTmp.size(); i++)
		{
			if (pointTmp[i] == end)//�ҵ��յ㣡���� 
				goto here1;
			else
			{
				int pos = findPos(stop, pointTmp[i]);
//				stop[pos].visited = true;//���ʸ�վ��
//				cout << "pos:" << pos << endl;//debug
				//������վ�����ڵ�����·����� 
				for (int j = 0; j < stop[pos].routes.size(); j++)
				{
					int tem = stop[pos].routes[j];//����·���±� 
					if (!visited[tem])
					{
						visited[tem] = true;//���ʸ�·��
						routeTmp.push_back(tem);
//						cout << "tem:" << tem << endl;//debug
						path[tem] = stop[pos].name;
//						cout << "stop[pos].name:" << stop[pos].name << endl;//debug
					}	
				}
			}
		}
		//debug
//		cout << "pointTmp:";
//		for (int z = 0; z < pointTmp.size(); z++)
//			cout << pointTmp[z] << " ";
//		cout << endl;
		
		pointTmp.clear(); 
		
		//�Ƿ���� 
		if (routeTmp.empty())
		{
			cout << "������յ㲻��ͨ�����������Ƿ�Ϸ���" << endl;
			return;
		}
		//�ߵ���
		for (int i = 0; i < routeTmp.size(); i++)
		{
			for (int j = 0; j < route[routeTmp[i]].stations.size(); j++)
			{
				int pos = findPos(stop, route[routeTmp[i]].stations[j]);
//				cout << "pos:" << pos << endl;//debug
//				cout << "stop[pos].visited:" << stop[pos].visited << endl;//debug
				if (!stop[pos].visited)
				{
					stop[pos].visited = true;//���ʸ�վ��
					pointTmp.push_back(stop[pos].name);
//					cout << "stop[pos].name:" << stop[pos].name << endl;//debug
					stop[pos].path = routeTmp[i];
				}
			}
		}
		//debug
//		cout << "routeTmp:";
//		for (int z = 0; z < routeTmp.size(); z++)
//			cout << routeTmp[z] << " ";
//		cout << endl;
		
		routeTmp.clear();
		
	}
	
	//�ҵ��յ㣡���� 
	here1:
//		cout << "here1" << endl;//debug
	
	//��ʵ��ӡ�����յ㵽����·��
	string pointTmp2 = end;
	int routeTmp2;
	
	cout << "����Ϊת���������ٵĳ˳�·�ߣ�" << endl;
	for (int i = 0; true; i++)
	{
		//�㵽��
		int pos = findPos(stop, pointTmp2);
		routeTmp2 = stop[pos].path;		
		if (routeTmp2 == NONE)//��ֹ���� 
		{
			cout << "����ת�� " << i-1 << " �Ρ�" << endl;
			break;	
		}
		cout << "�� " << pointTmp2 << " �ϳ������� " << routeTmp2 << " ���ߣ�";
		
		//�ߵ��� 
		pointTmp2 = path[routeTmp2];
		cout << "�� " << pointTmp2 << " �³���" << endl;
	}
}

//BFS
void operation2(vector<Stop>& stop, vector<Route>& route)
{
	//��Ԥ�����е�path��visited���������������������������������� 
	for (int i = 1; i < stop.size(); i++)
	{
		stop[i].path = NONE;
		stop[i].visited = false;
	}
	
	string start, end;
	cout << "������������վ������ƣ�" << endl;
	cin >> start >> end;
	if (start == end)
	{
		cout << "���յ���ͬ������˳���" << endl;
		return;
	}
	swap(start, end);//�������յ㣬Ŀ�ı���������·�� 
	
	vector<int> routeTmp;//�ݴ�·�� 
	int n = stop.size();
	vector<string> path(n+1, string(""));
	
	queue<string> Queue;//վ�����
	Queue.push(start);
	int pos = findPos(stop, start);
	if (pos == NONE)
	{
		cout << "����Ƿ���" << endl;
		return;
	}
	stop[pos].visited = true;//��Ӽ����� 
	 
	while (1)
	{
		if (Queue.empty())
		{
			cout << "������յ㲻��ͨ�����������Ƿ�Ϸ���" << endl;
			return;
		}
		
		string pointTmp = Queue.front();
//		cout << "pointTmp:" << pointTmp << endl;//debug
		Queue.pop();
		if (pointTmp == end)//�ҵ��յ� 
			break;
		
		//�� pointTmp ���е��ڽӵ���� 
		int pos2 = findPos(stop, pointTmp);
		for (int i = 0; i < stop[pos2].routes.size(); i++)
		{
			int tem2 = stop[pos2].routes[i];
//			cout << "tem2: " << tem2 << endl;//debug
			int j = 0;
			for (; j < route[tem2].stations.size(); j++)
			{
				if (route[tem2].stations[j] == pointTmp)
				{
//					tmp1 = j;
					break;//jΪpointTmp����������±� 
				}
			}
			
//			cout << "j: " << j << endl;//debug
			//ʹpointTmp������վ����� 
			if (j-1 >= 0)
			{
				int pos3 = findPos(stop, route[tem2].stations[j-1]);
//				cout << "stop[pos3].name  left  :" << stop[pos3].name << endl;//debug
				if (!stop[pos3].visited)
				{
					stop[pos3].visited = true;
					Queue.push(stop[pos3].name);
//					cout << "stop[pos3].name  left  :" << stop[pos3].name << endl;//debug
					stop[pos3].prev = pointTmp;
				}
			}
			if (j+1 < route[tem2].stations.size())
			{
				int pos3 = findPos(stop, route[tem2].stations[j+1]);
//				cout << "stop[pos3].name  right  :" << stop[pos3].name << endl;//debug
				if (!stop[pos3].visited)
				{
					stop[pos3].visited = true;
					Queue.push(stop[pos3].name);
//					cout << "stop[pos3].name  right  :" << stop[pos3].name << endl;//debug
					stop[pos3].prev = pointTmp;
				}
			}
		}
	} 
	
	cout << "����Ϊ����վ�����ٵĳ˳�·�ߣ�" << endl;
	string curName = end;
	int i = 0;
	for (; curName != start; i++)
	{
		cout << curName << " -> ";
		int pos4 = findPos(stop, curName);
		curName = stop[pos4].prev;
	}
	cout << curName << endl
		 << "������� " << i << " վ��" << endl;
}
