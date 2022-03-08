#include <stdio.h>
#include <stdlib.h>
#define MAXINT 65536
#define ARRSIZE 100

int a[ARRSIZE] ;

void Print( int length )
{
	printf( "a[...]: " ) ;
	for( int i = 0; i < length; i++ )
		printf( "%d ", a[i] ) ;
}

void Error( int length = 0 )
{
	printf( "ERROR!\n\n" ) ;
	Print(length) ;
	exit(1) ;
}

int main()
{
	int n ;
	scanf( "%d", &n ) ;
	if( n > ARRSIZE )
		Error() ;
	
	if( n <= 0 )
		return 0 ;
	else{
		int tem = 2 ;
		if( tem > MAXINT )
			Error() ;
		else
			a[0] = tem ;
		
		int i = 1;
		for( ; i <= n; i++ )
		{
			tem = a[i-1]* (i+1) * 2 ;
			if( tem > MAXINT )
				Error(i) ;
			else
				a[i] = tem ;
		}
		
		if( i == n+1 )
			Print(i-1) ;
	}
}
