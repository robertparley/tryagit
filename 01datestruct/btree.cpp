#include <iostream>
using namespace std;
typedef int T;
class que
{
	struct Node
	{
		T date;
		
	}
};
class tree
{
	struct que
	{
		T date;
		que* p;
		que(const T& d):date(d),p(0){}
	};
	struct Node
	{
		T date;
		Node* L;
		Node* R;
	//	Node()	{date=T();L=NULL;R=NULL;}
		Node(const T& d):date(d),L(),R()	{}
		Node(const T& d,Node* l,Node* r):date(d),L(l),R(r){}
	};
	Node* root;
public:
	tree():root(){}
	tree& add(Node*& l,Node* p)
	{
		if(l==NULL)
			l = p;
		else if(l->date > p->date)
			add(l->L,p);
		else
			add(l->R,p);
		return *this;
	}
	Node*& find(Node*& l,const T& d)
	{
		if(l == NULL)	return l;
		else if(l->date == d)	return l;
		else if(l->date > d)	find(l->L,d);
		else	find(l->R,d);
	}

/*	bool del(Node*& l,const T& d)
	{
		Node*& t = find(l,d);
		if(t==NULL)	delete t;
		else if(t->)
	}
*/
	void travel(Node*& l)
	{
		if(l!=NULL){
		travel(l->L);
		cout << l->date <<" ";
		travel(l->R);
		}
	}
	tree& add(const T& d)	{add(root,new Node(d));return *this;}
	void travel()	{travel(root);}
	void print(Node* d,)
	{
		
	}
};

int main()
{
	tree t;
	t.add(4).add(9).add(39).add(24);
	t.add(0);
	t.travel();
}
