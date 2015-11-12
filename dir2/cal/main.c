#include "calen.h"

int main()
{
	int i,a[3]={0};
A:	printf("请输入日期（年/月/日/）：\n");
	for(i=3;i;i--)
	{
		if(scanf("%d",&a[i-1])!=1)
			break;
		scanf("%*[^/]");scanf("%*c");
	}

	i=check(a[2],a[1],a[0]);
	if(i != 0)
	{
		scanf("%*[^\n]");scanf("%*c");
		printf("error!\n");
		goto A;
	}
	i=number(a[2],a[1],a[0]);
	switch(i){
		case 1:
			printf("这一天是星期一\n");
			break;
		case 2:
			printf("这一天是星期二\n");
			break;
		case 3:
			printf("这一天是星期三\n");
			break;
		case 4:
			printf("这一天是星期四\n");
			break;
		case 5:
			printf("这一天是星期五\n");
			break;
		case 6:
			printf("这一天是星期六\n");
			break;
		case 0:
			printf("这一天是星期日\n");
			break;
		default:
			printf("这是个神奇的日子\n");
	}
	return 0;
}

