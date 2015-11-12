#include <stdio.h>

int main()
{
	double a=5.6;
	double* p = &a;
	double** q = &p;
	printf("&a=%p\tp=%p\t",&a,p);printf("*q=%p",*q);
	printf("*p=%lf\n",*p);
	printf("&p=%p\t",&p);printf("q=%p",q);
	printf("&q=%p\n",&q);
	return 0;
}




/*
int main(int argc,char* argv[])
{
//	int i=atoi(argv[1]);
	if(argv[0]!="thanks")
		printf("wenjianmingbudui\n");
	else
		printf("yes:\n");
	printf("%s  %d\n",argv[1]);
	return 0;
}
*/
