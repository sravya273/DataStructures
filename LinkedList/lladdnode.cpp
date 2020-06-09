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
    a= addNode(3);
    a->next=addNode(4);
    a->next->next=addNode(5);
    printList(a);
}
