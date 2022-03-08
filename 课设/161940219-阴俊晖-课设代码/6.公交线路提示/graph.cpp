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
		if (stop[k].name == name)//该站点已存在 
			return k;
		else if (k+1 == stop.size())//该站点不存在
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
	//初始化 
	string tem("#");
	stop.push_back(Stop(tem, NONE));
	route.push_back(Route());
	
	for (int i = 1; !dataFile.eof(); i++)//i表示行数 
	{
		dataFile >> No;
		for (int j = 1; j <= 4; j++)//忽略路及其后的三个空格 
			dataFile.ignore();
		
		string line;
		dataFile >> line;
		line += ",";
		int start = 0;
		int end = 0;
		
//		cout << "line: " << line << endl;//debug
		
		route.push_back(Route());//构建route 
		while (string::npos != line.find(',', start))
		{
			end = line.find(',', start);
//			cout << "end: " << end << endl;//debug
			//构建stop 
			string newName(line.substr(start, end - start));
			start = end+1;
//			cout << newName << endl;//debug

			int pos = findPos(stop, newName);
			if (pos == NONE)//该站点不存在
				stop.push_back(Stop(newName, i));
			else
				stop[pos].routes.push_back(i);
			
			//构建route 
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
	cout<< "程序已退出" << endl;
	exit(0);
}

//点线交替BFS 
void operation1(vector<Stop>& stop, vector<Route>& route)
{
	//先预置所有的path和visited！！！！！！！！！！！！！！！！！ 
	for (int i = 1; i < stop.size(); i++)
	{
		stop[i].path = NONE;
		stop[i].visited = false;
	}
	
	string start, end;
	cout << "请任意输入两站点的名称：" << endl;
	cin >> start >> end;
	if (start == end)
	{
		cout << "起终点相同，不需乘车。" << endl;
		return;
	}
	swap(start, end);//交换起终点，目的便于最后输出路径 
	
	vector<string> pointTmp;//暂存站点 
	vector<int> routeTmp;//暂存路线 
	int n = stop.size();
	vector<int> visited(n+1, false);
	vector<string> path(n+1, string(""));
	
	pointTmp.push_back(start);
	int pos = findPos(stop, start);
	if (pos == NONE)
	{
		cout << "输入非法！" << endl;
		return;
	}
	stop[pos].visited = true;//入队即访问 
	
	while (1)
	{
		//非法检测 
		if (pointTmp.empty())
		{
			cout << "起点与终点不连通，请检查输入是否合法！" << endl;
			return;
		}
		//点到线 
		for (int i = 0; i < pointTmp.size(); i++)
		{
			if (pointTmp[i] == end)//找到终点！！！ 
				goto here1;
			else
			{
				int pos = findPos(stop, pointTmp[i]);
//				stop[pos].visited = true;//访问该站点
//				cout << "pos:" << pos << endl;//debug
				//将所有站点所在的所有路线入队 
				for (int j = 0; j < stop[pos].routes.size(); j++)
				{
					int tem = stop[pos].routes[j];//所有路线下标 
					if (!visited[tem])
					{
						visited[tem] = true;//访问该路线
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
		
		//非法检测 
		if (routeTmp.empty())
		{
			cout << "起点与终点不连通，请检查输入是否合法！" << endl;
			return;
		}
		//线到点
		for (int i = 0; i < routeTmp.size(); i++)
		{
			for (int j = 0; j < route[routeTmp[i]].stations.size(); j++)
			{
				int pos = findPos(stop, route[routeTmp[i]].stations[j]);
//				cout << "pos:" << pos << endl;//debug
//				cout << "stop[pos].visited:" << stop[pos].visited << endl;//debug
				if (!stop[pos].visited)
				{
					stop[pos].visited = true;//访问该站点
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
	
	//找到终点！！！ 
	here1:
//		cout << "here1" << endl;//debug
	
	//其实打印的是终点到起点的路径
	string pointTmp2 = end;
	int routeTmp2;
	
	cout << "以下为转车次数最少的乘车路线：" << endl;
	for (int i = 0; true; i++)
	{
		//点到线
		int pos = findPos(stop, pointTmp2);
		routeTmp2 = stop[pos].path;		
		if (routeTmp2 == NONE)//终止条件 
		{
			cout << "共需转车 " << i-1 << " 次。" << endl;
			break;	
		}
		cout << "在 " << pointTmp2 << " 上车，乘坐 " << routeTmp2 << " 号线，";
		
		//线到点 
		pointTmp2 = path[routeTmp2];
		cout << "至 " << pointTmp2 << " 下车。" << endl;
	}
}

//BFS
void operation2(vector<Stop>& stop, vector<Route>& route)
{
	//先预置所有的path和visited！！！！！！！！！！！！！！！！！ 
	for (int i = 1; i < stop.size(); i++)
	{
		stop[i].path = NONE;
		stop[i].visited = false;
	}
	
	string start, end;
	cout << "请任意输入两站点的名称：" << endl;
	cin >> start >> end;
	if (start == end)
	{
		cout << "起终点相同，不需乘车。" << endl;
		return;
	}
	swap(start, end);//交换起终点，目的便于最后输出路径 
	
	vector<int> routeTmp;//暂存路线 
	int n = stop.size();
	vector<string> path(n+1, string(""));
	
	queue<string> Queue;//站点队列
	Queue.push(start);
	int pos = findPos(stop, start);
	if (pos == NONE)
	{
		cout << "输入非法！" << endl;
		return;
	}
	stop[pos].visited = true;//入队即访问 
	 
	while (1)
	{
		if (Queue.empty())
		{
			cout << "起点与终点不连通，请检查输入是否合法！" << endl;
			return;
		}
		
		string pointTmp = Queue.front();
//		cout << "pointTmp:" << pointTmp << endl;//debug
		Queue.pop();
		if (pointTmp == end)//找到终点 
			break;
		
		//将 pointTmp 所有的邻接点入队 
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
					break;//j为pointTmp所在数组的下标 
				}
			}
			
//			cout << "j: " << j << endl;//debug
			//使pointTmp左右两站点入队 
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
	
	cout << "以下为经过站点最少的乘车路线：" << endl;
	string curName = end;
	int i = 0;
	for (; curName != start; i++)
	{
		cout << curName << " -> ";
		int pos4 = findPos(stop, curName);
		curName = stop[pos4].prev;
	}
	cout << curName << endl
		 << "共需乘坐 " << i << " 站。" << endl;
}
