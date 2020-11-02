#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

void push (struct node **x, int value)
{   
    struct node *newnode = new node();
    newnode->data = value;
    newnode->next = NULL;
    
    if(*x == NULL)
    {
        *x=newnode;
        return;
    }
    struct node *temp=NULL; 
    temp = *x;
    while(temp->next!= NULL)
    {
        temp = temp->next;
    }
    
    temp ->next = newnode;
    
}
void printList(struct node *l)
{
    if(l!=NULL)
    {
        cout<<l->data<<"\n";
        printList(l->next);
    }
    return;
}

int main() {
	struct node *a=NULL;
	push(&a,15);
	push(&a,25);
	push(&a,20);
	printList(a);
	return 0;
}
