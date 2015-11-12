//对个别问题对实验
//1、各数据类型的typeid.name()的名称
//2、可否在类外对数据成员赋值（当然不可以，否则要构造函数干嘛吃的！）
//3、对结构加构造函数，在初始化的时候怎么用
#include <iostream>
#include <typeinfo>
using namespace std;

class A 
{
	int  a;
public:
	void show(){cout<<a;}
};
struct Date
{
	int y,m,d;
	Date():y(1970),m(2),d(1){}
	Date(int y,int m,int d):y(y),d(d),m(m){}
};

int main()
{
	cout<<"int="<<typeid(int).name()<<endl;
	cout<<"double="<<typeid(double).name()<<endl;
	cout<<"char="<<typeid(char).name()<<endl;
	cout<<"bool="<<typeid(bool).name()<<endl;
	cout<<"A="<<typeid(A).name()<<endl;
	cout<<"Date="<<typeid(Date).name()<<endl;
	cout<<"int*="<<typeid(int*).name()<<endl;
	cout<<"string="<<typeid(string).name()<<endl;
	cout<<"string*="<<typeid(string*).name()<<endl;
	cout<<"========================="<<endl;
//问题3
	Date d[3]=	{
					Date(),
					Date(1999,9,9)
				};
	for(int i=0;i<3;i++)
		cout<<"d["<<i<<']'<<d[i].y<<'-'<<d[i].m<<'-'<<d[i].d<<'/'<<endl;

}

