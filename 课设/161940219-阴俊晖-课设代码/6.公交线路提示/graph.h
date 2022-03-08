#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <string>
#include <string.h>
#include <algorithm>
#define NONE -1
using namespace std;

struct Stop{
	string name;//站点名称 
	vector<int> routes;//所在的公交路线 
	int path;//记录路径 
	bool visited;//辅助标识 
	string prev;//记录路径，该站点前驱站点的名称 
	
	Stop(string& nameIn, int routeIn);
};

struct Route{
//	int No;//公交路线 
	vector<string> stations;//经停站点 
//	int path;//记录路径 
//	bool visited;//辅助标识 
	
	Route();
};

void readIn(const string fileName, vector<Stop>& stop, vector<Route>& route);////从文件读入数据 

void Operation(int x, vector<Stop>& stop, vector<Route>& route);
void operation0();
void operation1(vector<Stop>& stop, vector<Route>& route);
void operation2(vector<Stop>& stop, vector<Route>& route);

#endif
