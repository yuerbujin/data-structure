#include <stdio.h>
#include <string.h>
#define MAXSIZE 256

void Solve() ;
void Print() ;

int N, T = 0, D = 0, E = 0 ;
int Trees[MAXSIZE], get[MAXSIZE], loss[MAXSIZE] ;
int main()
{
	scanf( "%d", &N ) ;
	
	Solve() ;
	
	Print() ;
}

void Solve()
{
	memset( get, 0, sizeof(get) ) ;
	memset( loss, 0, sizeof(loss) ) ;
	
	int m, input ;
	for( int i = 1; i <= N; i++ )
	{
		scanf( "%d", &m ) ;
		
		for( int j = 1; j <= m; j++ )
		{
			scanf( "%d", &input ) ;
			if( j == 1 )
				Trees[i] = input ; //Trees[0]Œﬁƒ⁄»› 
			else if( input <= 0 )
				get[i] += -input ;
			else
				loss[i] = Trees[i] - get[i] - input ;
		}
	}
}

void Print()
{
	int flag1, flag2 ;
	flag1 = flag2 = 0 ;
	
	for( int i = 1; i <= N; i++ )
	{
		T += Trees[i] - get[i] - loss[i] ;	//À„T 
		
		if( loss[i] > 0 ){
			D++ ;							//À„D 
			if( flag1 == 0 )
				flag1 = 1 ;
			else if( flag2 == 0 )
				flag2 = 1 ;
			else
				E++ ;						//À„E 
		}
		else
			flag1 = flag2 = 0 ;
	}
	
	for( int i = 1; i <= 2; i++ )
	{
		if( loss[i] > 0 ){
			if( flag1 == 0 )
				flag1 = 1 ;
			else if( flag2 == 0 )
				flag2 = 1 ;
			else
				E++ ;
		}
		else
			flag1 = flag2 = 0 ;
	}
	
	printf( "%d %d %d", T, D, E ) ;
}
