#include <bits/stdc++.h>
using namespace std;

struct lnode
{
    int data;
    struct lnode *next;
};

struct lnode* addNode(int i)
{
    struct lnode *t=NULL;
    t=new(struct lnode);
    t->data=i;
    t->next=NULL;
    return t;
}

bool detectLoop(struct lnode *l)
{
    struct lnode *p,*q;
    p=l;
    q=l;
    while(p!=NULL && q!=NULL && q->next!=NULL)
    {
        p=p->next;
        q=q->next->next;
        if(p==q)
        return true;
    }
    return false;
}
int main()
{
    struct lnode *a, *b, *c=NULL;
    a= addNode(3);
    a->next=addNode(4);
    a->next->next=addNode(5);
    a->next->next->next=addNode(1);
    a->next->next->next->next=addNode(2);
    a->next->next->next->next->next=addNode(7);
    a->next->next->next->next->next->next=addNode(8);
    // a->next->next->next->next=a->next->next;
    detectLoop(a)?cout<<"loop": cout<<"no loop";
}
