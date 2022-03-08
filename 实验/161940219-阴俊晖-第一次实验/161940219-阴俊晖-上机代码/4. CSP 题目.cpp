#include <stdio.h>

int WaitCost( int k, int t, int sum ) ;

int red, yellow, green, cycle ;
int main()
{
	int N, k, t, sum = 0 ;
	
	scanf( "%d%d%d%d", &red, &yellow, &green, &N ) ;
	cycle = red + yellow + green ;
	
	for( int i = 1; i <= N; i++ )
	{
		scanf( "%d%d", &k, &t ) ;
		if( k == 0 )
			sum += t ;
		else
			sum += WaitCost( k, t, sum ) ;
	}
	
	printf( "%d", sum ) ;
}

//以绿黄红为一周期
int WaitCost( int k, int t, int sum )
{
	int begin, now ;
	if( k == 1 )
		begin = red + yellow + green - t ;
	else if( k == 2 )
		begin = green + yellow - t ;
	else if( k == 3 )
		begin = green - t ;
	
	now = (begin + sum) % cycle ;
	
	if( 0 <= now && now < green+yellow )
		return 0 ;
	else if( green+yellow <= now && now <= cycle )
		return cycle - now ;
}
