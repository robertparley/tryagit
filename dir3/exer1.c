#include <stdio.h>
#include <string.h>

//判断是否是整数字符串
int isdig(char* p)
{
	int i=0;
	if(*p=='+'||*p=='-')
		i=1;
	for(i;i<strlen(p);i++)
	{
		if(*(p+i)<'0'||*(p+i)>'9')
			return 0;
	}
	return 1;
}

//判断是否是实数字符串
int isnum(char* p)
{
	int i=0;
	if(*p=='+'||*p=='-')
		i=1;
	for(i;i<strlen(p);i++)
	{
		if(*(p+i)=='.')
			continue;
		if(*(p+i)<'0'||*(p+i)>'9')
			return 0;
	}
	return 1;
}

//分割字符输出
void strcut(char* p,char c)
{
	char* q[10]={NULL};
	int i,j=1;
	q[0]=p;
	printf("%s\n",q[0]);
	for(i=1;i<=strlen(p);i++)
	{
		if(p[i]==c){q[j]=&p[i]+1;j++;}
	}
	p=q[0];
	int k=strlen(p);
	for(i=0;i<=k;i++)
	{
		if(*(p+i)==c){
			*(&p[i])='\0';
		}	}

	for(k=0;k<j;k++)
	{
		printf("%s\n",q[k]);
	}
}

//寻找重复字符，返回长度
int findpa(char* p)
{
	const char* a = NULL;
	const char* b = NULL;
	a = p;
	int i=0,j=0,k=0,max=0;
	for(i=0;i<strlen(p);i++)
	{
		for(j=i+1;j<strlen(p);j++)
		{
			if(a[i]==p[j])
				for(k=0;j+k<=strlen(p);k++)
				{
					if(a[i+k]!=p[j+k])
						break;
				}
			if(max<k)
				if(p+j-a-i>=max)
					{
						b = &a[i];
						max=k;
					}
		}
	}
	for(k=0;k<max;k++)
		printf("%c",b[k]);
		
	return max;
}

int main()
{
	char a[100]="abdls:sidfl:adb:sdf:sdf";
	char b[100]="stringabcstringiklikeitabc";
	char c[100];
	printf("input:");
	scanf(" %s",c);
	printf("\nmax=%d\n",findpa(c));
	return 0;
}
