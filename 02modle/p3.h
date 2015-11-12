//把前面讲的二叉查找树写成模板，并分别实例化出两个类用来存放一组字符串和一组Person，后者用年龄排序
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
template <typename T>
class bintree
{
	T date;
	bintree* L;
	bintree* R;
	bintree* root;
	bintree(const T& d):date(d),L(NULL),R(NULL){}
public:
	bintree():date(T()),L(NULL),R(NULL),root(NULL){}
	void add(const T& d)	{add(d,root);}
	void add(const T& d,bintree*& p)
	{
		if(p==NULL)	
			p=new bintree(d);
		else if(d<p->date)	add(d,p->L);
		else	add(d,p->R);
	}
	void show(){show(root);cout<<endl;}
	void show(bintree* p)
	{
		if(p==NULL)	return;
		show(p->L);
		cout << p->date<<' ';
		show(p->R);
	}
};

template <>
class bintree<const char*>
{
	string date;
	bintree* L;
	bintree* R;
	bintree* root;
	bintree(const char* d):L(NULL),R(NULL)
	{
		date=d;
	}
public:
	bintree():L(NULL),R(NULL),root(NULL){}
	void add(const char* d)
	{
//		string a=d;	add(a,root);
		add(d,root);
	}
//	void add(string d,bintree*& p)
	void add(const char* d,bintree*&p)
	{
		if(p==NULL)	
		{	p = new bintree;
			p->date = d;
			return;
		}
//		if(d<p->date)	add(d,p->L);
		if(strcmp(d,p->date.c_str())<0)	add(d,p->L);
		else	add(d,p->R);
	}
	void show(){show(root);cout<<endl;}
	void show(bintree*& p)const
	{
		if(p==NULL)	return;
		show(p->L);
		cout <<p->date << ' ';
		show(p->R);
	}
};

template <>
class bintree<Person>
{
	Person date;
	bintree* L;
	bintree* R;
	bintree* root;
	bintree(Person& d):date(d),L(NULL),R(NULL){}
public:
	bintree():date(Person()),L(NULL),R(NULL),root(NULL){}
	void add(Person& p)	{add(p,root);}
	void add(Person& p,bintree*& p)
	{
		if(p==NULL)	
			p=new bintree(p);
		else if(p->age<p->date->age)	add(p,p->L);
		else	add(p,p->R);
	}
	void show(){show(root);cout<<endl;}
	void show(bintree* p)
	{
		if(p==NULL)	return;
		show(p->L);
		cout << p->date <<' ';
		show(p->R);
	}
};
