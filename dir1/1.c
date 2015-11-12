/*************************************
 * 产生含1000个随机数的数组，并排序       *
 *                                   *
 *************************************/

#include<stdlib.h>
#include<stdio.h>
#include<time.h>

void main()
{
//产生随机数组
	time_t ti;
	srand((unsigned int)time(&ti));
	int a[100];
	int i=0,j=0,X=0,temp=0;
	while(i<100)
	{
		a[i]=(rand()%1000);
		i++;
	}	
	while(j<100)
	{
		printf("a[%04d]=%-6d",j,a[j]);
		j++;
		if(j%5==0)
			printf("\n");
	}
/*
//选择排序法	
	for(i=0;i<99;)
	{
		for(j=i+1;j<100;j++)
		{
			if(a[X]>a[j])
				X=j;
		}
		temp=a[X];
		a[X]=a[i];
		a[i]=temp;
		X=++i;
	}

*/
//冒泡排序法
	for(j=0;j<98;j++)
		for(i=0;i+j<99;i++)
		{
			if(a[i]>a[i+1])
			{
				temp=a[i];
				a[i]=a[i+1];
				a[i+1]=temp;
			}
		}


//输出结果
	for(i=0;i<100;i++)
	{
		if(i%5==0)
			putchar('\n');
		printf("a[%03d]=%-5d" ,i,a[i]);
	}

}

