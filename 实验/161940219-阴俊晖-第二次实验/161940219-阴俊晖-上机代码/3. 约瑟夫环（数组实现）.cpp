#include <stdio.h>
#include <string.h>
#define MAXSIZE 16 

void Solve() ;

int N, M ;
int a[MAXSIZE] ;
int main()
{
	for( int i = 1; i < MAXSIZE; i++ ) 
		a[i] = i ;
		
	scanf( "%d%d", &N, &M ) ;
	
	Solve() ;
}

void Solve()
{
	int num = N ;
	int out[N] ;
	memset( out, false, sizeof(out) ) ;
	
	int m = 1 ;
	int pos = 1 ;
	while( num != 0 )//¼ì²éa[pos]
	{
		if( pos > N )
			pos = 1 ;
			
		if( !out[pos] )
		{
			if( m == M ){
				printf( "%d ", a[pos] ) ;
				m = 1 ;
				out[pos] = true ;
				num-- ;
			}
			else
				m++ ;
		}
		
		pos++ ;
	}
}
/*
5 3
*/
/*
1 2 3 4 5
*/
