#include <iostream>
#include <list>

using namespace std;

struct Window{
	int x1, y1;
	int x2, y2;
	int No;//窗口编号 
};

typedef list<Window>::iterator Position;

void readWindows(list<Window>& list);
void clickWindows(list<Window>& list);
void click(int x, int y, list<Window>& list);
bool In(int x, int y, Window& window); 

int N, M;

int main()
{
	list<Window> list;//存放窗口 
	
	readWindows(list);//读入窗口 
	
	clickWindows(list);//点击窗口并输出结果 
}

void readWindows(list<Window>& list)
{
	cin >> N >> M;
	Window window;
	
	for (int i = 1; i <= N; i++)//输入N个窗口 
	{
		cin >> window.x1
			>> window.y1
			>> window.x2
			>> window.y2;
			
		window.No = i;
		list.push_front(window);
	}
}

void clickWindows(list<Window>& list)//一次循环一次点击 
{
	int x, y;
	for (int i = 1; i <= M; i++)//M次点击 
	{
		cin >> x >> y;
		click(x, y, list);
	}
}

void click(int x, int y, list<Window>& list)
{
	Position iter = list.begin();
		
	for ( ; iter != list.end();)
	{
		//注意erase()的使用 
		if (In(x, y, *iter))//如果击中 
		{
			cout << iter->No << endl;
			list.push_front(*iter);
			iter = list.erase(iter);//返回删除结点下一个位置的迭代器 
			
			return;//本次点击结束 
		}
		else
		{
			iter++;
		}
	}
	
	if (iter == list.end())
		cout << "IGNORED" << endl;
}

bool In(int x, int y, Window& window)//是否点击中窗口 
{
	return (	(x >= window.x1)
			&&	(y >= window.y1)
			&&	(x <= window.x2)
			&&	(y <= window.y2)	);
}

/*
input sample1:
3 4
0 0 4 4
1 1 5 5
2 2 6 6
1 1
0 0
4 4
0 5

output sample1:
2
1
1
IGNORED

input sample2:

output sample2:

input sample3:

output sample3:

*/
