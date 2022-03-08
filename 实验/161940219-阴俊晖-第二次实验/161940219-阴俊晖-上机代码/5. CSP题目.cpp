#include <stdio.h>
#include <string.h>
#define MAXSIZE 256
#define ON 1
#define OFF 2

void Solve() ;

int n ;
int H[MAXSIZE] ;
int main()
{
	scanf( "%d", &n ) ;
	memset( H, OFF, sizeof(H) ) ;
	
	int start, end, time = 0 ;
	for( int i = 1; i <= n; i++ )
	{
		scanf( "%d%d", &start, &end ) ;
		for( int i = start; i <= end-1; i++ )
			H[i] = ON ;
	}

	for( int i = 1; i <= n; i++ )
	{
		scanf( "%d%d", &start, &end ) ;
		for( int i = start; i <= end-1 ; i++ )
			if( H[i] == ON )
				time++ ;
	}
	
	printf( "%d", time ) ;
}
