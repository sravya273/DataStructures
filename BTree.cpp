#include<iostream>
using namespace std;
const int d=2;
struct bnode
{
	int count=0;
	int k[2*d+1];
	struct bnode *ptr[2*d+1];
	struct bnode *pptr;
};
struct bnode *newnode()
{
	struct bnode *t=NULL;
	t=new(struct bnode);
	for(int i=0;i<2*d+1;i++)
	t->ptr[i]=NULL;
	t->pptr=NULL;
	return t;
}
int overflow(struct bnode *t)
{
	if(t->count==2*d)
	return 1;
	else return 0;
}
void sort(int a[],int count)
{
	for(int i=0;i<count-1;i++)
	for(int j=i;j<=count-1;j++)
	{
		if(a[i]>a[j])
		{
			int t;
			t=a[i];
			a[i]=a[j];
			a[j]=t;
		}
	}
}
int isleaf(struct bnode *t)
{
	int flag=1;
	for(int i=0;i<2*d+1;i++)
	{
		if(t->ptr[i]!=NULL)
		flag=0;
	}
	return flag;
}


struct bnode *toleafnode(struct bnode *t,int n)
{
	int s=isleaf(t);
	if(s==0)
	{
		if(n<t->k[0])
		return toleafnode(t->ptr[0],n);
		else if (n>t->k[0] && n<t->k[t->count-1])
		{
			for(int i=0;i<t->count-1;i++)
			 {
			 	if(n>t->k[i] && n<t->k[i+1])
				 return toleafnode(t->ptr[i+1],n);
			 }
		}
		else if(n>t->k[t->count-1])
		return toleafnode(t->ptr[t->count],n);
	}
	else 
	return t;
}


int ind(struct bnode *l, int n)
{
	int r;
	if(n<l->k[0])
	r=0;
	else
	{
	int flag=0;
	for(int i=0; i<l->count-1&&flag==0; i++)
	{
	if(n>l->k[i]&&n<l->k[i+1])
	{
		flag=1;
		r=i+1;
	}
   }
	if(flag==0)
	r=l->count;
    }
    return r;
}

