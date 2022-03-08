#include <iostream>
#include <list>

using namespace std;

struct Window{
	int x1, y1;
	int x2, y2;
	int No;//���ڱ�� 
};

typedef list<Window>::iterator Position;

void readWindows(list<Window>& list);
void clickWindows(list<Window>& list);
void click(int x, int y, list<Window>& list);
bool In(int x, int y, Window& window); 

int N, M;

int main()
{
	list<Window> list;//��Ŵ��� 
	
	readWindows(list);//���봰�� 
	
	clickWindows(list);//������ڲ������� 
}

void readWindows(list<Window>& list)
{
	cin >> N >> M;
	Window window;
	
	for (int i = 1; i <= N; i++)//����N������ 
	{
		cin >> window.x1
			>> window.y1
			>> window.x2
			>> window.y2;
			
		window.No = i;
		list.push_front(window);
	}
}

void clickWindows(list<Window>& list)//һ��ѭ��һ�ε�� 
{
	int x, y;
	for (int i = 1; i <= M; i++)//M�ε�� 
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
		//ע��erase()��ʹ�� 
		if (In(x, y, *iter))//������� 
		{
			cout << iter->No << endl;
			list.push_front(*iter);
			iter = list.erase(iter);//����ɾ�������һ��λ�õĵ����� 
			
			return;//���ε������ 
		}
		else
		{
			iter++;
		}
	}
	
	if (iter == list.end())
		cout << "IGNORED" << endl;
}

bool In(int x, int y, Window& window)//�Ƿ����д��� 
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
