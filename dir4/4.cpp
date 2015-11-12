#include "class_date.cpp"

//对go函数改成由键盘输入
int main()
{
	Date d;
	d.show();
	d.weekday();
	d.go(2012,2,27);
	d.show();
	d.weekday();
	d.go(2015,10,5);
	d.show();
	d.weekday();
	d.calender();
	return 0;
}
