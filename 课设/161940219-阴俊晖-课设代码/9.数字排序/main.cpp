#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

struct Bucket{
	int num;
	int times;
	
	Bucket(int numIn, int timesIn): num(numIn), times(timesIn){}
};

bool myCmp(const Bucket& b1, const Bucket& b2)//Ωµ–Ú 
{
	return b1.times > b2.times;
}

int N, M;
int main()
{
	cin >> N;
	vector<Bucket> buckets;
	for (int i = 0; i <= N; i++)
	{
		buckets.push_back(Bucket(i, 0));
	}
	
	int num;
	for (int i = 1; i <= N; i++)
	{
		cin >> num;
		buckets[num].times++;
	}
	
	stable_sort(buckets.begin(), buckets.end(), myCmp);// µœ÷Œ»∂®≈≈–Ú 
	
	for (int i = 0; i < N; i++)
	{
		if (buckets[i].times != 0)
			cout << buckets[i].num << " " << buckets[i].times << endl;
	}
}

/*
input sample1:
12
5 2 3 3 1 3 4 2 5 2 3 5

output sample1:
3 4
2 3
5 3
1 1
4 1

input sample2:

output sample2:

input sample3:

output sample3:

*/
