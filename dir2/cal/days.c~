#include<stdio.h>

int number(int year,int month,int day)
{
	int temp,i=0,res=0;
	if((year%4==0 && year%100 != 0)||(year%400 == 0))
		i=1;
	int a=year/4-year/100+year/400;
	res = 365*(year-1) + a;
	printf("result=%d\n",res);
	printf("i=%d\n",i);
	for(temp=1;temp < month;temp++)
	{
		if((temp>=8 && temp%2==0)||(temp<=7 && temp%2==1))
			res += 31;
		else if(temp == 2)
			res += 28+i;
		else
			res += 30;
	}
	res += day;
	printf("result=%d\n",res);
	res = res % 7;
	return res;
}
