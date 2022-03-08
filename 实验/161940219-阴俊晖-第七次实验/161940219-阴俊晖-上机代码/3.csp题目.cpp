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

int board[MAX_ROW][MAX_COL];//���� 

int main()
{
	int times;
	cin >> times;
	
	for (int i = 1; i <= times; i++)
	{
		readIn();//����ԭ���� 
		
		int score;
		if (over(score))//ʤ���ѷ� 
		{
			cout << score << endl;
		}
		else//ʤ��δ�֣��������� 
		{
			score = traversal(Alice);
			cout << score << endl;
		}
	}
}

void readIn()//����ԭ���� 
{
	for (int i = 0; i < MAX_ROW; i++)
		for (int j = 0; j < MAX_COL; j++)
			cin >> board[i][j];
}

//һ������������ͬ 
bool vertical(Person& person)//person����ʤ���� 
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

//һ������������ͬ 
bool horizontal(Person& person)//person����ʤ���� 
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

//�Խ�������������ͬ 
bool diagonal(Person& person)//person����ʤ���� 
{
	//�ж����Խ��� 
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
	
	//�жϸ��Խ��� 
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

int curZero()//��ǰ�ո�����Ŀ 
{
	int cnt = 0;
	for (int i = 0; i < MAX_ROW; i++)
		for (int j = 0; j < MAX_COL; j++)
			if (board[i][j] == Nobody)
				cnt++;
	
	return cnt;
}

bool over(int& score)//�ж���Ϸ�Ƿ��������ͨ��score���ص÷� 
{
	Person person;
	if (vertical(person) || horizontal(person) || diagonal(person))//һ��ʤ�� 
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
	else if (curZero() == 0)//ƽ�� 
	{
		score = 0;
		return true;
	}
	else//��Ϸδ���� 
		return false;
}

int traversal(Person person)//��ǰ��˭���� 
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
				if (over(score))//������������ص÷� 
				{
					board[i][j] = Nobody;//���� 
					
					return score; 
				}
				else//�������壬���µ�ǰ��ֵ 
				{
					if (person == Alice)
						curMax = max(curMax, traversal(Bob));
					else
						curMin = min(curMin, traversal(Alice));
				}
				
				board[i][j] = Nobody;//���� 
			}
		}
	
	//��������������� 
	if (person == Alice)
		return curMax;
	else
		return curMin;
}
