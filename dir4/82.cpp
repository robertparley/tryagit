//艺术品类
//可完善输出各类可变参数
#include <iostream>
#include <string>
using namespace std;

class art
{
protected:
	string name;
	int year;
public:
	art(const string& s,int i):name(s),year(i){}
	virtual void print()
	{cout << "这是" << name << year << "年的作品" <<endl;}
};

class painting:public art
{
	int sx,sy;
public:
	painting(const string& s,int year,int x,int y):art(s,year),sx(x),sy(y){}
	void print()
	{cout<<"这是"<<name<<"的油画"<<endl;
	cout<<"length="<<sx<<"width="<<sy<<endl;}
};

class music:public art
{
protected:
	int time;
public:
	music(const string& s,int year,int t):art(s,year),time(t){}
//	void print(){cout <<"music.."<<endl;}
};

class popu:public music
{
	string writer;
public:
	popu(const string& n,const string& wr,int year,int t)
	:music(n,year,t),writer(wr){}
	void print(){cout << "popular music.." << endl;}
};

class pop:public music
{
	int num;
public:
	void print(){cout << "pop music.." << endl;}
	
};

void show(art& a)	{a.print();}

int main()
{
	string a="name";
	popu po(a,"writer",1900,3);
	painting pa("nname",1999,100,200);
	show(po);show(pa);
}
