#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

int main()
{
string s="12345 6.78 x hello 234 100";
char buf[100]="abc";
	ostringstream os;
	//os << "buf=" << buf ;
	cout << "===========" << endl;
	cout << os.str() << endl;
	cout << os.str()[4] << endl;
	cout << "===========" << endl;
}
