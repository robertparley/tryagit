#include <iostream>
using namespace std;

template <typename T>
void output(const T* t,int n)
{
	for(int i=0;i<n;i++)
		cout << t[i] <<" ";
	cout<<endl;
}
void output(string t,int n)
{
	cout<<"input a string"<<endl;
	for(int i=0;i<n;i++)
		cout <<t[i]<<endl;
}

int main()
{
	char a[7]="hello";
	double b[4]={2.2,3.3,4.4,6.6};
	int c[4]={1,3,2,4};
	string s[4]={"hello","world","i","do"};
	output(a,7);
	output(b,4);
	output(c,4);
	output(s,4);
	
	char aa[2][8]={"hello","every"};
	output(aa,2);
}
