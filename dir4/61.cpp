//窗口类，基本完成
#include <iostream>
#include <string>
using namespace std;
struct num{
	int x;
	int y;
	};
class Window
{
	num size;num local;
	string title;
public:
	Window(string t="title",int sx=100,int sy=100,int lx=0,int ly=0)
	{
		title=t,size.x=sx,size.y=sy,local.x=lx,local.y=ly;
	}
	void move(int x,int y)
	{
		local.x += x;
		local.y += y;
	}
	string getti()const
	{
		cout << title <<endl;
		return title;
	}
	void setti( const string& str)
	{
		title = str;
	}
	void setlo(int x,int y)
	{
		local.x = x;local.y = y;
	}
	num& getlo()const
	{
		cout << local.x <<','<< local.y <<endl;
	}
};


int main()
{
	Window w;
	w.setti("genggai");
	w.setlo(44,55);
	w.getlo();
	w.getti();
}
