#include <stdio.h>

#define SORT(a,T,d) {\
	if(d=='<')	SORT1(a,T)\
	 if(d=='>') SORT2(a,T)\
	else printf("wrong!\n");}

#define SORT1(a,T) {int* d,e;int* b=&a[sizeof(a)/sizeof(T)-1];int* c=b;\
	for(a;a<b;){printf("a\n");\
		for(c=b;c>a;){printf("b\n");\
			if(*a>*c){printf("c\n");	*a += *c;	*c = *a-*c;	*a -= *c;}\
			c--;}a++;}}

/*
#define SORT2(a,T) {int* c=b;\
	for(a;a<b;a+1){\
		for(b=c;b>a;b-1){\
			if(*a<*b){	*a += *b;	*b = *a-*b;	*a -= *b;}}}}
*/
int main()
{
	int a[3]={2,5,3};
	SORT(a,int,'<')
	int i;
	for(i=0;i<3;i++){printf("%d ",a[i]);}
	return 0;
}

