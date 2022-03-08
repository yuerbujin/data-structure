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
	string name;//վ������ 
	vector<int> routes;//���ڵĹ���·�� 
	int path;//��¼·�� 
	bool visited;//������ʶ 
	string prev;//��¼·������վ��ǰ��վ������� 
	
	Stop(string& nameIn, int routeIn);
};

struct Route{
//	int No;//����·�� 
	vector<string> stations;//��ͣվ�� 
//	int path;//��¼·�� 
//	bool visited;//������ʶ 
	
	Route();
};

void readIn(const string fileName, vector<Stop>& stop, vector<Route>& route);////���ļ��������� 

void Operation(int x, vector<Stop>& stop, vector<Route>& route);
void operation0();
void operation1(vector<Stop>& stop, vector<Route>& route);
void operation2(vector<Stop>& stop, vector<Route>& route);

#endif
