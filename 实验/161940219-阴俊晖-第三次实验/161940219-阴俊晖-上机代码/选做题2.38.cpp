#include <stdio.h>
#include "mylist.h"
	
int N;
int main()
{
	P_List L = InitList() ;
	
	Input(L) ;
	
	DoubleLinked(L) ;
	
	Locate(L, 0);
	Locate(L, 1);
	Locate(L, 0);
	Locate(L, 0);
	Locate(L, -51);
	Locate(L, -51);
	Locate(L, -51);
	Locate(L, 1);
	Locate(L, 23);	
	Locate(L, 1);
	Locate(L, 1);
	
	ListPrint(L);
}

/*
input:
10
-11 -12 7 91 0 5 23 -51 11 1

expected output:
1 -51 0 23 -11 -12 7 91 5 11
*/
