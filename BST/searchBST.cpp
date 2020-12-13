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

struct bnode* searchBST(struct bnode* root, int key) 
{ 
    if (root == NULL || root->data == key) 
       return root; 
     
    if (root->data < key) 
       return searchBST(root->right, key); 
  
    return searchBST(root->left, key); 
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
    printBSTInorder(root);
    struct bnode *find = searchBST(root,25);
    cout<<"found "<<find->data<<endl;
    return 0;
}
