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

void printInorderTraversal(node* root)
{
    if(root == NULL)
    return;
    printInorderTraversal(root->left);
    cout<<root->data<<" ";
    printInorderTraversal(root->right);
}
int height(struct node* root)
{
    if(root == NULL)
    return 0;
    
    return 1+max(height(root->left),height(root->right));
}

bool isHeightBalanced(struct node* root)
{
    if(root==NULL)
    return true;
    
    if((abs(height(root->left)-height(root->right))<=1) && 
    isHeightBalanced(root->left)&& 
    isHeightBalanced(root->right))
    return true;
    return false;
}
int main() 
{ 
    struct node *root = newNode(1); 
    root->left        = newNode(2); 
    root->right       = newNode(3); 
    root->left->left  = newNode(4); 
    root->left->right = newNode(5); 
  
  cout<<"Given tree is ";printInorderTraversal(root);
  cout<<"Is the tree height balanced? True/false "<<isHeightBalanced(root)<<endl;
  return 0; 
} 
