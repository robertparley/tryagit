#include <iostream>
using namespace std;
/*
	int* totalpoint =new int(x*y);
	int* maxx = new int(x);
	int* maxy = new int(y);
*/
//bool func(int* x,int* y,int**& b,int* cnt);
bool func(int x,int y,int** b,int cnt,int i,int j,bool run=1);
bool mid(int startx,int starty,int x,int y);
void print(int** b,int x,int y)
{
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++)
			cout << b[i][j]<<' ';
		cout << endl;
	}
}

int main()
{
	int x=3;
	int y=4;
	int startx=0,starty=0;
	mid(startx,starty,x,y);
}

bool mid(int startx,int starty,int x,int y)
{
//new一个二维数组做棋盘
	int **chessboard;
	chessboard = new int*[x];
	for(int i=0;i<x;i++)
		chessboard[i]=new int[y];
	for(int i=0;i<x;i++)
		for(int j=0;j<y;j++)
			chessboard[i][j]=0;
	int cnt=0;
	bool f=func(startx,starty,chessboard,cnt,x,y,1);
	if(!f){
		cout << "found answer!" <<endl;
		print(chessboard,x,y);
		}
	else{
		cout << "not found." <<endl;
		print(chessboard,x,y);
		}
	for(int i=0;i<x;i++)
		delete[] chessboard[i];
}

bool func(int x,int y,int** b,int cnt,int i,int j,bool run)
{
//	cout <<"cc"<<cnt<<endl;
	if(run==0)	return 0;
	if(x<0||x>=i||y<0||y>=j)	return 1;
	if(cnt == i*j)	{
		run=0;
		return 0;}
	if(b[x][y]<cnt&&b[x][y]!=0)
		{
	//		--cnt;
			return 1;
		}
	b[x][y]=cnt+1;
	if(cnt == i*j)	{	cout<<"ok"<<endl;return 0;}
	
//	cout <<"success  "<<cnt<<endl;
	run=func(x+2,y-1,b,cnt+1,i,j,run);
	run=func(x+2,y+1,b,cnt+1,i,j,run);
	run=func(x+1,y+2,b,cnt+1,i,j,run);
	run=func(x+1,y-2,b,cnt+1,i,j,run);
	run=func(x-2,y-1,b,cnt+1,i,j,run);
	run=func(x-2,y+1,b,cnt+1,i,j,run);
	run=func(x-1,y+2,b,cnt+1,i,j,run);
	run=func(x-1,y-2,b,cnt+1,i,j,run);
	for(int m=0;m<i;m++)
		for(int n=0;n<j;n++)
			if(b[m][n]==cnt&&m!=x&&n!=y)
				b[m][n]=0;
	return 1;
}
/*
void print(int** b)
{
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++)
			cout << b[i][j]<<' ';
		cout << endl;
	}
}
*/
