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

bool isBST(struct node* root, int min,int max)
{
    if(root == NULL)
    return true;
    
    if(root->data < min || root->data>max)
    return 0;
    
    return isBST(root->left,min,root->data-1) && isBST(root->right,root->data +1, max);
}

void printInorder(struct node *root)
{
    
    if (!root) { 
        return; 
    } 
    printInorder(root->left); 
    cout << root->data << " "; 
    printInorder(root->right); 
}
int main()
{
    struct node *root = newNode(1); 
    root->left        = newNode(2); 
    root->right       = newNode(3); 
    root->left->left  = newNode(4); 
    root->left->right = newNode(5);
    
    cout<<"Inorder of the tree created is ";
    printInorder(root);
    if(isBST(root,INT_MIN,INT_MAX))
    {
        cout<<"\nThe given tree is BST"<<endl;
    }
    else 
    {
        cout<<"\nThe given tree is not a BST. It is a binary tree"<<endl;
    }
    return 0;
}
