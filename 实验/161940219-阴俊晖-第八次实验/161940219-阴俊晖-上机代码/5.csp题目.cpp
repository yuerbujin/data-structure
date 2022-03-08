#include <iostream>
#include <set>
#include <string.h>
using namespace std;

//À¬»øÎ»ÖÃ 
struct Point{
	int x;
	int y;
	
	Point(int xIn, int yIn): x(xIn), y(yIn){}
	bool operator <(const Point& point) const{
		if (x != point.x)
			return x < point.x;
		else
			return y < point.y;
	}
};

int N;
set<Point> graph;//´æ´¢À¬»øÍ¼ 
int score[5];//ÆÀ·Ö½á¹û

bool findPoint(const Point& point)
{
	if (graph.find(point) != graph.end())
		return true;
	else
		return false;
}

int main()
{
	memset(score, 0, sizeof(score));
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		int x, y;
		cin >> x >> y;
		graph.insert(Point(x, y));//½¨Í¼ 
	}
	
	auto iter = graph.begin();
	for (; iter != graph.end(); iter++)
	{
		int x = iter->x;
		int y = iter->y;
		if (findPoint(Point(x-1, y)) && findPoint(Point(x+1, y)) &&
			findPoint(Point(x, y-1)) && findPoint(Point(x, y+1)))
		{
			int cnt = 0;
			if (findPoint(Point(x-1, y-1)))
				cnt++;
			if (findPoint(Point(x-1, y+1)))
				cnt++;
			if (findPoint(Point(x+1, y-1)))
				cnt++;
			if (findPoint(Point(x+1, y+1)))
				cnt++;
				
			score[cnt]++;
		}
	}
	
	for (int i = 0; i < 5; i++)
		cout << score[i] << endl;
}

/*
input sample1:
7
1 2
2 1
0 0
1 1
1 0
2 0
0 1

output sample1:
0
0
1
0
0

input sample2:
2
0 0
-100000 10

output sample2:
0
0
0
0
0

input sample3:
11
9 10
10 10
11 10
12 10
13 10
11 9
11 8
12 9
10 9
10 11
12 11

output sample3:
0
2
1
0
0

*/
