#include<stdio.h>
#include<stdlib.h>

int main()
{
	int num=0,t1=0,t2=1;
	while(num<1 || num>9)
	{
	printf("请输入1-9，输出对应乘法表行：");
	scanf("%d",&num);
	}
	t1=num;
	for(t2;t2<=num;t2++)
	printf("%d*%d=%-2d, ",t2,num,t2*num);
	putchar('\n');
	return 0;
}
