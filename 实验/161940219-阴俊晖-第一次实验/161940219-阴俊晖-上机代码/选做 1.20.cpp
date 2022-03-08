#include <stdio.h>

int Solve( int a[], int i ) ;

int x, n ;
int main()
{
	scanf( "%d%d", &x, &n ) ;
	int a[n] ;
	for( int i = 0; i < n; i++ )
		scanf( "%d", a+i ) ;
	
	printf( "%d", Solve( a, n-1 ) ) ;	
}

int Solve( int a[], int i )
{
	if( i == 0 )
		return a[0] ;
	else
		return Solve( a, i-1 ) * x + a[i] ;
}
/*
3 5
5 3 9 6 5
*/
