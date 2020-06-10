#include<iostream>
using namespace std;
struct avlnode
{
	struct avlnode *lchild;
	int data;
	struct avlnode *rchild;
};
typedef struct avlnode *ATPTR;
ATPTR A,T1,T,T2;
int relheight(ATPTR &T1)
{
	int h=0;
	if(T1!=NULL)
	{
		int hl=1+relheight(T1->lchild);
		int hr=1+relheight(T1->rchild);
		if(hl>hr)
		    h=hl;
		else
		    h=hr;
	    		    
	}
	return h;
}
int difference(ATPTR &T1)
{
	int hl=relheight(T1->lchild);
		int hr=relheight(T1->rchild);
		int diff=hl-hr;
		return diff;
}
struct avlnode *singleleftrot(ATPTR &T)
{
	T1=T->lchild;
	T->lchild=T1->rchild;
	T1->rchild=T;
	return T1;
}
struct avlnode *singlerightrot(ATPTR &T)
{
	cout<<"right rotation start:"<<endl;
	T1=T->rchild;
	T->rchild=T1->lchild;
	T1->lchild=T;
	return T1;
	A=T1;
	cout<<"right rot end"<<endl;
}
struct avlnode *leftrightrot(ATPTR &T)
{
	T1=T->lchild;
	T->lchild=singlerightrot(T1);
	return singleleftrot(T);
}
struct avlnode *rightleftrot(ATPTR &T)
{
	T1=T->rchild;
	T->rchild=singleleftrot(T1);
	return singlerightrot(T);
}
struct avlnode *balancing(ATPTR &T1)
{
	int diff=difference(T1);
	if(diff>1)
	{
		if(difference(T1->lchild)>0)
		      T1=singleleftrot(T1);
	    else
		      T1=leftrightrot(T1);
    }
    else if(diff<-1)
	{
		if(difference(T1->rchild)>0)
		       T1=rightleftrot(T1);
		else       
		     T1=singlerightrot(T1);       
	}
	return T1;
}
struct avlnode* insert(ATPTR &A,int k)
{
	int h;
	if(A==NULL)
	{
		A=new(struct avlnode);
		A->data=k;
		A->lchild=NULL;
		A->rchild=NULL;
		return A;
	}
	else
	{
		if(A->data>k)
		{
			cout<<"entered lside"<<endl;
			A->lchild=insert(A->lchild,k);
			A=balancing(A);
		}
        else if(A->data<k)
		{
			cout<<"entered rside"<<endl;
			A->rchild=insert(A->rchild,k);
			A=balancing(A);
		}
	}
	return A;
}
void inorder(ATPTR &A)
{
	if(A!=NULL)
	{
	
		if(A->lchild!=NULL)
		     inorder(A->lchild);
		     	cout<<A->data<<" ";
		if(A->rchild!=NULL)
		     inorder(A->rchild);     
	}
}
int main()
{
	T=NULL;
	A=NULL;
	T1=NULL;
	int n;
	char ch='y';
	while(ch=='y')
	{
		cout<<"enter element to be inserted:"<<endl;
		cin>>n;
		T2=insert(A,n);
		cout<<"do you want to continue[y/n]"<<endl;
		cin>>ch;
	}
	cout<<endl;
	inorder(T2);
}
