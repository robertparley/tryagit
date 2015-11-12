#include <stdio.h>
#include <math.h>

void print(double a[],int r)
{
	printf("static:\n");
	for(;r;)
		printf("%lf\t",a[9-r]);
	printf("\n");
}

int main()
{
	double a,b;
	double c;
 	a=10.0 ;b=5;
	c = log10 (1.0);
	printf("%lf\n",b);
	int m;
	int n=9;
	double tem[10]={55.0,60.0,63.0,65.0,68.3,70.1,73.1,75.1,78.9};
	double pa[10] ={62.20,55.64,48.92,44.33,35.29,30.49,20.90,13.30,-0.0001};
	print(tem,n);
	for(m=0;m<9;m++)
		pa[m]=-pa[m];
	print(pa,n);
	for(m=0;m<9;m++)
		tem[m]=1.0/tem[m];
	for(m=0;m<9;m++);
		pa[m]=log10(pa[m]);
	return 0;
}
