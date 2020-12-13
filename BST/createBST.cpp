#include <bits/stdc++.h>
using namespace std;

struct bnode
{
    int data;
    struct bnode *left;
    struct bnode *right;
};

bnode* newNode(int k)
{
    struct bnode *temp = new bnode();
    temp->data =k;
    temp->left =NULL;
    temp->right = NULL;
    
    return temp;
}

struct bnode* insert(struct bnode *root, int value)
{
    if(root==NULL)
    {
        return newNode(value);
    }
    
    if(value>root->data)
    root ->right = insert(root->right, value);
    
    else
    root ->left = insert(root->left, value);
   
   return root; 
}

void printInorder(struct bnode *root)
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
    int n;
    cin>>n;
    int a;
    struct bnode *root = NULL; 
    while(n--)
    {
        cin>>a;
        root = insert(root,a);
    }
    printInorder(root);
}
