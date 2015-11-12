//数据库类的多态

#include <iostream>
using namespace std;

class Database
{
public:
	virtual void Connect()
	{cout << "connecting database" <<endl;}
	virtual void Query()
	{cout << "finding......"<<endl;}
};

class Access:public Database
{
	void Connect()
	{cout << "connect access success!" <<endl;}
	void Query()
	{cout << "finding data in access..." << endl;}
};

class SQLserver:public Database
{
	void Connect()
	{cout << "connecting sqlserver success!" << endl;}
	void Query()
	{cout << "finding data in sqlserver.." << endl;}
};

class Oracle:public Database
{
	void Connect()
	{cout << "connecting oracle success!" << endl;}
	void Query()
	{cout << "finding data in oracle..." << endl;}
};

class Program
{
public:
	void visit(Database* d)
	{d->Connect();(*d).Query();}
};

int main()
{
	Program p;
	Oracle o;
	Access a;
	SQLserver s;
	p.visit(&o);
	p.visit(&a);
	p.visit(&s);
}
