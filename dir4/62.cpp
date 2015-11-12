//unfinished
//写一个复数类Complex
//支持加减乘除、++、--运算，//除法运算未完成
//到bool类型和string类型转换，//未完成
//支持<< >>运算

#include <iostream>
#include <string>
using namespace std;

class Complex
{
	int a,b;
public:
	Complex(int m=1,int n=1):a(m),b(n){}
	Complex operator+(const Complex& l)const
	{return Complex(a+l.a,b+l.b);}
	Complex operator-(const Complex& l)const
	{return Complex(a-l.a,b-l.b);}
	Complex operator*(const Complex& l)const
	{return Complex ((a*l.a-b*l.b) , (a*l.b+b*l.a));}
/*
	Complex operator/(const Complex& l)const
	{	Complex te=*this * l;
		int t=l.a*l.a-l.b*l.b;
		te.a /=t;te.b/=t;
		return te;	}
*/
	string exchar();
	Complex operator++()
	{a++;return *this;}
	Complex operator--()
	{a--;return *this;}
	Complex operator++(int);
	Complex operator--(int);
	friend ostream& operator<<(ostream& o,const Complex& l);
	friend istream& operator>>(istream& i, Complex& l)
	{	i >> l.a >> l.b;return i;	}
};
ostream& operator<<(ostream& o,const Complex& l)
{
	if(l.a==0)	o << l.b <<'i';
	if(l.b==0)	o << l.a ;
	o << l.a <<(l.b>0?'+':'-')<< l.b <<'i';
	return o;	
}
string Complex::exchar()
{
	string str=itoa(a)+(b>0?'+':'-')+itoa(b)+'i';
	cout << str;
	return str;
}
Complex Complex::operator++(int)
{a++;return Complex (a-1,b); }
Complex Complex::operator--(int)
{a--;return Complex (a+1,b); }

int main()
{
	Complex a(3,4);
	cout << a++ <<endl;
	cout << a <<endl;
	a.exchar();
}
