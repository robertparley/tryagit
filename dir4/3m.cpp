#include "3.cpp"

int main()
{
	Time m(23,58,52);
	for(int i=0;i<70;i++)
	{
		m.tick();
		m.show();
	}
	Time t;
	t.show();
	return 0;
}
