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

struct bnode* insertBST(struct bnode *root, int value)
{
    if(root==NULL)
    {
        return newNode(value);
    }
    
    if(value>root->data)
    root ->right = insertBST(root->right, value);
    
    else
    root ->left = insertBST(root->left, value);
   
   return root; 
}

int minValue(struct bnode *root)
{
    if(root == NULL)
    return -1;
    struct bnode *temp = root;
    while(temp->left!=NULL)
    temp = temp->left;
    
    return temp->data;
}

int maxValue(struct bnode *root)
{
    if(root == NULL)
    return -1;
    struct bnode *temp = root;
    while(temp->right!=NULL)
    temp = temp->right;
    
    return temp->data;
}
void printBSTInorder(struct bnode *root)
{
    
    if (!root) { 
        return; 
    } 
    printBSTInorder(root->left); 
    cout << root->data << " "; 
    printBSTInorder(root->right); 
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
        root = insertBST(root,a);
    }
    cout<<"Inorder of the tree created is ";
    printBSTInorder(root);
    cout<<"\nMin value in BST is "<<minValue(root);
    cout<<"\nMax value in BST is "<<maxValue(root);
    return 0;
}
