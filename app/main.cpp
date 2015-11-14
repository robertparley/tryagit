#include<iostream>
#include<string>
using namespace std;

bool doit()
{
//	cout <<' ';
}

int main()
{
	int a=0;
	cout << doit();
}

int outn()
{
	int x=9,y=7;
	int **p;
	p = new int*[x];
	for(int i=0;i<x;i++)
		p[i]=new int[y];
	for(int i=0;i<x;i++)
		for(int j=0;j<y;j++)
			p[i][j]=j+i;
	for(int l=0;l<x;l++){
		for(int j=0;j<y;j++)
			cout << p[l][j];
		cout<<endl;
		}
}
