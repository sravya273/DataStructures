#include <iostream>
using namespace std;
struct node 
{ 
    int data; 
    struct node *left, *right; 
};

int haskchild(struct node* t)
{
	if (t== NULL)
	return 0;
    return 1+haskchild(t->left)+haskchild(t->right);   
}

void callchild(struct node* head, int k)
{
    if(head== NULL)
    return;
    if(head!=NULL)
    {
       int count= haskchild(head);
       if(count-1==k)
       cout<<head->data<<" has"<< count-1<<" decendents"<<endl;
    }
     callchild(head->left,k);
     callchild(head->right,k);
}
node *newnode(int data) 
{ 
    node *temp = new node; 
    temp->data = data; 
    temp->left = temp->right = NULL; 
    return temp; 
} 

int main() {
	node * root = newnode(20); 
    root->left = newnode(8); 
    root->right = newnode(22); 
    root->left->left = newnode(4); 
    root->left->right = newnode(12); 
    root->left->right->left = newnode(10); 
    root->left->right->right = newnode(14); 
    node * target = root->left->right; 
    callchild(root, 2); 
    return 0; 
}
