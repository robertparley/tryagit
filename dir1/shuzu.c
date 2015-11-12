#include<stdio.h>
#include<stdlib.h>
int main()
{
	char s[100]="hello world!";
	printf("%s\n",s);
	printf("c=%c\n",s[5]);
	s[12]='s';
	s[13]='d';
	puts(s);
	int i=3;
	printf("input one thing:");
	for(;i;i--)
	{
		scanf("%s",s);
//		scanf("%*[^\n]*c");
		printf("\n%s\n",s);
	}
	return 0;
}
