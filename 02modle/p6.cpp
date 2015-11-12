//统计一篇文档中字符的个数
#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

ostream& operator<<(ostream& o ,const pair<char,int>& p)
{
	return o<<p.first<<'\t'<<p.second;
}


int main()
{
	char temp=0;
	map<char,int> cnt;
	ifstream fr("a.bat");
	if(fr==NULL)	return 1;
	while(fr.get(temp))
	{
		
		++cnt[temp];
	}
	map<char,int>::iterator b=cnt.begin();
	while(b!=cnt.end())
	{
		if(b->first=='\n')	{
			cout<<"enter\t"<<b->second<<endl;
			b++;}
		else if
			(b->first==' ')	{
			cout<<"space\t"<<b->second<<endl;
			b++;}
		else
			cout<<*b++<<endl;
	}

//	cnt.insert(make_pair('a',0));
//	cout<<*cnt.begin();
}

