#include<stdio.h>

int main()
{
	short a=2,b=5;
	short c;
	c=a+b;
	printf("%d,%d,%d\n",sizeof(short),sizeof(int),sizeof((short)(a+b)));
	return 0;
}
