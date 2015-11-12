//把前面讲的二叉查找树写成模板，并分别实例化出两个类用来存放一组字符串和一组Person，后者用年龄排序
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
class Person
{
	string name;
	bool gender;
public:
	unsigned int age;
	Person():name(string()),gender(1),age(0){}
	Person(const Person& p)
	{name=p.name;gender=p.gender;age=p.age;}
	Person(const char* n,bool g,unsigned int a):name(n),gender(g),age(a){}
friend ostream& operator<<(ostream& o,const Person& p)
{
	o<<"name:\t"<<(p.name)<<"\ngender:\t"<<(p.gender?"男":"女")
	<<"\nage:\t"<<p.age<<endl;
	return o;
}
;

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
	bintree(const Person& d):date(d),L(NULL),R(NULL){}
public:
	bintree():date(Person()),L(NULL),R(NULL),root(NULL){}
	bintree& add(const Person& d)	{return add(d,root);}
	bintree& add(const Person& d,bintree*& p)
	{
		if(p==NULL)	
			p=new bintree(d);
		else if(d.age<p->date.age)	add(d,p->L);
		else	add(d,p->R);
		return *this;
	}
	void show(){show(root);cout<<endl;}
	void show(bintree* p)
	{
		if(p==NULL)	return;
		show(p->L);
		cout << p->date ;
		show(p->R);
	}
};

int main()
{

	bintree<int> a;
	a.add(4);
	a.add(2);
	a.add(9);
	a.show();
	bintree<const char*> b;
	b.add("onon");
	b.add("onpwd");
	b.add("yosens");
	b.show();
	bintree<string> c;
	c.add("mes");
	c.add("noyeah");
	c.show();
	Person p[3]={
		Person("John",1,29),
		Person("Amy",0,38),
		Person("Andriod",1,49)};
	bintree<Person> d;
	d.add(p[0]);
	d.add(p[1]);
	d.add(p[2]);
	d.show();

}
