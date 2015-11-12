//类定义
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

class wrong:public exception
{
	const char* what()const throw()
	{return "wrong for store";	}
};

class stadm
{
private:
	string name;
	bool gender;
	int point;
	bool store();
public:
	stadm();
	stadm(char* s,bool g,int p):name(s),gender(g),point(p){
	store();}
	bool rewrite();
	bool search();
	bool del();
	bool add();
};

int main()
{
	stadm sys1;
	sys1.search();


/*
	string s="abcdefghi";
	int x=0;
	char a[]="fe";
	string b="fe";
	x=s.find(a);
	cout <<"found char* : "<< x << endl;
	x=0;x = s.find(b);
	cout <<"found string: "<< x << endl;
*/
}
