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

void printReverseLevelOrder(node* root)
{
    queue <node*> q;
    stack <node*> s;
    if(root!= NULL)
    q.push(root);
    node* temp;
    while(!q.empty())
    {
        // dequeue from queue and push into stack
        temp = q.front();
        q.pop();
        s.push(temp);
        
        // visit right child before left child
        if(temp->right!=NULL)
        q.push(temp->right);
        
        if(temp->left!= NULL)
        q.push(temp->left);
    }
    while (!s.empty()) 
    { 
        temp = s.top(); 
        cout << temp->data << " "; 
        s.pop(); 
    } 
}
int main() 
{ 
    struct node *root = newNode(1); 
    root->left        = newNode(2); 
    root->right       = newNode(3); 
    root->left->left  = newNode(4); 
    root->left->right = newNode(5); 
  
    printf("Reverse Level Order traversal of binary tree is \n"); 
    printReverseLevelOrder(root); 
  
    return 0; 
} 
