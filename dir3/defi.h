#include <stdio.h>
#ifndef DIFI_H
#define DIFI_H 1
//判断是否是闰年
#define ISLEAP(y) (((y)%400==0)?1:((((y)%4==0)&&((y)%100!=0))?1:0))

//输出相应月份的天数
//#define DAY(y,m) ((m==2)?(ISLEAP(y)?(29):(28)):(((m<8)&&(m%2==1))?(31):(30)))
#define DAY(y,m)\
			((m==2)?(ISLEAP(y)+28):(((m<8)&&(m%2==1))?(31):(30)))

#endif
