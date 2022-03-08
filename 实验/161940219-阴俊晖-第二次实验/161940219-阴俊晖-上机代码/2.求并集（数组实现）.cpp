#include <stdio.h>
#include "myarray.h"

void Union( P_List L1, P_List L2 ) ;

int main()
{
	P_List L1 = InitList(MAXSIZE) ;
	Input( L1 ) ;
	P_List L2 = InitList(MAXSIZE) ;
	Input( L2 ) ;

//	ListPrint( L1 ) ;
//	ListPrint( L2 ) ;
	Union( L1, L2 ) ;
	ListPrint( L1 ) ;
}

void Union( P_List L1, P_List L2 )
{
	Position pos1 = 0; 
	Position pos2 = 0; 
	
	while (pos1 < L1->length && pos2 < L2->length){
		if (L2->data[pos2] > L1->data[pos1]){
			InsertElem( L1, pos1+1, L2->data[pos2] );
			pos2++;
		}
		else if (L2->data[pos2] == L1->data[pos1]){
			pos1++;
			pos2++;
		}
		else if (L2->data[pos2] < L1->data[pos1]){
			pos1++;
		}
	}
	
	if (pos1 == L1->length)
		while (pos2 != L2->length)
		{
			InsertElem(L1, pos1+1, L2->data[pos2]);
			pos1++;
			pos2++;
		}
}
/*
5 
84 7 0 -1 -4
7 
81 51 -1 -4 -5 -77 -78
*/ 
