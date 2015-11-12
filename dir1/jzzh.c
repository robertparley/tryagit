/****************************
 * 将十进制数值显示为二进制	*
 ****************************/

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int num = 0;
	printf("请输入数值：");
	scanf("%d",&num);
	int t1 = num;
	printf("%d的二进制表示为：",num);
	int i =0 , j = 1 ;
	for(i ; t1 != 0 ; i++)
	{
		t1 /= 2 ;
		j = j*2;
	}
	for(i;i;i--)
	{
		j>>=1;
		if((j&num) == 0)
			printf("0");
		else
			printf("1");
	}
	putchar('\n');
	return 0;
}
