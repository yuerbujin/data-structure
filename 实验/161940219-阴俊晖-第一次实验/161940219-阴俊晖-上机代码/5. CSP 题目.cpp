#include <stdio.h>

int main()
{
	int pos, score, lastscore, sum = 0, flag = 0 ;
	
	while(1){
		scanf( "%d", &pos ) ;
		if( pos == 0 )
			break ;
		else if( pos == 1 ){
			score = 1 ;
			sum += score ;
			flag = 0 ;
		}
		else if( pos == 2 )
		{
			if( flag == 0 ){
				score = 2 ;
				sum += score ;
			}
			else{
				score += 2 ;
				sum += score ;
			}
			flag = 1 ;
		}
	}
		
	
	printf( "%d", sum ) ;
}
