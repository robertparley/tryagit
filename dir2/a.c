#include <stdio.h>

int main()
{
	int a;char b[10];long c;
	printf("abc:");
	scanf(" %[^/]",b);
	printf("int b=%d,char b=%c,string b=%s",b,b,b);
//	printf("int c=%d,char c=%c,string c=%s",c,c,c);
	return 0;
}
