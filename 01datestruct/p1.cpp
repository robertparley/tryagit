#include <iostream>
using namespace std;
class T
{
	int a;
public:
	T(int b):a(b){}
	int test()const
	{
		int i=0;
		i++;
		i=38;
//		a=11;
		cout<<"i="<<i<<endl;
		cout<<"a="<<a<<endl;
		return a;
	}
};
int main()
{
	int a=8;
	double b=0;
	char c;
	int d=0;
	string e;
	T t(a);
	t.test();
	cout<<"end"<<endl;
	cout<<(a++%5)<<endl;
	cout << a <<"b"<< c <<"c" << d <<"d" << e <<endl;
}
