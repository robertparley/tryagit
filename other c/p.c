#include <stdio.h>
#include <math.h>

void writ(const double a[],char name[])
{
	FILE* f = fopen(name,"w");
	int t=0;
	for(;t<9;t++)
		fprintf(f,"%lf\n",a[t]);
	fclose(f);
}

void print(const double a[])
{
	int r=0;
	printf("static:\n");
	for(;r<9;r++){
		printf("%lf\t",a[r]);
	printf("\n");}
	printf("\n");
}

int main()
{
	int m;
	printf("log10 = %lf\n",log(10.0));
	printf("log63 = %lf\n",log(63.0));
	double pab=101.53;
	double tem[9]={55.0,60.0,63.0,65.0,68.3,70.1,73.1,75.1,78.9};
	double pa[9] ={62.20,55.64,48.92,44.33,35.29,30.49,20.90,13.30,-0.0001};
	for(m=0;m<9;m++)
		pa[m]=-pa[m];
	print(tem);
	print(pa);
	puts("=====temprature=============");
	for(m=0;m<9;m++)
	{
		tem[m]=1.0/tem[m];
		printf("%lf\n",tem[m]);
	}
	puts("===== lnp =============");
	for(m=0;m<9;m++)
	{
		pa[m]=log(pa[m]+pab);
		printf("%lf\n",pa[m]);
	}
	puts("==================");
	writ(tem,"temprature.txt");
	writ(pa,"psk.txt");
	puts("==================");
	return 0;
}
