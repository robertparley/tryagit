#include<stdio.h>
#include<stdlib.h>

int get(int a,int b)
{
	unsigned int x;
	scanf("%u",&x);
	srand(x);
	if(a>=b)
		return 0;
	int c;
	c = (rand()%(b-a))+a;
	return c;
}

int main()
{
	int m=get(5,10),n=(10,47);
	printf("%d,%d\n",m,n);
	return 0;
}
