#include <iostream>
using namespace std;

class USB
{
public:
	virtual void plugin(){};
	virtual void work(){};
	virtual void stop(){};
};

class USBDisk:public USB
{
public:
	void plugin()
	{cout << "please choose the working way...." <<endl;}
	void work()
	{cout << "the device works well..." <<endl;}
	void stop()
	{cout << "move the device!" << endl;}
};

class USBFan:public USB
{
public:
	void plugin()
	{cout << "please turn on the fan...." <<endl;}
	void work()
	{cout << "Are you cool?..." <<endl;}
	void stop()
	{cout << "The fan is stopped!" << endl;}
};
class Computer
{
public:
	void use(USB *d)
	{
		d->plugin();
		d->work();
		d->stop();
	}
};

int main()
{
	Computer c;
	USBDisk di;
	USBFan f;
	USB *p;
	p = &di;
	c.use(p);
	cout << endl;
	p = &f;
	c.use(p);
	cout <<endl;
	p = &di;
	c.use(p);
}

