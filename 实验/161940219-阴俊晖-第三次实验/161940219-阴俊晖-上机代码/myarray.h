#ifndef _MYARRAY_H_
#define _MYARRAY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INT_MAX 0x3f3f3f3f
#define MAXSIZE 256
#define OK 1
#define PARA_ERROR 0
#define ERROR 0
#define OVERFLOW -1
#define NOTFOUND -1

typedef int Status ;
typedef int Position ;
typedef int ElemType ;
struct List{
	ElemType* data ;
	int size ;
	int length ;
};
typedef struct List List ;
typedef struct List* P_List ;

//1.˳����ʼ�� 
P_List InitList( int size )
{
	P_List L = (P_List)malloc(sizeof(List)) ;
	if( L != NULL )
	{
		L->data = (ElemType*)malloc(size*sizeof(ElemType)) ;
		L->size = size ;
		L->length = 0 ;
	}
	return L ;
}

//2.˳������� 
Status DestroyList( P_List L )
{
	if( L == NULL )
		return PARA_ERROR ;
	else
	{
		free(L->data) ;
		L->data = NULL ;
		L->size = 0 ;
		L->length = 0 ;
		return OK ;
	}
}

//3.˳������
Status ClearList( P_List L )
{
	if( L == NULL )
		return PARA_ERROR ;
	else
	{
		memset( L->data, 0, sizeof(L->data) ) ;
		L->length = 0 ;
		return OK ;
	}
}

//4.�жϱ��Ƿ�Ϊ�� 
Status IsEmpty( P_List L )
{
	return L->length ;
}

//5.���ر���Ԫ�ظ���
int Length( P_List L )
{
	return L->length ;
}

//6.��ȡ���е�i��Ԫ�� 
Status GetElem( P_List L, int i, ElemType* e )
{
	if( L == NULL || i < 1 || i > L->length || e == NULL )
		return PARA_ERROR ;
	else
	{
		*e = L->data[i-1] ;
		return OK ;
	}
}

//7.����ĳԪ��λ�� 
Position FindList( P_List L, ElemType e )
{
	if( L == NULL )
		return PARA_ERROR ;
	else
	{
		int i = 0 ;
		for( ; i < L->length; i++ )
			if( e == L->data[i] )
				return i+1 ;
		
		if( i == L->length )
			return NOTFOUND ;
	}
}

//8.��ȡĳԪ��ǰ�� 
Status PreElem( P_List L, ElemType cur_e, ElemType* pre_e )
{
	if( L == NULL || pre_e == NULL )
		return PARA_ERROR ;
	else
	{
		int i = FindList( L, cur_e ) ;
		if( i == NOTFOUND )
			return ERROR ;
		else if( i == 0 )
			return PARA_ERROR ;
		else
		{
			*pre_e = L->data[--i] ;
			return OK ;
		}
	}
}

//9.��ȡĳԪ�غ�� 
Status NextElem( P_List L, ElemType cur_e, ElemType* next_e )
{
	if( L == NULL || next_e == NULL )
		return PARA_ERROR ;
	else
	{
		int i = FindList( L, cur_e ) ;
		if( i == NOTFOUND )
			return ERROR ;
		else if( i == L->length )
			return PARA_ERROR ;
		else
		{
			*next_e = L->data[++i] ;
			return OK ;
		}
	}
}

//10.������ 
Status ListPrint( P_List L )
{
	if( L == NULL )
		return PARA_ERROR ;
	else{
		printf( "List: " ) ;
		for( int i = 0; i < L->length; i++ )
			printf( "%d ", L->data[i] ) ;
		printf( "\n" ) ;
		return OK ;
	}
}

//11.�޸�Ԫ�� 
Status SetElem( P_List L, int i, ElemType e )
{
	if( L == NULL || i < 1 || i > L->length )
		return PARA_ERROR ;
	else{
		L->data[i-1] = e ;
		return OK ;
	}
}

//12.����Ԫ�� 
Status InsertElem( P_List L, int i, ElemType e )
{
	if( L == NULL || i < 1 )
		return PARA_ERROR ;
	else if( L->length == L->size )
		exit(OVERFLOW) ;
	else
	{
		i-- ;
		if( i == L->length ){
			L->data[i] = e ;
			L->length++ ;
			return OK ;
		}
		
		int j = L->length ;
		for( ; j > i; j-- )
			L->data[j] = L->data[j-1] ;
		L->data[j] = e ;
		L->length++ ;
		return OK ;
	}
}

//13.ɾ��Ԫ�� 
Status DeleteElem( P_List L, Position pos )
{
	if( L == NULL || pos < 1 || pos > L->length )
		return PARA_ERROR ;
	else
	{
		int j = pos ;
		for( ; j < L->length-1 ; j++ )
			L->data[j] = L->data[j+1] ;
		L->length-- ;
		return OK ;
	}
}

//�������� 
void Input( P_List L )
{
	int N ;
	scanf( "%d", &N ) ;
	ElemType elem ;
	for( int i = 1; i <= N; i++ ){
		scanf( "%d", &elem ) ;
		InsertElem( L, i, elem ) ;
	}
}

#endif
