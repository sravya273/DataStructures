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
        cout<<l->data<<" ";
        printList(l->next);
    }
    return;
}

node* merge (node *a, node *b)
{
    node *result = NULL;
    if (a == NULL)
    return b;
    else if (b == NULL)
    return a;
    
    if(a->data <= b->data)
    {
        result = a;
        result->next = merge(a->next,b);
    }
    else
    {
        result = b;
        result->next = merge(a,b->next);
    }
    return result;
}

int main() {
	struct node *a = NULL, *b =NULL, *result=NULL;
	push(&a,15);
	push(&a,20);
	push(&a,25);
	
	push(&b,1);
	push(&b,35);
	push(&b,50);
	
	result = merge(a,b);
	cout<<"Merged list is ";
	printList(result);
	return 0;
}
