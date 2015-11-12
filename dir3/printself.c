#include <stdio.h>
#include <string.h>
int main()
{
	char s[]={"cat "};
	strcat(s, __FILE__ );
	system(s);
	return 0;
}
