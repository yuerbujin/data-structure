#include <stdio.h>
#include "myarray.h"

void Inter_Set(P_List L1, P_List L2);
void Diff_Set(P_List L1, P_List L2);

int main()
{
	P_List L1 = InitList(MAXSIZE);
	Input(L1);
	P_List L2 = InitList(MAXSIZE);
	Input(L2);
	P_List L3 = InitList(MAXSIZE);
	Input(L3);
	
//	ListPrint(L1);
//	ListPrint(L2);
//	ListPrint(L3);
	
	Inter_Set(L2, L3);// result:  L2 = L2 - L3
	ListPrint( L2 ) ;
	Diff_Set( L1, L2 ) ;// result:  L1 = L1 - L2
	ListPrint( L1 ) ;
}

void Inter_Set( P_List L1, P_List L2 )
{
	Position pos1 = 0;
	Position pos2 = 0;
	
	while (pos1 != L1->length && pos2 != L2->length)
		if (L2->data[pos2] > L1->data[pos1])
			DeleteElem(L1, pos1);
		else if (L2->data[pos2] == L1->data[pos1]){
			pos1++;
			pos2++;
		}
		else if (L2->data[pos2] < L1->data[pos1])
			pos2++;
			
	if (pos2 == L2->length)
		while (pos1 != L1->length)
			DeleteElem(L1, pos1);
}

void Diff_Set( P_List L1, P_List L2 )
{
	Position pos1 = 0;
	Position pos2 = 0;
	
	while (pos1 != L1->length && pos2 != L2->length)
		if (L2->data[pos2] > L1->data[pos1])
			pos1++;
		else if (L2->data[pos2] == L1->data[pos1])
			DeleteElem(L1, pos1);
		else if (L2->data[pos2] < L1->data[pos1])
			pos2++;
}

/*
input:
10 
-78 -55 -55 -55 -4 -1 0 0 47 81
6
-55 -55 -54 0 19 81
7 
-55 -54 -53 -4 0 0 47
*/

/*
expected output:
-78 -4 -1 47 81
*/