struct bnode * pptradd(struct bnode *leaf,struct bnode *right,struct bnode *T,int n )
{
	if(leaf->pptr==NULL)
	{   cout<<"------------------***111***"<<endl;
		leaf->pptr=newnode();
		leaf->pptr->k[leaf->pptr->count]=n;
		leaf->pptr->count++;
		leaf->pptr->ptr[0]=leaf;
		leaf->pptr->ptr[1]=right;
		right->pptr=leaf->pptr;
		T=leaf->pptr;
		return T;
	}
	else
	{
		
		if(!overflow(leaf->pptr))
		{
			cout<<"--------------222***"<<endl;
		int index=ind(leaf->pptr,n);
		for(int x=leaf->pptr->count+1; x>index; x--)
        {
    	leaf->pptr->k[x]=leaf->pptr->k[x-1];
    	leaf->pptr->ptr[x+1]=leaf->pptr->ptr[x];
    	if(leaf->pptr->ptr[x+1]!=NULL)
         	{
    		leaf->pptr->ptr[x+1]->pptr=leaf->pptr;
	    	}
	     }
	    leaf->pptr->k[index]=n; 
		leaf->pptr->ptr[index+1]=right;
		leaf->pptr->count++;
		right->pptr=leaf->pptr;
	    return T;
		}
		else if(overflow(leaf->pptr))
		{  
		cout<<"--------------***3333***"<<endl;
		leaf->pptr->k[2*d]=n;
		sort(leaf->pptr->k,2*d+1);
		struct bnode *right1=newnode(); 
		if(leaf->pptr->ptr[0]!=leaf&&leaf->pptr->ptr[2*d]!=leaf)
		{
			cout<<"----------444***"<<endl;
		for(int x=d+1; x<2*d+1; x++)
		{
			right1->k[right1->count]=leaf->pptr->k[x];
			
			right1->ptr[right1->count]=leaf->pptr->ptr[x];
			if(right1->ptr[right1->count]!=NULL)
			{
				right1->ptr[right1->count]->pptr=right1;
			}
			right1->count++;
		}
		right1->ptr[right1->count]=leaf->pptr->ptr[2*d];
		leaf->pptr->count=d;
		right1->ptr[1]=right;
		right->pptr=right1;
		right->count=d;
		return pptradd(leaf->pptr,right1,T,leaf->pptr->k[d]);
		}
		else
		{
			cout<<"------------555"<<endl;
			if(leaf->pptr->ptr[0]==leaf)
			{   
			cout<<"p[0] is leaf"<<endl;
			    int x;
				for( x=d+1; x<2*d+1; x++)
				{
					right1->k[right1->count]=leaf->pptr->k[x];
					right1->ptr[right1->count]=leaf->pptr->ptr[x-1];
					if(right1->ptr[right1->count]!=NULL)
					{
						right1->ptr[right1->count]->pptr=right1;
					}
					right1->count++;
				}
				cout<<"me me"<<endl;
			//right->ptr[0]=leaf->ptr[d];
			//	right->	ptr[right1->count]=leaf->ptr[2*d];
				right1->count=d;
				right1->ptr[right1->count]=leaf->pptr->ptr[2*d];
			//	right1->ptr[0]=leaf->pptr->ptr[d];
				
				if(right1->ptr[right1->count]!=NULL)
				{
					right1->ptr[right1->count]->pptr=right1;
				}
				leaf->pptr->count=d;
				for( x=d; x>1; x--)
				{
					leaf->pptr->ptr[x]=leaf->pptr->ptr[x-1];
					if(leaf->pptr->ptr[x]!=NULL)
					leaf->pptr->ptr[x]->pptr=leaf->pptr;
				}
				leaf->pptr->ptr[1]=right;
				right->pptr=leaf->pptr;
				leaf->pptr->count=d;
			return 	pptradd(leaf->pptr,right1,T,leaf->pptr->k[d]);
			}
			else 
			{   cout<<"6666***";
		    	struct bnode *k=leaf->pptr;
				for(int x=d+1; x<2*d+1; x++)
				{
					right1->k[right1->count]=leaf->pptr->k[x];
					right1->ptr[right1->count]=leaf->pptr->ptr[x];
					if(right1->ptr[right1->count]!=NULL)
					{
						right1->ptr[right1->count]->pptr=right1;
					}
					right1->count++;
				}
				right1->ptr[right1->count]=right;
				right->pptr=right1;
				leaf->pptr->count=d;
				k->count=d;
				return pptradd(k,right1,T,k->k[d]);
			}
			
		}
	}
  }
}

struct bnode * btree(struct bnode *t, int n,struct bnode *T)
{
	struct bnode *leaf=toleafnode(t,n);
	if(!overflow(leaf))
	{   
		leaf->k[leaf->count]=n;
		leaf->count=leaf->count+1;
		sort(leaf->k,leaf->count);
		return T;
	}
	else if(overflow(leaf))
	{   
		leaf->k[2*d]=n;
		sort(leaf->k,2*d+1);
		struct bnode *right=newnode();
		for(int r=d+1; r<2*d+1; r++)
		{
			right->k[right->count++]=leaf->k[r];
		}
		leaf->count=d;
		T=pptradd(leaf,right,T,leaf->k[d]);
		return T;
	}
}
void print(struct bnode *t)
{
	if(t!=NULL)
	{
		for(int i=0;i<t->count;i++)
		cout<<t->k[i]<<"  ";
		cout<<endl;
		for(int i=0;i<t->count+1;i++)
		{
		//cout<<i<<".";
		print(t->ptr[i]);
	}
	}
	else return;
}

int main()
{
	struct bnode *b=NULL,*t=NULL;
	cout<<"value of d can be varied"<<endl;
	cout<<"enter first element"<<endl;
	int n;
	cin>>n;
	b=newnode();
	b->k[0]=n;
	b->count=b->count+1;
	t=b;
	cout<<"enter next element"<<endl;
	cin>>n;
	while(n!=-1)
	{
		t=btree(t,n,t);
		print(t);
		cout<<endl;
		cout<<"enter next element"<<endl;
		cin>>n;
	}
}
