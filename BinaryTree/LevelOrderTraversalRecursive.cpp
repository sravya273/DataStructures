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

int height(struct node *root)
{
    if(root ==NULL)
    return 0;
    
    else
    {
        int lheight = height(root->left); 
        int rheight = height(root->right); 
 
        if (lheight > rheight) 
            return(lheight + 1); 
        else return(rheight + 1);
    }
}

void printGivenLevel(struct node *root,int level)
{
    if (root == NULL) 
        return; 
    if (level == 1) 
        cout << root->data << " "; 
    else if (level > 1) 
    { 
        printGivenLevel(root->left, level-1); 
        printGivenLevel(root->right, level-1); 
    } 
}

void printLevelOrder(struct node *root)
{
    int h = height(root);
    for(int i=1;i<=h;i++)
    {
        printGivenLevel(root,i);
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
