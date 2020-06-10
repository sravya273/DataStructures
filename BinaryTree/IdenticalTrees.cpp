#include <bits/stdc++.h>
using namespace std;

struct bnode
{
    int data;
    struct bnode *left;
    struct bnode *right;
};

void printInorder(struct bnode* node) 
{ 
    if (node == NULL) 
        return; 
  
    printInorder(node->left); 
    cout << node->data << " "; 
    printInorder(node->right); 
} 

struct bnode* newNode(int i)
{
    struct bnode *temp =new (struct bnode);
    temp->data=i;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
    
}
int areIdentical(struct bnode* a, struct bnode* b)
{
    if(a==NULL && b==NULL)
    return 1;
    
    else if(a!=NULL && b!=NULL) 
    return (( a->data== b->data) && areIdentical(a->left,b->left) && areIdentical(a->right,b->right));
   return 0;
    
}

int main()
{
    bnode *root1 = newNode(1); 
    root1->left = newNode(2); 
    root1->right = newNode(3); 
    root1->left->left = newNode(4); 
    root1->left->right = newNode(5); 
    printInorder(root1);
    cout<<endl;
    bnode *root2 = newNode(1); 
    root2->left = newNode(2); 
    root2->right = newNode(3); 
    root2->left->left = newNode(4); 
    root2->left->right = newNode(5); 
    printInorder(root2);
    cout<<endl;
    areIdentical(root1, root2)? cout << "Identical" : cout << "Not Identical";
}
