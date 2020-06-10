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
int main()
{
    bnode *root1 = newNode(1); 
    root1->left = newNode(2); 
    root1->right = newNode(3); 
    root1->left->left = newNode(4); 
    root1->left->right = newNode(5); 
    printInorder(root1);
}
