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
bool detectLoop(struct lnode *l)
{
    unordered_set<lnode *>us;
    while(l != NULL)
    {
        if(us.find(l)!=us.end())
        return true;
        
        us.insert(l);
        l=l->next;
    }
    return false;
}
int main()
{
    struct lnode *a, *b, *c=NULL;
    a= addNode(3);
    a->next=addNode(4);
    a->next->next=addNode(5);
    a->next->next->next=a;
    // printList(a);
    detectLoop(a)?cout<<"loop": cout<<"no loop";
}
