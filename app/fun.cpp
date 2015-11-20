#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

bool func(int x,int y,int** b,int cnt,int i,int j,bool run=1);
void solveit(int startx,int starty,int x,int y);
void print(int** b,int x,int y)
{
	cout<<"遍历"<<x<<"行"<<y<<"列的棋盘的走法之一为："<<endl;
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++)
			cout << b[i][j]<<'\t';
		cout << endl;
	}
}
int main()
{
	int x,y,startx,starty;
	clock_t start,end;
	cout<<"请输入棋盘的大小（行数 列数）："<<endl;
	cin>>x>>y;
	cout<<"请输入起点位置（x y），以左上角为（0 0）" <<endl;
	cin>>startx>>starty;
	cout <<"正在计算，请稍等..."<<endl;
	start = clock();
	solveit(startx,starty,x,y);
	end = clock();
	double t=(end-start)*1.0/CLOCKS_PER_SEC;
	cout << "用时："<<t<<'s'<<endl;
}

void solveit(int startx,int starty ,int x,int y)
{
//clock it
//new一个二维数组做棋盘
	int **chessboard;
	chessboard = new int*[x];
	for(int i=0;i<x;i++)
		chessboard[i]=new int[y];
	for(int i=0;i<x;i++)
		for(int j=0;j<y;j++)
			chessboard[i][j]=0;
	int cnt=0;
	if(!func(startx,starty,chessboard,cnt,x,y,1))	
		print(chessboard,x,y);
	else
		cout << "未找到答案"<<endl;
	for(int i=0;i<x;i++)
		delete[] chessboard[i];
}

bool func(int x,int y,int** b,int cnt,int i,int j,bool run)
{
	if(run==0)			return 0;	
	if(cnt==i*j)		return 0;
	if(x>=0&&x<i&&y>=0&&y<j){	
		if(b[x][y]>cnt||b[x][y]==0){	
			b[x][y]=cnt+1;
			for(int m=0;m<i;m++)
				for(int n=0;n<j;n++)
					if(b[m][n]>=b[x][y]&&m!=x&&n!=y)
						b[m][n]=0;
		run=func(x+2,y-1,b,cnt+1,i,j,run);
		run=func(x+2,y+1,b,cnt+1,i,j,run);
		run=func(x+1,y+2,b,cnt+1,i,j,run);
		run=func(x+1,y-2,b,cnt+1,i,j,run);
		run=func(x-2,y-1,b,cnt+1,i,j,run);
		run=func(x-2,y+1,b,cnt+1,i,j,run);
		run=func(x-1,y+2,b,cnt+1,i,j,run);
		run=func(x-1,y-2,b,cnt+1,i,j,run);
		}
	}
	return run;
}
		/*
		for(int m=0;m<i;m++)
			for(int n=0;n<j;n++)
				if(b[m][n]==cnt+1&&m!=x&&n!=y)
					b[m][n]=0;
					*/
