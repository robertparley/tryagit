#include <iostream>
#include <sstream>
#include <cstring>
#include <fstream>
using namespace std;

class outofrange:public exception
{
	int e,max;
public:
	outofrange(int a,int b):e(a),max(b){}
	const char* what()const throw()
	{
		ostringstream o;
		o<< "该最大值为"<<max<<"的数组越界，实际长度为"<<e<<endl;
		string st=o.str();
		return st.c_str();
	}
};

class Array
{
	int num;
	char a[10];
public:
	void check(const char* c);
	Array():num(0){}
	Array(const char* c)
	{
		num = strlen(c);
		if(strlen(c)>10)
			throw outofrange(num,10);
		strcpy(a,c);
	}
	int size(){return strlen(a);}
	friend ostream& operator<<(ostream& cou,const Array& temp)
	{
		cou<< temp.a;
		return cou;
	}
	friend istream& operator>>(istream& c,Array& temp)
	{
		string r;
		c>>r;
		Array(r.c_str());
		strcpy(temp.a,r.c_str());
		return c;
	}
//	Array& operator[](char* ch);
};
//Array& Array::operator[](char* ch)

void Array::check(const char* c)
{
	if(strlen(c)>10)
		throw outofrange(num,10);
	num = strlen(c);
	strcpy(a,c);
}

int main(int argc,char* argv[])
{
	Array c;
	Array r[3];
	Array b;
	cout<<c<<" size "<<c.size()<<endl;
	cin>>b;
	cout<<b;
}
