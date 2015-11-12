//学生信息系统，记录姓名性别成绩
//完成录入 查询 改写 删除功能。
//改进：可以将各个功能整合，作出符号界面进行相应的操作
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

class wrong:public exception
{
	const char* what()const throw()
	{return "wrong for store";	}
};

class stadm
{
private:
	string name;
	bool gender;
	int point;
	bool store();
public:
	stadm();
	stadm(char* s,bool g,int p):name(s),gender(g),point(p){store();}
	bool rewrite();
	bool search(string a="none");
	bool del(string a="none");
	bool add();
};

stadm::stadm()
{
	char g;
	cout<<"正在创建学生管理数据，请输入第一位学生信息"<<endl;
	cout<<"姓名 性别（M/F） 成绩：";
	cin >> name >> g >> point;
	if(g=='M'||g=='m')	gender=1;
	else	gender = 0;
	store();
}

bool stadm::store()
{
	ofstream fout("stu.dat",ios::app);
	if(!fout)	return 1;
	fout<<"姓名："<<name<<endl
		<<"性别："<<(gender?"男":"女")<<endl
		<<"成绩："<<point<<endl;
	fout.close();
	return 0;
}
bool stadm::add()
{
	char g;
	cout<<"正在创建学生管理数据，请输入学生信息"<<endl;
	cout<<"姓名 性别（M/F） 成绩：";
	cin >> name >> g >> point;
	if(g=='M'||g=='m')	gender=1;
	else	gender=0;
	if(store())
		throw wrong();
	return 0;
}
bool stadm::search(string a)
{
	string s;
	if(a=="none"){
	cout<<"请输入待查找学生姓名：";
	cin>>a;}
	int p=0;
	ifstream fi("stu.dat");
	if(!fi)	throw wrong();
	while(!fi.eof())
	{
	fi>>s;
	p = s.find(a);
	if(p!=-1)
		break;
	}
	if(p==-1)
	{cout<<"Not Founded!"<<endl;return 1;}
	p=3;
	while(p--)
	{
		cout<<s<<endl;
		fi>>s;
	}
	return 0;
}

bool stadm::rewrite()
{
	string s;
A:	cout<<"请输入改写资料学生姓名："<<endl;
	cin>>s;
	cout<< s << "的原始资料为："<<endl;
	if(search(s)==1)
		goto A;
	cout<<"请输入改写后的学生姓名 性别（M/F） 成绩：";
	char g;
	cin>>name>>g>>point;
	if(g=='M'||g=='m')	gender = 1;
	else	gender = 0;
	del(s);store();
	return 0;
}

bool stadm::del(string a)
{
	if(a=="none")
	{
		cout<<"请输入要删除的学生姓名："<<endl;
		cin>>a;
	}
	ifstream fin("stu.dat");
	if(!fin)	throw wrong();
	ofstream fo("str.dat");
	if(!fo)	throw wrong();
	string s;
	char x[1000]={};
	int cur1=0;
	while(!fin.eof())
	{
		cur1=fin.tellg();
		getline(fin,s);
		if(s.find(a)!=-1)
			break;
	}
	fo.seekp(0,ios::beg);
	fin.seekg(0,ios::beg);
	while(fin.tellg()<cur1)
	{
		getline(fin,s);
		fo<<s<<endl;
	}
	fin.seekg(cur1,ios::beg);
	for(int tem=0;tem<3;++tem)
	{getline(fin,s);}
	fin.read(x,1000);
	fo.seekp(cur1,ios::beg);
	fo.write(x,fin.gcount());
	fin.close();fo.close();
	for(int tem=0;tem<1000;tem++)	{x[tem]=0;}
	fin.open("str.dat");
	if(!fin)	throw wrong();
	fo.open("stu.dat");
	if(!fo)	throw wrong();
	fin.read(x,1000);
	fo.write(x,fin.gcount());
	return 0;
}


int main()
{
	stadm sys1;
//	sys1.search();
	sys1.rewrite();
}
