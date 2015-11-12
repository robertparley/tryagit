//关于成员指针的练习

#include <iostream>
using namespace std;

struct date{
	int year;
	int month;
	int day;
};

void print(date *a,int date::*mp)
{
	for(int i=0;i<3;i++)
		cout << a[i].*mp <<"  ";
	cout << endl;
}

int main()
{
	cout << "abcd";
	cout << '\b' << '\n';
	date d[3]={{2010,1,1},{2012,3,6},{2014,5,5}};
	int date::*mp=&date::year;
	cout << d[0].*mp << endl;
	print(d,&date::month);
	print(d,&date::year);
	print(d,&date::day);
	return 0;
}
