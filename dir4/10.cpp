#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int inout()
{
	cout << showbase<<123<<endl;
	cout <<left <<setfill('M')<<setw(6)<< showpos<<23<<endl;
	cout <<setw(6) <<345<<endl;
	cout <<setw(6)<<internal<< 241<<endl;
//	cout << fixed(4) << 12.34<<endl;
}

int main(int argc,char* argv[])
{
	if(argc!=3) cout<<"error"<<endl;
	string s1=argv[1],s2=argv[2];
	char temp[100];
	ifstream fin(s1.c_str());
	if(!fin){cout<<"open error!"<<endl;}
	ofstream fo(s2.c_str());
	if(!fo){cout<<"open error!"<<endl;}
	while(fin.get(temp[0]))
		fo.put(temp[0]);

}




















