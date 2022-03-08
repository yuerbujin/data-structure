#include <stdio.h>
#include "mylist.h"

void Inter_Set(P_List L1, P_List L2);
void Diff_Set(P_List L1, P_List L2);

int main()
{
	P_List L1 = InitList() ;
	Input( L1 ) ;
	P_List L2 = InitList() ;
	Input( L2 ) ;
	P_List L3 = InitList() ;
	Input( L3 ) ;
	
	Inter_Set(L2, L3);// result:  L2 = L2 - L3
//	ListPrint( L2 ) ;
	Diff_Set( L1, L2 ) ;// result:  L1 = L1 - L2
	ListPrint( L1 ) ;
}

void Inter_Set( P_List L1, P_List L2 )
{
	P_LNode p1 = L1->head ; 
	P_LNode p2 = L2->head ;
	
	while (p1->next != NULL && p2->next != NULL)
		if (p2->next->data > p1->next->data)
			DeleteElem(L1, p1->next);
		else if (p2->next->data == p1->next->data){
			p1 = p1->next;
			p2 = p2->next; 
		}
		else if (p2->next->data < p1->next->data)
			p2 = p2->next;
			
	if (p2->next == NULL)
		while (p1->next != NULL)
			DeleteElem(L1, p1->next);
}

void Diff_Set( P_List L1, P_List L2 )
{
	P_LNode p1 = L1->head;
	P_LNode p2 = L2->head;
	
	while (p1->next != NULL && p2->next != NULL)
		if (p2->next->data > p1->next->data)
			p1 = p1->next;
		else if (p2->next->data == p1->next->data)
			DeleteElem(L1, p1->next);
		else if (p2->next->data < p1->next->data)
			p2 = p2->next;
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
