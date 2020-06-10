#include<iostream>
using namespace std;
struct btnode
{
	struct btnode *lchild;
	int tag;
	union
	{
		char ch;
		int x;
	}u;
	struct btnode *rchild;
};
void create(btnode *(&t),int tag)
{
	int t1,t2;
	if(t==NULL)
	{
		t=new(struct btnode);
		t->tag=tag;
		if(t->tag==0){cout<<"enter operator for"<< t->u.ch;cin>>t->u.ch;}
		else {cout<<"enter operand for"<< t->u.ch;cin>>t->u.x;}
		t->lchild=NULL;
		t->rchild=NULL;
	}
	if(t->tag==0)
   {
	cout<<"enter tags of lchild and rchild";
	cin>>t1>>t2;
	if(t1==0||t1==1) create(t->lchild,t1);
	if(t2==0||t2==1) create(t->rchild,t2);	
   } 
}
int calc(int a,int b,char c)
{
	switch(c)
	{
		case '+' : return(a+b);
		case '-' : return(a-b);
		case '*' : return(a*b);
		case '/' : return(a/b);
	}
}
int eval(btnode *(&t))
{
	if(t!=NULL)
	{
		if(t->tag==1) return t->u.x;
		else return(calc(eval(t->lchild),eval(t->rchild),t->u.ch));
	}
}
int main()
{
	cout<<"press 0 for operator and 1 for operand\n";
	struct btnode *t=NULL;
	create(t,0);
	int a=eval(t);
	cout<<endl<<a;
}
