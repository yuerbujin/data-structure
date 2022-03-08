#include <stdio.h>
#include <math.h>
#include "myarray.h"

void Bubble_Sort( P_List L ) ;
void Find(P_List L);

int main()
{
	P_List L = InitList(MAXSIZE) ;
	
	Input(L); 
	
	Bubble_Sort(L) ;
	
	Find(L);
}

void Swap( ElemType* e1, ElemType* e2 )
{
	ElemType tem = *e1 ;
	*e1 = *e2 ;
	*e2 = tem ;
}

void Bubble_Sort( P_List L )
{
	if( L->length == 0 || L->length == 1 )
		return ;
	else
		for( Position i = 0; i < L->length-1; i++ )
			for( Position j = 0; j < L->length-1-i; j++ )
				if( L->data[j] > L->data[j+1] )
					Swap( &L->data[j], &L->data[j+1] ) ;
					
}

void Find(P_List L)
{
	int min = INT_MAX;
	for (Position i = 0; i < L->length-1; i++)
	{
		int diff = abs(L->data[i] - L->data[i+1]);
		if (diff < min)
			min = diff;
	}
	
	printf("%d", min);
}

/*
10
61 -12 -13 5 7 61 0 0 61 -12
*/
