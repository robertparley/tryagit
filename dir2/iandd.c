#include <stdio.h>

struct date{
	int year;
	int month;
	int day;
};

struct date inttodate()
{
	int a;
	printf("ok,please input:");
	scanf(" %d",&a);
	struct date d;
	d.year = a/10000;
	d.month = a/100%100;
	d.day = a%100;
	printf("date:%d-%d-%d\n",d.year,d.month,d.day);
	return d;
}

int datetoint()
{
	struct date d;
	unsigned long a;
	printf("ok,please input(e.g.2015/01/01):");
	scanf(" %d",&d.year);scanf("%*c");
	scanf(" %d",&d.month);scanf("%*c");
	scanf(" %d",&d.day);scanf("%*c");
	printf("\nyear=%d,month=%d,day=%d\n",d.year,d.month,d.day);
	a=d.year*10000+d.month*100+d.day;
	printf("int:%d\n",a);
	return a;
}

int main()
{
	struct date d;
	int a;
	printf("please choose :\n\t1--number\n\t2--date\n");
	scanf("%d",&a);
	if(a==1)
		inttodate();
	else if(a==2)
		datetoint();
	else
		printf("error!\n");
	return 0;
}
