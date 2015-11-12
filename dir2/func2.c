#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct student{
	char name[18];
	unsigned char gender:1;
	unsigned char grade:2;
	char num[10];
	int chengji;
}

union id{
	char a;
	int b;
	double c;
}

int main()
{
	struct student s;
	
}
