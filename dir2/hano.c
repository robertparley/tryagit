#include <stdio.h>

void hano(char from,int n,char to,char spare)
{
	if(n>0)
	{
		hano(from,n-1,spare,to);
		printf("move %d %c==>%c \n", n , from, to);
		hano(spare,n-1,from,to);
	}
}
void pin(int num)
{
	if(num>9)
	{
		pin(num/10);
	}
	printf("%d",num%10);
}

int main()
{
//	hano('a',3,'b','c');
	pin(12345);
	return 0;
}
