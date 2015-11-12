#include <iostream>
using namespace std;
typedef int T;

class Queue
{
	T a[5];
	int beg,cnt;
public:
	Queue():beg(0),cnt(0){}
	Queue& push(const T& d);
	T pop();
	void clear();
	bool empty(){if(cnt==0) return 1;return 0;}
	bool full(){if(cnt==4)	return 1;return 0;}
};
Queue& Queue::push(const T& d)
{
	if(full())	throw "man";
	a[(cnt+beg)%5]=d;
	++cnt;
	return *this;
}
T Queue::pop()
{
	if(empty())	throw "kong";
	--cnt;
	return a[beg++%5];
}
void Queue::clear(){beg=0;cnt=0;}

int main()
{
try
{
	Queue q;
	q.push(1).push(2).push(3);
	while(!q.empty())
		cout<<q.pop()<<endl;
	q.push(2);
	q.push(4);
	q.push(5);
		cout<<q.pop()<<endl;
	q.push(2);
	q.push(4);
	while(!q.empty())
		cout<<q.pop()<<endl;
}
catch(const char* d)
	{cout<<"error  "<< d<<endl;}
}
