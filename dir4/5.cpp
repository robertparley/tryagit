#include<iostream>
using namespace std;

class Num{
	int fz,fm;
	int maxn(int a,int b){
		if (a==0)	return b;
		return maxn(b%a,a);
	}
	void easy(){
		if(fm==0)	throw 1;
		int i=maxn(fz,fm);	fz /= i;	fm /= i;
		if(fm<=0)	{fz=-fz;fm=-fm;}
	}
public:
	Num(int a=1,int b=1):fz(a),fm(b){easy();};
	friend Num operator+(const Num& a,const Num& b);
	friend Num operator-(const Num& a,const Num& b);
	friend Num operator*(const Num& a,const Num& b);
	friend Num operator/(const Num& a,const Num& b);
	friend ostream& operator<< (ostream& o,const Num& a);
	Num operator~()	{return Num(fm,fz);	}
	bool operator!()	{return (fz?0:1);	}
};

ostream& operator<< (ostream& o,const Num& a)
{o<<a.fz<<'/'<<a.fm;	return o;	}
Num operator+(const Num& a,const Num& b)
{return Num(a.fz*b.fm+b.fz*a.fm,a.fm*b.fm);	}
Num operator-(const Num& a,const Num& b)
{return Num(a.fz*b.fm-b.fz*a.fm,a.fm*b.fm);	}
Num operator*(const Num& a,const Num& b)
{return Num (a.fz*b.fz,a.fm*b.fm);	}
Num operator/(const Num& a,const Num& b)
{return Num(a.fz*b.fm,a.fm*b.fz);	}

int main()
{
	Num te(3,4),ta(2,5),t;
	Num a(0,5);
	cout << a << endl;
	cout << boolalpha << !a << endl;
	cout << te <<endl;
	cout<<ta<<endl;
	t = te + ta;
	cout << t << endl;
	cout << ~t<< endl;
	cout << boolalpha << !t << endl;
}

