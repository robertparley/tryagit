#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char a[20],b[20];
	int A=0;
	strcpy(a,"yes,it is!");
	strcpy(b,a);
	strcat(b,"b");
	*(b+12)='a';
	printf("a=%s , b=%s\n",a,b);
	printf("a==b:%d\n",a==b);
	return 0;
}
