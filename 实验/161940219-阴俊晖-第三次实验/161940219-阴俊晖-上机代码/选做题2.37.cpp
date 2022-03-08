#include <stdio.h>
#include "mylist.h"

void Transform(P_List L);
	
int N;
int main()
{
	P_List L = InitList() ;
	
	Input(L) ;
	
	DoubleLinked(L) ;
	
	Transform(L);
	
	ListPrint(L);
}

void Transform(P_List L)
{
	Position p1 = L->head->next;
	Position org_rear = L->rear;	
	
	for (int i = 1; i <= L->length; i++)
	{
		if (i % 2 == 0)
		{
			//删除并插入
			Position tem = p1;
			p1 = p1->next;
			InsertElem(L, org_rear, tem->data);
			DeleteElem(L, tem);
		}
		else{
			//无操作
			p1 = p1->next;
		}
	}
}

/*
input:
10
61 -12 -13 5 7 61 0 0 61 -12

expected output:
61 -13 7 0 61 -12 5 61 0 -12
*/
