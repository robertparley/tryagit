#include <stdio.h>

int fibon(int n)
{
	if((n==1)||(n==2))
		return 1;
	return fibon(n-1)+fibon(n-2);
}

int main()
{
	printf("fibon=%d\n",fibon(4));
	return 0;
}
