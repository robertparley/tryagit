#include<stdio.h>

int check(int year,int month,int day)
{
	int i=0;
	if(year == 0)
		i += 4;
	if((month<1)||(month>12))
		i += 2;
	switch(month) {
		case 1:	case 3:	case 5:	case 7:	case 8:	case 10:case 12:
		if(day > 31)
			i += 1;
		break;
		case 2:
			if((year%4==0 && year%100!=0)||(year%400==0))
				{
					if(day>29)
						i += 1;
				}
			else
				{
					if(day>28)
						i += 1;
				}
			break;
		default:
			if(day>30)
				i += 1;
	}
	return i;	
}
