//unfinished
//写一个大数类
//能处理50位以内加减运算、赋值运算和输入输出。

#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <iomanip>
using namespace std;

class Big
{
	char t1[50],t2[20];
	int num[6];
	int a,b;
	void check();
public:
	Big()
	{
		strcpy(t1,"0");
		strcpy(t2,"0");
		for(int i=0;i<6;i++)
			num[i]=0;a=0,b=1;
	}
	Big(char * t);
	void print();

	Big operator+(const Big& b)const;
	Big operator-(const Big& b)const;
};

Big::Big(char * t)
{
	cout << t[3]<<endl;
	for(int i=0;i<6;i++)
		num[i] = 0;
	strcpy(t1,t);
	a=strlen(t1);
	b =a-a/9*9;
	a = a/9;
	for(int i=0;i<=b;i++)
	{t2[i]=t[i];	}
	num[0]=atoi(t2);
	for(int i=0;i<=a;i++)
	{
		for(int j=0;j<=9;j++)
		{
			t2[j]=t[b+9*i+j];
		}
		num[i+1]=atoi(t2);
	}
}

void Big::print()	
{
	for(int i=0;i<6;i++)
		if(num[i]!=0)	cout << num[i];
	cout << endl;
}

void Big::check()
{
	for(int i=5;i;i++)
	{
		if(num[i]>=1000000000)	{num[i-1]+=1;	num[i]-=1000000000;	}
		if((num[i]<0)&&(num[i-1]>0))
			{num[i-1]-=1;num[i]+=1000000000;}
	}
}

Big Big::operator+(const Big& b)const
{
	Big te;
	for(int i=0;i<6;i++)
	{
		te.num[i] = num[i] + b.num[i];
	}
	te.check();
	return te;
}

Big Big::operator-(const Big& b)const
{
	Big te;
	for(int i=0;i<6;i++)
	{
		te.num[i] = num[i] - b.num[i];
	}
	te.check();
	return te;
}

int main()
{
	Big b("323048230148923570239535938252453456");
	b.print();
}
