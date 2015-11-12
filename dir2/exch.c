#include <stdio.h>

void swap(int a[],int n)
{
	int i=0,t=0;
	for(;i<n/2;i++)
	{
		t=a[i];
		int r;
		a[i]=a[n-i-1];
		a[n-i-1]=t;
	}
}
int main()
{
	int a[5]={1,2,3,4,5};
	int j=0;
	for(j=0;j<5;j++)
		printf("%d\t",a[j]);
	swap(a,5);
	printf("\n");
	for(j=0;j<5;j++)
		printf("%d\t",a[j]);
	return 0;
}
