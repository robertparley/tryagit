#include <iostream>
#include <cassert>
#include <list>
#include <cstdlib>
#include <deque>
#include <vector>
using namespace std;

bool compare(int x,int y)
{
	x%=3,y%=3;
	return x<y;
}

template <typename T>
void print(T b,T e)
{
	while(b!=e)
			cout << *b++ <<' ';
	cout << endl;
}
//vector练习
void vectorr()
{
	vector<int> v1;
	cout << v1.size() << '/' << v1.capacity() << endl;
	v1.reserve(6);
	cout << v1.size() << '/' << v1.capacity() << endl;
//	print(v1.begin(),v1.end());
	cout << v1.size()<<endl;
//	v1.front()=1;v1.back()=100;
//	int a[]={1,2,3,4,5};
//	print(a,a+5);
//	cout << &v1.begin() <<endl;
//	print(v1.begin(),v1.end());
	v1.push_back(8);
	v1.push_back(8);
	v1.push_back(8);
	v1.insert(2+v1.begin(),3,9);
	cout << v1.size()<<endl;
	v1.pop_back();
	print(v1.begin(),v1.end());
	v1.assign(6,22);
	cout << v1.size() <<endl;
	print(v1.begin(),v1.end());
	v1.resize(12,33);
	cout <<v1.size() <<endl;
	print(v1.begin(),v1.end());
	v1.clear();
	print(v1.begin(),v1.end());
}

//deque practise
void dequee()
{
	deque<int> q;
	q.push_front(4);
	q.push_front(5);
	q.push_back(3);
	print(q.begin(),q.end());
}

//list practise
void listt()
{
	int a[20]={0};
	for(int i=0;i<20;i++)
		a[i]=rand()%100;
	list<int> l(a,a+20);
	print(l.begin(),l.end());
	l.sort();
	print(l.begin(),l.end());
	l.reverse();
	print(l.begin(),l.end());
	l.unique();
	print(l.begin(),l.end());
	list<int> ll;
	ll.push_back(1);
	ll.push_back(2);
	ll.push_back(3);
	ll.sort( greater<int>());
	ll.sort(compare);
//	ll.splice(++++ll.begin(),l);
	ll.merge(l);
	print(l.begin(),l.end());
	print(ll.begin(),ll.end());
	ll.sort();
	print(ll.begin(),ll.end());
}

int main()
{
	vectorr();
	cout << "======================" <<endl;
	dequee();
	cout << "======================" <<endl;
	listt();
	cout << "======================" <<endl;
	int a=2;
	assert(a);
}
