#include <iostream>
#include <iomanip>
using namespace std;

class KUAN
{
	int width;
	int pre;
public:
	KUAN(const int a,const int b):width(a),pre(b){}
	friend ostream& operator<<(ostream& o,KUAN k)
	{
		return o<<setw(k.width)<<setprecision(k.pre);
	}
};
class test
{
	int a;
	double b;
public:
	test no(){return -1;}
}

int main()
{
	cout<<KUAN(10,7)<<12.38546<<endl;
	cout<<1234567890<<endl;
	test t;
	cout<<t.no;
}
