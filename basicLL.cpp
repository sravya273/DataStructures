#include <bits/stdc++.h>
using namespace std;

struct lnode
{
    int data;
    struct lnode *next;
};

void printList(struct lnode *l)
{
    if(l!=NULL)
    {
        cout<<l->data;
        printList(l->next);
    }
    return;
}

int main()
{
    struct lnode *a, *b, *c=NULL;
    a= new(struct lnode);
    a->data=3;
    b= new(struct lnode);
    b->data=4;
    c= new(struct lnode);
    c->data=5;
    a->next=b;
    b->next=c;
    c->next=NULL;
    printList(a);
}
