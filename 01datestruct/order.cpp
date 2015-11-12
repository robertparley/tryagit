#include <iostream>
#include <algorithm>
using namespace std;
#include <ctime>

/*
void sort(int* a, int n)
{
	int j;
	for(int i=1; i<n; i++){
		int t = a[i];
		for(j=i;j>0&&t<a[j-1];j--)
			a[j]=a[j-1];
		a[j] = t;
	}
}
*/
 //快速排序法

void sort(int *a,int n)
{	
	/*
	if(n<=1) return;
	if(n==2){
		if(a[1]<a[0]) swap(a[1],a[0]);
		return;
	}
	swap(a[n/2],a[0]);
	int jie=a[0];
	int* L=a+1;
	int* R=a+n-1;
	while(L<R){
		while(L<R&&*L<jie) ++L;
		while(a<R&&!(*R<jie)) --R;
		if(L<R) swap(*L,*R);
	}
	if(*R<jie) swap(*R,a[0]);
	sort(a, R-a);
	sort(R+1,n-1-(R-a));
}
	*/
	
	if(n<=1)	return;
	if(n==2)
	{
		if(a[0]>a[1])		
			swap(a[0],a[1]);
		return;
	}
	swap(a[0],a[n/2]);
	int j = a[0];
	int *L=a+1;
	int *R=a+n-1;
	while(L<R)
	{
		while(L<=R&&*L<j)	{L++;}
		while(L<=R&&*R>=j)	{R--;}
		if(L<R)	swap(*L,*R);
	}
	if(*R<j)	swap(a[0],*R);
	sort(a,R-a);
	sort(R+1,a+n-R-1);
}

int main()
{
	const int N=10240;
	int a[N];
	for(int i=0; i<N; i++)
		a[i] = N-i;
	for(int i=0; i<10; i++)
		cout << a[i] << ' ';
	cout << endl;
	//clock_t t1 = clock();
	sort(a,N);
	//clock_t t2 = clock();
	//cout << double(t2-t1)/CLOCKS_PER_SEC << endl;
	for(int i=0; i<10; i++)
		cout << a[i] << ' ';
	cout << endl;
}
