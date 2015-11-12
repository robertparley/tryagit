#include<stdio.h>
#include<string.h>
/*	1.验证可否直接输出struct类型（不可，可逐项输出）；
 *	2.未初始化的struct数据初值
 *			类似数组，{}方式赋初值则余下添0，各个单独赋值则乱码；
 */
int main()
{
	int a=0;
	struct person
	{
		int a;
		char name[30];
	};
	struct person ba[3];
	strcpy(ba[0].name,"john");
	ba[0].a=6;
	printf("%d岁的%s\n",ba[0].a,ba[0].name);
	printf("%d岁的%s\n",ba[2].a,ba[2].name);
	return 0;
}
