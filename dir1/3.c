#include<stdio.h>

int main()
{
	printf("4^5=%d\n~20=%d\n",4^5,~20);
	printf("-2 %d\n",~-2);
	printf("-1 %d\n 0 %d\n 1 %d\n2 %d\n",~-1,~0,~1,~2);
	int a=0x12,b=0x34,c=0x56;
	int d=0;
	d=(a<<16)+(b<<8)+c;
	printf("%x\n",d);
	return 0;
}
