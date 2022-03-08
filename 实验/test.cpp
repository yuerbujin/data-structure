#include<iostream>
#include<stdlib.h>
#define MAXINT 65535
#define ArrSize 100
using namespace std ;
int fun(int i);

int main()
{
	int i,k;
	int a[ArrSize];
	cout<<"Enter k:";
	cin>>k;
	if(k>ArrSize-1) exit(0);
	for(i=0;i<=k;i++){
		if(i==0) a[i]=1;
		else{
			if(2*i*a[i-1]>MAXINT) exit(0);
			else a[i]=2*i*a[i-1];
		}
	}
	for(i=0;i<=k;i++){
		if(a[i]>MAXINT) exit(0);
		else cout<<a[i]<<" ";
	}
	return 0;
}

