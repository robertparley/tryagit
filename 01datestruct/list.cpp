#include <iostream>

using namespace std;
typedef int T;
class List
{
	struct Node
	{
		T date;
		Node* next;
		Node(const T& d=T()):date(d),next(0){}
	};
	Node* head;
public:
	List():head(NULL){}
	Node*& find(int pos);
	List& add(const T& d,int pos=0);
	List& del(int pos);
	int quer(const T& d);
	List& rank();
	
	void rewrite(const T& d,int pos);
	void clear();
	void show();
	int size();
	void erase(const T& d);
	List operator+=(const List& l)
	{
		Node*& p = find(size());
		p = l.head;
	}
};
List::Node*& List::find(int pos)
{
	Node* p=head;
	if(pos==0)	return head;
	while(--pos)
	{
		p = p->next;
	}
	return p->next;
}
List& List::add(const T& d,int pos)
{
	if(pos<0||pos>(size()))
		throw "error";
	Node* p = new Node(d);
	Node*& tp = find(pos);
	p->next = tp;
	tp = p;
	return *this;
}
void List::show()
{
	Node* p = head;
	while(p!=NULL)
	{
		cout << p->date << "  ";
		p = p->next;
	}
	cout<<endl;
}
List& List::del(int pos)
{
	if(pos<0||(pos>size()-1))
		throw "error";
	Node*& p=find(pos);
	Node* t=p;
	p = p->next;
	delete t;
}
int List::quer(const T& d)
{
	int cnt=0;
	Node* p=head;
	while(p)
	{
		if(p->date==d)
			return cnt;
		p = p->next;
		++cnt;
	}
	return -1;
}
void List::rewrite(const T& d,int pos)
{
	if(pos<0||(pos>size()-1))
		throw "error";
	Node*& tp=find(pos);
	tp->date = d;
}
void List::clear()
{
	Node* p = head;
	while(p)
	{
		head = head->next;
		delete p;
		p = head;
	}
}
int List::size()
{
	int cnt=0;
	Node* p = head;
	while(p)
	{
		++cnt;
		p = p->next;
	}
	return cnt;
}
void List::erase(const T& d)
{
	int t;
	while((t = quer(d))!=-1)
	{
		del(t);
	}
}

List& List::rank()
{
	T d =T();
	int j,po;
	int temp = size();
	Node* p = head->next;
	Node* min=head;
	for(int i=1;i<temp;i++)
	{
		j=-1;po=0;
		min = find(i-1);
		p = min->next;
		while(p)
		{
			++j;
			if((p->date) <= (min->date))
				{min = p;po = j+i;}
			p = p->next;
		}
		if(po!=0)
		{
			d = min->date;
			del(po);
			add(d,i-1);
		}
	}
	return *this;
}

int main()
{
	List l;
	l.add(3).add(3);
	l.add(6).add(4);
	List l2;
	l2.add(4).add(7).add(49);
	l.show();
	l.rank();
	cout<<"======================"<<endl;
	l.show();
	l2.show();
	 l+=l2;
	l.show();
/*
	l.del(2);
	l.show();
	l.rewrite(9,2);
	l.show();
	l.erase(4);
	l.show();
	l.clear();
	l.show();
*/
}


