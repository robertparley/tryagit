#ifndef CLASS_DATE
#define CLASS_DATE 1

#include <iostream>
using namespace std;

class Date
{
	int isr, year, month, day;
public:
	int check(int y,int m,int d);
	Date();
	Date(int y,int m,int d);
	void show();
	void go(int y,int m,int d);
	void tick();
	int weekday();
	void calender();
};

Date::Date()
	{year=1970;month=1;day=1;isr=0;}

Date::Date(int y,int m,int d)
	{
	if(check(y,m,d))
		{year = y;	month = m;	day = d;	}
	else
		{cout << "input error!" << endl;year =1970;month = 1;day = 1;	}
	}

void Date::show()
	{cout<< "Date:" << year << '-' << month << '-' << day << endl;}

void Date::go(int y,int m,int d)
	{
	if(check(y,m,d)){
		year = y;	month = m;	day = d;	}
	else
		cout << "input error!" << endl;
	}

int Date::check(int y,int m,int d)
//返回值：2-闰年；1-非闰年；0-日期有误；
	{
		isr = 0;
		if(y < 1970)
			return 0;
		if((y%400==0)||((y%4==0)&&(y%100!=0)))
			isr=1;
		if((m<1)||(m>12))
			return 0;
		switch(m){
			case 1:	case 3:	case 5:	case 7:	
			case 8:	case 10:	case 12:
				if(d>31)	return 0;
				break;
			case 4:	case 6:	case 9:	case 11:
				if(d>30)	return 0;
				break;
			case 2:
				if(d>28+isr)	return 0;
				break;
			default:
				return 0;
		};
		return isr+1;
	}

void Date::tick()
{
	check(year,month,day);
	day++;
	switch(month){
		case 1:	case 3:	case 5:	case 7:	
		case 8:	case 10:	case 12:
			if(day>31)	{day -= 31;month++;}
			break;
		case 4:	case 6:	case 9:	case 11:
			if(day>30)	{day -= 30;month++;}
			break;
		case 2:
			if(day>28+isr)	{day -= (28+isr);month++;}
			break;
		default:
			cout << "tick error" <<endl;
	}
	if(month>12)	{month -= 12;year++;}
}

int Date::weekday()
//返回该月一号星期几
{
	check(year,month,day);
	cout << "isr=" << isr <<endl;
	int total=year/4-year/100+year/400+(year-1)*365;
	for(int i=1;i<month;i++)
	{
		if((i>=8 && i%2==0)||(i<=7 && i%2==1))
			total += 31;
		else if(i == 2)
			total += 28+isr;
		else
			total += 30;
	}
	int n=(total+1)%7;
	total += day;
	cout << total << endl;
	switch(total%7){
		case 1:
			cout << "这一天是星期一" << endl;
			break;
		case 2:
			cout << "这一天是星期二" << endl;
			break;
		case 3:
			cout << "这一天是星期三" << endl;
			break;
		case 4:
			cout << "这一天是星期四" << endl;
			break;
		case 5:
			cout << "这一天是星期五" << endl;
			break;
		case 6:
			cout << "这一天是星期六" << endl;
			break;
		case 0:
			cout << "这一天是星期日" << endl;
			break;
		default:
			cout << "这是个神奇的日子" << endl;

	}
	return n;
}

void Date::calender()
{
	int j=weekday();
	int k;
	if(((month<=7)&&(month%2==1))||((month>=8)&&(month%2==0)))
		k=31;
	else if(month==2)
			k = 28 + isr;
		else
			k = 30;
	cout << "月历: " <<endl;
	cout << year << "年" << month << "月" << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "日\t一\t二\t三\t四\t五\t六" << endl;
	for(int i=j++;i;i--)
		cout << '\t';
	for(int i=1;i<=k;j++,i++){
		cout << i;
		if(j%7==0)
			cout << endl;
		else
			cout << '\t';
	}
	cout << endl;
	cout << "----------------------------------------------------" << endl;
}

#endif/*CLASS_DATE*/

