#include <iostream>
using namespace std;

class Time
{
	int hour;
	int min;
	int sec;
public:
	Time(void)	
	{hour = 0;	min = 0;	sec = 0;	}
	Time(int h,int m,int s)	
	{hour = h;	min = m;	sec = s;	}
	void show()	
	{cout << "Now " << hour << ':' << min << ':' << sec << endl;}
	void tick()
	{
		sec++;
		if(sec >= 60)	{sec -= 60;min++;}
		if(min >= 60)	{min -= 60;hour++;}
		if(hour>= 24)	{hour -=24;}
	}
};
