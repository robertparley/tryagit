#include<stdio.h>
#include<time.h>
#include<string.h>
//倒序输出字符串

/*
int main1()
{
	char str[50],t;
	puts("input a string please:");
	scanf("%s",str);
	int l=strlen(str);
	printf("%d\n",l);
	for(int i=l/2-1;i>=0;i--)
	{
		t = str[i];
		str[i]=str[l-i-1];
		str[l-i-1]=t;
	}
	printf("result is:\n%s",str);
	return 0;
}
*/

//按大小排列小数

/*
int main()
{
	double a[10]={0},t=0;
	srand((unsigned)time(NULL));
	for(int j=10;j;j--)
	{
		a[j-1]=(double)(rand()%100000);
		a[j-1] /=100;
	}
	puts("before");
	for(int j=0;j<10;j++)
		printf("%lf\n",a[j]);
	for(int i=0;i<9;i++)
	{
		for(int j=0;i+j<9;j++)
		{
			if(a[j]>a[j+1])
			{
				a[j] += a[j+1];
				a[j+1] = a[j] - a[j+1];
				a[j] -= a[j+1];
			}
		}
	}
	puts("after");
	for(int i=9;i>=0;i--)
	{
		printf("%lf\n",a[i]);
	}
	return 0;
}

*/

//商品的统计和排序
//unfinished
int main()
{
	typedef struct sale{
		char name[30];
		double price;
		int num;
		char prin[30];
	}sale;
	int t=0;
	sale s[3]={
		{"apple",1.2,18,"Guangdong"},
		{"banana",6.4,10,"Jilin"},
		{"pencil",1.0,100,"Tianjin"}
	};
	int i=0;
	for(i=0;i<3;i++)
	{
		printf("有%d千克单价为%g产自%s的%s\n",
					s[i].num,s[i].price,s[i].prin,s[i].name);
	}
	puts("按单价排序：");
		for(i=0;i<3;i++)
		{
			if(s[i].price>s[t].price)
				t=i;
		}
	return 0;
}
