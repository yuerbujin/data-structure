#include <iostream> 
#include <algorithm>

#define MAX_COL 3
#define MAX_ROW 3

using namespace std;

enum Person{
	Nobody = 0,
	Alice = 1, 
	Bob = 2
}; 

void readIn();
bool over(int& score);
int curZero();
int traversal(Person person);

int board[MAX_ROW][MAX_COL];//棋盘 

int main()
{
	int times;
	cin >> times;
	
	for (int i = 1; i <= times; i++)
	{
		readIn();//读入原棋盘 
		
		int score;
		if (over(score))//胜负已分 
		{
			cout << score << endl;
		}
		else//胜负未分，继续下棋 
		{
			score = traversal(Alice);
			cout << score << endl;
		}
	}
}

void readIn()//读入原棋盘 
{
	for (int i = 0; i < MAX_ROW; i++)
		for (int j = 0; j < MAX_COL; j++)
			cin >> board[i][j];
}

//一列三个棋子相同 
bool vertical(Person& person)//person返回胜出者 
{
	for (int col = 0; col < MAX_COL; col++)
	{
		if ((board[0][col] == board[1][col]) &&
			(board[1][col] == board[2][col]) &&
			(board[0][col] == Alice)	)
		{
			person = Alice;
			return true; 
		}
		if ((board[0][col] == board[1][col]) &&
			(board[1][col] == board[2][col]) &&
			(board[0][col] == Bob)) 
		{
			person = Bob;
			return true; 
		}
	}
	
	return false;
}

//一行三个棋子相同 
bool horizontal(Person& person)//person返回胜出者 
{
	for (int row = 0; row < MAX_ROW; row++)
	{
		if ((board[row][0] == board[row][1]) &&
			(board[row][1] == board[row][2]) &&
			(board[row][0] == Alice)	)
		{
			person = Alice;
			return true; 
		}
		if ((board[row][0] == board[row][1]) &&
			(board[row][1] == board[row][2]) &&
			(board[row][0] == Bob)	)
		{
			person = Bob;
			return true; 
		}
	}
	
	return false;
}

//对角线三个棋子相同 
bool diagonal(Person& person)//person返回胜出者 
{
	//判断主对角线 
	if ((board[0][0] == board[1][1]) &&
		(board[1][1] == board[2][2]) &&
		(board[0][0] == Alice))
	{
		person = Alice;
		return true; 
	}
	if ((board[0][0] == board[1][1]) &&
		(board[1][1] == board[2][2]) &&
		(board[0][0] == Bob))
	{
		person = Bob;
		return true; 
	}
	
	//判断副对角线 
	if ((board[0][2] == board[1][1]) &&
		(board[1][1] == board[2][0]) &&
		(board[0][2] == Alice))
	{
		person = Alice;
		return true; 
	}
	if ((board[0][2] == board[1][1]) &&
		(board[1][1] == board[2][0]) &&
		(board[0][2] == Bob))
	{
		person = Bob;	
		return true; 
	}
	
	return false;
}

int curZero()//当前空格子数目 
{
	int cnt = 0;
	for (int i = 0; i < MAX_ROW; i++)
		for (int j = 0; j < MAX_COL; j++)
			if (board[i][j] == Nobody)
				cnt++;
	
	return cnt;
}

bool over(int& score)//判断游戏是否结束，并通过score返回得分 
{
	Person person;
	if (vertical(person) || horizontal(person) || diagonal(person))//一方胜出 
	{
		if (person == Alice)
		{
			score = curZero() + 1;
			return true;
		}
		else if (person == Bob)
		{
			score = -(curZero() + 1);
			return true;
		}
	}
	else if (curZero() == 0)//平局 
	{
		score = 0;
		return true;
	}
	else//游戏未结束 
		return false;
}

int traversal(Person person)//当前轮谁行棋 
{	
	int curMax = -10;
	int curMin = 10;
	
	for (int i = 0; i < MAX_ROW; i++)
		for (int j = 0; j < MAX_COL; j++)
		{
			if (board[i][j] == Nobody)
			{
				board[i][j] = person;
				
				int score;
				if (over(score))//下棋结束，返回得分 
				{
					board[i][j] = Nobody;//回溯 
					
					return score; 
				}
				else//继续下棋，更新当前最值 
				{
					if (person == Alice)
						curMax = max(curMax, traversal(Bob));
					else
						curMin = min(curMin, traversal(Alice));
				}
				
				board[i][j] = Nobody;//回溯 
			}
		}
	
	//所有情况遍历结束 
	if (person == Alice)
		return curMax;
	else
		return curMin;
}
