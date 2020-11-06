#include <bits/stdc++.h>
using namespace std;

struct node 
{ 
    int data; 
    struct node* left;
	struct node* right; 
}; 

node* newNode(int k)
{
    struct node *temp = new node();
    temp->data =k;
    temp->left =NULL;
    temp->right = NULL;
    
    return temp;
}
void printLevelOrder(node* root)
{
    queue <node*> q;
    if(root!= NULL)
    q.push(root);
    node* temp;
    while(!q.empty())
    {
        temp = q.front();
        cout<<temp->data<<" ";
        q.pop();
        
        if(temp->left!= NULL)
        q.push(temp->left);
        
        if(temp->right!=NULL)
        q.push(temp->right);
    }
}
int main() 
{ 
    struct node *root = newNode(1); 
    root->left        = newNode(2); 
    root->right       = newNode(3); 
    root->left->left  = newNode(4); 
    root->left->right = newNode(5); 
  
    printf("Level Order traversal of binary tree is \n"); 
    printLevelOrder(root); 
  
    return 0; 
} 
